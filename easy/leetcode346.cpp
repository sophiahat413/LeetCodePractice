class MovingAverage {
public:
    queue<int> Q;
    int AverageSize;
    double sum = 0;
    /** Initialize your data structure here. */
    MovingAverage(int size){
        AverageSize = size;
    }
        //vector<int> nums(size, 0);
    double next(int val) {
        if(Q.size() == AverageSize){
            sum -= Q.front();
            Q.pop();
        }
        Q.push(val);
        sum += val;
        return sum / Q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
