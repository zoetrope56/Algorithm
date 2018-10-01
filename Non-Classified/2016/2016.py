
def solution(a, b):
    weekday = ['MON','TUE','WED','THU','FRI','SAT','SUN']
    from datetime import datetime
    index = datetime(2016, a, b).weekday()
    return weekday[index

def protoType(a,b):
  months=[31,29,31,30,31,30,31,31,30,31,30,31]
  days=['FRI','SAT','SUN','MON','TUE','WED','THU']
  return days[(sum(months[:a-1])+b-1)%7]
print(protoType(5,24))
