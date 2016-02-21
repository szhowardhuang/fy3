// rope.c

#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
        set_name( "铁链", ({"tie lian"}) );
        set_weight(2800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
       set("long","一条粗大的铁链,上面沾着红色血丝.\n");
                set("unit", "条");
                set("value", 1500);
                set("material", "steel");
        }
        init_whip(20);

        set("wield_msg", "$N从腰间抽出一条$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n束在腰间。\n");

        setup();
}

