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
	string grade;//绩点
	string a[20];//20次出勤记录
	int mark;//出勤分数
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
    istringstream sin;         //将整行字符串line读入到字符串istringstream中
    vector<std::string> words; //声明一个字符串向量
    string word;
    // 读取标题行
    getline(csv_data, line);
    // 读取数据
    while (getline(csv_data, line))
    {
        sin.clear();
        sin.str(line);
        words.clear();
        while (getline(sin, word, ',')) //将字符串流sin中的字符读到field字符串中，以逗号为分隔符
         {
            words.push_back(word); //将每一格中的数据逐个push
            cout << word<<" ";
        }
        cout << endl;
        // do something
    }
    
    
    //此时已经得到每个学生具体的数据，并按顺序存储在结构体对应的位置里面。
    int N;//第N次抽点 
	scanf("%d",&N); 
	for(i=0;i<90;i++){
		stu[i].mark=100; //初始换出勤分数每人为100分，如果缺勤一次扣5分。 
	} 
	for(i=0;i<90;i++){
		for(j=0;j<N;j++){
			if(stu[i].a[j]==0){
				stu[i].mark-=5;
	        }
		}
	}
	//得到每个人的出勤总分数 
	//开始计算每个人的最终得分result=rate1*grade(绩点）+rate2*mark(出勤分数）；
	double rate1,rate2;
	for(i=0;i<90;i++){
		stu[i].result=rate1*stu[i].grade+rate2*stu[i].mark;
	} 
	//进行排序，按从小到大排序进行排序 
	for(i=0;i<89;i++){
		for(j=0;j<89;j++){
			if(stu[j].result>stu[j+1].result){
				item=stu[j];
				stu[j]=stu[j+1];
				stu[j+1]=item;
			}
		}
	}
	//完成排序，抽人可以按顺序用学号进行抽点。
	int n;//抽点的人数，也可以为90； 
	for(i=0;i<n;i++){
		printf("%d ",stu[i].id);
	} 
    csv_data.close();
    return 0;
}
