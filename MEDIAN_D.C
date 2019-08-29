#include <stdio.h>
#include <conio.h>

void main()
{
	FILE *p, *q;
	char file_mgmt[3];
	int n, i, j;
	float arr[100], k, median;
	clrscr();
	printf("Do you want to use File management or not ? (yes or no) :\n");
	scanf("%s", &file_mgmt);
	if(file_mgmt[0] == 'n'){
		/* Making the array */
		printf("Please enter the size of the array (size < 100): \n");
		scanf("%d", &n);
		printf("Now please enter %d numbers for the array:\n", n);
		for(i=0;i<n;i++){
			scanf("%f", &arr[i]);
		}
		printf("\n This is the array that you have inputted:\n");
		for(i=0;i<n;i++){
			printf("%.2f ", arr[i]);
		}
		/* Sorting the array */
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				if(arr[j]<arr[i]){
					k = arr[j];
					arr[j]= arr[i];
					arr[i] = k;
				}
			}
		}
		printf("\n And this is the sorted array:\n");
		for(i=0;i<n;i++){
			printf("%.2f ", arr[i]);
		}
		/*Finding the Median*/
		if((n%2)==0){
			median = (arr[(n/2)-1] + arr[(n/2)])/2;
		}else{
			median = arr[(n+1)/2-1];
		}
		printf("\nThe median (upto 3 decimal points) is: %.3f", median);
	}else{
		p = fopen("d_med_d.dat","r");
		q = fopen("o_med_d.rsl", "w");
		/* Making the array */
		printf("Please enter the number of numbers you want to use from the file (size < 100): \n");
		scanf("%d", &n);
		for(i=0;i<n;i++){
			fscanf(p,"%f", &arr[i]);
		}
		fprintf(q, "\n This is the array:\n");
		for(i=0;i<n;i++){
			fprintf(q, "%.2f ", arr[i]);
		}
		/* Sorting the array */
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				if(arr[j]<arr[i]){
					k = arr[j];
					arr[j]= arr[i];
					arr[i] = k;
				}
			}
		}
		fprintf(q, "\n And this is the sorted array:\n");
		for(i=0;i<n;i++){
			fprintf(q, "%.2f ", arr[i]);
		}
		/*Finding the Median*/
		if((n%2)==0){
			median = (arr[(n/2)-1] + arr[(n/2)])/2;
		}else{
			median = arr[(n+1)/2-1];
		}
		fprintf(q, "\nThe median (upto 3 decimal points) is: %.3f", median);
	}
	getch();
}






