// Room: /d/chengdu/wenzai/houyuan.c

inherit ROOM;

void create()
{
	set("short", "后院");
	set("long", @LONG
这里是个大大的后院，古树参天，知了在树上不停地叫着，有个
仆人在那里清扫着地面。
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/atu" : 1,
]));
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"zoulang3",
  "east" : __DIR__"zoulang5.c",
  "north" : __DIR__"zoulang4",
]));
	set("outdoors", "city3");

	setup();
	replace_program(ROOM);
}
