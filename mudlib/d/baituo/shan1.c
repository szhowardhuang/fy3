// Room: /d/baituo/shan1.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
一条上山的路，两边是陡峭的悬崖。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"shan",
]));

	setup();
}
void init()
{
        add_action("do_jump","jump");
}

int do_jump(string arg)
{
        object me;
        me = this_player();
        if (arg != "悬崖") return 0;
        {
        if (me->query_skill("dodge") < 120 )
                return notify_fail("你不想活了？跳下去不是摔死了么！\n");
        if (me->query("combat_exp") < 300000)
                return notify_fail("你在江湖上连个名都没闯出来，就想自杀了？\n");
        if(random(30) < (int)me->query("cor")) 
                return notify_fail("你深呼一口气，刚想跳下悬崖，又害怕了。。。\n");
        message_vision("只见$N纵身一跃，跳下了深深的悬崖。\n\n",me);
        me->start_busy(3);
        me->move(__DIR__"xia");
        me->add("sen",-80);
        me->add("kee",-80);
        me->add("gin",-80);
        return 1;
        }       
}

