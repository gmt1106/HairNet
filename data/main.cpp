#include <iostream>
#include <vector>
#include <string>
#include <io.h>
#include <random>
#include <time.h>
#include <stdlib.h>
#include "hair.h"
#include "head.h"

using namespace std;

const string input_path = "D:\\Documents\\Visual Studio 2017\\Project\\graphics\\hair\\hairstyles\\";
const string coutput_path = "output//";
const int projection_size = 256;
const int grid = 32;

void getFiles(const string& path, vector<string>& files);

int main()
{
	srand((unsigned)(time(NULL)));
	Hair* hair;

	// 投影盒
	float size = 0.6;
	Vec bbox_center = Vec(0, 1.65, 0);
	float scale = projection_size / size;

	// 采样点参数
	Vec head_cneter = Vec(0, 1.77, 0);
	short* mask = new short[grid*grid]{ 0 };
	vector<int> idx;

	// 输入文件
	vector<string> data_files;
	getFiles(input_path, data_files);
	
	hair = new Hair("strands00001.data");
	hair->get_interpolate_param(head_cneter, 30, grid, idx, mask);
	delete hair;

	for (int i = 0; i < data_files.size(); ++i) {
		cout << "working on " << data_files[i] << endl;
		hair = new Hair(data_files[i].c_str());
		hair->train_x(projection_size, scale, bbox_center);
		hair->train_y(grid, idx, mask);
		hair->rotate(rand() % 40 + 5);
		hair->train_x(projection_size, scale, bbox_center);
		hair->train_y(grid, idx, mask);
		hair->rotate(-(rand() % 40 + 5));
		hair->train_x(projection_size, scale, bbox_center);
		hair->train_y(grid, idx, mask);

		delete hair;

		hair = new Hair(data_files[i].c_str());
		hair->flip();
		hair->train_x(projection_size, scale, bbox_center);
		hair->train_y(grid, idx, mask);
		hair->rotate(rand() % 40 + 5);
		hair->train_x(projection_size, scale, bbox_center);
		hair->train_y(grid, idx, mask);
		hair->rotate(-(rand() % 40 + 5));
		hair->train_x(projection_size, scale, bbox_center);
		hair->train_y(grid, idx, mask);

		delete hair;
	}

    return 0;
}


void getFiles(const string& path, vector<string>& files)
{
	//文件句柄  
	intptr_t hFile = 0;
	//文件信息  
	struct _finddata_t fileinfo;
	if ((hFile = _findfirst((path+"*.data").c_str(), &fileinfo)) != -1) {
		do {
			files.push_back(path+fileinfo.name);
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}