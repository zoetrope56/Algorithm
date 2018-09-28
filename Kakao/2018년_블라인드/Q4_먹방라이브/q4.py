#remains = [3,1,2]
remains = [5,2,7,5,8,3,1]
shutdown = 10

def solution(food_times, k):
  count = 0
  idx = 0
  flag = 0
  while count < k:
    idx = count % len(food_times)
    print(idx)
    if remains[idx] == 0:
      while flag < len(food_times)+1:
        count+=1
        flag+=1
        idx = count % len(food_times)
        if remains[idx] == 0:
          continue
        else:
          remains[idx]-=1
          flag = 0
          break;
        if flag == len(food_times):
          return -1
    else:
      remains[idx]-=1
      count+=1
      flag=0
    if flag == len(food_times):
      return -1
    print(count,'<', k, ':', food_times)

  return (count+2)%len(food_times)

print (solution(remains, shutdown))
