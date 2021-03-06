// zhu.c 朱熹
// CLEANSWORD 1996/2/2

inherit NPC;

void create()
{
        set_name("杜甫", ({ "du fu", "du" }));
        set("long", "杜甫是一代大诗人，不过终生郁郁，不得其志。\n");
        set("gender", "男性");
        set("age", 65);

        set_skill("literate", 300);

        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_temp("apply/attack", 80);
        set_temp("apply/defense", 80);
        set_temp("apply/damage", 20);

        set("combat_exp", 400000);
        set("shen_type", 1);
        setup();

        set("chat_chance", 3);
        set("chat_msg", ({
                "杜甫叹了口气，说道：这风又开始吹起来了。\n",
                "杜甫低声道：安得广厦千万间.......\n",
        }) );
carry_object("/obj/cloth")->wear();
}

int recognize_apprentice(object ob)
{
        if (!(int)ob->query_temp("mark/杜"))
                return 0; 
        ob->add_temp("mark/杜", -1);
        return 1;
}

int accept_object(object who, object ob)
{
        if (!(int)who->query_temp("mark/杜"))
                who->set_temp("mark/杜", 0);
        if (ob->query("money_id") && ob->value() >= 5000) {
                message_vision("杜甫同意指点$N一些问题。\n", who);
                who->add_temp("mark/杜", ob->value() / 250);
                return 1;
        }
        return 0;
}

