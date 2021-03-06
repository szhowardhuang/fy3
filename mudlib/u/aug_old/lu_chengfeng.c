// lu_chengfeng.c 陆乘风
// str = 膂力, int = 悟性, cps = 定力, con = 根骨, wis = 慧根, dex = 机敏。
// 97.8.18  by Aug

//#include <localtime.h>

inherit NPC;
inherit F_MASTER;


void enter_room();
void leave_room();

int give_letter();

int IN_BOOKROOM=1;

void create()
{
	set_name("陆乘风", ({ "lu chengfeng", "lu" }) );
	set("title", "江南归云庄庄主");
	set("gender", "男性" );
	set("long",
"陆乘风约莫四十左右年纪，脸色枯瘦，似乎身患重病，身材甚高。
可惜双腿残废了。但他目光炯炯有神，上身挺的笔直，端的是条好汉！\n");

	set("age", 46);
	set("str", 30);
	set("cor", 30);
	set("cps", 33);
 	set("int", 30);
	
	set("shen_type", 1);

	set("max_force", 5000);
	set("force", 5000);
	set("force_factor", 3);


	create_family("桃花岛", 2, "弟子");

	set("combat_exp", 300000);
	set("score", 30000);
	set("mingwang",30000);

	set_skill("force", 120);
	set_skill("parry", 120);
	set_skill("dodge", 120);
	set_skill("sword", 120);
	set_skill("literate", 150);

     	set_skill("suiyu-force",120);
     	set_skill("luoying-sword",120);
     	set_skill("luoying-strike",120);
     	set_skill("bagua-steps",120);
     	set_skill("lanhua-finger",120);
	
	map_skill("dodge",  "bagua-steps");
	map_skill("unarmed","lanhua-finger");
	map_skill("parry",  "luoying-sword");
	map_skill("force",  "suiyu-force");
    	map_skill("sword",  "luoying-sword");

	set("inquiry", ([
		"陆家庄" : "这里便是陆家庄",
		"归云庄" : "这里便是归云庄",
		"桃花岛" : (: give_letter :),
	]) );	
//	set("schedule", ([
//		600: (: enter_room :),
//		2200: (: leave_room :),
//	]));

	setup();
	add_money("gold", 5);
	carry_object("/obj/cloth")->wear();
	carry_object("/obj/weapon/sword")->wield();
}

void attempt_apprentice(object ob)
{
	if(ob->query("family/generation")<=2)
	{
		command("?");
		command("say " + RANK_D->query_respect(ob) +  "这是开的什么玩笑啊？");
		return;		
	}


	if( ((int)ob->query_skill("suiyu-force",1)<40)) 
	{
		command("sigh");
		command("say " + RANK_D->query_respect(ob) +  "，你的碎玉神功似乎还不到家呀！别泄气，继续努力呀！");
		return;
	}

	if( ((int)ob->query_skill("literate",1)<40)) 
	{
		command("sigh");
		command("say " + RANK_D->query_respect(ob) +  "，你的读书写字似乎还不到家呀！别泄气，继续努力呀！");
		return;
	}

	
	if ( (ob->query("mingwang")<5000)&&(ob->query("mingwang")>(-5000)) )
	{
        command("sigh");
        command("say " + RANK_D->query_respect(ob) + 
        "，你的名望太差了吧？我要是收你做弟子，别人会笑话我的。");
        return;
      }

	command("haha");
	command("say 好！好！" + RANK_D->query_respect(ob) +  "，从今往后你就是我的亲传弟子了，可要给低辈弟子做榜样噢！\n");
 	command("recruit " + ob->query("id") );
}

void recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
 		ob->set("class1", "taohua");
}

int give_letter()
{
	object ob,ob2;

	ob=this_player();

	if(ob->query("family/generation")<=2)
	{
		command("?");
		command("say " + RANK_D->query_respect(ob) +  "这是看的什么玩笑啊？");
		return 1;		
	}

	if( ((int)ob->query_skill("suiyu-force",1)<80)) 
	{
		command("sigh");
		command("say " + RANK_D->query_respect(ob) +  "，你的碎玉神功似乎还不到家呀！别泄气，继续努力呀！");
		return 1;
	}

	if( ((int)ob->query_skill("literate",1)<40)) 
	{
		command("sigh");
		command("say " + RANK_D->query_respect(ob) +  "，你的读书写字似乎还不到家呀！别泄气，继续努力呀！");
		return 1;
	}

	
	if ( (ob->query("mingwang")<20000)&&(ob->query("mingwang")>(-20000)) )
	{
        command("sigh");
        command("say " + RANK_D->query_respect(ob) + 
        "，你的名望太差了吧？无名之辈可别想进桃花岛。");
        return 1;
      }

	command("haha");
	command("say 好！好! 我桃花岛又得一可造之才，我这就给我恩师写信，推荐"
		+RANK_D->query_respect(ob)+"进入桃花岛继续学习。");
	message_vision("陆庄主给$N一封刚写好的信。\n",ob);
 
	ob2=new(__DIR__"obj/letter");
	ob2->set("pl_name",ob->query("id"));
	ob2->set("long","这是一封写有"+ob->query("name")+"的名字，并有他的画像的推荐信。\n");
	ob2->move(ob);

	return 1;
}


int accept_fight(object me)
{
	command("say 好，我们就来较量一番。\n");
	return 1;
}

int accept_kill()
{
	command("emote 冷笑道：凭你就杀得了我？\n");
}

/*
void enter_room()
{
    object *all, ob;
	int i;

      if(IN_BOOKROOM==1) return;

	command("emote 打了个呵欠，说道：睡的真好。该去书房了。");
      ob=this_object();
      ob->move("/d/lu/bookroom");

	command("emote 用拐杖撑着地面，飘进书房。");

    all = all_inventory(environment(ob));
        
    for (i=0; i<sizeof(all); i++) 
      {
	  if( all[i]==this_object() ||!all[i]->is_character()) continue;
        {
	    message_vision(
"$N看到$n愣了一下，叫道：你是怎么进来的？好啊，一个偷书贼！
$N拨了一下桌上放着的古琴的一根琴弦，顿时从墙角射出了一把金针。
你一闪身，虽然逃到了门外，但终于没能躲开金针。
那把金针全打在了你的背上。\n", this_object(),all[i]);

        all[i]->move("/d/lu/hall");

	    all[i]->set("gin", (int)all[i]->query("max_gin")*(random(4)/5)+1);
        all[i]->set("kee", (int)all[i]->query("max_kee")*(random(4)/5)+1);
        all[i]->set("sen", (int)all[i]->query("max_sen")*(random(4)/5)+1);
        }	
     }


      IN_BOOKROOM=1;
}

void leave_room()
{
    object *all, ob;
	int i;

      if( this_object()->is_fighting() )	return ;

	command("say 二更了，我要睡觉去了，你还呆在这里干吗？");
	command("emote 将你赶出书房。");

	all = all_inventory(environment(ob));
        
    for (i=0; i<sizeof(all); i++) 
      {
	  if( all[i]==this_object() ||!all[i]->is_character()) continue;
        {

		all[i]->move(environment()->query("exits/east"));
		}
	  }

      ob=this_object();
      ob->move("/d/lu/bedroom");

	command("emote 用拐杖撑着地面，飘进寝室。");
	command("emote 你们快点出去，我要睡觉了。");
    for (i=0; i<sizeof(all); i++) 
      {
	  if( all[i]==this_object() ||!all[i]->is_character()) continue;
        {

		all[i]->move(environment()->query("exits/south"));
		}

	   }

      IN_BOOKROOM=0;
}
*/