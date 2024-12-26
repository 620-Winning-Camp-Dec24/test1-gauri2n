#include<iostream>
using namespace std;
 void area(int l,int b){
int areaofrectangle= l*b;
   cout<<"  area of rectangle  "<< areaofrectangle;
   cout<<endl;
   }
   void area(float b,float h){
    float areaoftriangle = 0.5 *b*h;
    cout<<"  area of triangle  "<<areaoftriangle;
cout<<endl;
   }
   void area(double r){
    double areaofcircle= 3.14*r*r;
    cout<<"  area of circle  "<<areaofcircle;
    cout<<endl;
   }
int main(){
    area(3,7);
    area(5.1f,7.0f);
    area(5.4545);
}