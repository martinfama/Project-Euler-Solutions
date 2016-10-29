def factorial(n):
    if n < 2:
        return 1
    else:
        return factorial(n-1)*n

def combi(n, r):
    return factorial(n)/factorial(r)/factorial(n-r)

count = 0

for n in range(101):
    for r in range(n+1):
        print combi(n, r),
        if combi(n, r) > 1000000:
            count += 1
    print

print count