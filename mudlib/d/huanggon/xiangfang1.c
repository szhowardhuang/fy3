// Room: /d/huanggon/xiangfang1
inherit ROOM;

void create()
{
  set ("short", "厢房");
  set ("long", @LONG
厢房的门上挂着门帏,四边用木板贴封,那是防备有人偷听隔音的,房
中书桌上摆了些摊开的书籍,一盏油灯还点燃着,靠壁的两张太师椅间是张
小茶几,屋角落中还摆着盆花.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"dating",
]));
  setup();
  replace_program(ROOM);
}
