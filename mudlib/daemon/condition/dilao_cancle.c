// snake_poison.c

#include <ansi.h>

int update_condition(object me)
{
	if((me->query("mud_age"))-(me->query("dilao_flag/time"))>=300)
 { 
	me->set("dilao_flag/lao",0);
message_vision("蒙云指了指$N道:你!就是你!看什么看,可以出去了,快走!\n",me);
return 0;
	}
me->apply_condition("dilao_cancle");
	return 1;
}
