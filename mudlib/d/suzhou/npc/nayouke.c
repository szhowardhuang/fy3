// woodcutter.c

inherit NPC;

void create()
{
	set_name("男游客",({"nan youke","nan","youke"}));
	set("gender", "男性" );
	set("age", 26);
	set("long","前天苏州游玩的外地游客。\n 正饶有兴致的四处游玩。\n");
	set("combat_exp",400);
	set("suzhou",1);
	set_temp("apply/defense",10);
	set_temp("apply/attack",5);
	set("str", 30);
	set("chat_chance", 15);
	set("chat_msg", ({
		"游客自言自语道：苏州可真是个好地方呀。\n",
		(: random_move :)
	}) );
	set("env/wimpy", 10);
	setup();
	carry_object("/obj/cloth")->wear();
}
