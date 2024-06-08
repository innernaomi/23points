#include <bits/stdc++.h>
#include "unit.h"
#include "important.h"
using namespace std;

int T1[13]={4,6,8,9,10,12,14,15,16,18,20,21,22};	//合数 
int T2[9]={2,3,5,7,11,13,17,19,23};					//质数 

int main(){
	/*long long n=0;
	int goal[12];
	for(int i0=0;i0<9;i0++){	//选择质数 
		goal[0]=T2[i0];
		for(int i1=0;i1<13;i1++){	//选择合数 
			goal[1]=T1[i1];
			for(int i2=0;i2<13;i2++){
				if(i1==i2)
					continue;
				goal[2]=T1[i2];
				for(int i3=0;i3<13;i3++){
					if(i1==i3 or i2==i3)
						continue;
					goal[3]=T1[i3];
					for(int i4=0;i4<13;i4++){
						if(i1==i4 or i2==i4 or i3==i4)
							continue;
						goal[4]=T1[i4];
						for(int i5=0;i5<13;i5++){
							if(i1==i5 or i2==i5 or i3==i5 or i4==i5)
								continue;
							goal[5]=T1[i5];
							for(int i6=0;i6<13;i6++){
								if(i1==i6 or i2==i6 or i3==i6 or i4==i6 or i5==i6)
									continue;
								goal[6]=T1[i6];
								for(int i7=0;i7<13;i7++){
									if(i1==i7 or i2==i7 or i3==i7 or i4==i7 or i5==i7 or i6==i7)
										continue;
									goal[7]=T1[i7];
									cout<<n<<' ';
									n++;
									choose(goal,8);
								}
							}
						}
					}
				}
			}
		}
	} 
	*/
	units m;
	m.first_all();
	m.choose(23);
	cout<<m.choose(3);
}
