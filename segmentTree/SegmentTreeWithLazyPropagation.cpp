class NumArray
{
    vector<int> tree, lazy;
    int low, high;

public:
    NumArray(vector<int> &nums)
    {
        int N = 2;

        while (N < nums.size())
            N *= 2;

        low = 0, high = nums.size() - 1;

        N = 2 * N - 1;

        tree.resize(N, 0), lazy.resize(N, 0);

        buildTree(nums, 0, low, high);

        //         for(auto const& num: tree)
        //             cout<<num<<" ";

        //         cout<<endl;
    }

    void buildTree(vector<int> &arr, int treeIdx, int lo, int hi)
    {
        if (lo == hi)
        {
            tree[treeIdx] = arr[lo];
            return;
        }

        int mid = lo + (hi - lo) / 2;

        buildTree(arr, 2 * treeIdx + 1, lo, mid);
        buildTree(arr, 2 * treeIdx + 2, mid + 1, hi);

        tree[treeIdx] = tree[2 * treeIdx + 1] + tree[2 * treeIdx + 2];
    }

    void updateTree(int treeIdx, int lo, int hi, int left, int right, int val)
    {
        if (left > hi || right < lo)
            return;
        if (lazy[treeIdx] != 0)
        {
            tree[treeIdx] = (hi - lo + 1) * lazy[treeIdx];
            if (lo != hi)
            {
                lazy[2 * treeIdx + 1] = lazy[treeIdx];
                lazy[2 * treeIdx + 2] = lazy[treeIdx];
            }
            lazy[treeIdx] = 0;
        }

        if (lo == hi)
        {
            tree[treeIdx] = val;
            return;
        }

        if (left <= low && right >= hi)
        {
            lazy[treeIdx] = val;
            return;
        }

        int mid = lo + (hi - lo) / 2;

        updateTree(2 * treeIdx + 1, lo, mid, left, right, val);
        updateTree(2 * treeIdx + 2, mid + 1, hi, left, right, val);

        tree[treeIdx] = tree[2 * treeIdx + 1] + tree[2 * treeIdx + 2];
    }

    void update(int index, int val)
    {
        updateTree(0, low, high, index, index, val);
    }

    int rangeSum(int treeIdx, int lo, int hi, int left, int right)
    {
        if (right < lo || left > hi)
            return 0;

        if (lazy[treeIdx] != 0)
        {
            tree[treeIdx] = (hi - lo + 1) * lazy[treeIdx];
            if (lo != hi)
            {
                lazy[2 * treeIdx + 1] = lazy[treeIdx];
                lazy[2 * treeIdx + 2] = lazy[treeIdx];
            }
            lazy[treeIdx] = 0;
        }

        if (left <= lo && right >= hi)
            return tree[treeIdx];

        int mid = lo + (hi - lo) / 2;

        if (left > mid)
            return rangeSum(2 * treeIdx + 2, mid + 1, hi, left, right);
        if (right <= mid)
            return rangeSum(2 * treeIdx + 1, lo, mid, left, right);

        int rightQuery = rangeSum(2 * treeIdx + 2, mid + 1, hi, left, right);
        int leftQuery = rangeSum(2 * treeIdx + 1, lo, mid, left, right);

        return leftQuery + rightQuery;
    }

    int sumRange(int left, int right)
    {
        // for(auto const& num: tree)
        //     cout<<num<<" ";
        // cout<<endl;
        return rangeSum(0, low, high, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */