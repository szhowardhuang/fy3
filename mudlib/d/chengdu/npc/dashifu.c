// bye enter

inherit NPC;


void create()
{
        set_name("大师傅", ({
                "da shifu",
                "shifu",
        }));
        set("long",
                "这是位胖乎乎的大师傅，是陈麻婆一手调教出来的，他要是发现你的偷看他做豆腐，可是会打人的哦。\n"
        );


        set("gender", "男性");
        set("attitude", "peaceful");
        set("class", "bonze");

        set("age", 44);
        set("shen_type", 1);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("max_kee", 400);
        set("max_gin", 200);
        set("force", 100);
        set("max_force", 100);
        set("force_factor", 10);
        set("combat_exp", 2000);
        set("score", 100);

        set_skill("force", 12);
        set_skill("dodge", 12);
        set_skill("unarmed", 12);
        set_skill("parry", 12);


        setup();

}

