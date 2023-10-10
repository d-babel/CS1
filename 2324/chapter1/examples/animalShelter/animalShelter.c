#include <stdio.h>
#include <math.h>

int main() {
    int initialAdoptions, totalWeeks;
    float adoptionRate;

    printf("Number of animals: ");
    scanf("%d", &initialAdoptions);
    printf("Adoption rate: ");
    scanf("%f", &adoptionRate);
    printf("Weeks: ");
    scanf("%d", &totalWeeks);

    int cumulativeTotal = 0;
    for (int week = 1; week <= totalWeeks; week++) {
        int roundedAdoptions = (int)floor(initialAdoptions);
        printf("Week %d: %d animals adopted\n", week, roundedAdoptions);
        cumulativeTotal += roundedAdoptions;
        initialAdoptions *= adoptionRate;
    }

    printf("Total animals adopted after %d weeks: %d\n", totalWeeks, cumulativeTotal);

    return 0;
}
