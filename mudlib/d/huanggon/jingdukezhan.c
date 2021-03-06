// Room: /d/huanggon/jingdukezhan.c

inherit ROOM;

void create()
{
	set("short", "京都客栈");
	set("long", @LONG
门口的旗杆上高挂一串大红灯笼,宽阔的门楣上是黑底泥金的招牌.
客栈里面打扫得十分干净,给人宾至如归的感觉.北边是西长安街,南边再
向里面去,就是卧室.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/sufoer.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"wchangan1",
  "south" : __DIR__"kezhanwoshi",
]));

	setup();
}
int valid_leave(object ob,string dir)
{
   if (dir=="south"&&!ob->query_temp("rent_paid"))  {
    if (present("su foer",this_object())) {
  message_vision("苏佛儿一把拉住$N:付钱,二两银子.\n",ob);
  return notify_fail("");
}
}
return ::valid_leave(ob,dir);
}