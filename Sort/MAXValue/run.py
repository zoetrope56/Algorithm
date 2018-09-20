answer=''
order=[]
numbers=[30,3,34,5,9]
numbers.sort(reverse=True)
for n in numbers:
  if len(str(n))>1:
	div = len(str(n))-1
	n = float(float(n)/(10**div))
  order.append(n)
print(order)
order.sort()
while(len(order)):
  answer+=str(order.pop()).replace('.','')
print(answer)
