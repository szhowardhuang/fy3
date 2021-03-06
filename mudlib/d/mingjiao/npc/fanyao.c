// FanYao.c
// pal 1997.05.09

#include "ansi.h"

inherit NPC;

void create()
{
    set_name("范遥", ({"fan yao","fan","yao",}));
	set("long",
        "他是一位带发修行的头陀，身穿白布长袍。\n"
        "他的脸上七七八八的全是伤疤，简直看不出本来面目了。\n"
	);

	set("banghui","明教");
	set("bh_rank","光明右使");
	set("level",11);
	set("gender", "男性");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("age", 38);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_kee", 3500);
	set("max_gin", 1500);
	set("force", 3000);
	set("max_force", 3000);
        set("force_factor", 90);
         set("combat_exp",600000);
        set("score",20000);

	set_skill("force",200);
	set_skill("sanyang-shengong",200);
	set_skill("dodge",200);
	set_skill("unarmed",200);
	set_skill("parry",200);
	set_skill("fengyun-shou",200);
	set_skill("tianlong-bu",200);
	set_skill("literate",110);

        map_skill("force","sanyang-shengong");
	map_skill("unarmed", "fengyun-shou");
         map_skill("dodge","tianlong-bu");
        map_skill("parry","fengyun-shou");

	set("inquiry", ([
//        "光明圣火阵"     : (: ask_me :)
	]));

	setup();

        carry_object("/d/mingjiao/obj/baipao")->wear();
}

int recognize_apprentice(object ob)
{
        string banghui;
        if(! stringp(banghui=ob->query("banghui")) ||
                banghui!=query("banghui"))
        return notify_fail(query("name")+"摇头道：你我非亲非故，"+
                RANK_D->query_self(this_object())+"如何敢当。\n");
	if(ob->query("score")<2500)
                return notify_fail(query("name")+"道：你还是多为本教做些实事吧。
\n");
        return 1;
}

