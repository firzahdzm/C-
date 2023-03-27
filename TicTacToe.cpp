#include <iostream>
#include <stdlib.h>
using namespace std;
 
char petak[3][3] = {
	{178, 178, 178},
	{178, 178, 178},
	{178, 178, 178} 
};
	
int NewPetak(){
	system("CLS");
	cout << "Round Baru \n" << endl;
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			petak[i][j]=178;
			cout << petak[i][j] << " ";
		}
	cout <<"\n"<<endl;
	}
}
int main (){
	bool gameselesai = false;
	bool seri = false;
	char rematch;
	int input;
	char player = '1';
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			cout << petak[i][j]<<" ";
		}
		cout <<"\n"<<endl;
	}
	while(gameselesai==false){
		cout << "Player " << player << " Bergerak ke : ";
		cin >> input;
		system("CLS");
		if(input>=1 and input<=9){
			if(input<=3){
				if(petak[0][input-1]!='X' and petak[0][input-1]!='O'){
					if(player=='1'){
						petak[0][input-1] = 'X';
						player = '2';
					}
					else{
						petak[0][input-1] = 'O';
						player = '1';
					}
				}
				else{
					cout << "[!] Petak tersebut sudah terisi!"<<endl<<"Ulangi gerakan.."<<endl;
				}
			}
			else if(input<=6){
				if(petak[1][input-3-1]!='X' and petak[1][input-3-1]!='X'){
					if(player=='1'){
						petak[0][input-1] = 'X';
						player = '2';
					}
					else{
						petak[0][input-1] = 'O';
						player = '1';
					}
				}
				else{
					cout << "[!] Petak tersebut sudah terisi!"<<endl<<"Ulangi gerakan.."<<endl;
				}
			}
			else if(input<=9){
			    if(petak[2][input-6-1]!='X' and petak[2][input-6-1]!='O'){
					if(player=='1'){
						petak[0][input-1] = 'X';
						player = '2';
					}
					else{
						petak[0][input-1] = 'O';
						player = '1';
					}
				}	
			} else{
					cout << "[!] Petak tersebut sudah terisi!"<<endl<<"Ulangi gerakan.."<<endl;
				}
		}
		else{
			cout << "Masukkan kolom 1-9 saja!"<<endl<<"Ulangi gerakan"<<endl;
		}
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				cout << petak[i][j]<<" ";
			}
			cout <<"\n"<<endl;
		}
		cout<<endl;
		
		if (petak[0][0]==178 or 
			petak[0][1]==178 or 
			petak[0][2]==178 or 
			petak[1][0]==178 or 
			petak[1][1]==178 or 
			petak[1][2]==178 or 
			petak[2][0]==178 or 
			petak[2][1]==178 or 
			petak[2][2]==178){
			gameselesai=false;
		}
		else if(
			(petak[0][0]== 'X' and petak[0][1]=='X' and petak[0][2]=='X') or 
			(petak[1][0]=='X' and petak[1][1]=='X' and petak[1][2]=='X') or 
			(petak[2][0]=='X' and petak[2][1]=='X' and petak[2][2]=='X') or
			(petak[0][0]== 'X' and petak[1][0]=='X' and petak[2][0]=='X') or 
			(petak[0][1]=='X' and petak[1][1]=='X' and petak[2][1]=='X') or 
			(petak[0][2]=='X' and petak[1][2]=='X' and petak[2][2]=='X') or
			(petak[0][0]== 'X' and petak[1][1]=='X' and petak[2][2]=='X') or 
			(petak[0][2]=='X' and petak[1][1]=='X' and petak[2][0]=='X')){
			gameselesai = true;
			seri=false;
			player='1';
		} 
		else if (
			(petak[0][0]== 'O' and petak[0][1]=='O' and petak[0][2]=='O') or 
			(petak[1][0]=='O' and petak[1][1]=='O' and petak[1][2]=='O') or 
			(petak[2][0]=='O' and petak[2][1]=='O' and petak[2][2]=='O') or
			(petak[0][0]== 'O' and petak[1][0]=='O' and petak[2][0]=='O') or 
			(petak[0][1]=='O' and petak[1][1]=='O' and petak[2][1]=='O') or 
			(petak[0][2]=='O' and petak[1][2]=='O' and petak[2][2]=='O') or
			(petak[0][0]== 'O' and petak[1][1]=='O' and petak[2][2]=='O') or 
			(petak[0][2]=='O' and petak[1][1]=='O' and petak[2][0]=='O')){
			gameselesai = true;
			seri=false;
			player='2';
		} else if(
			(petak[0][0]=='O' or petak[0][0]=='X') and
			(petak[0][1]=='O' or petak[0][1]=='X') and
			(petak[0][2]=='O' or petak[0][2]=='X') and
			(petak[1][0]=='O' or petak[1][0]=='X') and
			(petak[1][1]=='O' or petak[1][1]=='X') and
			(petak[1][2]=='O' or petak[1][2]=='X') and
			(petak[2][0]=='O' or petak[2][0]=='X') and
			(petak[2][1]=='O' or petak[2][1]=='X') and
			(petak[2][2]=='O' or petak[2][2]=='X')){
			gameselesai=true;
			seri=true;
		}
		if(gameselesai==true){
			if(seri==true){
				cout << "Game selesai dengan hasil seri"<<endl;
			} else{
				cout << "Player " << player << " menang"<<endl;
			}
			
			cout << "\nRematch?(y/n) = "; cin >> rematch;
			switch(rematch){
				case 'y' : gameselesai=false;seri=false; break;
				case 'n' : gameselesai=true; seri=true; break;
				default : cout << "Pilihan salah! Restart Game...";
			}
			if (gameselesai==false){
				NewPetak();
			}
		}
		
			
	}
	
	
}

