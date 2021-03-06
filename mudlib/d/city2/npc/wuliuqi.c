// wuliuqi.c
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("吴六奇", ({"wu liuqi", "wu","liuqi"}));
	set("banghui", "天地会");
	set("bh_rank","洪顺堂香主");
	set("nickname", "铁丐");
	set("gender", "男性");
	set("age", 50);
	set("long", 
		"这个老叫化，便是天下闻名的“铁丐”吴六奇，向来嫉恶如仇。\n"
		"他在官居广东提督之时，手握一省重兵，受了查伊璜的劝导，\n"
		"心存反清复明之志，暗入天地会，任职洪顺堂香主。\n"
	);

	set("attitude", "peaceful");
	
	set("str", 24);
	set("int", 20);
	set("con", 24);
	set("dex", 20);

	set("kee", 1500);
	set("max_kee", 1500);
	set("gin", 100);
	set("max_gin", 100);
	set("force", 1500);
	set("max_force", 1500);
	set("force_factor", 100);
	
	set("combat_exp", 500000);
	set("score", 30000);
	
	set_skill("force", 90);			// 基本内功
	set_skill("huntian-qigong", 90);	// 混天气功
	set_skill("unarmed", 90);		// 基本拳脚
	set_skill("xianglong-zhang", 80);	// 降龙十八掌
	set_skill("dodge", 90);			// 基本躲闪
	set_skill("xiaoyaoyou", 95);		// 逍遥游
	set_skill("parry", 85);			// 基本招架
	set_skill("begging", 50);		// 叫化绝活
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "xianglong-zhang");
	set("chat_chance", 3);
	set("chat_msg", ({
	"吴六奇忽然放开喉咙唱起曲来：“走江边，满腔愤恨向谁言？。。。。\n"
	"。。。。。。寒涛东卷，万事付空烟。精魂显大招，声逐海天远。\n",
	"吴六奇说: 江湖威望很重要，威望高大有好处啊。\n",
        "吴六奇突然说道: 松柏二枝分左右，中节洪华结义亭。\n",
        "吴六奇突然说道: 福德祠前来誓愿，反清复明我洪英。\n",
	}));
        set("inquiry", ([
		"陈近南" :  "\n想见总舵主可不容易啊。\n",
		"天地会" :  "\n要入我天地会，去找贾老六问问看吧。\n",
              "反清复明" : "去药铺和棺材店仔细瞧瞧吧！\n",

	]) );

	setup();
	carry_object("/obj/cloth")->wear();
}

int recognize_apprentice(object ob)
{
        string banghui;
        if(! stringp(banghui=ob->query("banghui")) ||
                banghui!=query("banghui"))
        return notify_fail(query("name")+"摇头道：非我天地会兄弟不教。\n");
        if(ob->query("score")<2000)
                return notify_fail(query("name")+"道：你要多为天地会出力啊。\n");
        return 1;
}

