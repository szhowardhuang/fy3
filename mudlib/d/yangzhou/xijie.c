// Room: /u/swordman/yangzhou/xijie
inherit ROOM;

void create ()
{
  set ("short", "西大街");
  set ("long", @LONG
你走在扬州城最繁华的大街上，沿街店铺林立，商贾成群。白天
这里车马如龙，人声鼎沸，夜里是星光伴月，灯火通明。这里是城中
的主要的商业和文化娱乐街，素有“春风十里扬州路”的美称。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"zhubaodian",
  "east" : __DIR__"guangchang",
  "west" : __DIR__"xijie1",
  "south" :__DIR__"caifengdian",
]));
  set("outdoors", "/u/swordman");
  set("light_up", 1);

  setup();
}
