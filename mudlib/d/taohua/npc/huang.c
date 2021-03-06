#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("黄药师", ({ "huang yaoshi", "huang" }));
        set("title",  "东邪" );
        set("long", "白发苍苍，锦衣长袍的一个老者。他就是桃花岛岛主。\n");
        set("gender", "男性");
        set("age", 65);
        set("class", "officer");
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 50);
        set("int", 30);
        set("per",28);
        set("con", 35);
        
        set("max_kee", 2500);
        set("max_gin", 1000);
        set("force", 2500);
        set("max_force", 3000);
        set("force_factor", 100);
        set("combat_exp", 3000000);
        set("score", 300000);

        set_skill("force", 210);
        set_skill("dodge", 210);
        set_skill("parry", 210);
      
        set_skill("sword", 210);
        set_skill("yingxian-steps", 210);
        set_skill("bibo-shengong", 210);
        set_skill("luoying-zhang", 210);
        set_skill("luoying-shenjian", 210);
        set_skill("yuxiao-jian", 210);
        set_skill("unarmed", 210);
        set_skill("tanzhi-shentong", 210);
        set_skill("literate", 250);

        map_skill("force", "bibo-shengong");
        map_skill("dodge", "yingxian-steps");
        map_skill("unarmed","tanzhi-shentong");
        map_skill("parry","luoying-shenjian");
        map_skill("sword", "yuxiao-jian");

        setup();
        carry_object("/d/taohua/obj/baipao")->wear();
        add_money("silver", 50);

        create_family("桃花岛",18,"岛主");
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query_skill("bibo-shengong",1) < 80)
        {
                command("say 你的本门内功心法太低了，还是努努力先提高一下吧。");
                return;
        }
        if ((int)ob->query("mingwang")<50000)   {
                command("say 我心情不好，见到你獐头鼠目的样子就烦。赶快离开这里吧！");
                return;
        }
        command("say 很好，既然入我门来就得忠心为主。");


        command("recruit " + ob->query("id"));
        ob->set("title","桃花岛第二代弟子");
}

