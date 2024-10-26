#include <stdio.h>
#include <math.h>

int num_divs(int a)
{
    int num=0;
    for (int i = 1; i < a+1 ; i++)
    {
        if (a%i==0)
        {
            num=num+1;
        }
    }
    return num;
}

int main()
{
    int a , i=1 ;
    scanf("%d" , &a );
    while (i>0)
    {
        int n=(i*(i+1))/2;
        if (num_divs(n) >=a )
        {
            printf("%d" , n);
            break;
        }
        i++;
    }
    
}
