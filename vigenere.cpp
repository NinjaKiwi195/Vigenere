/* vigenere.cpp
   CSC 116 - Fall 2023 - Assignment 1

abcdefghijklmnopqrstuvwxyz
computerscience
pear

Alphabet: [abcdefghijklmnopqrstuvwxyz]

Message: [computerscience]

Key: [pear]

Encrypted: [rsmgjxeihgivcge]

Decrypted: [nkmyfpeadyinyye]


   You can use this template as the basis of your solution if you want, but you are 
   also free to start from scratch (although you must ensure that the formatting of your 
   solution is absolutely identical to the formatting specified in the assignment).

   Kevin Javanmardi - V00977230 - 2023-09-24
*/ 

#include <iostream>
#include <string>
#include <cctype>
#include <vector>

int letter_to_index (std::string alphabet, char l){
        
    for(unsigned int i {}; i < alphabet.size(); i++){
        if(alphabet.at(i)==l){
            return i;
        }
    }
    return 99999;
}

char index_to_letter (std::string alphabet, int result){
        
    for(unsigned int i {}; i < alphabet.size() ; i++){
        if( (int)i == (int)result ){
            return alphabet.at(i);
        }
     }
    return 'X';
}

void PrintVector(std::vector<int> V){
    for(int x : V){
        std::cout << x << " ";
    }
    std::cout<< std::endl;
}


int main(){
    std::string alphabet {};
    std::string message {};
    std::string key {};
    std::string key_repeated {};
    std::string result {};
    std::string decrypted_result {};
    
    std::vector<int> alphabet_index {};
    std::vector<int> result_index {};
    
    //Read each of the alphabet, message and key (in that order).
    std::getline(std::cin, alphabet);
    std::getline(std::cin, message);
    std::getline(std::cin, key);   
    
    //Now print out the three input strings in the format specified in the assignment
    std::cout << "Alphabet: [" << alphabet << "]" << std::endl;
    std::cout << "Message: [" << message << "]" << std::endl;
    std::cout << "Key: [" << key << "]" << std::endl;
    
    std::string encrypted {};
    std::string decrypted {};

    /* Put your solution here, using the strings above to store the encrypted and decrypted results */

        //Indexes alphabet
    for(unsigned int i {}; i < alphabet.length(); i++){
        alphabet_index.push_back(i);
    }
    
        //Resize reapeat_key to lenght of messege by repeating the key
    for(unsigned int i {}; i < message.size(); i++){
        key_repeated.push_back(key.at(i%(key.size())));
    }
    
        //Encription
    for(unsigned int i {0}; i < message.size(); i++){
        
        result.push_back(index_to_letter(alphabet,(letter_to_index(alphabet, message.at(i))+letter_to_index(alphabet, key_repeated.at(i))) % alphabet.length()));
    }
     
        //Decription 
    for(unsigned int i {0}; i < message.size(); i++){ 
        
        int sum {letter_to_index(alphabet, message.at(i)) - letter_to_index(alphabet, key_repeated.at(i))};
        if(sum < 0 ){
            sum = sum + alphabet.size();
            decrypted_result.push_back(index_to_letter(alphabet,sum));
        }else{
            decrypted_result.push_back(index_to_letter(alphabet,sum));
        }                                                          
    }
       
    encrypted = result;
    decrypted = decrypted_result;

    /* Once both results have been computed, print them out in the format specified in the assignment */
    std::cout << "Encrypted: [" << encrypted << "]" << std::endl;
    std::cout << "Decrypted: [" << decrypted << "]" << std::endl;
    
    return 0;
}