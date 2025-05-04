import numpy as np
import matplotlib.pyplot as plt

# Parameters
L = 100            # Spatial domain length
T = 50             # Total simulation time
dx = 1.0
dt = 0.1
nx = int(L / dx)
nt = int(T / dt)

# Model parameters
beta = 0.3
gamma = 0.1
DS = 0.2
DI = 0.2
DR = 0.2

# Initial conditions
S = np.ones(nx)
I = np.zeros(nx)
R = np.zeros(nx)

center = nx // 2
I[center - 2:center + 3] = 0.1
S -= I

# Storage
S_mat = np.zeros((nt + 1, nx))
I_mat = np.zeros((nt + 1, nx))
R_mat = np.zeros((nt + 1, nx))
S_mat[0], I_mat[0], R_mat[0] = S.copy(), I.copy(), R.copy()

def laplacian(u):
    return np.roll(u, -1) - 2 * u + np.roll(u, 1)

for t in range(1, nt + 1):
    N = S + I + R
    dSdt = DS * laplacian(S) / dx**2 - beta * S * I / N
    dIdt = DI * laplacian(I) / dx**2 + beta * S * I / N - gamma * I
    dRdt = DR * laplacian(R) / dx**2 + gamma * I

    S += dt * dSdt
    I += dt * dIdt
    R += dt * dRdt

    for arr in [S, I, R]:
        arr[0] = arr[1]
        arr[-1] = arr[-2]

    S_mat[t], I_mat[t], R_mat[t] = S.copy(), I.copy(), R.copy()

# Plot snapshots
x = np.linspace(0, L, nx)
time_indices = [0, int(0.1*nt), int(0.3*nt), int(0.5*nt), int(0.7*nt), int(0.9*nt), nt]
titles = [f"t = {i*dt:.1f}" for i in time_indices]

fig, axs = plt.subplots(len(time_indices), 1, figsize=(10, 15), sharex=True)

for i, idx in enumerate(time_indices):
    axs[i].plot(x, S_mat[idx], label='Susceptible', color='blue')
    axs[i].plot(x, I_mat[idx], label='Infected', color='red')
    axs[i].plot(x, R_mat[idx], label='Recovered', color='green')
    axs[i].set_ylabel('Population')
    axs[i].set_title(titles[i])
    axs[i].legend(loc='upper right')

axs[-1].set_xlabel('Space')
plt.tight_layout()
plt.show()
