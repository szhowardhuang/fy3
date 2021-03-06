// Room: /d/suzhou/daoxiangcun.c

inherit ROOM;

void create()
{
	set("short", "稻香村");
	set("long", @LONG
稻香村是苏州茶食糖果业的一家老店，相传创建于乾隆年间。稻香村店招牌
之来由，一说早年店主喜读《红楼梦》，于书中得到启示，遂以“稻香村”命名。
由于此店生意兴旺，而人手短缺，因此店主经常招雇一些青年人前来干活，当然
也给一定的酬劳。
LONG
	);
	set("objects",([
		__DIR__"npc/changgong" :2,
		__DIR__"npc/shen" :1,
	]));
	set("exits", ([ /* sizeof() == 1 */
		"west" :__DIR__"chengbeijie3",
]));
	set("no_clean_up", 0);

	setup();
}
void init()
{
	add_action("do_work","work");
}
int do_work()
{
	object me;
	me=this_player();
	if(!living(me))	return 0;
	if((int)query_temp("have_worked")>50)
	return notify_fail("管家探出头来道：今天活都干完了，下次早点来吧。\n");
	if(me->query("sen")<11||me->query("gin")<11||me->query("kee")<11)	{
		write("您老千万注意身体。\n");
		return 1;
	}
	tell_object(me,"你很辛苦的干完了活，真是累得要命！\n");
	add_temp("have_worked",1);
	me->add("kee",-10);
	me->add("gin",-10);
	me->add("sen",-10);
	clone_object("/obj/money/silver.c")->move(me);
	return 1;
}
