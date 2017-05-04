#include <stdio.h>
#include "operators.h"
typedef float (*calcFunctionPointer) (float, float);

float calculator (float operand1, float operand2, calcFunctionPointer calc) {
	return calc (operand1, operand2) ;
}

int main(){
	FILE *fp = NULL;
	calcFunctionPointer calc = NULL;
	float operand1, operand2;
	char operator = ' ';
	float result = 0;
	int line = 0;

	fp = fopen("read.txt","r");
	if(fp!=NULL){
		fscanf(fp, "%d", &line);
		
		for(int i=0; i<line; i++) {
			fscanf(fp, "%f %c %f",&operand1, &operator, &operand2);
			if(operator == ' ') {
				return 0;
			}
			switch(operator) {
				case '+':
				calc = add;
				break;
				case '-':
				calc = minus;
				break;
				case '*':
				calc = mul;
				break;
				case '/':
				calc = div;
				break;
			}
			result = calculator (operand1, operand2, calc);
		
			printf("%.0f %c %.0f = %.5f\n",
				 operand1, operator, operand2, result);
			operand1 = 0;
			operator = ' ';
			operand2 = 0;
			result = 0;
		}
	}
	return 0;
}

