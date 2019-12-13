
inherit ROOM;

void create()
{
        set("short", "银杏酒楼");
        set("long", @LONG
这里就是城里最豪华的银杏酒楼，川菜的历史悠久，以
麻辣为主，因为这里一年四季都很潮湿，多吃点辣椒既开胃
健脾，又强身益寿，宽敞明亮而又富丽堂皇的大厅高朋满座，
小二哥满头大汗的招呼着所有嘉宾，不时传来阵阵欢歌笑语
......
LONG);

        set("objects", ([
                __DIR__"npc/xiaoer2" : 1,
            ]));

        set("exits", ([               
                "west"   : __DIR__"chunxilu1",
                "up"   : __DIR__"jiulou2",
            ]));
        setup();
}

