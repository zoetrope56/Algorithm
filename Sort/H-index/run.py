#input = [350,452,877]
input = [8,7,7,6,5,5,3,0,0,0]

def solution(citations):
  citations.sort()
  l = len(citations)
  for i, c in enumerate(citations):
	level = l-i
	if c >= level:
	  return level
  return level

print(solution(input))
