// xiang.c
#include <ansi.h>
inherit NPC;
#include "/d/zhongzhou/npc/renwu.h"

int ask_kill();
string do_tisheng();
void do_jiangli(object player,int lv,int type);

void create()
{
    set_name("向问天", ({ "xiang wentian", "xiang"}));
    set("nickname", HIR "天王老子" NOR );
    set("gender", "男性");
    set("banghui", "日月教");
    set("bh_rank","左使");
    set("long", "他就是日月教左使。为人极为豪爽。\n");
    set("age", 45);
    set("shen_type", -1);

    set("str", 21);
    set("per", 28);
    set("int", 30);
    set("con", 26);
    set("dex", 30);
    set("chat_chance", 1);
    set("inquiry", ([
      "杨莲亭"     : "这种人，该杀！\n",
      "东方不败"   : "篡位叛徒，我非杀了他不可！\n",
      "杀东方不败" : (: ask_kill() :),
      "任我行"     : "教主被困，已历十年......\n",
	"升职" :(:do_tisheng:),
    ]));
    set("kee", 4000);
    set("max_kee", 4000);
    set("gin", 1000);
    set("max_gin", 1000);
    set("force", 3500);
    set("max_force", 3500);
    set("force_factor", 350);

    set("combat_exp", 2500000);
    set("score", 0);

	set_skill("force",200);
	set_skill("hunyuan-yiqi",200);
	set_skill("kuihua-xinfa",100);
	set_skill("dodge",200);
	set_skill("shaolin-shenfa",200);
	set_skill("unarmed",200);
	set_skill("nianhua-zhi",200);
	set_skill("parry",200);
    set_skill("foxuexinde", 110);
    set_skill("literate", 110);
	set_skill("fumo-zhangfa",200);
	set_skill("duanyun-fufa",200);
	set_skill("huntian-cuifa",200);
	set_skill("hammer",200);
	set_skill("axe",200);
	set_skill("staff",200);

    map_skill("force", "hunyuan-yiqi");
    map_skill("dodge", "shaolin-shenfa");
	map_skill("unarmed","nianhua-zhi");
	map_skill("parry","nianhua-zhi");


    setup();
    carry_object(__DIR__"obj/cloth")->wear();
}

string do_tisheng()
{
	object me=this_player();
	string *lv=({"风雷堂","青龙堂","白虎堂","天香堂",});
	string banghui,str1,str2;

	if(!stringp( banghui=me->query("banghui")) || banghui!=query("banghui"))
		return "哼，你不是本教弟兄，向某可做不了这个主。";
	if((int)me->query("combat_exp")<10000)  {
                if(! (int)me->query("rank_lv"))
                return "你的经验点不够，不能提升职位！";
                me->delete("bh_rank");
                me->delete("rank_lv");
                return "由于"+me->query("name")+"办事不力，降为帮众。";
        }
        else if(me->query("combat_exp")<100000) {
                if((int)me->query("rank_lv")==1)
                return "你已经是本教"+(string)me->query("bh_rank")+
		"，要想升为堂主至少得100000经验点。";
		if(! (int)me->query("rank_lv"))
			str1=lv[random(sizeof(lv))];
		else	str1=me->query("bh_rank")[0..5];
		me->set("bh_rank",str1+"香主");
		if((int)me->query("rank_lv")>1)	{
		me->set("rank_lv",1);
		return me->query("name")+"办事不力，降为"+me->query("bh_rank")+"。";
		}
		me->set("rank_lv",1);
                return me->query("name")+"升为本教"+me->query("bh_rank")+"！";
	}
	else if(me->query("combat_exp")<500000) {
                if((int)me->query("rank_lv")==2)
                return "你已经是本教"+(string)me->query("bh_rank")+
		"，要想升为护法至少得500000经验点。";
                if(! (int)me->query("rank_lv"))
                        str1=lv[random(sizeof(lv))];
                else    str1=me->query("bh_rank")[0..5];
		me->set("bh_rank",str1+"堂主");
		if((int)me->query("rank_lv")>2)	{
		me->set("rank_lv",2);
		return me->query("name")+"办事不力，降为"+me->query("bh_rank")+"。";
                }
                me->set("rank_lv",2);
                return me->query("name")+"升为本教"+me->query("bh_rank")+"！";
        }
        else if(me->query("combat_exp")<1000000) {
                if((int)me->query("rank_lv")==3)
                return "你已经是本教"+(string)me->query("bh_rank")+
		"，要想升为长老至少得1000000经验点。";
                if(! (int)me->query("rank_lv"))
                        str1=lv[random(sizeof(lv))];
                else    str1=me->query("bh_rank")[0..5];
		me->set("bh_rank",str1+"护法");
		if((int)me->query("rank_lv")>3) {
                me->set("rank_lv",3);
		return me->query("name")+"办事不力，降为"+me->query("bh_rank")+"。";
		}
                me->set("rank_lv",3);
                return me->query("name")+"升为本教"+me->query("bh_rank")+"！";
        }
        else    {
                if((int)me->query("rank_lv")==4)
                return "你已经是本教"+(string)me->query("bh_rank")+"了。";
                if(! (int)me->query("rank_lv"))
                        str1=lv[random(sizeof(lv))];
                else    str1=me->query("bh_rank")[0..5];
		me->set("rank_lv",4);
		me->set("bh_rank",str1+"长老");
		return me->query("name")+"升为本教"+me->query("bh_rank")+"！";
        }

}



void init()
{
        object ob;

        ::init();

        if( interactive(ob=this_player()) && !is_fighting())
        {
                remove_call_out("greeting");
                call_out("greeting",1,ob);
        }
        add_action("do_renwu","renwu");
        add_action("do_jiaochai","jiaochai");
}

void greeting(object ob)
{ 
        string banghui;
        if(!ob || environment(ob)!=environment()) return;
        banghui=(string)ob->query("banghui");
        if(! banghui || banghui!=query("banghui"))
		command("say 此处乃日月教禁地，不要到处乱跑。");
	else    message_vision(HIC"向问天道：想要"+YEL"升职"HIC+
		"的话，那就为本教多出些力吧。\n"NOR,this_object());
	return;
}

int ask_kill()
{
   object ob,me = this_player();

   command("tell "+this_player()->query("id")+" 你要去杀东方不败？\n");
   message_vision(HIC "向问天对$N点了点头说：我助你一臂之力。\n" NOR,this_player());
   ob=new("/d/heimuya/npc/obj/card4");
   ob->move(me);
   tell_object(me,"向问天从怀里摸出一块令牌塞到你的手上。\n");
   return 1;
}

int do_renwu()
{
        object player,huowu;
        string banghui;
        mapping data;
        int long,sec,min;
        string msg;
        int time;

        player=this_player();
        banghui=(string)player->query("banghui");
	if(! banghui || banghui!=query("banghui"))	{
		command("say 这位"+RANK_D->query_respect(player)+
		"非我日月教弟兄，向某何德何能为你分配任务？");
		return 1;
	}
        if(!undefinedp(player->query("oldsix_quest")))   {
		command("say "+player->query("name")+"，你上次的任务还末曾交差(jiaochai)吧？。\n");
                return 1;
        }
//	if(intp(player->query("bad_quest"))
//	&& (int)player->query("mud_age")-(int)player->query("bad_quest")<600)	{
//		command("say 你还是好好反醒一下上次任务失败的原因吧。");
//		return 1;
//	}
//	if(intp(player->query("bad_quest")))	player->delete("bad_quest");
	huowu=present("huo wu",player);
	if(objectp(huowu))	{
		tell_object(player,"向问天道：先把你身上的货物处理一下吧！\n");
		return 1;
	}
	if((int)player->query("combat_exp")<10000)
		data=renwu1[random(sizeof(renwu1))];
	else if((int)player->query("combat_exp")<100000)
		data=renwu2[random(sizeof(renwu2))];
	else if((int)player->query("combat_exp")<800000)
		data=renwu3[random(sizeof(renwu3))];
	else 	data=renwu4[random(sizeof(renwu4))];
        time=time();
        player->set("oldsix_quest/type",data["type"]);
        player->set("oldsix_quest/id",data["id"]);
        player->set("oldsix_quest/name",data["name"]);
        player->set("oldsix_quest/lv",data["lv"]);
        player->set("oldsix_quest/start",time);
        player->set("oldsix_quest/over",0);
        long=data["lv"]*60+random(60);
	long+=120;
        player->set("oldsix_quest/time",long);
        sec=long%60;    long/=60;
        min=long;
        msg="请在"+chinese_number(min)+"分"+chinese_number(sec)+
                "秒内，";
        if(data["type"]==1)     msg+="把"+data["name"]+"("+data["id"]+")杀了。";
        else if(data["type"]==2)
                msg+="把"+data["name"]+"("+data["id"]+")找来。";
        else if(data["type"]==3)        {
                huowu=new("/obj/huowu");
                huowu->set("start",time);
                huowu->move(player);
                msg+="把货物送到"+data["name"]+"后回来交差。";
                }
        else if(data["type"]==4)
                msg+="为本教招慕一位NPC帮众。";
        else    msg+="为本教抢夺一块地盘。";

	tell_object(player,"向问天道："+msg+"\n");

        return 1;
}

int do_jiaochai()
{
        object player,ob;
        int type,start,time,over,lv;
        int now_time,score;
        string id,name,banghui;

        player=this_player();
        banghui=(string)player->query("banghui");
	if(! banghui || banghui!=query("banghui"))	{
                command("say 这位"+RANK_D->query_respect(player)+
		"非我日月教弟兄，何以向我交差？");
		return 1;
	}
        if(undefinedp(player->query("oldsix_quest")))    {
                command("say "+player->query("name")+"，你并末领取任何任务(renwu
)，何来交差之说？\n");
                return 1;
        }
        type=(int)player->query("oldsix_quest/type");
        id=(string)player->query("oldsix_quest/id");
        name=(string)player->query("oldsix_quest/name");
        start=(int)player->query("oldsix_quest/start");
        time=(int)player->query("oldsix_quest/time");
        over=(int)player->query("oldsix_quest/over");
        lv=(int)player->query("oldsix_quest/lv");

        if(type==2)     {
                ob=present(id,player);
                if(!ob || (string)ob->query("name")!=name)      {
                over=0;
                }
                else    {
                over=1;
                }
        }
        if(over==0)     {
                now_time=time();
                if(now_time<(start+time))
                message_vision("$N对$n道：你还有点时间，快抓紧完成任务去吧。\n",
this_object(),player);
                else    {
		message_vision("$N对$n叹道：你的任务已经过时了，好好反醒一下吧。\n",this_object(),player);
		player->delete("oldsix_quest");
		player->set("bad_quest",player->query("mud_age"));
                }
        }
        else if(over==1)        {
                if(time()<start+time)   {
                message_vision("$N拍了拍$n的肩膀道：这次任务完成的不错，休息一下再接新任务(renwu)吧。\n",this_object(),player);
                player->delete("oldsix_quest");
                if(objectp(ob)) destruct(ob);
                do_jiangli(player,lv,type);
                }
                else    {
                message_vision("$N安慰$n道：太可惜了，你应该早些来交差啊。\n",this_object(),player);
                player->delete("oldsix_quest");
                if(objectp(ob)) destruct(ob);
                }
        }
        return 1;
}

void do_jiangli(object player,int lv,int type)
{
	int exp,skl_exp;
	int score,db;

	if(type==4)	score=50;
	if(type==5)	score=100;
	if(type!=4&&type!=5)	{
	exp=(lv*50)+random(lv*50);
	skl_exp=exp+random(exp);
	if( player->query("combat_exp")<10000)	db=1;
	else if( player->query("combat_exp")<80000)	db=3;
	else if( player->query("combat_exp")<500000)	db=6;
	else db=10;
	skl_exp*=db;
	player->add("combat_exp",exp);
	player->add("wgjn",skl_exp);
	score=10;
	tell_object(player,"你的经验点增加了"+chinese_number(exp)+"点！\n");
	tell_object(player,"你的武功技能增加了"+chinese_number(skl_exp)+"点！\n");
	tell_object(player,"使用分配(fenpei)命令分配你的武功技能点数！\n");
	}
	player->add("score",score);
	tell_object(player,"你的评价上升了"+chinese_number(score)+"点！\n");
}


int recognize_apprentice(object ob)
{
        string banghui;
        if(! stringp(banghui=ob->query("banghui")) ||
                banghui!=query("banghui"))
        return notify_fail(query("name")+"摇头道：你我非亲非故，"+
                RANK_D->query_self(this_object())+"如何敢当。\n");
	if(ob->query("score")<2500)
		return notify_fail(query("name")+"道：你还是多为本教做些实事吧。\n");
        return 1;
}
