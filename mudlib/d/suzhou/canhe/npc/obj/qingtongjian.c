// sword.c : an example weapon

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("青铜剑",({"sword","qingtong jian","jian"}));
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
	set("long","这把剑看起来年代相当久远,份量大约有十来斤左右。\n");
	set("value",5000);
		set("material", "steel");
	}
	init_sword(40);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");

// The setup() is required.

	setup();
}
