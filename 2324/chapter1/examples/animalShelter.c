// Animal Shelter by Drew Babel

#include <stdio.h>

int main()
{
    int n, weeks, total;
    float a;
    printf("Number of animals: ");
    scanf("%d", &n);
    printf("Adoption rate: ");
    scanf("%f", &a);
    printf("Weeks: ");
    scanf("%d", &weeks);

    for(int i = 1; i <= weeks; i++) {
        printf("Week %d: %d animals adopted\n", i, (int)(n *= a));
        total += (int)n;
    }
    printf("Total animals adopted after %d weeks: %d\n", weeks, total);
}