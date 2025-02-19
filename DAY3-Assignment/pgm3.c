#include <stdio.h>
int main() 
{
    int n,i,sum=0;
    printf("Enter number of matches:");
    scanf("%d",&n);
    int scores[n];
    printf("Enter scores of %d matches:",n);
    for (i=0;i<n;i++) 
    {
        scanf("%d",&scores[i]);
    }
    int highest=scores[0];
    int lowest=scores[0];
    for (i=0;i<n;i++)
    {
        if (scores[i]>highest) {
            highest=scores[i];
        }
        if (scores[i]<lowest) {
            lowest = scores[i];
        }
        sum=sum+scores[i];
    }
     float average = (float)sum / n;
    printf("\nHighest Score: %d\n",highest);
    printf("Lowest Score: %d\n",lowest);
    printf("Average Score: %.2f\n",average);
    return 0;
}
