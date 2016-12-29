#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class CSV
{
private:
	vector<string> _headers;
	vector<vector<string>> _data;
	ifstream _file;
	int _numColumns;

	string NextLine();
	vector<string> ParseTokens(string input, int numColumns = -1);
public:
	CSV(string fileName);
	~CSV();
	vector<string> GetHeaders();
	vector<vector<string>> GetData();
};

