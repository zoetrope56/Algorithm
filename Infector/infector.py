import random
import time

human=[]
warning=[]
flag=True
col = input()
row = input()
for i in range(int(row)):
  temp=list()
  for j in range(int(col)):
	temp.append(0)
  human.append(temp)

#inject virus
target = random.randrange(0,col*row)
human[target/col][target%col]=1

# view all humans with 1 infector
print(str(target)+'+1')
strBuf=''
for i in range(int(row)):
  for j in range(int(col)):
	strBuf+=str(human[i][j])+' '
  strBuf+='\n'
print(strBuf)

print('-----------------------------\n')

count = 0
while flag:
  strBuf=''
  for i in range(int(row)):
	for j in range(int(col)):
	  if(i==0):
		if(human[i+1][j]==1):
		  warning.append([i,j])
	  elif(i==row-1):
		if(human[i-1][j]==1):
		  warning.append([i,j])
	  else:
		if(human[i+1][j]==1):
		  warning.append([i,j])
		if(human[i-1][j]==1):
		  warning.append([i,j])

	  if(j==0):
		if(human[i][j+1]==1):
		  warning.append([i,j])
	  elif(j==col-1):
		if(human[i][j-1]==1):
		  warning.append([i,j])
	  else:
		if(human[i][j+1]==1):
		  warning.append([i,j])
		if(human[i][j-1]==1):
		  warning.append([i,j])

  for x in warning:
	x_pos, y_pos = x
	human[x_pos][y_pos] = 1
  
  warning=list()

  for i in range(int(row)):
	for j in range(int(col)):
	  strBuf+=str(human[i][j])+' '
	strBuf+='\n'
  print(strBuf)
  print('\n')
	  
  count+=1
  print('count :',count)
  time.sleep(2)

  for h in human:
	if int(0) in h:
	  flag=True
	  break;
	else:
	  flag=False

