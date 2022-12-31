# l1 = [0.029, 0.086, 0.631, 6.660]
# l2 = [0.373, 0.063, 0.508, 5.380]
# l3 = [0.018, 0.086, 0.700, 9.417]

import matplotlib.pyplot as plt
import numpy as np

# x = np.array([10000, 100000, 1000000, 10000000])
# y1 = np.array(l1)
# y2 = np.array(l2)
# y3 = np.array(l3)
# plt.xlim(10000, 10000000)
# fig, ax = plt.subplots()
# ax.set_xscale('log')
# ax.set_xticks(x)
# plt.scatter(x, y3, color = "red")
# plt.plot(x, y3)
# plt.xlabel("Input Size")
# plt.ylabel("Time taken(s)")
# plt.title("Heap Sort - Input Size vs Time taken")
# plt.savefig("heap_sort_time")
# plt.show()
# merge sort
import matplotlib.pyplot as plt
import numpy as np

y = np.array([15.79, 76.32, 0, 2.63, 5.26])
mylabels = ["swap", "partition", "genRandom", "quick_sort", "runSuite"]
plt.title("Quick Sort, n = 1000k - Percentage time spent in each of the functions")
plt.pie(y, labels = mylabels, autopct='%1.0f%%')
plt.savefig("pieQS1000k_time")
plt.show() 


