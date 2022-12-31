'''
Assume df is a pandas dataframe object of the dataset given
'''

import numpy as np
import pandas as pd
import random

'''Calculate the entropy of the enitre dataset'''
# input:pandas_dataframe
# output:int/float
def get_entropy_of_dataset(df):
    columns = df.columns
    target = df[columns[-1]]
    classes = df[columns[-1]].unique()

    entropy = 0

    for class_ in classes:
        prob = len(df[target == class_])/len(target)
        entropy -= (prob * np.log2(prob))
	
    return entropy


'''Return avg_info of the attribute provided as parameter'''
# input:pandas_dataframe,str   {i.e the column name ,ex: Temperature in the Play tennis dataset}
# output:int/float
def get_avg_info_of_attribute(df, attribute):
    column = df[attribute]
    values = column.unique()
    avg_info = 0
    for value in values:    
        new_df = df[column == value]
        avg_info += (get_entropy_of_dataset(new_df) * (len(new_df)/len(df))) 

    return avg_info


'''Return Information Gain of the attribute provided as parameter'''
# input:pandas_dataframe,str
# output:int/float
def get_information_gain(df, attribute):
    information_gain = get_entropy_of_dataset(df) - get_avg_info_of_attribute(df, attribute)
    return information_gain

#input: pandas_dataframe
#output: ({dict},'str')
def get_selected_attribute(df):
    '''
    Return a tuple with the first element as a dictionary which has IG of all columns 
    and the second element as a string with the name of the column selected

    example : ({'A':0.123,'B':0.768,'C':1.23} , 'C')
    '''
    d = {}
    for col in list(df.columns[:-1]):
        d[col] = get_information_gain(df, col)
    
    vals = list(d.values())

    for k in list(d.keys()):
        if(d[k] == max(vals)):
            max_ = k
            break

    ans = (d, max_)
    
    return ans
