// music yangzhou' 花生米

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("花生米", ({"huashengmi", "huasheng","mi"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一袋花生。\n");
		set("unit", "粒");
		set("value", 30);
		set("food_remaining", 2);
		set("food_supply", 20);
	}
}
