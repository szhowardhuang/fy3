// musix yangzhou's ���ǹ�

inherit NPC;

void create()
{
	set_name("���ǹ�", ({ "langgou", "lang gou","wolf dog", "dog" }) );
	set("race", "Ұ��");
	set("age", 3);
	set("long", "һֻ�װͰ͵Ĵ��ǹ���\n");
	set("attitude", "peaceful");
        set("mingwang",-1);
	
	set("str", 26);
	set("cor", 30);

	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 2500);
//	set("shen_type", -1);

//	set("chat_chance", 6);
//	set("chat_msg", ({
//		(: this_object(), "random_move" :),
//	}) );
	
	set("chat_msg_combat", ({
		(: this_object(), "random_move" :),
		"���ǹ������ͽУ�������������������������\n",
		"���ǹ�ͻȻ����������������ҧ��ȴ��֪������ҧ˭��\n"
	}) );
		
	set_temp("apply/attack", 15);
	set_temp("apply/damage", 6);
	set_temp("apply/armor", 2);

	setup();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) &&
		random(ob->query_kar() + ob->query_cps()) < 20) {
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
	}	
}
void die()
{
	object ob;
	message_vision("$N�Һ�һ�������ˣ�\n", this_object());
	ob = new(__DIR__"obj/goupi");
	ob->move(environment(this_object()));
	destruct(this_object());
}
