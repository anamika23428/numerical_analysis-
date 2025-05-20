import numpy as np
import matplotlib.pyplot as plt

def table_construction(x, y, n):
    table = np.zeros((n, n))
    table[:, 0] = y 
    
    for col in range(1, n):
        for row in range(col, n):
            table[row, col] = table[row, col-1] - table[row-1, col-1]
    
    return table

def forward_diff(x, y, n, k):
    s = (k - x[0]) / (x[1] - x[0])
    
    ans = y[0]
    diff_table = table_construction(x, y, n)
    
    for i in range(1, n):
        term = 1
        for j in range(i):
            term *= (s - j) / (j + 1)
        ans += term * diff_table[i, i]
    
    return ans

def backward_diff(x, y, n, k):
    s = (k - x[n-1]) / (x[1] - x[0])
    
    ans = y[n-1]
    diff_table = table_construction(x, y, n)
    
    for i in range(1, n):
        term = 1
        for j in range(i):
            term *= (s + j) / (j + 1)
        ans += term * diff_table[n-1, i]
    
    return ans

def langranges(x, y, n, k):
    res = 0
    for i in range(n):
        term = y[i]
        for j in range(n):
            if j != i:
                term *= (k - x[j]) / (x[i] - x[j])
        res += term
    return res

def plot(x, y):
    plt.plot(x, y)
    plt.xlabel("X-axis")
    plt.ylabel("Y-axis")
    plt.title("Data Representation")
    plt.show()


x = [9, 10, 11, 12, 13, 14, 15, 16, 17, 18]
y = [153.8, 155.2, 157.38, 160.0, 161.3, 163.5, 164.7, 166.1, 168.0, 169.5]
    
n = len(x)
k = 12.5
    
f1 = forward_diff(x, y, n, k)
b1 = backward_diff(x, y, n, k)
l1 = langranges(x, y, n, k)
 

print(f"Value of prize at 12:30 am using Newton Forward Interpolation is: {f1}")
print(f"Value of prize at 12:30 am using Newton Backward Interpolation is: {b1}")
print(f"Value of prize at 12:30 am using Langranges Interpolation is: {l1}")



plt.plot(x, y, color='r', linestyle='-',   label='Original Data', linewidth=2)

points =np.linspace (9,18,1000)
y_nf = []
for i in range(1000):
    y_nf.append(forward_diff(x, y, n, points[i]))
plt.plot(points, y_nf, linestyle=':', color='b',  label='Forward Difference', linewidth=2)


y_nb = []
for i in range(1000):
    y_nb.append(forward_diff(x, y, n, points[i]))
plt.plot(points, y_nb, linestyle='--', color='g',  label='Backward Difference', linewidth=2)


y_l = []
for i in range(1000):
    y_l.append(forward_diff(x, y, n, points[i]))
plt.plot(points, y_l, linestyle='-.', color='m', label='Lagrange Interpolation', linewidth=2)

plt.xlabel("X-axis", fontsize=14)
plt.ylabel("Y-axis", fontsize=14)
plt.title("Data Representation with Interpolations", fontsize=16)

plt.grid(True, which='both', linestyle='--', linewidth=0.5)
plt.legend()

plt.show()

