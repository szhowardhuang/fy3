// wuhu-duanmendao.c 五虎断门刀

inherit SKILL;

mapping *action = ({
([	"action" : "$N手中$w斜指，一招「直来直去」，反身一顿，一刀向$n的$l撩去",
	"damage":50,
	"damage_type" : "割伤"
]),
([	"action" : "$N一招「童子挂画」，左右腿虚点，$w一提一收，平刃挥向$n的颈部",
	"damage":70,
	"damage_type" : "割伤"
]),
([	"action" : "$N展身虚步，提腰跃落，一招「推窗望月」，刀锋一卷，拦腰斩向$n",
	"damage":90,
	"damage_type" : "割伤"
]),
([	"action" : "$N一招「力劈华山」，$w大开大阖，自上而下划出一个闪电，直劈向$n",
	"damage":110,
	"damage_type" : "割伤"
]),
([	"action" : "$N手中$w一沉，一招「临溪观鱼」，双手持刃拦腰反切，砍向$n的胸口",
	"damage":130,
	"damage_type" : "割伤"
]),
([	"action" : "$N挥舞$w，使出一招「张弓望的」，上劈下撩，左挡右开，齐齐罩向$n",
	"damage":150,
	"damage_type" : "割伤"
]),
([	"action" : "$N一招「风送轻舟」，左脚跃步落地，$w顺势往前，挟风声劈向$n的$l",
	"damage":170,
	"damage_type" : "劈伤"
]),
([	"action" : "$N盘身驻地，一招「川流不息」，挥出一片流光般的刀影，向$n的全身涌去",
	"damage":190,
	"damage_type" : "刺伤"
]),
([	"action" : "$N右手后撤，手腕一翻，一招「壮士断腕」，顿时一道白光直斩向$n的手臂",
	"damage":190,
	"damage_type" : "砍伤"
]),
([	"action" : "$N高高跃起，一招「人头落地」，手中$w直劈向$n的颈部",
	"damage":210,
	"damage_type" : "劈伤"
]),
([	"action" : "$N贴地滑行，一招「断子绝孙」，手中$w直撩去$n的裆部",
	"damage":250,
	"damage_type" : "割伤"
]),
});


int valid_enable(string usage) { return (usage == "blade") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_force") <80)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("blade", 1) < 20)
		return notify_fail("你的基本刀法火候太浅。\n");
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
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("kee") < 50)
		return notify_fail("你的体力不够练五虎断门刀法。\n");
	me->receive_damage("kee", 30);
	return 1;
}
int power_point()	{	return 1.25;	}

