inherit KZZNPC;

string query_save_file() { return DATA_DIR + "npc/清济"; }
void create()
{
#include <kzznpc.h>
	setup();
	carry_object("/obj/cloth")->wear();
	carry_object("/obj/std/armor/pijia")->wear();
}
void init()
{
  object ob;
  ::init();
 	command("guard up");
if (interactive(ob=this_player())&&!is_fighting()) {
    remove_call_out("greeting");
    call_out("greeting",1,ob);
    }
 }
void greeting(object ob)
{
  if (!ob||environment(ob)!=environment()) return;
  switch(random(3))   {
   case 0:
     say("清济合掌:阿~密~豆~腐!\n");
     break;
   case 1:
     say("清济摸着后脑勺,迷糊道:佛?...色?...\n");
     break;
     }
  return;
}
    

