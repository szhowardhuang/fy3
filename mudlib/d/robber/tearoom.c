// Room: /d/robber/tearoom.c

inherit ROOM;

void create()
{
	set("short", "茶寮");
	set("long", @LONG
几根毛竹，一块油布，挑起一个小茶蓬。门口的白底布招上老大的一
个茶字，老远就能看到。几张粗木板凳，两张桌子，朴实中露出天然。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"road5",
]));
set("outdoors","/d/jiangnan");
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/laohan.c" : 1,
  __DIR__"npc/obj/pot.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
