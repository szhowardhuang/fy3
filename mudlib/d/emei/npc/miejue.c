// miejue.c 灭绝师太
// Modified by That Oct.1997

inherit NPC;
inherit F_MASTER;
string ask_for_quit();
mixed out_master(mixed arg);

void create()
{
        set_name("灭绝师太", ({ "miejue shitai","miejue","shitai"}));
        set("long",
                "她是峨嵋派的第三代弟子，现任峨嵋派掌门人。\n");
        set("gender", "女性");
        set("age", 62);
        set("attitude", "peaceful");

        set("mingwang", 100000);
        set("class", "bonze");
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "sword.mie" :),
        }) );
        set("inquiry",([
                "剃度"  : "贫尼只知除妖杀魔，不剃度弟子。",
                "出家"  : "贫尼只知除妖杀魔，不剃度弟子。",
                "还俗"  :  (: ask_for_quit :),
        ]));

        set("str", 35);
        set("int", 35);
        set("con", 35);
        set("per", 20);

        set("max_kee", 4000);
        set("max_gin", 2000);
        set("force", 4000);
        set("max_force", 4000);
        set("force_factor", 25);
        set("max_sen", 1500);

        set("combat_exp", 2000000);
        set("score", 1000);
        set_skill("foxuexinde", 150);
        set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("unarmed", 200);
        set_skill("sword", 200);

        set_skill("literate", 100);
     
        set_skill("emei-xinfa", 200);
        set_skill("huifeng-jian", 200);
        set_skill("sixiang-zhang", 200);
        set_skill("anying-fuxiang", 200);

        map_skill("force","emei-xinfa");
        map_skill("dodge","anying-fuxiang");
        map_skill("unarmed","sixiang-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("parry","huifeng-jian");
        create_family("峨嵋派", 3, "掌门");

        setup();
        carry_object("/obj/weapon/sword")->wield();
        carry_object("/obj/armor/ni-cloth")->wear();
        carry_object("/obj/armor/ni-xie")->wear();
}
void init()
{
  add_action("do_kneel","kneel");
}
void attempt_apprentice(object ob)
{
   mapping ob_fam;
   mapping my_fam  = ob->query("family");

   string name, new_name;
   name = ob->query("name");

   if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "峨嵋派")
   {
      command("say " + RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？");
      return;
   }
   switch (random(2))
   {
        case 1: break;
        default:
           if ((string)ob->query("class")!="bonze" )
           {
               command ("say 阿弥陀佛！贫尼不收俗家弟子。");
               return;
           }
           else
           {
               command ("say 阿弥陀佛！贫尼不收弟子。");
               return;
           }
   }
   if ((int)ob->query_skill("foxuexinde",1)<90||(int)ob->query_skill("sixiang-zhuang",1)<90)
   {
      command("say 你本门的功夫修为还太低。");
      return;
   }
   if ((int)ob->query("mingwang") < 50000)
   {
      command("say " + RANK_D->query_respect(ob) + "你行侠仗义之事还做的不够。");
      return;
   }
   if ((string)ob->query("class")=="bonze" )
   {
        name = ob->query("name");
        new_name = "静" + name[2..3];
        ob->set("name", new_name);
        command("say 从今以后你的法名叫做" + new_name + "，恭喜你成为峨嵋第四代弟子!");
   }

   command("say 阿弥陀佛，善哉！善哉！好吧，我就收下你了。");
   command("say 希望你能以慈悲之心，以智慧之力，努力行善，济度众生。");
   command("recruit " + ob->query("id"));
}

string ask_for_quit()
{
    object me;
    mapping myfam;
    me = this_player();

    myfam = (mapping)me->query("family");
    if (!myfam || (myfam["family_name"] != "峨嵋派")) 
        return ("你和峨嵋没有渊源，贫尼不敢给你还俗。\n");
    if( (string)me->query("class")!="bonze" )
        return "阿弥陀佛！出家人不打诳语。你已经是俗家人了。\n";
    me->set_temp("pending/quit_bonze", 1);
        command ("say 阿弥陀佛！善哉！善哉！你一心要还俗，我也不挽留。\n");
        command ("say 我将废去你部分武功。请跪下(kneel)听宣。\n");
        return "如果不愿还俗的，就安心在此修炼吧。\n";
}

int do_kneel()
{
  object ob;
  int level;
  ob=this_player();
  if (ob->query("family/family_name")!="峨眉派")  {
  message_vision("$N突然跪下向$n磕了个头.\n",ob,this_object());
  return 1;
}
if (!ob->query_temp("pending/quit_bonze"))   {
	command("say 跪我干嘛,你神经啊你,还不去练武读经.\n");
	return 1;}
message_vision("$N在$n头顶轻拍两下道:出道入道,自在由心.\n",this_object(),ob);
ob->set("name",ob->query("marks/old_name"));
(int)level=ob->query_skill("foxuexinde",1);
ob->set_skill("foxuexinde",level/2);
tell_object(ob,"你蓄发还俗,佛学心得降低了.\n");
ob->set("class","xiake");
ob->delete("marks/old_name");
return 1;
}

