#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("�ذ׳�ȹ", ({"skirt","cloth","changqun"}));
	set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "��");
		set("armor_prop/armor", 16);
        }
        setup();
}
