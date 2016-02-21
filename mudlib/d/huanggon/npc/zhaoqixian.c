inherit NPC;
void create()
{
  set_name("赵齐贤",({"zhao qixian","zhao"}));
  set("gender","男性");
  set("nickname","御前侍卫");
  set("age",34);
  set("combat_exp",200000);
  set("force",300);
  set("force_factor",24);
  set("chat_chance",3);
  set("chat_msg",({
  "赵齐贤道:昨晚宫中不大太平,幸好我躲在被窝中.\n",
  "赵齐贤道:刺客招供是平西王派来的,这老小子好大胆.\n",
  "赵齐贤道:跟了桂公公,升官发财不用愁.\n",
  }));
  
  set_skill("dodge",50);
  set_skill("parry",50);
  set_skill("blade",50);
  set_skill("unarmed",50);
  set_skill("wuhu-duanmendao",50);
  set_skill("huashan-quanfa",50);
  map_skill("blade","wuhu-duanmendao");
  map_skill("parry","huashan-quanfa");
  map_skill("unarmed","huashan-quanfa");
  setup();
  carry_object("/obj/std/armor/pijia")->wear();
  carry_object("/obj/weapon/blade")->wield();
  add_money("silver",50);
 }
#include "shiwei.h"
