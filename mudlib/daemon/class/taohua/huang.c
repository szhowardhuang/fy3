#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();
string ask_me();

void create()
{
    set_name("黄药师", ({"huang yaoshi", "huang", "yaoshi"}));
    set("title", "桃花岛主");
    set("nickname", HIY "东邪" NOR );
    set("gender", "男性");
    set("age", 42);
    set("long", 
        "他就是桃花岛主。行事好恶全由己心，因此被人称作「东邪」。\n");
    set("attitude", "peaceful");
    set("class", "scholar");
        
    set("str", 21);
    set("int", 30);
    set("con", 26);
    set("dex", 30);

    set("chat_chance", 1);
    set("chat_msg", ({
        "黄药师叹了口气道：“唉 …… 蓉儿这苦命的孩子，从小就没了娘 ……”\n",
        "黄药师低头沉思，悠然不语。\n",
    }));
    set("inquiry", ([
        "黄蓉"     : "你敢直称我女儿的闺名？ \n",
        "九阴真经" : "如果你能帮我取得真经上册，我一定重重谢你。\n",
    ]));

    set("kee", 3000);
    set("max_kee", 3000);
    set("gin", 3000);
    set("max_gin", 3000);
    set("force", 3500);
    set("max_force", 3500);

    set("combat_exp", 1500000);
    set("score", 0);
         
    set_skill("force", 200);             // 基本内功
    set_skill("bibo-shengong", 200);     // 碧波神功
    set_skill("claw", 200);              // 基本爪法
    set_skill("hand", 200);              // 基本手法
    set_skill("finger", 200);            // 基本指法
    set_skill("tanzhi-shentong", 200);   // 弹指神通
    set_skill("unarmed", 200);           // 基本拳脚
    set_skill("strike", 200);            // 基本拳脚
    set_skill("luoying-zhang", 200);     // 落英神剑掌
    set_skill("dodge", 200);             // 基本躲闪
    set_skill("yingxian-steps", 200);    // 影仙步法
    set_skill("parry", 200);             // 基本招架
    set_skill("sword", 200);             // 基本剑法
    set_skill("luoying-shenjian", 200);  // 落英神剑
    set_skill("yuxiao-jian", 200);       // 玉箫剑法
    set_skill("literate",150);           // 读书识字
        
    map_skill("force"  , "bibo-shengong");
    map_skill("finger" , "tanzhi-shentong");
    map_skill("unarmed", "luoying-zhang");
    map_skill("dodge"  , "yingxian-steps");
    map_skill("parry"  , "luoying-shenjian");
    map_skill("sword"  , "yuxiao-jian");

    create_family("桃花岛", 1, "岛主");
    setup();
        
    
}

void attempt_apprentice(object ob)
{
    if (ob->query_int() < 30) {
        command("say 我不收资质差的弟子，您请回吧！");
                return;
    }
    if ((int)ob->query_skill("bibo-shengong",1) < 50 ) {
        command("say 你的本门内功心法太低了,还是努努力先提高一下吧!");
                return;
    }
    if ((int)ob->query("shen") >100000 || (int)ob->query ("shen") < -100000 ) {
        command("say 我桃花岛与世隔绝，向来不与您这种成名人物打交道，您请回吧！");
                return;
        }
    command("say 很好，很好。");
    command("recruit " + ob->query("id"));
}

int recognize_apprentice(object ob)
{
        mapping myfam;
        myfam = (mapping)ob->query("family");
        if ( myfam["family_name"] == "桃花岛") return 1 ;
        if ((int)ob->query_temp("tmark/黄") == 1 )
        message_vision("黄药师看了看$N，说道：咱们现在是谁也不欠谁,\n"
                          "你不要再找我学习技艺了。\n", ob);
        if (!(int)ob->query_temp("tmark/黄"))
                return 0; 
        ob->add_temp("tmark/黄", -1);
        return 1;
}




