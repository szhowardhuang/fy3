// Room: /u/oldsix/room1/ru1.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
西面朦朦胧胧一座大石屋，门上石匾依稀三个大字“花肥房”。房中传来阵
阵的磨刀之声，更显得诡密阴森。你不禁头皮发麻，不知该不该进去看看。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"east":__DIR__"ru1",
		"west":__DIR__"huafang",
]));
	set("no_clean_up", 0);
	set("outdoors","room1");
	setup();
	replace_program(ROOM);
}
