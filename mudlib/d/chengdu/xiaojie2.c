// Room: /d/chengdu/xiaojie2.c
// oooc 1998/06/21 

inherit ROOM;

void create()
{
	set("short", "小街");
	set("long", @LONG
这是一条青石板铺成的小街，路面非常干净。这是因为每天清
晨都会有工人把这里打扫一遍。朝东南边看,天气好的话，还可以
隐约看到风雨亭的一角。
LONG
	);
set("outdoors","/d/chengdu");

	set("exits", ([
                "north" : __DIR__"xiaojie1",
                "east" : __DIR__"xiaojie3",
	]));
        set("objects", ([
            __DIR__"npc/kid" : 1,
            __DIR__"npc/liumang" : 1,
        ]));

	setup();
	replace_program(ROOM);
}

