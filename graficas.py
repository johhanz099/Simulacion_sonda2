import numpy as np
import matplotlib.pylab as plt

data = np.genfromtxt("data.txt", delimiter = ",")

t =  data[:,0]
sx = data[:,1]
tx = data[:,2]
sy = data[:,3]
ty = data[:,4]

plt.figure()
plt.plot(t,tx,label="tx(t)")
plt.plot(t,ty,label="ty(t)")
plt.legend()
#plt.savefig("sx_sy.png")
plt.close()

plt.figure()
plt.plot(sx,sy,label="Sol y(x)")
plt.plot(tx,ty,label="Tierra y(x)")
plt.legend()
plt.savefig("Sol_Tierra_yx.png")
plt.close()