// Room: /d/hangzhou/dating.c

inherit ROOM;

void create()
{
	set("short", "大厅");
	set("long", @LONG
石龙武场的大厅用水磨石铺就.北面的大屏风上写了个大大的[武]字.
后面似乎有路可通.中间摆的酸枣木太师椅上坐着武场主人,两边的兵器
架上摆满了各类武器.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"back_yard",
  "south" : __DIR__"front_yard",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shilong.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
