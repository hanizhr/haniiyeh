n = input ("n")
n = int (n)

s = 0
r = 0
i = 0

while n > 0 :

   r = n % 10
   n = n // 10
   s = s + (r*(2 ** i))
   i = i + 1

print (s)
