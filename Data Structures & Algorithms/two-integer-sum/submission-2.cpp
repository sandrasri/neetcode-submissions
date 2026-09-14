#include <vector>
#include <cmath>
#include <cstdlib>

struct Entry {
    int key;
    int value;
    bool used;
};

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        int n = nums.size();
        int table_size = n * 2; 
        if (table_size < 16) table_size = 16;
        
        struct Entry* hash_table = (struct Entry*)calloc(table_size, sizeof(struct Entry));
        
        std::vector<int> result;

        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            int hash_idx = std::abs(complement) % table_size;
            
            while (hash_table[hash_idx].used) {
                if (hash_table[hash_idx].key == complement) {
                    result = {hash_table[hash_idx].value, i};
                    break;
                }
                hash_idx = (hash_idx + 1) % table_size;
            }
            
            if (!result.empty()) break;

            int insert_idx = std::abs(nums[i]) % table_size;
            while (hash_table[insert_idx].used) {
                insert_idx = (insert_idx + 1) % table_size;
            }
            
            hash_table[insert_idx].key = nums[i];
            hash_table[insert_idx].value = i;
            hash_table[insert_idx].used = true;
        }
        
        free(hash_table);
        
        return result;
    }
};
