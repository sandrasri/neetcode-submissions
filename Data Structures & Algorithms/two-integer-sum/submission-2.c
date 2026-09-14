#include <stdlib.h>
#include <stdbool.h>

struct Entry {
    int key;
    int value;
    bool used;
};

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    int table_size = numsSize * 2; 
    if (table_size < 16) table_size = 16;

    struct Entry* hash_table = (struct Entry*)calloc(table_size, sizeof(struct Entry));

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int hash_idx = abs(complement) % table_size;

        while (hash_table[hash_idx].used) {
            if (hash_table[hash_idx].key == complement) {
                result[0] = hash_table[hash_idx].value;
                result[1] = i;
                
                free(hash_table);
                return result;
            }
            hash_idx = (hash_idx + 1) % table_size;
        }

        int insert_idx = abs(nums[i]) % table_size;

        while (hash_table[insert_idx].used) {
            insert_idx = (insert_idx + 1) % table_size;
        }

        hash_table[insert_idx].key = nums[i];
        hash_table[insert_idx].value = i;
        hash_table[insert_idx].used = true;
    }
    free(hash_table);
    *returnSize = 0;
    return NULL;
}
