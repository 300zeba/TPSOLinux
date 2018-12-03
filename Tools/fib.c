#include <stdio.h>
#include <stdlib.h>


int fib(int n){
	if(n==1 || n==0){
		return 1;
	}
	return (fib(n-1) + fib(n-2));
}

int main(){
	printf("%d\n",fib(50));
	return 0;
}
