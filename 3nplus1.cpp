#include<cstdio>
int main()
{
    int a,b,i,temp,cnt,MX=0, A, B;
    while(scanf("%d %d",&a,&b) != EOF)
    {
        A = a, B = b;
        MX = 0;
        if(a>b)
        {
            temp=a;
            a=b;
            b=temp;
        }
        for(i=a; i<=b; i++)
        {
            temp=i;
            cnt=1;
            while(temp != 1)
            {
                if(temp%2) {
                    temp = temp*3+1;
                    temp = temp >> 1;
                    cnt+=2;
                } else {
                    temp = temp >> 1;
                    cnt++;
                }

            }
            MX = (MX<cnt)?cnt:MX;
        }
        printf("%d %d %d\n",A, B, MX);
    }

}
