#include <iostream>

template <typename T>
class Stepper{
	private:
		T step, value;
	public:
		Stepper(int s) : step(s), value(0){}
		T getValStep(){
			return this->value;
		}
		Stepper operator+(Stepper &other){
			this->value = this->value + other.step;
			return *this;
		}
		/*Stepper &operator++(){
			this->value = this->value + step;
			return *this;
		}*/
		Stepper &operator++(){
			this->value += 10;
			return *this;
		}

};
int main(){
	Stepper<int> s(2);
	Stepper<int> s2(4);
	Stepper<int> sU(3);
	sU = s + s2;
	++sU;
	std::cout << sU.getValStep();
	
}
