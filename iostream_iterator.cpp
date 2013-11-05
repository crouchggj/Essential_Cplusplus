/*
 * =====================================================================================
 *
 *       Filename:  iostream_iterator.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年11月05日 21时37分31秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
	//string word;
	//vector<string > text;
	//int count = 0;
	//while( cin >> word)
	//{
		//text.push_back(word);
		//if(count > 5)
			//break;
		//else
			//count++;
	//}
	//sort(text.begin(), text.end());

	//for( int ix=0; ix < text.size(); ix++)
		//cout <<text[ix]<<' ';

	//cout<<"\n"<<endl;
	//

	ifstream in_file( "input_file.txt");
	ofstream output_file( "output_file.txt");
	if( !in_file || !output_file)
	{
		cerr << "!! Unable to open the necessary file \n";
		return -1;
	}

	istream_iterator< string > is(in_file);
	istream_iterator< string > eof;

	vector<string> text;
	copy(is, eof, back_inserter(text));

	sort(text.begin(), text.end());

	ostream_iterator<string> os(output_file, " ");
	copy(text.begin(), text.end(), os);
}
