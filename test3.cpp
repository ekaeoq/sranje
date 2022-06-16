#include <iostream>
#include <exception>
#include <vector>

/*class Exc : public std::exception{
	private:
		std::string message;
	public:
		explicit Exc(std::string &name) : message("Ne valja: \"" + name + "\n") {}
		const char * what() const noexcept override{
			return message.c_str();
		}
};*/

class Exception : public std::exception {
private:
    std::string message;
public:
    //explicit Exception(int &name) : message("Uparsable name: \"" + name + "\"") {}
    explicit Exception(int &name) : message("Ma sta ce nama broj") {}
    const char * what() const noexcept override{
		return message.c_str();
	}
};

int tester(int broj){
	if(broj < 20){
		throw Exception(broj);
	}else{
		return broj;
	}
}

bool kurcina(int x){
	if(x == 5){
		return true;
	}else{
		return false;
	}
}

int find(int array[], bool(*c)(int)){
	for(int i = 0; i < 5; i++){
		if(c(array[i])){
			std::cout << "NASLO SE NEKI KURAC";
		}
	}
}

class kurac{
	private:
		std::string ime;
		std::vector<int> ha;
	public:
		kurac(std::string ime) : ime(ime){}
		void add(int array[]){
			for(int i = 0; i < 5; i++){
				ha.push_back(array[i]);
			}
		}
		void find(bool(*c)(int)){
			int ok = ha.size();
			for(int i = 0; i < ok; i++){
				if(c(ha[i])){
				std::cout << "jebote nasli i u klasi" << std::endl << ha[i] << std::endl;
				}
			}
		}

};

int main(){
	int test = 40;
	try{
		//tester(test);
		if(test > 10){
			throw Exception(test);
		}else{
		std::cout << test;
		}
	}catch(Exception ehbrate){
		std::cout << ehbrate.what();
	}
	int array[] = {1,2,5,4,5,67};
	for(int i = 0; i < 5; i++){
		std::cout << array[i];
	}
	std::cout << std::endl;
	find(array, kurcina);
	kurac a("hiiii");
	a.add(array);
	a.find(kurcina);
}

