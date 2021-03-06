// songshan-sword.c
// Modified by Java Sep.1998
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([
        "action":  "$N左手一拳直攻,右手如开似闭,封住对方出手,底下暗出撩阴腿.正[痛快淋漓]",
        "damage":  50,
        "damage_type":  "瘀伤"
]),
([
        "action":  "$N右手一掌封向$n面门,手掌暗颤,已是封住$n视线,左手直拳攻向$n胸口",
	"damage":80,
        "damage_type":  "瘀伤"
]),
([
        "action":  "$N右手五直叉开,挥向$n面门,左手挥动,急点$n右身数处大穴,乃是[六月挥扇]",
	"damage":110,
        "damage_type":  "瘀伤"
]),
([
        "action":  "$N使出[腊月围炉],双臂向$n身体抱去,正中出腿疾踢",
	"damage":140,
        "damage_type":  "瘀伤"
]),
([
        "action":  "$N使出[月下赏梅],左掌入弯月,斜斜向$n面门劈下,右手五指半曲,
        如梅枝斜出,指向$n",
	"damage":170,
        "damage_type":  "瘀伤"
]),
([
        "action":  "$N腰间使出铁板桥功夫,双手成提壶斟酒状,片刻间已指向
        $n嘴角,正是一招[花间酌酒]",
	"damage":200,
        "damage_type":  "瘀伤"
]),
([
        "action":  "$N右手五指直颤,急点$n数处大穴,左手成鹤形击出,乃是[弄鹤闲琴]",
	"damage":220,
        "damage_type":  "瘀伤"
]),
});

int valid_learn(object me)
{
    object ob;
    if( (int)me->query("max_force") < 50 )
        return notify_fail("你的内力不够，没有办法练快活十三掌。\n");
	if(ob = me->query_temp("weapon"))
        return notify_fail("练快活十三掌必须空手。\n");

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
        return notify_fail("你的内力或气不够，没有办法练习快活十三掌。\n");
    me->receive_damage("kee", 30);
    me->add("force", -5);
    write("你按著所学练了一遍快活十三掌。\n");
    return 1;
}


string perform_action_file(string action)
{
        return "/daemon/class/taishan/kuaihuo-zhang/" + action;
}
