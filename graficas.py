import numpy as np
import matplotlib.pylab as plt

data = np.genfromtxt("data.txt", delimiter = ",")

#t =  data[:,0]
sx = data[:,4]
sy = data[:,5]
tx = data[:,0]
ty = data[:,1]
jx = data[:,2]
jy = data[:,3]
#sondax = data[:,4]
#sonday = data[:,5]

plt.figure()
plt.plot(sx,sy,label="Sol y(x)")
plt.plot(tx,ty,label="Tierra y(x)")
plt.plot(jx,jy,label="Marte y(x)")
# plt.plot(sondax,sonday,label="Sonda y(x)")
plt.legend()
plt.savefig("Sol_Tierra_yx.png")
plt.close()