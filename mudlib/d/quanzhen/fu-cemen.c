// Room: /d/quanzhen/fu-cemen.c

inherit ROOM;

void create()
{
	set("short", "侧门");
	set("long", @LONG
	这里是一道小门，可能是由于怕进出不方便而修建的。门虽然
小，但还修饰得人模人样，门上嵌着两个大铜环。几条大狼狗懒洋洋躺
在门边，一看见有人进来就‘汪汪’地乱吠。出了门就是长安镇的南街
了，进门后是富家的小院。
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/wolfdog" : 2,
]));
	set("outdoors", "/d/quanzhen");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"fu-xiaoyuan",
  "northwest" : __DIR__"nanjie",
]));

	setup();
	replace_program(ROOM);
}
