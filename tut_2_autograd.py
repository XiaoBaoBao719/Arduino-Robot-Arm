#!/usr/bin/env python
# coding: utf-8

# In[1]:


import torch
import numpy as np

x = torch.randn(3, requires_grad=True)
print(x)

#creates computation graph where each operation is a node (like a perceptron) that we can apply backprop to

y=x+2 
print(y)


# In[2]:


z = y*y*2
z = z.mean()
print(z)


# In[3]:


#calculates gradients
#note .backward() needs a gradient argument when not using scalars
v = torch.tensor([0.1, 1.0, 0.001], dtype=torch.float32)

z.backward() #dz/dx  calculates the gradient

print(x.grad)


# In[4]:


# x.requires_grad_(False)  the trailing underscore "_" means that it will update the variable in place
# x.detach()   omits the gradient option from tensor
# with torch.no_grad():   wraps the tensor in an operation that disables the gradient attribute option
#   y = x + 2

#dummy training example with "weights"

weights = torch.ones(4, requires_grad=True)

for epoch in range(3):
    model_output = (weights*3).sum()
    
    model_output.backward()
    
    print(weights.grad)
    
#Notice how each iteration causes the backprop to accumulate values in our weights


# In[5]:


# empty the weights
weights.grad.zero_()
weights


# In[12]:


weights = torch.ones(4, requires_grad=True)

optimizer = torch.optim.SGD([weights], lr=0.01)
optimizer.step()
optimizer.zero_grad()

weights

