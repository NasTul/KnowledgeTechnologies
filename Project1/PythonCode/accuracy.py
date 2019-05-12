# -*- coding: utf-8 -*-
"""
Created on Tue Apr 23 01:27:02 2019

@author: Nastul
"""

import pandas as pd
import re
import linecache
import numpy as np
import os


def txt_strtonum_feed(filename):
    data = []
    with open(filename, 'r') as f:#with call close()
        line = f.readline()
        while line:
            read_data = line.split('\n')
            data.append(read_data[0])
            line = f.readline()
        return data 
    
    
test_content = txt_strtonum_feed("combine-5.txt")
combinecost1_txt = np.array(test_content)
test_content = txt_strtonum_feed("correct.txt")
correct_txt = np.array(test_content)


i = 0;
j = 0;
k = 0;
for i in range(0,10322):
    elementlist = combinecost1_txt[i].split(",")
    k = k + len(elementlist)
    if correct_txt[i] == max( elementlist,key=len):
        j=j+1;
      #  print(correct_txt[i]+"----");
     # print(elementlist,end=', ')

print("accuracy:"+str(j/10322*100))

i = 0;
j = 0;
k = 0;
for i in range(0,10322):
    elementlist = combinecost1_txt[i].split(",")
    k = k + len(elementlist)
    if correct_txt[i] in elementlist:
        j=j+1;


f1 = 2*(j/k*100)*(j/10322*100) / ((j/k*100)+(j/10322*100))


print("precision:"+str(j/k*100))
print("recall:"+str(j/10322*100))
print("f1:"+str(f1))
