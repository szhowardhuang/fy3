inherit FORCE;

int valid_enable(string usage) { return usage=="parry";}

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return 
notify_fail("金刚不坏功只能用学的。\n");
}

 
int effective_level() { return 20;}

string *absorb_msg = ({
		"$n使出斗转星移，将招数尽数转攻$N的身上。\n",
});

string query_absorb_msg()
{
        return absorb_msg[random(sizeof(absorb_msg))];
}

int bounce_ratio()
{
        return 10;
}

int learn_bonus()
{
        return -10;
}
int practice_bonus()
{
        return -5;
}
int black_white_ness()
{
        return 20;
}
