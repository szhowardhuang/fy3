// halt.c

#include "/doc/help.h"
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob;
         if(!arg || arg == "")
                   return notify_fail("指令格式: fushu (人物)\n");
         if( !environment(me)->query("biwuchang") )
                  return notify_fail("这条指令只能在比武场使用。\n");
         if( !me->query_temp("war_biwu") )
                return notify_fail("你现在并没有在战斗。\n");
         if(!objectp(ob = present(arg, environment(me))))
                 return notify_fail("这里没有这个人。\n");
         if(ob==me)
                 return notify_fail("没这种必要吧。\n");
         if(!ob->query_temp("war_biwu") || ob->query_temp("war_biwu")!= me->name())
                 return notify_fail(ob->name()+"现在并没有和你比武啊。\n");
          me->remove_all_killer();
          ob->remove_all_killer();
         me->delete_temp("war_biwu");
          ob->delete_temp("war_biwu");
         message_vision("$N跳出圈外拱手说道: " +
                         RANK_D->query_self(me) + "武功不济，甘拜下风!\n",me);
	write("Ok.\n");
	return 1;
}

int help(object me)
{
   write(@HELP
  指令格式: fushu (人物)

 在比武场可以停止与别人的战斗。

 相关指令: biwu
HELP
   );
   return 1;
}
