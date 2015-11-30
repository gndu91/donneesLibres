#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>

using namespace std;

#define println(T)  print(T,profondeur(T));\
                    print('\n',0);

#define DO(t) int __ACCU__ = 0; while (__ACCU__++ < t)

template<typename T> int
profondeur(T t) {
    return 0;
}
template<typename T> int
profondeur(vector<T> t) {
    T t2;
    if(!t.size())
        t.push_back(t2);
    return profondeur(t.front()) + 1;
}


template<typename T>
void print(T t, int layer) {
    cout << t;
}

#warning FIXME (Ghoul Nadir#1#): Allow mote than 2 dimensions

template<typename T>
void print(vector<T> t, int layer) {
    print('{', layer);
    int i = 0;
    if(t.size()) {
        if(layer == profondeur(t))
            print('\n',layer);
        while(i < t.size()) {
            if(i > 0) {
                print(',',layer);
                if(layer == profondeur(t))
                    print('\n',layer);
            }
            DO(profondeur(t)-layer + 1) {
                print('\t',0);
            }
            print(t.at(i),layer);
            i+=1;
        }
        if(layer == profondeur(t))
            print('\n',layer);
    }else   print("__VOID__", layer);
    print('}', layer);
}

void fprint(string nom);
