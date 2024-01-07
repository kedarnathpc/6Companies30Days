class DataStream {
public:
    int n, val, lastVal, freq;
    DataStream(int value, int k) {
        n = k;
        val = value;
        lastVal = -1;
        freq = 0;
    }
    
    bool consec(int num) {
        if(n == 1)  return num == val;
        if(num == lastVal) freq++;
        else{
            lastVal = num;
            freq = 1;
        }
        return num == val ? freq >= n : false;
    }
};