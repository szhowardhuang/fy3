// Room: /u/swordman/yangzhou/ddajie1.c

inherit ROOM;

void create ()
{
  set ("short", "东大街");
  set ("long", @LONG
你走在东大街上，踩着坚实的青石板地面。东边是东城门，可以听到守 
城官兵的吆喝声，与西边朗朗的读书声混杂在一起。北边是一家老字号的药
铺， 南边是打铁铺，叮叮当当的声音老远就能听到。 
LONG);

  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/wulai" : 2,
]));
  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"dongmen",
  "west" : __DIR__"ddajie",
  "north" : __DIR__"yaopu",
  "south" : __DIR__"tiepu",
]));
  set("outdoors", "/u/swordman");

  setup();
}
