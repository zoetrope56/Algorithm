# -*- coding:utf-8 -*-
fail_rate = dict()

def solution(N, stages):
    answer=[]
    users = len(stages)

    for i in range(1,N+2):
        fail_rate[i]=[]

    for s in stages:
        fail_rate[s].append(1)
        
    print(fail_rate)    

    for i in range(1,N+2):
        temp = len(fail_rate[i])
        print(temp)
        print(float(users))
        if(temp == 0):
            fail_rate[i]=0
        else:
            fail_rate[i] = temp/float(users)
        users -= temp
    
    del(fail_rate[N+1])
    for stage_number in sorted(fail_rate, key=fail_rate.get, reverse=True):
        answer.append(stage_number)

    return answer

print( solution(7, [1,3,4,4,2,6,5,8,5,4,4,2] ) )
