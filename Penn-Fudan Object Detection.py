#!/usr/bin/env python
# coding: utf-8

# In[1]:


import os 
import numpy as np
import torch
from torchvision import datasets, transforms
from PIL import Image
import glob

import zipfile as zf
files = zf.ZipFile("PennFudanPed.zip", 'r')
files.extractall()
files.close()

picture_list = files.namelist()
#print(picture_list)



# In[2]:


for filename in picture_list:
    try:
        pic = files.read(filename)
    except ValueError:
        print("Issue attempting to read file")
    else:
        #print(filename, ':')
        #print(repr(pic))
        #print(pic.file_size)
    
#files.printdir()

#for filename in files:
#    file = files.read(filename)
#    print(file)

#for (dirpath, dirnames, filenames) in zip("PennFudanPed"):
#    print("Directory path: ", dirpath)
#    print("Folder name: ", dirnames)
#    print("File name: ", filenames)


# In[ ]:


ped_masks_list = "Pytorch_Stuff/PennFudanPed/PedMasks"
images_list = "Pytorch_Stuff/PennFudanPed/PNGImages"

#for filename in glob.glob('C:\Users\Xiao Bao Bao\Desktop\PennFudanPed\PedMasks*.png'):
#    im = Image.open(filename)
#    ped_masks_list.append(im)
    
#img_list = datasets.ImageFolder('C:\Users\Xiao Bao Bao\Desktop\PennFudanPed\PedMasks*.png', transform=transforms)


# In[ ]:




