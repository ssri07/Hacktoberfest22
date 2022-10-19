// SELECTION SORT

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

void selectionSort(int *a, int n)
{
    int indexOfMin = 0, temp = 0;
    for (int i = 0; i < n-1; i++)
    {
        indexOfMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[indexOfMin] > a[j])
            {
                indexOfMin = j;
            }
        }
        temp = a[indexOfMin];
        a[indexOfMin] = a[i];
        a[i] = temp;
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
    printf("Unsorted Array is: ");
    print(a, n);
    selectionSort(a, n);
    printf("Sorted Array is: ");
    print(a, n);
    return 0;
}