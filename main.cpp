/*
 * main.cpp
 *Otmane Chaibe
 * CS280
 * Fall 2019
 */
#include <iostream>
#include <fstream>
#include <string>
#include "lex.h"
#include <list>
#include <sstream> 
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc,  char * argv[]) {
    int lineNumber  =0;
    bool vFlag=false; //-v  (optional)  if present, every token is printed when it is seen
    bool idsFlag =false;//-ids (optional) if present, print out all of the identifiers in alphabetical order 
    bool constsFlag =false;//-consts (optional) if present, print out all the string constants in alphabetical orderfollowed by all the integer constants in numeric order
   
    istream *in = &cin;
    
    ifstream inFile;
   
    for(int i =1; i<argc; i++){
    
     string arg(argv[i]);
        
    if(arg == "-v"){ 
        vFlag = true ;
      
    }
    else if(arg =="-ids"){
     idsFlag = true;

    }

    else if(arg == "-consts"){
   constsFlag = true;

    }

   else if(arg[0] == '-'){
       cout<< "UNRECOGNIZED FLAG " << arg <<endl;
    return -1;
   } 


   else if (i == argc-1){



    inFile.open(arg);

  if( inFile.is_open() == false ) {
    cout << "CANNOT OPEN "<< arg << endl;
    return -1;
    } 
   if(inFile.peek()==EOF){
       cout<<"Lines: "<< lineNumber<<endl;

    }
        in = &inFile; 
     

    }

    else{

     cout << "ONLY ONE FILE NAME ALLOWED" <<endl;
    return -1;
    }


  
    }
    
    
    
    
    
    Lex tok;
    int Tokens=0;
   
    list<string> ids;
    list<string> strings;
    list<int> ints;
    
    while((tok = getNextToken(*in, lineNumber)) != ERR && tok != DONE){
        
     
        Tokens++;
        if(vFlag){
          cout<<tok<<endl;
        } 
    
        
        
        if(idsFlag && tok== ID){
            ids.push_back(tok.GetLexeme());
        }
        
        if(constsFlag  && tok==STR ){
            strings.push_back(tok.GetLexeme());
        
        }
        if(constsFlag  && tok==INT ){
            int temp = stoi(tok.GetLexeme());
            
            ints.push_back(temp);
        
        }
        
       
    }
    
    ///// 
    
    if(tok== ERR){
        if(lineNumber<=2){
        cout<< "Error on line " << lineNumber+1 << " (" <<tok.GetLexeme()<< ")"<<endl;
        }
        else{
        cout<< "Error on line " << lineNumber+1 << " (" <<tok.GetLexeme()<< ")"<<endl;
        }
        return -1;
    }
    
    
    ////
    
     if(idsFlag){
         if(ids.size()>0){
          ids.unique();
          ids.sort();
         
         cout<< "IDENTIFIERS: ";
          for (string n : ids) {
              
           cout << n;
              if(n.compare(ids.back())){
                  cout<<", ";
              }
           
    }  cout<<endl;
         if(!vFlag){
         cout<<"Lines: "<< tok.GetLinenum()<<endl;
  
 
            if(Tokens <=8){
            cout<<"Tokens: " << Tokens+1  <<endl;
            }else{
            cout<<"Tokens: " << Tokens  <<endl;
            }
         }}
         
            
        }
       
        
       
    
 if(vFlag && !constsFlag ){  
    if(vFlag ){
  
    cout<<"Lines: "<< tok.GetLinenum()<<endl;
  
 
    if(Tokens >=0){
    
    cout<<"Tokens: " << Tokens <<endl;}
    }
  
    
 }
    if(constsFlag){
           if(vFlag && constsFlag){
                if(strings.size()>0){
            strings.sort();
            cout<< "STRINGS:"<<endl;
            
           
            for (string s : strings) {
              
        
          
           cout << s<<endl;
             
            }   
     } 
        }
       else if(strings.size()>0){
            strings.sort();
            cout<< "STRINGS:"<<endl;
            
           
            for (string s : strings) {
              
        
          
           cout << s<<endl;
             
           
     } 
           
         }
        else if(ints.size()>0){
            ints.unique();
            ints.sort();
            cout<< "INTEGERS:"<<endl;
            
           for(int i: ints){
           
              
                   cout<<i<<endl;
              
                   
           }}
       
         cout<<"Lines: "<< tok.GetLinenum()<<endl;
  
 
            if(Tokens <=8){
            cout<<"Tokens: " << Tokens<<endl  ;
            }else{
            cout<<"Tokens: " << Tokens<<endl  ;
            }
        
     
           
}    
    else if ( !constsFlag &&!vFlag &&!idsFlag){
       if(lineNumber==0){
           
       }
        
        else {if(lineNumber>0){
        cout<<"Lines: "<< tok.GetLinenum()<<endl;
        }
 
            if(Tokens <=8){
            cout<<"Tokens: " << Tokens  <<endl;
            }else{
            cout<<"Tokens: " << Tokens  <<endl;
            }
        }
        
    }
             
             
  
    
    
    return 0;
}
