// lu:pharmacy.c
// 97.9.16

inherit ROOM;

#include <ansi.h>

int last_time=-10000;

void create()
{
	set("short", "炼丹房");
	set("long", @LONG
这里是陆庄主的炼丹房。房间的中央是座古色古香的炼丹炉，四周堆
放着各种各样的珍贵药材。因为炉火整日不熄，炼丹房里总是烟雾缭绕，
平添一种神秘气氛。黄药师的九香玉露丸天下闻名，听说陆庄主也会炼，
只是原料珍贵，炼制费力，庄主不会随便给人。
LONG
	);

//	set("objects", ([ /* sizeof() == 2 */
//		"/obj/npc/di_pi" :  1,
//		"/obj/npc/punk": 1,
//	]));

	set("detail", ([ /* sizeof() == 1 */
		"炼丹炉" : 
"这是个青铜炼丹炉，看来有点年头了。炉中正炼着丹药。
炉壁上有个脚印，也不知是谁踢的。\n",
]));

	set("exits", ([ /* sizeof() == 1 */
		"southwest" : __DIR__"hall",
	]));

	set("outdoors", "lu_town");

	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_kick", "kick");
}

int do_kick(string arg)
{
    object me,ob;
    int i;

    if(arg!="炼丹炉") return 0;
    
    me=this_player(); 
    me->set_temp("kick",me->query_temp("kick")+1);

    if(me->query_temp("kick")==9)
    {
      me->set_temp("kick",0);

      i=time();
      if((i-last_time)>900)
      {
        ob=new(__DIR__"obj/jiuhua");
        ob->move(me);
         
        message_vision(
"炉子被$N踢开了，$N看到炼丹炉里有一颗芳香扑鼻的"+HIM+"九香玉露丸"+NOR+"。
$N捡起了这粒丹药，再把炉子扶正。\n", me);
        last_time=i;
      }
      else          
        message_vision("炉子被$N踢开了，但$N没有发现什么。$N又把炉子扶正了。\n", me); 
           
    }
    else
      message_vision("$N踢了一下炼丹炉，炉子晃了晃。\n", me);
   
    return 1; 
}

int valid_leave(object me, string dir)
{
  if(dir=="southwest") me->delete_temp("kick");

  return ::valid_leave(me, dir);  
}
