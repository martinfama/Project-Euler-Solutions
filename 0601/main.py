import tqdm as tqdm


def streak(n):
    if n == 1:
        return 1
    k = 0
    while True:
        if (n + k) % (k + 1) != 0:
            return k
        k += 1


for i in tqdm.tqdm(range(1, 4**31)):
    streak(i)
