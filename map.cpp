/*
 * =====================================================================================
 *
 *       Filename:  map.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年11月04日 22时40分16秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include <map>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	map<string,int> words;
	string tword;
	int count = 0;
	while( cin >> tword)
	{
		words[tword]++;
		if(count > 2)
			break;
		count++;
	}

	map<string, int>::iterator it = words.begin();
	for( ; it != words.end(); ++it)
		cout <<" key:"<<it->first
			<<" values:"<<it->second<<endl;

	//map find
	it = words.find("ggj");
	if(it != words.end())
		cout <<"found map ggj, value: "<<it->second<<endl;

	//map count
	string search_word("ggj");
	if(words.count(search_word))
	{
		count = words[search_word];
		cout << "Map has found\n";
	}
	return 0;
}
