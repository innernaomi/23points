#include <bits/stdc++.h>
#include "unit.h"
int n_get();
int get();
int main(){
	using std::cout;
	using std::cin;
	using std::endl;
	units m;
	m.first_all();
	int n=-13;
	while(n!=42)
	{
		m.out_ss_add();
		n=n_get();
		if(n==114)
			break;
		m.choose(n);
		m.del(1);
		if(!m.check_all())
			break;
	}
	m.result();
}
int n_get()
{
	using namespace std;
	int n;
	cout<<"please put a num between 1 and 23"<<endl;
	cout<<"if it can be chosen (put 42 to stop):"<<endl;
	cin>>n;
	if(n==42)
		return n;
	if(!(1<=n && n<=23))
	{
		cout<<"it is not a choise"<<endl;
		n=n_get();
	}
	return n;
}