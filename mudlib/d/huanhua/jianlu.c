// Room: /d/new/huanhua/jianlu.c

inherit ROOM;

void create()
{
	set("short", "剑庐");
	set("long", @LONG
剑庐是浣花剑派的重地,当今掌门萧西楼为天下七名剑之一,剑庐隐
于浣花溪旁的树林中,只有一条小路通到此处.通过高大的前门看进去,楼
阁重重,森森然剑气逼人.
LONG
	);
	set("outdoors", "/d/new");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"bamboo",
  "north" : __DIR__"huapath",
]));

	setup();
	replace_program(ROOM);
}
