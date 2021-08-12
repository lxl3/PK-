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
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	string firstline;
	ifs >> firstline;
	//cout << firstline << endl;
	//�������������ݷ�װ�ɺ���
	vector<string>v1;
	parseLineToVector(firstline, v1);
	/*for (vector<string>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << endl;
	}*/
	//׼����������
	//map<string, map<string, string>>m;
	string data;//��������
	while (ifs >> data)
	{
		//cout << data << endl;
		vector<string>vOtherdata;//���������ݴ�ŵ�������
		parseLineToVector(data, vOtherdata);
		//׼����һ��С����
		map<string, string>mSmall;
		//ƴ��С�����е�����
		for (int i = 0; i < v1.size(); i++)
		{
			mSmall.insert(make_pair(v1[i], vOtherdata[i]));
		}
		//��С�����е����ݷŵ���������
		m.insert(make_pair(vOtherdata[0], mSmall));
	}
	
}
