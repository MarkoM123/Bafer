#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int rows, cols;
    cout << "Broj redova:" << endl;
    cin >> rows;
    cout << endl << "Broj kolona:" << endl;
    cin >> cols;

    int N = 10000;

    int M[rows][cols];

    for (int i=0; i<rows; i++)
        for (int j=0; j<cols; j++)
            M[i][j]=0;

    for (int i=0; i<rows; i++)
    {
        int N_ulaz = (int)((N/rows)*(double)(rand()/(double)RAND_MAX));
        int n=N_ulaz;
        int j=0;

        while (N_ulaz>0)
        {
            if (i!=j)
            {
                M[i][j]+=1;
                N_ulaz--;
            }
            else
            {
                M[i][j]+=n/2;
                N_ulaz-=n/2;
            }

            if (j==cols-1) j=0;
            else j++;
        }
    }

    for (int i=0; i<cols; i++)
    {
        int sum=0;
        int k=i;
        for (int j=0; j<rows; j++)
            sum += M[j][i];
        cout << "Ukupan broj paketa na izlazu " << ++k << ": " << sum << endl << endl;
    }
    return 0;
}
