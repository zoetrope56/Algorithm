#-*- coding:utf-8 -*-

record = ['Enter uid1234 Muzi', 'Enter uid4567 Prodo','Leave uid1234','Enter uid1234 Prodo','Change uid4567 Ryan']
"""

answer = ['Prodo님이 들어왔습니다.', 'Ryan님이 들어왔습니다.', 'Prodo님이 나갔습니다.', 'Prodo님이 들어왔습니다.']
"""

action_eng = ['Enter', 'Leave']
action_kor = ['님이 들어왔습니다.', '님이 나갔습니다.']
user = dict()

def solution(record):
    answer = []
    count = 0
    record = list(r.split(' ') for r in record)
    
    for r in record:
        if len(r) == 3:
            user[r[1]] = r[2]

    for r in record:
        if r[0] == action_eng[0]:
            answer.append(user[r[1]]+action_kor[0])
        elif r[0] == action_eng[1]:
            answer.append(user[r[1]]+action_kor[1])
        else:
            pass

    """
    print ('action_eng', action_eng)
    print ('action_kor', action_kor)
    print ('record', record)
    print ('user', user)
    """

    return answer

print (solution(record))

