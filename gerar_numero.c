#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));

    int n;
    printf("Enter the number of random numbers to generate: ");
    scanf("%d", &n);

    FILE *file = fopen("random_numbers.txt", "w");
    for (int i = 0; i < n; i++) {
        int number = rand() % 100;
        fprintf(file, "%d\n", number);
    }
    fclose(file);

    printf("Random numbers saved to random_numbers.txt\n");

    int numbers[n];
    file = fopen("random_numbers.txt", "r");
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &numbers[i]);
    }
    fclose(file);

    printf("Numbers read from random_numbers.txt: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    printf("%d\n", sizeof(numbers));

    return 0;
}
