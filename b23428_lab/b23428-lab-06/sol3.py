import numpy as np

A=np.array([[2,3,1],[4,1,-2],[1,-1,3]] , dtype=float)
B=np.array([7,-1,5], dtype=float)
A_inv= np.linalg.inv(A);
print("inverse of X: ")
print(A_inv)
print("solution: ")
X=np.dot(A_inv ,B)
print(X)



#inverse of X: 
#[[-0.02222222  0.22222222  0.15555556]
#[ 0.31111111 -0.11111111 -0.17777778]
#[ 0.11111111 -0.11111111  0.22222222]]
#solution: 
#[0.4 1.4 2. ]

