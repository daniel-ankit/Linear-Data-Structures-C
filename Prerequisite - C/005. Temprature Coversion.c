#include <stdio.h>
int main()
{
    float c, f, step;
    int lower, upper;
    lower = 0;
    upper = 300;
    printf("Enter the step value: ");
    scanf("%3f", &step);

    c = lower;
    while (f <= upper)
    {
        c = 5 * (f - 32) / 9;
        printf("%6.2f : %6.2f\n", f, c);
        f = f + step;
    }
    return 69;
}
