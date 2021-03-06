inherit NPC;
void create()
{
  set_name("察尔珠",({"chaer zhu"}));
  set("gender","男性");
  set("age",49);
  set("nickname","都统");
  set("combat_exp",300000);
  set("force",700);
  set("max_force",700);
  set("force_factor",40);
  
  set_skill("unarmed",40);
  set_skill("dodge",40);
  set_skill("parry",40);
  set_skill("blade",40);
  set_skill("wuhu-duanmendao",40);
  set_skill("anying-fuxiang",40);
  map_skill("blade","wuhu-duanmendao");
  map_skill("parry","wuhu-duanmendao");
  map_skill("dodge","anying-fuxiang");
  
  set("chat_chance",4);
  set("chat_msg",({
  "察尔珠道:北门的钱兴隆的肉猪是供奉的.\n",
  "察尔珠道:天地会不灭,京城看来不会太平.\n",
  "察尔珠道:只有太监和蒙皇上召见才能进出皇宫.\n",
  }));
  setup();
  carry_object("/obj/weapon/blade")->wield();
  carry_object("/obj/std/armor/tiejia")->wear();
  carry_object("/obj/std/armor/tiekui")->wear();
  carry_object("/obj/std/armor/tiexue")->wear();
  add_money("silver",50);
}
  