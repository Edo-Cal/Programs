#include <iostream>
#include <fstream>
using namespace std;

int main(){
	
	ofstream fout;
	fout.open("output.txt");
	
	//declaring character constants (character's unicode value)
	const int b=183; //white
	const int n=42; //black
	const int f=164; //ant
	
	//read grid dimensions
	int mx, my;
	cout << "Insert grid's max width and lenght: ";
	cin >> mx >> my;
	
	//verify grid dimensions values
	if(mx<0 || my<0){
		cerr << "Error->grid's dimensions need to be greater than 0.";
		return 1;
	}
	
	//initialize grid
	unsigned char grid[mx][my];
	for(int y=0;y<my;y++){
		for(int x=0; x<mx;x++){
			grid[x][y]=b;
 		}
	}
	
	//read ant's coordinates and direction
	int fx,fy,dir;
	cout << "Ant coordinates(x,y): ";
	cin >> fx >> fy;
	cout << "What direction is the ant facing?:\nNorth[0]\nWest[1]\nSouth[2]\nEast[3]\n";
	cin >> dir;
	
	//Verify ant's coordinates and direction values
	if(fx<0 || fy<0 || fx>mx || fy>my){
		cerr << "Error->Ant's coordinates need to be included in the grid's dimensions.";
		return 1;
	}
	if(dir<0 || dir >3){
		cerr << "Error->the value inserted for the ant's direction is not valid, the value needs to be included between -1 and 4.";
		return 1;
	}
	
	//initialize ant
	int current=grid[fx][fy];
	grid[fx][fy]=f;
	
	//read number of steps to execute
	int step;
	cout << "How many steps to do before stopping?: ";
	cin >> step;
	
	//verify value of number of steps
	if(step<=0){
		cerr << "Error->the numbers of steps must be greater than 0.";
		return 1;
	}
	cout << "\nloading...\n";

	//start of algorithm for langton's ant
	while(step>0){
		
		//establish direction and change cell colour
		if(current == b){
			if(dir<3)
				dir++;
			else
				dir=0;
			grid[fx][fy]=n;
		}
		else if(current == n){
			if (dir>0)
				dir--;
			else
				dir=3;
			grid[fx][fy]=b;
		}
		
		//move the ant based on the direction
		if(dir==0){
			fy--;
		}
		else if(dir==1){
			fx--;
		}
		else if(dir==2){
			fy++;
		}
		else if(dir==3){
			fx++;
		}
		
		if(fx==mx){
			fx=0;
		}
		if(fx<0){
			fx=mx-1;
		}
		if(fy==my){
			fy=0;
		}
		if(fy<0){
			fy=my-1;
		}
		
		current=grid[fx][fy];
		grid[fx][fy]=f;
		
		//visualize current grid status
		for(int y=0;y<my;y++){
			for(int x=0; x<mx;x++){
				fout << grid[x][y];
 			}
 			fout << endl;
		}
		fout << "\n\n\n";
		step--;
	}
	
	cout << "\n\n|END|\n";
	fout << "\n\n|END|";
	fout.close();
	system("PAUSE");
	
	return 0;
}
