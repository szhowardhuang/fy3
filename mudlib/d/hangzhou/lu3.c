// Room: /d/hangzhou/lu3.c

inherit ROOM;

void create()
{
	set("short", "叉路口");
	set("long", @LONG
这个三叉路口正当苏杭要道，路边池塘中两头水牛玩得正欢。放
牧的顽童正在池边嘻笑，路上不时有骏马奔驰而过，时而俊俏的小媳妇
骑着小毛驴悠悠的走过，东边隐隐山水清明，正是山明水秀的杭州，北
边的大道直通苏州，向南可到瓷都景德镇。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhiluren.c" : 1,
]));
	set("no_clean_up", 0);
	set("outdoors", "/d/hangzhou");
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"lu2",
  "southup" : __DIR__"lu4.c",
  "north" : "/d/suzhou/dadao3",
]));

	setup();
	replace_program(ROOM);
}
