// Room: /d/suzhou/npc/yaopu.c

inherit ROOM;

void create()
{
	set("short", "回春堂");
	set("long", @LONG
刚进房门，一股刺鼻的药味扑面而来，你下意识的皱了皱眉。迎面是个药柜
，小抽屉上下好几排，也不知收藏了多少药材。几包还没扎好的小纸袋散放在桌
上。一位身着长袍的老者和蔼的看着你。
LONG
	);
	set("objects",([
		__DIR__"npc/xuemuhua" :1,
	]));
	set("exits", ([ /* sizeof() == 1 */
		"east" :__DIR__"chengbeijie2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
