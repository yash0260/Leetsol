
class Solution {
    struct Node {
        int prod;
        int cnt[5];

        Node() {
            prod = 1;
            for (int i = 0; i < 5; i++)
                cnt[i] = 0;
        }
    };

    int k, n, size;
    vector<Node> seg;

    Node merge(const Node& L, const Node& R) {
        Node res;

        res.prod = (L.prod * R.prod) % k;

        for (int r = 0; r < k; r++) {
            res.cnt[r] = L.cnt[r];
        }

        for (int r = 0; r < k; r++) {
            int rem = (L.prod * r) % k;
            res.cnt[rem] += R.cnt[r];
        }

        return res;
    }

    Node makeNode(int val) {
        Node res;
        int rem = val % k;

        res.prod = rem;
        res.cnt[rem] = 1;

        return res;
    }

    void update(int pos, int val) {
        pos += size;
        seg[pos] = makeNode(val);

        for (pos >>= 1; pos > 0; pos >>= 1) {
            seg[pos] = merge(seg[pos << 1],
                             seg[pos << 1 | 1]);
        }
    }

    Node query(int l, int r) {
        Node left, right;

        l += size;
        r += size;

        while (l < r) {
            if (l & 1) {
                left = merge(left, seg[l]);
                l++;
            }

            if (r & 1) {
                --r;
                right = merge(seg[r], right);
            }

            l >>= 1;
            r >>= 1;
        }

        return merge(left, right);
    }

public:
    vector<int> resultArray(vector<int>& nums, int k,
                            vector<vector<int>>& queries) {
        this->n = nums.size();
        this->k = k;

        size = 1;
        while (size < n)
            size <<= 1;

        seg.resize(2 * size);

        // Initialize all nodes as identity
        for (int i = 0; i < 2 * size; i++) {
            seg[i].prod = 1 % k;
        }

        // Build leaves
        for (int i = 0; i < n; i++) {
            seg[size + i] = makeNode(nums[i]);
        }

        // Build internal nodes
        for (int i = size - 1; i > 0; i--) {
            seg[i] = merge(seg[i << 1],
                           seg[i << 1 | 1]);
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            nums[index] = value;
            update(index, value);

            Node res = query(start, n);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};