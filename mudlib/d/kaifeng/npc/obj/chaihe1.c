// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// shugan.c

#include <weapon.h>

inherit STAFF;

void create()
{
   set_name("柴禾", ({ "chaihe", "staff" }) );
   set_weight(2000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "根");
     set("material", "wood");
     set("long", "这是一根粗长的树枝。\n");
     set("weapon_prop/courage", -4);
   }
   init_staff(5);
   setup();
}
