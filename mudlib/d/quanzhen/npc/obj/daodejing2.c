// daodejing-ii.c

inherit ITEM;

void create()
{
	set_name( "道德经「下卷」", ({ "jing", "daode jing" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是一册道德经「下卷」，由同异第四十一始至显质第八十一止。\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":"daoxuexinde",
			"exp_required":	0,	// minimum combat experience required
			"sen_cost":30+random(11),
			"max_skill":80,
		]) );
	}
}
