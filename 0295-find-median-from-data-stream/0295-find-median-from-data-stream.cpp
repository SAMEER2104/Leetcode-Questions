class MedianFinder {
public:

    priority_queue<int>max_pq;
    priority_queue<int, vector<int>, greater<int>>min_pq;
    int n;

    MedianFinder() {
        n = 0;
    }
    
    void addNum(int num) {

        n++;

        if(max_pq.size() == 0)
        {
            max_pq.push(num);
            return;
        }

        if(min_pq.size() < max_pq.size())
        {
            if(num < max_pq.top())
            {
                int val = max_pq.top();
                max_pq.pop();
                max_pq.push(num);
                min_pq.push(val);
            }

            else
            {
                min_pq.push(num);
            }
        }

        else
        {
            if(num > min_pq.top())
            {
                int val = min_pq.top();
                min_pq.pop();
                min_pq.push(num);
                max_pq.push(val);
            }

            else
            {
                max_pq.push(num);
            }
        }
        
    }
    
    double findMedian() {

        int x = max_pq.top();
        int y;

        if(min_pq.size() > 0) y = min_pq.top();

        if(max_pq.size() == min_pq.size()) {
            double ans = ((x + y ) * 1.0 ) / 2.0;
            return ans;
        }


        double ans = x * 1.0;
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */