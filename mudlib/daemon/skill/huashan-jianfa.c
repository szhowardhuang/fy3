// huashan-sword.c
// Modified by Venus Oct.1997
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([
        "action":      "$N使一招「有凤来仪」，手中$w剑光暴长，向$n的$l刺去",
	"damage":	50,
        "damage_type":  "刺伤"
]),
([
        "action":      "$N剑随身转，一招「无边落木」罩向$n的$l",
	"damage":	80,
        "damage_type":  "刺伤"
]),
([
        "action":      "$N舞动$w，一招「鸿飞冥冥」挟著无数剑光刺向$n的$l",
	"damage":	110,
        "damage_type":  "刺伤"
]),
([
        "action":      "$N手中$w龙吟一声，祭出「平沙落雁」往$n的$l刺出数剑",
	"damage":	140,
        "damage_type":  "刺伤"
]),
([
        "action":      "$N手中$w剑光暴长，一招「金玉满堂」往$n$l刺去",
	"damage":	170,
        "damage_type":  "刺伤"
]),
([
        "action":      "$N手中$w化成一道光弧，直指$n$l，一招「白虹贯日」发出虎哮龙吟刺去",
	"damage":	200,
        "damage_type":  "刺伤"
]),
});

int valid_learn(object me)
{
    object ob;
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
	if( (int)me->query("kee")<30
	||      (int)me->query("force")<5)
        return notify_fail("你的内力或气不够，没有办法练习华山剑法。\n")
;
	me->receive_damage("kee",30);
	me->add("force",-5);
    write("你按著所学练了一遍华山剑法。\n");
    return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}


string perform_action_file(string action)
{
return "/daemon/class/huashan/huashan-jianfa/" + action;
}
