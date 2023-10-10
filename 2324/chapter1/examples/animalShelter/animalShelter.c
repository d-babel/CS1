

#include <stdio.h>

int main() {
    int n, weeks;
    float a;
    printf("Number of animals: ");
    scanf("%d", &n);
    printf("Adoption rate: ");
    scanf("%f", &a);
    printf("Weeks: ");
    scanf("%d", &weeks);

    int total = 0;
    for (int i = 1; i <= weeks; i++) {
        int adopted = (int)(n * a);
        printf("Week %d: %d animals adopted\n", i, adopted);
        total += adopted;
        n = adopted; // Update the number of animals available for adoption
    }

    printf("Total animals adopted after %d weeks: %d\n", weeks, total);

    return 0;
}
