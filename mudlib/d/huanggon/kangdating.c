// Room: /d/huanggon/kangdating.c

inherit ROOM;

void create()
{
	set("short", "王府大厅");
	set("long", @LONG
王府大厅是康亲王平时接见下属的地方,大厅中八根朱红的柱子撑
起屋顶,柱子间是白纱宫灯,一排贝雕屏风挡住后堂入口,几张桌椅按主
客位分别摆放.
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/qiyuankai.c" : 1,
  __DIR__"npc/shzhshangren.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"tingyuan",
  "north" : __DIR__"tianjin",
]));

	setup();
	replace_program(ROOM);
}
