// Room: /d/zhongzhou/wroad1.c

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
这是条连接开封府与中州府的官道，由于这条路治安较好，行人也
不少。西面通向开封，东面是中州府。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"wroad2",
  "east" : __DIR__"xijiao",
]));
	set("outdoors", "zhongzhou");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
