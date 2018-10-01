arr = [1,1,3,3,0,1,1]
def solution(origin):
  count = 0
  modify = [-1]
  for item in origin:
    if item == modify[count]:
      pass
    else:
      modify.append(item)
      count+=1
  del(modify[0])
  return modify
print(solution(arr))

