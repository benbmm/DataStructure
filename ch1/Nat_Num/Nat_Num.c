#include <stdio.h>
#include <limits.h>

typedef unsigned int Nat_Num;

Nat_Num Zero(){
	return 0;
	}

int Is_Zero(Nat_Num x){
	if(x){
		return 0;
	}
	else{
		return 1;
	}
}
Nat_Num Add(Nat_Num x,Nat_Num y){
	if(x+y <= INT_MAX){
		return x+y;
	}else{
		return INT_MAX;
	}
}
int Equal(Nat_Num x,Nat_Num y){
	if (x==y){
		return 1;
	}else{
		return 0;
	}
}
Nat_Num Successor(Nat_Num x){
	if (x==INT_MAX){
		return x;
	}else{
		return x+1;
	}
}
Nat_Num Subtract(Nat_Num x,Nat_Num y){
	if (x<y){
		return 0;
	}else{
		return x-y;
	}
}

int main() {
    Nat_Num a = 10, b = 5, c = INT_MAX;

    printf("Zero() = %u\n", Zero());
    printf("Is_Zero(0) = %d\n", Is_Zero(Zero()));
    printf("Is_Zero(5) = %d\n", Is_Zero(5));
    
    printf("Add(%u, %u) = %u\n", a, b, Add(a, b));
    printf("Add(%u, %u) = %u (should be INT_MAX)\n", c, 1, Add(c, 1));
    
    printf("Equal(%u, %u) = %d\n", a, b, Equal(a, b));
    printf("Equal(%u, %u) = %d\n", a, a, Equal(a, a));
    
    printf("Successor(%u) = %u\n", a, Successor(a));
    printf("Successor(%u) = %u (should be INT_MAX)\n", c, Successor(c));
    
    printf("Subtract(%u, %u) = %u\n", a, b, Subtract(a, b));
    printf("Subtract(%u, %u) = %u (should be 0)\n", b, a, Subtract(b, a));
	//dd
    return 0;
}