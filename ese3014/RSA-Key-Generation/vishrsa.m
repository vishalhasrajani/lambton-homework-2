P = 113; #just a random prime number 

Q = 131; #just a random prime number 

e = 0; #setting default value of e to 0

d_mod = 0; 

d = 0;

n = P * Q;
Phi = (P - 1) * (Q - 1);
  

 for j = 3 : 1 : Phi - 1  #for loop till (Phi-1) with a increment of 1
    if gcd(j, Phi) == 1  # If HCF of j and Phi is equal to 1 then e is coprime with Phi
       e = j;  #e is coprime with Phi
       break
    end
 end
    

while(d_mod~=1)  #Finding the value of d until d_mod is not equal to 1
d = d+1; # Using it like a counter 
d_mod = mod((e*d),Phi); # Finding mod of e*d and Ph1
endwhile


printf("PUBLIC KEY is (n,e)----------->(%d,%d)\n",n,e); #printing out the values of public key 
printf("PRIVATE KEY is (n,d)----------->(%d,%d)\n",n,d);#printing out the values of private key 
