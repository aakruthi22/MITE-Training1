#include <stdio.h>
void displayages(short int ages[], int size, int i) {
    if (i==size) {
        return;
    }
    printf("Age %d: %d\n", i+1, ages[i]);
    displayages(ages,size,i+1); 
    }
int main(){
    short int ages[]={45,34,79,80}; 
    displayages(ages,4,0);
    return 0;
}
