// Room: /u/swordman/yangzhou/qiao
inherit ROOM;

void create ()
{
  set ("short", "小东门桥");
  set ("long", @LONG
这里是扬州城东的一座小桥，桥下就是举世闻名的“大运河”，
是扬州城历代繁华的命脉。桥下流水清清，两岸傍水建了不少房屋
和船码头，河里来往大小船只连绵不断，一片繁容景象。
LONG);

  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shangren" : 1,
]));
  set("outdoors", "/u/swordman");
  set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"qiaoxia",
  "north" : __DIR__"ddajie",
]));

  setup();
}
