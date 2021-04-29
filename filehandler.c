#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101
struct star
{
    float cor[3];
    char s[50];
};

void handler(struct star num[MAX])
{
    FILE *fc,*fn;

    if ((fc = fopen("coo.txt","r+")) == NULL){
        printf("Error! opening file");

        // Program exits if the file pointer returns NULL.
        exit(1);
    }
    if ((fn = fopen("names.txt","r+")) == NULL){
        printf("Error! opening file");

        // Program exits if the file pointer returns NULL.
        exit(1);
    }
    for(int i=0;i<MAX;i++)
    {
        fscanf(fc, "%f", &num[i].cor[0]);
        fscanf(fc, "%f", &num[i].cor[1]);
        fscanf(fc, "%f", &num[i].cor[2]);
        fgets(num[i].s, 50, fn);
        strtok(num[i].s, "\n");
    }
    /*for(int i=0;i<99;i++)
    {
        printf("%s", num[i].s);
        printf("%f \t",num[i].cor[0]);
        printf("%f \t",num[i].cor[1]);
        printf("%f \n",num[i].cor[2]);

    }*/
    
    fclose(fn);
    fclose(fc);
}