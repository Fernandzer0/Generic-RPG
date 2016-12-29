#include "CSV.h"



CSV::CSV(string fileName)
{
	_file.open(fileName, ios::in);
	if (_file.fail())
		throw std::invalid_argument("File failed to load! " + fileName);

	string headers = NextLine();
	_headers = ParseTokens(headers);
	_numColumns = _headers.size();

	while (!_file.eof()) {
		string nextLine = NextLine();
		_data.push_back(ParseTokens(nextLine, _numColumns));
	}
}


CSV::~CSV()
{
}

string CSV::NextLine() {
	string input;
	getline(_file, input);
	return input;
}

vector<string> CSV::ParseTokens(string input, int numColumns) {
	bool parsingHeaders = numColumns == -1;

	vector<string> tokens;
	bool quoted = false;
	string tok = "";
	for (int i = 0; i < input.size(); i++) {
		char c = input[i];

		if (c == '"') {
			quoted = !quoted;
		}
		else {
			if (quoted) {
				tok += c;
			}
			else {
				if (c == ',') {
					tokens.push_back(tok);
					tok = "";
				}
				else {
					tok += c;
				}
			}
		}
	}
	if (!tok.empty())
		tokens.push_back(tok);
	tok = "";

	for (int i = tokens.size(); i < _numColumns && !parsingHeaders; i++) {
		tokens.push_back("");
	}
	for (auto it = tokens.begin(); it != tokens.end(); it++) {
		cout << *(it) << " ";
	}
	cout << endl;
	return tokens;
}

vector<string> CSV::GetHeaders() {
	return _headers;
}

vector<vector<string>> CSV::GetData() {
	return _data;
}