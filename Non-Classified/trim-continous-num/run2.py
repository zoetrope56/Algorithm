def solution(s):
  return [v for i, v in enumerate(s) if i==0 or s[i-1] != s[i]]

print(solution([1,1,3,3,0,1,1]))

