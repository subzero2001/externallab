#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct{
    char dirname[10], fname[10][10];
    int fcnt;
}dir;
void main()
{
    dir.fcnt = 0;
    int opt;
    char fnametemp[25];
    printf("Enter the name of directory: ");
    scanf("%s", &dir.dirname);
    printf("\n1.Create a file. \n2.Delete a file \n3.Search for a file. \n4.Display files \n5.Exit\n");
    while(1)
    {
    printf("Enter your choice: ");
    scanf("%d", &opt);
        switch(opt)
        {
            case 1: printf("Enter the name of the file: ");
                    scanf("%s", &dir.fname[dir.fcnt]);
                    dir.fcnt++;
                    break;
            case 2: printf("Enter the name of the file to be deleted: ");
                    scanf("%s", &fnametemp);
                    int i;
                    for(i = 0; i < dir.fcnt; i++)
                    {
                        if(strcmp(fnametemp, dir.fname[i]) == 0)
                        {
                            printf("File %s is deleted...\n", fnametemp);
                            strcpy(dir.fname[i], dir.fname[dir.fcnt -1]);
                            break;
                        }
                    }
                    if(i == dir.fcnt)
                    {
                        printf("File %s not found.\n", fnametemp);
                    }
                    else
                        dir.fcnt--;
                    break;
            case 3: printf("Enter the file to be searched: ");
                    scanf("%s", &fnametemp);
                    int flag = 0;
                    for(int i = 0; i < dir.fcnt; i++)
                    {
                        if(strcmp(fnametemp, dir.fname[i]) == 0)
                        {
                            flag = 1;
                            printf("File Found!!\n");
                            break;
                        }
                    }
                    if(i == dir.fcnt)
                    {
                        printf("File not found..\n");
                    }
                    break;
            case 4: if(dir.fcnt == 0)
                    {
                        printf("Empty Directory..\n");
                    }
                    else
                    {
                        printf("The files are: \n");
                        for(int i = 0; i < dir.fcnt; i++)
                        {
                            printf("%s\n", dir.fname[i]);
                        }
                    }
                    break;
            default: exit(0);
        }
    }
}