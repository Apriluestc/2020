#include <vector>
#include <random>

class Sort {
public:
    void quickSort(std::vector<int>& nums) {
        if (nums.size() == 0) {
            return;
        }
        if (nums.size() <= 10) {
            insertSort(nums);
        }
        quickSort(nums, 0, nums.size() - 1);
    }
    void headSort(std::vector<int>& nums) {
        int size = nums.size();
        createHeap(nums, size);
        int end = size;
        while (end > 0) {
            std::swap(nums[0], nums[end-1]);
            end--;
            AdjustDown(nums, 0, end);
        }
    }
private:
    void createHeap(std::vector<int>& nums, int size) {
        for (int i = (size - 1) / 2; i >= 0; i--) {
            AdjustDown(nums, i, size);
        }
    }
    void AdjustDown(std::vector<int>& nums, int root, int size) {
        int parent = root;
        int child = 2 * parent + 1;
        while (child < size) {
            if (child < size - 1 && nums[child] < nums[child + 1]) {
                child++;
            }
            if (nums[parent] < nums[child]) {
                std::swap(nums[parent], nums[child]);
                parent = child;
                child = 2 * parent + 1;
            }
        }
    }
    void quickSort(std::vector<int>& nums, int begin, int end) {
        if (begin >= end) {
            return;
        }
        int left = begin;
        int right = end;
        int base = nums[left];
        // int index = random(left, right);
        // int base = nums[index];
        while (left < right) {
            while (left < right && nums[right] >= base) {
                right--;
            }
            if (left < right) {
                nums[left++] = nums[right];
            }
            while (left < right && nums[left] <= base) {
                left++;
            }
            if (left < right) {
                nums[right--] = nums[left];
            }
            nums[left] = base;
        }
        quickSort(nums, begin, left - 1);
        quickSort(nums, left + 1, end);
    }
    int random(int left, int right) {
        return rand() % (right - left + 1) + left;
    }
    void insertSort(std::vector<int>& nums) {
        if (nums.size() == 0) {
            return;
        }
        insertSort(nums, nums.size());
    }
    void insertSort(std::vector<int>& nums, int size) {
        for (int i = 1; i < size; i++) {
            if (nums[i] < nums[i-1]) {
                int j = i - 1;
                int temp = nums[i];
                while (j >= 0 && temp < nums[j]) {
                    nums[j+1] = nums[j];
                    j--;
                }
                nums[j+1] = temp;
            }
        }
    }
};
