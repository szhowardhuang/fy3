//玄天内功
#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return 
notify_fail("玄天内功只能用学的，或是从运用(exert)中增加熟练度。\n");
}

string exert_function_file(string func)
{
return "/daemon/class/meizhuang/xuantian-neigong/"+func;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int ap,dp;
	if(victim->is_busy())	return;
	if(factor<5)	return;
	if(victim->query("force")>me->query("force"))	return;
	ap=me->query_skill("force")+me->query_skill("dodge");
	dp=victim->query_skill("parry")+me->query_skill("dodge");
	if(random(ap)<random(dp))	return;
	me->add("force",-factor);
	victim->start_busy(factor/10+3);
	return YEL"只见$N脸色铁青，右掌扬起，顿时$n被一股寒气笼罩！\n$n忙于御寒，无法反击！\n"NOR;
}

int power_point()	{	return 1.5;	}
