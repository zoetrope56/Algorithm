# -*- coding:utf-8 -*-
from collections import OrderedDict
relation = [
            [100,'ryan','music',2],
            [200,'apeach','math',2],
            [300,'tube','computer',3],
            [400,'con','computer',4],
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
        count_idx.append(len(relation[i]))
    
    print(count_idx)

    answer = 0
    return answer

print(solution(relation))