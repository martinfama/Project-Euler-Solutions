import time
start_time = time.time()
row = [0]*15

row[0] = 75
row[1] = 95, 64
row[2] = 17, 47, 82
row[3] = 18, 35, 87, 10
row[4] = 20, 4, 82, 47, 65
row[5] = 19, 1, 23, 75, 3, 34
row[6] = 88, 2, 77, 73, 7, 63, 67
row[7] = 99, 65, 4, 28, 6, 16, 70, 92
row[8] = 41, 41, 26, 56, 83, 40, 80, 70, 33
row[9] = 41, 48, 72, 33, 47, 32, 37, 16, 94, 29
row[10] = 53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14
row[11] = 70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57
row[12] = 91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48
row[13] = 63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31
row[14] = 4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23

sum = 0

for one in range(1):
    for two in range(one, one+2):
        for three in range(two, two+2):
            for four in range(three, three+2):
                for five in range(four, four+2):
                    for six in range(five, five+2):
                        for seven in range(six, six+2):
                            for eight in range(seven, seven+2):
                                for nine in range(eight, eight+2):
                                    for ten in range(nine, nine+2):
                                        for eleven in range(ten, ten+2):
                                            for twelve in range(eleven, eleven+2):
                                                for thirteen in range(twelve, twelve+2):
                                                    for fourteen in range(thirteen, thirteen+2):
                                                        for fifteen in range(fourteen, fourteen+2):
                                                            total = row[0] + row[1][two] + row[2][three] + row[3][four] + row[4][five] + row[5][six] + row[6][seven] + row[7][eight] + row[8][nine] + row[9][ten] + row[10][eleven] + row[11][twelve] + row[12][thirteen] + row[13][fourteen] + row[14][fifteen]
                                                            if total > sum:
                                                                sum = total

print sum

print time.time()- start_time