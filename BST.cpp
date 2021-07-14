#include "BST.h"
/////////////////////////////constructor
BST::BST(){
    isempty=true;
    title=" ";
    day=0;
    hour=0;
    treeleft=NULL;
    treeright=NULL;
}
/////////////////////
/////////////////////////////insert function
void BST::insert(string t,int d,int h){
    if(isempty){
        treeleft=new BST;
        treeright=new BST;
        isempty=false;
        title=t;
        day=d;
        hour=h;
    }
    else if(d<day||(d==day&&h<hour)){
        treeleft->insert(t,d,h);
    }
    else if(d>day||(d==day&&h>hour)){
        treeright->insert(t,d,h);
    }
    else{
        if(firstflag==false){
            cout<<"Conflict "<<d<<" "<<h;
            firstflag=true;
        }
        else{
            cout<<"\nConflict "<<d<<" "<<h;
        }
    }
}
///////////////////////
////////////////////////////////find function
void BST::find(int d,int h){
    if(!isempty){
        if(d==day&&h==hour){
            if(firstflag==false){
               cout<<'"'<<title<<'"';
               firstflag=true;
            }
            else{
                cout<<"\n"<<'"'<<title<<'"';
            }
        }
        else if(d<day||(d==day&&h<hour)){
            treeleft->find(d,h);
        }
        else if(d>day||(d==day&&h>hour)){
            treeright->find(d,h);
        }
        /*
        else{
            if(firstflag==false){
                cout<<"Empty "<<d<<" "<<h;
                firstflag=true;
            }
            else{
                cout<<"\nEmpty "<<d<<" "<<h;
            }
        }
        */
    }
    else{
        if(firstflag==false){
            cout<<"Empty "<<d<<" "<<h;
            firstflag=true;
        }
        else{
            cout<<"\nEmpty "<<d<<" "<<h;
        }
    }
}
/////////////////////////////
////////////////////////////////////////modify function
void BST::modify(string e,int d,int h){
    if(!isempty){
        if(d==day&&h==hour){
            title=e;
        }
        else if(d<day||(d==day&&h<hour)){
            treeleft->modify(e,d,h);
        }
        else if(d>day||(d==day&&h>hour)){
            treeright->modify(e,d,h);
        }
        /*
        else{
            if(firstflag==false){
                cout<<"Empty "<<d<<" "<<h;
                firstflag=true;
            }
            else{
                cout<<"\nEmpty "<<d<<" "<<h;
            }
        }
        */
    }
    else{
        if(firstflag==false){
            cout<<"Empty "<<d<<" "<<h;
            firstflag=true;
        }
        else{
            cout<<"\nEmpty "<<d<<" "<<h;
        }
    }
}
///////////////
//////////////////////////print function
void BST::print(){
    if(!isempty){
        treeleft->print();
        if(firstflag==false){
                cout<<'"'<<title<<'"'<<" "<<day<<" "<<hour;
                firstflag=true;
        }
        else{
            cout<<"\n"<<'"'<<title<<'"'<<" "<<day<<" "<<hour;
        }
        treeright->print();
    }
}
///////////
/////////////////////////////isempty function
bool BST::isemp(){
    return isempty;
}
//////////
///////////////////////////delete function
void BST::del(int d,int h,BST* ptr,bool& fflag){
    if(!isempty){
        treeleft->del(d,h,ptr,fflag);
        if(!(d==day&&h==hour)){
            ptr->insert(title,day,hour);
        }
        else{
            fflag=true;
        }
        treeright->del(d,h,ptr,fflag);
    }
}

