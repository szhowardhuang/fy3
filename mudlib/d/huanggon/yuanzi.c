// Room: /d/huanggon/yuanzi.c

inherit ROOM;

void create()
{
	set("short", "后院");
	set("long", @LONG
院子极大,地上青砖好多已经破损,沿着墙脚一带,是一层暗绿色的
苔藓,几株小草从墙壁的缝隙中探起身子,墙头上的覆瓦有几块掉了下来.
北边一排长窗,那是后堂.
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"qingmutang",
  "north" : __DIR__"houtang",
  "west" : __DIR__"xiangfang",
]));
	set("outdoors", "/d/huanggon");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
