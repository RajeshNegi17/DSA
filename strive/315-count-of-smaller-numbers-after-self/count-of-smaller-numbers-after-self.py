class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        n = len(nums)

        arr = [(nums[i], i) for i in range(n)]

        ans = [0] * n

        def merge(low, mid, high):

            temp = []

            i = low
            j = mid + 1

            right_count = 0

            while i <= mid and j <= high:

                if arr[i][0] <= arr[j][0]:

                    ans[arr[i][1]] += right_count

                    temp.append(arr[i])

                    i += 1

                else:

                    right_count += 1

                    temp.append(arr[j])

                    j += 1

            while i <= mid:

                ans[arr[i][1]] += right_count

                temp.append(arr[i])

                i += 1

            while j <= high:

                temp.append(arr[j])

                j += 1

            for idx in range(low, high + 1):

                arr[idx] = temp[idx - low]

        def merge_sort(low, high):

            if low >= high:
                return

            mid = (low + high) // 2

            merge_sort(low, mid)

            merge_sort(mid + 1, high)

            merge(low, mid, high)

        merge_sort(0, n - 1)

        return ans