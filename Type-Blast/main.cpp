#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>

using namespace std;

int high_wpm=0,goal=0,plays=0,total_wpm=0;
float total_acc=0,high_acc;

void num_attr(string sentence,string user,int *arr);

int main()
{

  string sentence,user;

  int arr[4],choice,run=1;

  cout <<"          Type Blast      \n";
  cout <<"          -----------     \n";
  cout << "Your typing speed calculator!\n\n";

  while(run)
    {
        cout<<"1.Test your typing speed with default text\n";
        cout<<"2.Test your typing speed with custom text\n";
        cout<<"3.Show highscores and average speed\n";
        cout<<"4.Set speed goals\n";
        cout<<"5.End the program\n";

        cin >> choice;

        cout<<"\n";

        if(choice == 1)
        {
            clock_t time_req;

            cout << "Please enter the text given below:\n";

            sentence = "By typing this text you can determine your WPM";

            cin.get();

            cout<<"\n"<<sentence<<"\n";

            cout<<"\nWhen you are ready press enter and start typing....";

            cin.get();

            time_req = clock();

            getline(cin, user);

            time_req = clock() - time_req;

            num_attr(sentence,user,arr);

            int wpm = 60000*arr[3]/time_req;

            float acc = (float)100*arr[2]/arr[0];

            cout <<"\nWPM      :" << wpm << endl;

            cout <<"ACCURACY :"<<fixed<<setprecision(2)<<acc<< endl;

            total_wpm+=wpm;
            total_acc+=acc;

            plays++;

            if(wpm>high_wpm)
            {
                high_wpm = wpm;
                high_acc = acc;

                cout<<"\nCongratulations this is your new highscore....\n";
            }
            if(wpm>=goal&&goal!=0)
            {
                  cout<<"\nCongratulations you have achieved your goal of "<<goal << " wpm\n";
                  cout<<"Do you want to set a new goal?<y/n>\n";

                  char x;

                  if(x=='y'||x=='Y')
                  {
                      cout<<"Enter your new goal\n";
                      cin >> goal;
                  }

            }
        }
        else if(choice == 2)
        {
            clock_t time_req;

            cout << "Please enter the text you want to type:\n\n";

            cin.get();

            getline(cin, sentence);

            cout<<"\nWhen you are ready press enter and start typing....";

            cin.get();

            time_req = clock();

            getline(cin, user);

            time_req = clock() - time_req;

            num_attr(sentence,user,arr);

            int wpm = 60000*arr[3]/time_req;

            float acc = (float)100*arr[2]/arr[0];

            cout <<"\nWPM      :" << wpm << endl;

            cout <<"ACCURACY :" <<fixed<<setprecision(2)<<acc << endl;

            if(wpm>high_wpm)
            {
                high_wpm = wpm;
                high_acc = acc;

                cout<<"\nCongratulations this is your new highscore....\n";
            }
            if(wpm>=goal&&goal!=0)
            {
                  cout<<"\nCongratulations you have achieved your goal of "<<goal << " wpm\n";
                  cout<<"Do you want to set a new goal?<y/n>\n";

                  char x;

                  if(x=='y'||x=='Y')
                  {
                      cout<<"Enter your new goal\n";
                      cin >> goal;
                  }

            }
        }
        else if(choice == 3)
        {
            int avg_wpm = total_wpm/plays;
            float avg_acc = (float)total_acc/plays;

            cout<<"Highscore: "<<high_wpm <<" wpm with "<<high_acc<<" accuracy!\n"; 
            cout <<"Average: "<<avg_wpm <<" wpm with "<<fixed<<setprecision(2)<<avg_acc<<" accuracy\n";
        }
        else if(choice == 4)
        {
            cout<< "Enter your goal:\n";

            cin >> goal;

            cout<<"Your new goal is set to "<<goal << " wpm\n";
        }
        else if(choice == 5)
        {
            cout <<"\nThank you for using Type Blast...\n";
            run = 0;
        }
        else
            cout<<"\nEnter a valid number from the menu....\n";

        cout<< "\n";

    }


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
