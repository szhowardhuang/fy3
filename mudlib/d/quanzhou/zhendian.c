// Room: /d/quanzhou/zhendian.c

inherit ROOM;

void create()
{
	set("short", "正殿");
	set("long", @LONG
正殿之中供奉的是太子神,也有人说是龙神,反正大殿的柱子上都 
雕刻上了盘龙,神像前的香火还挺旺盛. 
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"gulou",
  "southup" : __DIR__"houdian",
  "north" : __DIR__"mazhu",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/fishman.c" : 1,
  __DIR__"npc/fishgirl.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
