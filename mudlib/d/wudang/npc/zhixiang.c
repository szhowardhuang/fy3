// zhixiang.c 制香
inherit NPC;

void create()
{
	set_name("制香道长", ({ "zhixiang daozhang", "zhixiang" }));
	set("long", 
		"他是武当山的制香道长, 兼在这里出售香烛。\n");
	set("gender", "男性");
	set("age", 30);
	set("attitude", "peaceful");
	set("shen_type", 1);

	set("str", 20);
	set("int", 20);
	set("con", 25);
	set("dex", 20);
	
	set("max_kee", 600);
	set("max_gin", 600);
	set("force", 600);
	set("max_force", 600);

	set("combat_exp", 15000);
	set("score", 3000);

	set_skill("force", 60);
	set_skill("dodge", 60);
	set_skill("unarmed", 60);
	set_skill("parry", 60);
	set_skill("sword", 60);
	set_skill("taiji-jian", 60);
//	set_skill("taoism", 60);

	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

	create_family("武当派", 4, "弟子");

	setup();
	carry_object("/obj/weapon/sword")->wield();
}

