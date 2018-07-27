#include <iostream> 
#include <stdio.h>
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main(){
	// 读入图片
	Mat img = imread("pic.png");

	//配置点数 默认4个
	const int pointnum = 4;

	double a[pointnum];
	double b[pointnum];
	double max = 0;
	int maxindex = 0;

	//打开文件
	freopen("E:\\programs\\c++\\Drawpic\\Drawpic\\pos", "r", stdin);
	//while (scanf("[%lf, %lf]\n", &a[i], &b[i]) != EOF){

	//读入文件，并找到位置最低的点
	for (int i = 0; i<pointnum;i++){
		scanf("[%lf, %lf]\n", &a[i], &b[i]);
		if (b[i] > max){
			max = b[i];
			maxindex = i;
		}
	}

	//画线
	for (int i = 0; i < pointnum; i++){
		if (i == maxindex){
			continue;
		}
		line(img, Point(a[maxindex], b[maxindex]), Point(a[i], b[i]), Scalar(0, 0, 255),3);
	}

	imshow("face",img);

	// 等待60000 ms后窗口自动关闭
	waitKey(60000);
}
