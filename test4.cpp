#include <iostream>
#include <sstream>
#include <vector>
#include <memory>

template <typename T>
T function(int prvi, double drugo){
	T varijabla = prvi * drugo;
	return varijabla;
}
class bok{
	protected:
		int hehe;
		std::string bokac;
	public:
		bok(int hehe, std::string bokac) : hehe(hehe), bokac(bokac) {}
		
		virtual std::string toString(){
			std::stringstream mystring;
			mystring << "hehe: " << hehe << " bokac: " << bokac << std::endl;
			std::string ss = mystring.str();
			return ss;
		}
		
};

class aut{
	protected:
		int broj;
		std::string ime;
		bok* b;
	public:
		aut(int broj, std::string ime, bok* b) : broj(broj), ime(ime), b(b) {} 
		std::string toString(){
			std::stringstream mystring;
			mystring << "ID: " << broj << " aut: " << ime << b->toString() << std::endl;
			std::string ss = mystring.str();
			return ss;
		}
};
//agregacija
template <typename T>
class garaz{
	protected:
		std::string imegaraz;
		std::vector<T> puni;
		//std::vector<aut*> puni;
	public:
		garaz(std::string imegaraz) : imegaraz(imegaraz) {}
		void addaut(T aut){
			puni.push_back(aut);
		}
		void print(){
			for(unsigned int i = 0; i < puni.size(); i++){
				std::cout << puni[i]->toString();
			}
		}

};
template <typename T>
class garazpointerless{
	protected:
		std::string imegaraz;
		//std::vector<T> 
		std::vector<T> puni;
	public:
		garazpointerless(std::string imegaraz) : imegaraz(imegaraz) {}
		void addaut(T aut){
			puni.push_back(aut);
		}
		void print(){
			for(unsigned int i = 0; i < puni.size(); i++){
				std::cout << puni[i].toString();
			}
		}

};

template <typename T>
class garazSHAREDjebomaterpointer{
	protected:
		std::string imegaraz;
		//std::vector<T> 
		std::vector<T> puni;
	public:
		garazSHAREDjebomaterpointer(std::string imegaraz) : imegaraz(imegaraz) {}
		void addaut(T aut){
			puni.push_back(aut);
		}
		void print(){
			for(unsigned int i = 0; i < puni.size(); i++){
				std::cout << puni[i]->toString();
			}
		}

};

int main(){
	int kurac = 15;
	double wtf = 234.234234;

	std::cout << function<int>(kurac, wtf);
	//zapravo trebam za tamplate uvijek stavit kaj hocu za output dobit 
	//jer drugacije kurac jebote neznam kaj odabrat i guess
	bok *newbok = new bok(34, "bokac");
	aut jedan(1, "kar", newbok);
	aut *peder = new aut(2, "evogabravo", newbok);
	garaz<aut*> *kurac2 = new garaz<aut*>("jebote prekrasne kurcine");
	std::cout << jedan.toString();
//	kurac2->addaut(jedan);
	kurac2->addaut(peder);
	kurac2->print();
	//bok test
	std::cout << newbok->toString();
	garazpointerless<aut> blabla("ime");
	blabla.addaut(jedan);
	blabla.print();
	std::cout << "SHATED POINTEOINRIOERE ---------------------" << std::endl;
	std::shared_ptr<aut> tester(new aut(123, "shared", newbok));
	garazSHAREDjebomaterpointer<std::shared_ptr<aut> > garaaa("shared");
	garaaa.addaut(tester);
	tester->toString();
	garaaa.print();
	return 0;
	
}
