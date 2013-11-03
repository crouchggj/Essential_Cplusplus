/*
 * =====================================================================================
 *
 *       Filename:  gp_less_than.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年11月03日 20时59分48秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> less_than_10(const vector<int> &vec)
{
	vector<int> nvec;
	for(int ix = 0; ix < vec.size(); ix++)
	{
		if(vec[ix] < 10)
			nvec.push_back(vec[ix]);
	}
	return nvec;
}

bool less_than( int v1, int v2)
{
	return (v1 < v2) ? true : false;
}

bool greater_than( int v1, int v2)
{
	return (v1 > v2) ? true : false;
}

vector<int> filter(const vector<int> &vec, int filter_value, bool (*pred)(int, int))
{
	vector<int> nvec;
	for(int ix = 0; ix < vec.size(); ix++)
	{
		if(pred(vec[ix], filter_value))
			nvec.push_back(vec[ix]);
	}
	return nvec;
}

int count_occurs(const vector<int> &vec, int val)
{
	vector<int>::const_iterator iter = vec.begin();
	int occurs_count = 0;
	while((iter = find(iter, vec.end(),val)) != vec.end() )
	{
		occurs_count++;
		iter++;
	}
	return occurs_count;
}

void display(const vector<int> &dis_vec)
{
	vector<int>::const_iterator iter = dis_vec.begin();
	while(iter < dis_vec.end())
	{
		cout<<*iter<<",";
		iter++;
	}
	cout<<"\n";
}

int main()
{
	int test_array[] = {42,11,34,42,13};
	int test_array_1[] = {1,1,1,1,1};
	//vector<int> test_vec(5,1);
	vector<int> test_vec(test_array,test_array + sizeof(test_array)/ sizeof(int));
	vector<int> test_vec1(test_array_1,test_array_1 + sizeof(test_array_1)/ sizeof(int));
	int find_num = count_occurs(test_vec, 42);
	cout <<"Vector has found numeric 42:"
		<<find_num<<"\n";
	display(test_vec);
	sort(test_vec.begin(),test_vec.end(),greater<int>());
	cout<<"after sort:\n";
	display(test_vec);

	cout<<"transform:\n";
	vector<int> transform_vec(test_vec.size());
	transform(test_vec.begin(),test_vec.end(),test_vec1.begin(),transform_vec.begin(),plus<int> ());
	display(transform_vec);
	return 0;
}
