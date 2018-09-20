genres = ['classic','pop','pop','classic','classic','pop']
plays = [500, 600, 2500,400, 800, 600]
# return [4,1,3,0]

def solution(genres, plays):
  answer = list()
  dic = dict()
  
  for i, (g, p) in enumerate(zip(genres, plays)):
	print i, (g, p)
	try:
	  dic[g] == None
	except KeyError:
	  dic[g]=list()
	dic[g].append([i,p])

  for (x,y) in sorted(dic.items(), key=lambda x:x[1], reverse=True):
	y.sort(key=lambda t: t[1], reverse=True)
	for i in y[:2]:
	  answer.append(i[0])
  
  return answer

print(solution(genres, plays))
