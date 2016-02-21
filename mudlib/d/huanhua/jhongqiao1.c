// Room: /d/new/huanhua/jhongqiao1.c

inherit ROOM;

void create()
{
	set("short", "霁虹桥");
	set("long", @LONG
桥如彩虹,横跨南明河,桥下流水清清,远处青山隐隐,南面
一座楼阁飞檐拱柱,气度不凡.
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/qiu.c" : 1,
  __DIR__"npc/tie.c" : 1,
]));
	set("no_clean_up", 0);
	set("outdoors", "/d/new");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"hbiting",
  "south" : __DIR__"jhongqiao",
]));

	setup();
	replace_program(ROOM);
}
