// xianhe.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
void create()
{
         set_name("仙鹤翁", ({ "xianhe weng", "xianhe", "weng" }) );
        set("nickname", "仙极老人");
        set("gender", "男性");
        set("age", 85);
        set("long", "他是嵩山派的长老，是带艺投师的，所以资格很老，连左冷禅都要
敬他三分。仙极老人与世无争，投靠嵩山派到底是为了什么，谁也
不知道。他不愿意收徒也不愿意参与嵩山派的任何活动，于是就在
这里专门看守本门的武功秘芨，倒也自得其乐。\n");

        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("force", 2000);
        set("max_force", 2000);
        set("max_kee",5000);
        set("max_gin",5000);
        set("combat_exp", 900000);
        set("chat_chance_combat", 80);

        set("shen_type", -1);

        set_skill("unarmed", 120);
        set_skill("songyang-zhang",120);
        set_skill("sword", 120);
        set_skill("force", 120);
        set_skill("hanbing-zhenqi",120);
        set_skill("parry", 120);
        set_skill("dodge", 120);
        set_skill("songshan-jianfa", 120);
        set_skill("fuguanglueying", 120);

        map_skill("sword", "songshan-jianfa");
        map_skill("parry", "songshan-jianfa");
        map_skill("dodge", "fuguanglueying");
        map_skill("force","hanbing-zhenqi");
        map_skill("unarmed","songyang-zhang");

        create_family("嵩山派", 12, "长老");
        setup();

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "sword.suiyuan" :),
                (: perform_action, "sword.weizun" :),
                (: exert_function, "powerup" :),
                (: exert_function, "heal" :)
        }) );

carry_object("/obj/weapon/sword")->wield();
carry_object("/obj/cloth")->wear();
}
