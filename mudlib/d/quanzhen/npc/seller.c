// seller.c

inherit NPC;
inherit F_VENDOR;

string ask_me();

void create()
{
	set_name("С��",({"xiao fan"}));
	set("gender", "����" );
	set("age", 32);
	set("long",
		"���Ǹ�С����������������ʵʵ�������������Ƕ��ͱ��ˡ�\n");
	set("combat_exp", 300);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
	set("attitude", "friendly");
	set("vendor_goods", ([
		"1":__DIR__"obj/stick",
                "2":__DIR__"obj/bottle",
                "3":__DIR__"obj/egg",
	]) );
        set("inquiry", ([
		"ҩ" : (: ask_me :),
		"ҩ��" : (: ask_me :),
        ]) );
	setup();
        carry_object(__DIR__"obj/cloth")->wear();
	add_money("coin", 100);
}

void init()
{
        ::init();
        add_action("do_vendor_list", "list");
}

string ask_me()
{
	object me=this_player();
	if ( me->query_temp("tmark/ҩ")) {
		return "�����ϴ�����û��������ô���µ��ˣ�\n";
	}
	else {
		me->set_temp("tmark/ҩ",1);
		return "�����ҵ�����ɭ���в�ҩ������������һЩ��ҩ�ģ�Ҫ����Ƚ�Ǯ��\n";
	}
}

int accept_object(object who, object ob)
{
    	object obj;

    	if ((ob->query("money_id")) && (ob->value() >= 10000)
	 && (who->query_temp("tmark/ҩ")))
	{
        	obj = new(__DIR__"obj/shouwu");
        	obj->move(who);
        	who->add_temp("tmark/ҩ",0);
		write("С��˵��������Ȼ���������Ǯ����ζҩ�ɾ͹����ˡ���\n");
        	return 1;
        }
    	else 
		if (ob->query("money_id"))
		{
			write("С����Цһ����˵�������ٺ٣�������ô��Ǯ�ġ���\n");
			return 1;
        	}
		else {
			return notify_fail("С�������˵���������������ʲô����\n");
		}
}