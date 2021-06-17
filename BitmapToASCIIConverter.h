#pragma once
#using <System.Drawing.dll>

using namespace System::Drawing;
using namespace System;
ref class BitmapToASCIIConverter
{
public:

	BitmapToASCIIConverter(Bitmap^ bitmap);

	array<array<char>^>^ Convert();

	float Map(float valueToMap, float start1, float stop1, float start2, float stop2);

private:
	Bitmap^ _bitmap;
	System::String^ str = ".,:+*?%S#@";
	array<char>^ _asciiTable;
	
	array<array<char>^>^ result;
};

