import matplotlib.pyplot as plt

def forward_difference(data, k, h):
    return (data[k + h] - data[k]) / h

def forward_difference_3point(data, k, h):
    return (-3 * data[k] + 4 * data[k + h] - data[k + 2 * h]) / (2 * h)

# Temperature data
data = {
    0: 25.0,
    1: 27.2,  
    2: 30.1,
    3: 33.8,
    4: 38.2,
    5: 43.4,
    6: 49.3,
    7: 56.1,
    8: 63.7,
    9: 72.1,
    10: 81.4,
    11: 91.5,
    12: 102.5
}

x = list(data.keys())
y = list(data.values())

# Calculations
h = 1
t = 0
ans1 = forward_difference(data, t, h)
ans2 = forward_difference_3point(data, t, h)

print("Temperature at t=0 using forward difference with h=1:", ans1)
print("Temperature at t=0 using 3-point forward difference with h=1:", ans2)

# Plotting
plt.plot(x, y, marker='o')
plt.title("Temperature over Time")
plt.xlabel("Time")
plt.ylabel("Temperature")
plt.grid(True)
plt.show()

