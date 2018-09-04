#pragma once
#include <string>
#include <list>
#include <unordered_map>
#include <map>
#include <vector>

#include <Windows.h>
#include "types.h"
#include "StringUtils.h"
#include <iostream>
#include <fstream>


struct InsensitiveCompare
{
	bool operator() (const std::string& a, const std::string& b) const
	{
		return _stricmp(a.c_str(), b.c_str()) < 0;
	}
};

class File
{
private:
	char* filename;
public:
	File(char* filesname) {
		this->filename = filesname;
	}

	void ClearFile();

	void Write(char* text);
	void Append(char* text, bool newLine = true);
	void AppendAtLine(char* text, int line);
	void WriteAtLine(char* text, int line);

	void Write(int text);
	void Append(int text, bool newLine = true);
	void AppendAtLine(int text, int line);
	void WriteAtLine(int text, int line);

	void Write(float text);
	void Append(float text, bool newLine = true);
	void AppendAtLine(float text, int line);
	void WriteAtLine(float text, int line);

	void Write(double text);
	void Append(double text, bool newLine = true);
	void AppendAtLine(double text, int line);
	void WriteAtLine(double text, int line);

	void Write(bool text);
	void Append(bool text, bool newLine = true);
	void AppendAtLine(bool text, int line);
	void WriteAtLine(bool text, int line);

	std::vector<std::string> readFileContents();
	std::string readLine(int line);
};
void File::ClearFile()
{
	std::ofstream ourFile(this->filename);
	try
	{
		ourFile.write("", NULL);
		ourFile.close();
	}
	catch (...) {}
}

void File::Write(char * text)
{
	std::ofstream ourFile(this->filename);
	try
	{
		ourFile.write(text, strlen(text));
		ourFile.close();
	}
	catch (...) {}
}

void File::Append(char * text, bool newLine)
{
	std::fstream ourFile(this->filename, std::ios::app);
	try
	{
		char* writing = _strdup(((newLine ? "\n" : NULL) + (std::string)text).c_str());
		ourFile.write(writing, strlen(writing));
		ourFile.close();
	}
	catch (...) {}
}

void File::AppendAtLine(char * text, int line)
{
	std::fstream ourFile(this->filename, std::ios::app);
	std::vector<std::string> fileContents = readFileContents();
	if (line > fileContents.size()) return;
	int length = (int)fileContents.size();
	ClearFile();
	for (int i = 0; i < length + 1; i++)
	{
		if (i < line)
		{
			if (i == 0) Write(_strdup(fileContents.at(i).c_str()));
			else Append(_strdup(fileContents.at(i).c_str()));
		}
		if (i == line)
		{
			Append(text);
		}
		if (i > line)
		{
			Append(_strdup(fileContents.at(i - 1).c_str()));
		}
	}
}

void File::WriteAtLine(char * text, int line)
{
	std::fstream ourFile(this->filename, std::ios::app);
	std::vector<std::string> fileContents = readFileContents();
	if (line > fileContents.size()) return;
	int length = (int)fileContents.size();
	ClearFile();
	for (int i = 0; i < length; i++)
	{
		if (i < line)
		{
			if (i == 0) Write(_strdup(fileContents.at(i).c_str()));
			else Append(_strdup(fileContents.at(i).c_str()));
		}
		if (i == line)
		{
			Append(text);
		}
		if (i > line)
		{
			Append(_strdup(fileContents.at(i).c_str()));
		}
	}
}

void File::Write(int text)
{
	std::ofstream ourFile(this->filename);
	try
	{
		ourFile.write(_strdup((std::to_string(text)).c_str()), strlen(_strdup((std::to_string(text)).c_str())));
		ourFile.close();
	}
	catch (...) {}
}

void File::Append(int text, bool newLine)
{
	std::fstream ourFile(this->filename, std::ios::app);
	try
	{
		char* writing = _strdup(((newLine ? "\n" : NULL) + std::to_string(text)).c_str());
		ourFile.write(writing, strlen(writing));
		ourFile.close();
	}
	catch (...) {}
}

void File::AppendAtLine(int text, int line)
{
	char* writing = _strdup((std::to_string(text).c_str()));
	AppendAtLine(writing, line);
}

void File::WriteAtLine(int text, int line)
{
	char* writing = _strdup((std::to_string(text).c_str()));
	WriteAtLine(writing, line);
}

void File::Write(float text)
{
	std::ofstream ourFile(this->filename);
	try
	{
		ourFile.write(_strdup((std::to_string(text)).c_str()), strlen(_strdup((std::to_string(text)).c_str())));
		ourFile.close();
	}
	catch (...) {}
}

void File::Append(float text, bool newLine)
{
	std::fstream ourFile(this->filename, std::ios::app);
	try
	{
		char* writing = _strdup(((newLine ? "\n" : NULL) + std::to_string(text)).c_str());
		ourFile.write(writing, strlen(writing));
		ourFile.close();
	}
	catch (...) {}
}

void File::AppendAtLine(float text, int line)
{
	char* writing = _strdup((std::to_string(text).c_str()));
	AppendAtLine(writing, line);
}

void File::WriteAtLine(float text, int line)
{
	char* writing = _strdup((std::to_string(text).c_str()));
	WriteAtLine(writing, line);
}

void File::Write(double text)
{
	std::ofstream ourFile(this->filename);
	try
	{
		ourFile.write(_strdup((std::to_string(text)).c_str()), strlen(_strdup((std::to_string(text)).c_str())));
		ourFile.close();
	}
	catch (...) {}
}

void File::Append(double text, bool newLine)
{
	std::fstream ourFile(this->filename, std::ios::app);
	try
	{
		char* writing = _strdup(((newLine ? "\n" : NULL) + std::to_string(text)).c_str());
		ourFile.write(writing, strlen(writing));
		ourFile.close();
	}
	catch (...) {}
}

void File::AppendAtLine(double text, int line)
{
	char* writing = _strdup((std::to_string(text).c_str()));
	AppendAtLine(writing, line);
}

void File::WriteAtLine(double text, int line)
{
	char* writing = _strdup((std::to_string(text).c_str()));
	WriteAtLine(writing, line);
}

void File::Write(bool text)
{
	std::ofstream ourFile(this->filename);
	try
	{
		ourFile.write(text ? "true" : "false", strlen(text ? "true" : "false"));
		ourFile.close();
	}
	catch (...) {}
}

void File::Append(bool text, bool newLine)
{
	std::fstream ourFile(this->filename, std::ios::app);
	try
	{
		std::string stringWrite = newLine ? "\n" : NULL;
		stringWrite = stringWrite + (text ? "true" : "false");
		char* writing = _strdup(stringWrite.c_str());
		ourFile.write(writing, strlen(writing));
		ourFile.close();
	}
	catch (...) {}
}

void File::AppendAtLine(bool text, int line)
{
	std::string writingString = text ? "true" : "false";
	char* writing = _strdup(writingString.c_str());
	AppendAtLine(writing, line);
}

void File::WriteAtLine(bool text, int line)
{
	std::string writingString = text ? "true" : "false";
	char* writing = _strdup(writingString.c_str());
	WriteAtLine(writing, line);
}

std::vector<std::string> File::readFileContents()
{
	std::string currentLine;
	std::vector<std::string> returningValue;
	std::ifstream ourFile(this->filename);
	try
	{
		while (std::getline(ourFile, currentLine))
		{
			returningValue.push_back(currentLine);
		}
		ourFile.close();
	}
	catch (...) {}
	return returningValue;
}

std::string File::readLine(int line)
{
	std::vector<std::string> fileContents = readFileContents();
	std::string returningValue;
	try
	{
		returningValue = fileContents.at(line);
	}
	catch (...) {}
	return returningValue;
}