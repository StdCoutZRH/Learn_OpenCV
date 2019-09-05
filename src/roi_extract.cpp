#include<opencv2/opencv.hpp>
#include<iostream>
//#include<Windows.h>

using namespace cv;
using namespace std;

int main(int argc, char**argv)
{
	//get gray input image
	Mat input_image = imread("./whisper.jpg", 1);
	if (input_image.empty())
	{
		cout << "read input error!" << endl;
		return -1;
	}
	//imshow("input", input_image);

	int height = input_image.rows;
	int width = input_image.cols;

	//���ĵ�����
	int cy = height / 2, cx = width / 2;
	Rect rect(cx - 100, cy - 100, 200, 200);


	//ֱ�Ӹ�ֵ��ԭͼ�и�����ռ��ͬһ���ڴ�
	Mat roi_rect = input_image(rect);
	imshow("roi", roi_rect);

#if 0
	//�ı�ROI��ԭͼҲ��ı�
	roi_rect.setTo(Scalar(0, 0, 255));
	imshow("input", input_image);
	imshow("roi rect", roi_rect);
#endif

#if 1
	//��¡
	Mat roi_rect_copy = roi_rect.clone();
	//�ı�ROI��ԭͼ����ı�
	roi_rect_copy.setTo(Scalar(0, 0, 255));
	imshow("input", input_image);
	imshow("roi rect copy", roi_rect_copy);
#endif


	waitKey(0);
	destroyAllWindows();
	return 0;
}