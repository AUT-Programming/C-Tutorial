#include <stdio.h>
#include<math.h>


int is_prime(int a)
{
    if (a==1)
    {
        return 0;
    }
    
    for (int i = 2; i <= sqrt(a) ; i++)
        {
            if (a%i == 0)
            {
                return 0;
            }
        }
        return 1;
}    
        
    
int main()
{
    int a,b;
    scanf("%d%d" , &a , &b );
    for (int i = a ; i < b+1 ; i++)
        {
            if (is_prime(i))
            {
                printf("%d\n" , i);
            }
        }    
}
