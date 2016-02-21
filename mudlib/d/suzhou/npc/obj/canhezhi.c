// jinchuang.c 金创药

#include <ansi.h>
inherit ITEM;



void create()
{
	set_name("参合指要诀",({"canhezhi","shu","book"}));
	set("unit","本");
	set("long","一本记载着「参合指」指法的小册子。\n");
	set("no_drop",1);
	set("no_get",1);
	setup();
}
void init()
{
	add_action("do_study","study");
	add_action("do_study","du");
}
int do_study(string arg)
{
	int k;
	object me;
	me=this_player();
	if( !living(me))	return 0;
	if (!id(arg))
	return 0;
	if(me->query_skill("murongquanfa",1)<40||!me->query_skill("murongquanfa",1))
	{
	tell_object(me,"你的「慕容拳法」功力不够，还没有领悟「参合指」呢。\n");
	return 1;
	}
	k=me->query("oldsix_flag/canhezhi");
	if(!k||k==0)	k=3;
	if(k==10)	
	{
	tell_object(me,"你的「参合指」已达到最高级了，再研究它也没用啦。\n");
		return 1;
	}
	message_vision("$N正仔细专研「参合指」指法。\n",me);
	if(me->query_int()<24+(k-2)*3)
	{
	tell_object(me,"以你当前的领悟力还难以理解更深的「参合指」指法。\n");
		return 1;
	}
	if(random(me->query_kar())<25)
	{
	tell_object(me,"你好象对「参合指」有所理解，但又不敢肯定。\n");
		return 1;
	}
	tell_object(me,CYN"你的「参合指」等级提高了！\n"NOR);
	k=k+1;
	 me->set("oldsix_flag/canhezhi",k);
	return 1;
}
