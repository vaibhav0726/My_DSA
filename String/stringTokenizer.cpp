#include<bits/stdc++.h>
#include<cstring>
using namespace std;

int main(){
	char s[100]="today is a rainy day";
	// char *ptr=strtok(s," ");
	// cout<<ptr<<endl;

	// // also we can do this
	// ptr=strtok(s," ");
	// cout<<ptr<<endl;

	// // it maintains the static location of next variable if NULL is passed to the token
	// ptr=strtok(NULL," ");

	// to get all tokens at the same time we use loop as follows
	// first print the first token then the apply loop
	char *ptr=strtok(s," ");
	cout<<ptr<<endl;
	while(ptr!=NULL){
		ptr=strtok(NULL," ");
		cout<<ptr<<endl;
	}


	return 0;
}