# Lab 42: Radix Sort

In this lab, we will study the linear-time sort algorithm radix sort and compare its performance to quick sort.

## Bucket Sort

Bucket sort is a linear-time sort algorithm that requires each element to be represented by an integer key. Its pseudocode is in Example 11.8 in the textbook and is repeated here:

    Algorithm bucketSort(S):
        Input: Sequence S of entries with integer keys in the range [0,N − 1]
        Output: Sequence S sorted in nondecreasing order of the keys
        let B be an array of N sequences, each of which is initially empty
        for each entry e in S do
            k ← e.key()
            remove e from S and insert it at the end bucket (sequence) B[k]
        for i ← 0 to N − 1 do
            for each entry e in sequence B[i] do
                remove e from B[i] and insert it at the end of S

Implement this pseudocode in the `bucketSort` function. Note that the input is a vector of `std::pair` values, where the first part of the pair is an integer key and the second part is a value bound to the key. The `maxKey` parameter is the maximum value out of all keys in the vector.

For the implementation, you will want to create some kind of 2D data structure to represent the _B_ in the pseudocode--that is, the "buckets". (Hint: Is the size of _B_ equal to `maxKey`? Watch out for off-by-one errors!)

For the sorting, simply add all values to their appropriate buckets, clear the original vector, then copy the values from the buckets back to the vector.

Make sure the bucket sort unit tests pass before continuing.

## Radix Sort

Radix sort is already implemented for you in `radixSort`, but it relies on your `bucketSort` function to do its work. Make sure all radix sort unit tests pass before continuing.

## Performance Comparison

Finally, uncomment all benchmark tests and run them. Note that the speed of the benchmarks depends on the speed of your computer, so feel free to reduce the input sizes if your computer is taking longer than a couple of minutes to run them.

Compare the performance of quick sort, bucket sort, and radix sort. You should find that quick sort is the slowest, while bucket sort is the fastest.

Question: If radix sort is slower than bucket sort, why use radix sort at all? (Hint: Consider the space complexity if the maximum key is very large.)
