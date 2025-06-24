#numbers = [319, 680, 180, 690, 129, 620, 762, 689, 762, 318, 368, 710, 720, 710, 629, 168, 160, 689, 716, 731, 736, 729, 316, 729, 729, 710, 769, 290, 719, 680, 318, 389, 162, 289, 162, 718, 729, 319, 790, 680, 890, 362, 319, 760, 316, 729, 380, 319, 728, 716]
numbers = [129, 389, 769, 790, 160, 289, 290, 680, 689, 690, 180, 316, 318, 319, 710, 716, 162, 718, 719, 720, 728, 729, 731, 890, 736, 362, 620, 368, 168, 629, 760, 762, 380]

digits = []
for i in xrange(10):
	digits.append([])

print numbers
for x in numbers:
	t_digits = [x/100, (x/10)%10, x%10]
	if not (t_digits[1] in digits[t_digits[0]]):
		digits[t_digits[0]].append(t_digits[1])
	if not (t_digits[2] in digits[t_digits[1]]):
		digits[t_digits[1]].append(t_digits[2])

for i in xrange(10):
	print i
	for j in digits[i]:
		print "-", j
			
