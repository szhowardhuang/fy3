// jingling 艳娘

inherit NPC;
inherit F_VENDOR;
#include <ansi.h>

void create()
{
        set_name("艳娘", ({"yan niang","yan"}));
        set("long",
             HIM"素衣布裙，却掩盖不住他的绝世容貌。更添一分清丽。\n
                 看着使人如沐春风，不生丝毫异念。\n" NOR);
        set("title", HIC "豆腐西施" NOR);
        set("gender", "女性");
        set("age", 22);
        set("rank_info/respect", "姑娘");                     
        set("combat_exp",10000);
        set_temp("apply/defense",10);
        set("vendor_goods", ([
                "清水豆腐" : __DIR__"obj/qs-doufu",
                "水晶豆腐" : __DIR__"obj/sj-doufu",
        ]));
        setup();
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
if( !ob || environment(ob) != environment() ) return;
if(!userp(ob)) return;
message_vision("$N对$n嫣然一笑.\n",this_object(),ob );
if(ob->query("id")=="cyj")
{
          ob->set("qi",10000);
          ob->set("jing",10000);
          command("say 噢，"+ob->query("name")+"公子回来了。");
}
else
{
if (ob->query("gender") == "男性"||ob->query("gender") == "无性")
       message_vision(
        HIM"$N站到柜台前，咋一见这姑娘，不由得呆了，心中只有\n
一个念头：世间竟有如此女子，清丽脱俗，又美艳不可方物。\n
心道：我死了，我死了！世间那来这样的美女?\n" NOR,ob,this_object());
        command("say "+"这位" + RANK_D->query_respect(ob)+"，欢迎光临，请问要点什么？");
        command("say "+"这位" + RANK_D->query_respect(ob)+"，本店的豆腐清爽可口，提神补脑。可是本地特产佳肴哦！");
}

}

