// woodcutter.c

inherit NPC;

void create()
{
	set_name("街霸",({"jieba","jie ba","ba"}));
	set("gender", "男性" );
	set("age",30);
	set("long","惹事生非的地痞。\n");
	set("combat_exp",20000);
	set_skill("unarmed",30);
	set_skill("parry",30);
	set_skill("dodge",30);
	set("chat_chance",2);
        set("chat_msg", ({
		"街霸向围墙处张望了一下，神色似乎有些慌张。\n",
		"街霸小声嘀咕道：田伯光。。。不知。。。\n",
		"街霸恶狠狠的骂道：他娘的，还不给老子死出来！\n",
}));
	set("mingwang",-1);
	set("max_force",250);
	set("force",250);
	set_temp("apply/attack",20);
	set_temp("apply/defense",50);
	set_temp("apply/armor",50);
	set_temp("apply/damage",5);
	setup();
	carry_object("/obj/cloth")->wear();
	add_money("silver",5);
}
