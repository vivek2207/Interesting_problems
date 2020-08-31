class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        
        len_num1=len(nums1)
        len_num2=len(nums2)
        
        if not nums1:
            if len_num2==1:
                return nums2[0]
            mid1=len_num2//2-1
            mid2=mid1+1
            
            if len_num2%2==0:
                return ((nums2[mid1]+nums2[mid2]))/2
            else:
                return nums2[mid2]
        if not nums2:
            if len_num1==1:
                return nums1[0]
            mid1=len_num1//2-1
            mid2=mid1+1
            
            if len_num1%2==0:
                return ((nums1[mid1]+nums1[mid2]))/2
            else:
                return nums1[mid2]
                        
        sum_new_arr=len_num1+len_num2
        mid1=sum_new_arr//2
        mid2=mid1+1
                
        new_arr=[]
        for _ in range(mid2):
            if not nums1:
                new_arr.append(nums2.pop(0))
            elif not nums2:
                new_arr.append(nums1.pop(0))
            elif nums1[0]<=nums2[0]:
                new_arr.append(nums1.pop(0))
            else:
                new_arr.append(nums2.pop(0))
                        
        num1, num2=new_arr[-2], new_arr[-1]
        
        if sum_new_arr%2==0:
            res=(num1+num2)/2
            return res
        else:
            return num2
