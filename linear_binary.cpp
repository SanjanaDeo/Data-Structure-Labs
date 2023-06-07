def linear_search(arr, target):
for i in range(len(arr)):
if arr[i] == target:
return i
return -1
def binary_search(arr, target):
low = 0
high = len(arr) - 1
while low <= high:
mid = (low + high) // 2
if arr[mid] == target:
return mid
elif arr[mid] < target:
low = mid + 1
else:
high = mid - 1
return -1
# Test the linear search
array = [4, 2, 7, 1, 9, 5]
target = 7
index = linear_search(array, target)
if index != -1:
print(f"Linear search: Element {target} found at index {index}")
else:
print(f"Linear search: Element {target} not found")
# Test the binary search
sorted_array = [1, 2, 3, 4, 5, 6, 7, 8, 9]
target = 6
index = binary_search(sorted_array, target)
if index != -1:
print(f"Binary search: Element {target} found at index {index}")
else:
print(f"Binary search: Element {target} not found")
