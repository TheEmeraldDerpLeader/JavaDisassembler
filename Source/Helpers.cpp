#include "Helpers.hpp"

StreamBuffer::StreamBuffer()
{
	for (int i = 0; i < 512; i++)
		buf[i] = 0;
}
StreamBuffer::StreamBuffer(std::string filename)
{
	stream = std::fstream(filename, std::ios::binary | std::ios::in | std::ios::out);
	Seek(0);
}

unsigned char StreamBuffer::Pop()
{
	if (bufIndex>=validBuf)
	{
		Seek(fileIndex+bufIndex);
		bufIndex = 1;
		return buf[0];
	}
	else
	{
		bufIndex++;
		return buf[bufIndex-1];
	}
}

unsigned char StreamBuffer::Read(int offset)
{
	if (offset >= 512)
	{
		std::cout << "Cannot read past end of buffer\n";
		abort();
	}
	if (bufIndex+offset >= validBuf)
		Seek(fileIndex+bufIndex);
	if (bufIndex+offset >= validBuf)
		return 'X';
	else
		return buf[bufIndex+offset];
}

void StreamBuffer::Seek(int location)
{
	fileIndex = location;
	bufIndex = 0;

	stream.clear();
	stream.seekg(location);
	stream.read(reinterpret_cast<char*>(buf),512);
	validBuf = stream.gcount();
}

unsigned char StreamBuffer::operator[](int offset)
{
	return Read(offset);
}

StreamBuffer& StreamBuffer::operator+=(int offset)
{
	bufIndex += offset;
	return *this;
}
