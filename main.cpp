#include"Magick++.h"
#include<string>
#include"Extensions.h"
#include"BitmapToASCIIConverter.h"
#using <System.Drawing.dll>


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


const int maxWidth = 350;
Bitmap^ ResizeBitmap(Bitmap^ bitmap)
{
	double newHeight = bitmap->Height / 1.5 * maxWidth / bitmap->Width;
	if (bitmap->Width > maxWidth || bitmap->Height > newHeight)
		bitmap = gcnew Bitmap(bitmap, Size(maxWidth, (int)newHeight));

	return bitmap;
}

[STAThread]
int main(int argc, char** argv)
{
	//Magick::InitializeMagick(*argv);
	OpenFileDialog^ openDlg = gcnew OpenFileDialog();
	openDlg->Filter = "Images | *.bmp; *.png; *.jpg; *.JPEG";

	Extensions ext;

	array<array<char>^>^ result;

	while (true)
	{
		Console::ReadLine();
		if (openDlg->ShowDialog() != DialogResult::OK)
			continue;

		Console::Clear();
		Bitmap^ bitmap = gcnew Bitmap(openDlg->FileName);
		bitmap = ResizeBitmap(bitmap);
		//System::Console::SetWindowSize(bitmap->Width + 100, bitmap->Height + 100);
		bitmap = ext.ToGrayscale(bitmap);

		BitmapToASCIIConverter converter(bitmap);
		result = converter.Convert();

		for (int i = 0; i < bitmap->Height; i++)
		{
			for (int j = 0; j < bitmap->Width; j++)
				System::Console::Write((char)result[i][j]);
			Console::Write("\n");
		}
		
		System::Console::SetCursorPosition(0, 0);
	}
	return 0;
}
