#include <iostream>
#include <random>
#include <chrono>



using namespace std;

char gen_random_char(){
    std::random_device rd;
    std::mt19937 gen(rd());

    // Define the two ranges
    std::vector<int> valid_values;
    for (int i = 65; i <= 90; ++i) {
        valid_values.push_back(i);
    }
    for (int i = 97; i <= 122; ++i) {
        valid_values.push_back(i);
    }

    // Create a uniform integer distribution based on the valid_values indices
    std::uniform_int_distribution<> dist(0, valid_values.size() - 1);

    // Generate a random value from the combined range
    int randint = valid_values[dist(gen)];


    return char(randint);
}

int main() {

    string input;
    
    cout<<"Enter Input: ";
    cin>>input;

    // Get the start time
    auto start = std::chrono::high_resolution_clock::now();

    long long counter = 0;
    int length_of_input = input.length();
    bool flag = true;
    string generated_string;

    while(flag == true){
        char randchar = gen_random_char();
        cout<<randchar;
        
        
        generated_string += randchar;
        counter++;
        
        // If the generated_string is longer than input, keep only the last characters
        // equal to the length of input
        if (generated_string.length() > length_of_input) {
            generated_string = generated_string.substr(generated_string.length() - length_of_input);
        }

        // Check if the generated string matches the input
        if (generated_string == input) {
            cout << "\nMatch found!" << endl;
            cout << counter << " characters printed until match was found."<<endl;
            flag = false;

            // Get the end time
            auto end = std::chrono::high_resolution_clock::now();
            // Calculate duration in milliseconds
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

            std::cout << "Time taken: " << duration.count() << " milliseconds" << std::endl;

            }


        }
    float average_word_length = 5.1;
    float words_typed = counter / average_word_length;

    int wpm = 200;

    float minutes = words_typed / wpm;

    cout << "The average English word is 5.1 letters long. If a monkey randomly typed at 200 wpm it would have taken them "<<minutes<<" minutes" << endl;

    if(minutes >= 60){
        float hours = minutes / 60;
        cout<<"or "<<hours<<" hours"<<endl;
        if(hours >= 24){
            float days = hours / 24;
            cout<<"or "<<days<<" days"<<endl;
            if(days >= 365){
                float years = days / 365;
                cout<<"or "<<years<<" years"<<endl;
                if(years > 33){
                    float monkey_lifetimes = years / 33;
                    cout<<"or "<<monkey_lifetimes<<" average chimpanzee lifetimes"<<endl;
                }
            }
        }   
    }
    
}