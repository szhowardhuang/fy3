// xiaolu2.c 林间小径
// by Xiang

#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "林间小径");
  set ("long", @LONG
	你走在一条小径上，两旁种满了竹子，修篁森森，绿荫满地，除了竹叶
声和鸟鸣声，听不到别的动静。北面似乎有一座简陋的小院。
LONG);

  set("outdoors", "wudang");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"xiaoyuan.c",
  "south" : __DIR__"xiaolu1",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/qingfeng.c" : 1,
]));

  setup();
}
