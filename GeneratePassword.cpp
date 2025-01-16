#include <iostream> 
#include <cstdlib>  // for the rand() function  
#include <ctime>
#include <string> 
using namespace std;
string getpassword(int _lenght){
    string _password="";
    string characters="aquickbrownfoxjumpsoveralazydogAQUICKBROWNFOXJUMPSOVERTHELAZYDOG123456789";
    int charsize=characters.size();
    srand(time(0));   
    int random_index;
     for (int i=0; i < _lenght; i++){
        random_index=rand()%charsize;
        _password=_password + characters[random_index];
    }
    return _password;
}
int main(){
     int lenght;
  cout<<"Enter the lenght of the Password :: ";
  cin>>lenght;
  string password = getpassword(lenght);
  cout<<"Generated Password :: "<<password;
 return 0;
}

