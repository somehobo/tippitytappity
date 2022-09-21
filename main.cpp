#include <iostream>
#include <chrono>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){
    const string phrase = "The quick brown fox jumps over the lazy dog";
    string input;
    std::chrono::steady_clock::time_point started; 
    std::chrono::steady_clock::time_point stopped;
    long milliseconds = 0;

    do{
        cout << "Type the following phrase and then press return:\n" 
            << phrase << endl;
        started = std::chrono::steady_clock::now(); // start timer
        getline(cin,input);
        stopped = std::chrono::steady_clock::now(); // stop timer
        milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(stopped - started).count();
        
        //TODO: Show results here
        cout << "You took " << milliseconds / 1000.0 << " seconds" << endl;
        int score = (phrase.size() - input.size())*-2;

        
        for(int i = 0; i < phrase.size(); i++){
            if (!input[i]) {
                break;
            }
            if (phrase[i] == input[i]){
                score++;
            } else {
                score--;
            }
        }

        cout<<score<<endl;
        cout<<phrase.size()<<endl;

        double result = (score / phrase.size());

        cout << "Results: "<<result<<"% Accurate"<<endl;

        do{
            cout << "Try again? (yes/no)\n";
            getline(cin,input);
        }while( input != "yes" && input != "no" );
    }while( input == "yes" );

    return 0;
}