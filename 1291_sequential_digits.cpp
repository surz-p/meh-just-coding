class Solution {
private:
    using vi = vector<int>;
public:
    vi generate_n_length_numbers(int sz, const int& L, const int& H) {
        // if s=6, 123456, 234567,345678, 456789 [10-6 combinations]
        // if s=4, 1234, 2345, 3456, 4577, 5678, 6789 [10-4 combinations]
        // if s=k, ... [10-k combinations]
        vector<int> sequence;
        bool isLoopContinued = true;
        while (isLoopContinued && sz <= 10) {
            for (int i = 1; i <= 10 - sz; i++) {
                int copy = sz;
                // can i do something about memory? 
                // maybe just use integers and not strings?
                int possibleNumber = 0;
                while (copy > 0) {
                    possibleNumber = possibleNumber * 10 + (i + sz - copy);
                    copy--;
                }
                if (possibleNumber >= L && possibleNumber <= H) {
                    sequence.push_back(possibleNumber);
                }
                if (possibleNumber > H) {
                    isLoopContinued = false;
                    break;
                }
            }
            sz++;
        }
        return sequence;
    }

    vector<int> sequentialDigits(int low, int high) {
        // dig = get no. of digits in "low"
        int lowCopy = low, dig = 0;
        while (lowCopy > 0) {
            lowCopy = lowCopy / 10;
            dig++;
        }
        return generate_n_length_numbers(dig, low, high);
    }
};

// topics: misc
// time complexity: ~O(1), space complexity: ~O(1)

