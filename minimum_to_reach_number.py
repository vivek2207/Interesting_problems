"""

If you start with $1 and, with each move, you can either double your money or add another $1, what is the smallest number of moves you have to make to get to exactly $200?
"""

a=int(input('Enter the number : '))

count=0

while a!=1:
    if a%2==0:
        a=a//2
        count+=1
    else:
        a=a-1
        count+=1

print(count)
