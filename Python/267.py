import random
value = 1.0
f = 0.0

for f in range(0, 100000):
    f /= .01
    value = 1.0
    for i in range(1000):
        bet = value*f
        if random.randint(0, 1) == 0:
            value += bet
        else:
            value -= bet
    print str(f) + " = " + str(value)
    f = int(f)