inherit NPC;
string ask_quxiao();
void create()
{
	set_name("陈帮办",({"chen bangban","chen"}));
   set("gender","男性");
   set("age",34);
   set("combat_exp",90000);
   set("long","如果你被官府通辑,只要向他打听取消
 通辑就行了.\n");
   
   set_skill("unarmed",30);
   set("nickname","钱到灾除");
   set_skill("force",30);
   set_skill("parry",30);
   set_skill("dodge",30);
set("inquiry",([
  "取消通辑":(:ask_quxiao:),
  ]));
   setup();
   carry_object("/obj/std/armor/tiejia")->wear();
}
string ask_quxiao()
{
  object ob=this_player();
  int money;
  if (!ob->query("oldsix_flag/tongji")||ob->query("oldsix_flag/tongji")!=1)
  return "你又不是通辑犯,取消什么?";
  money=ob->query("oldsix_flag/long");
  switch(money)  {
    case 0:
    case 1: return "取消通辑要10两黄金.";
    case 2: return "取消通辑要2两黄金.";
    case 3: return "取消通辑要20两银子.";
}
 return;
}
int accept_object(object who,object item)
{
  if (!item->query("money_id"))  {
 command("say tnnd,我这不是当铺.\n");
 return 0;  }
  if (!who->query("oldsix_flag/tongji"))  {
 command("say 虽然你没被通辑,但给我钱还是收下了.\n");
 return 1;  }
 if ((who->query("oldsix_flag/long")==1&&item->value()<100000)
||(who->query("oldsix_flag/long")==2&&item->value()<20000)
||(who->query("oldsix_flag/long")==3&&item->value()<2000))  {
 
  command("say 我这没有你讨价还价的份.\n");
  return 0;   }
 who->delete("oldsix_flag/tongji");
 who->delete("oldsix_flag/long");
 command("chat 官府取消对"+who->query("name")+"的通辑.\n");
 return 1;    
}
