#include <QCoreApplication>
#include <QPair>
#include <QDebug>
#include <QList>
#include <QMap>
#include "windows.h"
#include <iostream>




using namespace std;








int static right1=0;
int static count1=0;
QPair<int/*index el*/,int /*count call*/> binSearch(int* ar, int sizeAr, int el){
    int middle =sizeAr/2;
    count1++;
    if (ar[middle]==el){
        return{middle+right1,count1};
    }
    if (ar[middle]>el){
        if (sizeAr%2==0)
            sizeAr=sizeAr-middle;
        else
            sizeAr=sizeAr-1-middle;
        return binSearch(ar,sizeAr,el);
    }
    if (ar[middle]<el){
        right1+=middle+1;
        for (int i=0;i<middle;i++){
            int c=ar[i];
            ar[i]=ar[middle+1+i];
            ar[middle+1+i]=c;

        }

        sizeAr=sizeAr-middle-1;

        return binSearch(ar,sizeAr,el);

    }
}


template<class T1>
    class Filo {
        private :
            T1* ar;	//массив
            int size;	//размер массива
            int countData;	//число элементов в массиве
        public :
            Filo(){
                size=10;
                countData=0;
                ar=new T1[10];
            }
            Filo(int _size){
                size=_size;
                countData=0;
                ar=new T1 [_size];
            }
            ~Filo(){
                size=0;
                countData=0;
                delete[] ar;
            }

            int push_back(T1 el){
                if(countData>size-1)
                    return 0;
                if (ar==nullptr)
                    ar=new T1();

                ar[countData]=el;
                countData++;
                return 1;
            }

            pair<int,T1> pop_back(){
                if (countData<1)
                    return {0,0};
                if (ar==nullptr)
                    ar=new T1();
                countData--;
                return {1,ar[countData]};
            }
    };


template <typename T>
ostream & operator <<(ostream & os, const QPair<int,T> t){
    os<<"("<<t.first<<" , "<<t.second<<")"<<"\n";
    return os;
}


class CheckBrackets : public Filo<char> {
    private:


    public :
        CheckBrackets() : Filo<char>(256) { }
        ~CheckBrackets() {}


        int checkBrackets(const char* strBrackets){
            for (int i=0;strBrackets[i]!=NULL;i++){

               if (strBrackets[i]=='(')
                    push_back(strBrackets[i]);
                if (strBrackets[i]=='[')
                    push_back(strBrackets[i]);
                if (strBrackets[i]=='{')
                    push_back(strBrackets[i]);
                if (strBrackets[i]==')'){

                    if (pop_back().second!='('){
                        return -1;
                    }
                }
                if (strBrackets[i]=='}'){

                    if (pop_back().second!='{'){
                        return -1;
                    }
                }
                if (strBrackets[i]==']'){
                    if (pop_back().second!='['){
                        return -1;
                    }
                }
            }
            if (pop_back().first!=0)
                return -1;
            return 0;
        }
    };




int main(int argc, char *argv[])
{



    return 0;
  //  return a.exec();
}
