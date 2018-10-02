def solution(n, map_a, map_b):
  secret = list()
  for i in range(n):
    target = bin(map_a[i] | map_b[i])[2:]
    count = n - len(target)
    while count is not 0:
      target='0'+target
      count-=1
    secret.append(target.replace('0',' ').replace('1','#'))
  return secret

print(solution(6, [46,33,33,22,31,50], [27,56,19,14,14,10]))
