full_list = []

for i in range(2, 9):
    for j in range(1234, 9876):
        string_i, string_j, string_product = str(i), str(j), str(i*j)
        if len(string_product) <= 4:
            if not bool(set(string_i) & set(string_j)) and not bool(set(string_i) & set(string_product)) and not bool(set(string_j) & set(string_product)):
                if len(string_i) == len(set(string_i)) and len(string_j) == len(set(string_j)) and len(string_product) == len(set(string_product)) and not('0' in string_i+string_j+string_product):
                    if not (i*j in full_list):
                        full_list.append(i*j)

for i in range(12, 82):
    for j in range(123, 987):
        string_i, string_j, string_product = str(i), str(j), str(i*j)
        if len(string_product) <= 4:
            if not bool(set(string_i) & set(string_j)) and not bool(set(string_i) & set(string_product)) and not bool(set(string_j) & set(string_product)):
                if len(string_i) == len(set(string_i)) and len(string_j) == len(set(string_j)) and len(string_product) == len(set(string_product)) and not('0' in string_i+string_j+string_product):
                    if not (i*j in full_list):
                        full_list.append(i*j)

print sum(full_list)