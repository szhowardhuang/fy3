// dodge_book.c

inherit ITEM;

void create()
{
        set_name("��������", ({ "shenfa rumen", "shu", "book", "rumen" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
            set("long", "����һ�����������ŵ��顣\n");
                 set("value",2000);
                set("material", "paper");
                set("skill", ([
                  "name": "zixia-shengong",
                  "exp_required": 3000,
                    "sen_cost":1,
                  "max_skill": 150,
                ]) );
        }
}