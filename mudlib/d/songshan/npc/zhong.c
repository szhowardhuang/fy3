// zhong.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
void create()
{
        set_name("钟镇", ({ "zhong zhen", "zhen", "zhong" }) );
        set("nickname", "九曲剑");
        set("gender", "男性");
        set("class", "swordsman");
        set("age", 45);
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("force", 2000);
        set("max_force", 2000);
        set("force_factor", 30);
        set("max_kee",2000);
        set("max_gin",1200);
        set("combat_exp", 600000);
        set("shen_type", -1);

        set_skill("unarmed", 120);
	set_skill("songyang-zhang",120);
        set_skill("sword", 120);
set_skill("poyun-zhang",120);
        set_skill("force", 120);
	set_skill("hanbing-zhenqi",120);
        set_skill("parry", 120);
        set_skill("dodge", 120);
        set_skill("songshan-jianfa", 120);
        set_skill("fuguanglueying", 120);

        map_skill("sword", "songshan-jianfa");
        map_skill("parry", "songshan-jianfa");
        map_skill("dodge", "fuguanglueying");
	map_skill("force","hanbing-zhenqi");
	map_skill("unarmed","songyang-zhang");

        create_family("嵩山派", 13, "弟子");
        setup();

carry_object("/obj/weapon/sword")->wield();
carry_object("/obj/cloth")->wear();
}

void init()
{
        object ob;

        ::init();

        if( interactive(ob=this_player()) && !is_fighting())
        {
                remove_call_out("greeting");
                call_out("greeting",1,ob);
        }
}

void greeting(object ob)
{
        string family;

        family=(string)ob->query("family/family_name");
	if(family=="嵩山派")
	command("say 我嵩山派必定会成为武林第一大门派。");
	else
	command("say "+ob->query("name")+"，不要在本派乱窜！");
}

void attempt_apprentice(object ob)
{
	string fam;

	fam=(string)ob->query("family/family_name");
	if(! fam || fam!="嵩山派")
	command("say 哼，钟某可不敢收其他门派的弟子。");
	else if((int)ob->query("mingwang")>-5000)
	command("say 我嵩山弟子做事要心狠手辣，"+
        RANK_D->query_respect(ob)+"还做的不够啊。");
	else if((int)ob->query_skill("hanbing-zhenqi",1)<60)
	command("say 本门寒冰真气的心法，"+RANK_D->query_respect(ob)
	+"还要多花些功夫啊。");
	else	{
	command("say 呵呵，既然你如此诚心，那钟某就收下你吧。");
       command("recruit " + ob->query("id") );
       ob->set("class","swordsman");
	}
}
