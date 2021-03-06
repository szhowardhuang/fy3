// /NPC jujian.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("菊剑", ({ "ju jian", "ju"}));
	set("long",
	    "这是个容貌姣好的女子, 瓜子脸蛋,\n"+
	    "眼如点漆, 清秀绝俗.\n"+
	    "你总觉得在哪见过她.\n");
	set("gender", "女性");
	set("age", 18);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("kee", 1000);
	set("max_kee", 1000);
	set("gin", 500);
	set("max_gin", 500);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 20);

	set("combat_exp", 50000);
	set("score", 10000);
	set_skill("force", 70);
	set_skill("unarmed", 70);
	set_skill("dodge", 80);
	set_skill("parry", 70);
	set_skill("sword",80);

	set_skill("liuyang-zhang",80);
  	set_skill("tianyu-qijian",80);
	set_skill("yueying-wubu",80);
	set_skill("duzun-gong", 70);

	map_skill("force", "duzun-gong");
	map_skill("dodge", "yueying-wubu");
	map_skill("unarmed", "liuyang-zhang");
	map_skill("parry", "liuyang-zhang");
	map_skill("sword", "tianyu-qijian");

	create_family("灵鹫宫",3,"弟子");
	setup();
	carry_object("/obj/weapon/sword")->wield();
	carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/lingjiu/obj/doupeng")->wear();
        add_money("silver",15);
}

