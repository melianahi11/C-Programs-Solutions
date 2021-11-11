#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int prime(int m) {
//condition if not prime
		if(m==2){
		 return 0;
		}	
		if(m<2) {
		 return 0;
		}

	for(int i=2; i<m; i++){
		if(m%i == 0) {
		 return 0;
		}
		
}
return 1;
	
}

/*int twinP(int m) {

	if(prime(m-2))
		return 1;
	if(prime(m+2))
		return 1;
	return 0;
		} */


int main(int argc, char* argv[argc+1]) {
	FILE* fp = fopen(argv[1], "r");
		if(fp==NULL) 
			return 0;

	int num;
		while(fscanf(fp, "%d ", &num) != EOF) {
			if((prime(num) && prime(num-2)) || (prime(num) && prime(num+2)))printf("yes\n");
			
			else printf("no\n");
		}
		return EXIT_SUCCESS;
}
