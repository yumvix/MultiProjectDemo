#include <iostream>
#include <memory>

using namespace std;

class A
{
public:
	A() {};
	~A()
	{
		cout << "~A" << endl;
	}
};

class B : public A
{
public:
	B() {};
	~B()
	{
		cout << "~B" << endl;
	}
};

int main() {
	{
		//std::unique_ptr<A> a = std::make_unique<B>();
		std::shared_ptr<A> a = std::shared_ptr<B>();

	}


	return 0;
}
