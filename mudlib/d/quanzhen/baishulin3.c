// baishulin3.c ������


inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
	���߽��˰����ֵ�������²��ź�����Ҷ�����������������
���߷ǳ��������㼸��ʲô���������ˡ�ͻȻһֻ���������ǰ����֦����
�����˹�ȥ��������һ����
LONG
	);

	set("exits", ([
		"northup" : __DIR__"cuipingfeng",
		"east" : __DIR__"baishulin4",
		"southdown" : __DIR__"baishulin1",
	]));

	setup();
set("outdoors","/d/quanzhen");
	replace_program(ROOM);
}