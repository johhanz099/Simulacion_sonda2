import numpy as np
import matplotlib.pylab as plt

data = np.genfromtxt("data.txt", delimiter = ",")

#t =  data[:,0]
sx = data[:,6]
sy = data[:,7]
tx = data[:,2]
ty = data[:,3]
jx = data[:,4]
jy = data[:,5]
sondax = data[:,0]
sonday = data[:,1]

print("Maximo sonda: ", sondax.min())
print("Maximo sonda: ", jx.min())

plt.figure()
plt.plot(sx,sy,label="Sol y(x)")
plt.plot(tx,ty,label="Tierra y(x)")
plt.plot(jx,jy,label="Jupiter y(x)")
plt.plot(sondax,sonday,label="Sonda y(x)")
plt.legend()
plt.savefig("Sol_Tierra_yx.png")
plt.close()
