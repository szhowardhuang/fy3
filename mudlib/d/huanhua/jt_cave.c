// Room: /d/new/huanhua/jt_cave.c

inherit ROOM;

void create()
{
	set("short", "见天洞前");
	set("long", @LONG
见天洞是浣花萧家宗祠拜祭之所.里面供奉的是萧家历代祖先灵位.
另外,据说浣花萧家的镇山之剑---[长歌剑],就藏于此洞中.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guanbo.c" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"changlang3",
  "enter" : __DIR__"injt_cave",
]));
	set("no_clean_up", 1);

	setup();
}
int valid_leave(object me,string dir)
{
   if (objectp(present("guang bo",this_object()))&&dir=="enter")
      {
         if (me->query("family/family_name")!="浣花剑派")
              return notify_fail("广伯呀呀叫着对你摇了摇手,看来是不让你进去!\n");
       }
return ::valid_leave(me,dir);
}           
