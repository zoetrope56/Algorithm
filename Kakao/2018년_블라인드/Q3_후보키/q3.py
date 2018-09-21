# -*- coding:utf-8 -*-
relation = [
            [200,'ryan','music',2],
            [200,'apeach','math',2],
            [300,'tube','computer',3],
            [200,'con','computer',4],
            [500,'muzi','music',3],
            [600,'apeach','music',2]
            ]	

def solution(relation):
    t_size = 0
    columns = 0
    count_idx = []
    relation = list(zip(*relation))
    t_size = len(relation[0])
    columns = len(relation)
    
    for i in range(columns):
        relation[i] = list(set(relation[i]))
        count_idx.append( [i,len(relation[i])] )
    
    sorted(count_idx, key=lambda x:x[0])

    print(count_idx)
	
    answer = 0
    return answer

print(solution(relation))
