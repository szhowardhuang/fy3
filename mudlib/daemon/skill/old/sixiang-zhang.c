inherit SKILL;
#include <ansi.h>
mapping *action = ({
([      "action" : "$N��$nңңһ�ϣ�һʽ��������̩����˫�ƴ󿪴��أ�����$n�Ľ�����",
        "force" : 130,
        "parry" : 2,
        "dodge" : 5,
        "damage_type" : "����",
        "lvl" : 0,
        "skill_name" : "������̩"
]),
([      "action" : "������$N�溬΢Ц��һʽ���������项��˫���Ʋ����ƣ�ͬʱ����$nȫ��������",
        "force" : 190,
        "dodge" : 5,
        "parry" : 5,
        "damage_type" : "����",
        "lvl" : 12,
        "skill_name" : "��������"
]),
([      "action" : "$N����������һʽ��������ɳ����˫����£���У�����$n����磡",
        "force" : 250,
"dodge" : 5,
        "parry" : -5,
        "damage_type" : "����",
        "lvl" : 18,
        "skill_name" : "������ɳ"
]),
([      "action" : "$Nһʽ���׶���������˫����Ѹ�ײ����ڶ�֮�ƣ�����$n������̫��Ѩ��",
        "force" : 320,
        "dodge" : 5,
        "parry" : 10,
        "damage_type" : "����",
        "lvl" : 36,
        "skill_name" : "�׶�����"
]),
([      "action" : "$Nʹһʽ��ժ�ǻ�����������������˫�����֣�һ������$n�ĺ���ȥ",
        "force" : 390,
        "dodge" : 10,
        "parry" : 15,
        "damage_type" : "����",
        "lvl" : 48,
        "skill_name" : "ժ�ǻ���"
]),
([      "action" : "$Nһʽ�����Ľ�ħ����˫�����÷��ã��ƶ��Ƕ��������缱����ʹ$n�������У�",
"force" : 470,
        "dodge" : 5,
        "parry" : 10,
        "damage_type" : "����",
        "lvl" : 54,
        "skill_name" : "���Ľ�ħ"
]),
});

int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�������Ʊ�����֡�\n");
        if ((int)me->query_skill("emei-xinfa", 1) < 20)
                return notify_fail("��Ķ�ü�ķ���򲻹����޷�ѧϰ�����ơ�\n");
        if ((int)me->query("max_force") < 150)
                return notify_fail("�������̫�����޷��������ơ�\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me)
{
        int i, level, force, ljz, sxz, unarmed;
        force = me->query("force");
        sxz = me->query_skill("sixiang-zhang", 1);
        ljz = me->query_skill("emei-xinfa", 1);
        unarmed = me->query_skill("unarmed", 1);
        if (ljz > 79 && sxz > 79 && unarmed > 79 && force > 500 
            && random(me->query_int()) > 24 ){
                me->add("force", -60);
                if(random(10) < 2 )
                return ([
                "action":HIY
    "��ʱ��,�����羲���ƺ�ƽ�̣������Լ��������$N����б���������γɲ�ɫ�⻷��
$N�����Լ�����Ӱ�����س�������ɫ�����ϡ�"HIC"���⻷���˶�����Ӱ�ڻ��С�"HIY",ʹ����
"HIW"�����ƾ�ѧ"HIY"���𶥷�⡻"NOR,
"weapon" : HIY"�𶥷��"NOR,
                "force": 550,
                "damage" : 120,
                "dodge": 15,
                "parry": 15,
                "damage_type": "����"]);
          }

        level   = (int) me->query_skill("sixiang-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
        return action[random(sizeof(action))];

}

int practice_skill(object me)
{
        if ((int)me->query("gin") < 30)
                return notify_fail("��ľ���̫���ˡ�\n");
        if ((int)me->query("kee") < 20)
                return notify_fail("������������������ơ�\n");
        me->receive_damage("gin", 15+random(10));
        me->add("force", -5+random(5));
        return 1;
}
