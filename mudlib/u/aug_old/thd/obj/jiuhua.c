// jiuhua.c
// 97.7.14 by Aug

inherit COMBINED_ITEM;

void create()
{
	set_name("九花玉露丸", ({"jiuhua" }));
	if( !clonep() ) {
		set("unit", "些");
		set("long",
"九花玉露丸是以「东邪」黄药师的秘方，采集九种珍贵药材，费时三年
由桃花弟子炼制而成的灵药。能大量的恢复精、气、神。\n");
		set("base_unit", "粒");
		set("base_value", 10000);
		set("base_weight", 50);
	}
	set_amount(1);
	setup();
}

int stuff_ob(object me)
{
	if( me->query_stat_maximum("food") - me->query_stat("food") < 5 )
		return notify_fail("你的肚子已经撑得什麽东西也吞不下去了。\n");
	message_vision(
"$N拿出一粒九花玉露丸，放入口中，吞了下去，顿时有一种飘飘欲仙
的感觉，身上病痛、疲劳似乎一下子都消失了。\n", me);
	me->supplement_stat("food", 5);
	me->heal_stat("gin", 3000);
	me->heal_stat("kee", 3000);
	me->heal_stat("sen", 3000);
	me->supplement_stat("gin", 3000);
	me->supplement_stat("kee", 3000);
	me->supplement_stat("sen", 3000);
	add_amount(-1);

	return 1;
}

