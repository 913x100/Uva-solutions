#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int m, n;

    while(1)
    {
        scanf("%d %d", &n, &m);
        if (m == 1 && n == 1) return 0;

        int a[6] = {0, 1, 1, 0, 1, 1};

        while(1)
        {
            int A = a[4], B = a[5];
            if(A == n && B == m) break;
            int t1 = A*m, t2 = B*n;

            if(t1 <= t2)
            {
                a[0]=A;
                a[2]=B;
                cout<<"R";
            }
            else
            {
                a[1]=A;
                a[3]=B;
                cout<<"L";
            }
            a[4] = a[0]+a[1];
            a[5] = a[2]+a[3];
        }
        cout<<endl;
    }
    return 0;
}
