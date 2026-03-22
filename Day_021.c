#include <stdlib.h>

typedef struct {
    int key;
    int value;
} HashNode;

int findIndex(HashNode* map, int size, int key) {
    int idx = abs(key) % size;
    while (map[idx].key != 0 && map[idx].key != key)
        idx = (idx + 1) % size;
    return idx;
}

int countZeroSumSubarrays(int* nums, int n) {
    int size = 2 * n + 1;
    HashNode* map = (HashNode*)calloc(size, sizeof(HashNode));

    int prefix_sum = 0;
    int count = 0;

    int idx0 = findIndex(map, size, 0);
    map[idx0].key = 0;
    map[idx0].value = 1;

    for (int i = 0; i < n; i++) {
        prefix_sum += nums[i];

        int idx = findIndex(map, size, prefix_sum);

        if (map[idx].key == prefix_sum) {
            count += map[idx].value;
            map[idx].value++;
        } else {
            map[idx].key = prefix_sum;
            map[idx].value = 1;
        }
    }

    free(map);
    return count;
}