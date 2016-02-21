//bye enter

#include <ansi.h>

inherit ROOM;

void create()
{
  set ("short", "车厢内");
  set ("long", @LONG
你正躺在马车车厢内，车厢里的陈设极为豪华，波斯地毯，
上好的座椅，最妙的是有瓶五粮液在那里放着，你忍不住想喝
他几口。
LONG
    );
  set("exits",([
          "out": __DIR__"houyuan",
      ]));
  set("objects",([
          __DIR__"obj/wuliangye" : 1,
     ]));

	set("no_fight",1);
  setup();
}

void init()
{
        object ob;
	ob=this_player();
	remove_call_out("greeting");
	call_out("greeting", 1, ob);
}

void greeting(object ob)
{
	object room;

        if( !ob || environment(ob) != this_object() ) return;
	write("车夫探头道："+RANK_D->query_respect(ob)+
	"咱们这就上路。说罢扬起马鞭吆喝了一声：架！\n");
	if(! (room=find_object(__DIR__"houyuan")))
		room=load_object(__DIR__"houyuan");
	room->delete("exits");
	delete("exits");
	call_out("reach",30,ob);
}

void reach(object ob)
{
	object room;
	if(! (room=find_object(__DIR__"houyuan")))
		room=load_object(__DIR__"houyuan");

	write("车夫回头对你道：扬州到了！说完把你扶出车厢。\n");
	ob->move("/d/yangzhou/shizhongxin");
	set("exits/out",__DIR__"houyuan");
	room->set("exits/enter",__DIR__"chexiang");
}

