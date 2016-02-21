// Room: /d/heimuya/dating3.c

inherit ROOM;

void create()
{
	set("short", "青龙堂");
	set("long", @LONG
这是『日月神教』下第三大堂：青龙堂的大厅，十分气派，
又或有一条青龙时隐时现。堂梁上有一块匾(bian)。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/qinglongdizi.c" : 2,
]));
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 1 */
  "bian" : "上面写到：长虹贯日，青龙飞天。千秋万载，一统江湖 。
",
]));
	set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"guang",
  "south" : __DIR__"chlang1",
]));

	setup();
	replace_program(ROOM);
}
