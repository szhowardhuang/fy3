// xiaofan.c
inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("小贩",({"xiao fan","xiao","fan"}));
	set("gender", "男性" );
	set("age", 22);
	set("long",
		"沿街叫卖的小贩，忙的不亦乐乎。\n");
	set("chat_chance",15);
	set("chat_msg",	({
		"小贩说道：我这里有不少好东西，侬要买点--伐？\n",
		"小贩掏出毛巾擦了擦额头的汗水。\n",
		(: random_move :)
	}));
	set_temp("apply/attack",5);
	set_temp("apply/defense",10);
	set("suzhou",1);
	set("combat_exp",300);
	set("attitude", "friendly");
	set("vendor_goods", ([
		"包子" : __DIR__"obj/baozi",
		"鸡腿" : __DIR__"obj/jitui",
		"酒壶" : __DIR__"obj/jiuhu",
	]) );
	setup();
}

void init()
{	
	::init();
	add_action("do_vendor_list", "list");
}

