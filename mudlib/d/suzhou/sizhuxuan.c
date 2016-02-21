// Room: /d/suzhou/sizhuan.c

inherit ROOM;

void create()
{
	set("short", "丝竹轩");
	set("long", @LONG
迎头是面缎黄色的门帘，你掀开门帘进得屋内。南面是用青竹搭成的一座小
台楼，台楼上端坐着位妙龄少女。台楼下两排桌椅早已坐得满满的。但见那少女
怀抱琵琶，信手弹唱，声音如珠落玉盘，甚是悦耳动听。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"chengbeijie1",
]));
	set("objects",([
		__DIR__"npc/miaolingnu":1,
]));
	set("no_clean_up", 0);
	set("no_fight",1);
	setup();
	replace_program(ROOM);
}
