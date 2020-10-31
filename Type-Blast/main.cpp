#include <iostream>
#include <ctime>
#include <string>


using namespace std;

void num_attr(string sentence,string user,int *arr);


int main()
{

  string sentence,user;

  int arr[4];

  clock_t time_req;

  cout << "I am going to calculate the number of words per minute you can accomplish\n";

  cout << "Please enter the text you want to type:\n";

  getline(cin, sentence);

  cout<<endl<<endl<<"When you are ready press enter and start typing....";

  cin.get();

  time_req = clock();

  getline(cin, user);

  time_req = clock() - time_req;


  num_attr(sentence,user,arr);

  cout << "WPM      :" << 60000*arr[3]/time_req<<endl;

  cout << "ACCURACY :" << 100*arr[2]/arr[0];

  return 0;
}

void num_attr(string sentence,string user,int *arr)
{
  int words = 0,corr_words=0,chars = 0,corr_chars=0,check =0,temp=0;

 while(sentence[chars]!='\0')
{

    if(sentence[chars]==user[chars])
    {
        corr_chars++;
        check++;//this and temp together finds the correct number of words typed
    }
    temp++;
    if(sentence[chars]==' '||sentence[chars+1]=='\0')
    {

        words++;

        if(check == temp)
        {
            corr_words++;
        }
        check = temp =0;
    }
    chars++;

}

arr[0] = chars;
arr[1] = words;
arr[2] = corr_chars;
arr[3] = corr_words;

}