// Room: /d/huanggon/chaguan.c

inherit ROOM;

void create()
{
	set("short", "高升茶馆");
	set("long", @LONG
你一走进来,就闻到一股茶香沁入心脾,精神为之一爽.几张八仙桌
一字排开,坐满了客人,或高声谈笑,或交头接耳。茶馆前端是个小高台,
说书的老头正口沫四溅的说'英烈传'.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/liuwusheng.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"ndajie2",
]));

	setup();
	replace_program(ROOM);
}
