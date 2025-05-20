import numpy as np
import matplotlib.pyplot as plt
def simple_linear_reg(x,y):
	x_mean=np.mean(x)
	y_mean=np.mean(y)
	
	n=np.sum((x-x_mean)*(y-y_mean))
	d=np.sum((x-x_mean)**2)
	m=n/d
	b=y_mean-m*x_mean
	
	return m,b

x=[1500, 1600, 1700, 1800, 2000]
y=[245, 265, 275, 295, 325]

a,b=simple_linear_reg(x,y)
print(f"{a} x+{b}")


points =np.linspace (1500,2000,100)
y1=[]
for i in range(100):
	y1.append(a*points[i]+b)
	
plt.plot(x, y, color='r',   label='Original Data')
plt.plot(points, y1, color='b', linestyle='-',   label='ax+b', linewidth=2)
plt.grid(True, which='both', linestyle='--', linewidth=0.5)
plt.legend()

plt.show()

#0.1581081081081081 x+9.054054054054063
