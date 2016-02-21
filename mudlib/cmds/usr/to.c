// to.c

// inherit F_CLEAN_UP;
// Don't want this command be cleaned up while typing long string.

int main(object me, string arg)
{
	me->edit( (: call_other,this_object(),({"do_to",me,arg}) :) );
	return 1;
}

void do_to(object me, string arg, string str)
{
	seteuid(getuid());
	if(arg) me->force_me(arg + " " + str);
	else me->force_me(str);
}

int help(object me)
{
write(@HELP
指令格式 : to <指令>

可以一次输出多行以上的文字, <指令>通常是输出讯息的指令如
say , tell , describe , chat , reple ........等。
范例 : 
 to say
 结束离开用 '.'，取消输入用 '~q'，使用内建列编辑器用 '~e'。
 —————————————————————————————
结束离开用
取消输入用
使用内建列编辑器用
 .

输出到萤幕上的结果则是 :

你说道：结束离开用
取消输入用
使用内建列编辑器用
HELP
    );
    return 1;
}

