inherit ITEM;
void create()
{
  set_name("《四十二章经》", ({"book" }));
        set_weight(100);
        set("unit", "本");
        set("long","蓝绸子镶红边的一部经书,比寻常庙
中的要厚出许多,你有意的话,可以读一读(read).\n");
        set("value", 1000);
        set("skill", ([
                "name":"foxuexinde",         
                "exp_required": 0,                             
                "sen_cost":     20,                            
                "difficulty":   20,     
                "max_skill":    20 
        ]) );
}
void init()
{
        add_action("do_read", "read");
}
int do_read(string arg)
{
        this_player()->start_more(read_file(__DIR__"42book"));
        return 1;
}
