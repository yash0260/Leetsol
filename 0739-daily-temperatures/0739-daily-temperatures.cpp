class Solution { 
public: 
    vector<int> dailyTemperatures(vector<int>& temperatures) { 
 
        int n = temperatures.size(); 
 
        // Initially all answers are 0 
        vector<int> answer(n, 0); 
 
        // Store indices of temperatures 
        stack<int> st; 
 
        for (int i = 0; i < n; i++) { 
 
            // Current temperature is warmer than the temperature 
            // represented by the index at the top of the stack. 
            while (!st.empty() && 
                   temperatures[i] > temperatures[st.top()]) { 
 
                // Get the previous colder day 
                int prevIndex = st.top(); 
                st.pop(); 
 
                // Number of days we waited 
                answer[prevIndex] = i - prevIndex; 
            } 
 
            // Current day is unresolved, so push its index 
            st.push(i); 
        } 
 
        return answer; 
    } 
}; 