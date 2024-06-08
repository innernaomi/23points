#include "unit.h"
#include "important.h"
void choose_test(int a[],int b){
	units m;
	m.first_all();
	m.error(1);
	for(int i=0;i<b;i++){ 
		if(a[i]==0 or a[i]==1){
			continue;
		}
		if(m.check_one(a[i])!=1)
			continue;
		m.choose(a[i]);
	}
	m.result();
}
void choose(int a[],int b){				//主要的调用 
	units m;
	m.first_all();
	m.error(1);
	for(int i=0;i<b;i++){ 
		if(a[i]==0 or a[i]==1){
			continue;
		}
		if(m.check_one(a[i])!=1)
			continue;
		m.choose(a[i]);
	}
	if(m.check_result())
		m.result();
}
void test(){			//测试 
	int n[8]={23,22,21,16,12,18,15,20};
	choose(n,8);
} 
