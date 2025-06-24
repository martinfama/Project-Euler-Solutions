
all_of = []

max = 0

for r in range(3, 7):
    i = 1
    numbers = []
    for x in range(1, r):
        numbers.append(x)
    print numbers
    while 1:
        results = ""
        for x in range(len(numbers)):
            results += str(i*numbers[x])
        if len(results) == len(set(results)) and not ('0' in results):
            if max < int(results):
                max = int(results)
        if int(results) > 987654321:
            break
        i += 1

print max
#print all_of