#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<map>
using namespace std;
class FileManager {
public:
	void parseLineToVector(string line,vector<string>&v);//������������
	map<string, map<string, string>>m;//�������ݺ������ݵ�����
	void loadCSVData(string path, map<string, map<string, string>>&m);//��������
};
