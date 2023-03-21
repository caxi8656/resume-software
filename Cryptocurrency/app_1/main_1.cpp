#include <iostream>
#include <fstream>
#include "../code_1/Blockchain.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    Blockchain buffCUoin;

    buffCUoin.prettyPrint(); 

    cout << "User A mines the first coins ... " << endl;
    buffCUoin.minePendingTransactions("User A");
    buffCUoin.prettyPrint(); 
    
    cout << "User A gives 1 coin to User B ... " << endl;
    buffCUoin.addTransaction("User A","User B", 1);

    cout << "User B gives 1 coin to User C ... " << endl;
    buffCUoin.addTransaction("User B","User C", 1);
    //cout << "asa mining second block ... " << endl;
    buffCUoin.minePendingTransactions("User B");
    buffCUoin.prettyPrint(); 
    
    /*
    cout << "asa paid ashutosh 1 BFC ... " << endl;
    buffCUoin.addTransaction("asa","ashutosh", 1);    
    cout << "ashutosh paid maciej 2 BFC ... " << endl;
    buffCUoin.addTransaction("asa","maciej", 2);
    */

    cout << "User C mines ... " << endl;
    buffCUoin.minePendingTransactions("User C");
    buffCUoin.prettyPrint(); 

    cout << "User B gives 1 coin to User A ... " << endl;
    buffCUoin.addTransaction("User B","User A", 1);
    //cout << "asa mining second block ... " << endl;
    buffCUoin.minePendingTransactions("User B");
    
    buffCUoin.prettyPrint(); 
    
    /*
    cout << "ashutosh mining fourth block ... " << endl;
    buffCUoin.minePendingTransactions("ashutosh");
    buffCUoin.prettyPrint();
    */
    
    return 0;
}