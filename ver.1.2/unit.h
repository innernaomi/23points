//ver.1.2
//20240604
#ifndef UHIT_H_
#define UNIT_H_
#include <iostream>
class unit {
	public:
		int add,	
			s,		
			ss[5];	
		//dangerous but protected
		void first(int n);
		void check_unit();
};
class units {
	private:
		unit set[24];	
		bool ERROR;		
		bool TEST;
		//dangerous
		int get_ss_add(int n,int i);
		void sign(int n,int j);
		void srch_sg(int n,int j);
	public:
		int set_add[24];
		//only for test
		int get_ss_add(int n,int i,char ch);
		void error(bool n);
		void test(bool n);
		void sign(int n,int j,char ch);
		void srch_sg(int n,int j,char ch);
		void check_units(int n);
		void del_all();
		//normal
		int result();
		bool find(int n);
		bool check_all();
		bool check_one(int n);
		void first_all();
		void del(int n);
		void choose(int n);
		void out_ss_add();
		bool check_result();
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
void units::test(bool n)
{
	TEST=n;
}
void units::first_all()
{			
	ERROR=0;
	TEST=0;
	for(int i=1;i<24;i++)
	{
		set[i].first(i);
		set_add[i]=0;
	}
}
void units::check_units(int n)	
{
	using namespace std;
	if(TEST!=1)
		return;
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
		set[n].add=j;
		set_add[n]=j;
} 
void units::srch_sg(int n,int j)
{	
	using std::cout;
	using std::endl;
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
	using std::cout;
	using std::endl;
	if(n==1)
		return;
	if(set[n].add!=0)
		return;
	if(check_one(n))
	{
		sign(n,1);
		srch_sg(n,2);
	}
	else if(ERROR)
	{
		cout<<"====choose-error===="
			<<endl;
	}
} 
void units::del_all()	
{				
	if(TEST!=1)
		return;
	for(int i=1;i<24;i++)
		del(i);
} 
bool units::check_all() 
{			
	for(int i=2;i<24;i++)
	{
		if(set_add[i]==0 && check_one(i))
			return 1; 
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
	using std::cout;
	using std::endl;
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
	using std::endl;
	cout<<"the num you can choose:"
		<<endl;
    for(int i=1;i<24;i++)
    {
        if(set_add[i]==0 && find(i))
            cout<<i<<' ';
    }
    cout<<endl;
}
int units::get_ss_add(int n,int i,char ch)
{
	using std::cout;
	using std::endl;
	if(ch!='t' || TEST!=1)
	{
		cout<<"not in test"
			<<endl;
		return -13; 
	}
	return get_ss_add(n,i);
}
void units::sign(int n,int j,char ch)
{
	using std::cout;
	using std::endl;
	if(ch!='t' || TEST!=1)
	{
		cout<<"not in test"
			<<endl;
		return; 
	}
	sign(n,j);
}
void units::srch_sg(int n,int j,char ch)
{
	using std::cout;
	using std::endl;
	if(ch!='t' || TEST!=1)
	{
		cout<<"not in test"
			<<endl;
		return; 
	}
	srch_sg(n,j);
}
#endif