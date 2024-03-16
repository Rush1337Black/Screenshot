#include <opencv2/opencv.hpp>
#include <vector>
#include <string>
#include <Windows.h>

#include "Window.h"


using namespace cv;
using namespace std;

int main()
{
	
	Window Window;


	Mat Screenshot = Window.Screenshot();
	imshow("output", Screenshot);
	waitKey(0);

	/*win.Screenshot();

	Mat Screenshot = win.Screenshot();
	imshow("output", Screenshot);
	waitKey(0);*/

	return 0;
}


/*  std::string ClassName = "UnityWndClass";
  std::string WindowName = "Albion Online Client";

  Window win(ClassName, WindowName);
  win.Screenshot();

  Mat Screenshot = win.Screenshot();
  imshow("output", Screenshot);
  waitKey(0);*/