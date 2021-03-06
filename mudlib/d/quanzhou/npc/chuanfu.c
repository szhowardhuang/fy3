inherit NPC;
void reset();
void create()
{
        set_name("船夫", ({ "chuan fu","chuanfu"}) );
        set("gender", "男性" );
        set("age",40);
        set("str",30);
        set("int",25);

        set("max_kee",900);
        set("kee",900);
        set("max_sen",900);
        set("sen",900);
        set("combat_exp",3000);
        set_skill("unarmed",100);
        set_skill("parry",120);
        setup();
        carry_object("/obj/armor/cloth")->wear();
        add_money("silver",5);
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
	                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
	object me,room;
	me=this_object();

        if( !ob || environment(ob) != environment() ) 
		return;
              room=load_object("/d/quanzhou/haigang");
              room->delete("exits/enter");
       message_vision("$N高喊一声,楼船缓缓开出了安海港.\n",me);
              load_object("/d/quanzhou/duchuan")->delete("exits/out");
              message("vision","一片号子声中,楼船缓缓离开海港!\n",room);
		call_out("arrive",20+random(20),ob);
	return;
}
void arrive(object ob)
{ object room;
  int i;
  
    if (!living(ob)||environment(ob)!=environment()) 
           { reset();
             return;
            }
    i=ob->query_temp("luyin/target");
    switch(i)
   {   
               case 1:
                   room=load_object("/d/hainan/haibian");
                  break;
               case 2:
                   room=load_object("/d/taiwan/matou");
                  break;
     }
    message_vision("船夫指着越来越近的码头对$N道:到点啦,您老下船吧!\n",ob);
    message_vision("$N顺着长长的甲板走下船去.\n",ob);
   
    ob->delete_temp("luyin");
    tell_room(room,ob->query("name")+"从一艘刚靠岸的楼船上走了下来!\n");
            ob->move(room);
    reset();
return;
}
void reset()
{   
    load_object("/d/quanzhou/haigang")->set("exits/enter","/d/quanzhou/duchuan");
    load_object("/d/quanzhou/duchuan")->set("exits/out","/d/quanzhou/haigang");

       return;
}