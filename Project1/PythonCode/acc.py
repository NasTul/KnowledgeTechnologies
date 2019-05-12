# -*- coding: utf-8 -*-
"""
Created on Sat Apr 27 16:50:51 2019

@author: Nastul
"""


def txt_strtonum_feed(filename):
    data = []
    with open(filename, 'r') as f:#with call close()
        line = f.readline()
        while line:
            read_data = line.split('\n')
            data.append(read_data[0])
            line = f.readline()
        return data 
    
    
test_content = txt_strtonum_feed("dict.txt")
dirc_txt = np.array(test_content)
test_content = txt_strtonum_feed("correct.txt")
correct_txt = np.array(test_content)
test_content = txt_strtonum_feed("misspell.txt")
misspell_txt = np.array(test_content)

i = 0;
j = 0;
k = 0;
for i in range(0,10322):
    if correct_txt[i] == misspell_txt[i] :
        if (misspell_txt[i] in dirc_txt):
            j=j+1;
      #  print(correct_txt[i]+"----");
     # print(elementlist,end=', ')





print("accuracy:"+str(j/10322))

