
#import math

def solution(num):
    numset = ['1','2','3','4','5','6','7','8','9']
    num += 1
    answer=''
    for i in range(len(str(num))):
      if str(num)[i] not in numset:
        answer+='1'
      else:
        answer+=str(num)[i]
    return answer


num = 9949999;
ret = solution(num)

print(ret)
