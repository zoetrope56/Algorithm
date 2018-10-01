n = 5
lost = [2,4]
reserve = [1,3,5]

def solution(n, lost, reserve):
  answer = 0
  student = list()
  for i in range(n):
    student.append(1)
  for r in reserve:
    student[r-1]+=1
  for l in lost:
    student[l-1]-=1
  for i in range(n):
    if i == 0:
      if student[i] == 2:
        if student[i+1] == 0:
          student[i]-=1
          student[i+1]+=1
    elif i < n-1:
      if student[i] == 2:
        if student[i-1] == 0:
          student[i]-=1
          student[i-1]+=1
        elif student[i+1] == 0:
          if student[i] == 2:
            student[i]-=1
            student[i+1]+=1
          else:
            pass
        else:
          pass
    elif i == n-1:
      if student[i] == 2:
        if student[i-1] == 0:
          student[i]-=1
          student[i-1]+=1
    else:
      pass

  for s in student:
    if s > 0:
      answer+=1
  return answer

print(solution(n,lost,reserve))
