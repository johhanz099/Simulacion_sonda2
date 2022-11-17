import numpy as np
import matplotlib.pylab as plt

data = np.genfromtxt("data.txt", delimiter = ",")

#t =  data[:,0]
sx = data[:,0]
sy = data[:,1]
tx = data[:,2]
ty = data[:,3]
mx = data[:,4]
my = data[:,5]

# plt.figure()
# plt.plot(t,tx,label="tx(t)")
# plt.plot(t,ty,label="ty(t)")
# plt.legend()
# #plt.savefig("sx_sy.png")
# plt.close()

plt.figure()
plt.plot(sx,sy,label="Sol y(x)")
plt.plot(tx,ty,label="Tierra y(x)")
plt.plot(mx,my,label="Marte y(x)")
plt.legend()
plt.savefig("Sol_Tierra_yx.png")
plt.close()