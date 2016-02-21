// Room: /d/new/robber/road3.c

inherit ROOM;

void create()
{
	set("short", "大路");
	set("long", @LONG
一条笔直的大路，足可容四马并驰。路的左面是一片树林，右边的
草丛中隐约有一条小路。向东，不远就是天下会的总舵了。
LONG
	);
	set("no_clean_up", 0);
set("outdoors","/d/jiangnan");
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"road5",
  "south" : __DIR__"road2",
  "east" : __DIR__"road4",
]));

	setup();
	replace_program(ROOM);
}
