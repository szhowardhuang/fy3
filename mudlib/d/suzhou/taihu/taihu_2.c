// Room: /u/oldsix/room1/taihu_1.c

inherit ROOM;

void create()
{
	set("short", "太湖");
	set("long", @LONG
费了九牛二虎之力，你终于把船划到了岸边。本想在船上歇息歇息，一阵
浪头打了过来。使你不得不重新考虑考虑。
LONG
	);
	set("exits",([
		"southup":"/d/suzhou/huan",
	]));
	set("no_clean_up", 0);
	set("outdoors","room1");
	setup();
	replace_program(ROOM);
}
