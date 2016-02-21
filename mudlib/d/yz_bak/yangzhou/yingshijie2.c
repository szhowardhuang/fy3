//Mr.music  yangzhou's 引市街 2

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "引市街");
        set("long", @LONG
	你正走在城南引市街的中段，街上人声鼎沸，车马如龙。沿街边
满是各类的商家、店铺和小贩。这里南来北往的路人不断，还不时有游方
郎中，算命打卦的来回游荡。

LONG
        );

        set("outdoors", "/d/yangzhou");
        set("objects", ([
              __DIR__"npc/dipi" : 1,
        ]));

        set("exits", ([
              "north" : __DIR__"yingshijie1",
              "south" : __DIR__"yingshijie3",
              "east"  : __DIR__"zahuopu",
                     ]));
        setup();
        replace_program(ROOM);
}

