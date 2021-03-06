//七弦无形剑
inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N使一招「弦外有音」，手中$w如一风一般卷向$n的$l",
		"damage":		100,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N伸指在$w上一弹，趁$w轻响之际一招「庸人自扰」，剑光向残照般洒向$n的$l",
		"damage":120,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N一招「寂寞无声」，手中$w默默的削向$n的$l",
		"damage":140,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N手中$w一式「珠落玉盘」对准$n的$l一连刺出数剑",
		"damage":160,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N的$w凭空一指，一招「有所思」刺向$n的$l",
		"damage":180,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N手中$w向外一分，使一招「清心普善」反手对准$n$l一剑刺去",
		"damage":		200,
                "damage_type":  "刺伤"
        ]),
	([	"action":
"$N忽然眼中精光四射，一招「六丁开山」，一阵寒气逼个的剑气直逼$n",
		"damage":		250,
		"damage_type":		"内伤",
	]),
});

int valid_learn(object me)
{
    if(me->query_skill("xuantian-quan",1)<20)
        return notify_fail("你的「玄天拳法」不够娴熟。\n");
    if(me->query_skill("xuantian-neigong",1)<20)
    return notify_fail("你的「玄天内功」功力不够。\n");
    if(me->query("max_force")<50)
    return notify_fail("你的内力修为不够。\n");
        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object ob;
	        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
			return notify_fail("你必须先找一把剑才能练剑法。\n");
	if( (int)me->query("kee") <40)
                return 
	notify_fail("你的气不够，没有办法练习「七弦无形剑」。\n");
	me->receive_damage("kee",40);
        return 1;
}

string perform_action_file(string action)
{
return "/daemon/class/meizhuang/qixianwuxing-jian/"+action;
}
 

int power_point()	{	return 1.25;	}
