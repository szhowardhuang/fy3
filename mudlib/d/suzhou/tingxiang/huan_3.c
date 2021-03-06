// Room: /u/oldsix/room1/huan_2.c

inherit ROOM;

void create()
{
	set("short", "湖岸");
	set("long", @LONG
极目远眺，只见烟波浩渺，远水接天，望不到头。岸边不远处有一座松树
枝成的木梯，垂下来通向水面。一只[1;32m小船[2;37;0m系在树枝之上。忽听得柳枝上一只小
鸟“莎莎都莎”的叫了起来，声音清脆。
LONG
	);
	set("item_desc",([
		"小船" : "一条小船(xiaochuan)，船中放着对桨。看样子你正好坐得下。\n"
			+"你考虑了一下，倒底要不要上船(boat)。\n",
		"xiaochuan" :"一条小船，船中放着对桨。看样子你正好坐得下。\n"
			+"你考虑了一下，倒底要不要上船(boat)。\n",
		]));
	set("objects",([
		__DIR__"npc/chuanfu":1,
]));
	set("exits", ([ /* sizeof() == 1 */
		"up":__DIR__"txmen",
]));
	set("no_clean_up", 0);
	set("outdoors","room1");
	setup();
}
void init()
{
	object me;
	me=this_player();
	add_action("do_boat","boat");
}
int do_boat()
{
	object me;
	me=this_player();
	message_vision("$N小心翼翼的上了小船，这次没有发生意外。\n"
			+"$N拿起双桨，慢慢的把小船划(hua)到了湖中。\n"
			+"小船离岸越来越远。。。\n",me);
	me->move("/d/suzhou/taihu/w2");
	return 1;
}
