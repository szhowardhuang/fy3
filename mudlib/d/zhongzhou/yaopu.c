// Room: /d/zhongzhou/yaopu.c

inherit ROOM;

void create()
{
	set("short", "ҩ��");
	set("long", @LONG
�������ݳ�����ҩ�̡���һ���ҩ�ĵ�������в�ҩһӦ��ȫ��
ŨŨ��ҩζ�����е�͸�����������������������ģ����ĳ��˴�����
������������Ҫҩ�Ļ�������С����һ�㣬������ҩ����Ժ����������
�Լ���ҩ��
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xinyaonong.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"yaopuboss",
  "west" : __DIR__"wendingbei2",
  "enter" : __DIR__"yaopu1",
]));

	setup();
	replace_program(ROOM);
}