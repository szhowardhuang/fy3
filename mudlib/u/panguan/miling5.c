//make by temp
//ROOM: miling5.c

inherit ROOM;

void create()
{
        set("short", "密林");
        set("long",@LONG
好一片茂密是森林，在这里连阳光都不能透进来，你仔细的向左
右观望，不过到处都一样，也许你迷路了。
LONG
        );
        set("exits", ([
                "southdown" : __DIR__"miling3",
                "northup" : __DIR__"wumingsy"
        ]));
        setup();
        replace_program(ROOM);
}
