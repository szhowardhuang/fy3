// 

inherit ITEM;

void create()
{
	set_name("《剑术指南上卷》",({"jianshushang","shang"}));
        set_weight(100);
        set("unit", "本");
        set("long",
	"一本记载剑法招式的武学书籍。\n"
             );
	set("value",1000);
        set("skill", ([
	"name":"sword",
        "exp_required":100,
        "max_skill":20,
        "sen_cost":10,
        ]) );
}
 
