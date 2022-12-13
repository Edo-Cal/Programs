#include <iostream>
using namespace std;

int main(){
	
	//initialize and read a string
	string txt;
	cout << "Insert a string: ";
	getline(cin, txt);
	unsigned char str[txt.length()];
	
	//convert each character to it's unicode value
	for(int i=0;i<txt.length();i++){
		
		str[i]=txt[i];
		cout << int(str[i])<< " ";
		
	}
	
	return 0;
}
