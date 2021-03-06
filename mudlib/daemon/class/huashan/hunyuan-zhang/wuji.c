// wuji.c 混元无极
 
#include <ansi.h>
 
inherit SSERVER;
 
int perform(object me, object target)
{
	string msg;
	object weapon;
	int skill, ap, dp, neili_wound, qi_wound;

	if( !target ) target = offensive_target(me);

	skill = me->query_skill("hunyuan-zhang",1);

	if( !(me->is_fighting() ))
		return notify_fail("「混元无极」只能对战斗中的对手使用。\n");
 
	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("你使用了武器。\n");

	if( skill < 60)
		return notify_fail("你的「混元掌」等级不够, 不能使用「混元无极」！\n");

	if( me->query("force") < 150 )
		return notify_fail("你的内力不够，无法运用「混元无极」！\n");
        if(me->query_temp("have_pfm"))
        return notify_fail("你刚展施完特殊招式，内息还没调整过来。\n");
        me->set_temp("have_pfm",1);

 
	msg = HIC "$N潜运「混元无极」，双拳挟着隐隐的风雷之声向$n击去。\n"NOR;
	message_vision(msg,me,target);
 
	ap = me->query("combat_exp") + skill * 400;
	dp = target->query("combat_exp") / 2;
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me))
			me->add("force",-100);

		msg = HIG "$n只觉得胸前一阵剧痛，“哇”的一声喷出一口鲜血！\n"NOR;
		neili_wound = 100 + random(skill);
		if(neili_wound > target->query("force"))
			neili_wound = target->query("force");

		qi_wound = neili_wound / 5;
		if(qi_wound > target->query("kee"))
			qi_wound = target->query("kee");

		target->add("force", -neili_wound);
		target->receive_wound("kee", qi_wound,me);
		target->start_busy(2);
	}
	else
	{
		msg = HIG "只见$n不慌不忙，轻轻一闪，躲过了$N的必杀一击！\n"NOR;
		if(userp(me))
			me->add("force",-100);
		me->start_busy(2);
	}
	message_vision(msg,me,target);

	if(!target->is_fighting(me)) target->fight_ob(me);
        call_out("do_reset",5,me);
	return 1;
}

void do_reset(object me)
{
        if( !objectp(me))       return;
        if( (int)me->query_temp("have_pfm"))
                me->delete_temp("have_pfm");
}
