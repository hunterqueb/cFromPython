import numpy as np
import time

from ctypes import *
libc = CDLL('./lib_test.so')

a = libc.cmult(5,c_double(.1345233))

p = c_int(10)
libc.changeByRef(byref(p))
print(p.value)

x = np.array((0,1,2,3,1,1,6,8,1,8,5,7),dtype=np.int32)
y = np.array(((0,1,2),(3,4,5),(6,7,8)),dtype=np.int32)
z = np.zeros((3,3),dtype=np.int32)
z[0] = 1;z[1] = 2;z[2] = 3

print(x.data) # pointer to memory area of array as py integer
print(y)

libc.print1dArray(x.ctypes.data_as(POINTER(c_int)))
print()
libc.print2dArray(np.ctypeslib.as_ctypes(z),3)
libc.returnByRefArray(np.ctypeslib.as_ctypes(z),3)
libc.print2dArray(np.ctypeslib.as_ctypes(z),3)

arrayFromC = libc.createArray()
print()
# cStart = time.time()
# libc.c_speed()
# cEnd = time.time()

# pStart = time.time()
# for i in range(10000):
#     for j in range(10000):
#         pass
# pEnd = time.time()

# print("C: {}\n Python: {}".format(cEnd-cStart,pEnd-pStart))h