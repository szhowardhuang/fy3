//Mr.music yangzhou 赌场东风厅

#include <pig.h>

inherit "/std/room/pigroom";

string look_table();
string look_scoreboard();
string look_rules();


void create()
{
        set("short", "赌场东风厅");
        set("long", @LONG
	这是个热火朝天的大赌场，场里笑声哭声叫骂声乱成一团，不论
是大亨还是小贩，休暇时间总来碰碰运气。这里是赌场的东风厅。房间中
心是拱猪桌，桌上是一本纪录册，桌角有个牌子。

LONG
        );
        set("pigging", 1);
        set("no_fight", "1");
        set("item_desc", ([
                "table" : (: look_table :),
                "zhuo" : (: look_table :),
                "ce" : (: look_scoreboard :),
                "paizi" : "请务必读 help pig_cmds 和 help pig_rules。\n",
        ]));

        set("exits", ([ 
                      "west" : __DIR__"duchang",
                     ]));
        set("objects", ([
                __DIR__"npc/duchangxiaoer": 1 ,
        ]) );

        setup();
}



string look_table()
{
	if (this_player()->query_temp("pigging_seat"))
		return table_str(this_player()->query_temp("pigging_seat"));
	return table_str("");
}

string look_scoreboard()
{
	return scoreboard_str();
}

int valid_leave(object me, string dir)
{
	if (me->query_temp("pigging_seat"))
		return notify_fail("先离开拱猪桌才能行动。\n");
	return ::valid_leave(me, dir);
}
