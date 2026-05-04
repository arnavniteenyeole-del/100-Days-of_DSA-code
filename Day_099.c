#include <stdio.h>
#include <stdlib.h>

struct Car {
    int pos;
    double time;
};

int cmp(const void* a, const void* b) {
    return ((struct Car*)b)->pos - ((struct Car*)a)->pos;
}

int main() {
    int n, target;
    scanf("%d %d", &n, &target);

    int position[n], speed[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &position[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &speed[i]);

    struct Car cars[n];

    for (int i = 0; i < n; i++) {
        cars[i].pos = position[i];
        cars[i].time = (double)(target - position[i]) / speed[i];
    }

    qsort(cars, n, sizeof(struct Car), cmp);

    int fleets = 0;
    double maxTime = 0.0;

    for (int i = 0; i < n; i++) {
        if (cars[i].time > maxTime) {
            fleets++;
            maxTime = cars[i].time;
        }
    }

    printf("%d", fleets);
    return 0;
}