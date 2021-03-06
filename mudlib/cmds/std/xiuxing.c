// dazuo.c
//Write by Huang (10/27/96)

#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int gin_cost, atman_gain;

        seteuid(getuid());
        
        if( me->is_fighting() )
                return notify_fail("战斗中不能修行，会走火入魔。\n");
        if( me->query("food")<70 )
                return notify_fail("空腹不能修行，会走火入魔。\n");

	if(!(int)me->query_skill("daoxuexinde",1))
		return notify_fail("你得先学会「道学心得」这门学问。\n");

        if( !arg
        ||      !sscanf(arg, "%d", gin_cost) )
                return notify_fail("你要花多少精修行？\n");

        if( gin_cost < 10 ) return notify_fail("你最少要花 10 点「精」才能修行。\n");

        if( (int)me->query("gin") < gin_cost )
                return 
notify_fail("你现在的精太少了，无法修行。\n");

        if( (int)me->query("sen") * 100 / (int)me->query("max_sen") < 70 )
                return notify_fail("你现在精神状况太差了，无法凝神专一！\n");

        if( (int)me->query("kee") * 100 / (int)me->query("max_kee") < 70 )
                return notify_fail("你现在气力不够，无法修行！\n");

        write("你坐下来双手虚拢，修行道行。\n");

        me->receive_damage("gin", gin_cost);

        // This function ranged from 1 to 15 when gin_cost = 30
        atman_gain = gin_cost * ((int)me->query_skill("daoxuexinde", 1)
                + (int)me->query("spi") ) / 300;

        if( atman_gain < 1 ) {
                write("但是当你行功完毕，只觉得头昏眼花。\n");
                return 1;
        }

        me->add("atman", atman_gain );

        if( (int)me->query("atman") > (int)me->query("max_atman") * 2) {
                if( (int)me->query("max_atman") >= 
                        ((int)me->query_skill("daoxuexinde", 1) + 
me->query_skill("daoxuexinde")/5) * 10 ) {
                        
write("但是你的道学心得不够，道行并没有增加！\n");
                } else {
                        write("你的道行增强了！\n");
                        me->add("max_atman", 1);
                }
                me->set("atman", me->query("max_atman"));
        }       
        
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : xiuxing [<耗费「精」的量>]

此指令可以将你的精转换为道行，并能提高自己的精力。

HELP
        );
        return 1;
}
 
