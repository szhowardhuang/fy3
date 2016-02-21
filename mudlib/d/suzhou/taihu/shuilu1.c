// Room: /u/oldsix/room1/shuilu1.c

inherit ROOM;

void create()
{
	set("short","太湖");
	set("long", @LONG
你发现自已正坐在一艘小船上，四周一片水色，分不清方向。头顶上恰好是听
雨居。只可惜木板早已关上，要想上去简直是不可能的。看样子只好划出去碰碰运
气了。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","room1");
	setup();
}
void init()
{
	add_action("do_hua","hua");
}
int do_hua(string str)
{
	object me;
	me=this_player();
	if (!str)	{
		write("你要往哪儿划？\n");
		return 1;
			}
	if (str=="n"||str=="s"||str=="w"||str=="e"||
		str=="north"||str=="south"||str=="west"||str=="east")
						{
		me->move(__DIR__"shuilu2.c");
		return 1;
			}
	write("没有这个方向。\n");
	return 1;
}
