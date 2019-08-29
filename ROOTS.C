#include <stdio.h>
#include <conio.h>
#include <math.h>
void main()
{
	FILE *p, *q;
	float a, b, c, d, sqrt_d;
	char fm[3];
	clrscr();
	printf("Do you want to use file management or not ? Please type in yes or no:\n");
	scanf("%s", &fm);
	if(fm[0]=='n'){
		printf("-> Not using file management");
		printf("\nPlease enter the coefficients of X^2, X and X^0:\n");
		scanf("%f", &a);
		scanf("%f", &b);
		scanf("%f", &c);
		printf("\nThe equation is : %.2fX^2 + %.2fX + %.2f", a, b, c);
		d = b*b-4*a*c;
		if(d<0){
			printf("\nRoots are Imaginary");
		}else{
			sqrt_d = sqrt(d);
			printf("\nThe roots are: %f and %f", (-1.0*(float)b+sqrt_d)/(2*(float)a),(-1.0*(float)b-sqrt_d)/(2*(float)a));
		}
	}else{
		printf("-> Using file management");
		p = fopen("d_roots.dat", "r");
		q = fopen("o_roots.rsl", "w");
		fscanf(p, "%f %f %f", &a, &b, &c);
		fprintf(q, "\nThe equation is : %.2fX^2 + %.2fX + %.2f", a, b, c);
		d = b*b-4*a*c;
		if(d<0){
			fprintf(q, "\nRoots are Imaginary");
		}else{
			sqrt_d = sqrt(d);
			fprintf(q, "\nThe roots are: %f and %f", (-1.0*(float)b+sqrt_d)/(2*(float)a),(-1.0*(float)b-sqrt_d)/(2*(float)a));
		}
	}
	getch();
}