# -*- coding: utf-8 -*-
"""
Created on Sat Apr 20 23:59:16 2019

@author: Nastul
"""

import pandas as pd
#mydata_txt = pd.read_csv('dict.txt',sep = '\n',encoding = 'utf-8')
import re
import linecache
import numpy as np
import os
from numba import jit



def txt_strtonum_feed(filename):
    data = []
    with open(filename, 'r') as f:#with语句自动调用close()方法
        line = f.readline()
        while line:
            read_data = line.split('\n')
            data.append(read_data[0])
            line = f.readline()
        return data 

@jit
def minEditDist(sm,sn):
    
    temp = sm
    sm =sn
    sn = temp
    m,n = len(sm)+1,len(sn)+1
    matrix = [[0]*n for i in range(m)]
    matrix[0][0]=0
    for i in range(1,m):
        matrix[i][0] = matrix[i-1][0]-1
    for j in range(1,n):
        matrix[0][j] = matrix[0][j-1]-1
    cost = 0    
    for i in range(1,m):
        for j in range(1,n):
            #print(sm[i-1]+"-"+sn[j-1])
            if sm[i-1]==sn[j-1]:
                cost = 3
            else:
                cost = -1
            matrix[i][j]=max(matrix[i-1][j]-1,matrix[i][j-1]-1,matrix[i-1][j-1]+cost)
    return matrix[m-1][n-1]





if __name__ == '__main__':
    test_content = txt_strtonum_feed('dict.txt')
    dict_txt = np.array(test_content)
    test_content = txt_strtonum_feed('misspell.txt')
    misspell_txt = np.array(test_content)
    
    final_len = 10322
    final_data = []
    int_proec = 0
    for j in misspell_txt:
        int_proec = int_proec + 1
        f = open('combinecost1.txt', 'a')
        data = [] 
        small_score = -999
        find_str = ""
        for i in dict_txt:
            score = minEditDist(j,i)
            if(score > small_score):
                small_score = score
                find_str = i
            elif (score == small_score):
                find_str = find_str + "," + i
            
        print ("processing - %d  %s , find : %s",((int_proec/final_len)*100,j,find_str))
        f.write(find_str + "\n")
        f.close()
    
    
    print (final_data)