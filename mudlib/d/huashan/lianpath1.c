//Roon: lianpath1.c ������С·
//Date: Oct. 2 1997 by Venus
inherit ROOM;

void create()
{
      set("short","������С·");
      set("long",@LONG
С·ͨ�������壬��Χ�������ģ�΢�Ų��������������Ĺȣ�����
������
LONG);
      set("outdoors", "xx");
      set("no_clean_up", 0);
      set("exits",([ /* sizeof() == 1 */
          "westup"   : __DIR__"lianpath2",
          "northeast": __DIR__"zhenyue",
      ]));
      setup();
      replace_program(ROOM);
}
