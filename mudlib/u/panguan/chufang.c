//make by temp
//ROOM: chufang.c

inherit ROOM;

void create()
{
        set("short", "厨房");
        set("long",@LONG
这是间厨房，浓郁的饭菜香味一个劲地钻进你的鼻子， 你环顾四周
只见，橱柜中摆满了食物，不知道能不能拿？
LONG
        );
        set("exits", ([
                "west" : __DIR__"tingyuan2"
        ]));
        set("objects",([
                __DIR__"npc/shinv":1,
        ]));
        setup();
        replace_program(ROOM);
}
