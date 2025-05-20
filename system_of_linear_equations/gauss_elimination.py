import numpy as np
def gauss_elimination(a,n):
    for i in range(n-1):
        for j in range(i+1,n):
            factor=a[j][i]/a[i][i]
            for k in range(n+1):
                a[j][k]=a[j][k]-factor*a[i][k]
    
    x=[0 for i in range(n)]
    for i in range(n-1 , -1, -1):
        x[i]=a[i][n]
        for j in range(i+1,n):
            x[i]=x[i]-x[j]*a[i][j]
        x[i] /= a[i][i]
    
    return x

a = [
    [3.0, 2.0, -1.0, 1.0],
    [2.0, -2.0, 4.0, -2.0],
    [-1.0, 0.5, -1.0, 0.0]
]
n = 3

solution = gauss_elimination(a, n)
print("Solution x =", solution)


