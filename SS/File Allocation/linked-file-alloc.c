#include<stdio.h>
#include<stdlib.h>
void main()
{
    int f[50],a,n,st,len,k,c;
    for(int i = 0; i < 50; i++)
        f[i] = 0;
    printf("Enter the number of blocks already occupied: ");
    scanf("%d", &n);
    printf("Enter the blocks that are occupied: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        f[a] = 1;
    }
    x: printf("Enter the index starting block and length: ");
    scanf("%d%d", &st, &len);
    k = len;
    if(f[st] == 0)
    {
        for(int j = st; j < (st+k); j++)
        {
            if(f[j] == 0)
            {
                f[j] = 1;
                printf("%d ----------> %d\n", j, f[j]);
            }
            else
            {
                printf("Block is already allocated \n");
                k++;
            }
        }
    }
    else
    {
        printf("%d starting block is already allocated \n", st);
    }
    printf("Do you want to enter more file? (1 -> Yes / 0 -> No)");
    scanf("%d", &c);
    if(c == 1)
        goto x;
    else
        exit(0);
}