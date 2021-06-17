#include "Extensions.h"

Extensions::Extensions()
{
	avg = 0;
	pixel = Color::Gray;
}

Bitmap ^Extensions::ToGrayscale(Bitmap^ bitmap)
{

	for (int i = 0; i < bitmap->Height; i++)
	{
		for (int j = 0; j < bitmap->Width; j++)
		{
			pixel = bitmap->GetPixel(j, i);
			avg = (pixel->R + pixel->G + pixel->B) / 3;
			bitmap->SetPixel(j, i, Color::FromArgb(pixel->A, avg, avg, avg));
		}
	}
	return bitmap;
}
