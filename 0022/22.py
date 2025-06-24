f = open('22_names.txt')
names_string = f.read()
names = []
counter = 0
i = 0
while i < len(names_string):
    names.append([""])
    while i < len(names_string) and names_string[i] != ",":
        names[counter].append(names_string[i])
        i += 1
    counter += 1
    i += 1
list_of_names = []
for i in range(len(names)):
    current = ""
    for x in range(2, len(names[i])-1):
        current += names[i][x]
    list_of_names.append(current)
ordered = []
alphabet = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
i = 0
while i < len(list_of_names):
    original = list_of_names[i]
    for x in range(i+1, len(list_of_names)):
        if min(original, list_of_names[x]) == list_of_names[x]:
            list_of_names[i] = list_of_names[x]
            list_of_names[x] = original
            original = list_of_names[i]
    i += 1
total = 0
for i in range(len(list_of_names)):
    little_total = 0
    for x in range(len(list_of_names[i])):
        little_total += alphabet.index(list_of_names[i][x])+1
    total += little_total*(i+1)
print total
