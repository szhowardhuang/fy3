// Room: /open/stst/sazai/qianting.c

inherit ROOM;

void create()
{
        set("short", "前厅");
        set("long", @LONG
        这里就是野羊寨的前厅了，前厅装修的简单而朴素，一般的客人都
是在前厅招待。前厅的东边是帐房，西边是山寨的休息室，北边是大厅，南
面是练武场。

LONG

        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"lu3",
  "west" : __DIR__"lu4",
  "north" : __DIR__"lu6",
  "east" : __DIR__"lu5",
]));
	set("objects",([
		__DIR__"npc/datoumu":2,
]));

        setup();
        replace_program(ROOM);
}

