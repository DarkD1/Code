// Sliding Window
// Maximum sum of sub array

function slidingWindow(arr, num) {
    if (num > arr.length) return null;
    let max = 0,
        temp = 0;
    for (let i = 0; i < num; i++) {
        max += arr[i];
        temp += arr[i];
    }

    for (let i = num; i < arr.length; i++) {
        temp = temp - arr[i - num] + arr[i];
        max = Math.max(max, temp);
    }
    return max;
}

console.log(slidingWindow([1, 4, 2, 3, 4, 6, 5], 3));