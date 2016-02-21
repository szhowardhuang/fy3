inherit F_DEALER;
inherit KZZNPC;
string query_save_file() { return DATA_DIR + "npc/刘朝奉"; }

void create()
{
#include <kzznpc.h>
   set("area_name","扬州当铺");
        set("area_file","/d/yangzhou/dangpu");

   set_name("刘朝奉",({"liu chaofeng","liu"}));
   set("long","这个刘朝奉听说年轻的时候是一个学武之人。\n");
   set_max_encumbrance(100000000);
   set("combat_exp",1200000);
   set("force",1000);
   set("max_force",1000);
   set("force_factor",30);
   set("max_kee",1500);
set("kee",1500);
   set("mingwang",1500);
   set_temp("apply/armor",50);
   set_temp("apply/damage",25);
   
   setup();
   carry_object("/obj/cloth")->wear();
   carry_object("/obj/std/armor/pijia")->wear();
   add_money("gold",2);
}
void init()
{
   ::init();
        add_action("do_list","list");
        add_action("do_sell","sell");
        add_action("do_value", "value");
        add_action("do_buy","buy");
}
void unconcious()
{

        message_vision("\n$N死了。\n", this_object());
        destruct(this_object());
}

