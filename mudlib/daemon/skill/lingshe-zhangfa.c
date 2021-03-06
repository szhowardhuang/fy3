//lingshe_zhangfa.c 灵蛇杖法

#include "ansi.h"

inherit SKILL;

mapping *action = ({
([	"action": "$N使出一招「灵蛇出洞」，手中$w大开大阖扫向$n的$l",
	"damage":60,
	"damage_type": "挫伤"
]),
([	"action": "$N手中$w阵阵风响，一招「摇头摆尾」向$n的$l攻去",
	"damage":80,
	"damage_type": "挫伤"
]),
([	"action": "$N举起$w，居高临下使一招「灵蛇下涧」砸向$n的$l",
	"damage":100,
	"damage_type": "挫伤"
]),
([	"action": "$N一招「灵蛇挺身」，手中$w猛烈扫向$n的$l",
	"damage":120,
	"damage_type": "挫伤"
]),
([	"action": "$N使出一招「蛇游蟒走」，$w左右迂回向$n的$l扫去",
	"damage":140,
	"damage_type": "挫伤"
]),
([	"action": "$N手中$w一挥，使出一招「蛇缠左右」，忽左忽右扫向$n的$l",
	"damage":160,
	"damage_type": "挫伤"
]),
([	"action": "$N使出一招「巨蟒下山」，高举手中$w，劈头砸向$n的$l",
	"damage":180,
	"damage_type": "挫伤"
]),
([	"action": "$N使出一招「灵蛇出洞」，手中$w猛一探，直扫$n的$l",
	"damage":200,
	"damage_type": "挫伤"
]),

});


mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_force") < 70)
		return notify_fail("你的内力不够。\n");
	return 1;
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("kee") < 50)
		return notify_fail("你的体力不够练灵蛇杖法。\n");
	me->receive_damage("kee", 20);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	string msg;
        if( random(me->query_skill("hamagong")) > 10 ) 
	{
	victim->apply_condition("snake_poison", random(me->query_skill("hamagong")/10) + 1 +
	victim->query_condition("snake_poison"));
	msg=HIG"突然，杖头的毒蛇窜出来，狠狠地咬了$n一口！\n"NOR;
	return msg;
	}
}

int power_point()	{	return 1.5;	}
int hard_point()	{	return 2;	}

string perform_action_file(string action)
{
return "/daemon/class/baituo/lingshe-zhangfa/" + action;
}

