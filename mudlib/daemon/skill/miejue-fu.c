// miejue-fu.c 灵蝎灭绝斧 by ksusan 7/27/97 8:30

inherit SKILL;

mapping *action = ({
([	"action" : "$N藏斧内收，一招「割肉饲鹰」，斧锋自下而上划了个半弧，向$n的$l挥去",
	"damage":50,
	"damage_type" : "割伤"
]),
([	"action" : "$N左掌虚托右肘，一招「投身饿虎」，手中$w笔直划向$n的$l",
	"damage":100,
	"damage_type" : "割伤"
]),
([	"action" : "$N一招「斫头谢天」，$w绕颈而过，刷地一声自上而下向$n猛劈",
	"damage":150,
	"damage_type" : "劈伤"
]),
([	"action" : "$N右手反执斧柄，一招「折骨出髓」，猛一挫身，$w直向$n的颈中斩去",
	"damage":200,
	"damage_type" : "砍伤",
]),
([	"action" : "$N一招「挑身千灯」，无数斧尖化作点点繁星，向$n的$l挑去",
	"damage":250,
	"damage_type" : "挫伤"
]),
([	"action" : "$N双手合执$w，一招「挖眼布施」，拧身急转，斧尖直刺向$n的双眼",
	"damage":300,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「剥皮书经」，手中$w划出一个大平十字，向$n纵横劈去",
	"damage":350,
	"damage_type" : "劈伤"
]),
([	"action" : "$N反转斧尖对准自己，一招「剜心决志」，全身一个翻滚，$w向$n拦腰斩去",
	"damage":400,
	"damage_type" : "砍伤"
]),
([	"action" : "$N一招「烧身供佛」，$w的斧光仿佛化成一簇簇烈焰，将$n团团围绕",
	"damage":450,
	"damage_type" : "砍伤"
]),
([	"action" : "$N斧尖平指，一招「刺血满地」，一片片切骨斧气如飓风般裹向$n的全身",
	"damage":500,
	"damage_type" : "劈伤"
]),
});

int valid_enable(string usage) { return usage == "axe" || usage == "parry"; }


int valid_learn(object me)
{
	if ((int)me->query("max_force") < 50)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("xiuluo-force", 1) < 10)
		return notify_fail("你的修罗阴煞功火候太浅。\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "axe")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("kee") < 50)
		return notify_fail("你的体力不够练灵蝎灭绝斧。\n");
	me->receive_damage("kee", 35);
	return 1;
}

