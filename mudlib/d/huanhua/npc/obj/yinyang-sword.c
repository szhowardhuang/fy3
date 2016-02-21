#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("阴阳剑", ({"yinyang-sword","sword"}));
   set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一把剑身漆黑,剑轻如鸿毛的铁剑。\n");
                set("unit", "把");
                set("value", 10000);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
        }
        init_sword(40);
        setup();
}

