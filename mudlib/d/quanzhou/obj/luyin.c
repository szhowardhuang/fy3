inherit ITEM;

void create()
{
  set_name("·��", ({ "luyin"}));
  set("unit", "��");
  set_weight(300);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("material", "paper");
  }
  setup();
}

