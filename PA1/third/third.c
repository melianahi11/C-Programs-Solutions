#include <stdlib.h>
#include <stdio.h>
#include <string.h>



int getParity(unsigned int n) {
	int parity =0;
	while(n){
		parity = !parity;
		n = n & (n-1);
	}
	return parity;
}

int getPairs(unsigned int n){
	int pairs = 0;
	int count = 0;

	while(n) {
		if(n&1){
		count++;
	}
	else{
		count = 0;
	}
	if(count ==2) {
		pairs++;
		count = 0;
	}
	n= n>>1;
}
return pairs;
}


int main(int argc, char *argv[]){
unsigned short num;
	sscanf(argv[1],"%hu", &num);

	int parity = getParity(num);
	int pairs = getPairs(num);
	
	if(parity ==0) {
		printf("%s\t%d\n", "Even-Parity", pairs);
	}
	else{
		printf("%s\t%d\n", "Odd-Parity", pairs);

	}
return EXIT_SUCCESS;
}







