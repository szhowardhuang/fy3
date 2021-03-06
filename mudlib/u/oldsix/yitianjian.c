// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name("倚天剑",({ "yitian jian","jian"}));
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把看起相当普通的长剑，份量大约有十来斤左右。\n");
		set("value", 400);
		set("material", "steel");
		set("oldsix/qjdy",1);
	}
	init_sword(25);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");

// The setup() is required.

	setup();
}

mixed weapon_action(object me,object victim)
{
	object ob,target_weapon;
	string msg;
	target_weapon=victim->query_temp("weapon");
	if(! target_weapon)	return 0;
	if( target_weapon->query("oldsix/qjdy"))	{
		msg=HIW"“铛”的一声，"+this_object()->query("name")+"与"+
		target_weapon->query("name")+"相交，冒出点点火星！\n"NOR;
		return msg;
	}
	msg=HIW"只见白光一闪，"+victim->query("name")+"手中的"+target_weapon->query("name")+"被"+this_object()->query("name")+"削为两段！\n"NOR;
			ob=target_weapon;
			ob->unequip();
                        ob->move(environment(victim));
                        ob->set("name", "断掉的" + ob->query("name"));
                        ob->set("value", (int)ob->query("value") / 10);
                        ob->set("weapon_prop", 0);
                        victim->reset_action();
			return msg;

}
	
