// Room: /d/xxy/mishi 
inherit ROOM; 
 
void create ()
{
  set ("short", "秘室");
  set ("long", @LONG
四面靠墙的地方都是高大的檀木柜子,一直伸到屋顶.上面都上着锁,不知
里面是些什么东西.屋子中除了柜子只有一张挺大的躺椅,此外一无所有.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhuge.c" : 1,
]));

  setup();
}
