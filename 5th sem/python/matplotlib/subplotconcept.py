import matplotlib.pyplot as pit
import numpy as np

x=np.array([2,4,6,8])
y=np.array([4,6,8,10])
pit.subplot(3,1,1)
pit.plot(x,y)


x=np.array([2,4,3,8])
y=np.array([4,6,15,10])
pit.subplot(3,1,2)
pit.plot(x,y,color='red')


x=np.array([2,6,5,9])
y=np.array([1,5,8,3])
pit.subplot(3,1,3)
pit.plot(x,y,color='green')
pit.show()