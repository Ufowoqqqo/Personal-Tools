//by oql
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <ctime>
#include <string>
#include <cstring>
#include <fstream>
#include <unistd.h>

using namespace std;

#ifndef _CLOCK_T_DEFINED
typedef long clock_t;
#define _CLOCK_T_DEFINED
#endif

#define CLOCKS_PER_SEC ((clock_t)1000)

clock_t clock( void );


ifstream fin("get.txt");

string name;
int l,r;
string NowWay()
{
      char buf[80];   
      getcwd(buf,sizeof(buf));
      string s = buf;
      return s;
}
string StrToInt(int x)
{
	string s;
	s.clear();
	while(x)
	{
		s = char(x%10 + 48) + s;
		x/=10;
	}
	return s;
}
int main()
{
	string now = NowWay();
	fin>>name>>l>>r;
	system(("md "+now+"\\data").c_str());//创建一个文件夹
	system(("md "+now+"\\data\\"+name).c_str());//创建一个文件夹
	
	long time=0,st,en;
	
	for(int i=l;i<=r;i++)
	{
		system("cls");
		printf("正在制作第%d个数据",i-l+1);
		string nsum = StrToInt(i);
		system("data.exe");
		
		st = clock();
		
		system( (name+".exe").c_str() );
		
		en = clock();
		
		time += en-st;
		
		system( ("ren "+now+"\\"+name+".in "+nsum+ ".in ").c_str() );
		system( ("ren "+now+"\\"+name+".out "+nsum+".out").c_str() );
		system( ("move "+now+"\\"+nsum+".in "+now+"\\data\\"+name+"\\").c_str() );
		system( ("move "+now+"\\"+nsum+".out "+now+"\\data\\"+name+"\\").c_str() );
	}
	system("cls");
	printf("制作数据完毕!");
	printf("\n程序平均用时%.5f",(double)(time)/(1000.0*(r-l+1.0)));
	Sleep(1300);
	return 0;
}
