// Room: /d/quanzhen/shijie7.c

inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
	这是一条整齐的石板路，依山而建，随着山势的曲折蜿蜒曲折。由
于山势陡了，当初修建这条石阶时肯定费了不小的功夫。走到这里，已经可
以看见全真教重阳观的檐角了。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  "/d/hangzhou/npc/man.c" : 2,
]));
	set("no_clean_up", 0);
	set("outdoors", "/d/quanzhen");
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"shijie6",
  "northup" : __DIR__"fangzhenqiao",
]));

	setup();
	replace_program(ROOM);
}
