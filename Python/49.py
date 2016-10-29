import math
import collections
primes = []
primes.append(2)
primes.append(3)
primes.append(5)

def generate_primes(number = 0):
    last_prime = primes[len(primes)-1]
    i = primes[len(primes)-1] + 2
    number += primes[len(primes)-1]
    while primes[len(primes)-1] < number:
        x = 0
        it_isnt = False
        if str(i)[len(str(i))-1] != '5':
            while primes[x] <= math.sqrt(i):
                if i % primes[x] == 0:
                    it_isnt = True
                    break
                x += 1
        else:
            it_isnt = True
        if it_isnt == False:
            primes.append(i)
        i += 1

generate_primes(9999)
new_primes = [nums for nums in primes if len(str(nums)) == 4]

omitted = []
full_list = []
for i in range(len(new_primes)):
    if i > len(new_primes)+1:
        break
    if not (new_primes[i] in omitted):
        count = 0
        current_list = []
        current_string = str(new_primes[i])
        for j in range(i+1, len(new_primes)):
            if collections.Counter(current_string) == collections.Counter(str(new_primes[j])):
                count += 1
                current_list.append(new_primes[j])
                omitted.append(new_primes[j])
        #if current_string[0] in str(new_primes[j]) and current_string[1] in str(new_primes[j]) \
         #   and current_string[2] in str(new_primes[j]) and current_string[3] in str(new_primes[j]):
          #  print str(new_primes[j]) + ",",
        if count >= 2:
            full_list.append([])
            full_list[len(full_list)-1].append(new_primes[i])
            #print current_string + " =",
            for i in range(count):
                #print str(current_list[i]) + ",",
                full_list[len(full_list)-1].append(current_list[i])

for i in range(len(full_list)):
    print full_list[i]

for i in range(len(full_list)):
    for j in range(len(full_list[i])):
        for x in range(j+1, len(full_list[i])):
            difference = full_list[i][x] - full_list[i][j]
            if full_list[i][x]+difference in full_list[i]:
                print full_list[i]