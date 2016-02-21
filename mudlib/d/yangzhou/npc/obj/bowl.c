// bowl.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("大碗茶", ({ "cha wan", "bowl" }) );
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一个茶碗，里面有什么呢？当然是茶啦。还是上好的毛峰呢！\n");
                set("unit", "个");
                set("value", 100);
                set("max_liquid", 60);
        }

        set("liquid", ([
                "type": "water",
                "name": "毛峰",
                "remaining": 60,
                "drunk_apply": 2,
        ]) );
}