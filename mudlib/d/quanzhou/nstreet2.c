// Room: /d/quanzhou/nstreet2.c

inherit ROOM;

void create()
{
	set("short", "北街");
	set("long", @LONG
这里是泉州城的北街,因为泉州靠海,东门外的安海港是联系世界各
地的大海港,所以泉州城中的洋人俯拾皆是,向西就是专门接待洋人的市
舶司.进出的人还不少.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"nstreet1",
  "south" : __DIR__"nstreet3",
  "west" : __DIR__"sibosi",
]));
	set("outdoors", "/d/quanzhou");

	setup();
	replace_program(ROOM);
}
