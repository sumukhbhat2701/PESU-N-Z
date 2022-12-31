l1 = [0.063, 0.046, 0.049, 0.041, 0.041, 0.047, 0.036, 0.050, 0.054, 0.063, 0.087, 0.126, 0.224, 0.395]
l2 = [2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384]


import matplotlib.pyplot as plt
import numpy as np

x = np.array(l2)
y1 = np.array(l1)
# y2 = np.array(l2)
# y3 = np.array(l3)
# plt.xlim(10000, 10000000)
fig, ax = plt.subplots()
ax.set_xticks(x)
ax.set_xscale('log')

plt.scatter(x, y1, color = "red")
plt.plot(x, y1)
plt.xlabel("Number of threads")
plt.ylabel("Time taken(s)")
plt.title("Scalability - #Threads vs Time taken")
plt.savefig("partially_parallel")
plt.show()


