from tqdm import tqdm
from itertools import permutations


def is_triangular(n):
    x = (8 * n + 1) ** 0.5
    return x.is_integer() and (x - 1) % 2 == 0


def is_square(n):
    x = n**0.5
    return x.is_integer()


def is_pentagonal(n):
    x = (24 * n + 1) ** 0.5
    return x.is_integer() and (x + 1) % 6 == 0


def is_hexagonal(n):
    x = (8 * n + 1) ** 0.5
    return x.is_integer() and (x + 1) % 4 == 0


def is_heptagonal(n):
    x = (40 * n + 9) ** 0.5
    return x.is_integer() and (x + 3) % 10 == 0


def is_octagonal(n):
    x = (3 * n + 1) ** 0.5
    return x.is_integer() and (x + 1) % 3 == 0


triangular_set = []
square_set = []
pentagonal_set = []
hexagonal_set = []
heptagonal_set = []
octagonal_set = []

for n in range(1000, 10000):
    if is_triangular(n):
        triangular_set.append(n)
    if is_square(n):
        square_set.append(n)
    if is_pentagonal(n):
        pentagonal_set.append(n)
    if is_hexagonal(n):
        hexagonal_set.append(n)
    if is_heptagonal(n):
        heptagonal_set.append(n)
    if is_octagonal(n):
        octagonal_set.append(n)


def is_number_chain(n):
    # given a list of 4 digit numbers, check if the last two digits of n_1 are the first
    # of n_2, the last two digits of n_2 are the first of n_3, and so on. check all permutations
    n_perm = permutations(n, len(n))
    for perm in n_perm:
        valid = False
        for i in range(len(perm) - 1):
            if str(perm[i])[-2:] != str(perm[i + 1])[:2]:
                valid = False
                break
            valid = True
        if valid and str(perm[-1])[-2:] == str(perm[0])[:2]:
            return True

    return False


def is_valid_pair(n1, n2):
    return str(n1)[-2:] == str(n2)[:2] and n1 != n2


all_sets = [
    triangular_set,
    square_set,
    pentagonal_set,
    hexagonal_set,
    heptagonal_set,
    octagonal_set,
]

for i in range(len(all_sets)):
    for j in range(i + 1, len(all_sets)):
        print(f"Checking combinations between set {i} and set {j}")
        for n1 in all_sets[i]:
            for n2 in all_sets[j]:
                if is_valid_pair(n1, n2):
                    print(f"    Found a valid pair: {n1}, {n2}")

# for t in tqdm(triangular_set, desc="Processing Triangular Numbers"):
#     for s in tqdm(square_set, desc="Processing Square Numbers"):
#         for p in pentagonal_set:
#             for hx in hexagonal_set:
#                 for hp in heptagonal_set:
#                     for o in octagonal_set:
#                         numbers = [t, s, p, hx, hp, o]
#                         if is_number_chain(numbers):
#                             print("Found a valid chain:", numbers)
#                             print("Sum of the chain:", sum(numbers))
#                             exit(0)
# print("No valid chain found.")
