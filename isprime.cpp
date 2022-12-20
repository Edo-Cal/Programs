//this function takes in an int and returns 1 if it's prime and 2 if it's not, if the number is equal to 0 it returns 0.
int isprime(int num){
	
	int x=0;
	
	if (num == 0) {
		return 0; //zero
	}
	else {
		for (int i=2; i < num; i++){
			if (num % i == 0){
				x++;
			}
		}
	}
	
	
	if (x >= 1){
		return 2; //not prime
	}
	else
		return 1; //prime
}
