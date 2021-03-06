// music yangzhou's 人参

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("人参", ({ "renshen","shen" }) );
        set("long","一种贵重的滋补药材。\n");
        set("unit", "段");
        set("weight", 50);
        set("value", 1000);
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object ob;
        if( !id(arg) ) return notify_fail("你要吃什麽？\n");

        ob=this_player();
        ob->add("max_kee",1);
        ob->set("kee",(int)ob->query("max_kee"));
        ob->set("eff_kee",(int)ob->query("max_kee"));

        ob->set("force", (int)ob->query("max_force"));

        write("[1;33m你吃下了一段人参。\n[0;37m");

        message("vision", HIY + ob->name() + 
"吃下吃下了一段人参，长吸了一口气，感觉好多了。\n"+NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}
