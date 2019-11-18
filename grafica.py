import os
import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("exe_14.dat")
data2 = np.loadtxt("exe_rk14.dat")

plt.figure(1, figsize=(10,4)) 

plt.subplot (2,3,1)
plt.plot(data[:,0], data[:,1],label=(" t vs x Euler"),c='blue')
plt.xlabel('X')
plt.ylabel('Y')
plt.legend(loc='0')

plt.subplot(2,3,2)
plt.plot(data[:,0], data[:,2],label=(" t vs v Euler"),c='blue')
plt.xlabel('X')
plt.ylabel('Y')
plt.legend(loc='0')

plt.subplot(2,3,3)
plt.plot(data[:,2], data[:,1],label=(" v vs x Euler"),c='green')
plt.xlabel('X')
plt.ylabel('Y')
plt.legend(loc='0')

plt.subplot (2,3,4)
plt.plot(data2[:,0], data2[:,1],label=(" t vs x RK_fric"),c='green')
plt.xlabel('X')
plt.ylabel('Y')
plt.legend(loc='0')

plt.subplot(2,3,5)
plt.plot(data2[:,0], data2[:,2],label=(" t vs v RK_fric"),c='green')
plt.xlabel('X')
plt.ylabel('Y')
plt.legend(loc='0')

plt.subplot(2,3,6)
plt.plot(data2[:,2], data2[:,1],label=(" v vs x RK_fric"),c='green')
plt.xlabel('X')
plt.ylabel('Y')
plt.legend(loc='0')

plt.savefig("graph.png")
