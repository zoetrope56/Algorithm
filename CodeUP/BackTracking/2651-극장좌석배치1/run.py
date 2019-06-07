from math import factorial

empty, users = map(int, input('빈자리, 관객수: ').split())

print(
    factorial(empty) // ( factorial(users) * factorial(empty-users) )
)
