// chan 泰山缠剑式 

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
	string msg;
      object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("缠剑式只能对战斗中的对手使用。\n");

      if(!objectp(weapon=me->query_temp("weapon"))||
      (string)weapon->query("skill_type")!="blade")
            return notify_fail("缠剑式只有用剑才能发挥威力。\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "已经自顾不暇了，放胆攻击吧！\n");

	msg = CYN "$N使出泰山十八盘剑法之缠剑式，一把剑闪出十八道剑影，将$n缠个动弹不得，";

	me->start_busy(1);
	if( random(me->query("combat_exp")+me->query_skill("shibapan-jianfa",1)*1000) 
       > (int)target->query("combat_exp")/3*2 ) {
		msg += "结果$p被缠住了！\n" NOR;
		target->start_busy( (int)me->query_skill("shibapan-jianfa") / 30 + 2);
	} else {
		msg += "可是$p看破了$P的剑招，一拧身跃出了剑影。\n" NOR;
            msg += "$P却一下失去平衡，反陷入了被动。\n" NOR;
	      me->start_busy(2);
      }
	message_vision(msg, me, target);

	return 1;
}
