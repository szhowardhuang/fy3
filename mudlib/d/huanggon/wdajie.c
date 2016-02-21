// Room: /d/huanggon/wdajie
inherit ROOM;

void create()
{
  set ("short", "西大街");
  set ("long", @LONG
这是条东西向的街道,向东穿过天安门广场.街道两边招牌林立,吆喝
声不断,因为是京城,治安很好,所以生意人挺多.南边一座兵营,门口的兵
士老拿斜眼看你.
LONG);

  set("outdoors", "/d/huanggon");
  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"qianfengyin",
  "west" : __DIR__"wdajie1",
  "east" : __DIR__"guangchang",
]));
  setup();
  replace_program(ROOM);
}
