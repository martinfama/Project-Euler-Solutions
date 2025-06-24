import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import minimize

x_e = 50 / np.sqrt(2) - 25


def objective(thetas):
    global x_e
    yf = 100 / np.sqrt(2)
    t_0, t_1, t_2, t_3, t_4, t_5 = thetas
    l_0 = x_e / np.cos(t_0)
    l_1 = 10 / np.cos(t_1)
    l_2 = 10 / np.cos(t_2)
    l_3 = 10 / np.cos(t_3)
    l_4 = 10 / np.cos(t_4)
    l_5 = 10 / np.cos(t_5)
    y = x_e * np.tan(t_0) + 10 * (
        np.tan(t_1) + np.tan(t_2) + np.tan(t_3) + np.tan(t_4) + np.tan(t_5)
    )
    y_l = yf - y
    l_6 = np.sqrt(x_e**2 + y_l**2)

    total_time = l_0 / 10 + l_1 / 9 + l_2 / 8 + l_3 / 7 + l_4 / 6 + l_5 / 5 + l_6 / 10

    return total_time


def plot_objective_path(thetas):
    global x_e
    y_f = 100 / np.sqrt(2)
    t_0, t_1, t_2, t_3, t_4, t_5 = thetas

    x_0 = 0
    x_1 = x_e
    x_2 = x_1 + 10
    x_3 = x_2 + 10
    x_4 = x_3 + 10
    x_5 = x_4 + 10
    x_6 = x_5 + 10
    x_7 = x_6 + x_e
    y_0 = 0
    y_1 = x_e * np.tan(t_0)
    y_2 = y_1 + 10 * np.tan(t_1)
    y_3 = y_2 + 10 * np.tan(t_2)
    y_4 = y_3 + 10 * np.tan(t_3)
    y_5 = y_4 + 10 * np.tan(t_4)
    y_6 = y_5 + 10 * np.tan(t_5)
    y_7 = y_f

    x = [x_0, x_1, x_2, x_3, x_4, x_5, x_6, x_7]
    y = [y_0, y_1, y_2, y_3, y_4, y_5, y_6, y_7]

    fig, ax = plt.subplots()
    ax.grid(alpha=0.5)
    # vertical lines at x_1, x_2, x_3, x_4, x_5
    for x_val in [x_1, x_2, x_3, x_4, x_5, x_6]:
        ax.axvline(x=x_val, color="red", linestyle="--", alpha=0.5)

    ax.plot(x, y, marker="o")
    fig.savefig("trajectory.png", dpi=300)


initial_guess = np.array([45 * np.pi / 180] * 6)
result = minimize(lambda x: objective(x), initial_guess, method="SLSQP", tol=1e-11)
print("Optimal angles (in radians):", result.x)
print(f"Minimum time (in days): {result.fun:.10f}")
plot_objective_path(result.x)
