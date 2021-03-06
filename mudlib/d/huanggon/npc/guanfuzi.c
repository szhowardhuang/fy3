// guanfuzi.c 关安基 

#include <ansi.h>
inherit NPC;
void create()
{
	set_name("关安基", ({ "guan anji", "guan" }));
	set("banghui", "天地会");
	set("nickname", "关夫子");
	set("shen_type", 1);

	set("gender", "男性");
	set("age", 35);
	set("long",
		"\n只见他长长的胡子飘在胸前，模样甚是威严。因此人称关夫子。\n");

	set_skill("unarmed", 70);
	set_skill("poyu-quan",70);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set_skill("sword", 80);
	set_skill("force", 70);
	set_skill("zixia-shengong", 70);
	set_skill("huashan-jianfa", 70);
	set_skill("feiyan-huixiang",60);
	map_skill("dodge", "feiyan-huixiang");
	map_skill("parry", "huashan-jianfa");
	map_skill("sword", "huashan-jianfa");
	map_skill("force", "zixia-shengong");
	map_skill("unarmed","poyu-quan");

	set_temp("apply/attack", 35);
	set_temp("apply/defense", 35);
	set_temp("apply/damage", 25);

	set("combat_exp", 50000);
	set("max_kee",800);
	set("max_force",1000);
	set("force",1000);
	set("force_factor",80);
	set("attitude", "friendly");
	set("chat_chance", 1);
	set("chat_msg", ({
	"关安基忽然说：本堂的香主谁来当，还轮不到我说话。\n",
	"关安基忽然说：唉，我的脾气不大好，大家可要小心了。\n",
	}));
        set("inquiry", ([
		"陈近南" :  "总舵主在城西的山庄中商量大事。\n",
		"天地会" :  "要入我天地会，得去找贾老六。\n",
                "贾老六" : "这小子常去天桥一带！\n",
          
       ]) );

	setup();
	carry_object("/obj/cloth")->wear();
	carry_object("/obj/weapon/sword")->wield();
}

int recognize_apprentice(object ob)
{
        string banghui;
        if(! stringp(banghui=ob->query("banghui")) ||
                banghui!=query("banghui"))
        return notify_fail(query("name")+"摇头道：非我天地会兄弟不教。\n");
        if(ob->query("score")<50)
                return notify_fail(query("name")+"道：你要多为天地会出力啊。\n");
        return 1;
}
