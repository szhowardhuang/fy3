// music   yangzhou's 书场看客

inherit NPC;

void create()
{
	set_name("书场看客", ({ "kanke", "ke", "kan ke" }) );
	set("gender", "男性" );
	set("age", 28);
	set("long",
		"这是位书场的老客人了。\n");
	set("mingwang", 1);
	set("combat_exp", 6000);
        set("str", 2);
        set("con", 2);
        set("int", 2);
	set("attitude", "peaceful");
	setup();
        carry_object("/obj/cloth")->wear();
	add_money("coin", 5);
}


