#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &vec, int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;

    vector<int> arr1, arr2;
    for (int i = 0; i < n1; i++)
        arr1.push_back(vec[l + i]);

    for (int i = 0; i < n2; i++)
        arr2.push_back(vec[mid + 1 + i]);
    
    int i = 0, j = 0, k = l;
    while (i < n1 and j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            vec[k] = arr1[i];
            k++;
            i++;
        }
        else
        {
            vec[k] = arr2[j];
            k++;
            j++;
        }
    }
    while (i < n1)
    {
        vec[k] = arr1[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        vec[k] = arr2[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &vec, int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;

        mergeSort(vec, l, mid);
        mergeSort(vec, mid + 1, r);

        merge(vec, l, mid, r);
    }
}
int main()
{
    int n;
    cin >> n;

    vector<int> vec(n);
    for (auto &i : vec)
        cin >> i;
    mergeSort(vec, 0, n - 1);
    for (auto &i : vec)
        cout << i << " ";

    return 0;
}