/* 
LPMud Smtp Client v0.1a0
[for CCTX II by CuteRabbit Studio]

初写于1999年5月16日
作者：JackyBoy(胖胖) @ CuteRabbit Studio for CCTX II (胖兔兔工作室)
主页：http://mud.yn.cninfo.net/jackyboy
电子邮件：jackyboy@126.com
申明：本程序可以复制使用于非商业的MUD中，但是请尊重作者凝集在这一行行代码中的心
血，不要篡改作者的署名，你可以任意修改代码的任何部分，唯一的要求是请你公布你修
改后的程序，并请你在下面的修改表中署名：
------------------------------------------------------
更新记录：
1999年5月17日 增加了配合LOGIND.C的注册功能，并重新设置密码，完善了信息显示，同时
	利用修改logind.c的机会增加了Gb to Big5的转换，涉及文件较多：
	/include/globals.h
	/adm/daemons/language.c /adm/etc/下的table文件
	/adm/simul_efun/message.c
	/clone/user/ user.c login.c
	/adm/daemons/logind.c
	/adm/daemons/alias.c
	/adm/daemons/message.c
	...(不能详细列尽)
	已知BUG：printf函数不能正确显示，必须使用write(sprintf())来取代
	JackyBoy@CuteRabbit
...
*/

/*
文件功能说明：
    对玩家进行注册并设置注册口令，为了避免被别人知道最初的预设口令而被抢夺ID，
应该允许玩家重新修改自己的口令——也就是说允许双口令登录，其中最初设定的口令用于重
新取回口令。同时也可以记录玩家数据，方便玩家忘记口令是取回口令。
    玩家新登录的时候应该设置口令到temp_password属性，注册时设置password属性，当玩
家登录时输入了正确的注册口令，则设置registered属性，这在login ob和user ob里都设置的。
*/
#include <ansi.h>
#include <net/dns.h>
#include <net/telnet.h>
#include <net/socket.h>
#include <net/socket_errors.h>
#include <socket_err.h>
#include <mudlib.h>

inherit ITEM;

static int my_socket,socket1,socket2;
static object me;
static int status=0;
static string smtp_ip="202.106.186.237 25";
static string smtp_domain="www.email.com.cn";
static string sender="Xyj";
static string rcpt,msg;
int write_message(string);
void tell_me(string arg)
{
        tell_object(environment(this_object()),arg);
}
void chat(string arg)
{
	//CHANNEL_D->do_channel(this_object(),"sys",arg);
	tell_me(arg);
	return;
}

void create()
{
        set_name("["+INTERMUD_NAME+"]"+"注册器", ({ "register","smtp", "telnet" }) );
        set("long",
                "这是用来连接发邮件和连接其他MUD的工具。\n");
                set_weight(3000);
                set_max_encumbrance(0);
                if( clonep() )
                        set_default_object(__FILE__);
                else {
                        set("unit", "个");
                        set("material", "unknow");
                }
        setup();
}

void init()
{       
        object ob;

        if( interactive(ob = this_player()) ) {
                add_action("close_socket","close");
                add_action("write_message","/");
                add_action("do_register","register");
                add_action("do_telnet","telnet");
                me = ob;
        }
}

int do_telnet(string arg)
{
        int err;
        if( query("connected") )        socket_close(my_socket);
        my_socket = socket_create( STREAM, "in_read_callback","in_close_callback" );
        if ( my_socket < 0 ) {
                tell_me( "Failed to create socket.\n" );
                return 1;
        }
        err = socket_connect( my_socket, arg , "read_callback","write_callback" );
        if( err==EESUCCESS ) {
                        tell_me("Connect to " + arg + "\n");
                        set("connected",1);
        }
        else
                        tell_me("Can't connect to " + arg + "\n");
        return 1;
}

int close_socket()
{
        if( query("connected") )  {
                        if( socket_close(my_socket) ) {
                                tell_me("Closed telnet socket.\n");
                                delete("connected");
                        }
                        else
                                tell_me("Close telnet socket fail.\n");
                }
        else
                tell_me("Not connected.\n");
        return 1;
}

void read_callback(int fd, mixed message)
{
    tell_me( BOLD + "→" + NOR + message );
    switch(status)
    {
    	case 0:
    		if(sscanf(message,"220%*s"))
    		{
    			status++;
    			write_message("HELO " +smtp_domain );
    			//chat("发出HELO命令");
    			return;
    		}
    		break;
    	case 1:
    		if(sscanf(message,"250%*s"))
    		{
    			status++;
    			write_message("MAIL FROM:<TXJH>");
    			//chat("发出MAIL FROM命令");
    			return ;
    		}
			break;
    	case 2:
    		if(rcpt&&sscanf(message,"250%*s"))
    		{
    			status++;
    			write_message("RCPT TO:<"+rcpt+">");
    			//chat("发出RCPT TO命令");
    			return ;
    		}
    		break;
    	case 3:
    		if(sscanf(message,"250%*s"))
    		{
    			status++;
    			write_message("DATA");
    			//chat("发送DATA命令");
    			return;
    		}
    		break;
    	case 4:
    		if(sscanf(message,"354%*s"))
    		{
    			status++;
    			if(sscanf(msg,"%*s\r\n.\r\n%*s"))
    				chat("包含非法数据，可能会无法发送。\n");
    			log_file("sendmail","\n试图发送数据:\n"+msg);
    			write_message(msg+"\n.\n");
    			//chat("发送数据");
    			return;
    		}
    		break;
    	case 5:
    		if(sscanf(message,"451%*s"))
    			chat("Smtp Server接收数据出错！请另选服务器。\n");
    		else
    			chat("注册信件已经正确发送了\n"+
    				"请过几分钟后再打开你的信箱查收。\n\t\t\t\tLxh@TXJH\n");
    		break;    			
    }
    if(status!=5||!sscanf(message,"250%*s"))
    	chat("发送出错");
    status=0;
	write_message("QUIT");
	chat("恢复断线状态");
	close_socket();
	return ;        			
}

void write_callback(int fd)
{
        int res;
        if(query("connect"))return ;
        res = socket_write( fd,"");
        if (res == EESUCCESS || res == EECALLBACK) {
                set("connected",1);
        }
}

int write_message(string arg)
{
        if( !arg ) arg="";
        socket_write(my_socket,arg+"\n");
        return 1;
}

string make_password(string arg,string id)
{
	return id;
}

int do_register(string dest)
{
	object me,linkob;

	me=this_player(1);
	if( !dest||!sscanf(dest,"%*s@%*s.%*s") )
		return notify_fail("电子邮件地址错误。\n");
	rcpt=dest;
	status=0;
	if(!my_socket&&do_telnet(smtp_ip)==0)
		return notify_fail("无法连接邮件服务器。\n");
	//设置玩家的注册信息
	linkob=me->query_temp("link_ob");
	linkob->set("password", crypt(make_password(dest,me->query("id")),0) );
	linkob->set("email",lower_case(dest));
	me->set("startroom","/d/welcome/wel1_1");
	//发出注册信件
	msg="\n你好！欢迎光临"+INTERMUD_NAME+"！\n"+
		"你已经成功地在本游戏注册，请使用下面提供的密码登录完成注册。\n你的注册密码是："+
		make_password(dest,me->query("id"))+"\n"
		"如果你丢失此信，请用原来的临时密码进入，并重新注册。\n"+
		CHINESE_D->chinese_time(0,(string)localtime(time()));
	msg="TO:"+dest+"\n"+
		"SUBJECT:"+INTERMUD_NAME+"注册信件！\n"+
		"FROM:"+me->query("id")+"@"+INTERMUD_MUD_NAME+"\n"+
		"MIME-Version:1.0\n"+
		"DATE:"+time()+"\n"+
		"X-MAILER:Lpc Smtp client v0.1\n"+"\n"+
		msg;
		
//下面的这些操作移动到read_callback里了		
/*	msg="HELO " + smtp_domain + "\n" +
        "MAIL FROM: <" + sender + ">\n" + 
        "RCPT TO: <" + dest + ">\n" +
        "DATA\n" + msg + "\n.\n" +
        "QUIT\n";
	write_message(msg);
	*/
	return 1;
}

