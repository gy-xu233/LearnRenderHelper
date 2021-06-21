#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#include <vector>
#include <map>
#include <initializer_list>
#include <stdexcept>
#include <functional>
#include <ostream>
#include <sstream>
#include <iostream>
//#include "uoin.h"
#include "RenderHelp.h"
int main()
{
	const int len = 5;
	Vector<len,int> v1;
	int a[len] = { 1,2,3,4,5 };
	Vector<len,int> v2(a);
	Vector<5, int> v3 = { 1,2,4,8,16 };
	Vector<len, int> v4(v3);
	const Vector<len, int> v5(v4);
	std::cout << "------const test-----------" << std::endl;
	for (int i = 0; i < len; i++)
	{
		std::cout << v5[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "----load and save-----------" << std::endl;
	v3.load(a);
	for (int i = 0; i < len; i++)
	{
		std::cout << v3[i] << " ";
	}
	std::cout << std::endl;
	v4.save(a);
	for (int i = 0; i < len; i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
	//system("pause");

	std::cout<<"------2021年6月21日测试--------"<<std::endl;

	std::cout<<"------特化2"<<std::endl;
    const int len2 = 2;
	Vector<len2,int> vv1;
	int aa[len2] = { 1,1 };
	Vector<len2,int> vv2(aa);
	Vector<2, int> vv3 = { 1,2};
	Vector<len2, int> vv4(vv3);
	const Vector<len2, int> vv5(vv4);
	std::cout << "------const test-----------" << std::endl;
	for (int i = 0; i < len2; i++)
	{
		std::cout << vv5[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "----load and save-----------" << std::endl;
	vv3.load(aa);
	std::cout << vv3.xy1()<<";"<<vv3.xy11()<<";"<<std::endl;
	std::cout << vv3.xy()<<"=?";
	for (int i = 0; i < len2; i++)
	{
		std::cout << vv3[i] << " ";
	}

	std::cout << std::endl;
	vv4.save(aa);
	std::cout << vv4.u <<","<< vv4.v <<"=?";
	for (int i = 0; i < len2; i++)
	{
		std::cout << aa[i] << " ";
	}
	std::cout << std::endl;
	
	//system("pause");

    std::cout<<"------特化3"<<std::endl;
    const int len3 = 3;
	Vector<len3,int> u1;
	int aaa[len3] = { 1,2,3};
	Vector<len3,int> u2(aaa);
	Vector<3, int> u3 = { 1,2,4};
	Vector<len3, int> u4(u3);
	const Vector<len3, int> u5(u4);
	std::cout << "------const test-----------" << std::endl;
	for (int i = 0; i < len3; i++)
	{
		std::cout << u5[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "----load and save-----------" << std::endl;
	u3.load(aaa);
	std::cout << u3.xy()<<";"<<u3.xyz1()<<std::endl;
	std::cout << u3.xyz()<<"=?";
	for (int i = 0; i < len3; i++)
	{
		std::cout << u3[i] << " ";
	}

	std::cout << std::endl;
	u4.save(aaa);
	std::cout << u4.r <<","<< u4.g <<","<<u4.b<<"=?";
	for (int i = 0; i < len3; i++)
	{
		std::cout << aaa[i] << " ";
	}
	std::cout << std::endl;

    std::cout<<"------特化4"<<std::endl;
    const int len4 = 4;
	Vector<len4,int> uu1;
	int aaaa[len4] = { 1,2,4,8};
	Vector<len4,int> uu2(aaaa);
	Vector<4, int> uu3 = { 1,2,4,9};
	Vector<len4, int> uu4(uu3);
	const Vector<len4, int> uu5(uu4);
	std::cout << "------const test-----------" << std::endl;
	for (int i = 0; i < len4; i++)
	{
		std::cout << uu5[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "----load and save-----------" << std::endl;
	uu3.load(aaaa);
	std::cout << uu3.xy()<<";"<<uu3.xyz()<<std::endl;
	std::cout << uu3.xyzw()<<"=?";
	for (int i = 0; i < len4; i++)
	{
		std::cout << uu3[i] << " ";
	}

	std::cout << std::endl;
	uu4.save(aaaa);
	std::cout << uu4.r <<","<< uu4.g <<","<<uu4.b<<","<<uu4.a<<"=?";
	for (int i = 0; i < len4; i++)
	{
		std::cout << aaaa[i] << " ";
	}
	std::cout << std::endl;

    std::cout<<"------向量计算--------"<<std::endl;
    v3=v1+v2;
	std::cout<<v3<<std::endl;
	vv3=vv2-vv1;
	std::cout<<vv3<<std::endl;
	std::cout<<"0,1??"<<(v3==(v1-v2))<<","<<(vv3==(vv2+vv1))<<std::endl;
	return 0;
}
