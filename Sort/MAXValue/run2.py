num=[3,30,34,5,9]

def solution(numbers):
  length = list()
  temp = list()
  for num in numbers:
    temp.append(str(num))
  for num in temp:
    length.append(len(num))
  maxlen = max(length)
  temp.sort(key=lambda x: x*(maxlen//len(str(x))+1),reverse=True)
  print(length)
  print(maxlen)
  print(temp)
  return str(int(''.join(temp)))
print(solution(num))
