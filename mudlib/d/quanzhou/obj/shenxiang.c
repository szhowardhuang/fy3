
inherit ITEM;
void create()
{
	set_name("妈祖神像", ({"shenxiang", "mazu"}));
	set_weight(50000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "慈祥安定的妈祖像,一羽一发莫不传神动人。\n");
		set("unit", "个");
             set("no_get",1);
	}
setup();
}
