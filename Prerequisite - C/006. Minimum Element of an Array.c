#include<stdio.h>
int main()

{
    int A[3],min;
    printf("Enter the Numbers: ");
    for(int i=0;i<3;i++)
    scanf("%d", &A[i]);
    min=A[0];
    for(int i=0;i<3;i++)
        {
        if(A[i] < min)
        min = A[i];
        }
    printf("The smallest Number is: %d.", min);
    return 69;
}
