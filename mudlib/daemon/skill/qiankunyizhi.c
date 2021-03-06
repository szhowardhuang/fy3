// musix ' skill 乾坤一掷

#include <ansi.h>

inherit SKILL;
mapping *action = ({
	([	"name":			"心言手语",
		"action":		"$N使一招「心言手语」，手中$w笔直向$n的$l飞去",
		"dodge":		-10,
		"damage":		50,
		"damage_type":	"刺伤"
	]),
	([	"name":			"星星点灯",
		"action":		"$N身形一转，一招「星星点灯」$w幻出满天灯影，虚虚实实地袭向$n的$l",
		"dodge":		-50,
		"damage":		40,
		"damage_type":	"戳伤"
	]),
        ([      "name":                 "风雨无阻",
                "action":               "$N向前一跃，一招「风雨无阻」$w象离弦之箭飞向$n的$l",
                "dodge":                -50,
                "damage":               40,
                "damage_type":  "戳伤"
        ]),
	([	"name":			"爱如潮水",
		"action":		"$N力贯$w，一招「爱如潮水」点点幻影飘浮不定地点向$n的$l",
		"dodge":		-30,
		"damage":		80,
		"damage_type":	"戳伤"
	]),
});

int valid_learn(object me)
{
	object ob;

//	if( (int)me->query("max_force") < 100 )
//		return notify_fail("你的内力不够，没有办法练乾坤一掷, 多练些内力再来吧。\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "throwing" )
		return notify_fail("你必须先找一支镖才能练。\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="throwing";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 50
	||	(int)me->query("force") < 10 )
		return notify_fail("你的内力或气不够，没有办法练习。\n");
	me->receive_damage("kee", 40);
	me->add("force", -10);
	write("你练了下乾坤一掷。\n");
	return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

