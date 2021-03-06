//jiabu.c
inherit NPC;

void create()
{
	set_name("贾布", ({ "jia bu", "jia", "bu"}) );
	set("gender", "男性" );
	set("age", 45);
	set("banghui", "日月教");
	set("bh_rank","青龙堂长老");
	set("long", "他蜡黄瘦脸，两边太阳穴高高鼓起，变如藏了一枚枚核桃似的。\n");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("per", 15);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 29);

	set("max_kee", 1000);
	set("max_gin",1000);
	set("force", 2000);
	set("max_force", 2000);
	set("combat_exp", 350000);
	set("score", 30000);
	set("force_factor", 200);
	set_skill("force", 140);
	set_skill("dodge", 90);
	set_skill("unarmed", 100);
	set_skill("parry", 80);
	set_skill("hammer",100);
	set_skill("blade",100);
	set_skill("taiji-shengong",70);
	set_skill("tiyunzong", 80);
	set_skill("taiji-dao", 100);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	
	map_skill("parry", "taiji-dao");
	map_skill("blade", "taiji-dao");

	set("chat_chance", 2);
	set("chat_msg", ({
		 "贾布叹道: “攘外必先安内，堂中令牌被盗若是被教主知道，我命休矣。”\n"
        }) );
	setup();
        carry_object(__DIR__"obj/dadao")->wield();
        carry_object(__DIR__"obj/cloth")->wear();
      

}



void attempt_apprentice(object ob)
{
     command("say 我这点皮毛，不敢，不敢!\n");
}

