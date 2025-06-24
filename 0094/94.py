import math
sides = 2
sum = 0


while 1:
    one = sides+1
    perimeter = 2*sides+one
    if perimeter > 1000000000:
        break
    semiperimeter = perimeter/2.0
    area = math.sqrt(semiperimeter*(semiperimeter-sides)**2*(semiperimeter-one))
    if area.is_integer():
        print str(sides) + ", " + str(sides) + ", " + str(one) + " = Perimeter " + str(perimeter) + ", Area " + str(area)
        sum += perimeter
    one = sides-1
    perimeter = 2*sides+one
    semiperimeter = perimeter/2.0
    area = math.sqrt(semiperimeter*(semiperimeter-sides)**2*(semiperimeter-one))
    if area.is_integer():
        print str(sides) + ", " + str(sides) + ", " + str(one) + " = Perimeter " + str(perimeter) + ", Area " + str(area)
        sum += perimeter
    sides += 1

print sum