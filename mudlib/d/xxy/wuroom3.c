// Room: /d/xxy/wuroom3 
inherit ROOM; 
 
void create() 
{ 
  set ("short", "寝室");
  set ("long", @LONG
地上铺着杏红的地毯,牙床上叠着柔软的被子,床前的棱台上摆着些零食.
一只淡青色花瓶中插了一朵梅花.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"wuroom2",
]));
   set("sleep_room",1);
  setup();
}
