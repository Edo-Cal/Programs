#include <iostream>
using namespace std;

int main(){
	
	int chars[256];
	for(int i=0;i<256;i++){
		chars[i]=0;
	}
	
	string nstr;
	cout << "Insert a string: ";
	getline(cin, nstr);
	unsigned char str[nstr.length()];
	
	for(int i=0;i<nstr.length();i++){
		str[i]=nstr[i];
		chars[int(str[i])]++;
	}
	
	for(int i=0;i<256;i++){
		if(chars[i]!=0){
			cout << char(i)<< " : "<< chars[i] << endl;
		}
	}
	
	return 0;
}
