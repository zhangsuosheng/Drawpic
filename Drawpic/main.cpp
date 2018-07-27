#include <iostream> 
#include <stdio.h>
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main(){
	// ����ͼƬ
	Mat img = imread("pic.png");

	//���õ��� Ĭ��4��
	const int pointnum = 4;

	double a[pointnum];
	double b[pointnum];
	double max = 0;
	int maxindex = 0;

	//���ļ�
	freopen("E:\\programs\\c++\\Drawpic\\Drawpic\\pos", "r", stdin);
	//while (scanf("[%lf, %lf]\n", &a[i], &b[i]) != EOF){

	//�����ļ������ҵ�λ����͵ĵ�
	for (int i = 0; i<pointnum;i++){
		scanf("[%lf, %lf]\n", &a[i], &b[i]);
		if (b[i] > max){
			max = b[i];
			maxindex = i;
		}
	}

	//����
	for (int i = 0; i < pointnum; i++){
		if (i == maxindex){
			continue;
		}
		line(img, Point(a[maxindex], b[maxindex]), Point(a[i], b[i]), Scalar(0, 0, 255),3);
	}

	imshow("face",img);

	// �ȴ�60000 ms�󴰿��Զ��ر�
	waitKey(60000);
}
