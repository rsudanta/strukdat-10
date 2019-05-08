/*
*Author:M Risqullah Sudanta G
*NPM: 140810180066
*Deskripsi: case 1
*Tahun: 2019
*/

#include <iostream>
using namespace std;

const int maxElement=5; 

struct Queue{
    char info[maxElement];
    int head;
    int tail;
};

void createQueue(Queue &Q);
void push(Queue &Q);
void pop(Queue &Q);
void print(Queue Q);

int main(){
    Queue Q;
	int pil,n;
	char loop;
	createQueue(Q);
	do{
		cout<<"Banyak Data (MAX "<<maxElement<<"): ";
		cin>>n;
	}while(n>maxElement);
	cout<<"Masukkan Data : "<<endl;
	for(int i=0; i<n; i++){
		push(Q);
	}
	do{
		system("CLS");
		cout<<"1. Tambahkan Antrian \n2. Kurangi Antrian \n3. Print Antrian"<<endl;
		do{
			cin>>pil;
		}while(pil>3 || pil<1);
		switch(pil){
			case 1:
				if(Q.head!=0){
					cout<<"Masukkan Data : "<<endl;
				}
				push(Q);
				break;
			case 2:
				pop(Q);
				break;
			case 3:
				print(Q);
				break;
		}
		cout<<endl<<"Kembali ke menu? (Y/N) ";
		do{
			cin>>loop;
		}while(loop!='Y' && loop!='y' && loop!='N' && loop!='n');
	}while(loop=='Y' || loop=='y');
}

void createQueue(Queue &Q){
    Q.head=-1;
    Q.tail=-1;
}

void push(Queue &Q){
    if(Q.head==-1){
		Q.head++;
		Q.tail++;
		cin>>Q.info[Q.head];
	}else{
		if(Q.tail<maxElement-1){
			Q.tail++;
			cin>>Q.info[Q.tail];
		}else{
			if(Q.head==0){
				cout<<"Antrian penuh!"<<endl;
			}else{
				Q.tail=0;
				cin>>Q.info[Q.tail];
			}
		}
	}
}

void pop(Queue &Q){
	if(Q.tail==-1){
		cout<<"Antrian kosong, tidak ada yang didelete."<<endl;
	}else if(Q.head==Q.tail){
		Q.head=-1;
		Q.tail=-1;
	}else{
		if(Q.head<maxElement-1){
			Q.head++;
		}else{
			Q.head=0;
		}
	}
}

void print(Queue Q){
	if(Q.head==-1){
		cout<<"Antrian Kosong."<<endl;
	}else{
		int i=Q.head;
		cout<<endl<<"Antrian = [";
		if(Q.head>Q.tail){
			while(i<maxElement){
				cout<<Q.info[i];
				if(i!=Q.tail){
					cout<<", ";
				}
				i++;
			}
			i=0;
			while(i<=Q.tail){
				cout<<Q.info[i];
				if(i!=Q.tail){
					cout<<", ";
				}
				i++;
			}
		}
		else{
			while(i<=Q.tail){
				cout<<Q.info[i];
				if(i!=Q.tail){
					cout<<", ";
				}
				i++;
			}
		}
		cout<<"]"<<endl;
	}
}
