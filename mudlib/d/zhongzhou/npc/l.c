#include <ansi.h>
inherit NPC;
void create()
{
        set_name("李半仙", ({ "li banxian", "li" , "banxian"}) );
        set("long",
                "李半仙是个鹤发童颜的老人！\n");
        set("title", BLU"疯疯癫癫"NOR);
        set("attitude", "peaceful");
        set("combat_exp",4000000);
        set("str",60);
        set("per",10);
        set("int",80);
        set("force_factor", 100);
        set("max_force",5000);
        set("force",5000);
        set_skill("unarmed", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("force",200);
        set_skill("chanchu-bufa",200);
        set_skill("hamagong",200);
        set_skill("shexing-diaoshou",200);
        set_skill("lingshe-zhangfa",200);
        set_skill("staff",200);

        map_skill("dodge", "chanchu-bufa");
        map_skill("force", "hamagong");
        map_skill("parry", "lingshe-zhangfa");
        map_skill("unarmed", "shexing-diaoshou");
        map_skill("staff", "lingshe-zhangfa");
        
        set("inquiry", ([
                "判师记录"          :"你找对人了，就是我能给你减判师记录(jian 判师记录)。\n",
        ]) );
        setup();

        carry_object("/obj/cloth")->wear();
        carry_object("/d/baituo/obj/tianmozhang")->wield();

}
int accept_fight(object me)
{
        command("say 李半仙说：你还不配和我过招。");
        return 0;
}
void init()
{
        add_action("do_jian","jian");
}

int do_jian(string arg)
{
        object me;
        me= this_player();
        if (arg != "判师记录") 
                return notify_fail("你要减什么？\n");
        if (me->query("betrayer",) < 1) 
                return notify_fail("你判过师么？\n");
        message_vision(MAG"$N跪在了地上，开始忏悔背叛师门的往事，后悔呀。。。后悔。。。\n\n"NOR,me);
        me->set("combat_exp", me->query("combat_exp") - me->query("combat_exp") /10);
        me->add("betrayer",-1);
        me->start_busy(2);
        me->set("mingwang",0);
        return 1;
}

