// Room: /u/xxy/room/shuitan
inherit ROOM;

void create ()
{
  set ("short", "玉液泉");
  set ("long", @LONG
泉从地底拥出,水清味甘,古名玉液.蓄水而成池,是为太极池,池
畔有大石横卧,山石上都是古来文人墨客的题刻.'大峨'二字据说还
是唐吕纯阳所书.另有一块石碑(bei),屹立池边.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/wenhui.c" : 1,
]));
  set("outdoors", "/d/emei");
  set("item_desc", ([ /* sizeof() == 1 */
  "bei" : "神水通楚碑,上刻明诗人扬升庵题诗.
山僧言此泉,下与江陵通.智者昔说法,龙女为飞空
夏冽冬复暖,凡水焉可闻.造物有至理,灵源谁能穷
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"wanhegu",
]));

  setup();
}
void init()
{
	add_action("do_jump", "jump");
}

int do_jump(string arg)
{
    if(arg!="down") return 0;
 
    message_vision("$N掂起脚,试了试水温,皱了下眉,捏着鼻子跳进池中。\n", this_player());
    this_player()->move(__DIR__"xixiang"); 

    return 1;
}
