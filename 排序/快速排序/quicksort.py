def quickSort(a, left, right):
    base = a[left]
    low = left
    high = right

    if left >= right:
        return

    while left != right:
        while left != right:
            if a[right] <= base:
                a[left] = a[right]
                left += 1
                break
            right -= 1

        while left != right:
            if a[left] >= base:
                a[right] = a[left]
                right -= 1
                break
            left += 1
    a[left] = base

    print(a, left, right)

    quickSort(a, low, right - 1)
    quickSort(a, left + 1, high)

arr = [77, 2, 22, 86, 94, 8, 101]
print(arr)
quickSort(arr, 0, len(arr) - 1)

print(arr)
