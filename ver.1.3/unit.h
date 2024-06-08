//ver.1.3
//20240605
#ifndef UHIT_H_
#define UNIT_H_
#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
class unit
{
	public:
		int add,				//此牌的占用状态:0-可用; 1-被甲占用; 2-被乙占用; -1-被禁用	
			s,					//因子个数（含1）
			ss[5];				//因子的集合（空位用-13填充）
		//dangerous but be protected in units
		void first(int);		//初始化
		void check_unit();		//输出单元状态
		void operator=(unit);	//重载=，建立副本
};
class units
{
	private:
		unit set[24];	//23张牌
		bool ERROR;		//控制报错
		bool TEST;		//调试模式
		int NUM;		//计数器
		//dangerous but can't be used directly
		int get_ss_add(int n,int i);			//获取某张牌某个因子的状态
		void sign(int n,int j);					//将某张牌的占用更新
		void srch_sg(int n,int j);				//"search_sign"的简写 将某张牌的所有因子更新占用
		void f_out_set_add();					//文件输出set_add的状态
	public:
		int set_add[24];						//记录每张牌的占用情况，作为一个副本，方便查阅
		//only for test
		int get_ss_add(int n,int i,char ch);	//调试专用
		void error(bool);						//报错开关
		void test(bool);						//调试专用
		void sign(int n,int j,char ch);			//调试专用
		void srch_sg(int n,int j,char ch);		//调试专用
		void check_units(int);					//输出某个单元的状态(调试专用)
		void del_all();							//"delete_all"的简写 全局禁用（调试专用）
		//normal
		int result();							//输出结果及输赢
		void f_result();						//文件输出结果及输赢
		bool find(int);							//判断该张牌是否有因子未被占用
		bool check_all();						//判断是否有牌未被占用
		bool check_one(int);					//判断该张牌是否未被占用
		bool check_result();					//判断甲是否胜利
		bool operator[](int);					//重载[]，相当于check_one
		void operator<<(int);					//重载<<，相当于choose
		void operator=(units);					//重载=，建立副本
		void f_true();							//文件输出正解
		void first_all();						//全局初始化
		void del(int);							//"delete"的简写 禁用某张牌
		void choose(int);						//对某张牌标记占用并标记因子占用
		void out_ss_add();						//输出未占用的牌
		void out_set_add();						//输出set_add的状态
};
//for unit
//初始化
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
//输出单元状态
void unit::check_unit()	
{
	cout<<"check"<<endl;
	cout<<"    add="<<add<<endl;
	cout<<"    s="<<s<<endl;
	cout<<"    ss=";
	for(int i=0;i<s;i++) cout<<ss[i]<<' ';
	cout<<endl;
}
//重载=，建立副本
void unit::operator=(unit m)
{
	add=m.add;
	s=m.s;
	for(int i=0;i<5;i++) ss[i]=m.ss[i];
}
//for units
//报错开关
void units::error(bool n)
{	
	ERROR=n;
}
//调试专用
void units::test(bool n)
{
	TEST=n;
}
//全局初始化
void units::first_all()
{			
	ERROR=0;
	TEST=0;
	NUM=0;
	for(int i=1;i<24;i++)
	{
		set[i].first(i);
		set_add[i]=0;
	}
}
//输出某个单元的状态(调试专用)
void units::check_units(int n)	
{
	if(TEST!=1) return;
	set[n].check_unit();
	cout<<"    set_add="<<set_add[n]<<endl;
}
//获取某张牌某个因子的状态
int units::get_ss_add(int n,int i)
{	
	if(set[n].ss[i]==-13 || i<0 || i>=set[n].s)
	{	
		if(ERROR) cout<<"error get_ss_add"<<endl;
		return -13;
	}
	return set[set[n].ss[i]].add;
} 
//判断该张牌是否有因子未被占用
bool units::find(int n)
{			
	if(n==1)
		return 0;
	for(int i=0;i<set[n].s;i++)
		if(get_ss_add(n,i)==0) return 1;
	return 0;
}
//将某张牌的占用更新
void units::sign(int n,int j)
{		
	set[n].add=j;
	if(j==1)
	{
		NUM++;
		set_add[n]=NUM;
	}
	if(j==2) set_add[n]=-NUM;
}
//"search_sign"的简写 将某张牌的所有因子更新占用
void units::srch_sg(int n,int j)
{
	if(find(n))
	{
		for(int i=0;i<set[n].s;i++) 
			if(get_ss_add(n,i)==0) sign(set[n].ss[i],j);
	}else
		if(ERROR) cout<<"error srch_sg"<<endl;	
}
//"delete"的简写 禁用某张牌
void units::del(int n)
{			
	set[n].add=-1;
	set[n].s=0;
	for(int i=0;i<5;i++) set[n].ss[i]=-13;
} 
//对某张牌标记占用并标记因子占用
void units::choose(int n)
{
	if(n==1) return;
	if(set[n].add!=0) return;
	if(check_one(n))
	{
		sign(n,1);
		srch_sg(n,2);
	}
	else if(ERROR) cout<<"error chooes"<<endl;
} 
//"delete_all"的简写 全局禁用（调试专用）
void units::del_all()	
{
	if(TEST!=1)
	{
		cout<<"error not_in_test"<<endl;
		return;
	}
	for(int i=1;i<24;i++) del(i);
} 
//判断是否有牌未被占用
bool units::check_all() 
{			
	for(int i=2;i<24;i++)
		if(set[i].add==0 && check_one(i))
			return 1; 
	return 0;
}
//判断该张牌是否可选
bool units::check_one(int n) 
{
	if(set[n].add==0 && find(n)) return 1;
	else return 0;
}
//判断甲是否胜利
bool units::check_result()	
{
	int ans=0;
	for(int i=1;i<24;i++)
		if(set[i].add==1) ans+=i;
	if(ans*2>=276) return 1;
	return 0;
}
//输出结果及输赢
int units::result(){
	cout<<"result:"<<endl;
	cout<<"    the integers A got ( in order ): ";
	out_set_add();
	int ans=0;
	for(int i=1;i<24;i++)
		if(set[i].add==1) ans+=i;
	cout<<endl;
	if(ans<0 ||ans>276)
		if(ERROR) cout<<"error result"<<endl;	
	cout<<"    the sum of A:"<<ans<<' ';
	if(ans*2<276) cout<<" lost";
	if(ans*2==276) cout<<" draw";
	if(ans*2>276) cout<<" win";
	cout<<endl;
	return ans;
}
//输出未占用的牌
void units::out_ss_add()
{
	cout<<"    the num you can choose: ";
    for(int i=1;i<24;i++)
    {
        if(set[i].add==0 && find(i))
            cout<<i<<' ';
    }
    cout<<endl;
}
//调试专用
int units::get_ss_add(int n,int i,char ch)
{
	if(ch!='t' || TEST!=1)
	{
		cout<<"error not_in_test"<<endl;
		return -13; 
	}
	return get_ss_add(n,i);
}
//调试专用
void units::sign(int n,int j,char ch)
{
	if(ch!='t' || TEST!=1)
	{
		cout<<"error not_in_test"<<endl;
		return; 
	}
	sign(n,j);
}
//调试专用
void units::srch_sg(int n,int j,char ch)
{
	if(ch!='t' || TEST!=1)
	{
		cout<<"error not_in_test"<<endl;
		return; 
	}
	srch_sg(n,j);
}
//按顺序输出set_add(被甲选中)
void units::out_set_add()
{
	for(int i=1;i<=NUM;i++)
	{
		for(int j=1;j<24;j++)
		{
			if(set_add[j]<=0) continue;
			if(set_add[j]==i) cout<<j<<' ';
		}
	}
}
//文件输出正解
void units::f_true()
{
	if(check_result()!=1) return;
	std::ofstream fout;
	fout.open("answer.txt",
		std::ios_base::out | std::ios_base::app);
	if(fout.is_open())
	{
		for(int i=1;i<=NUM;i++)
		{
			for(int j=1;j<24;j++)
			{
				if(set_add[j]<=0) continue;
				if(set_add[j]==i) fout<<j<<' ';
			}
		}
		fout<<endl;
	}
	else if(ERROR) cout<<"error fout"<<endl;
	fout.close();
}
//重载[]，相当于check_one
bool units::operator[](int n)
{
	return check_one(n);
}
//重载<<，相当于choose
void units::operator<<(int n)
{
	choose(n);
}
//重载=，建立副本
void units::operator=(units m)
{
	//the control num
	ERROR=m.ERROR;
	TEST=m.TEST;
	NUM=m.NUM;
	//set_add
	for(int i=1;i<23;i++) set_add[i]=m.set_add[i];
	//for unit
	for(int i=1;i<23;i++) set[i]=m.set[i];
}
//文件输出结果及输赢
void units::f_result()
{
	std::ofstream fout;
	fout.open("result.txt",
		std::ios_base::out | std::ios_base::app);
	if(fout.is_open())
	{
		fout<<"result:"<<endl;
		fout<<"    the integers A got ( in order ): ";
		fout.close();
		fout.clear();
		f_out_set_add();
		fout.open("result.txt",
			std::ios_base::out | std::ios_base::app);
		int ans=0;
		for(int i=1;i<24;i++)
			if(set[i].add==1) ans+=i;
		fout<<endl;
		if(ans<0 ||ans>276)
			if(ERROR) fout<<"error result"<<endl;	
		fout<<"    the sum of A:"<<ans<<' ';
		if(ans*2<276) fout<<" lost";
		if(ans*2==276) fout<<" draw";
		if(ans*2>276) fout<<" win";
		fout<<endl;
	}else if(ERROR) cout<<"error fout"<<endl;
	fout.close();
}
//文件输出set_add的状态
void units::f_out_set_add()
{
	std::ofstream fout;
	fout.open("result.txt",
		std::ios_base::out | std::ios_base::app);
	if(fout.is_open())
	{
		for(int i=1;i<=NUM;i++)
		{
			for(int j=1;j<24;j++)
			{
				if(set_add[j]<=0) continue;
				if(set_add[j]==i) fout<<j<<' ';
			}
		}
	}else if(ERROR) cout<<"error fout"<<endl;
	fout.close();
}
#endif