// 

inherit ITEM;

void create()
{
	set_name("《易》",({"yi","shu","book"}));
        set_weight(100);
        set("unit", "本");
        set("long",
		"一本可以提高文化的好书。\n"
             );
	set("value",2000);
        set("skill", ([
		"name":"literate",
		"max_skill":40,
        ]) );
}
 
