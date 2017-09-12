// STLHJ.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include <array>
#include <ctime>
#include <string>
#include <stack>
#include <queue>

using namespace std;

const int ASIZE = 100000;

long get_a_target_long()
{
	long target = 0;

	cout << "target (0~" << RAND_MAX << "): ";

	cin >> target;

	return target;
}

string get_a_target_string()
{
	return "23456";

	long target = 0;
	char buf[10];

	cout << "target (0~" << RAND_MAX << "): ";
	cin >> target;
	snprintf(buf, 10, "%d", target);
	return string(buf);
}

int compareLongs(const void* a, const void* b)
{
	return (*(long*)a - *(long*)b);
}

int compareStrings(const void* a, const void* b)
{
	if (*(string*)a > *(string*)b)
		return 1;
	else if (*(string*)a < *(string*)b)
		return -1;
	return 0;
}

void STL3_test_array()
{
	cout << endl << "test_array()..........\n";

	array<long, ASIZE> c;

	srand(clock());

	clock_t	timeStart = clock();
	for (long i = 0; i < ASIZE; ++i)
	{
		c[i] = rand();		
	}

	cout << "milli-seconds : " << (clock() - timeStart) << endl;
	cout << "array.size= " << c.size() << endl;
	cout << "array.front()= " << c.front() << endl;
	cout << "array.back()= " << c.back() << endl;
	cout << "array.data()=" << c.data() << endl; // start address of this array

	long target = get_a_target_long();

	timeStart = clock();
	qsort(c.data(), ASIZE, sizeof(long), compareLongs);

	long* pItem = (long*)bsearch(&target, (c.data()), ASIZE, sizeof(long), compareLongs);
	cout << "qsort() + bsearch(), milli-seconds:"<< (clock() - timeStart) << endl;

	if (pItem != NULL)
	{
		cout << "found, " << *pItem << endl;
	}
	else
	{
		cout << "not found! " << endl;
	}
}

#include <vector>
void STL4_test_vector(long value)
{
	srand(time(0));

	cout << "test vector" << endl;

vector<string> c;
char buf[10];
clock_t timeStart = clock();
	
	for (long i = 0; i < value; ++i)
	{
		try
		{
			snprintf(buf, 10, "%d", rand());
			c.push_back(string(buf));
		}
		catch (exception& p)
		{
			cout << "i = " << i << " " << p.what() << endl;
			abort();
		}
	}

	cout << "milli-seconds: " << (clock() - timeStart) << endl;
	cout << "size:" << c.size() << endl;
	cout << "front: " << c.front() << endl;
	cout << "end: " << c.back() << endl;
	cout << "address:" << c.data() << endl;
	cout << "capacity:" << c.capacity() << endl;

string target = get_a_target_string();
	{
		timeStart = clock();
		auto pItem = ::find(c.begin(), c.end(), target);
		cout << "::find(), milli-secs:" << clock() - timeStart << endl;

		if (pItem != c.end())
		{
			cout << "found" << *pItem << endl;
		}
		else
		{
			cout << "Not found" << endl;
		}
	}

	{
		timeStart = clock();
		sort(c.begin(), c.end());
		string* pItem = (string*)bsearch(&target, c.data(), c.size(), sizeof(string), compareStrings);
		cout << "sort+bSearch, milli-secs:" << clock() - timeStart << endl;

		if (pItem != nullptr)
		{
			cout << "found" << *pItem << endl;
		}
		else
		{
			cout << "Not found" << endl;
		}
	}
}

#include <forward_list>
void STL5_test_forwardlist(long value)
{
	forward_list<string> c;
	char buf[10];

	clock_t timeStart = clock();

	for (long i = 0; i < value; ++i)
	{
		try
		{
			snprintf(buf, 10, "%d", rand());
			c.push_front(string(buf));  // NOTE
		}
		catch (exception& p)
		{
			cout << " i = " << i << " " << p.what() << endl;
			abort();
		}
	}

	cout << "millisecs: " << clock() - timeStart << endl;
	//cout << "size" << c.size() << endl; // Not support
	cout << "max_size" << c.max_size() << endl; 
	cout << "front: " << c.front() << endl;
	//cout << "end: " << c.back() << endl; // Not support

	string target = get_a_target_string();
	timeStart = clock();
	auto pItem = ::find(c.begin(), c.end(), target);
	cout << *pItem << clock() - timeStart << endl;

	timeStart = clock();
	c.sort();
	cout << clock() - timeStart << endl;
}

#include <list>
void STL5_test_list(long value)
{
	list<string> c;
	char buf[10];

	clock_t timeStart = clock();
	
	for (long i = 0; i < value; ++i)
	{
		try
		{
			snprintf(buf, 10, "%d", rand());
			c.push_back(string(buf));
		}
		catch (exception& p)
		{
			cout << " i = " << i << " " << p.what() << endl;
			abort();
		}
	}

	cout << "millisecs: " << clock() - timeStart << endl;
	cout << "size" << c.size() << endl;
	cout << "max_size" << c.max_size() << endl;
	cout << "front: " << c.front() << endl;
	cout << "end: " << c.back() << endl;

	string target = get_a_target_string();
	timeStart = clock();
	auto pItem = ::find(c.begin(), c.end(), target);
	cout << *pItem << "find time" << clock() - timeStart << endl;

	timeStart = clock();
	c.sort();
	cout << clock() - timeStart << endl;
}

#include <deque>
void STL5_test_deque(long value)
{
	deque<string> c;
	char buf[10];

	clock_t timeStart = clock();

	for (long i = 0; i < value; ++i)
	{
		try
		{
			snprintf(buf, 10, "%d", rand());
			c.push_back(string(buf));
		}
		catch (exception& p)
		{
			cout << " i = " << i << " " << p.what() << endl;
			abort();
		}
	}

	cout << "millisecs: " << clock() - timeStart << endl;
	cout << "size" << c.size() << endl;
	cout << "max_size" << c.max_size() << endl;
	cout << "front: " << c.front() << endl;
	cout << "end: " << c.back() << endl;

	string target = get_a_target_string();
	timeStart = clock();
	auto pItem = ::find(c.begin(), c.end(), target);
	cout << *pItem << clock() - timeStart << endl;

	timeStart = clock();
	sort(c.begin(), c.end());
	cout << clock() - timeStart << endl;
}

void STL5_test_stack_queue()
{
	/*
	Stack operations: pop, push, top, no front, no back
	Queue: pop, push, front, back
	*/
}

#include <set>
void STL6_test_multiset(long value)
{
	multiset<string> c;
	char buf[10];

	clock_t start = clock();

	for (long i = 0; i < value; ++i)
	{
		try
		{
			snprintf(buf, 10, "%d", rand());
			c.insert(string(buf)); // Will insert a suitable place, it will sort when put a new element
		}
		catch (exception& p)
		{
			cout << p.what() << endl;
		}
	}

	cout << "time:" << clock() - start << endl;
	cout << "size: " << c.size() << endl;
	cout << "maxsize: " << c.max_size() << endl;

	string target = get_a_target_string();
	{
		start = clock();
		auto pItem = ::find(c.begin(), c.end(), target);
		cout << "find time:" << clock() - start << endl;
	}

	{
		start = clock();
		auto pItem = c.find(target);
		cout << "find time:" << clock() - start << endl;
	}
}

#include <unordered_set>
void STL6_test_unordered_multiset(long value)
{
	unordered_multiset<string> c;
	char buf[10];

	clock_t start = clock();

	for (long i = 0; i < value; ++i)
	{
		try
		{
			snprintf(buf, 10, "%d", rand());
			c.insert(string(buf)); // Will insert a suitable place
		}
		catch (exception& p)
		{
			cout << p.what() << endl;
		}
	}

	cout << "time:" << clock() - start << endl;
	cout << "size: " << c.size() << endl;
	cout << "maxsize: " << c.max_size() << endl;
	cout << "bucket_count:" << c.bucket_count() << endl;
	cout << "load_factor" << c.load_factor() << endl;
	cout << "max bucket count:" << c.max_bucket_count() << endl;
	cout << "max load factor: " << c.max_load_factor() << endl;

	for (int i = 0; i < 20; ++i)
	{
		cout << "bucket#" << i << "has:" << c.bucket_size(i) << endl; // NOTE
	}

	string target = get_a_target_string();
	{
		start = clock();
		auto pItem = ::find(c.begin(), c.end(), target);
		cout << "time:" << clock() - start << endl;
	}

	{
		start = clock();
		auto pItem = c.find(target);
		cout << "time:" << clock() - start << endl;
	}
}

#include <map>
void STL6_test_multimap(long value)
{
	multimap<long, string> c;
	char buf[10];

	clock_t start = clock();

	for (long i = 0; i < value; ++i)
	{
		try
		{
			snprintf(buf, 10, "%d", rand());
			c.insert(pair<long, string>(i, string(buf))); // NOTE
		}
		catch (exception& p)
		{
			cout << p.what() << endl;
		}
	}

	cout << "time:" << clock() - start << endl;
	cout << "size: " << c.size() << endl;
	cout << "maxsize: " << c.max_size() << endl;

	long target = get_a_target_long();

	{
		start = clock();
		auto pItem = c.find(target);
		cout << "time:" << clock() - start << endl;
	}
}

#include <unordered_map>
void STL6_test_unordered_multimap(long value)
{
	unordered_multimap<long, string> c;
	char buf[10];

	clock_t start = clock();

	for (long i = 0; i < value; ++i)
	{
		try
		{
			snprintf(buf, 10, "%d", rand());
			c.insert(pair<long, string>(i, string(buf))); // NOTE
		}
		catch (exception& p)
		{
			cout << p.what() << endl;
		}
	}

	cout << "time:" << clock() - start << endl;
	cout << "size: " << c.size() << endl;
	cout << "maxsize: " << c.max_size() << endl;

	long target = get_a_target_long();

	{
		start = clock();
		auto pItem = c.find(target);
		cout << "time:" << clock() - start << endl;
		cout << (*pItem).second << endl; // NOTE
	}
}

void STL2()
{
	int ia[6] = { 27, 210, 12, 47, 109, 83 };
	vector<int, allocator<int>> vi(ia, ia + 6);

	cout << count_if(vi.begin(), vi.end(), not1(bind2nd(less<int>(), 40)));

	for (auto am : vi)
	{
		am = 10;
	}

	for (auto& am : vi)
	{
		am = 10;
	}

	for (vector<int, allocator<int>>::iterator it = vi.begin(); it != vi.end(); ++it)
	{
		*it = 20;
	}
}

void _display_category(random_access_iterator_tag)
{
	cout << "randome_access_iterator_tag" << endl;
}

void _display_category(bidirectional_iterator_tag)
{
	cout << "bidirectional_iterator_tag" << endl;
}

void _display_category(forward_iterator_tag)
{
	cout << "forward_iterator_tag" << endl;
}

void _display_category(output_iterator_tag)
{
	cout << "output_iterator_tag" << endl;
}

void _display_category(input_iterator_tag)
{
	cout << "input_iterator_tag" << endl;
}

template<typename I>
void STL28_display_category(I itr)
{
	typename iterator_traits<I>::iterator_category cagy;
	_display_category(cagy);
}

void TestIterator()
{
	STL28_display_category(array<int, 10>::iterator());
	STL28_display_category(vector<int>::iterator());
	STL28_display_category(list<int>::iterator());
	STL28_display_category(forward_list<int>::iterator());
	STL28_display_category(deque<int>::iterator());
	STL28_display_category(set<int>::iterator());
}

class BBase
{
};

class Base2
{};

class Base : public BBase{};

class Sub : public Base, public Base2
{
public:
	Sub(int i)
	{

	}
	int a;
};

void Add(int a, int b)
{
	cout << a + b;
}

using namespace std::placeholders;

int main()
{
	tuple<Sub> t();

	cout << sizeof(string) << endl;

	Sub ssa{ 10 };

	auto bindTest = bind(Add, _1, 10);
	//bindTest(109);

	auto bindTest1 = bind(Add, _2, _1);
	bindTest1(100, 200);

	TestIterator();

	array<int, 10> aaa;

	cout << typeid(aaa).name() << endl;

	map<int, int> m;
	m[0] = 1;
	m[1] = 1;
	m.insert(pair<int, int>(2, 1));

	long value = 1000000;
	STL6_test_multiset(value);
	STL5_test_list(value);

	STL6_test_unordered_multiset(value);
	STL6_test_multimap(value);
	STL6_test_multiset(value);

	STL5_test_list(value);
	STL5_test_forwardlist(value);
	STL5_test_deque(value);

	STL4_test_vector(value);

	STL3_test_array();

	STL2();

    return 0;
}