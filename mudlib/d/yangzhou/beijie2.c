// Room: /u/swordman/yangzhou/beijie2
inherit ROOM;

void create ()
{
  set ("short", "北大街");
  set ("long", @LONG
这里的路相当的宽，能容好几匹马车并行，长长的道路通向北方。远
远的能看到北面的北城门。向南是城中心。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"beimen",
  "south" : __DIR__"beijie1",
  "west" : __DIR__"liangdian",
]));
  set("outdoors", "/u/swordman");
  set("light_up", 1);

  setup();
}
