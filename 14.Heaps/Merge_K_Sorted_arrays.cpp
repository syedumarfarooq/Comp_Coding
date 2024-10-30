
#include <iostream>
#include<vector>
#include<queue>
using namespace std;

class info {
        public:
        int data;
        int row;
        int col;

        info(int val, int r, int c) {
                data = val;
                row = r;
                col = c;
        }  
};

class compare {
        public:
        bool operator()(info* a, info* b) {
                return a->data > b->data;
        }
//         When a->data > b->data: It returns true, which means b (the smaller value) is given higher priority than a.
// When a->data <= b->data: It returns false, meaning a has higher or equal priority.
// If a->data = 15 and b->data = 10:
// Since 15 > 10, the function returns true. This means that b (10) is given higher priority than a (15), so b comes first in the queue.

// If a->data = 5 and b->data = 20:
// Since 5 < 20, the function returns false. This means a (5) has higher priority than b (20), so a comes first.

// If a->data = 7 and b->data = 7:
// Since 7 == 7, the function returns false because a->data is not greater than b->data. Here, a retains priority (or equal priority).
};


vector<int> mergeKSortedArrays(int arr[][4], int k, int n) {
        priority_queue<info*,vector<info*>, compare > minHeap;

        //hr array ka first element insert karo 
        for(int i=0; i<k; i++) {
                info* temp = new info(arr[i][0], i, 0);
                minHeap.push(temp);
        }

        vector<int> ans;

        while(!minHeap.empty()) {
                info* temp = minHeap.top();
                int topElement = temp->data;
                int topRow = temp->row;
                int topCol = temp->col;
                minHeap.pop();

                ans.push_back(topElement);

                if(topCol + 1 < n) {
                        info* newInfo = new info(arr[topRow][topCol+1], topRow, topCol+1);
                        minHeap.push(newInfo);
                }
        }
        return ans;
}

int main() {
        int arr[][4] = { {2,4,6,8}, 
                        {1,3,5,7}, 
                        {0,9,10,11}
                        };
        int k = 3;
        int n = 4;
        vector<int> ans  = mergeKSortedArrays(arr, k, n);
        for(auto i:ans) {
                cout << i << " ";
        }cout << endl;
  return 0;
}
