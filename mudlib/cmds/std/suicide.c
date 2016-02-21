// suicide.c
#define SAVE_EXTENSION ".o"
#include <ansi.h>

inherit F_CLEAN_UP;
int main(object me, string arg)
{
	if( me->is_busy() )
		return notify_fail("����һ��������û��ɡ�\n");

	if( !arg ) {
		write("You commit suicide.\n");
		return 1;
	}

	if( arg!="-f" ) 
		return notify_fail("��ɱ�����֣�����Ҫ��Զ������������Ͷ̥��\n");

	write(
		"�����ѡ����Զ��������ɱ��ʽ�������������Ͼ���Զɾ���ˣ������\n"
		"���������ȷ���Ļ��������������룺");
	input_to("check_password", 1, me, 1);
	return 1;
}

private void check_password(string passwd, object me, int forever)
{
	object link_ob;
	string old_pass;

	link_ob = me->query_temp("link_ob");
	old_pass = link_ob->query("password");
	if( crypt(passwd, old_pass)!=old_pass ) {
		write("�������\n");
		return;
	}

	if (forever) {
		tell_object( me,
			HIR "\n\n�����Ҫ��ɱ�ˣ����ʮ���ڲ��˳�������������ˡ�\n\n\n" NOR);
		me->set_temp("suicide_countdown", 10);
		me->start_busy( (: call_other,this_object(), "slow_suicide" :));
	}
}

private int slow_suicide(object me)
{
	string banghui;
	object lingpai;
	object link_ob;
	int stage;

	stage = me->query_temp("suicide_countdown");
	me->add_temp("suicide_countdown", -1);
	if( stage > 1 ) {
		if( stage%5 == 0 )
			tell_object(me, HIR "�㻹�� " + stage + " ���ʱ�������ڡ�\n" NOR);
		return 1;
	}

	link_ob = me->query_temp("link_ob");
	if( !link_ob ) return 0;

	log_file("static/SUICIDE",
		sprintf("%s commits a suicide on %s\n", geteuid(me), ctime(time())) );

        if((string)(banghui=me->query("banghui")))
        {
                lingpai=new("/obj/lingpai");
                lingpai->create(banghui);
                if(! lingpai->query("no_use"))
                        "/cmds/usr/tuoli.c"->yes_or_no("yes",me,banghui);
                destruct(lingpai);
        }
	seteuid(getuid());
	rm( link_ob->query_save_file() + SAVE_EXTENSION );
	rm( me->query_save_file() + SAVE_EXTENSION );
		write("�ðɣ�������:)��\n");
	tell_room(environment(me), me->name() +
		"��ɱ�ˣ���������Ҳ������������ˡ�\n", ({me}));
	destruct(me);
	return 0;
}

int help (object me)
{
        write(@HELP
ָ���ʽ: suicide [-f]
 
�����Ϊĳ��ԭ���㲻�����, �����ѡ����ɱ.
��ɱ������:
 
suicide    : ����Ͷ̥
suicide -f : ��Զ�ĳ�ȥ�������, ϵͳ��Ҫ����
             ����������ȷ������.
 
������ѡ�� :)
 
HELP
);
        return 1;
}