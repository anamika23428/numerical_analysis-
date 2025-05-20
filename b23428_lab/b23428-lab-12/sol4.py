import matplotlib.pyplot as plt

def central_difference(data, k, h):
    return (data[k + h] - data[k-h]) / (2*h)

def central_difference_4point(data, k, h):
    return (-1 * data[k+2*h] +  8* data[k + h] - 8*data[k -  h] + data[k-2*h]) / (12 * h)

# Temperature data
data = {
    0:1013,
    100:1001,
    200:990,
    300:979,
    400:969,
    500:959,
    600:950,
    700:941,
    800:933,
    900:925,
    1000:917,
    1100:910,
    1200:902
}

x = list(data.keys())
y = list(data.values())

# Calculations
h = 100
t = 600
ans1 = central_difference(data, t, h)
ans2 = central_difference_4point(data, t, h)

print("rate of pressure drop at  altitude=600 using central difference :", ans1)
print("rate of pressure drop at  altitude=600  using 3-point central difference :", ans2)

# Plotting
plt.plot(x, y, marker='o')
plt.title("Altitue and pressure")
plt.xlabel("altitude")
plt.ylabel("pressure")
plt.grid(True)
plt.show()


#4.3)based on data pressure is decreasing
#4.4)yes there is exponential decrease in the pressure
#4.5)bcoz of higher order of accuracy
#4.6)a.)incorrect weather prediction
#b.) risk of ballon brust
