// 妙手回春

#include <ansi.h>

inherit SKILL;
mapping *action = ({
	([	"name":			"针锋相对",
		"action":		"$N使一招「针锋相对」，手指一弹，银针笔直向$n打去",
		"dodge":		-10,
		"damage":		30,
		"damage_type":	"刺伤"
	]),
	([	"name":			"针砭时弊",
		"action":		"$N身形一转，一招「针砭时弊」，银针从不可思议的角度打向$n的肋部。",
		"dodge":		-50,
		"damage":		40,
		"damage_type":	"刺伤"
	]),
        ([      "name":                 "如坐针毡",
                "action":               "$N身子一伏，银针自下向上直击$n，把$n吓得手忙脚乱。",
                "dodge":                -50,
                "damage":               60,
                "damage_type":  "刺伤"
        ]),
	([	"name":			"芒刺在背",
		"action":		"$N右手看似虚挥，一招「芒刺在背」，不知什么方法，竟然将银针从背后向$n打来！",
		"dodge":		-30,
		"damage":		80,
		"damage_type":	"刺伤"
	]),
});

int valid_learn(object me)
{
	
	if ( me->query_temp("weapon")!= "银针")
		return notify_fail("你没有装备适当的武器。\n");

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
	||	(int)me->query("force") < 20 )
		return notify_fail("你的内力或气不够，没有办法练习妙手回春。\n");
	me->receive_damage("kee", 40);
	me->add("force", -10);
	write("你拿着银针在自己的穴道周围比划了两下，似乎有点心得。\n");
	return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string action)
{
	return action;
}

void skill_improved(object me)
{
	if(me->query_skill("miaoshouhuichun",1)==20)	
	tell_object(me,HIC"你自己觉得已经对针灸技术有点了解了。\n"NOR);
	if(me->query_skill("miaoshouhuichun",1)==40)
	tell_object(me,HIC"你自己觉得对针灸技术有了不少心得体会，自信增强了不少。\n"NOR);
	if(me->query_skill("miaoshouhuichun",1)==80)
	tell_object(me,HIC"你对针灸技术已经充满自信了。\n"NOR);
}
