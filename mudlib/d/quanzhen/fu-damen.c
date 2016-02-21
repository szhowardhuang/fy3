// Room: /d/quanzhen/fu-damen.c

inherit ROOM;

void create()
{
	set("short", "候府");
	set("long", @LONG
	这里是长安镇上首富--侯员外家的大门，门上挂着一块大横匾，
上面写着‘侯府’两个大字。门内立着一面朱红的影壁，模模糊糊好象
题着一些诗句之类的东西。几个横眉立眼的家丁正挺胸凸肚地站在门口
耀武扬威，看来这是一家为富不仁的乡绅列霸。
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/jiading" : 3,
]));
	set("outdoors", "/d/quanzhen");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"fu-xiaoyuan",
  "north" : __DIR__"dongjie",
]));

	setup();
	replace_program(ROOM);
}
