// xian.c 静闲师太
// Modified By That Oct.1997

inherit NPC;
inherit F_MASTER;
string ask_for_join();

void create()
{
        set_name("静闲师太", ({ "jingxian shitai","jingxian","shitai"}));
        set("long",
           "她是一位中年出家道姑，身穿道袍，眉目之间有一股祥和之气。\n");
        set("gender", "女性");
        set("age", 45);
        set("attitude", "peaceful");
        set("mingwang", 10000);
        set("class", "bonze");
        set("inquiry",([
                "剃度"  : (: ask_for_join :),
                "出家"  : (: ask_for_join :),
                "还俗"  : "峨嵋弟子，不能还俗。你找掌门师太吧。",
        ]));

        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("max_kee", 1000);
        set("max_gin", 500);
        set("force", 1500);
        set("max_force", 1500);
        set("force_factor", 25);
        set("max_sen", 350);

        set("combat_exp", 150000);
        set("score", 1000);
        set_skill("foxuexinde", 80);
        set_skill("force", 70);
        set_skill("dodge", 70);
        set_skill("parry", 70);
        set_skill("unarmed", 65);
        set_skill("sword", 60);
        set_skill("literate", 60);
        set_skill("sixiang-zhang", 60);
        set_skill("anying-fuxiang", 60);
        set_skill("emei-xinfa", 60);
        set_skill("huifeng-jian", 70);
        map_skill("force","emei-xinfa");
        map_skill("dodge","anying-fuxiang");
        map_skill("unarmed","sixiang-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("parry","huifeng-jian");

        create_family("峨嵋派", 4, "弟子");

        setup();
        carry_object("/obj/weapon/sword")->wield();
        carry_object("/obj/armor/ni-cloth.c")->wear();
        carry_object("/obj/armor/ni-xie")->wear();
}
void init()
{
  object ob;
  ::init();
  if (interactive(ob=this_player())&&!is_fighting()) {
  	remove_call_out("greeting");
  	call_out("greeting",1,ob);
    }
        add_action("do_kneel", "kneel");
}

void greeting(object ob)
{
   command("say 这位施主,从此向东,再向北就到伏虎寺了.\n");
  return;
}
void attempt_apprentice(object ob)
{
   if( (string)ob->query("class")!="bonze" )
   {
      command ("say 阿弥陀佛！贫尼不收俗家弟子。施主若想学艺可去找我俗家师妹。");
      return;
   }
   if( (string)ob->query("gender") != "女性" )
   {
      command ("say 阿弥陀佛！贫尼不收男弟子。施主若想学艺可去找我俗家师妹。");
      return;
   }
   if ((int)ob->query("mingwang") < 100)
   {
      command("say " + RANK_D->query_respect(ob) + "你行侠仗义之事还做的不够。");
      return;
   }
   command("say 阿弥陀佛，善哉！善哉！好吧，我就收下你了。");
   command("say 希望你能以慈悲之心，以智慧之力，努力行善，济度众生。");
   command("recruit " + ob->query("id"));
}
#include "tobebonze.h"
