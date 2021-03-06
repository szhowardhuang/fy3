// songshan-sword.c
// Modified by Java Sep.1998
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([
        "action":  "$N右手当胸一立，左手五指半曲,向$n击去",
	"damage":50,
        "damage_type":  "瘀伤"
]),
([
        "action":  "$N左手成阳掌,右手阴掌,两掌一拍,铮然有声,正是乾坤合一",
        "damage":  80,
        "damage_type":  "瘀伤"
]),
([
        "action":  "$N拇指,小指相扣,双掌击出之时,上下互换,刹那间已交叠三次,
        只见掌影如山,向$n的胸口冲去",
	"damage":110,
        "damage_type":  "瘀伤"
]),
([
        "action":  "$N双掌虚虚相合,忽又十指次第散开,双臂圆转如轮,
        只见一圈臂影中无数指影向$n击去",
	"damage":140,
        "damage_type":  "瘀伤"
]),
([
        "action":  "$N左手向外一分，右手在刹那间连出三下杀手,正是龙壶飞瀑一招",
	"damage":170,
        "damage_type":  "瘀伤"
]),
([
        "action":  "$N双掌一顿尤翻,寒冰真气如针般射出",
	"damage":200,
        "damage_type":  "瘀伤"
]),
([
        "action":  "$N使出万里冰封,双掌在击出之时稍稍一顿,掌缘上无端结上
        一层寒冰,双掌推出之时,真力到处,空中出现一条冰雾",
	"damage":220,
        "damage_type":  "瘀伤"
]),
});

int valid_learn(object me)
{
    object ob;
    if( (int)me->query("max_force") < 50 )
        return notify_fail("你的内力不够，没有办法练大嵩阳掌。\n");
	if(ob = me->query_temp("weapon"))
        return notify_fail("练大嵩阳掌必须空手。\n");

    return 1;
}

int valid_enable(string usage)
{
    return usage=="unarmed" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
    if( (int)me->query("kee") < 30
    ||      (int)me->query("force") < 5 )
        return notify_fail("你的内力或气不够，没有办法练习大嵩阳掌。\n");
    me->receive_damage("kee", 30);
    me->add("force", -5);
    write("你按著所学练了一遍嵩山剑法。\n");
    return 1;
}


string perform_action_file(string action)
{
        return __DIR__"songyang-zhang/" + action;
}
