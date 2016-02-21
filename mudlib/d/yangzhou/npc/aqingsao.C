// aqingsao.c ����ɩ

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("����ɩ", ({ "aqing sao", "sao" }));
	set("title", "����ϰ���");
	set("nickname", "����һ֧��");
	set("mingwang", 1);
	set("str", 30);
	set("gender", "Ů��");
	set("age", 25);
	set("long",
		"����ɩ�����ݳ��������Ĵ����ˣ���Ϊү������ϲ����������䣬\n"
		"�������Գ����һ��һ��������ִ�ơ�\n");
	set("combat_exp", 5000);
	set("attitude", "friendly");
	set("vendor_goods", ([
		"���㻨��":   __DIR__"obj/huasheng",
		"�����":   __DIR__"obj/bowl",
	]));
	set("inquiry", ([
		"����" : "���ǼҰ���ȥ����������ȥ��Ү��\n",
		"����" : "���ô������\n",
	]));
	

	setup();
	carry_object("/obj/cloth")->wear();
	        add_money("silver", 4);
}
void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

        add_action("buy_object", "buy");
        add_action("buy_object", "mai");
        add_action("do_vendor_list", "list");
        add_action("do_vendor_list", "wen");
        add_action("do_sell", "sell");
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment())
		return;
	switch(random(2)) {
	case 0 :
		say("����ɩЦ���е�˵������λ" + RANK_D->query_respect(ob) +
			"����������ȱ��Ȳ衣\n");
		break;
	case 1 :
		say("����ɩ˵����Ӵ����λ" + RANK_D->query_respect(ob) + 
			"�����˰��������и�ը�õ����㻨�����ۡ�\n");
		break;
		
	}
}

