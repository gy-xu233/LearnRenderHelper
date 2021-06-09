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
	system("pause");
	return 0;
}
