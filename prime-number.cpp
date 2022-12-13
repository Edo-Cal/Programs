#include <iostream>
using namespace std;
int main () {
	
	int num, x = 0, y = 0;
	cout << "Insert a number to verify if it's prime: ";
	cin >> num;
	
	if (num == 0) {
		cout << "\n" << num << " is not a prime number.";
		return 0;
	}
	else {
		for (int i=2; i < num; i++){
			if (num % i == 0){
				x++;
			}
		}
	}
	
	int div[x];
	for (int i=1; i <= num; i++){
			if ( num % i == 0){
				div[y]=i;
				y++;
			}
	}
	
	if (x > 1){
		cout << "\n" << num << " is not a prime number." << "\n\nthe dividers of " << num << " are: \n";
	
		for (int i=0;i<=x+1;i++){
			cout << div[i] << endl;
		}
	}
	else
		cout << "\n" << num << " is a prime number.";
	
	return 0;
}
