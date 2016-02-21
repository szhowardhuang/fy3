// Room: /d/xxy/wuroom 
inherit ROOM; 
 
void create ()
{
  set ("short", "武字一号楼");
  set ("long", @LONG
登上几级楼梯,你走上二楼,这里的一切显得十分富丽堂皇,从红漆栏杆
向外眺望,满园春色入目,在北面是武士休息的地方.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/wushou.c" : 2,
]));
  set("outdoors", "/d/xxy");
  set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"zoulang5",
  "north" : __DIR__"wuroom2",
]));

  setup();
}
int valid_leave(object me,string dir)
{
    object ob;
    string str;
    ob=present("pai",me);
    if (dir=="north")           {
      if (!ob)
               return notify_fail("你混了进来还想到处走么!\n");
       str=ob->query("name");
          if (str=="铜牌"||str=="铁牌")
              return notify_fail("你的等级不够进入武字楼!\n");
                   }
       else return ::valid_leave(me,dir);
}
     