#include "FileManager.h"
void FileManager::parseLineToVector(string line, vector<string>&v)
{
	int pos = 0;
	int start = 0;
	while (true)
	{
		
		int pos = line.find(",", start);
		if (pos == -1)
		{
			string temp= line.substr(start,line.size()- start);
			v.push_back(temp);
			break;
		}
		string temp = line.substr(start, pos - start);
		v.push_back(temp);
		start = pos + 1;
	}
}


void FileManager::loadCSVData(string path, map<string, map<string, string>>& m)
{
	ifstream ifs(path);
	if (!ifs.is_open())
	{
		cout << "文件打开失败：" << endl;
		return;
	}
	string firstline;
	ifs >> firstline;
	//cout << firstline << endl;
	//将解析单行数据封装成函数
	vector<string>v1;
	parseLineToVector(firstline, v1);
	/*for (vector<string>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << endl;
	}*/
	//准备最大的容器
	//map<string, map<string, string>>m;
	string data;//其他数据
	while (ifs >> data)
	{
		//cout << data << endl;
		vector<string>vOtherdata;//将其他数据存放到容器中
		parseLineToVector(data, vOtherdata);
		//准备出一个小容器
		map<string, string>mSmall;
		//拼接小容器中的数据
		for (int i = 0; i < v1.size(); i++)
		{
			mSmall.insert(make_pair(v1[i], vOtherdata[i]));
		}
		//将小容器中的数据放到大容器中
		m.insert(make_pair(vOtherdata[0], mSmall));
	}
	
}
