progresses=[93,30,55]
speeds=[1,30,5]
queue=[]
for i in range(len(progresses)):
  days=0
  works=progresses[i]
  while(works<100):
	works+=speeds[i]
	days+=1
  queue.append(days)
days=0
cnt=1
for q in queue:
  if(days==0):
	temp=q
  else:
	if temp<q

  days+=1

print(answer)
