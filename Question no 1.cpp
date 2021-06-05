#include<iostream>
#include<time.h>
#include<string>
#include<fstream>
using namespace std;

//CREATING FUNCTION TO FIT WORDS IN GRID
void Create_Grid(int Rows , int Columns , int Word_No,string File_Name,string Oppening_File){
//CREATING FILE TO READ WORDS FROM GIVEN INPUT IN FILE
 ifstream File(File_Name);
//CREATING ARRAY OF STRING TO COLLECTWORDS IN STRING
 string Collect[Rows];
//APPLYING FOR LOOP TO COLLECT THE GIVEN INPUT
 for(int i=0;i<Rows;i++){

    getline(File,Collect[i]);
 }
//CRATING 2D CHAR ARRAY TO STORE RANDOM ALPHABETS IN 2D ARRAY
 char Grid[Rows][Columns];
//APPLYING FOR LOOP INODER TO STORE RANDOM ALPHABETS
 for(int i=0;i<Rows;i++){
    for(int j=0;j<Columns;j++){

        int r=0;
        char c;
        r=rand( )%26;
        c='A'+r;
        Grid[i][j]=c;
    }
 }
//DECLAING VARIABLE INORDER TO STORE THE LENGTH OF LONGEST WORD.
 int count=0;
 int Temp=0;
 int Temp2=0;

 for(int i=0;i<Rows;i++){

    for(int j=0;Collect[i][j]!='\0';j++){

        Grid[i][j]=Collect[i][j];

       Temp=j+1;
        }

//STORING THE LENGTH OF LONGEST WORD IN VARIABLE TEMP2
        if(Temp>Temp2){

            Temp2=Temp;
    }
 }

 //APPLYING CONDITION THAT IF WORD IS LONGER THEN GIVEN DIMENSION THE GRID SHOULD NOT BE PRINTED
 if(Temp2>Columns){

    cout<<" Grid Can,t be formed!!"<<endl;
 }else{
//ASKING USER TO NAME A FILE INORDER TO STORE DESIRE OUTPUT
 ofstream Secound_File;

 Secound_File.open(Oppening_File);

//PRINTING THE DESIRE OUTPUT IN THE FILE DECLARE BY USER
 for(int i=0;i<Rows;i++){
    for(int j=0;j<Columns;j++){

        Secound_File<<Grid[i][j]<<" ";
    }

    Secound_File<<endl;
 }
 }

}

//CHECK LEFT TO RIGHT
void Left_Right( int i,int j,string n,char A[18][19],string Open){
int q=0;
int c=0;
int p=0;
p=j;
c=n.length( )-1;
  for(int k=j,l=0;k<n.length( );k++,l++){

    if(A[i][k]==n[l]){
        q++;
    }
  }

  ofstream File_Open;
  File_Open.open(Open);

  if(q==n.length( )){
    cout<<"{"<<i<<","<<j<<"}"<<"{"<<i<<","<<p+c<<"}"<<endl;
    File_Open<<"{"<<i<<","<<j<<"}"<<"{"<<i<<","<<p+c<<"}"<<endl;
  }

}

//CHECK RIGHT TO LETF
void Right_Left( int i,int j,string n,char A[18][19],string Open){
int q=0;
int x=0;
int l=0;
l=n.length( );
x=j-l;

if(x<0){
    x=0;
}
  for(int k=j,l=0;k>=x;k--,l++){

    if(A[i][k]==n[l]){
        q++;
    }
  }


  ofstream File_Open;
  File_Open.open(Open);

  if(q==n.length( )){
    cout<<"{"<<i<<","<<j<<"}{"<<i<<","<<x<<"}"<<endl;
    File_Open<<"{"<<i<<","<<j<<"}{"<<i<<","<<x<<"}"<<endl;
  }

}


//CHECK TOP TO BOTTOM
void TOP_BOTTOM( int i,int j,string n,char A[18][19],string Open){
int q=0;
int c=n.length( )-1;
int w=0;

  for(int k=i,l=0;k<n.length( );k++,l++){

    if(A[k][j]==n[l]){
        q++;
    }
  }
w=i+c;


  ofstream File_Open;
  File_Open.open(Open);

  if(q==n.length( )){
    cout<<"{"<<i<<","<<j<<"}{"<<w<<","<<j<<"}"<<endl;
    File_Open<<"{"<<i<<","<<j<<"}{"<<w<<","<<j<<"}"<<endl;
  }

}

//CHECK BOTTOM TO TOP
void Bottom_Top( int i,int j,string n,char A[18][19],string Open){
int q=0;
int x=0;
int l=0;
l=n.length( )-1;
x=i-l;

if(x<0){
    x=0;
}
  for(int k=i,l=0;k>=x;k--,l++){

    if(A[k][j]==n[l]){
        q++;
    }
  }


  ofstream File_Open;
  File_Open.open(Open);

  if(q==n.length( )){
     cout<<"{"<<i<<","<<j<<"}{"<<x<<","<<j<<"}"<<endl;
     File_Open<<"{"<<i<<","<<j<<"}{"<<x<<","<<j<<"}"<<endl;
  }

}

//CHECKING RIGHT DIAGONAL
void TOP_BOTTOM_Diagonal( int i,int j,string n,char A[18][19],string Open){

int q=0;
int r1=0;
int r2=0;
  for(int k=i,l=0,z=j;k<n.length( );k++,l++,z++){

    if(A[k][z]==n[l]){
        q++;
    }
    r1=k;
    r2=z;
  }

  ofstream File_Open;
  File_Open.open(Open);

  if(q==n.length( )){
     cout<<"{"<<i<<","<<j<<"}{"<<r1<<","<<r2<<"}"<<endl;
     File_Open<<"{"<<i<<","<<j<<"}{"<<r1<<","<<r2<<"}"<<endl;
  }


}

//CHECKING RIGHT DIAGONAL FROM BOTTOM
void Bottom_Top_Diagonal( int i,int j,string n,char A[18][19],string Open){
int q=0;
int x=0;
int l=0;
l=n.length( )-1;
x=i-l;
int r1=0;
int r2=0;

if(x<0){
    x=0;
}
  for(int k=i,l=0,z=j;k>=x;k--,l++,z--){

    if(A[k][z]==n[l]){
        q++;
    }
    r1=k;
    r2=z;
  }

  ofstream File_Open;
  File_Open.open(Open);

  if(q==n.length( )){
     cout<<"{"<<i<<","<<j<<"}{"<<r1<<","<<r2<<"}"<<endl;
     File_Open<<"{"<<i<<","<<j<<"}{"<<r1<<","<<r2<<"}"<<endl;
  }


}

//CHECKING LEFT DIAGONAL FROM TOP
void TOP_BOTTOM_Diagonal_Left( int i,int j,string n,char A[18][19],string Open){

int q=0;
int r1=0;
int r2=0;
  for(int k=i,l=0,z=j;k<n.length( );k++,l++,z--){

    if(A[k][z]==n[l]){
        q++;
    }
    r1=k;
    r2=z;
  }

  ofstream File_Open;
  File_Open.open(Open);

  if(q==n.length( )){
    cout<<"{"<<i<<","<<j<<"}{"<<r1<<","<<r2<<"}"<<endl;
    File_Open<<"{"<<i<<","<<j<<"}{"<<r1<<","<<r2<<"}"<<endl;
  }


}

//CHECKING LEFT DIAGONAL FROM BOTTOM
void Bottom_Top_Diagonal_Left( int i,int j,string n,char A[18][19],string Open){
int q=0;
int x=0;
int l=0;
l=n.length( )-1;
x=i-l;
int r1=0;
int r2=0;

if(x<0){
    x=0;
}
  for(int k=i,l=0,z=j;k>=x;k--,l++,z++){

    if(A[k][z]==n[l]){
        q++;
    }
    r1=k;
    r2=z;
  }


  ofstream File_Open;
  File_Open.open(Open);

  if(q==n.length( )){
    cout<<"{"<<i<<","<<j<<"}{"<<r1<<","<<r2<<"}"<<endl;
    File_Open<<"{"<<i<<","<<j<<"}{"<<r1<<","<<r2<<"}"<<endl;
  }


}

int main( ){

  //CREATING MENUE WHICH WOULD BE DISPLAYED TO THE USER

    cout<<"//************************************************|| MENUE ||*********************************************//"<<endl;
    cout<<"||                                                                                                        ||"<<endl;
    cout<<"|| 1. Create Grid(c).                                                                                     ||"<<endl;
    cout<<"|| 2. Search Words From Grid(S).                                                                          ||"<<endl;
    cout<<"|| 3. Quit(Q).                                                                                            ||"<<endl;
    cout<<"||                                                                                                        ||"<<endl;
    cout<<"//********************************************************************************************************//"<<endl;

// ASKING THE USER TO ENTER THE INPUT
cout<<" Enter the options : "<<endl;
char a;
cin>>a;
//APPLYING THE CONDITION THAT IF USER ENTERED WRONG INPUT THEN PRINT INVALID INPUT
if(a!='C'&&a!='c'&&a!='S'&&a!='s'&&a!='Q'&&a!='q'){

    cout<<" Invalid Option!!"<<endl;
}else{
//APPLYING THE CONDITION FOR TERMINAL OF LOOP UNTIL USER ENTER OR PRESS Q
while(a!='Q'&&a!='q'){
//IF USER ENTER OPTION C THEN CREATION OF GRID SHOULD BE FORMED
if(a=='c' || a=='C'){
//ASKING THE USER TO ENTER THE NAME OF FILE WHER INPUT IS STORED
    cout<<" Enter the name of file where input is stored : ";
    string k;
    cin>>k;
//ASKING THE USER TO ENTER THE NUMBER OF WORDS
    cout<<" Enter the numbers of words stored in file :  ";
    int n=0;
    cin>>n;
 //ASKING THE USER TO ENTER THE NUMBER OF ROWS
    cout<<" Enter the number of rows : ";
    int r=0;
    cin>>r;
  //ASKING THE USER TO ENTER THE NUMBER OF COLUMNS
    cout<<" Enter the number of coloumns : ";
    int c=0;
    cin>>c;
  //ASKING THE USER TO NAME THE OUTPUT GRID
    cout<<" Enter the name of output grid : ";
    string o;
    cin>>o;
  //DECLARING FUNCTION WHCH WAS CREATED FOR THE FORMATION OF GRID
    Create_Grid(r,c,n,k,o);
}
// IF USER ENTER S THEN WORD SEARCH SHOULD BE PERFORMED
if(a=='S' || a=='s'){
//ASKING THE USER TO ENTER THE NAME OF FILE WHERE GRID ID STORED
    cout<<" Enter the name of file : ";
    string File;
    cin>>File;
//CRAETING THE INPUT FILE TO READ THE WORDS FROM THE GRID
ifstream input(File);
//READING THE DATA FROM THE GRID
char A[18][19];
for(int i=0;i<18;i++){
  for(int j=0;j<19;j++){
    input>>A[i][j];
  }
}

//ASKING THE USER TO ENTER THE NAME OF FILE WHERE WORDS ARE STORED TO BE SEARCHED
 cout<<" Enter the name of file where words are stored : ";
 string words;
 cin>>words;
//ASKING THE USER TO ENTER THE NUMBER OF ROWS
 cout<<" Enter the number of rows : ";
 int rows=0;
 cin>>rows;
//ASKING THE USER TO ENTER THE NUMBER OF COLUMNS
 cout<<" Enter the number of coloumns : ";
 int coloumns;
 cin>>coloumns;
//CREATING THE STRING TO COLLECT THE WORDS FROM THE FILE
    string n[20];

    ifstream file(words);
//CRAETING THE LOOP TO INTAKE THE WORDS FROM THE FILE
    for(int i=0;i<20;i++){

        getline(file,n[i]);
    }

//ASKING THE USER TO ENTER THE NAME OF FILE WHERE OUTPUT SHOULD BE STORED
cout<<" Enter the file name where input should be stored : ";
string t;
cin>>t;
//PRINTING THE DESIRE INDEXES
cout<<" Indexes are as follows : "<<endl;

//CRAETING THE LOOP CONSIDERING ALL THE WORDS IN THE FILE
for(int we=0;we<20;we++){

  n[we];
//CREATING THE CHAR TYPE VARIABLE TO STORE THE FIRST ALPHABET OF THE WORD
char c;
string k;
k=n[we];

//STORING THE FIRST ALPHABET
c=n[we][0];
//CREATING LOOP TO TRANSFER THE INDEXES OF FIRST LETTER OF THE WORD IN FUNCTIONS
 for(int i=0;i<rows;i++){

    for(int j=0;j<coloumns;j++){

        if(A[i][j]==c){
//CALLING ALL THE CONDITION INORDER TO SEARCH THE WORD
     Left_Right(i,j,k,A,t);
     Right_Left(i,j,k,A,t);
     TOP_BOTTOM(i,j,k,A,t);
     Bottom_Top(i,j,k,A,t);
     TOP_BOTTOM_Diagonal(i,j,k,A,t);
     Bottom_Top_Diagonal(i,j,k,A,t);
     TOP_BOTTOM_Diagonal_Left(i,j,k,A,t);
     Bottom_Top_Diagonal_Left(i,j,k,A,t);

        }

}
    }

 }


}
//DECLAIRING THAT OPERATIPON IS ENDED AFTER PERFORMING EACH OPTION FROM THE MENUE
cout<<endl;
cout<<"********************************************|| OPERATION DONE ||**************************************************"<<endl<<endl;
//ASKING USER THE OPRION UNTIL USER ENTER Q INORDER TO TERMINATE THE FUNCTION
cout<<" Enter Your Option : ";
cin>>a;
}
}
}
