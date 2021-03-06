// piaohua-hand.c 飘花落叶手
// By temp,1999,12,14

inherit SKILL;

mapping *action = ({
([	"action" : "$N缓缓的举起双手，平平的向$n推去",
	"force" : 180,
	"dodge" : 5,
	"damage":15,
	"lvl" : 0,
	"skill_name" : "平推手",
	"damage_type" : "内伤"
]),
([	"action" : "$N突然后退一步，反手直袭$n的面门",
	"force" : 200,
	"dodge" : 5,
	"damage": 20,
	"lvl" : 10,
	"skill_name" : "反身追月",
        "damage_type" : "内伤"
]),
([	"action" : "$N突然使出一招「湖光跃影」，从侧面撞向$n",
	"force" : 230,
	"dodge" : 15,
	"damage": 35,
	"lvl" : 22,
	"skill_name" : "湖光跃影",
        "damage_type" : "内伤"
]),
([	"action" : "$N纵身一跃，竟然从空中向下攻击$n，好一招 「莲花飘落」 ",
	"force" : 270,
	"dodge" : 5,
	"damage": 40,
	"lvl" : 34,
	"skill_name" : "莲花飘落",
        "damage_type" : "内伤"
]),
([	"action" : "$N突然急身前冲，双手直袭$n的右手而去，原来「落叶分飞」竟是擒拿手法",
	"force" : 320,
	"dodge" : 10,
	"damage": 50,
	"lvl" : 48,
	"skill_name" : "落叶分飞",
        "damage_type" : "内伤"
]),
([	"action" : "$N左掌猝翻，右掌蓦然挥斩而去，「枫叶飞散」呼啸着劈向$n",
	"force" : 380,
	"dodge" : 25,
	"damage": 62,
	"lvl" : 60,
	"skill_name" : "枫叶飞散",
        "damage_type" : "内伤"
]),
([	"action" : "$N朝着$n微微一笑，然而突然蓦然挥出右掌，只是在一伸缩间，掌风已出",
	"force" : 450,
	"dodge" : 15,
	"damage": 74,
	"lvl" : 68,
	"skill_name" : "随风散去",
        "damage_type" : "内伤"
]),
([	"action" : "$N的右掌猝然扬起，急迎而上，「回风叶旋」夹着掌风向$n的面门袭去",
	"force" : 530,
	"dodge" : 20,
	"damage": 90,
	"lvl" : 75,
	"skill_name" : "回风叶旋",
        "damage_type" : "内伤"
]),
([	"action" : "$N猝然晃动，上身突然如波浪轻颤，「落花无声」般的双掌却向$n推去",
	"force" : 530,
	"dodge" : 20,
	"damage": 81,
	"lvl" : 95,
	"skill_name" : "落花无声",
        "damage_type" : "内伤"
]),
([	"action" : "$N狂笑半声，接着$N悲愤得如泣血似的狂啸入空，一股寒气直扑$n而去",
	"force" : 530,
        "parry" : 5,
	"dodge" : 20,
	"damage": 91,
	"lvl" : 109,
	"skill_name" : "落叶萧萧",
        "damage_type" : "内伤"
]),
([	"action" : "$N突然间诡异的暴闪而出，一招「花叶齐现」幻起的掌风，分袭$n的左右",
	"force" : 530,
        "parry" : 10,
	"dodge" : 20,
	"damage": 94,
	"lvl" : 129,
	"skill_name" : "花叶齐现",
        "damage_type" : "内伤"
]),
([	"action" : "$N使出「秋叶绵绵」掌劲凝结成形，连拍出数掌，猛然击向$n",
	"force" : 530,
        "parry" : 15,
	"dodge" : 20,
	"damage": 100,
	"lvl" : 149,
	"skill_name" : "秋叶绵绵",
        "damage_type" : "内伤"
]),
([	"action" : "$N右手猝然由左至右，划出一个半弧，像一个月亮一样罩向$n",
	"force" : 530,
        "parry" : 25,
	"dodge" : 20,
	"damage": 210,
	"lvl" : 110,
	"skill_name" : "月夜无情",
        "damage_type" : "内伤"
])
});

int valid_enable(string usage) { return  usage=="hand" || usage=="unarmed" || usage=="parry" ; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("飘花落叶手只能空手练习。\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法学习飘花落叶手。\n");
	return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
	level   = (int) me->query_skill("piaohua-hand",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太差了，不能练习飘花落叶手。\n");
	me->receive_damage("qi", 25);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"piaohua-hand/" + action;
}
