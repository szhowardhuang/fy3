//music  yangzhou's 荷花池

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "荷花池");
        set("long", @LONG
	你现在正站在风景秀丽，碧波荡漾的荷花池边，每年夏季，池中
荷花盛开，娇艳多姿，令无数游人驻足，更使文人墨客留恋忘返。轻风吹
来，池面泛起一阵涟漪，使你有一种想跳下去的冲动。池边是一大片绿草
坪，是门徒们休息和学习的地方。

LONG
        );

        set("outdoors", "/d/yangzhou");
        set("sleep_room",1);
        set("objects", ([
        //      __DIR__"obj/box" : 1,
        ]));

        set("exits", ([
              "east" : __DIR__"xiangzhai",
                     ]));
 //       create_door("northwest", "竹门", "southeast", DOOR_CLOSED);
        setup();
}

int init()
{

add_action("do_jump","jump");
add_action("do_jump","tiao");
add_action("do_back","back");
add_action("do_chat","chat");

}

int do_chat()
{
return 0;
}

int do_jump()
{
if( living(this_player()) ==0 ) return 1;

say(this_player()->query("name")+"扑通一声，跳下池去\n");
tell_object(this_player(),"你纵身跳下池去.\n");
this_player()->move("/d/yangzhou/chizhong");
return 1;

}

int do_back()
{
return 1;
}

