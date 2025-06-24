total = 1 #2 pounds is included

for pound in range(3):
    for fifty_pence in range(5):
        if pound*100 + fifty_pence*50 > 200:
            break
        for twenty_pence in range(11):
            if pound*100 + fifty_pence*50 + twenty_pence*20 > 200:
                break
            for ten_pence in range(21):
                if pound*100 + fifty_pence*50 + twenty_pence*20 + ten_pence*10 > 200:
                    break
                for five_pence in range(41):
                    if pound*100 + fifty_pence*50 + twenty_pence*20 + ten_pence*10 + five_pence*5 > 200:
                        break
                    for two_pence in range(101):
                        if pound*100 + fifty_pence*50 + twenty_pence*20 + ten_pence*10 + five_pence*5 + two_pence*2 > 200:
                            break
                        for one_pence in range(201):
                            if pound*100 + fifty_pence*50 + twenty_pence*20 + ten_pence*10 + five_pence*5 + two_pence*2 + one_pence == 200:
                                total += 1
                                one_pence = 202
                            elif pound*100 + fifty_pence*50 + twenty_pence*20 + ten_pence*10 + five_pence*5 + two_pence*2 + one_pence > 200:
                                break
print total