#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;

int ind = 0;

int present(int num[], int len, int i, int n){
    
    for(int j=0; j<i; j++){
        
        if(num[j]==n){
            
            ind = j;
            return 1;
            
        }
        
    }
    return 0;
}

int main(){
    
    srand (time(NULL));
    
    int len;
    cout << "Difficulty: ";
    cin >> len;
    
    int num[len];
    
    for(int i=0; i<len;){
        
        int n=rand() % 10;
        if(present(num, len, i, n) == 0){
            
            num[i]=n;
            //cout << num[i] << "|";
            i++;
            
        }
        
        
    }
    
    bool correct = false;
    int guess[len];
    int right = 0;
    int right_pos = 0;
    int guesses = 0;
    while(!correct){
        
        cout << ":";
        for(int i=0; i<len; i++){
            
            cin >> guess[i];
            if(present(num, len, len, guess[i]) == 1 && ind==i){
                
                right_pos++;
                right++;
                
            }
            else if(present(num, len, len, guess[i]) == 1){
                
                right++;
                
            }
        }
        
        if(right_pos == len){
            
            correct = true;
            
        }
        cout << "right: " << right;
        cout << "\nright position: " << right_pos << "\n";
        right_pos = 0;
        right = 0;
        guesses++;
        
    }
    cout << "\nCORRECT!\nGuesses: " << guesses << endl;
    system("PAUSE");
    return 0;
}
