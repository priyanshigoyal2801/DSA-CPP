#include<iostream>
using namespace std;
class unknown_word{};
class bad_grammar{};
void translate(int a) throw(unknown_word,bad_grammar){
    
    if (a==0) throw unknown_word();
    else if(a==1) throw bad_grammar();
    else throw 10;
}
int main(){
    try{
    translate(0);
    }
    catch(...){
        cout<<"caught";
    }
}