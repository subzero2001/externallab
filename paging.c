#include<stdio.h>
void main()
{
    int s[10], fno[10][20];
    int ms,ps,nop,np;
    int pno,page,off;
    int pa;
    printf("Enter the memory size: ");
    scanf("%d", &ms);
    printf("Enter the number of pages: ");
    scanf("%d", &ps);
    nop = ms/ps;
    printf("The number of pages available in memory are: %d\n", nop);
    printf("Enter the number of processes: ");
    scanf("%d", &np);
    int remsize = nop;
    for(int i = 1; i <= np; i++)
    {
        printf("Enter the number of pages required for the proccess %d: ", (i));
        scanf("%d", &s[i]);
        if(s[i] > remsize)
        {
            printf("Memory is full..\n");
            break;
        }
        remsize = remsize - s[i];
        printf("Enter the pagetable for the process %d: ", i);
        for(int j = 0; j < s[i]; j++)
        {
            scanf("%d", &fno[i][j]);
        }
    }
    printf("Enter the processNo, pagenumber and offset: ");
    scanf("%d%d%d", &pno, &page, &off);
    if(pno > nop || off>ps)
        printf("INVAID INPUT\n");
    else{
        pa = fno[pno][page] * ps + off;
        printf("The physical address is --> %d\n", pa);
    }
}