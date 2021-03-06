// Room: /u/swordman/yangzhou/ycsz2
inherit ROOM;

void create ()
{
  set ("short", "竹叶香斋");
  set ("long", @LONG
这座小楼就是扬州八怪之首，当代书画名家板桥先生的书房--
竹叶香斋，小楼依竹傍水，池水潺潺，竹香阵阵，你只想在这多呆
上一会儿。向北是一条竹林蹊径，向西就是荷花池了。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"ycsz3",
  "north" : __DIR__"ycsz1",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhengbanqiao" : 1,
]));

  setup();
}
