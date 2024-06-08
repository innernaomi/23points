#include <bits/stdc++.h>
#include "unit.h"
const int mmm=114;
int n_get();
int get();
int main(){
	using std::cout;
	using std::cin;
	using std::endl;
	system("cls");
	cout<<"Start!"<<endl;
	units m;
	m.first_all();
	int n=-13;
	while(n!=mmm)
	{
		m.out_ss_add();
		n=n_get();
		if(n==mmm) break;
		m<<n;
		if(!m.check_all()) break;
	}
	m.result();
	m.f_true();
	cout<<"End!"<<endl;
}
int n_get()
{
	using namespace std;
	int n;
	cout<<"    if it can be chosen (put "
		<<mmm<<" to stop):"<<endl;
	cin>>n;
	if(n==mmm) return n;
	if(!(1<=n && n<=23))
	{
		cout<<"    it is not a choise"<<endl;
		n=n_get();
	}
	return n;
}