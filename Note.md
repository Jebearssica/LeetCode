# Note

## 16.最接近的三数之和

代码写得好看是要付出代价的, 粗暴一点的代码虽然可读性差了点, 但是效率会高

一个速度优解如下, 少了很多中间变量名, 所以速度就快了

```c++
class Solution {
public:

    #define MATH_ABS(x) ((x) > 0 ? (x) :-(x))

    int threeSumClosest(vector<int>& nums, int target) {
        
    int i,j,k;

    int minVal_s32;
    int minVavId_s32;

    //先排序
   for(i = 0; i < nums.size() - 1; i++)
   {
    minVal_s32 = nums[i];
    minVavId_s32 = i;

    for(j = i+1; j < nums.size(); j++)
    {
        if(nums[j] < minVal_s32)
        {
            minVal_s32 = nums[j];
            minVavId_s32 = j;
        }
        else
        {

        }
    }

    //交换
    nums[minVavId_s32] = nums[i];
    nums[i] = minVal_s32;
   }

   int sum_tmp_s32;
   int sum_nearest_s32;

   sum_nearest_s32 = nums[0] + nums[1] + nums[2];

   //从小到大排序好了
   for(i = 0; i < nums.size() - 2; i++)
   {
      j = i+1;

      k = nums.size()-1; 

       while(1)
       {
            sum_tmp_s32 = nums[i] + nums[j] + nums[k];

            if(MATH_ABS(sum_tmp_s32-target) < MATH_ABS(sum_nearest_s32-target))
            ///if(sum_tmp_s32 < sum_nearest_s32)
            {
                 sum_nearest_s32 = sum_tmp_s32;
            }
            else
            {

            }

            if(sum_tmp_s32 < target)
            {
               j++;
            }
            else if(sum_tmp_s32 > target)
            {
               k--;
            }
            else
            {
              return sum_tmp_s32;
            }

            if(j < k)
            {

            }
            else
            {
                break;
            }
          
       }  
               
   }

   //
   return sum_nearest_s32;

    }
};
```