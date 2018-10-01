n = 5
lost = [2,4]
reserve = [1,3,5]

def solution(n, lost, reserve):
  rsv = [r for r in reserve if r not in lost]
  los = [l for l in lost if l not in reserve]
  for r in rsv:
    f = r - 1
    b = r + 1
    if f in los:
      los.remove(f)
    elif b in los:
      los.remove(b)
  return n - len(los)

print(solution(n,lost,reserve))
