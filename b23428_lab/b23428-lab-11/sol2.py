import numpy as np
import matplotlib.pyplot as plt


def fun(x,y,m):
	n=0
	for i in range(5):
		n=n+(x[i]**m)*y[i]
	d=0
	for j in range(5):
		d=d+(x[j]**(2*m))
	return n/d
	
	
def cal_pred(a,m,x):
	return a*(x**m)
	
x=[1,2,3,4,5]
y=[120, 300, 550 , 900, 1400]


a1=fun(x,y,2)
print(f"{a1} x^2")
a2=fun(x,y,3)
print(f"{a2} x^3")
e1=0
e2=0

for i in range(5):
	e1=e1+(y[i]-a1*(x[i]**2))**2
	e2=e2+(y[i]-a2*(x[i]**2))**2
	
print(f"error for ax^2 is: {e1}")
print(f"error for bx^3 is: {e2}")
points =np.linspace (1,5,100)
y1=[]
y2=[]
for i in range(100):
	y1.append(cal_pred(a1,2,points[i]))
	y2.append(cal_pred(a2,3,points[i]))
	
plt.plot(x, y, color='r', linestyle='-',   label='Original Data', linewidth=2)
plt.plot(points, y1, color='b', linestyle='-',   label='am^2', linewidth=2)
plt.plot(points, y2, color='g', linestyle='-',   label='bm^3', linewidth=2)
plt.xlabel("X-axis", fontsize=14)
plt.ylabel("Y-axis", fontsize=14)
plt.title("Data Representation with Interpolations", fontsize=16)

plt.grid(True, which='both', linestyle='--', linewidth=0.5)
plt.legend()

plt.show()

##ax^2 is better bcoz of less least square error
#56.86414708886619 x^2
#12.184742871069949 x^3
#error for ax^2 is: 11272.93156281921
#error for bx^3 is: 1965600.860433646

