// jingling ����

inherit ITEM;
inherit F_FOOD;
inherit F_LIQUID;

void create()
{
        set_name("��ˮ����", ({"baozi", "dumpling"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ���������������ӡ�\n");
                set("unit", "��");
                set("value", 100);
                set("food_remaining", 5);
                set("food_supply", 30);
                set("max_liquid", 60);


        }
}