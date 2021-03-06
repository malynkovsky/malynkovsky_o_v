#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
	int height = 60, width = 768;
	Mat result_image(Mat::zeros(height * 2, width, CV_8UC1));//�������������� �����������
	//c����� �������� (�������������, ������� 8 ���), ��� ������� �������������� ��������
	Mat img(Mat::zeros(height, width, CV_8UC1));
	//��������� ���������� ���, ����� ��������� �������� �� ������� � ������ (����� �� 3 ��-�� ������� ��������)
	for (int col = 0; col < width; col += 1) {
		for (int row = 0; row < height; row += 1) {
			img.at<uchar>(Point(col, row)) = col / 3;
		}
	}
	//�������� �������� � ������� ����� ��������������� �����������, � � ���� ��������� �����-��������� � ������������� 2.4
	img.copyTo(result_image(Rect(0, 0, width, height)));
	img.convertTo(img, CV_64FC1, 1.0 / 255);//������� � float, 1/255 ��������, ��� ������ �������� ����� �������� �� 255
	cv::pow(img, 2.4, img);//���������� � ������� �������� � ������ �������
	img.convertTo(img, CV_8UC1, 255);//����������� � ��������� ���� ������
	//�������� ����������������� ����������� � ������ ����� ��������������� �����������
	img.copyTo(result_image(Rect(0, height, width, height)));
	//������� ���������
	namedWindow("Gradient and gamma-corrected gradient - 1", 1);
	imshow("Gradient and gamma-corrected gradient - 1", result_image);




	Mat result_image2(Mat::zeros(height * 2, width, CV_8UC1));//�������������� �����������
	//c����� �������� (�������������, ������� 8 ���), ��� ������� �������������� ��������
	Mat img2(Mat::zeros(height, width, CV_8UC1));
	//��������� ���������� ���, ����� ��������� ����������� ������� �� ������� � ������ (�� 5 � ����� ������)
	for (int col = 0; col < width; col += 1) {
		for (int row = 0; row < height; row += 1) {
			img2.at<uchar>(Point(col, row)) = 5 + col / 30 * 10;
		}
	}
	//�������� �������� � ������� ����� ��������������� �����������, � � ���� ��������� �����-��������� � ������������� 2.4
	img2.copyTo(result_image2(Rect(0, 0, width, height)));
	img2.convertTo(img2, CV_64FC1, 1.0 / 255);//������� � float, 1/255 ��������, ��� ������ �������� ����� �������� �� 255
	cv::pow(img2, 2.4, img2);//���������� � ������� �������� � ������ �������
	img2.convertTo(img2, CV_8UC1, 255);//����������� � ��������� ���� ������
	//�������� ����������������� ����������� � ������ ����� ��������������� �����������
	img2.copyTo(result_image2(Rect(0, height, width, height)));
	//������� ���������
	namedWindow("Gradient and gamma-corrected gradient - 2", 1);
	imshow("Gradient and gamma-corrected gradient - 2", result_image2);


	Mat save_arr[2] = { result_image, result_image2 };
	Mat save;
	vconcat(save_arr, 2, save);
	imwrite("lab01.png", save);
	waitKey(0);
	return 0;
}