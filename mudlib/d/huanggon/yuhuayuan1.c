// Room: /d/huanggon/yuhuayuan1.c

inherit ROOM;

void create()
{
	set("short", "御花园");
	set("long", @LONG
小桥流水,回廊画栋,假山形微而逼真,一些牵藤勾莶带着深绿的叶子
从假山上垂下来,几个深隧的洞窟在假山中穿过.山边缘临水,乃是从山顶
泄流而下的瀑布汇聚而成.
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"bukufang",
  "east" : __DIR__"lianxishi",
  "west" : __DIR__"qianqinmen",
]));
	set("outdoors", "/d/huanggon");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
