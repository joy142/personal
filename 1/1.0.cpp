#include <iostream>
#include <istream>
#include <streambuf>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
struct student{
	string id;
	string name;
	string grade;//����
	string a[20];//20�γ��ڼ�¼
	int mark;//���ڷ���
	double result; 
}stu[90],item;
int main()
{
	int cnt=0,i=0;
    ifstream csv_data("2.csv", ios::in);
    string line;
    if (!csv_data.is_open())
    {
        cout << "Error: opening file fail" << endl;
        exit(1);
    }
    istringstream sin;         //�������ַ���line���뵽�ַ���istringstream��
    vector<std::string> words; //����һ���ַ�������
    string word;
    // ��ȡ������
    getline(csv_data, line);
    // ��ȡ����
    while (getline(csv_data, line))
    {
        sin.clear();
        sin.str(line);
        words.clear();
        while (getline(sin, word, ',')) //���ַ�����sin�е��ַ�����field�ַ����У��Զ���Ϊ�ָ���
         {
            words.push_back(word); //��ÿһ���е��������push
            cout << word<<" ";
        }
        cout << endl;
        // do something
    }
    
    
    //��ʱ�Ѿ��õ�ÿ��ѧ����������ݣ�����˳��洢�ڽṹ���Ӧ��λ�����档
    int N;//��N�γ�� 
	scanf("%d",&N); 
	for(i=0;i<90;i++){
		stu[i].mark=100; //��ʼ�����ڷ���ÿ��Ϊ100�֣����ȱ��һ�ο�5�֡� 
	} 
	for(i=0;i<90;i++){
		for(j=0;j<N;j++){
			if(stu[i].a[j]==0){
				stu[i].mark-=5;
	        }
		}
	}
	//�õ�ÿ���˵ĳ����ܷ��� 
	//��ʼ����ÿ���˵����յ÷�result=rate1*grade(���㣩+rate2*mark(���ڷ�������
	double rate1,rate2;
	for(i=0;i<90;i++){
		stu[i].result=rate1*stu[i].grade+rate2*stu[i].mark;
	} 
	//�������򣬰���С��������������� 
	for(i=0;i<89;i++){
		for(j=0;j<89;j++){
			if(stu[j].result>stu[j+1].result){
				item=stu[j];
				stu[j]=stu[j+1];
				stu[j+1]=item;
			}
		}
	}
	//������򣬳��˿��԰�˳����ѧ�Ž��г�㡣
	int n;//����������Ҳ����Ϊ90�� 
	for(i=0;i<n;i++){
		printf("%d ",stu[i].id);
	} 
    csv_data.close();
    return 0;
}
