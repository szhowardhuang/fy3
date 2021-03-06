// taixuan 太玄掌
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit SSERVER;
 
int perform(object me, object target)
{
	object weapon, ob;
    string msg, string1;
    int count;
 
    if( !me->is_fighting() )
	    return notify_fail("「太玄掌」只能在战斗中使用。\n");


        if((int)me->query("kar") < 25)
		return notify_fail("你的臂力不够, 目前还不能使用这项绝技! \n");

	if((int)me->query_skill("xiake-shengong",1) < 150)
		return notify_fail("你的侠客神功修为不够, 不能使用这一绝技 !\n");

	if((int)me->query_skill("dodge") < 150)
		return notify_fail("你的轻功修为不够, 不能使用太玄掌！\n");
 
	if((int)me->query_skill("unarmed") < 150)
                return notify_fail("你的徒手搏击修为不够， 目前不能使用太玄掌! \n");

    if( (int)me->query("force") < 1000 )
		return notify_fail("你的内力不够！\n");


    msg = HIG "$N使出侠客神功的绝技「太玄掌」，身法陡然加快！\n" NOR;
    message_vision(msg, me);

	me->clean_up_enemy();
	ob = me->select_opponent();

	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

	me->add("force", -150);
	me->start_busy(random(2));

    return 1;
}
