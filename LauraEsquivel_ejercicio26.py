import matplotlib
import matplotlib.pyplot as plt
import numpy as np

def leer(f):
    return [float(i) for i in f.readline().strip().split()]
file1=open("euler.dat","r")
y1=leer(file1)
y2=leer(file1)
t=leer(file1)
fig, axs = plt.subplots(nrows=3, ncols=3)
ax=axs[0][0]
ax.plot(t,y1 )
ax.set_ylim(-1.5,1.5)
ax.set_xlim(0,15)
ax=axs[1][0]
ax.plot(t, y2)
ax.set_ylim(-1.5,1.5)
ax.set_xlim(0,15)
ax=axs[2][0]
ax.plot(y1, y2)
ax.set_ylim(-2.0,2.0)
ax.set_xlim(-2.0,2.0)
file1=open("rk4.dat","r")
y1=leer(file1)
y2=leer(file1)
t=leer(file1)

ax=axs[0][1]
ax.plot(t,y1 )
ax.set_ylim(-1.5,1.5)
ax.set_xlim(0,15)
ax=axs[1][1]
ax.plot(t, y2)
ax.set_ylim(-1.5,1.5)
ax.set_xlim(0,15)
ax=axs[2][1]
ax.plot(y1, y2)
ax.set_ylim(-2.0,2.0)
ax.set_xlim(-2.0,2.0)
file1=open("leapfrog.dat","r")
y1=leer(file1)
y2=leer(file1)
t=leer(file1)

ax=axs[0][2]
ax.tricontourf
ax.plot(t,y1  )
ax.set_ylim(-1.5,1.5)
ax.set_xlim(0,15)
ax=axs[1][2]
ax.plot(t, y2 )
ax.set_ylim(-1.5,1.5)
ax.set_xlim(0,15)
ax=axs[2][2]
ax.plot(y1, y2)
ax.set_ylim(-2.0,2.0)
ax.set_xlim(-2.0,2.0)
ax=axs[0][0]
ax.set_title('Euler\nposition vs t')
ax.patches
ax=axs[0][1]
ax.set_title('rk4\nposition vs t')
ax=axs[0][2]
ax.set_title('Leap Frog\nposition vs t')
ax=axs[1][0]
ax.set_title('velocity vs t')
ax=axs[1][1]
ax.set_title('velocity vs t')
ax=axs[1][2]
ax.set_title('velocity vs position')
ax=axs[2][0]
ax.set_title('velocity vs position')
ax=axs[2][1]
ax.set_title('velocity vs position')
ax=axs[2][2]
ax.set_title('velocity vs position')
fig.subplots_adjust(hspace=0.5, wspace=0.5)
plt.savefig('test.png', bbox_inches='tight')
plt.show()
