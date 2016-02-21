inherit NPC;
#include <ansi.h>
void create()
{
    set_name("坤婆",({"kun po"}));
    set("title","["+HIY+"乾坤二奇"+NOR+"]");
    set("age",63);
    set("gender","女性");
    set("long","身高不足三尺，脸上的只有骨头不见肉，
双手如鸡爪子一般，一件青衫在身上晃晃荡荡.\n");
    set("str",16);
    set("max_kee",1000);
    set("kee",1000);
    set("max_force",1000);
    set("force",1000);
    set("force_factor",40);
    set("combat_exp",100000);
    set_skill("dodge",80);
    set_skill("force",60);
    set_skill("sword",80);
    set_skill("unarmed",60);
    set_skill("parry",60);
    setup();
carry_object("/obj/cloth")->wear();
carry_object("/d/obj/weapon/sword/panguanbi")->wield();
  add_money("gold",1);
}
void init()
{
    ::init();

    add_action("do_agree", "yuanyi");
    add_action("do_agree", "agree");
}
int do_agree(string arg)
{
    object me=this_player(), npc=this_object(), ob;
    string myname=me->name(), myrude=RANK_D->query_rude(me);

    if (!me->query_temp("sandboy/to_be_hit_2"))
   return 0;
    me->delete_temp("sandboy/to_be_hit_2");
    set("force", 2*query("max_force"));
    set("force_factor", 50);
    if (!(ob=query_temp("weapon"))
     || ob->query_temp("skill_type") != "sword")
    {
   destruct(ob);
   ob=new("/d/obj/weapon/sword/panguanbi");
   ob->move(npc);
   command("wield sword");
    }
    command("say 嘿嘿，我叫你有来无回！");
    COMBAT_D->do_attack(npc, me, query_temp("weapon"));
    if(me->query("kee") < 0
    || !present(me, environment()))
    {
   command("say 嘿嘿，"+myrude+"这么差的武功，也敢跟老婆子动手！");
   return 1;
    }
    command("say 有点意思，再看这一招！");
    COMBAT_D->do_attack(npc, me, query_temp("weapon"));
    if(me->query("kee") < 0
    || !present(me, environment()))
    {
   command("say "+myrude+"还是回去练两年再出来闯道吧！");
   return 1;
    }
    command("say 咦，武功果然不错！");
    COMBAT_D->do_attack(npc, me, query_temp("weapon"));
    if(me->query("kee") < 0
    || !present(me, environment()))
    {
   command("say 嘿嘿,"+myrude+"怎是老身对手。");
   return 1;
    }
    me->add_temp("sandboy/可以过去", 1);
    command("say "+myname+"武功不错，老婆子卖个交情，过去吧。");

    return 1;
}
int accept_fight(object me)
{
    command("say 老婆子哪有闲情逗你玩，去!去!去!滚一边去!\n");
    return 0;
}
 