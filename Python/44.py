import math
prev_diff = 0
first = True
how = 10000
for i in range(1, how):
    one = i*(3*i-1)/2
    for x in range(i-1, 0, -1):
        two = x*(3*x-1)/2
        difference = abs(two-one)
        sum = two+one
        if ((.5+math.sqrt(.25+6*difference))/3.0).is_integer() and ((.5+math.sqrt(.25+6*sum))/3.0).is_integer():
            if first == True:
                prev_diff = difference
                print prev_diff
                first = False
            elif prev_diff > difference:
                prev_diff = difference
                print prev_diff

