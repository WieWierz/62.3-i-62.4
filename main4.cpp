#include <iostream>
#include <fstream>

using namespace std;

int countOf6(int number)
{
int count6=0;
 while (number > 0)
  {
       if (number %10 == 6) 
              count6++;
       number/=10;
 }
return count6;
}

class licz{
	
	public:
	void trzy();
	void cztery();
};

void licz::trzy(){
	
	ifstream plik1;
	ifstream plik2;
	
	int liczba1, liczba2;
	int rowne=0;
	int wieksze=0;
	
	plik1.open("liczby1.txt");
	plik2.open("liczby2.txt");
	
	while(!plik1.eof() && !plik2.eof()){
		plik1 >> oct >> liczba1;
		plik2 >> dec >> liczba2;
		if(liczba1==liczba2){
			rowne++;
		}else if(liczba1>liczba2){
			wieksze++;
		}
	}
	cout<<"Liczby maja w obu plikach taka sama wartosc w "<<rowne<<" wierszach"<<endl;
	cout<<"Wartosc liczby z pliku liczby1.txt jest wieksza od wartosci liczby z pliku liczby2.txt w "<<
			wieksze<<" wierszach"<<endl;
			
	plik1.close();
	plik2.close();
}

void licz::cztery(){

	ifstream plik2;
	
	int liczba, liczba2;
	int suma = 0;
	int suma2 = 0;
	plik2.open("liczby2.txt");
	
	while(!plik2.eof()){
		plik2 >> dec >> liczba;
		suma = suma + countOf6(liczba);
	}
	cout<<"W zapisie dziesietnym 6 wystepuje: "<< suma<<" razy"<<endl;

	while(!plik2.eof()){
		plik2 >> oct >> liczba2;
		suma2 = suma2 + countOf6(liczba2);
	}
	cout<<"W zapisie osemkowym 6 wystepuje: "<< suma2<<" razy"<<endl;
	
	plik2.close();
}

int main(int argc, char** argv) {
	
	licz l;
	l.trzy();
	l.cztery();
	return 0;
}
