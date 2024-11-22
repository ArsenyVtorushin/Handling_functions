#include <iostream>
#include <cmath>

#include <thread> 
// ����� windows.h
// �� ������� posx

#include <functional> // ������� ������� ��� �������



// �������� ������� � ������ �������
//  ��������� �� �������
//  ��������� ������� 
//  �������� - ������ ������ ������� ����� ���� ��� ������
//  ��������� - ���������� ��� ���� 
//


typedef int (*Curwy)(int, int);

using Curly = int (*)(int, int);


int Sum(int a, int b) { return a + b; }
int Subtract(int a, int b) { return a - b; }
int Multiply(int a, int b) { return a * b; }

int DoAction1(int a, int b, int(*func)(int, int));

int DoAction2(int a, int b, Curwy func)
{
	return func(a, b);
}

int DoAction3(int a, int b, Curly);
int DoAction4(int a, int b, std::function<int(int, int)> func);


int main()
{

	// 3 ���� ����. ����������:
	//  int �(4);
	//  int a = 4; ����� ��������� ���� float
	//  int a{ 4 }; �� �������� float
	//

	std::cout << "Enter first number: ";
	int first{};
	std::cin >> first;
	std::cout << "Enter second number: ";
	int second{};
	std::cin >> second;

	//std::cout << Sum << ' ' << Subtract << ' ' << Multiply << '\n';
	//
	//std::function<int(int, int)> var1 = Sum;
	////����� ���: int (*var1)(int, int)
	//auto var2 = Multiply;
	//Curwy var3 = Subtract;

	//Curly arrFunc[]{ Sum, Subtract, Multiply };
	// // ����� ���: int (*arrFunc[])(int, int) ������ Curly


	//for (auto i : arrFunc)
	//{
	//	std::cout << first << " and " << second << " = " << i(first, second);
	//	std::cout << '\n';
	//}
	
	std::cout << "Enter typr of action: \n 1 - summ, \n 2 - subtract, \n 3 - multiply\n";
	int key{};
	std::cin >> key;
	int answer{};

	switch (key)
	{
	case 1:
		answer = DoAction2(first, second, Sum);
		break;
	case 2:
		answer = DoAction2(first, second, Subtract);
		break;
	case 3:
		answer = DoAction2(first, second, Multiply);
	}

	std::cout << "Your result: " << answer << '\n';



	std::thread tr(Sum, 3, first);



	tr.join();
	
	// tr.detach(); // ��������� ����� (������ ������ � join � ����� ��������)

	return 0;
}