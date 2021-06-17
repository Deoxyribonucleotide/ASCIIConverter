#pragma once
#using <System.Drawing.dll>

using namespace System::Drawing;

ref class Extensions
{
public:
	Extensions();

	Bitmap^ ToGrayscale(Bitmap^ bitmap);

private:
	int avg;
	Color^ pixel;
};

