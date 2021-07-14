#include "BST.h"
#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
using namespace std;
bool firstflag=false;
int main(int argc,char** argv){
    BST *tree=new BST;
    ifstream comfile(argv[1]);
    if(!(comfile.is_open())){
        cout<<"File not found";
        return 0;
    }
    string command;
    bool dvalid,hvalid,tvalid;
    int d,h;
    string t,order,title,day,hour,word;
    int state,argu;
    while (getline(comfile,command)){
        ////////////////parsing
        if(command=="\0"||command=="\n"||command=="\r")
			continue;
        order=" ";
        title=" ";
        day=" ";
        hour=" ";
        word="";
        t="";
        argu=0;
        state=1;
        dvalid=false;
        hvalid=false;
        tvalid=false;
        d=0;
        h=-1;
        for(char& c:command){
            if(c==' '&&state<=2){
                if(state==1){
                    if(argu==0){
                        order=word;
                        word="";
                        argu=1;
                    }
                    else if((order=="ADD"||order=="MOD")&&argu==1){
                        title=word;
                        word="";
                        argu=2;
                    }
                    else if(((order=="Find"||order=="DEL")&&argu==1)||((order!="Find"||order!="DEL")&&argu==2)){
                        day=word;
                        word="";
                        if(order=="Find"||order=="DEL"){
                            argu=2;
                        }
                        else{
                            argu=3;
                        }
                    }
                    else if(((order=="Find"||order=="DEL")&&argu==2)||((order!="Find"||order!="DEL")&&argu==3)){
                        hour=word;
                        word="";
                        if(order=="Find"||order=="DEL"){
                            argu=3;
                        }
                        else{
                            argu=4;
                        }
                    }
                    else{
                        argu=5;
                    }
                    state=2;
                }
                
            }
            else if(state==1||(state==2&&c!='"')){
                string ss(1,c);
                word=word+ss;
                state=1;
            }
            else if(state==2&&c=='"'){
                string ss(1,c);
                word=word+ss;    
                state=3;
            }
            else if(state==3&&c!='"'){
                string ss(1,c);
                word=word+ss;                
            }
            else if(state==3&&c=='"'){
                if((order=="ADD"||order=="MOD")&&argu==1){
                    title=word;
                    word="";
                    argu=2;
                }
                else{
                    word="";
                    argu=5;
                }
                state=2;
            }
        }
        if(argu==0&&state<=2){
            order=word;
            argu=1;
        }
        else if(argu==1&&state<=2){
            if(order=="Find"||order=="DEL"){
                day=word;
                argu=2;
            }
            else if(order=="Print"){
                argu==5;
            }
            else{
                argu=2;
                title=word;
            }
        }
        else if(argu==2&&state<=2){
            if(order=="Find"||order=="DEL"){
                hour=word;
                argu=3;
            }
            else if(order=="Print"){
                argu==5;
            }
            else{
                argu=3;
                day=word;
            }
        }
        else if(argu==3&&state<=2){
            if(order=="Find"||order=="DEL"){
                argu==5;
            }
            else if(order=="Print"){
                argu==5;
            }
            else{
                argu=4;
                hour=word;
            }
        }
        else if(word!=""){
            argu=5;
        }
        /////check for 3valids
        stringstream ss;  
        ss << day;  
        ss >> d;
        stringstream sss; 
        sss << hour;  
        sss >> h;
        if(d>=1&&d<=365){
            dvalid=true;
        }
        if(h>=0&&h<=23){
            hvalid=true;
        }
        for(char& cc:title){
            if(!tvalid&&cc=='"'){
                tvalid=true;
            }
            else if(tvalid&&cc!='"'){
                string x(1,cc);
                t=t+x;
            }
        }
        //cout<<"command: "<<order<<" title: "<<t<<" day: "<<d<<" hour: "<<h<<" argunum: "<<argu<<endl;
        ///need to fill 3valids,order,t,d,h,argu 
        ///////////////////commands
        ///////////////ADD
        //////////////////////////////////////
        if(order=="ADD"){
            if(tvalid&&dvalid&&hvalid&&argu==4){
                tree->insert(t,d,h);
            }
            else{
                if(argu!=4&&!firstflag){
                    cout<<"Invalid arguments";
                    firstflag=true;
                }
                else if(argu!=4&&firstflag){
                    cout<<"\nInvalid arguments";
                }
                else if(!tvalid&&!firstflag){
                    cout<<"Invalid title";
                    firstflag=true;
                }
                else if(!tvalid&&firstflag){
                    cout<<"\nInvalid title";
                }
                else if(!dvalid&&!firstflag){
                    cout<<"Invalid day";
                    firstflag=true;
                }
                else if(!dvalid&&firstflag){
                    cout<<"\nInvalid day";
                }
                else{
                    if(!firstflag){
                        cout<<"Invalid hour";
                        firstflag=true;
                    }
                    else{
                        cout<<"\nInvalid hour";
                    }
                }
            }
        }
        ////////////////////////////
        //////////////////////////////Find
        else if(order=="Find"){
            if(dvalid&&hvalid&&argu==3){
                tree->find(d,h);
            }
            else{
                if(argu!=3&&!firstflag){
                    cout<<"Invalid arguments";
                    firstflag=true;
                }
                else if(argu!=3&&firstflag){
                    cout<<"\nInvalid arguments";
                }
                else if(!dvalid&&!firstflag){
                    cout<<"Invalid day";
                    firstflag=true;
                }
                else if(!dvalid&&firstflag){
                    cout<<"\nInvalid day";
                }
                else{
                    if(!firstflag){
                        cout<<"Invalid hour";
                        firstflag=true;
                    }
                    else{
                        cout<<"\nInvalid hour";
                    }
                }
            }
        }
        ///////////////////
        //////////////////////////MOD
        else if(order=="MOD"){
            if(tvalid&&dvalid&&hvalid&&argu==4){
                tree->modify(t,d,h);
            }
            else{
                if(argu!=4&&!firstflag){
                    cout<<"Invalid arguments";
                    firstflag=true;
                }
                else if(argu!=4&&firstflag){
                    cout<<"\nInvalid arguments";
                }
                else if(!tvalid&&!firstflag){
                    cout<<"Invalid title";
                    firstflag=true;
                }
                else if(!tvalid&&firstflag){
                    cout<<"\nInvalid title";
                }
                else if(!dvalid&&!firstflag){
                    cout<<"Invalid day";
                    firstflag=true;
                }
                else if(!dvalid&&firstflag){
                    cout<<"\nInvalid day";
                }
                else{
                    if(!firstflag){
                        cout<<"Invalid hour";
                        firstflag=true;
                    }
                    else{
                        cout<<"\nInvalid hour";
                    }
                }
            }
        }
        ////////////////////////
        ///////////////////////////////DEL
        else if(order=="DEL"){
            if(dvalid&&hvalid&&argu==3){
                bool flag=false;
                BST* treetemp=new BST;
				tree->del(d,h,treetemp,flag);
				tree->dist();
				free(tree);
				tree=treetemp;
                if(!flag){
                    if(firstflag==false){
                        cout<<"Empty "<<d<<" "<<h;
                        firstflag=true;
                    }
                    else{
                        cout<<"\nEmpty "<<d<<" "<<h;
                    }
                }
            }
            else{
                if(argu!=3&&!firstflag){
                    cout<<"Invalid arguments";
                    firstflag=true;
                }
                else if(argu!=3&&firstflag){
                    cout<<"\nInvalid arguments";
                }
                else if(!tvalid&&!firstflag){
                    cout<<"Invalid title";
                    firstflag=true;
                }
                else if(!tvalid&&firstflag){
                    cout<<"\nInvalid title";
                }
                else if(!dvalid&&!firstflag){
                    cout<<"Invalid day";
                    firstflag=true;
                }
                else if(!dvalid&&firstflag){
                    cout<<"\nInvalid day";
                }
                else{
                    if(!firstflag){
                        cout<<"Invalid hour";
                        firstflag=true;
                    }
                    else{
                        cout<<"\nInvalid hour";
                    }
                }
            }
        }
        //////////////////////////
        ///////////////////////////////////////Print
        else if(order=="Print"){
            if(argu==1){
				if(tree->isemp()){
					if(!firstflag){
                        cout<<"Empty Planner";
                        firstflag=true;
                    }
                    else{
                        cout<<"\nEmpty Planner";
                    }
				}
				else{
					tree->print();
				}
            }
            else{
                if(!firstflag){
                    cout<<"Invalid arguments";
                    firstflag=true;
                }
                else{
                    cout<<"\nInvalid arguments";
                }
            }
        }
        else{
            if(!firstflag){
                cout<<"Invalid command";
                firstflag=true;
            }
            else{
                cout<<"\nInvalid command";
            }
        }
    }
}