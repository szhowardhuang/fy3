//This xuedao116 room file by mapmaker

inherit ROOM;

void create()
{
  set("short", "东挎院");
  set("long",@LONG
这是一间空空荡荡的房间。
LONG
  );
  set("exits", ([ /* sizeof() == 2 */ 
      "west" : __DIR__"xuedao115",
      "east" : __DIR__"xuedao120",
      ]));
  set("no_clean_up", 0);
  set("outdoors","xuedaomen/1");
  setup();
  replace_program(ROOM);//如果没有init函数请不要删除这句话

}
