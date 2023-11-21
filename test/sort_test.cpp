#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark_all.hpp>

#include "bucket_sort.h"
#include "quick_sort.h"
#include "radix_sort.h"

#include <algorithm>

using namespace std;

vector<pair<int,int>> makePairVector(int size)
{
	vector<pair<int,int>> v(size);
	generate(v.begin(), v.end(), [&size]{
        return make_pair(size, size);
        size--;
    });
	return v;
}

TEST_CASE("Quick sort")
{
	vector<int> v;
    function<bool(const int&,const int&)> isLess = [](const int& left, const int& right) { return left < right; };
	
	v = {};
	quickSort(v, isLess);
	REQUIRE(v == vector<int> {});

	v = {1};
	quickSort(v, isLess);
	REQUIRE(v == vector<int> {1});

	v = {4, 3, 2, 1};
	quickSort(v, isLess);
	REQUIRE(v == vector<int> {1, 2, 3, 4});

	v = {5, 4, 3, 2, 1};
	quickSort(v, isLess);
	REQUIRE(v == vector<int> {1, 2, 3, 4, 5});

	v = {1, 2, 3, 4, 5};
	quickSort(v, isLess);
	REQUIRE(v == vector<int> {1, 2, 3, 4, 5});

    function<bool(const pair<int,int>&, const pair<int,int>&)> isPairLess = [](const pair<int,int>& left, const pair<int,int>& right) {
        return left.first < right.first;
    };

/*
    BENCHMARK_ADVANCED("Quick sort (1k)")(Catch::Benchmark::Chronometer meter) {
        vector<pair<int,int>> v = makePairVector(1000);
        meter.measure([&v,&isPairLess] {
            quickSort(v, isPairLess);
			return v;
        });
    };

    BENCHMARK_ADVANCED("Quick sort (2k)")(Catch::Benchmark::Chronometer meter) {
        vector<pair<int,int>> v = makePairVector(2000);
        meter.measure([&v,&isPairLess] {
            quickSort(v, isPairLess);
			return v;
        });
    };

    BENCHMARK_ADVANCED("Quick sort (3k)")(Catch::Benchmark::Chronometer meter) {
        vector<pair<int,int>> v = makePairVector(3000);
        meter.measure([&v,&isPairLess] {
            quickSort(v, isPairLess);
			return v;
        });
    };

    BENCHMARK_ADVANCED("Quick sort (4k)")(Catch::Benchmark::Chronometer meter) {
        vector<pair<int,int>> v = makePairVector(4000);
        meter.measure([&v,&isPairLess] {
            quickSort(v, isPairLess);
			return v;
        });
    };

    BENCHMARK_ADVANCED("Quick sort (5k)")(Catch::Benchmark::Chronometer meter) {
        vector<pair<int,int>> v = makePairVector(5000);
        meter.measure([&v,&isPairLess] {
            quickSort(v, isPairLess);
			return v;
        });
    };
*/
}

TEST_CASE("Bucket sort")
{
	vector<pair<int,int>> v;
	
	v = {};
	bucketSort(v, 5);
	REQUIRE(v == vector<pair<int,int>> {});

	v = {{1,1}};
	bucketSort(v, 5);
	REQUIRE(v == vector<pair<int,int>> {{1,1}});

	v = {{4,4}, {3,3}, {2,2}, {1,1}};
	bucketSort(v, 5);
	REQUIRE(v == vector<pair<int,int>> {{1,1}, {2,2}, {3,3}, {4,4}});

	v = {{5,5}, {4,4}, {3,3}, {2,2}, {1,1}};
	bucketSort(v, 5);
	REQUIRE(v == vector<pair<int,int>> {{1,1}, {2,2}, {3,3}, {4,4}, {5,5}});

	v = {{1,1}, {2,2}, {3,3}, {4,4}, {5,5}};
	bucketSort(v, 5);
	REQUIRE(v == vector<pair<int,int>> {{1,1}, {2,2}, {3,3}, {4,4}, {5,5}});

	v = {{5,5}, {4,4}, {4,4}, {3,3}, {2,2}, {1,1}, {1,1}};
	bucketSort(v, 5);
	REQUIRE(v == vector<pair<int,int>> {{1,1}, {1,1}, {2,2}, {3,3}, {4,4}, {4,4}, {5,5}});

	vector<pair<int,string>> vPair = {{5,"five"}, {4,"four"}, {3,"three"}, {2,"two"}, {1,"one"}};
	bucketSort(vPair, 5);
	REQUIRE(vPair == vector<pair<int,string>> {{1,"one"}, {2,"two"}, {3,"three"}, {4,"four"}, {5,"five"}});

/*
    BENCHMARK_ADVANCED("Bucket sort (1k)")(Catch::Benchmark::Chronometer meter) {
        vector<pair<int,int>> v = makePairVector(1000);
        meter.measure([&v] {
            bucketSort(v, 1000);
			return v;
        });
    };

    BENCHMARK_ADVANCED("Bucket sort (2k)")(Catch::Benchmark::Chronometer meter) {
        vector<pair<int,int>> v = makePairVector(2000);
        meter.measure([&v] {
            bucketSort(v, 2000);
			return v;
        });
    };

    BENCHMARK_ADVANCED("Bucket sort (3k)")(Catch::Benchmark::Chronometer meter) {
        vector<pair<int,int>> v = makePairVector(3000);
        meter.measure([&v] {
            bucketSort(v, 3000);
			return v;
        });
    };

    BENCHMARK_ADVANCED("Bucket sort (4k)")(Catch::Benchmark::Chronometer meter) {
        vector<pair<int,int>> v = makePairVector(4000);
        meter.measure([&v] {
            bucketSort(v, 4000);
			return v;
        });
    };

    BENCHMARK_ADVANCED("Bucket sort (5k)")(Catch::Benchmark::Chronometer meter) {
        vector<pair<int,int>> v = makePairVector(5000);
        meter.measure([&v] {
            bucketSort(v, 5000);
			return v;
        });
    };
*/
}

TEST_CASE("Radix sort")
{
	vector<pair<int,int>> v;
	
	v = {};
	radixSort(v, 3);
	REQUIRE(v == vector<pair<int,int>> {});

	v = {{1,1}};
	radixSort(v, 3);
	REQUIRE(v == vector<pair<int,int>> {{1,1}});

	v = {{4,4}, {3,3}, {2,2}, {1,1}};
	radixSort(v, 3);
	REQUIRE(v == vector<pair<int,int>> {{1,1}, {2,2}, {3,3}, {4,4}});

	v = {{5,5}, {4,4}, {3,3}, {2,2}, {1,1}};
	radixSort(v, 3);
	REQUIRE(v == vector<pair<int,int>> {{1,1}, {2,2}, {3,3}, {4,4}, {5,5}});

	v = {{1,1}, {2,2}, {3,3}, {4,4}, {5,5}};
	radixSort(v, 3);
	REQUIRE(v == vector<pair<int,int>> {{1,1}, {2,2}, {3,3}, {4,4}, {5,5}});

	v = {{5,5}, {4,4}, {4,4}, {3,3}, {2,2}, {1,1}, {1,1}};
	radixSort(v, 5);
	REQUIRE(v == vector<pair<int,int>> {{1,1}, {1,1}, {2,2}, {3,3}, {4,4}, {4,4}, {5,5}});

	vector<pair<int,string>> vPair = {{5,"five"}, {4,"four"}, {3,"three"}, {2,"two"}, {1,"one"}};
	radixSort(vPair, 5);
	REQUIRE(vPair == vector<pair<int,string>> {{1,"one"}, {2,"two"}, {3,"three"}, {4,"four"}, {5,"five"}});

/*
    BENCHMARK_ADVANCED("Radix sort (1k)")(Catch::Benchmark::Chronometer meter) {
        vector<pair<int,int>> v = makePairVector(1000);
        meter.measure([&v] {
            radixSort(v, 10);
			return v;
        });
    };

    BENCHMARK_ADVANCED("Radix sort (2k)")(Catch::Benchmark::Chronometer meter) {
        vector<pair<int,int>> v = makePairVector(2000);
        meter.measure([&v] {
            radixSort(v, 11);
			return v;
        });
    };

    BENCHMARK_ADVANCED("Radix sort (3k)")(Catch::Benchmark::Chronometer meter) {
        vector<pair<int,int>> v = makePairVector(3000);
        meter.measure([&v] {
            radixSort(v, 12);
			return v;
        });
    };

    BENCHMARK_ADVANCED("Radix sort (4k)")(Catch::Benchmark::Chronometer meter) {
        vector<pair<int,int>> v = makePairVector(4000);
        meter.measure([&v] {
            radixSort(v, 12);
			return v;
        });
    };

    BENCHMARK_ADVANCED("Radix sort (5k)")(Catch::Benchmark::Chronometer meter) {
        vector<pair<int,int>> v = makePairVector(5000);
        meter.measure([&v] {
            radixSort(v, 13);
			return v;
        });
    };
*/
}
