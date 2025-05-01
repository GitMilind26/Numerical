#include<iostream>
using namespace std;
double function(double x){
    return x*x*x-x-11;
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
        c = (a+b)/2;
        if (function(c) == 0.0){
            
            break;
        }
        else if (function(c)*function(a) < 0){
                
                b = c;
        }
        else{
                
                a = c;
        }
     cout<<"("<<a<<b<<")"<<endl;
    }
    
  
}
int main(){
     
    check(2,3);
 
 if(c!=0){
     cout<<"Root is "<<c<<endl;
}
}
