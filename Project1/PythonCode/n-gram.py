# -*- coding: utf-8 -*-
"""
Created on Mon Apr 22 23:25:47 2019

@author: Nastul
"""
import pandas as pd
#mydata_txt = pd.read_csv('dict.txt',sep = '\n',encoding = 'utf-8')
import re
import linecache
import numpy as np
import os
def ngram2(word1s,word2s):
    bigram1s =list( zip(word1s, word1s[1:]))
    bigram2s =list( zip(word2s, word2s[1:]))
    G1len = len(bigram1s)
    G2len = len(bigram2s)
    

    G1=0
    for i in bigram1s:
        if i in bigram2s:
            G1=G1+1
            bigram2s.remove(i)
      
            
    score = -(G1len + G2len - 2*G1)
    
    return score

def txt_strtonum_feed(filename):
    data = []
    with open(filename, 'r') as f:#with语句自动调用close()方法
        line = f.readline()
        while line:
            read_data = line.split('\n')
            data.append(read_data[0])
            line = f.readline()
        return data 




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
        f = open('outngram.txt', 'a')
        data = [] 
        small_score = -999
        find_str = ""
        for i in dict_txt:
            score = ngram2(j,i)
            if(score > small_score):
                small_score = score
                find_str = i
            elif (score == small_score):
                find_str = find_str + "," + i
            
        print ("processing - %d  %s , find : %s",((int_proec/final_len)*100,j,find_str))
        f.write(find_str + "\n")
        f.close()
    
    
    print (final_data)
    















