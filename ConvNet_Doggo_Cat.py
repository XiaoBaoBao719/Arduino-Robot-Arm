#!/usr/bin/env python
# coding: utf-8

# In[1]:


#import zipfile as zf
#files = zf.ZipFile("cats_dogs.zip", 'r')
#files.extractall()
#files.close()

#REBUILD_DATA = True


# In[14]:


import os
import cv2
import torch
import torch.nn as nn
from torch.optim import lr_scheduler
import torchvision
from torchvision import datasets, models, transforms
import matplotlib
import time
import copy
import math
import numpy as np
from tqdm import tqdm

print(torch.__version__)


# In[3]:


main_dir = os.getcwd()


# In[4]:


os.listdir("PetImages")


# In[15]:


main_dir = "./PetImages"
dogs_dir = f'{main_dir}/Dog'
cats_dir = f'{main_dir}/Cat'

cat_list = os.listdir(cats_dir) # dir is your directory path
dog_list = os.listdir(dogs_dir)

number_cat_photos = len(cat_list)
number_dog_photos = len(dog_list)
print(*['Number of cat photos ', number_cat_photos, 
        '| Number of Doggo photos ', number_dog_photos])

#os.listdir(dogs_dir)


# In[11]:


#import shutil
#import re

train_size = int(0.8 * len(cat_list))
test_size = len(cat_list) - train_size
#split doggo data into test and train
dog_training_set, dog_target_set = torch.utils.data.random_split(dog_list, [train_size, test_size])
#split cat data into test and train
cat_training_set, cat_target_set = torch.utils.data.random_split(cat_list, [train_size, test_size])

print(len(dog_training_set))
print(len(cat_training_set))


# In[18]:


#Perform data augmentation in order to prevent overfitting
#Perform normalization for validation

data_transforms = {
    'train': transforms.Compose([
        transforms.RandomRotation(5),
        transforms.RandomHorizontalFlip(),
        transforms.RandomResizedCrop(224, scale=(0,96,1.0), 
                                            ratio=(0.95,1.05)),
        transforms.ToTensor(),
        transforms.Normalize([0.485, 0.456, 0.406],
                             [0.229, 0.224, 0.225])
    ]),
    
    'val': transforms.Compose([
        transforms.Resize([224,224]),
        transforms.ToTensor(),
        transforms.Normalize([0.485, 0.456, 0.406],
                             [0.229, 0.224, 0.225])
    ]),
}


# In[ ]:


#Define constants as well as define the datasets

