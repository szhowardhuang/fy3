#include <ansi.h>

inherit NPC;
string do_yaoqing();


void create()
{
    set_name("冷谦", ({ "leng qian", "leng", "qian", }));
        set("long",
        "他是一位冷冷的老者，身穿一件白布长袍。\n"
        "他说话极为简捷，便是杀了他的头也不肯多说半句废话。\n"
        );

	set("banghui","明教");
	set("bh_rank","散人");
    set("nickname", "冷面先生");
        set("gender", "男性");
        set("attitude", "friendly");

    set("age", 54);
        set("shen_type", 1);
       set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        set("max_kee", 500);
        set("max_kee", 500);
        set("force", 500);
        set("max_force", 500);
        set("force_factor", 40);
        set("combat_exp", 50000);
        set("score", 5000);

        set_skill("force", 45);
        set_skill("sanyang-shengong", 45);
       set_skill("tianlong-bu",50);
        set_skill("dodge", 50);
	set_skill("unarmed",50);
        set_skill("fengyun-shou",45);
        set_skill("parry", 45);
        set_skill("literate", 60);

	map_skill("force","sanyang-shengong");
	map_skill("dodge", "tianlong-bu");
        map_skill("parry", "fengyun-shou");
	map_skill("unarmed","fengyun-shou");
	set("inquiry", ([
		"加入明教" : (:do_yaoqing:),
	]));

        setup();

    carry_object("/d/mingjiao/obj/baipao")->wear();
}

void init()
{
	object ob;

	::init();

	if( interactive(ob=this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting",1,ob);
	}
}

void greeting(object ob)
{
	string banghui;
	if(!ob || environment(ob)!=environment()) return;
	banghui=(string)ob->query("banghui");
	if(! banghui || banghui!=(string)query("banghui"))
	message_vision("$N对$n点头微笑道：你，"+
	YEL"加入明教"NOR+"？\n",this_object(),ob);
	else
	message_vision("$N冲着$n点了点头。\n",this_object(),ob);
}
string do_yaoqing()
{
	object ob;
	string banghui;
	ob=this_player();
	banghui=(string)ob->query("banghui");
	if(! banghui)	{
	if((int)ob->query("have_banghui")<=4)	{
		ob->set_temp("oldsix/target",this_object());
		return "入本教(jiaru leng)，快。";
	}
	else	return "入会太多，本教不要。";
	}
	else if(banghui !=(string)query("banghui"))	{
		return "哼，你先脱离"+banghui+"，再说。";
	}
	else	return "哈，别开玩笑。";
}



