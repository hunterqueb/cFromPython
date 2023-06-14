import numpy as np
import time
import matplotlib.pyplot as plt

from ctypes import *
libc = CDLL('./lib_rk4.so')
libFunctions = CDLL('./lib_functions.so')

IC = np.array((1,0),dtype=np.double)
IC_c = np.ctypeslib.as_ctypes(IC)
print(IC_c[0])

tStart = 0
tEnd = 7
h = 0.01
problemDim = 2
length = int(tEnd / h) + 1

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