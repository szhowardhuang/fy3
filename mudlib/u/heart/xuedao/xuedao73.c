//This xuedao73 room file by mapmaker

inherit ROOM;

void create()
{
  set("short", "牢房夹道");
  set("long",@LONG
这里连接秘道的出口以后是封闭的，用于迷题而设。
因此不要写出有这秘道
LONG
  );
  set("exits", ([ /* sizeof() == 2 */ 
      "east" : __DIR__"xuedao179",
      "west" : __DIR__"xuedao74",
      "north" : __DIR__"xuedao182",
      ]));
  set("no_clean_up", 0);
  set("outdoors","xuedaomen/2");
  setup();
  replace_program(ROOM);//如果没有init函数请不要删除这句话

}
