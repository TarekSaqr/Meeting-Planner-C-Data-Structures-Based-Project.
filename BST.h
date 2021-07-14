#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;
extern bool firstflag;
#define btElemtype char
class BST{
    public:
        BST();
        void insert(string t,int d,int h);
        void find(int d,int h);
        void modify(string t,int d,int h);
        void del(int d,int h,BST* ptr,bool& fflag);
        void print();
        bool isemp();
        void dist(){
            delete(treeleft);
            delete(treeright);
            isempty=true;
        }
        bool FDEL(int d,int h,bool& flag);
        bool FDEL1(int d,int h,BST* ptr);
        void DEL(BST* p1,BST* p2,bool flag);
        void analysis(int d,int h,BST* tree,bool flagy);
    private:
        bool isempty;
        string title;
        int day;
        int hour;
        BST* treeleft;
        BST* treeright;
};