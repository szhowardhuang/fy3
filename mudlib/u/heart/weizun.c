// weizun.c  五岳为尊

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon, ob;
        string msg, string1;
        int count;
 
        if( !me->is_fighting() )
                return notify_fail("「五岳为尊」只能在战斗中使用。\n");
 
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("「五岳为尊」开始时必须拿着一把剑！\n");

        if( (int)me->query("neili") < 100 )
                return notify_fail("你的真气不够！\n");

        if( (int)me->query_skill("zixia-shengong",1) < 50 )
                return notify_fail("你的紫霞神功不够！\n");

        if( (int)me->query_skill("sword",1) < 50 ||
            me->query_skill_mapped("sword") != "huashan-sword")
                return notify_fail("你的嵩山剑法还不到家，无法使用五岳为尊！\n");

        msg = HIW "$N使出嵩山派绝技「五岳为尊」，身法陡然加快,剑锋一转,从五个方向连出数剑！\n" NOR;
        message_combatd(msg, me);

        me->clean_up_enemy();
        ob = me->select_opponent();

        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

        me->add("neili", -100);

        if(!ob->is_fighting(me)) ob->fight_ob(me);
        return 1;
}
