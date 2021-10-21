q = input ('2_10 or 10_2 :')

if q == '2_10' :
    
    n = input ("n:")
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


elif q == '10_2' :

    n = input ("n: ")
    n = int (n)
    r = 0
    s = 0
    i = 0

    while n > 0 :

       r = n % 2
       n = n // 2
       s = s + r * (10 ** i)
       i = i + 1

    print (s)


else :
    print ("false")