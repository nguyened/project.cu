#include <stdio.h>

int main() {

	int a;
	int b;
	int c;
	int count;
	int input = 0;
	int *x = &input;
	int select = 0;
	int *y = &select;

	start:
	a = 1;
	b = 1;
	count = 0;
	x = NULL;
	y = NULL;



	printf("enter a 'n' value:\n");
	scanf("%d", &input);
	if (input < 1) {
		printf("invalid 'n' value\n");
		goto start;
	}

	printf("%d, ",a);
	if (input == 1) {
			printf("\n");
			goto again;
	}

	printf("%d, ",b);
	if (input == 2) {
			printf("\n");
			goto again;
	}

	while(count < input-2)
	{
		c = a+b;
		printf("%d, ",c);
		a=b;
		b=c;
		count++;
	}
	printf("\n");

	again:
	printf("continue? (1=yes, 0=no)\n");
	scanf("%d", &select);
	if(select == 1){
		goto start;
	} else if (select == 0){
		return 0;
	}	else {
		printf("invalid, try again\n");
		goto again;
	}

	return 0;
}
