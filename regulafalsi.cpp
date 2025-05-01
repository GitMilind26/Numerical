#include<iostream>
using namespace std;
double function(double x){
    return x*x-2*x-1;
}
double c=0;
double StopValue = 0.00001;
double check(double a,double b){
      
 if(function(a) * function(b) >= 0)
    { cout<<"you have input wrong a and b"<<endl;
        
    }
    c=a;
        while ((b-a) >= StopValue)
    {
        c =  a-(((b-a)/(function(b)-function(a))) *function(a));
        cout<<"("<<a<<","<<b<<")"<<endl;
        if (function(c) == 0.0){
            
            break;
        }
        else if (function(c)*function(a) < 0){
                
                b = c;
        }
        else{
                
                a = c;
        }
     
    }
    
  
}
int main(){
     
check(2,3);
 
 if(c!=0){
     cout<<"Root is "<<c<<endl;
}
}
 
