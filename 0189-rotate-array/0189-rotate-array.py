class Solution:
    def rotate(self, nums: list[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        arr=[]
        n=len(nums)
        k=k%n
        for i in range(n-k,n-k+n):
            arr.append(nums[i%n])
        nums[:]=arr
        