//Mr.music yangzhou 匕首

#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()

{
set_name(HIC"屠龙刀"NOR,({"tulong","blade","dao"}));
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
set("long",HIM"无声无色,神物自晦,据说刀中藏有一个秘密\n"NOR);
set("value",100000);
set("unit","把");
		set("material", "steel");
	}
init_blade(150);

// These properties are optional, if you don't set them, it will use the
// default values.

set("wield_msg",HIC"$N从背后的鲨鱼皮套中掏出一把乌沉沉的大刀\n"NOR);
set("unwield_msg",HIC"$N潇洒地收回屠龙刀\n"NOR);

	setup();
}
