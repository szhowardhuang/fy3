// abandon.c
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob,env;
	string file;

	if(me->is_fighting() || me->is_busy())
		return notify_fail("你正忙着呢，没法使用奇门遁甲术。\n");
	if( me->is_ghost())
		return notify_fail("死人用不了道法！\n");
	if( environment(me)->query("no_fight"))
		return notify_fail("这儿风水不好，无法施展奇门遁甲术。\n");
	if((int)me->query_skill("daoxuexinde",1)<40)
		return notify_fail("你的道学心德不够，不会使用奇门遁甲术。\n");
	if((int)me->query("atman")<50)
		return notify_fail("你的道行不够，无法施展奇门遁甲术。\n");
	if(! arg)
		return notify_fail("你准备施展奇门遁甲术遁形到谁身边？\n");
	ob=find_living(arg);
	if(! ob || !me->visible(ob))
		return notify_fail("没有这么个人。\n");
	if(! env=environment(ob))
		return notify_fail("你无法遁形到"+ob->query("name")+"的身边！\n");
//	if( userp(ob))
//		return notify_fail("你感觉不到对方的存在。\n");

	if( base_name(env)[0..8]=="/d/death/")
		return notify_fail("死了去的更快。:)\n");
	
if (ob->query("combat_exp")>1500000)
return notify_fail("你感觉到一股强大的煞气把你挡了回来！\n");
	message_vision(HIY"$N右手捏个剑决口中念念有词，施展出「奇门遁甲」术！\n"NOR,me);
	me->add("atman",-50);
	if(random((int)me->query_spi())>random((int)ob->query_spi()))	{
		message_vision(HIY"$N身影突然不见！\n"NOR,me);
		me->move(env);
		message_vision(HIY"$N突然出现在烟雾中！\n"NOR,me);
		return 1;
	}
	else	return notify_fail(HIY"你似乎感觉到了"+ob->query("name")+"的存在，但却感到脑中一片空白！\n"NOR);
}

int help()
{
	write(@TEXT

指令格式：qmdj <某人>
道学心德学习到四十级，你便可以学得此项道法。
但并不是每次都能成功遁形到目标身边，这还与
你的灵性有一定的关系。

TEXT
	);
	return 1;
}
