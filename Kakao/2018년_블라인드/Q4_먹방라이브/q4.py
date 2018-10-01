remains = [3,1,2]
shutdown = 5 

def solution(food_times, k):
  index = 0
  count = 0
  fail_count = 0
  len_food = len(food_times)
  while count < k:
    while food_times[index%len_food] == 0:
      index+=1
      fail_count+=1
      if fail_count == len_food:
        return -1
    food_times[index%len_food]-=1
    index+=1
    count+=1
    print('index',index,'count',count,'food_times',food_times)
  return (index%len_food)+1
print (solution(remains, shutdown))
