#include<iostream>
#include<opencv2\opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char**argv)
{
	
	/*		相关API介绍：
					CV_EXPORTS_W Mat imread( const string& filename, int flags=1 );
							* filename 为要读取的图片路径
							* flags默认为1，表示按三通道彩色读入图像，设为0时将原图转成灰度图读入				

					CV_EXPORTS_W void namedWindow(const string& winname, int flags = WINDOW_AUTOSIZE);
							* winname 为创建的窗口名称，后续可以使用imshow来绑定同名窗口显示图片
							* flags默认为WINDOW_AUTOSIZE，此时窗口大小固定同图片大小一样，设为WINDOW_NORMAL则窗口可拉伸

					CV_EXPORTS_W void imshow(const string& winname, InputArray mat);
							* winname 为要要显示到的窗口名
							* mat为要显示的图像

					CV_EXPORTS_W bool imwrite( const string& filename, InputArray img,const vector<int>& params=vector<int>());
							* filename 为保存的图片文件名
							* img为要保存的图像
							* params表示为特定格式保存的参数编码
	*/

	Mat input = imread("test_images/opencv.jpg",0);
	namedWindow("input", CV_WINDOW_NORMAL);
	imshow("input", input);

	imwrite("gray_input.jpg", input);
	waitKey(0);

	return 0;
}