#include <iostream>
#include <vector>
class A {
public:
	virtual ~A(){}
	virtual void foo(std::vector<int>& vec) = 0;//необходимо убрать амперсант, произойдет копирование вектора а исходный вектор останется не изменным
};
class B : public A {
public:
	void foo(std::vector<int>& vec) override {//необходимо убрать амперсант, произойдет копирование вектора а исходный вектор останется не изменным
		std::cout << "foo function" << std::endl;
		vec.erase(vec.begin());//delete fist element vector v
	}
};
int main() {
	setlocale(LC_ALL, "Russian");
	A* b = new B();
	std::vector<int> v = { 1,2,3 };
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << std::endl;
	}
	b->foo(v);//содержит в себе лементы 2,3
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << std::endl;
	}
	delete b;
}