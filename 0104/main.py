import math

def last_n_digits(n, d):
    return n % (10 ** d)
def first_n_digits(n, d):
    digits = int(math.log10(n)) + 1
    return n // (10 ** (digits - d))

def p(s):
    if len(set(s)) != 9 or '0' in s:
        return False
    return True

f = [1,1]
i = 2
while len(str(f[-1])) < 18:
    f.append(f[-1] + f[-2])
    i += 1
    
for i in range(i, 1000000):
    f.append(f[-1] + f[-2])
    sl = str(last_n_digits(f[-1], 9))
    if p(sl):
        sf = str(first_n_digits(f[-1], 9))
        if p(sf):
            print(i + 1)
            break