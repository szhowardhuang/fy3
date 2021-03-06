// Room: /u/yuki/room/meihuating.c

inherit ROOM;

void create()
{
        set("short", "梅花亭");
        set("long", @LONG
这里就是文明江湖的梅花亭，亭子很小但却很精致，让人很
难相信在梅庄里居然会有这样一个建筑物。到了冬天这里梅花盛
开，别有一番景象。亭子周围及里面都被打扫的干干净净。几位
庄主时常来这里谈天说地。亭子顶端在晚上总有亮光。
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"baiqiao",
]));

        setup();
}

void init()
{
          add_action("do_pa","pa");
}

int do_pa(string arg)
{
        object ob,me = this_player();

        if(arg != "亭子")
                return notify_fail("你要爬什么？\n");

        ob = find_object(__DIR__"shangfang");
        if(!ob)
                ob = load_object(__DIR__"shangfang");
        if(!ob)
                return notify_fail("你要爬什么？\n");

        write("你向亭子上爬去。\n");
        if(me->move(ob))
                 tell_room(ob,me->name()+"从下面爬了上来。\n",({me}));
        return 1;
}
