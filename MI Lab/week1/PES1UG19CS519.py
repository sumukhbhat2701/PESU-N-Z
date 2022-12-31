#This weeks code focuses on understanding basic functions of pandas and numpy 
#This will help you complete other lab experiments


# Do not change the function definistions or the parameters
import numpy as np
import pandas as pd

#input: tuple (x,y)    x,y:int 
def create_numpy_ones_array(shape):
        # return a numpy array with one at all index
        # returns None if parameters do not support the operation
        array = None
        
        if(shape[0] > 0 and shape[1] > 0):
                array = np.ones(shape, dtype = int)
        return array
     
#input: tuple (x,y)    x,y:int 
def create_numpy_zeros_array(shape):
        # return a numpy array with zeros at all index
        # returns None if parameters do not support the operation
        array = None

        if(shape[0] > 0 and shape[1] > 0):
                array = np.zeros(shape, dtype = int)
        return array

#input: int  
def create_identity_numpy_array(order):
        #return a identity numpy array of the defined order
        # returns None if parameters do not support the operation
        array = None

        if(order > 0):
                array = np.identity(order, dtype = int)

        return array

#input: numpy array
def matrix_cofactor(array):
        #return cofactor matrix of the given array
        # array=None
        # returns None if parameters do not support the operation
        res = None

        if(array.shape[0] == array.shape[1]):
            res = np.random.rand(array.shape[0], array.shape[1])

            for i in range(array.shape[0]): 
                    for j in range(array.shape[1]):
                            minor_matrix = np.delete(array, i, 0)
                            minor_matrix = np.delete(minor_matrix, j, 1)
                            minor = np.linalg.det(minor_matrix)
                            res[i][j] = ((-1)**(i+j))*minor
        return res

#Input: (numpy array, int ,numpy array, int , int , int , int , tuple,tuple)
#tuple (x,y)    x,y:int 
def f1(X1,coef1,X2,coef2,seed1,seed2,seed3,shape1,shape2):
        #note: shape is of the forst (x1,x2)
        #return W1 x (X1 ** coef1) + W2 x (X2 ** coef2) +b
        # where W1 is random matrix of shape shape1 with seed1
        # where W2 is random matrix of shape shape2 with seed2
        # where B is a random matrix of comaptible shape with seed3
        # if dimension mismatch occur return -1
        
        ans1 = X1 ** coef1
        ans2 = X2 ** coef2
        if(shape1[0] > 0 and shape1[1] > 0):
                np.random.seed(seed1)
                W1 = np.random.rand(shape1[0], shape1[1])
        else:
            ans = -1

        if(shape2[0] > 0 and shape2[1] > 0):
                np.random.seed(seed2)
                W2 = np.random.rand(shape2[0], shape2[1])
        else:
            ans = -1
	
        if(W1.shape[1] != ans1.shape[0] or W2.shape[1] != ans2.shape[0]):
                ans = -1
        else:
                
                ans4 = np.matmul(W1, ans1)
                ans5 = np.matmul(W2, ans2)
                
                if(ans4.shape[0] != ans5.shape[0] or ans4.shape[1] != ans5.shape[1]):
                        ans = -1
                else:
                        ans3 = ans4 + ans5
                        np.random.seed(seed3)
                        B = np.random.rand(ans3.shape[0], ans3.shape[1]) 
                        ans = ans3 + B
        return ans


def fill_with_mode(filename, column):
        """
        Fill the missing values(NaN) in a column with the mode of that column
        Args:
                filename: Name of the CSV file.
        column: Name of the column to fill
        Returns:
        df: Pandas DataFrame object.
        (Representing entire data and where 'column' does not contain NaN values)
        (Filled with above mentioned rules)
        """

        # Return None incase of invalid parameters passed
        if(filename == '' or filename[-4:]!=".csv" or filename == None or column == None):
            return None

        df = pd.read_csv(filename)
        df[column].fillna(df[column].mode()[0], inplace=True)

        return df

def fill_with_group_average(df, group, column):
        """
        Fill the missing values(NaN) in column with the mean value of the 
        group the row belongs to.
        The rows are grouped based on the values of another column

        Args:
                df: A pandas DataFrame object representing the data.
                group: The column to group the rows with
                column: Name of the column to fill
        Returns:
                df: Pandas DataFrame object.
        (Representing entire data and where 'column' does not contain NaN values)
        (Filled with above mentioned rules)
        """
        # Return None incase of invalid parameters passed
        if(df.empty or column == None or group == None):
            return None

        groups = df.groupby(group)
        df[column].fillna(groups[column].transform('mean'), inplace = True)

        return df


def get_rows_greater_than_avg(df, column):
        """
        Return all the rows(with all columns) where the value in a certain 'column'
        is greater than the average value of that column.

        row where row.column > mean(data.column)

        Args:
                df: A pandas DataFrame object representing the data.
                column: Name of the column to fill
        Returns:
                df: Pandas DataFrame object.
        """
        # Return None incase of invalid parameters passed
        if(df.empty or column == None):
            return None

        return df[df[column] > df[column].mean()]      
    
