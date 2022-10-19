// BUBBLE SORT

#include <stdio.h>

void take(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}

void print(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void bubbleSort(int *a, int n)
{
    int temp = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter size of Array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements in an Array: ");
    take(a, n);
    bubbleSort(a, n);
    printf("Sorted Array is: ");
    print(a, n);
    return 0;
}




