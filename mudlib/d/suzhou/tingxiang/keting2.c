// Room: /u/oldsix/room1/keting2.c

inherit ROOM;

void create()
{
	set("short", "客厅");
	set("long", @LONG
但见大厅上灯烛辉煌，可是只照亮了东边一面，几个粗豪大汉正在放怀畅饮，
桌上杯盘狼藉，地下椅子东倒西歪。西首望去，但见二十余人都是白袍，肃然而
坐，桌上只点了一根蜡烛，照见近处那六七人个个脸上一片木然，既无喜容，亦
无怒色，当真有若僵尸一般。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"south":__DIR__"ru6",
		"east" :__DIR__"yuemen",
		"west":__DIR__"ru7",
		"north":__DIR__"ru9",
]));
	set("objects",([
		__DIR__"npc/yao" :1,
		__DIR__"npc/zhu" :1,
		__DIR__"npc/sima" :1,
		__DIR__"npc/zaiding" :1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
