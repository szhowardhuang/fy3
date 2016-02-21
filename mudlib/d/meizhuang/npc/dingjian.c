// woodcutter.c
#include <ansi.h>
inherit NPC;
int do_ask();
void create()
{
	set_name("丁坚",({"dingjian","ding jian","ding"}));
	set("gender", "男性" );
	set("age",55);
	set("long","曾威震江湖，而今隐居在此的老者。\n");
	set("nickname","一字电剑");
	set("combat_exp",300000);
	set("str", 30);
	set("mingwang",-1);
	set_skill("unarmed",50);
	set_skill("dodge",50);
	set_skill("parry",50);
	set_skill("sword",50);
	set("max_force",1000);
	set("chat_chance",2);
	set("chat_msg",({
		"“唰”的一声，只见丁坚手中长剑划出一道闪亮的光芒。\n",
		"只听见丁坚自言自道：二庄主他。。。也。。。干什么。。\n",
		"丁坚嘴角边忽然闪过一丝"+YEL"冷笑"NOR+"。\n",
	}));
	set("force",1000);
	set_skill("xuantian-bu",50);
	set_skill("xuantian-quan",50);
	set_skill("qixianwuxing-jian",50);
	set("inquiry",([
		"二庄主":	(: do_ask :),
		"冷笑":		"怎么，不行啊。老子还想奸笑呢，管得着吗！\n",
	]));
	map_skill("unarmed","xuantian-quan");
	map_skill("dodge","xuantian-bu");
	map_skill("sword","qixianwuxing-jian");
	map_skill("parry","qixianwuxing-jian");
	setup();
	carry_object(__DIR__"obj/qingyi")->wear();
	carry_object("/obj/weapon/sword")->wield();
	add_money("silver",50);
}
int do_ask()
{
	object me;
	string something;
	 something="我前几天发现二庄主趁大庄主不在，偷偷溜进内室去了，也不知干啥。";
	me=this_player();
	if(me->query("family/family_name")!="孤山梅庄")	{
		command("say 这是我们梅庄的事，"+RANK_D->query_respect(me)+"还是少操这份心吧。\n");
		return 1;
	}
	message_vision("丁坚突然神秘兮兮的对着$N耳语了几句。\n",me);
	tell_object(me,"丁坚对你说道："+something+"\n");
	me->set_temp("oldsix_flag/ask",1);
	return 1;
}
