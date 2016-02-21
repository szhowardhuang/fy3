// Room: /d/huanggon/shilaozoulang.c

inherit ROOM;

void create()
{
	set("short", "石牢走廊");
	set("long", @LONG
石屋内甚是阴暗,一条走廊通向北边的一座小堂,走廊之侧搭了一座
行灶,一名老汉正在煮饭,从北边小堂中传来铁链叮当作响的声音.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shaolaohan.c" : 1,
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "south" : (: look_door,     "south" :),
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shilaoxiaotang",
  "south" : __DIR__"shiwu",
]));

	setup();
	replace_program(ROOM);
}
