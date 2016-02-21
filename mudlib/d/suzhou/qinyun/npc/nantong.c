// music   yangzhou's 店小二

#include <ansi.h>
inherit NPC;
void create()
{
	set_name("男童",({"nan tong","nan","tong"}));
	set("gender", "男性" );
	set("age",15);
	set("long",
	"眉清目秀的小男孩。正冲你微笑。\n");
	set("combat_exp",150);
	set("attitude", "friendly");
	set("rank_info/respect","小兄弟");
	setup();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{

	if( !ob || environment(ob) != environment() ) return;
	if(ob->query("gender")!="男性")	return;
	switch( random(2) ) {
		case 0:
	message_vision(CYN"男童对$N关照道：“这位"+
	RANK_D->query_respect(ob)+"，不要在这儿乱跑哟。”\n"NOR,ob);
			break;
		case 1:
	message_vision(CYN"男童自言自语道：不知阿朱姐姐又在装扮谁呢。\n"NOR,ob);
			break;
                           }
}
