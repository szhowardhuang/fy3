
inherit ROOM;
int do_out(string arg);

void create()
{
set("short","玉带桥");
        set("long",
"这座大石桥宽阔而雄壮,两端桥栏杆上突起盘龙的石柱.桥下的水流急
冲而过,看上去有些浑浊,据说时常有人在此跳河(out),前面不远就是皇宫
的正门,南边通向天安门.\n");
        set("outdoors", "city2");
        set("exits", ([
                "north" : __DIR__"zhengmen",
                "south" : __DIR__"tian_anm",
"westdown":__DIR__"bridge2",
"eastdown":__DIR__"bridge3",
        ]));
	set("no_clean_up", 0);
        setup();
}

void init()
{
	add_action("do_out", "out");
}

int do_out(string arg)
{
	object me;
	int i, ging_cost, qi_cost;

	me = this_player();
	i = (int)me->query_skill("dodge", 1) + random(50);
	ging_cost = 300 / (int)me->query("int");
	qi_cost = 300 / (int)me->query("int");
	if(((int)me->query("gin") < ging_cost) || ((int)me->query("kee") < qi_cost))
		i = 0;

	message_vision("$N翻过石栏，一个纵身，跳了下去。\n", me);
	if ( i < 75)
		{
	        message_vision("一股潜流立刻把$N吞没了。\n", me);
		me->die();
	        }
	else if( i < 100)
		{
	        message_vision("一股潜流立刻把$N吞没了。\n", me);
		me->unconcious();
		switch( random(2) ) {
		case 0:
		me->move(__DIR__"bridge2");
			break;
		case 1:
		me->move(__DIR__"bridge3");
			break;
		message_vision("一股潜流把$N冲回岸边。\n", me);
		}
	        }
	else {
		switch( random(5) ) {
		case 0:
		message_vision("一股潜流把$N冲回岸边。\n", me);
		me->move(__DIR__"bridge2");
			break;
		case 1:
		message_vision("一股潜流把$N冲回岸边。\n", me);
		me->move(__DIR__"bridge3");
			break;
		case 2:
		case 3:
		case 4:
		message_vision("$N在水中昏昏沉沉地胡乱挣扎，突然之间触到了一面硬壁。\n", me);
		message_vision("$N恍若抓住了救命稻草，贴着滑溜溜的硬壁就浮出了水面。\n", me);
		message_vision("$N吐了一口水，抬头一看，原来身在一口井中。\n", me);
         	me->move("/d/huanggon/inwell");
		break;
		}
		if( (i > 125) && me->querk_skill("dodge",1)<101)
			me->improve_skill("dodge", 2*(int)me->query_skill("dodge", 1));
		me->receive_damage("gin", ging_cost );
		me->receive_damage("kee", qi_cost );
	     }
	return 1;
}
