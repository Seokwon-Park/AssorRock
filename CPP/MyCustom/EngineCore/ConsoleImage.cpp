#include "ConsoleImage.h"
#include <string>

ConsoleImage::~ConsoleImage()
{
	Release();
}

void ConsoleImage::Release()
{
	Pixels.clear();
}

void ConsoleImage::Create(int _X, int _Y, char _BaseChar)
{
	// 리스트 이니셜라이저
	ImageSize = {_X, _Y};

	// 얼마
	// Arr = new char* [_Y];
	Pixels.resize(_Y);
	for (size_t y = 0; y < _Y; y++)
	{
		Pixels[y].resize(_X + 1);
	}

	Clear(_BaseChar);
}

void ConsoleImage::Create(int _X, int _Y, std::vector<std::string> _Image)
{
	// 리스트 이니셜라이저
	ImageSize = { _X, _Y };

	// 얼마
	// Arr = new char* [_Y];
	Pixels.resize(_Y);
	for (size_t y = 0; y < _Y; y++)
	{
		Pixels[y].resize(_X + 1);
	}

	for (size_t y = 0; y < ImageSize.Y; y++)
	{
		for (size_t x = 0; x < ImageSize.X; x++)
		{
			Pixels[y][x] = _Image[y][x];
		}
		// 마지막라인에 0을 넣는다.
		Pixels[y][ImageSize.X] = 0;
	}
}

void ConsoleImage::Clear(char _Clearchar)
{
	for (size_t y = 0; y < ImageSize.Y; y++)
	{
		for (size_t x = 0; x < ImageSize.X; x++)
		{
			Pixels[y][x] = _Clearchar;
		}
		// 마지막라인에 0을 넣는다.
		Pixels[y][ImageSize.X] = 0;
	}
}

void ConsoleImage::SetPixel(FIntPoint _Pos, char _Char)
{
	// 화면 바깥에 그려지는것 막은것
	if (0 > _Pos.X || ImageSize.X <= _Pos.X)
	{
		return;
	}

	// 화면 바깥에 그려지는것 막은것.
	if (0 > _Pos.Y || ImageSize.Y <= _Pos.Y)
	{
		return;
	}

	Pixels[_Pos.Y][_Pos.X] = _Char; 
}

void ConsoleImage::Rotate()
{
	std::vector<std::vector<char>> NewImage(ImageSize.X, std::vector<char>(ImageSize.Y));

	for (int y = 0; y < ImageSize.Y; y++)
	{
		for (int x = 0; x < ImageSize.X; x++)
		{
			NewImage[x][ImageSize.Y-y-1] = Pixels[y][x];
		}
	}

	Pixels = NewImage;
}

void ConsoleImage::Copy(FIntPoint _Offset, ConsoleImage& _Image)
{
	// 2차원
	// 상대도 2차원
	for (int y = 0; y < _Image.ImageSize.Y; y++)
	{
		for (int x = 0; x < _Image.ImageSize.X; x++)
		{
			FIntPoint SetPos = _Offset + FIntPoint{ x, y };

			char X = _Image.GetPixel(x, y);
			if (X == ' ')continue;

			SetPixel(SetPos, X);
		}
	}
}