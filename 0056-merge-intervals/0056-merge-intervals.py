class Solution:
    def merge(self, intervals: list[list[int]]) -> list[list[int]]:
        ans=[]
        intervals.sort()
        start=intervals[0][0]
        end=intervals[0][1]
        n=len(intervals)
        for i in range(1,n):
            if intervals[i][0]<=end:
                end=max(intervals[i][1],end)
            else:
                ans.append([start,end])
                start=intervals[i][0]
                end=intervals[i][1]
        ans.append([start,end])
        return ans