// woodcutter.c

inherit NPC;

void create()
{
	set_name("中州地痞",({"di pi"}));
	set("gender", "男性" );
	set("age", 26);
	set("long","不务正业，游手好闲的地痞。\n");
	set("combat_exp",750);
	set_temp("apply/attack",15);
	set_temp("apply/defense",15);
	set("suzhou",1);
	set("mingwang",-1);
	set("str", 30);
	set("chat_chance", 15);
	set("chat_msg", ({
		"地痞不怀好意的冲你笑了笑，你下意识的摸了摸钱袋。\n",
		"地痞冲你喝道：看什么看，没见过流氓！？\n",
	}) );
	setup();
	carry_object("/obj/cloth")->wear();
}
