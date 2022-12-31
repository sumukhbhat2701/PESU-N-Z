l1 = [0.063, 0.046, 0.049, 0.041, 0.041, 0.047, 0.036, 0.050, 0.054, 0.063, 0.087, 0.126, 0.224, 0.395] # lock, shared mem
l2 = [0.058, 0.056, 0.041, 0.038, 0.031, 0.043, 0.031, 0.048, 0.037, 0.039, 0.082, 0.119, 0.189, 0.333] # no locks, no shared mem
l3 = [2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384]
l4 = [51.454, 36.752, 25.431, 24.504, 24.748, 25.05, 24.496, 27.923, 52.218, 40.081, 61.65, 107.73, 195.723, 355.867]
l5 = [0.000073, 0.000100, 0.000089, 0.000112, 0.000191, 0.000330, 0.000622, 0.001249, 0.002034, 0.004077, 0.007114, 0.010540, 0.021104, 0.046325]

l3 = [10, 100, 250, 500, 750, 1000, 1250, 1500, 1750, 2000]
l1 = [1050, 1140, 1290, 1540, 1790, 2040, 2290, 2540, 2790, 3040]

import matplotlib.pyplot as plt
import numpy as np

x = np.array(l3)
y1 = np.array(l1)
y2 = np.array(l2)
# y2 = np.array(l2)
# y3 = np.array(l3)
# plt.xlim(10000, 10000000)
fig, ax = plt.subplots()
ax.set_xticks(x)
ax.set_xscale('log')

#v1
plt.plot(x, y1, color = "blue")

#v2
plt.plot(x, y2, color = "yellow")

# v1
plt.scatter(x, y1, color = "red")


#v2
plt.scatter(x, y2, color = "brown")



plt.legend(["With mutex lock", "Without mutex lock"])

plt.xlabel("Number of threads")
plt.ylabel("Time taken(s)")
plt.title("Scalability - #Threads vs Time taken")
plt.savefig("comparision")
plt.show()


