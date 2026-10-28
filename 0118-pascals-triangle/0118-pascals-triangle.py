class Solution:
    def generate(self, numRows: int) -> list[list[int]]:
        ans=[]
        n=numRows
        ans.append([1])
        n=n-1
        prev_idx=0
        while n>0:
            temp=[]
            temp.append(1)
            for i in range(1,len(ans[prev_idx])):
                temp.append(
                    ans[prev_idx][i]+ans[prev_idx][i-1]
                )
            prev_idx+=1
            temp.append(1)
            ans.append(temp)
            n-=1
        return ans