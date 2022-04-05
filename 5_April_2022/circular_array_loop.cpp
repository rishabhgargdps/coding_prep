

// INCORRECT--

// class Solution {
// public:
//     bool circularArrayLoop(vector<int>& nums) {
//         unordered_set<int>visited;
//         unordered_set<int>ans;
//         int i=0, curr_sign =  nums[0] > 0 ? 1 : -1;
//         while(visited.size() != nums.size()) {
//             if(ans.empty()) {
//                 visited.insert(i);
//                 ans.insert(i);
//             }
//             else if(nums[i] * curr_sign > 0 && visited.find(i) == visited.end()) {
//                 visited.insert(i);
//                 ans.insert(i);
//             }
//             else if(nums[i] * curr_sign > 0 && visited.find(i) != visited.end() && ans.size() > 1) {
//                 return true;
//             }
//             else if(nums[i] * curr_sign > 0 && visited.find(i) != visited.end() && ans.size() <= 1) {
//                 return false;
//             }
//             else if(nums[i] * curr_sign < 0 && visited.find(i) != visited.end()) {
//                 return false;
//             }
//             else if(nums[i] * curr_sign < 0 && visited.find(i) == visited.end()) {
//                 curr_sign = -curr_sign;
//                 visited.insert(i);
//                 ans.clear();
//                 ans.insert(i);
//             }
//             i = (i + nums[i])%nums.size();
//         }
//         return false;
//     }
// };

// class Solution {
// public:
//     bool circularArrayLoop(vector<int>& nums) {
//         unordered_set<int>visited;
//         unordered_set<int>ans;
//         int i=0, curr_sign =  nums[0] > 0 ? 1 : -1;
//         while(visited.size() != nums.size()) {
//             if(ans.empty()) {
//                 visited.insert(i);
//                 ans.insert(i);
//             }
//             else if(nums[i] * curr_sign > 0 && visited.find(i) == visited.end()) {
//                 visited.insert(i);
//                 ans.insert(i);
//             }
//             else if(nums[i] * curr_sign > 0 && visited.find(i) != visited.end() && ans.size() > 1) {
//                 return true;
//             }
//             else if(nums[i] * curr_sign > 0 && visited.find(i) != visited.end() && ans.size() <= 1) {
//                 visited.insert(i);
//                 ans.clear();
//                 i++;
//                 continue;
//             }
//             else if(nums[i] * curr_sign < 0 && visited.find(i) != visited.end()) {
//                 visited.insert(i);
//                 ans.clear();
//                 i++;
//                 continue;
//             }
//             else if(nums[i] * curr_sign < 0 && visited.find(i) == visited.end()) {
//                 curr_sign = -curr_sign;
//                 visited.insert(i);
//                 ans.clear();
//                 ans.insert(i);
//             }
//             i = (i + nums[i])%nums.size();
//         }
//         return false;
//     }
// };

// class Solution {
// public:
//     bool circularArrayLoop(vector<int>& nums) {
//         unordered_set<int>s;
//         int curr_sign = nums[0] > 0 ? 1 : -1, i = 0, prev_i = 0;
//         while(true) {
//             if(nums[i]*curr_sign > 0 && s.find(nums[i]) == s.end()) s.insert(nums[i]);
//             else if(nums[i]*curr_sign > 0 && s.find(nums[i]) != s.end() && prev_i != i) return true;
//             else if(nums[i]*curr_sign < 0 && s.find(nums[i]) == s.end()) {
//                 curr_sign = -curr_sign;
//                 s.insert(nums[i]);
//             }
//             else return false;
//             prev_i = i;
//             i = (i + nums[i])%nums.size();
//         }
//         return false;
//     }
// };