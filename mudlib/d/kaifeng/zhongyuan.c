// Room: /d/kaifeng/zhongyuan.c

inherit ROOM;

void create()
{
	set("short", "中院");
	set("long", @LONG
中院分为前后两部分,院子的正中有座铁制浮屠，高七层，雕刻
精美花纹。前边部分除中间的行道外，两边是花圃，各种一棵高大
的菩提树。后边铺着青石，通向大雄宝殿。南边是天王殿，东边是
素斋厨，西面是浴室。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/obj/tiefutu.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"tianwang",
  "north" : __DIR__"daxiong",
  "east" : __DIR__"chufang",
  "west" : __DIR__"yushi",
]));
	set("outdoors", "/d/kaifeng");

	setup();
	replace_program(ROOM);
}
