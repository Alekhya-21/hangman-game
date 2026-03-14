#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
  cout<<"Welcome to Hangman!"<<endl;
  vector<string> words={"apple","banana","mango","orange"};
  srand(time(0));
  string secret_word=words[rand()%words.size()];
  int tries=6;
  vector<char> guessed_letters;
  while(tries>0){
      string display="";
      for(char i:secret_word){
          if(find(guessed_letters.begin(),guessed_letters.end(),i)!=guessed_letters.end()){
              display+=i;
          }
          else{
              display+=" _";
          }
      }
      cout<<"word :"<<display<<endl;
      // check win
      if(display.find('_')==string::npos){
          cout<<"You guessed the word!"<<endl;
          return 0;
      }
      cout<<"Guess a letter :";
      char letter;
      cin>>letter;
      
      // check if the letter is already existed
      if(find(guessed_letters.begin(),guessed_letters.end(),letter)!=guessed_letters.end()){
          cout<<"letter is already guessed."<<endl;
      }
      guessed_letters.push_back(letter);
      // check if the guessed the wrong letter
      if(secret_word.find(letter)==-1){
          tries--;
          cout<<"wrong guess, tries left :"<<tries<<endl;
      }
  }
  cout<<"You lost, the word was :"<<secret_word<<endl;
}

