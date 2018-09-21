result=[]
users=[
       [1,2,3,4,5],
	   [2,1,2,3,2,4,2,5],
	   [2,3,5,1,2,2,4,4,5,5]
      ]
count=dict()
for i in range(len(users)):
  count[i]=0

answer=[1,2,3,4,5]

l = len(answer)
user_count=0
for user in users:
  for i in range(l):
    if(user[i%len(user)]==answer[i]):
      count[user_count]+=1
  user_count+=1

count= sorted(count.items(), key=lambda value: value[1], reverse=True)
for c in count:
  if(c[1] != 0):
	result.append(c[0]+1)
print(result)
