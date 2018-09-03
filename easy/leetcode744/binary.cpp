class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(letters.back() <= target)
            return letters.front();
        int front = 0, end = letters.size()-1, mid;
        while(front < end){
            mid = (front + end) / 2;
            if(target < letters[mid])
                end = mid;
            else
                front = mid + 1;
        }
        return letters[front];
    }
};
