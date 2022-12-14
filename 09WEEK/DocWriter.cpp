#include "DocWriter.h"
#include <iostream>
#include <fstream>

using namespace std;

DocWriter::DocWriter()
	:DocWriter("noFileName", "noContent")
{
}

DocWriter::~DocWriter()
{
	cout << "DocWriter 소멸자" << endl;
}

DocWriter::DocWriter(const string& fileName, const string& content)
	:fileName(fileName), content(content)
{
	cout << "DocWriter 생성자" << endl;
}

void DocWriter::setFileName(const string& fileName)
{
	this->fileName = fileName;
}

void DocWriter::setContent(const string& content)
{
	this->content = content;
}

void DocWriter::write()
{
	ofstream fout(fileName); // 파일 생성
	fout << "202014191 전유정" << endl;
	fout << content << endl;
}

DocWriter& DocWriter::operator<<(const string& str)
{
	content += str + "\n";
	return *this;
}

DocWriter& DocWriter::operator<<(const int& num)
{
	content += to_string(num) + "\n";
	return *this;
}

void DocWriter::readFile()
{
	ifstream fin(fileName);
	if (fin.is_open()) {
		while (!fin.fail()) {
			string str;
			getline(fin, str);
			cout << str << endl;
		}
	}
}
