// baishulin1.c 柏树林

inherit ROOM;

void create()
{
	set("short", "柏树林");
	set("long", @LONG
	绕过翠屏谷的山壁，眼前是一片大柏树林，想是由于山壁挡住了视
线，在山下的山路上根本想不到这里的柏树竟会有这么密这么高。你踏进柏
树林中，阳光全被头顶的树叶遮住了，越往树林深处，光线越是幽暗。
LONG
	);

	set("exits", ([
		"southdown" : __DIR__"cuipingu",
		"northup" : __DIR__"baishulin3",
		"east" : __DIR__"baishulin2",
	]));

set("outdoors","/d/quanzhen");
	setup();
	replace_program(ROOM);
}
