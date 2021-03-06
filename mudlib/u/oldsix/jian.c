// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name("长剑", ({ "sword" , "chang jian" , "jian" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把看起相当普通的长剑，份量大约有十来斤左右。\n");
		set("value", 400);
		set("material", "steel");
	}
	init_sword(25);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");

// The setup() is required.

	setup();
}

void hit_ob(object me,object victim,int damage)
{
	object ob;
	if(damage==-1)	return;
	if(! ob=victim->query_temp("weapon")) return;
                        message_vision(HIW "只听见「啪」地一声，$N手中的" +
ob->name()
                                + "已经断为两截！\n" NOR, victim );
                        ob->unequip();
                        ob->move(environment(victim));
                        ob->set("name", "断掉的" + ob->query("name"));
                        ob->set("value", (int)ob->query("value") / 10);
                        ob->set("weapon_prop", 0);
                        victim->reset_action();

}
	
