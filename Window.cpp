#include "Window.h"

cv::Mat Window::Screenshot()
{
   HWND HandleWindow = FindWindow(NULL, L"ZETFLIX");
   HDC WindowContextHandle;
   HDC WindowCompatible;

   HBITMAP BitMapImg;
   BITMAPINFOHEADER BitMapInfo{};

   int Height;
   int Width;
   int SrcHeight;
   int SrcWidth;

   float WindowsDisplaySettingsSize = 1;

   RECT WindowSize;
   cv::Mat Image;

   WindowContextHandle = GetDC(HandleWindow);
   WindowCompatible = CreateCompatibleDC(WindowContextHandle);
   SetStretchBltMode(WindowCompatible, COLORONCOLOR);

   GetClientRect(HandleWindow, &WindowSize);

   SrcHeight = (int)((float)WindowSize.bottom * WindowsDisplaySettingsSize);
   SrcWidth = (int)((float)WindowSize.right * WindowsDisplaySettingsSize);
   Height = WindowSize.bottom / 1;
   Width = WindowSize.right / 1;

   Image.create(Height, Width, CV_8UC4);

   BitMapImg = CreateCompatibleBitmap(WindowContextHandle, Width, Height);
   BitMapInfo.biSize = sizeof(BITMAPINFOHEADER);
   BitMapInfo.biWidth = Width;
   BitMapInfo.biHeight = -Height;
   BitMapInfo.biPlanes = 1;
   BitMapInfo.biBitCount = 32;
   BitMapInfo.biCompression = BI_RGB;
   BitMapInfo.biSizeImage = 0;
   BitMapInfo.biXPelsPerMeter = 0;
   BitMapInfo.biYPelsPerMeter = 0;
   BitMapInfo.biClrUsed = 0;
   BitMapInfo.biClrImportant = 0;

   SelectObject(WindowCompatible, BitMapImg);
   StretchBlt(WindowCompatible, 0, 0, Width, Height, WindowContextHandle, 0, 0, SrcWidth, SrcHeight, SRCCOPY);
   GetDIBits(WindowCompatible, BitMapImg, 0, Height, Image.data, (BITMAPINFO*)&BitMapInfo, DIB_RGB_COLORS);

   DeleteObject(BitMapImg);
   DeleteDC(WindowCompatible);
   ReleaseDC(HandleWindow, WindowContextHandle);

   return Image;
}

//TEXT("UnityWndClass"), TEXT("Albion Online Client")