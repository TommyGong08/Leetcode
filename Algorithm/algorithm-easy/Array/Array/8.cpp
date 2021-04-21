class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       vector<int>::iterator Iter;
       int count=0;
        for(Iter = nums.begin();Iter != nums.end(); Iter++){
            if(*Iter == 0){
                count++;//指向下一元素的迭代器
                Iter = nums.erase(Iter);
                Iter--;
            }
        }
        for(int i=1;i<=count;i++){
            nums.push_back(0);
        }
    }
};