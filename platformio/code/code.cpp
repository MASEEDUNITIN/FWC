#include<Arduino.h>
void setup() {
    pinMode(4, OUTPUT);  
    pinMode(5, OUTPUT);
    pinMode(8, OUTPUT);

}
 void func(int A, int B){
   int op;
   digitalWrite (4,A);
   digitalWrite (5,B);
   op = (!A&&B)||(A&&!B);
   digitalWrite (8,op);
}   
void loop() {  
 func(0,0);
 delay(1000);
 func(0,1);
 delay(1000);
 func(1,0);
 delay(1000);
 func(1,1);
 delay(1000);
}