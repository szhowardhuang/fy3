inherit SKILL;

string *dodge_msg = ({
	"只见$n使出[洛神凌波],衣诀飘飘,脚下如凌波踏水,快速几步,已避开攻击。\n",
	"但是$n使出[凌空虚度],提气纵起,在空中连跨七步,已在$N寻丈之外。\n",
	 "$n一招[布法行云],脚踏子午,掌分阴阳,不经意间避过$N这一招。\n",
	"可是$n一个[风起云涌],身形如被大风所吹,飘飘优悠落到$N身后。\n",
	"却见$n使出[春风拂柳],一足脚尖点地,身如弱柳,俯仰不定,$N这招可落了空。\n",
	"$n使出[秋风萧瑟],一手捂胸,挺身前行,大有壮士一去不复返之势,
	$N被其气势所慑,只得退开。\n"
});

int valid_enable(string usage) { return (usage == "dodge"); }

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 45 )
		return notify_fail("你的体力太差了，不能练风神诀。\n");
	me->receive_damage("kee", 35);
	return 1;
}

