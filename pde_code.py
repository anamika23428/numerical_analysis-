
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

# ======================
# Parameters
# ======================
L = 100            # Spatial domain length
T = 50             # Total simulation time
dx = 1.0           # Spatial step
dt = 0.1           # Time step
nx = int(L / dx)   # Number of spatial points
nt = int(T / dt)   # Number of time steps

# Model parameters
beta = 0.3         # Transmission rate
gamma = 0.1        # Recovery rate
DS = 0.2           # Diffusion coefficient - Susceptible
DI = 0.2           # Diffusion coefficient - Infected
DR = 0.2           # Diffusion coefficient - Recovered

# ======================
# Stability Check
# ======================
max_diff = max(DS, DI, DR)
cfl_condition = dx**2 / (2 * max_diff)
if dt > cfl_condition:
    print(f"Warning: dt = {dt} may be unstable. Suggested dt < {cfl_condition:.4f} for stability")

# ======================
# Initial Conditions
# ======================
S = np.ones(nx)    # Susceptible population
I = np.zeros(nx)   # Infected population
R = np.zeros(nx)   # Recovered population

# Initial infection in the center
center = nx // 2
I[center - 2:center + 3] = 0.1
S -= I

# ======================
# Storage for Visualization
# ======================
S_mat = np.zeros((nt + 1, nx))
I_mat = np.zeros((nt + 1, nx))
R_mat = np.zeros((nt + 1, nx))
S_mat[0], I_mat[0], R_mat[0] = S.copy(), I.copy(), R.copy()

# ======================
# Laplacian Operator (with Neumann BCs)
# ======================
def laplacian(u):
    laplacian_u = np.roll(u, -1) - 2 * u + np.roll(u, 1)
    # Apply Neumann boundary conditions (zero flux)
    laplacian_u[0] = -2 * u[0] + 2 * u[1]
    laplacian_u[-1] = 2 * u[-2] - 2 * u[-1]
    return laplacian_u

# ======================
# Main Simulation Loop
# ======================
for t in range(1, nt + 1):
    N = np.maximum(S + I + R, 1e-10)  # Avoid division by zero
    
    # Compute derivatives
    dSdt = DS * laplacian(S) / dx**2 - beta * S * I / N
    dIdt = DI * laplacian(I) / dx**2 + beta * S * I / N - gamma * I
    dRdt = DR * laplacian(R) / dx**2 + gamma * I
    
    # Update populations (ensure non-negative)
    S = np.maximum(S + dt * dSdt, 0)
    I = np.maximum(I + dt * dIdt, 0)
    R = np.maximum(R + dt * dRdt, 0)
    
    # Store results
    S_mat[t], I_mat[t], R_mat[t] = S.copy(), I.copy(), R.copy()

# ======================
# Visualization
# ======================
x = np.linspace(0, L, nx)

# Option 1: Static Plot of Snapshots
plt.figure(figsize=(12, 8))
time_indices = [0, int(0.2*nt), int(0.4*nt), int(0.6*nt), int(0.8*nt), nt]
colors = ['blue', 'red', 'green']

for i, idx in enumerate(time_indices):
    plt.subplot(2, 3, i+1)
    for j, (mat, label) in enumerate(zip([S_mat, I_mat, R_mat], ['Susceptible', 'Infected', 'Recovered'])):
        plt.plot(x, mat[idx], color=colors[j], label=label)
    plt.title(f"Time = {idx*dt:.1f} days")
    plt.ylim(0, 1.1)
    if i == 0:
        plt.legend()
    if i >= 3:
        plt.xlabel('Space')

plt.tight_layout()
plt.suptitle('SIR Model with Spatial Diffusion', y=1.02)
plt.show()

# Option 2: Animation (uncomment to use)

fig, ax = plt.subplots(figsize=(10, 6))
ax.set_xlim(0, L)
ax.set_ylim(0, 1.1)
ax.set_xlabel('Space')
ax.set_ylabel('Population')

lineS, = ax.plot(x, S_mat[0], 'b-', label='Susceptible')
lineI, = ax.plot(x, I_mat[0], 'r-', label='Infected')
lineR, = ax.plot(x, R_mat[0], 'g-', label='Recovered')
ax.legend()

def update(frame):
    lineS.set_ydata(S_mat[frame])
    lineI.set_ydata(I_mat[frame])
    lineR.set_ydata(R_mat[frame])
    ax.set_title(f'Time = {frame*dt:.1f} days')
    return lineS, lineI, lineR

ani = FuncAnimation(fig, update, frames=nt, interval=50, blit=True)
plt.show()

