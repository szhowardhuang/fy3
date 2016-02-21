// Room: /u/swordman/yangzhou/ycsz1
inherit ROOM;

void create ()
{
  set ("short", "青竹林");
  set ("long", @LONG
你走进了一片青竹林，青竹茂密修长，参差掩映，别是一番情趣，
竹径弯弯向南通向一座小楼，那就是板桥先生的书房--竹叶香斋，板桥
先生平日多在此会会文朋墨友，偶然也在此挥毫泼墨。向北是山庄大门。
LONG);

  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/obj/zhuye" : 2,
]));
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"ycsz",
  "south" : __DIR__"ycsz2",
]));
  set("outdoors", "/u/swordman");

  setup();
}
