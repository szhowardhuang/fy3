// Room: /d/suzhou/meizhuang/midao1.c

inherit ROOM;

void create()
{
	set("short", "密道");
	set("long", @LONG
密道内阴暗异常，隔老远才有一盏油灯，有些地方油灯已熄，更是一
片漆黑，要摸索而行数丈，才又见灯光。你只觉呼吸不畅，壁上和足底潮
湿之极，只怕已深入西湖之底。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	"up":__DIR__"midao7",
	"west":__DIR__"midao9",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
