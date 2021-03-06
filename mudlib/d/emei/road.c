// Room: /d/emei/road.c

inherit ROOM;

void create()
{
	set("short", "湖边");
	set("long", @LONG
这是一条通向报国寺的大道,道路沿红珠湖(lake)而行,清风徐来
水波不兴,路边植满了枫树,茂密浓郁,鸟语花香,气候宜人.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/bei.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"fenhuang",
  "south" : __DIR__"xiaolu1",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "lake" : "湖上隐隐传来船夫兴起而随口唱起的号子,极目四望,孤帆点点.
",
]));
	set("outdoors", "/d/emei");

	setup();
}

int valid_leave(object me,string dir)
{
	string fam;
	object npc;

	fam=(string)me->query("family/family_name");
	npc=present("bei jinyi",environment(me));
	if( fam && fam!="峨嵋派" && objectp(npc) &&
		dir=="northup")
	return notify_fail("贝锦仪轻喝一声：峨嵋禁地闲人莫入！\n");
	return ::valid_leave(me,dir);
}


