#include <iostream>
#include <vector>
#include <functional>


class myfun
{
public:

	int a = 10;

	void msg() {
		std::cout << "msg" << std::endl;
	}

	void lambda()
	{
		auto f = [this]() {
			msg();
			a = 99;
			std::cout << a << std::endl;
		};

		f();
	}
};

void doWork(const std::vector<int>& vec, std::function<void(int)> func)
{
	for (auto el : vec)
	{
		func(el);
	}
}

class evenfunctor
{
	size_t evensum = 0;
	size_t evencounter = 0;
public:
	size_t operator()(std::vector<int>* myvector)
	{
		size_t counter = 0;
		for (auto var : *myvector)
		{
			if (var % 3 == 0)
			{
				++evencounter;
			}
			evensum += var;
		}
	}
};


int main()
{
	setlocale(LC_ALL, "Rus");

	std::vector<int> vInt = { 1, 2, 3, 23, 5432, 12, 23,  4324,  2344,  91 };

	/*std::function<void(int)> f; это посредник

	f = [](int a)
	{
		if (a % 2 == 0)
		{
			std::cout << a << " ";
		}
	};*/

	//doWork(vInt, [](int a)  //тернарный оператор применить не удалось
	//{
	//	if (a % 2 == 0)
	//	{
	//		std::cout << a << " ";
	//	}
	//});

	/*auto f = [&vInt](double a) 
	{
		for (auto val : vInt)
		{
			if (val % 2 == 0)
			{
				std::cout << val * a << " ";
			}
		}
	};

	f(0.01);*/

	/*int a = 55;

	auto f = [&]()
	{
		std::cout << a << std::endl;
		
		for (auto var : vInt)
		{
			std::cout << var << std::endl;
		}

	};

	f();*/

	/*myfun m;

	m.lambda();*/

	size_t result = evenfunctor(&vInt);


	std::cout << std::endl;

	system("pause");

}