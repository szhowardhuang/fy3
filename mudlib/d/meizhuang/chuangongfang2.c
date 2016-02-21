// Room: /d/suzhou/meizhuang/chuangongfang1.c

inherit ROOM;

void create()
{
	set("short", "传功房");
	set("long", @LONG
这儿是秃笔翁弟子的练功场所。除了在房间四周摆放了些兵刃、护具
之外，整个屋内空空荡荡，显而是为了练功方便。东面有个屋室便是秃笔
翁居住的地方了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	"west":__DIR__"heilang5",
	"east":__DIR__"tubiwengju",
]));
	set("objects",([
	//	 __DIR__"obj/bingqijia3":1,\
		__DIR__"npc/chuangongdizi3":1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
