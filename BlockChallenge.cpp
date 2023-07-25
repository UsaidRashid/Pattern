#include <iostream>
#include <conio.h>

using namespace std;

int A[10000][10000];

void PATTERN(int n, int c1, int c2, int k, int f)
{ 
    if (n == 1)
    {
        A[c1][c2] = n;
    }
    if (n > 1)
    {

        for (int i = c1, j = c2; j < k; j++)
        {
            A[i][j] = n;
        }
        for (int i = c1, j = c2; i < k; i++)
        {
            A[i][j] = n;
        }
        for (int j = c2, i = (k)-1; j < k; j++)
        {
            A[i][j] = n;
        }
        for (int i = c1, j = (k)-1; i < k; i++)
        {
            A[i][j] = n;
        }
        n--;
        c1++;
        c2++;
        k = 2 * n - 1;
        f++;
        k = k + f;
        PATTERN(n, c1, c2, k, f);
    }
    else
    {
        return;
    }
}

int main()
{
    void PATTERN(int, int, int, int, int);
    int n, i, j, c1 = 0, c2 = 0, k, f = 0;
    cout << "ENTER THE OUTERMOST BLOCK ELEMENT \n";
    cin >> n;
    k = 2 * n - 1;
    PATTERN(n, c1, c2, k, f);
    for (i = 0; i < 2 * n - 1; i++)
    {
        cout << endl;
        for (j = 0; j < 2 * n - 1; j++)
        {
            cout << A[i][j];
        }
    }
    getch();
}