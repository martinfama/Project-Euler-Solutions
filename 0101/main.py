import numpy as np

u_coeffs = np.array([1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1])
def u_n(n):
    return 1 - n + n**2 - n**3 + n**4 - n**5 + n**6 - n**7 + n**8 - n**9 + n**10

S = 0
for N in range(1, 11):
    b = [u_n(n) for n in range(1, N+1)]
    coeff = np.polyfit(range(1, N+1), b, N-1)
    s = 0
    for ic, c in enumerate(coeff[::-1]):
        s += c * (N+1)**ic
    S += s
    
print(int(S))