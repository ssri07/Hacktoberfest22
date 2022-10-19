/*In this we are at the starting point of the grid i.e at (0,0) and we have to move it to the other
end i.e at (n-1,n-1) position*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int countPathGrid(int n, int i, int j)
{
    if (i == n - 1 && j == n - 1) /// when we reach at the end
        return 1;

    if (i >= n || j >= n) // if we go beyong the size then return 0
        return 0;

    // either we move in positive x direction or we move in downward y direction
    return countPathGrid(n, i + 1, j) + countPathGrid(n, i, j + 1);
}

int main()
{
    cout << countPathGrid(3, 0, 0);
    return 0;
}