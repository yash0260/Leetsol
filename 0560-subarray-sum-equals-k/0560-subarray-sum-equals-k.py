class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        mp={}
        n=len(nums)
        sum=0
        cnt=0
        mp[0]=1
        for i in range(n):
            sum+=nums[i]
            required=sum-k
            if required in mp:
                cnt+=mp[required]
            mp[sum]=mp.get(sum,0)+1
        return cnt
        