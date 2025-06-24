from progressbar import ProgressBar
count = 0
avoid_1 = [1]
avoid_89 = [89]
bar = ProgressBar(maxval=9999999)
bar.start()
for i in range(1, 10000000):
    bar.update(i)
    number = i
    prev = 0
    while 1:
        digits = []
        for x in range(len(str(number))):
            digits.append(int(str(number)[x]))
        number = 0
        for x in range(len(digits)):
            number += digits[x]**2
        if number in avoid_89:
            if prev != 0:
                avoid_89.append(prev)
            count += 1
            break
        if number in avoid_1:
            if prev != 0:
                avoid_1.append(prev)
            break
        prev = number

bar.finish()
print count