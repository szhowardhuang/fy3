// music   yangzhou's 船老大

inherit NPC;

void yangzhou_suzhou();
int enter_boad(string);

void create()
{
	set_name("船老大",({"chuan laoda","laoda"}));
	set("gender", "男性" );
	set("age", 54);
	set("long",
		"这是位饱经风雨的船家，看上去强壮精悍。\n");
	set("mingwang", 2);
	set("combat_exp", 50000);
        set("str", 22);
        set("kar", 12);
        set("con", 12);
        set("int", 12);
	set("attitude", "peaceful");
        set("inquiry", ([
                       "chuan" : "不知您想到哪里啊? \n" ,
                       "船" : "不知您想到哪里啊? \n", 
                       "suzhou" : (: yangzhou_suzhou :),
                       "苏州" : (: yangzhou_suzhou :),
                       ]) );
	setup();
        carry_object("/obj/cloth")->wear();
        carry_object(__DIR__"obj/chuanjiang")->wield();
	add_money("coin", 100);
}

void init()
{
add_action("enter_boat","enter");
add_action("enter_boat","jin");
add_action("enter_boat","shang");
}

int enter_boat(string arg)
{
if ((arg=="boat")||(arg=="chuan")) 
 {
  if( this_player(1)->query_temp("in_river") != 0 )
     {
      say("船老大抱歉的说：船都出去了，稍候片刻，船就到。\n");
      return 1;
    } 
  if( (this_player(1)->query_temp("yz_sz"))==1 )
   {
   tell_object(this_player(1),"船家说：客官一路平安.\n");
   say(this_player(1)->query("name")+"上了小船，离岸上路. \n");
   this_player(1)->move("/d/yangzhou/yunhe1");
   return 1;
   } 
  else
   {
   tell_object(this_player(1),
   "船老大对你大喊道：别动我的船！\n你一惊，差点掉下水去。\n");
   return 1;
   }
 }
// else tell_object(this_player(1),"你想到哪？\n");
return 0;
}

void yangzhou_suzhou()
{
say ("船老大说道：扬州和苏州之间走水路，又快又安全，只要五两银子.\n");
say ("船老大奸笑了几声，说道：陆路可不好走啊，路难走还不定会遇到土匪.\n");
return;
}


int accept_object(object who, object ob)
{
        if ( ((int)who->query_temp("yz_sz")) !=0 )
           {
           message_vision("船老大笑笑说：客官不必再付钱了！\n", who);   
           return 1;
           }
        if (ob->query("money_id") && ob->value() >= 500) 
           {
                message_vision("船老大眼睛一眯，向$N说：客官请上船。\n", 
who);
                who->set_temp("yz_sz",1);
                return 1;
          }
        return 0;
}

