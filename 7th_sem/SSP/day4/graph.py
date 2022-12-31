import matplotlib.pyplot as plt
import numpy as np

f = open('network_logs.txt', 'r')
lines = f.readlines()
l1 = []
l2 = []
for line in lines:
	words = line.split()
	if(words[-1].startswith("Len=")):
		l1.append(float(words[-1].split("Len=")[-1]))
		l2.append(float(words[1]))

x = np.array(l2)
y = np.array(l1)
#print(len(l1))
plt.scatter(x, y, color = "red")
#plt.plot(x, y)
plt.xlabel("Time")
plt.ylabel("Load")
plt.title("Load Analysis")
plt.savefig("load_analysis")
plt.show()
	

