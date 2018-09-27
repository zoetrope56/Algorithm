# -*- coding:utf-8 -*-
relation = [
            [100,'ryan','music',2],
            [200,'apeach','math',2],
            [300,'tube','computer',3],
            [400,'con','computer',4],
            [500,'muzi','music',3],
            [600,'apeach','music',2]
           ]	

"""
def get_keys(dict_table, target):
  count = 0
  list_result = list()
  len_temp = len(mydict[0])
  for i in range(len_temp):
    list_temp = []
    for t in target:
      list_temp.append(dict_table[t[0]][t[1]])
    list_result.append(list_temp)
    count+=1
  print(list_result)
"""

answer = 0
relation = list(zip(*relation))
mydict = dict()
for i, r in enumerate(relation):
  mydict[i] = r

from itertools import combinations
list_combine = list()
for i in range(len(mydict)):
  list_combine.append(i)

list_combined = list()
for i in range(1,len(list_combine)+1):
  list_combined.append(list(combinations(list_combine, i)))


selected = []
for item in list_combined:
  for element in item:
    list_temp = []
    index_temp = []
    flag = True
    for i in element:
      index_temp.append(i) 
      print('selected', selected,'index_temp', index_temp, 'i', i)
      if index_temp in selected or i in selected:
        flag=False
        continue
      t=[]
      for j in range(len(mydict[i])):
        t.append(mydict[i][j])
      list_temp.append(t)
    if len(list_temp) == 1:
      if len(list(set(list_temp[0]))) == len(list_temp[0]):
        selected.append(i)
    else:
      list_temp = list(zip(*list_temp))
      if len(list(set(list_temp))) == len(list_temp):
        selected.append(index_temp)
    print(list_temp)
  
    print('---')

print(selected)
#  print(get_keys(mydict, 0,1))
