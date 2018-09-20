array = [1,5,2,6,3,7,4]
commands = [[2,5,3],[4,4,1],[1,7,3]]

answer=list()
for command in commands:
  temp = list()
  print('command',command)
  for i in range(command[0]-1, command[1]):
	temp.append(array[i])
  print('before',temp)
  temp.sort()
  print('after',temp)
  answer.append(temp[command[2]-1])

print(answer)
	
