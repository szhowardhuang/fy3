// dagou-bang.c 打狗棒法
// Modified by Venus Oct.1997
// write by Xiang

inherit SKILL;

mapping *action = ({
([  "action": "$N使出一招「棒打双犬」，手中$w化作两道青光砸向$n的$l",
	"damage":100,
	"limb":"面颊",
    "damage_type": "挫伤"
]),
([  "action": "$N手中$w左右晃动，一招「拨草寻蛇」向$n的$l攻去",
	"damage":150,
	"limb":"咽喉",
    "damage_type": "挫伤"
]),
([  "action": "$N举起$w，居高临下使一招「打草惊蛇」敲向$n的$l",
	"damage":150,
    "damage_type": "挫伤"
]),
([  "action": "$N施出「拨狗朝天」，$w由下往上向$n的$l撩去",
	"damage":200,
	"limb":"裆部",
    "damage_type": "挫伤"
]),
});

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_force")<100)
      return notify_fail("你的内力不够。\n");
    return 1;
}

mapping query_action(object me, object weapon)
{
    if (random(me->query_skill("staff",1)) > 60 &&
        me->query_skill("force",1) > 60 &&
	me->query("force")>100 &&
	objectp(weapon) &&
        (string)weapon->query("id") == "yuzhu zhang" ) {
	me->add("force",-100);
        return ([
      "action": "$N眼中射出一道青芒，手中玉竹杖使出「天下无狗」，劈天盖地劈落",
      "damage": 500,
      "damage_type": "挫伤"]);
    }
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
    object weapon;

    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "staff")
      return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("kee")<50)
      return notify_fail("你的体力不够练打狗棒法。\n");
	me->receive_damage("kee",40);
    return 1;
}

string perform_action_file(string action)
{
        return __DIR__"dagou-bang/" + action;
}
int power_point()	{	return 2;	}
int hard_point()	{	return 3;	}
