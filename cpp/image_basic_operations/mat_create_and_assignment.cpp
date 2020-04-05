/*
Mat ����
*/

#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main(int argc, char**argv)
{
	Mat input_image = imread("test_images/opencv.jpg");
	if (input_image.empty())
	{
		cout << "read input error!" << endl;
		return -1;
	}
	imshow("input", input_image);

	//��¡:��ԭͼƬռ�в�ͬ�ڴ�ռ�
	Mat clone_img = input_image.clone();
	imshow("clone", clone_img);

	//����:��ԭͼƬռ�в�ͬdata block
	Mat copy_img;
	input_image.copyTo(copy_img);
	imshow("copy", copy_img);

	//ֱ�Ӹ�ֵ:��ԭͼͬһ��data block
	Mat assign_img = input_image;
	imshow("assign", assign_img);

	//�����հ�ͼ��
	Mat empty_1 = Mat::zeros(input_image.size(), input_image.type());
	imshow("empty_1", empty_1);

	//�Զ����С Size()
	Mat empty_2 = Mat::zeros(Size(200, 200), input_image.type());
	imshow("empty_2", empty_2);
	Mat empty_3 = Mat::ones(Size(300, 300), CV_8UC3);
	imshow("empty_3", empty_3);

	//�Զ����˲���ʱ�õ����Զ������˷���
	//�����<<����
	//	[0, -1, 0,
	//	 -1, 5, -1,
	//   0, -1, 0]
	Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);

	waitKey(0);
	destroyAllWindows();

	return 0;
}