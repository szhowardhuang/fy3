// Room: /d/jinling/xiaolu-w.c

inherit ROOM;

void create()
{
	set("short", "�ּ�С·");
	set("long", @LONG
����һ���������ּ��С·��ֻ�������˲��������Ӧ�˲���˭���������
��Ҫ���ж��롣��������羰�ܺã��ľ��ǳ�����������Ҳ��һ�����ܡ�
������ǰ���ּ�С·�������㷼���������¥�ˡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"xiaolu-n.c",
  "east" : __DIR__"xiaolu-e.c",
  "north" : __DIR__"xiaolu.c",
  "south" : __DIR__"xiaolu-w.c",
]));
	set("outdoors", "/d/jingling");

	setup();
	replace_program(ROOM);
}