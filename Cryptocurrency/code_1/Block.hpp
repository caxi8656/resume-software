#pragma once
#include<iostream>
#include <vector>
#include "Transaction.hpp"

using namespace std;

class Block {
private:
    long long nonce; // An arbitrary number crucial in mining
    vector<Transaction> transactions; //vector of transactions 
    string previousHash; // Hash of previous block
    time_t timestamp; // Time when mined 
    string hash; // Hash of this block
    
public:
    Block(vector<Transaction> _transactions, time_t _timestamp, string _previousHash);
    void setPreviousHash(string hash);
    string calculateHash();

    Transaction getTransation(int index);
    string getPreviousHash(); // made this myself, talk to TA
    int transactionSize();

    void mineBlock(unsigned int nDifficulty);
    string toString();
};

