#include "BitmapToASCIIConverter.h"

BitmapToASCIIConverter::BitmapToASCIIConverter(Bitmap^ bitmap)
{
    //_asciiTable = { '.',',',':','+','*','?','%','S','#','@' };
	Array::Resize(_asciiTable, 10);
	for (int i = 0; i < str->Length; i++)
	{
		_asciiTable[i] = str[i];
	}
	_bitmap = bitmap;
}

array<array<char>^>^ BitmapToASCIIConverter::Convert()
{
	Array::Resize(result, _bitmap->Height);

	for (int i = 0; i < _bitmap->Height; i++)
	{
		Array::Resize(result[i], _bitmap->Width);
		for (int j = 0; j < _bitmap->Width; j++)
		{
			int mapIndex = (int)Map(_bitmap->GetPixel(j, i).R, 0, 255, 0, _asciiTable->Length - 1);
			result[i][j] = _asciiTable[mapIndex];
		}
	}
	return result;
}

float BitmapToASCIIConverter::Map(float valueToMap, float start1, float stop1, float start2, float stop2)
{
	return ((valueToMap - start1) / (stop1 - start1)) * (stop2 - start2) + start2;
}

