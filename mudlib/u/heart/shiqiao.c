// Room: /u/uuui/shiqiao.c

inherit ROOM;

void create()
{
        set("short", "小石桥");
        set("long", @LONG
这是一座汉白玉的小石桥，因为龙心小时侯总去
燕京的银锭桥，所以回府后便在这里修了一座小石桥
总想找回而是的乐趣。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"guandao",
  "south" : __DIR__"guandao1",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

