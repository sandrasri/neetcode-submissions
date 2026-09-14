#include <stdlib.h>
#include <stdbool.h>

struct hashMap {
    int key;
    int value;
    bool used;
};

bool containsDuplicate(int* nums, int numsSize) {
    if (numsSize <= 1) {
        return false;
    }

    int table_size = numsSize * 2;
    struct hashMap* hash_table = (struct hashMap*)calloc(table_size, sizeof(struct hashMap));
    
    for (int i = 0; i < numsSize; i++) {
        int index = abs(nums[i]) % table_size;

        while (hash_table[index].used) {
            if (hash_table[index].key == nums[i]) {
                free(hash_table);
                return true;
            }

            index = (index + 1) % table_size;
        }
        hash_table[index].key = nums[i];
        hash_table[index].used = true;
    }
    free(hash_table);
    return false;
    
}
