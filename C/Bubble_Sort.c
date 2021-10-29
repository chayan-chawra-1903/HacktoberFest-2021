#include <stdio.h>
int main()
{
int array[100], n, c, d, swap;
printf("Enter number of elements : ");
scanf("%d", &n);
printf("Enter %d integers : ", n);
for (c = 0; c < n; c++)
scanf("%d", &array[c]);
for (c = 0 ; c < n - 1; c++)
{
for (d = 0 ; d < n - c - 1; d++)
{
if (array[d] > array[d+1])
{
swap = array[d];
array[d] = array[d+1];
array[d+1] = swap;
}
}
}
printf("Sorted list in ascending order : ");
for (c = 0; c < n; c++)
printf("%d ", array[c]);
return 0;
}