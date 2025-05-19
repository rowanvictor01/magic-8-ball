#include <iostream>
#include <limits>

using namespace std;

void choices(int fortune)
{
    switch(fortune)
    {
        case 0: cout << "\nYes, Most definitely!" << endl; break;
        case 1: cout << "\nNah..." << endl; break;
        case 2: cout << "\nCall me MAYBE" << endl; break;
        case 3: cout << "\nDon't know, Don't care." << endl; break;
        case 4: cout << "\nThe stars says yes, but I say NO!" << endl; break;
        case 5: cout << "\nI don't know. I'll ask Google." << endl; break;
        default: cout << "\nListen to what your gut tells you." << endl; break;
    }
}


int replyCheck(string r)
{
    while((r != "Yes" && r != "yes") && (r != "No" && r != "no"))
    {
        return 1;
    }

    if(r == "Yes" || r == "yes")
    {
        return 2;
    }
    else
    {
        return 3;
    }
}

void clear_buffer()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


int main()
{
    srand(time(NULL));
    bool programRepeat = true;

    cout << "Hi, Welcome to the Magic 8 Ball program. Just type a question to and get an answer. (Make sure to type in a question mark :)" << endl;

    do
    {
        string response;
        getline(cin, response);
        
        bool check_question = !response.empty() && response.back() == '?';
        bool has_letter = false;
        for (char c : response)
        {
            if(isalpha(static_cast<unsigned char>(c)))
            {
                has_letter = true;
                break;
            }
        }
        // code above and below getline() is to check if there's a question mark at the end and if atleast one letter and not just numbers is in the sentence
        while(!check_question || !has_letter)
        {
            cout << "Did not enter a valid question. Please try again." << endl;
            getline(cin, response);
            check_question = !response.empty() && response.back() == '?';
            has_letter = false;
            for(char c : response)
            {
                if(isalpha(static_cast<unsigned char>(c)))
                {
                    has_letter = true;
                    break;
                }
            }
        }


        choices(rand() % 6);

        cout << "\nThankyou for using the program. Would like to ask another question?" << endl;

        string tryAgain;
        cin >> tryAgain;
        clear_buffer();
        int rC;
        rC = replyCheck(tryAgain);

        while(rC == 1) 
        {
            cout << "\nInvalid reply. Please confirm with yes or no only." << endl;
            cin >> tryAgain;
            rC = replyCheck(tryAgain);
            clear_buffer();
        }
        if(rC == 2)
        {
            cout << "Aight, What's your next question?\n>> " << flush;
            programRepeat = true;
        }
        else if(rC == 3)
        {
            cout << "Have a great day." << endl;
            programRepeat = false;
        }
    } while(programRepeat);

    return 0;
}