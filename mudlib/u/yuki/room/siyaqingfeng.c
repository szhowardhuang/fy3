// Room: /u/yuki/room/siyaqingfeng.c

inherit ROOM;

void create()
{
	set("short", "四雅清风");
	set("long", @LONG
你已经到了梅庄的大厅门口，门内的匾额龙飞凤舞的写着“四雅清风”
四个大字，笔法娟秀中透着挺拔，不失为一笔好字。透过后门你看到里面一
尘不染，一张石桌和几个石凳都安放得整整齐齐。
LONG
	);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
