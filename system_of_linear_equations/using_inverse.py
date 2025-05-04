import numpy as np

# Define matrix A and vector b
A = np.array([[2, 1],
              [5, 3]])
b = np.array([1, 2])

# Compute the inverse of A
A_inv = np.linalg.inv(A)

# Multiply inverse of A with b to get x
x = np.dot(A_inv, b)

print("Solution x =", x)
