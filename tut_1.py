#!/usr/bin/env python
# coding: utf-8

# In[37]:


import torch
import numpy as np

x = torch.ones(2, 2, dtype=torch.int)
print(x.size())


# In[38]:


x2 = torch.tensor([2.5, 0.1])
x = torch.rand(2,2)
y = torch.rand(2,2)
z = x + y #can use +, - , *, / operators
#print(z)

z = torch.add(x, y)
z = torch.rand(3,3)
print(z)
print(z[1,:]) #prints second row, all cols 


# In[40]:


#Conversion between numpy and torch tensors
a = torch.tensor(5)
b = a.numpy()

#Caution, tensors created on the CPU reference the same memory, modifying array a will also mutate numpy array b

print(type(b))

a = np.ones(5)
b = torch.from_numpy(a)
print(b)
a += 1
print(b) #b changes since it references the same memory space as array a


# In[ ]:


#We may specify and move the array to a specific device
if(torch.cuda.is_available()):
    device = torch.device("cuda")
    x = torch.ones(5, device=device)
    y = torch.ones(5)
    y = y.to(device) #moves array to the GPU
    z = x + y
    z = z.to("cpu") #moves to the CPU


# In[41]:


x = torch.ones(5, requires_grad=True) #tells pytorch that it will calculate gradient later for optimization
print(x)


# In[ ]:




