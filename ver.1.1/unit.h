//ver.1.1
//20240603
#ifndef UHIT_H_
#define UNIT_H_
#include <iostream>
class unit {
	public:
		int add,	
			s,		
			ss[5];	
		void first(int n);
		void check_unit();
};
class units {
	private:
		unit set[24];	
		bool ERROR;		
		bool TEST;
		int get_ss_add(int n,int i);
		void sign(int n,int j);
		void srch_sg(int n,int j);
	public:
		int set_add[24];
		void error(bool n);
		void first_all();
		void check_units(int n);
		void del(int n);
		void del_all();
		void out_ss_add();
		bool find(int n);
		void choose(int n);
		bool check_all();
		bool check_one(int n);
		bool check_result();
		int result();
};
//for unit
void unit::first(int n) 
{	
	add=0;
	int goal=0;
	for(int i=1;i<n;i++)
	{
		if(n%i==0)
		{			
			ss[goal]=i;
			goal++;
		}
	}
	s=goal;
	for(int i=goal;i<5;i++)
		ss[i]=-13;		
}
void unit::check_unit()	
{
	using namespace std;
	cout<<"====check"<<endl;
	cout<<"=====add="<<add<<endl;
	cout<<"=====s="<<s<<endl;
	cout<<"=====ss=";
	for(int i=0;i<s;i++)
		cout<<ss[i]<<' ';
	cout<<endl;
}

//for units
void units::error(bool n)
{	
	ERROR=n;
}
void units::first_all()
{			
	ERROR=0;
	for(int i=1;i<24;i++)
	{
		set[i].first(i);
		set_add[i]=0;
	}
}
void units::check_units(int n)	
{
	using namespace std;
	set[n].check_unit();
	cout<<"=====set_add="
		<<set_add[n]
		<<endl;
}
int units::get_ss_add(int n,int i)
{	
	using namespace std;
	if(set[n].ss[i]==-13 || i<0 || i>=set[n].s)
	{	
		if(ERROR)	//error
			cout<<"====getadd-error===="
				<<endl;
		return -13;
	}
	return set[set[n].ss[i]].add;
} 
bool units::find(int n)
{			
	if(n==1)
		return 0;
	for(int i=0;i<set[n].s;i++)
	{
		if(get_ss_add(n,i)==0)
			return 1;
	}
	return 0;
}
void units::sign(int n,int j)
{		
	if(set_add[n]==0 && find(n))
	{
		set[n].add=j;
		set_add[n]=j;
	}
} 
void units::srch_sg(int n,int j)
{	
	using namespace std;
	if(find(n)){
		for(int i=0;i<set[n].s;i++)
		{
			if(get_ss_add(n,i)==0)
			{
				sign(set[n].ss[i],j);
			}
		}
	}else{
		if(ERROR)	//error
			cout<<"====srch_sg-error===="
				<<endl;	
	}
}
void units::del(int n)
{			
	set[n].add=-1;
	set[n].s=0;
	for(int i=0;i<5;i++)
		set[n].ss[i]=-13;
} 
void units::choose(int n)
{			
	if(n==1)
		return;
	if(set[n].add!=0)
		return;
	if(set_add[n]==0)
	{
		sign(n,1);
		srch_sg(n,2);
	}
} 
void units::del_all()	
{				
	for(int i=1;i<24;i++)
		del(i);
} 
bool units::check_all() 
{			
	for(int i=2;i<24;i++)
	{
		if(set_add[i]==0 && check_one(i)) return 1; 
	}
	return 0;
}
bool units::check_one(int n) 
{
	if(set[n].add==0 && find(n))
		return 1;
	else return 0;
}
bool units::check_result()	
{
	int ans=0;
	for(int i=1;i<24;i++)
	{
		if(set_add[i]==1)
			ans+=i;
	}
	if(ans>=138)
		return 1;
	else return 0;
}
int units::result(){	
	using namespace std;
	cout<<'-'<<endl;
	cout<<"the integers A got ( no order ):";
	int ans=0;
	for(int i=1;i<24;i++)
	{
		if(set_add[i]==1)
		{
			cout<<i<<' ';
			ans+=i;
		}
	}
	cout<<endl;
	if(ans<0 ||ans>276)
		if(ERROR)	//error
			cout<<"====result-error===="
				<<endl;	
	cout<<"the sum of A:"<<ans<<' ';
	if(ans*2<276)
		cout<<"lost";
	if(ans*2==276)
		cout<<"draw";
	if(ans*2>276)
		cout<<"====win====";
	cout<<endl;
	return ans;
}
void units::out_ss_add()
{
    using std::cout;
	using std::cin;
	using std::endl;
	cout<<"the num you can choose:"<<endl;
    for(int i=1;i<24;i++)
    {
        if(set_add[i]==0 && find(i))
            cout<<i<<' ';
    }
    cout<<endl;
}
#endif