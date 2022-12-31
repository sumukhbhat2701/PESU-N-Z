
/* Arrays in java are dynamically allocated. 
->arrays are objects in Java, 
->can find their length using the object property length. 

A Java array variable can also be declared like other variables with [] after the data type.
index beginning from 0.

The direct superclass of an array type is Object.

An array can contain primitives (int, char, etc.) and object (or non-primitive) references of a class depending on
the definition of the array. 
In the case of primitive data types, the actual values are stored in contiguous memory locations. 
In the case of class objects, the actual objects are stored in a heap segment. 
Declaration of an array:

type var-name[];
OR
type[] var-name;

int intArray[]; 
or int[] intArray; 

int[] m; or int m[];

Instantiation of an Array:
When an array is declared, only a reference of an array is created. 
To create or give memory to the array, you create an array like this
var-name = new type [size];
*/



import java.util.*;

class student
{
int srn;
int marks;
}



class arr
{
public static void main(String args[])
{
int n;

student[] s=new student[10];

System.out.println("Enter the size of the array");
Scanner in = new Scanner(System.in);

n=in.nextInt();

for(int i=0;i<n;i++)
{
s[i]=new student();
}



//s[0].srn=20;
//s[0].marks=100;





System.out.println("Enter the values");
for(int i=0;i<n;i++)
{
s[i].srn=in.nextInt();
s[i].marks=in.nextInt();
}

System.out.println("Details of students");
for(int i=0;i<n;i++)
{
System.out.println(s[i].srn);
System.out.println(s[i].marks);
}
}
}