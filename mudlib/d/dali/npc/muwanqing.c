// muwangqing.c

inherit NPC;

void create()
{
	set_name("木婉清",({ "mu wanqing", "mu", "wanqing" }) );
        set("gender", "女性" );
        set("age", 17);
        set("long", 
"她长得似新月清晕，如花树堆雪，一张脸秀丽绝俗，只是过于苍白，
没半点血色，想是她长时面幕蒙脸之故，两片薄薄的嘴唇，也是血
色极淡，神情楚楚可怜，娇柔婉转。\n");
	set("combat_exp", 200000);
	set("shen_type", 1);
        set("per", 29);
        set("str", 30);
        set("dex", 30);
        set("con", 30);
        set("int", 30);
        set("attitude", "friendly");
	set("max_kee", 1000);
	set("max_gin", 500);
	set("force", 1200);
	set("max_force", 1200);
	set("force_factor", 100);

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("unarmed", 100);
	set_skill("whip", 100);
	set_skill("sword", 100);
	set_skill("kurong-changong", 100);
	set_skill("tiannan-step", 100);
	set_skill("jinyu-quan", 100);
	set_skill("duanjia-sword", 100);
	set_skill("wuluo-zhang", 100);
	set_skill("feifeng-bian",100);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("whip","feifeng-bian");
	map_skill("unarmed", "wuluo-zhang");
	map_skill("sword", "duanjia-sword");
	map_skill("parry", "duanjia-sword");

        setup();
        carry_object(__DIR__"obj/whitecloth1")->wear();
carry_object("/obj/weapon/sword")->wield();
}

