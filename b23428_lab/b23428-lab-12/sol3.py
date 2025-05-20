import matplotlib.pyplot as plt

def backward_difference(data, k, h):
    return (data[k ] - data[k-h]) / h

def backward_difference_3point(data, k, h):
    return (3 * data[k] - 4 * data[k - h] + data[k - 2 * h]) / (2 * h)
def double_derivative(data, t, h):
	return (data[t+h] - 2* data[t] +data[t-h])/(h**2)
# Temperature data
data = {
   0:0.0,
   5:5.4,
   10:10.6,
   15:15.7,
   20:20.7,
   25:25.4,
   30:29.8,
   35:33.9,
   40:37.5,
   45:40.6,
   50:43.0
}

x = list(data.keys())


# Calculations
h = 5
t = 50
ans1 = backward_difference(data, t, h)
ans2 = backward_difference_3point(data, t, h)

print("Truck's speed at t=50 using forward difference: ", ans1)
print("Truck's speed at t=50 using 3-point forward difference: ", ans2)



a=double_derivative(data, 45, h)
print(a)
stopping_dis= backward_difference_3point(data, 50, h)**2/(-2*a)
print("stopping distance is" , stopping_dis)


#3 point is better as it's order of accuracy is high and using more data points
# Plotting

y=[]
for i in range(2,10):
	y.append(backward_difference_3point(data, x[i], h))
	
plt.plot(x[3:], y, marker='o')
plt.title("speed over Time")
plt.xlabel("Time")
plt.ylabel(" speed  ")
plt.grid(True)
plt.show()
print("Truck's speed at t=20",backward_difference_3point(data, 20, h))
print("Truck's speed at t=30",backward_difference_3point(data, 30, h))
print("Truck's speed at t=40",backward_difference_3point(data, 40, h))
#as speed is decreasing so truck is slowing

#
