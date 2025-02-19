#include <stdio.h>
#include <string.h>
void find(char *dna,char *pattern) 
{
    int count=0;
    char *ptr=dna;
    int Len=strlen(pattern);
    
    while ((ptr = strstr(ptr, pattern))!=NULL)
    {
        count++;
        ptr=ptr+Len; 
    }
    printf("Pattern found %d time(s) in the dna sequence\n",count);
}
int main()
{
    char dna[100],pattern[100];
    printf("enter dna Sequence: ");
    scanf("%s",dna);
    printf("enter pattern to search: ");
    scanf("%s",pattern);
    find(dna, pattern);
    return 0;
}
