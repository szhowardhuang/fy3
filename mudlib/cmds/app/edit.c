// edit.c

#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string file)
{
	if( !file ) file = me->query("cwf");
        if (!file) return notify_fail("ָ���ʽ��edit <����>\n");

	if( in_edit(me) ) return notify_fail("���Ѿ���ʹ�ñ༭���ˡ�\n");

	seteuid(geteuid(me));
          log_file( "wiz/edit/"+me->query("id")+".log", sprintf("(%s)
        %s edit %s\n", ctime(time()), me->query("name"), (resolve_path(me->query("cwd"), file))));

	ed(resolve_path(me->query("cwd"), file));
	return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : edit <����>, edit here

���ô�һָ���ֱ�������ϱ༭������
HELP
    );
    return 1;
}