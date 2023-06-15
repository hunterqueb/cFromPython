import numpy as np
import time
import matplotlib.pyplot as plt

from ctypes import *
libc = CDLL('./lib_rk4.so')
libFunctions = CDLL('./lib_functions.so')

IC = np.array((0.753906,-0.656982),dtype=np.double)
IC_c = np.ctypeslib.as_ctypes(IC)

tStart = 7
tEnd = 0
h = -0.1
problemDim = 2

if(tStart > tEnd):
    largestTime = tStart
else:
    largestTime = tEnd

length = int(np.abs(largestTime / h)) + 1

# create a 2d array and send it as a single list of pointers to C
sol = np.zeros((length,problemDim),dtype=np.double)
sol = sol.ctypes.data_as(POINTER(c_double))

startTime = time.time()
libc.rk4(libFunctions.linPend,IC_c,c_double(tStart),c_double(tEnd),c_double(h),c_int(problemDim),sol)

sol = np.ctypeslib.as_array(sol,(length,problemDim))

endTime = time.time()
print('time to complete integration: {}'.format(endTime-startTime))

plt.plot(sol[:,0],sol[:,1])
plt.show()