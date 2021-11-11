#include <stdlib.h>
#include <stdio.h>

//i need two forloops, one for the input and another for the output

int inputOutput(int input, int output, int num1, int num2) {
	int m = 1;
	for(int i=0; i< input;i++){
		num1 =num1%2;
		num2 = (num2%2);
		int sum = num1+ num2;
		
		output += m* sum;
		num1 = num1/2;
		num2 = num2/2;
		m = 2*m;
	}
	
}
	
 
int main(int argc, char* argv[argc+1]) {
	
	int a, b , num1 , num2;
	scanf("%d %d %d %d\n", &a, &b, &num1, &num2);
		inputOutput(a, b, num1, num2);

	char printOutput[output];
	for(int i=output-1; i>=0; i--){
		if(output%2 ==1)
			printOutput[i] = '1';
		else
			printOutput[i] ='0';
		output = output/2;
		 }	

	if(for(int i=0; i<output; i++) {
		printf("%c\n", printOutput[i]);
	}
	else{
		printf("OVERFLOW\n");
		}
	}	

return EXIT_SUCCESS;
}



	

	
