import random


#Main program starts here
uppercaseLetter=['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'M', 'N', 'O', 'p', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
lowercaseLetter=['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
digits=['0', '1','2','3','4','5','6','7','8','9',]

choose_option=uppercaseLetter+lowercaseLetter+digits

print('Min length is 8.')

n=int(input('Password Length: '))

rand_digit = random.choice(digits)
rand_upper = random.choice(uppercaseLetter)
rand_lower = random.choice(lowercaseLetter)


password=rand_digit+rand_upper+rand_lower

for i in range(n-3):
    password=password+random.choice(choose_option)
    
    
    
    
""" shuffle function works only on list hence convert the password string into list and then apply random.shuffle
"""    
convert_list=list(password)
random.shuffle(convert_list)
    
res=''
    
for i in convert_list:
    res=res+i

#Ouput
print(res)
