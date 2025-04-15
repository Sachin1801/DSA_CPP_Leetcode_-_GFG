class NumArray {
private:
    int *st;
    int n;
    vector<int> arr;
    int getMid(int s, int e){ return s+ (e-s)/2;}

    int constructSTUtil(vector<int> &arr, int ss, int se, int *st, int si){
        //if there is one element in array, store it in the current node of
        //segment tree
        if(ss ==se){
            st[si]= arr[ss];
            return arr[ss];
        }

        //if there are more than one elements, then recur for left and 
        // right subtrees and store the sum of values in this node
        int mid = getMid(ss,se);
        st[si] = constructSTUtil(arr,ss,mid,st,si*2+1) + constructSTUtil(arr,mid+1, se, st, si*2+2);

        return st[si];
    }

    int getSumUtil(int *st, int ss, int se,int qs, int qe, int si){
        //if the segment of this node is a part of given range. then reutrn 
        //the sum of the segment
        if(qs <= ss && qe >= se) return st[si];

        //if segment of this node is outside the given range
        if(se < qs || ss > qe) return 0;

        //if a part of this segment overlaps with the given range
        int mid = getMid(ss,se);
        return getSumUtil(st,ss,mid,qs,qe,2*si+1) + getSumUtil(st,mid+1,se,qs,qe,2*si+2);
    }

    void updateValueUtil(int *st, int ss, int se, int i , int diff, int si){
        //base change: if the input index lies outside the range 
        //of the segment
        if(i < ss || i > se) return;

        //if the input index is in the range of this node, then update 
        //the value of the node and its children
        st[si] = st[si] + diff; 
        if(se!=ss){
            int mid = getMid(ss,se);
            updateValueUtil(st,ss,mid,i,diff,2*si+1);
            updateValueUtil(st,mid+1,se,i,diff,2*si+2);
        }
    }

public:
    NumArray(vector<int>& nums) {
        arr = nums;
        n = nums.size();
        int x = (int)ceil(log2(n));

        //max size of the segment tree
        int max_size = 2*(int)pow(2,x)-1;

        //allocate memory 
        st = new int[max_size];

        //fill the allocated memory st
        constructSTUtil(arr,0,n-1,st,0);

    }
    
    void update(int i, int val) {
        //check for erroneous value
        if(i < 0 || i > n-1) return;

        //get the difference between new value and old value
        int diff = val - arr[i];

        //update the value in the array
        arr[i] = val;

        //update the values of node in segmentr tree
        updateValueUtil(st,0,n-1,i,diff,0);
    }
    
    int sumRange(int left, int right) {
        //check for erroneous input index
        if(left < 0 || right > n-1 || left > right){
            return -1;
        }
        return getSumUtil(st,0,n-1,left,right,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */