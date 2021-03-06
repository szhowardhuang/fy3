// feng.c 风清扬

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("风清扬", ({ "feng qingyang", "feng", "qingyang" }));
//	set("nickname", "大师兄");
	set("long", 
"他就是华山剑宗的长老风清扬。他身材瘦长，眉宇间一直笼罩着一股淡淡的忧伤\n"
"神色，显然对当年的剑宗气宗之争一直难以忘怀。\n");
	set("gender", "男性");
	set("age", 68);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 35);
	set("dex", 35);
	
	set("kee", 5500);
	set("max_kee", 5500);
	set("gin", 3600);
	set("max_gin", 3600);
	set("force", 5500);
	set("max_force", 5500);
	set("force_factor", 200);

	set("combat_exp", 2750000);
	set("score", 500000);

	set_skill("force", 200);
	set_skill("blade", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("unarmed",200);
	set_skill("zixia-shengong", 200);
	set_skill("poyu-quan", 200);
	set_skill("fanliangyi-dao", 200);
	set_skill("huashan-jianfa", 200);
	set_skill("hunyuan-zhang", 200);
	set_skill("dugu-jiujian", 200);
	set_skill("feiyan-huixiang",200);
	set_skill("literate", 200);

	map_skill("force", "zixia-shengong");
	map_skill("dodge", "feiyan-huixiang");
	map_skill("parry", "dugu-jiujian");
	map_skill("sword", "dugu-jiujian");
	map_skill("blade", "fanliangyi-dao");
	map_skill("unarmed", "hunyuan-zhang");

	create_family("华山派", 12, "弟子");

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.poqi" :),
//		(: perform_action, "sword.pozhang" :),
//		(: perform_action, "sword.pojian" :),
		(: exert_function, "recover" :),
	}) );

	setup();
	carry_object("/obj/cloth")->wear();
	carry_object("/obj/weapon/sword")->wield();
}

void attempt_apprentice(object ob)
{
	int student_num;
	string temp;
	string line;

	temp = read_file("/data/npc/fengqingyang", 1, 1);
	student_num = atoi(temp);

	line = "风清扬说道：“我现在共有" + temp + "个徒弟。”\n";
	write(line);

          if ( student_num == 8)
	{
                  command("say 你来晚了，我已经收了八个徒弟了。");
		return;
	}

	if ((string)ob->query("family/family_name") != "" &&
	    (string)ob->query("family/family_name") != "华山派")
	{
		command("say " + RANK_D->query_respect(ob) + "既然已有名师指点，何必又来拜老朽呢？");
		return;
	}
         if ((int)ob->query("mingwang") < 1000000)
	{
		command("say 我华山派乃是堂堂名门正派，对弟子要求极严。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}

	command("say 好吧，我就收下你了。");
	command("recruit " + ob->query("id"));
	if((string)ob->query("class") != "xiake")
		ob->set("class", "xiake");
	ob->set("oldsix/fengqingyang",1);

	student_num++;
//	temp = itoa(student_num);
	if(student_num == 1)
		temp = "1";
	else if(student_num == 2)
		temp = "2";
	else if(student_num == 3)
		temp = "3";
	write_file("/data/npc/fengqingyang", temp, 1);
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
	string family;
	
	family=(string)ob->query("family/family_name");
	if(family!="华山派" && (int)ob->query("oldsix/fengqingyang"))	{
		command("say 哼，让老夫亲手收拾你这个华山叛徒！");
		kill_ob(ob);
		ob->fight_ob(this_object());
	}
}

