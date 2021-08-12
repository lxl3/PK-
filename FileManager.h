#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<map>
using namespace std;
class FileManager {
public:
	void parseLineToVector(string line,vector<string>&v);//解析单行数据
	map<string, map<string, string>>m;//解析数据后存放数据的容器
	void loadCSVData(string path, map<string, map<string, string>>&m);//加载数据
};
