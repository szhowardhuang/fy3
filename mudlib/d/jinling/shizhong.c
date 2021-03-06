// Room: /d/jinling/shizhong.c

inherit ROOM;

void create()
{
	set("short", "市中心");
	set("long", @LONG
忽然你来到一个很大的广场，广场中心有一块告示牌(gaoshi),旁边有几
个卫兵守着．此外广场上几乎没人．东西两面合称上林道．东南面有一家
客栈，看上去挺豪华的！
LONG
	);
set("valid_startroom",1);
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 1 */
  "gaoshi" : "[1;33m由于帮派私斗，惊扰百姓。为了大家的安全，现实行宵禁。
望大家晚上不要出门，谢谢合作!! 
[2;37;0m",
]));
	set("outdoors", "/d/jingling");
	set("exits", ([ /* sizeof() == 5 */
  "north" : __DIR__"changjie3.c",
  "southeast" : __DIR__"ke.c",
  "south" : __DIR__"changjie2.c",
  "east" : __DIR__"shanglin7.c",
  "west" : __DIR__"shanglin1.c",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/chengwei.c" : 4,
  __DIR__"npc/yinjiaweishi.c" : 2,
]));

	setup();
	replace_program(ROOM);
}
