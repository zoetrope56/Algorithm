def solution(brown, red):
  mylist = []
  if red > 4:
    r=red//4
  else:
    pass
  for i in range(1,r+1):
    if (red) % i == 0:
      temp = [i, red/i]
      if ((temp[0]+2)*2 + (temp[1])*2) == brown:
        temp.sort(reverse=True)
        temp[0]+=2
        temp[1]+=2
  return temp

print(solution(24,24))
