// wuchang2.c 武场


#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "武场");
	set("long", @LONG
	这里是全真教的演武场，地下的青砖本来铺的整整齐齐，却不
知道被谁踩出了几十个大大小小的凹坑。看的出来，这里成年累月的有
弟子修炼掌法步法，天长日久，地下就踩出了凹坑。武场中央立着几个
练功用的木人。
LONG
	);

	set("exits", ([
		"north" : __DIR__"wuchang1",
		"east" : __DIR__"xiuxishi",
		"southeast" : __DIR__"shantang",
	]));
set("outdoors","/d/quanzhen");

	set("objects", ([
		__DIR__"npc/mu-ren" : 2,
	]));

	setup();
	replace_program(ROOM);
}
