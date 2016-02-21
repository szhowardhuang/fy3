// music.   wiz's 巫师们的会客厅

#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "巫师们的会客厅");
  set ("long", @LONG
	这儿是巫师们的会客大厅，室内布置非常朴素却很得体。
迎面是一扇明亮的玻璃窗，透过这扇玻璃窗可以俯看扬州城的全貌。
客厅通向巫师们的工作室. 巫师们通常很忙，不易见到。如有问题，
可在此留言，但如果问题牵涉到解谜或者已经有帮助说明，巫师们就
可能就不作回答了。楼上是巫师会议室，烦请玩家们留步了。
	靠窗的沙发上坐着一位漂亮小姐，她就是闻名天下的绝代佳人
---- 崔莺莺. 你可以向她打听些巫师们的近况。

LONG
);

//  set("item_desc", ([ /* sizeof() == 2 */
//  "south" : (: look_door,     "south" :),
//  "door" : (: look_door,     "south" :),
//                   ]));
  set("exits", ([ 
  "up"    : "/d/wiz/meeting",
  "down"  : "/d/yangzhou/mingyue2",

]));
  set("no_fight", "1");

  set("objects", ([ 
                     __DIR__"npc/yingying" : 1,
                 ]));

  set("no_magic", 1);
  set("valid_startroom", 1);

  setup();
  call_other("/obj/board/guestboard","???");

}


int valid_leave(object me, string dir)
{
        if( dir=="up" && !wizardp(me) )
                return 
notify_fail("崔莺莺无奈的摇摇头: 真抱歉，只有巫师才能上去。\n");
        return ::valid_leave(me, dir);
}

