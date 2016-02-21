// Room: /d/suzhou/kufang.c

inherit ROOM;

void create()
{
	set("short", "库房");
	set("long", @LONG
金风庄的库房内摆设着各式各样的武器及护具。由于慕容氏志向远大，有兴
复大燕之志，顾而其家臣收罗了不少金戈器械诺大的库房内早已堆的满满的。房
内灯火通明，一身着青衣的管家正忙着整理。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"west" :__DIR__"lianwuchang",
]));
	set("objects",([
		__DIR__"npc/guanjia" :1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
