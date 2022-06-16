#include <iostream>
#include <string>
#include <sstream>

class A{
	protected:
		int a;
		std::string name;
	public:
		A(std::string name, int a) : name(name), a(a) {}
		virtual std::string toString(){
			std::stringstream mystream;
			mystream << "ime: " << name << std::endl;
			std::string ss = mystream.str();
			return ss;
		}		
};

class B : public A{
	protected:
		std::string dodatno;
	public:
		B(std::string dodatno, std::string name) : dodatno(dodatno), A(name, a) {}
		std::string toString() {
			std::stringstream mystream;
			mystream << "dodatno: " << dodatno << " ime: " << A::name << std::endl;
			std::string ss = mystream.str();
			return ss;
		}
};
class C : public A{
	protected:
		std::string dodatno2;
	public:
		C(std::string dodatno2, std::string name, int a) : dodatno2(dodatno2), A(name, a) {}
		std::string toString() {
			std::stringstream mystream;
			mystream << "dodatno2: " << dodatno2 << " ime: " << A::name << A::a << std::endl;
			std::string ss = mystream.str();
			return ss;
		}
};

void func(A test){
	std::cout << test.toString();
}


int main(){
	A t1("bok", 2);
	B t2("nesto", "bokac");
	C t3("nesto3", "jao", 6);
	std::cout << t1.toString();
	std::cout << t2.toString();

	std::cout << t3.toString();
 	func(t1);
	func(t2);
	A *kurac[3];
	kurac[0] = new A("hi", 3);
	kurac[1] = new B("jao", "tebi");
	kurac[2] = new C("nesto", "trece", 6);
	for(int i = 0; i < 3; i++)	{
		std::cout << kurac[i]->toString();
	}


	return 0;
}
