#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class StreamBuffer
{
public:
	std::fstream stream;
	unsigned char buf[512];
	int fileIndex = 0;
	int bufIndex = 0;
	int validBuf = 0;

	StreamBuffer();
	StreamBuffer(std::string filename);

	unsigned char Pop();
	unsigned char Read(int offset);

	void Seek(int location);
	inline bool CanPop() { return !stream.eof() || bufIndex < validBuf; }

	unsigned char operator[](int offset);
	StreamBuffer& operator+=(int offset);
};

inline std::string SToLower(std::string& str)
{
	std::string hold = "";
	for (int i = 0; str[i] != '\0'; i++)
		hold += std::tolower(str[i]);
	return hold;
}