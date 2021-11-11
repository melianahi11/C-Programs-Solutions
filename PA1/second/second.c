#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void get(unsigned short x, int n){
	printf("%d\n", (x >> n) & 1);
}
	
unsigned short comp(unsigned short x, int n){
	unsigned short getcomp = x ^ (1 << n);
	printf("%hd\n", getcomp);
		return getcomp;
}

unsigned short set(unsigned short x, int n, int v){
	unsigned short setnum = ((x & (~(1 << n))) | (v << n));
	printf("%hd\n", setnum);
		return setnum;
}

int main(int argc, char* argv[argc+1]) {
	FILE* fp = fopen(argv[1], "r");
		
unsigned short num;
	(fscanf(fp,"%hd\n", &num)); 

char str_in[20] = "";
int n1;
int n2;
	while(fscanf(fp,"%s%d%d\n", str_in, &n1, &n2) != EOF) {
		if(strcmp(str_in, "get") == 0) {
			get(num,n1);
		}
		if(strcmp(str_in, "comp") == 0) {
			num = comp(num,n1);
		}
		if(strcmp(str_in, "set") == 0) {
			num = set(num,n1,n2);
		}	
		
	}
return EXIT_SUCCESS;
}




