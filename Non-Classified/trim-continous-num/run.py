arr = [1,1,3,3,0,1,1]
def solution(arr):
  temp = ''
  count = 0
  for a in arr:
    if temp == a:
      arr[count]=-1
    else:
      temp = a
    count+=1
  while -1 in arr:
    arr.remove(-1)
  return arr

print(solution(arr))

