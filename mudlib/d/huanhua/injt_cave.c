// Room: /d/huanhua/injt_cave.c

inherit ROOM;

void create()
{
	set("short", "见天洞内");
	set("long", @LONG
见天洞内部打扫得一尘不染,烛火常明，壁内各处有凹了进去的地方，供
奉着一栩栩如生的神像。神像前是七星灯火，供奉拜祭的三牲礼酒，坛前
架着一把剑.旁边有一个更小的洞口.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"jt_cave1",
  "out" : __DIR__"jt_cave",
]));

	setup();
	replace_program(ROOM);
}
