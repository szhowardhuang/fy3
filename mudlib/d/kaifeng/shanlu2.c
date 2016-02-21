// Room: /d/kaifeng/shanlu2
inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG
此条山路直通嵩山，由此前住嵩山进香、游玩的客人络绎不绝。北
边不远便是嵩山入口。
LONG);

  set("outdoors", "/d/kaifeng");
  set("exits", ([ /* sizeof() == 2 */
  "north":"/d/songshan/taishique",
  "eastup" : __DIR__"shanlu1",
]));

  setup();
}
