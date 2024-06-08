#ifndef UHIT_H_
#define UNIT_H_
#include <iostream>
struct unit {
	int add,	//标记  (-1,0,1,2) 
		s,		//因子个数 
		ss[5];	//因子表 
	
	void first(int n){	//初始化 
		add=0;
		int goal=0;
		for(int i=1;i<n;i++){
			if(n%i==0){			//填充因子 
				ss[goal]=i;
				goal++;
			}
		}
		s=goal;
		for(int i=goal;i<5;i++){
			ss[i]=-13;		//填充空位(-13) 
		} 
	}
};
struct units {
	private:
		unit set[24];	//集合 1~23 
	public:
		bool ERROR;			//报错标记 
		
		void error(bool n){	//报错开关 
			ERROR=n;
		}
		void first_all(){			//集合初始化 
			ERROR=1;
			for(int i=1;i<24;i++){
				set[i].first(i);
			}
		}
		int getadd(int n,int i){	//返回因子标记 
			using namespace std;
			if(set[n].ss[i]==-13 || i<0){	//error
				if(ERROR)
					cout<<"====getadd-error===="<<endl;
				return -13;
			}
			return set[set[n].ss[i]].add;
		} 
		bool find(int n){			//检查n是否可选 
			for(int i=0;i<set[n].s;i++){
				if(getadd(n,i)==0)
					return 1;
			}
			return 0;
		}
		void sign(int n,int j){		//标记赋值 
			set[n].add=j;
		} 
		void srch_sg(int n,int j){	//因子标记赋值 
			using namespace std;
			if(find(n)){
				for(int i=0;i<set[n].s;i++){
					if(getadd(n,i)==0){
						sign(set[n].ss[i],j);
					}
				}
			}else{
				if(ERROR)
					cout<<"====srch_sg-error===="<<endl;	//error
			}
		}
		void del(int n){			//禁用该元素 
			set[n].add=-1;
			set[n].s=0;
			for(int i=0;i<5;i++){
				set[n].ss[i]=-13;
			}
		} 
		bool choose(int n){			//标记元素及因子 
			if(set[n].add!=0)
				return 0;
			sign(n,1);
			srch_sg(n,2);
			return 1;
		} 
		void del_all(){				//禁用所有元素 
			for(int i=1;i<24;i++){
				del(i);
			}
		} 
		bool check_all(){			//检查元素是否耗尽 
			for(int i=1;i<24;i++){
				if(find(i)) return 1; 
			}
			return 0;
		}
		bool check_one(int n){
			if(set[n].add==0 && find(n)){
				return 1;
			}else{
				return 0;
			}
		}
		bool check_result(){
			int ans=0;
			for(int i=1;i<24;i++){
				if(set[i].add==1){
					ans+=i;
				}
			}
			if(ans>=138){
				return 1;
			}else{
				return 0;
			}
		}
		int result(){
			using namespace std;
			cout<<'-'<<endl;
			cout<<"the integers A got ( no order ):";
			int ans=0;
			for(int i=1;i<24;i++){
				if(set[i].add==1){
					cout<<i<<' ';
					ans+=i;
				}
			}
			cout<<endl;
			if(ans<0 ||ans>276)
				if(ERROR)
					cout<<"====result-error===="<<endl;	//error
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
};
#endif
