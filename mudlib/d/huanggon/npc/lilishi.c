// lilishi.c 李力世

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("李力世", ({ "li lishi", "li" }));
	set("banghui", "天地会");
	set("gender", "男性");
	set("age", 45);
	set("str", 25);
	set("dex", 20);
	set("long", "这是一个身材矮小，满连胡须的中年人，身上的\n"+
"衣服又脏又破，脸上满是皱纹，看上去饱经风霜。\n");
	set("combat_exp", 35000);
	set("score", 5000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set_skill("unarmed", 50);
	set_skill("yunlong-shou",50);
	set_skill("force", 60);
	set_skill("yunlong-xinfa",50);
	set_skill("blade", 90);
	set_skill("dodge", 70);
	set_skill("parry", 50);
	set_skill("wuhu-duanmendao", 90);
	set_skill("yunlong-shenfa", 60);
	map_skill("blade", "wuhu-duanmendao");
	map_skill("dodge", "yunlong-shenfa");
	map_skill("force","yunlong-xinfa");
	map_skill("parry","wuhu-duanmendao");

	set("max_force", 600);
	set("force",600);
	set("force_factor", 50);
	set("max_kee",800);
	set("chat_chance", 2);
	set("chat_msg", ({
        "李力世突然说：初进洪门结义兄，对天明誓表真心。\n",
	}));
        set("inquiry", ([
		"陈近南" :  "想见总舵主可不容易啊。\n",
		"天地会" :  "要入天地会，得去找贾老六。\n",
       ]) );
	setup();
	carry_object("/obj/weapon/blade")->wield();
	carry_object("/obj/cloth")->wear();
	add_money("silver", 20);
}


int recognize_apprentice(object ob)
{
        string banghui;
        if(! stringp(banghui=ob->query("banghui")) ||
                banghui!=query("banghui"))
        return notify_fail(query("name")+"摇头道：非我天地会兄弟不教。\n");
	if(ob->query("score")<1000)
                return notify_fail(query("name")+"道：你要多为天地会出力啊。\n");
        return 1;
}

