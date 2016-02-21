inherit ITEM;
inherit F_LIQUID;

void create()
{
set_name("白瓷酒坛",({"jiutan","jiu","tan"}));
  set_weight(8000);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
     set("long", "一个用来装酒的小酒坛。\n");
     set("unit", "个");
     set("value", 2000);
     set("max_liquid", 150);
  }

  set("liquid", ([
        "type": "alcohol",
        "name": "曲酒",
        "remaining": 150,
        "drunk_supply": 12,
      ]));
}

