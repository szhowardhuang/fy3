//Mr.music yangzhou 药铺

inherit ROOM;

void create()
{
        set("short", "药铺");
        set("long", @LONG
	这里是一家药铺，因为外地商家来往很多，所以药品很齐全，价格
也比较公道。所以天天有人老远赶到这里来购买希罕紧缺的药材。

LONG
        );

        set("exits", ([ 
                      "south" : __DIR__"dongguan2",
                     ]));
        set("objects", ([
                __DIR__"npc/qilaoban": 1
        ]) );

        setup();
}

