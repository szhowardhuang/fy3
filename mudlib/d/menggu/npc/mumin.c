inherit NPC;
void create()
{
   set_name("�ɹ�����",({"mu min"}));
   set("gender","����");
   set("long","��ľ�沿��������!\n");
   set("mingwang",5000);
   set("combat_exp",60000);
   set("area_name","�ɹŲ�ԭ");
   
set("age",54);
   set("kee",600);
   set("max_kee",600);
set("food",250);
set("water",250);
   set("force",200);
   set("max_force",200);
   set("force_factor",20);

   set_skill("dodge",60);
   set_skill("force",60);
   set_skill("parry",60);
   set_skill("unarmed",60);

   setup();
   add_money("silver",3);
carry_object("/obj/cloth")->wear();
}
void init()
{
        object area;
        area=new("/obj/area");
	area->create(query("area_name"));
        set("banghui",(string)area->query("banghui"));
        destruct(area);
}