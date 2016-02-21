
//Mr.music  yangzhou's 听萧园

inherit ROOM;

void create()
{
        set("short", "听萧园");
        set("long", @LONG
	这里是路边的一座小酒店，因靠近荒野，酒客也不是很多，
但好象客店的老板很有钱，伙计也都很精神。当街一个“酒”字招牌
，白底黑字，非常醒目。

LONG
        );

        set("exits", ([
                "east"   : __DIR__"siqiaoyanyu",
        ]));

        set("item_desc", ([
                       "招牌" : "白底黑字，非常醒目的酒字" , 
                          ]));
        
        set("objects", ([
		__DIR__"npc/txlaoban":1,
                __DIR__"npc/nanhai": 1,
                __DIR__"npc/nuhai": 1,  
        ]));

        setup();
}





