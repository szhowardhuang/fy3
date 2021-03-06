// Room: /u/uuui/workroom.c
#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short", "凝王寝殿");
        set("long", @LONG
凝王寝殿是龙心和莞儿休息的地方，清新淡雅，绣帐低
垂的大床。旁有张梳妆台。铜镜胭脂水粉眉笔骨梳等如家装
扮之物式式具备临床处放了一组几椅，几上古琴旁还有一本
翻开了的词谱。细看下原来是唐代诗人白居易的“琵琶行”
配着墙上风格清婉，分绘上梅兰竹菊的卷轴。那充满阁楼内
清幽的茉莉花香气，既有书卷气息，又不失香艳的气氛。
LONG
        );
        set("exits", ([ /* sizeof() == 6 */
  "yuki" : "/u/yuki/workroom",
  "down" : "/d/zhongzhou/shizhongxin",
  "wangs" : "/u/wangs/workroom.c",
  "north" : __DIR__"guandao1",
  "south" : __DIR__"guandao2",
]));
        set("valid_startroom", 1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

