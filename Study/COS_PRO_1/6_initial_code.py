def solution(pos):
  answer = 0
  index = {"A":1, "B":2, "C":3, "D":4, "E":5, "F":6, "G":7, "H":8}
  print(pos)
  pos = [index[pos[0]], int(pos[1])]
  idx = [0, 1]
  for i in range(1, 3):
    if i % 2 == 0:
      idx[0], idx[1] = idx[1], idx[0]
    
    if pos[idx[0]]+2 < 9:
      if pos[idx[1]]-1 > 0:
        answer+=1
      if pos[idx[1]]+1 < 9:
        answer+=1

    if pos[idx[0]]-2 > 0:
      if pos[idx[1]]-1 > 0:
        answer+=1
      if pos[idx[1]]+1 < 9:
        answer+=1

  return answer

pos = "A7"
ret = solution(pos)

print( ret )
