// hengshan-jian.c 恒山剑法
// Made by deaner
// Modified by Venus Oct.1997
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action" : "$N虚步提腰，一招"+HIC"『朴实无华』"NOR+"，剑招看似平淡却暗含后着，手中$w点向$n的$l",
	"damage":50,
    "damage_type" : "刺伤",
]),
([  "action" : "$N使出一式"+HIC"『开门见山』"NOR+"，挥舞$w直刺$n的$l",      
	"damage":60,
    "damage_type" : "刺伤",
]),
([  "action" : "$N祭出一招"+HIC"『弹剑有音』"NOR+"，手里$w剑光暴长，已罩向$n的$l",
	"damage":70,
    "damage_type" : "刺伤",
]),
([  "action" : "$N双手握剑，一招"+WHT"『远离尘埃』"NOR+"，$w看似随意地划向$n的$l",
	"damage":80,
    "damage_type" : "割伤",
]),
([  "action" : "$N施展出"+HIW"『菩提明净』"NOR+"，左手合什微喧佛号，右手$w如游龙般击向$n的$l",
	"damage":90,
    "damage_type" : "刺伤",
]),
([  "action" : "$N凝神使出"+HIW"『心净如泓』"NOR+"，$w在胸前飞舞数圈后化为白泓点向$n的$l",
	"damage":100,
    "damage_type" : "刺伤",
]),
([  "action" : "$N双足一点，一招"+MAG"『心魔缠身』"NOR+"，鬼魅般欺至$n面前，$w带着一道飞芒逼向$n的$l",
	"damage":110,
    "damage_type" : "刺伤",
]),
([  "action" : "$N原地一转，使出"+HIM"『恶魔附体』"NOR+"，$n却见四面八方皆是$N，无数把$w闪烁不定刺向自己的$l",
	"damage":120,
    "damage_type" : "刺伤",
]),
([  "action" : "$N飞身跃起，祭出"+HIR"『万劫不复』"NOR+"，$w发出一声龙吟从半空中洒向$n的$l",
	"damage":130,
    "damage_type" : "刺伤",
]),
([  "action" : "$N右手微微一震，一招"+HIB"『缩地三尺』"NOR+"，快速绝伦地揉身而上，手中$w飘忽不定地洒向$n的$l",
	"damage":150,
    "damage_type" : "刺伤",
]),
([  "action" : "$N神色平和地微微低首，一招"+YEL"『仙风道骨』"NOR+"，$w剑尖游移不定地刺向$n的$l",
	"damage":170,
    "damage_type" : "刺伤",
]),
([  "action" : "$N双手和什，使出一招"+HIY"『仙降于世』"NOR+"，$w平平地飞出刺向$n的$l",
	"damage":190,
    "damage_type" : "刺伤",
]),
([  "action" : "$N面露微笑，一招"+HIY"『普渡众生』"NOR+"，$w一闪间舞出无数团剑花刺向$n的$l",
	"damage":200,
    "damage_type" : "刺伤",
])
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry")
; }

int valid_learn(object me)
{
    if ((string)me->query("gender") != "女性" )
   return notify_fail(HIY"这种阴柔的剑法只有女子才适合学。\n"NOR);
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
    || (string)weapon->query("skill_type") != "sword")
   return notify_fail("你使用的武器不对。\n");
	if((int)me->query("kee")<50)
   return notify_fail("你的体力不够练恒山剑法。\n");
	me->receive_damage("kee",30);
    return 1;
}

string perform_action_file(string action)
{
    return __DIR__"hengshan-jian/" + action;
}
int power_point()	{	return 1.25;	}
int hard_point()	{	return 2;	}

