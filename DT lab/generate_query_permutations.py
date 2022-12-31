from itertools import permutations 
l = ['buyers', 'other_info', 'buyers_address', 'ph_no_customers']
p = permutations(l)
for i in p:
	print('explain analyze select * from '+i[0]+' natural join '+i[1]+' natural join '+i[2]+' natural join '+i[3]+';')
	
x = [1,2,3,4]
x1 = permutations(x)
for i in x1:
	print(i)
