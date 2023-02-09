#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct{
    char dirname[10], fname[10][10];
    int fcnt;
}dir[10];
void main()
{
    int opt;
    int dcnt = 0;
    char fnametemp[25], dirtempname[25];
    printf("\n1. Create a directory \n2.Create a file. \n3.Delete a file \n4.Search for a file. \n5.Display files \n6.Exit\n");
    while(1)
    {
    printf("Enter your choice: ");
    scanf("%d", &opt);
        switch(opt)
        {
            case 1: printf("Enter the name of directory: ");
                    scanf("%s", &dir[dcnt].dirname);
                    dir[dcnt].fcnt = 0;
                    dcnt++;
                    printf("Directory created. \n");
                    break;
            case 2: printf("Enter the name of the directory: ");
                    scanf("%s", &dirtempname);
                    int i;
                    for(i = 0; i < dcnt; i++)
                    {
                        if(strcmp(dirtempname, dir[i].dirname) == 0)
                        {
                            printf("Enter the name of the file: ");
                            scanf("%s", &dir[i].fname[dir[i].fcnt]);
                            dir[i].fcnt++;
                            printf("File created..\n");
                            break;
                        }
                    }
                    if(i == dcnt)
                        printf("Directory %s not found. \n", dirtempname);
                    break;
            case 3: printf("Enter the name of the directory: ");
                    scanf("%s", &dirtempname);
                    for(i = 0; i < dcnt; i++)
                    {
                        if(strcmp(dirtempname, dir[i].dirname) == 0)
                        {
                            printf("Enter the name of the file to be deleted: ");
                            scanf("%s", &fnametemp);
                            int k;
                            for(k = 0; k < dir[i].fcnt; k++)
                            {   
                                if(strcmp(fnametemp, dir[i].fname[k]) == 0)
                                {
                                    printf("File %s is deleted...\n", fnametemp);
                                    strcpy(dir[i].fname[k], dir[i].fname[dir[i].fcnt]);
                                    dir[i].fcnt--;
                                    goto jmp;
                                }
                            }
                            if(k == dir[i].fcnt)
                            {
                                printf("File %s not found.\n", fnametemp);
                                goto jmp;
                            }
                        }
                    }
                    printf("Directory not found..\n");
                    jmp: break;
            case 4: printf("\nEnter name of the directory : ");
                    scanf("%s",&dirtempname);
                    for(i = 0; i < dcnt; i++)
                    {
                        if(strcmp(dirtempname,dir[i].dirname)==0)
                        {
                            printf("Enter the file to be searched: ");
                            scanf("%s", &fnametemp);
                            int flag = 0;
                            int k;
                            for(k = 0; k < dir[i].fcnt; k++)
                            {
                                if(strcmp(fnametemp, dir[i].fname[k]) == 0)
                                {
                                    flag = 1;
                                    printf("File Found!!\n");
                                    goto jmp1;
                                }
                            }
                            if(k == dir[i].fcnt)
                            {
                                printf("File not found..\n");
                                goto jmp1;
                            }
                        }
                    }
                    printf("Directory %s not found",dirtempname);
                    jmp1: break;
            case 5: if(dcnt == 0)
                    {
                        printf("No directory..\n");
                    }
                    else
                    {
                        printf("\nDirectories\tFiles");
                        for(int i = 0; i < dcnt; i++)
                        {
                            printf("\n%s\t\t", dir[i].dirname);
                            for(int k = 0; k < dir[i].fcnt; k++)
                            {
                                printf("\t%s", dir[i].fname[k]);
                            }
                            printf("\n");
                        }
                    }
                    break;
            default: exit(0);
        }
    }
}