import random 
list1 = range(1, 100) 
n = int(input("n = ")) 
print(n) 

for i in range(n):     
    for j in range(n):         
        if i == j:             
            print(0, end = ' ')         
        else:            
            print(random.choice(list1), end = ' ')          
    print()