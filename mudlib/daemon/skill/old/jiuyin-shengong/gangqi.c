inherit SKILL;

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int damage;

        me->add("force", - factor );
        damage = (int)me->query("force")/20 + factor
                - (int)victim->query("force")/25;

        if( damage < 0 ) {
                if( !me->query_temp("weapon")
                &&      random(victim->query_skill("force")) > me->query_skill("force")/2 ) {
                        damage = - damage;
                        me->receive_damage( "kee", damage * 1.5 );
                        me->receive_wound( "kee", damage );
                        if( damage < 10 ) return "$n九阴罡气护体，竟能抵挡住$N的猛烈攻击。\n";
                        else if( damage < 20 ) return "$n运起九阴神功，周身肌肉暴涨，现出微弱蓝光，把$N的攻击震开了。\n";
                        else if( damage < 40 ) return "$n用尽全力运起九阴罡气,$N怎么也攻不进去。\n";
                        else return "$n将逆运之九阴神功提升到极尽，浑身蓝光暴现，将$N震飞出几丈之外。\n";
                }
                if( damage_bonus + damage < 0 ) return - damage_bonus;
                return damage;
        }

        damage -= victim->query_temp("apply/armor_vs_force");
        if( damage_bonus + damage < 0 ) return - damage_bonus;
        if( random(me->query_skill("force")) < damage )
                return damage;
}
