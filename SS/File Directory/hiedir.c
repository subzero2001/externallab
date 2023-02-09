#include<stdio.h>
#include<stddef.h>
void main()
{
        char d[50][50][50],f[50][50][50][50];
        int o[10];
        int i,m,n[30][30],j,k;
        printf("Enter the number of directories of ROOT :");
        scanf("%d",&m);
        for(i=1;i<=m;i++)
        {
                printf("Enter the number of all subdirectories in directory %d :",i);
                scanf("%d",&o[i]);
                for(j=1;j<=o[i];j++){
		printf("Enter the number of files in the subdirectory %d of %d : ",j,i);
		scanf("%d",&n[i][j]);}
        }
        printf("Enter the name of the ROOT : ");
        scanf("%s",d[0][0]);
        for(i=1;i<=m;i++)
        {
                printf("Enter the name of Main Directory %d : ",i);
                scanf("%s",d[i][0]);
        }
        for(i=1;i<=m;i++)
        {	
		printf("Enter the name of the subdirectories of %d :",i);
		for(j=1;j<=o[i];j++)
		{
			scanf("%s",d[i][j]);
		}
	}
	i=0;
	for(i=1;i<=m;i++)
	{  for(j=1;j<=o[i];j++)
	   {  printf("Enter the name of the files in folder %d of %d :",j,i);
	       for(k=1;k<=n[i][j];k++)
		scanf("%s",f[i][j][k]);
		
           }						 
       }
        printf("The directory structure\n");
        printf("The ROOT : \t            %s \n",d[0][0]);
        for(i=1;i<=m;i++)
        {
                printf("\nThe Directory %d :%s\n",i,d[i][0]);                
                for(j=1;j<=o[i];j++)
                { printf("\nSubdirectory %d: %s ",j,d[i][j]);
		  printf("\nFiles:");
		  for(k=1;k<=n[i][j];k++)
		    printf("%s ",f[i][j][k]);		                        
                }
        }
 printf("\n");
}
