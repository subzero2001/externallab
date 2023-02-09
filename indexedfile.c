#include <stdio.h>
#include <stdlib.h>
#define max 100
int block[max];
void indexed();
void allocate(int fno);
void display(int n);


struct file
{
    int len;
    int start;
    
    int flag;
};

struct index
{
    int blockno[10];
    int blocklocation[10];
};

struct index in[20];
struct file f[20];





int main()
{
    int op;

   for(int i=0;i<max;++i)
   {
    block[i]=0;
   }


   while(1)
   {
    printf("MENU\n 1.indexed\n 2.exit\n");
    printf("enter your choice \n");
    scanf("%d",&op);
     

     switch(op)
     {
        case 1:
        indexed();
        break;
        case 2 :
        exit(0);
        default:
        printf("invalid choice try again\n");

     }
    
   }

    return 0;
}

void indexed()
{
     int occupied,usedblock,n;
    printf("Enter the no of blocks already occupied\n");
    scanf("%d",&occupied);
    for(int i=0;i<occupied;++i)
      {
        printf("enter the %dst block",i+1);
        scanf("%d",&usedblock);
        block[usedblock]= 1;
      }


   printf("enter the no of files: ");
   scanf("%d",&n);
   for(int i=0;i<n;++i)
   {
       printf("enter the starting block: ");
       scanf("%d",&f[i].start);
       printf("enter the length of the block: ");
       scanf("%d",&f[i].len);
        
        allocate(i);



   }  

   display(n);


}


void allocate(int fno)
{
    

    int n=0,count=0;
    
     if(block[f[fno].start]==1)
     {
        f[fno].flag = 1;
        
     }

else
{

    for(int i=0;i<max;++i)
    {
         if(block[i]==0)
         {
            ++count;
             if(count==f[fno].len)
               break;

         }   
       printf("count value :%d\n",count);
    }

    if(count==f[fno].len)
    {
               f[fno].flag = 0;

          while(n<f[fno].len)
          {
             for(int i=f[fno].start;i<max;++i)
             {
                   if(block[i]==0)
                      {    
                           
                             block[i]=1;
                             in[fno].blockno[n]=n;
                             in[fno].blocklocation[n]=i;
                             break;
                          }   
             }

             ++n;

          }
    }
   
   else
   {
     f[fno].flag = 1;   

   }


}
}


void display(int n)
{

     printf("File No.\tStarting block\tLength\tStatus\n");
    for(int i=0;i<n;++i)
    {
        if(f[i].flag==0)
        {

            printf("%d\t%d\t%d\t Allocated\n",i+1,f[i].start,f[i].len);
        }
        else
        {
            printf("-\t-\t-\t UnAllocated\n");
        }
    }

  

  for(int i=0;i<n;++i)
  {
       if(f[i].flag==0)
       {
        printf("the index block for file %d\n",i+1);
           printf("blockno\t  blocklocation\n");
           for(int j=0;j<f[i].len;++j)
           {
               printf("%d\t %d\t",in[i].blockno[j],in[i].blocklocation[j]);
           }
       }
  }
    

}