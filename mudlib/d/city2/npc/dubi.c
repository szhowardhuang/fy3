// dubi.c 独臂神尼

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("独臂神尼", ({ "dubi shenni", "dubi" }));
	set("gender", "女性");
	set("age", 44);
	set("str", 25);
	set("dex", 20);
	set("long", "这是一位白衣女尼，手握拂尘，目视前方。\n"+
	"一只长袖空空如也，显是断了一臂，尽管如此，\n"+
	"仍然掩不住她迷人的风采。\n");
	set("combat_exp", 200000);
	set("score", 10000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("whip", 150);
	set_skill("force", 90);
	set_skill("unarmed", 90);
	set_skill("dodge", 150);
	set_skill("parry", 90);

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 40);
	set_temp("apply/damage", 100);
	set("force", 1500); 
	set("max_force", 1500);
	set("force_factor", 100);
        set("inquiry", ([
                "阿珂" :  "神尼叹了一口气，说道：她是我的得意弟子，\n人长得挺美，唉，只可惜被韦小宝骗去了。\n",
        ]) );
	setup();
       carry_object("/d/city2/obj/fuchen")->wield();
	carry_object("/obj/cloth")->wear();
	add_money("gold", 2);
}

void init()
{
::init();
remove_call_out("greeting");
call_out("greeting", 1, this_player() );
}


void greeting(object ob)
{
int i;	
object man,*obj;

man=this_object();
message_vision("$N踏进屋来，只见地上女尼横陈，喘息不止。\n",ob);		
if( !ob || environment(ob) != environment()) return;
    
if((int)ob->query_temp("hastrystab")==6)
{
message_vision(HIC "$N踏进屋来，只见地上尸体横陈，一个女尼喘息不止。\n" NOR,ob);		
ob->delete_temp("hastrystab");
ob->delete_temp("warned2");
if(ob->query("mingwang")<600)
{
ob->add("mingwang",100);
message_vision(HIC "$N的江湖名望提高了！\n" NOR,ob);
command("tell "+ob->query("id")+" 你现在的江湖名望是 " +(string)(ob->query("mingwang")));
return ;
}
message_vision(HIC "白衣女尼对$N微微一笑。\n" NOR,ob);		
return;
}
obj = all_inventory(environment(ob));
for(i=0; i<sizeof(obj); i++) {
	if( !living(obj[i]) || userp(obj[i]) || obj[i]==man ) continue;
	if( !userp(obj[i]) ) { 
		man->set_leader(obj[i]);
		man->kill_ob(obj[i]);
		obj[i]->fight_ob(man);
		}
	}
return ;
}
