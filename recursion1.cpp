#include <iostream>
using namespace std;

int getmypositioninline(Person person){
    if(person.nextInLine==null){
        return 1;
    }
    return 1+ getmypositioninline(person.nextInLine)
}