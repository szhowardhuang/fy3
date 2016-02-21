//wendingnan1
  

inherit ROOM;

void create()
{
	set("short", "文定南街");
	set("long", @LONG
这是中州城文定南街，宽敞的街道看的人不竟心情一畅。街道的东面
熙熙攘攘的是一个菜场。西面的一家店面，一听里面的算盘声就知道是一
家不小的钱庄。
LONG
	);
set("outdoors","/d/zhongzhou");

	set("exits", ([
		"east" : __DIR__"canchang",
		"south" : __DIR__"wendingnan2",
		"west" : __DIR__"bank",
		"north" : __DIR__"shizhongxin",
	]));
	set("objects", ([
		__DIR__"npc/liumang" : 1,
		__DIR__"npc/xiaohai" : 1,
	]));

	setup();
	replace_program(ROOM);
}

