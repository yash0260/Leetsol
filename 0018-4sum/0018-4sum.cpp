class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {

        int n = arr.size();

        set<vector<int>> st;

        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                unordered_set<long long> seen;

                for (int k = j + 1; k < n; k++) {

                    long long sum =
                        (long long)arr[i] +
                        arr[j] +
                        arr[k];

                    long long required =
                        (long long)target - sum;

                    if (seen.find(required) != seen.end()) {

                        vector<int> temp = {
                            arr[i],
                            arr[j],
                            arr[k],
                            (int)required
                        };

                        sort(temp.begin(), temp.end());

                        st.insert(temp);
                    }

                    seen.insert(arr[k]);
                }
            }
        }

        return vector<vector<int>>(st.begin(), st.end());
    }
};