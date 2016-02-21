// Room: /d/suzhou/canhe/dating.c

inherit ROOM;

void create()
{
	set("short", "大厅");
	set("long", @LONG
进入大厅，迎面的墙头上挂着一幅画。画中一身着黄袍的中年男子骑于马上，
手持马鞭遥指前方，一副志得意满、踌躇满志的神情。画边站着一位青年男子，
正沉迷于画中，并没注意到你进来。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"west":__DIR__"qianting",
		"east":__DIR__"houting",
]));
	set("objects",([
		__DIR__"npc/murongfu":1,
]));
	set("no_clean_up",0);

	setup();
	replace_program(ROOM);
}
