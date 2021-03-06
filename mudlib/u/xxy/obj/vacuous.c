#include <dbase.h>
#include <name.h>

void init()
{
   add_action("do_unwrap", "unwrap");
   add_action("do_coat", "coat");
}

string extra_long()
{
   string str;
   if (query("vacuous/status"))   
     str="这个"+name()+"盖得紧紧的.\n";
      else   str="这个"+name()+"打开着.\n";
return str;
}

int do_coat(string arg)
{
        if ( !living(this_player()))
           return 1;
   if( !this_object()->id(arg) ) return 0;
   if( this_player()->is_busy() )
     return notify_fail("你上一个动作还没有完成。\n");
   if( query("vacuous/status")==1 )
     return notify_fail( "这个"+name() +"已经盖好了.\n");
   add("vacuous/status", 1);
     message_vision("$N用"+query("vacuous/name")+"把" + name() + "盖上了.\n", this_player());
   if( this_player()->is_fighting() ) this_player()->start_busy(2);
   return 1;
}

int do_unwrap(string arg)
{
   if( !living(this_player()))
     return 1;
   if( !this_object()->id(arg) ) return 0;
   if( this_player()->is_busy() )
     return notify_fail("你上一个动作还没有完成。\n");
   if( query("vacuous/status")!=1 )
     return notify_fail("这个"+name()+"已经打开了!\n");
   message_vision("$N打开" + name() + "上的"+query("vacuous/name")+"。\n", this_player());
   add("vacuous/status",-1);
   if( this_player()->is_fighting() ) this_player()->start_busy(2);
   return 1;
}
