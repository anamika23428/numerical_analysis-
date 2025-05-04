#include<bits/stdc++.h>
using namespace std;

#define e 1e-4

double fp1(double p2,double p3){
	return (50 - 0.2*p3 - 0.1*p2)/0.2;
	}
	
double fp2(double p1, double p5,double p3){
	return (75 - 0.1*(p1 + p3+p5))/0.4;
	}
	
double fp3(double p2,double p6){
	return (100 -0.2*(p2+p6) )/0.1;
	}

	
double fp4(double p1, double p5,double p7){
	return (125 - 0.1*(p1 + p7 +p5))/0.3;
	}

double fp5(double p2, double p4,double p6,double p8){
	return (150 - 0.2*(p2 + p6) - 0.1*(p4 + p8) )/0.3;
	}
	
double fp6(double p3, double p5,double p9 ){
	return (175 - 0.2*(p5) - 0.1*(p3  + p9) )/0.1;
	}

double fp7(double p4, double p5 ){
	return (200 - 0.2*(p4) - 0.1*(p5) )/0.2;
	}
	
double fp8(double p5, double p9 ){
	return (255 - 0.1*(p5+p9) )/0.4;
	}	
	
double fp9(double p6, double p8 ){
	return (250 - 0.1*(p8) -0.2*(p6) )/0.2;
	}	 	
void jaccobi_iteration(double p01,double p02,double p03 ,double p04 ,double p05 , double p06 ,double p07 ,double p08 ,double p09){
	double p1=fp1(p02,p03);
	double p2=fp2(p01,p05 ,p03);
	double p3=fp3(p02,p06);
	double p4=fp4(p01,p05,p07);
	double p5=fp5(p02,p04 ,p06 ,p08);
	double p6=fp6(p03,p05,p09);
	double p7=fp7(p04,p05);
	double p8=fp8(p05,p09);
	double p9=fp9(p06,p08);
	int iter=1;
	//while(abs(p1-p01)>=e && abs(p2-p02)>=e && abs(p3-p03)>=e && abs(p4-p04)>=e && abs(p5-p05)>=e && abs(p6-p06)>=e && abs(p7-p07)>=e && abs(p8-p08)>=e  && abs(p9-p09)>=e  ){
	while(iter<12 ){
		p01=p1;
		p02=p2;
		p03=p3;
		p04=p4;
		p05=p5;
		p06=p6;
		p07=p7;
		p08=p8;
		p08=p9;
		
		p1=fp1(p02,p03);
	p2=fp2(p01,p05 ,p03);
		p3=fp3(p02,p06);
		 p4=fp4(p01,p05,p07);
	p5=fp5(p02,p04 ,p06 ,p08);
	 p6=fp6(p03,p05,p09);
	 p7=fp7(p04,p05);
	 p8=fp8(p05,p09);
	 p9=fp9(p06,p08);
		iter++;
		cout<<"p1: "<<p1<<endl;
	cout<<"p2: "<<p2<<endl;
	cout<<"p3: "<<p3<<endl;
	cout<<"p4: "<<p4<<endl;
	cout<<"p5: "<<p5<<endl;
	cout<<"p6: "<<p6<<endl;
	cout<<"p7: "<<p7<<endl;
	cout<<"p8: "<<p8<<endl;
	cout<<"p9: "<<p9<<endl;
		
	} 
	cout<<"solution: "<<endl;
	cout<<"p1: "<<p1<<endl;
	cout<<"p2: "<<p2<<endl;
	cout<<"p3: "<<p3<<endl;
	cout<<"p4: "<<p4<<endl;
	cout<<"p5: "<<p5<<endl;
	cout<<"p6: "<<p6<<endl;
	cout<<"p7: "<<p7<<endl;
	cout<<"p8: "<<p8<<endl;
	cout<<"p9: "<<p9<<endl;
	cout<<"iterations: "<<iter<<endl;
	return ;
	}
	
int main(){
	jaccobi_iteration(0,0,0,0,0,0,0,0,0);
	
	}
//solution is 	oscillating
//cout<<"p1: "<<p1<<endl;
//	cout<<"p2: "<<p2<<endl;
//	cout<<"p3: "<<p3<<endl;
//	cout<<"p4: "<<p4<<endl;
//	cout<<"p5: "<<p5<<endl;
//	cout<<"p6: "<<p6<<endl;
//	cout<<"p7: "<<p7<<endl;
//	cout<<"p8: "<<p8<<endl;
//	cout<<"p9: "<<p9<<endl;
