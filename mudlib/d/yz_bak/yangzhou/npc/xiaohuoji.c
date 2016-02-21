inherit KZZNPC;
inherit F_VENDOR;

string query_save_file() { return DATA_DIR + "npc/听萧伙计"; }
void create()
{
#include <kzznpc.h>
 set("long","年龄不大，但很粗壮的小伙计\n");
set("skills_lv",10);
set("exp_lv",10);
        setup();
carry_object("/obj/cloth")->wear();
add_money("coin",30);
}
void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
add_action("do_vendor_list","list");
}

void greeting(object ob)
{
 if( !wizardp(ob) )
    {
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "小伙计笑道：这位" + RANK_D->query_respect(ob)+ 
"，来壶好酒吧？\n");
                        break;
                case 1:
                        say( "小伙计放下酒壶，说道：这位" + RANK_D->query_respect(ob)
                                + "，请坐请坐。\n");
                        break;
                           }
   }
else{
 say("小伙计满脸堆笑道: 是" + 
ob->query("name")+RANK_D->query_respect(ob) + "来啦？尝尝刚到的好酒吧。\n");
say("小伙计递给你一壶好酒。\n");
clone_object("/d/yangzhou/npc/obj/jiuhu")->move(ob);
    }
}

