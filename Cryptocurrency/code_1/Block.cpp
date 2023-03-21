#include<iostream>
#include <sstream>
#include <cstdlib>


#include "Transaction.hpp"
#include "Block.hpp"
#include "sha256.hpp"

using namespace std;

Block::Block(vector<Transaction> _transactions, time_t _timestamp, string _previousHash) {
    nonce = -1;
    transactions = _transactions;
    previousHash = _previousHash;
    timestamp = _timestamp;
    hash = calculateHash();
}

void Block::setPreviousHash(string _previousHash) {
    // TODO
    previousHash = _previousHash;
    return;
}

string Block::calculateHash() {
    // TODO
    stringstream inputStream;
    inputStream << "[ ";

    for (int i = 0; i < transactions.size(); i++)
    {
        inputStream << transactions[i].toString();
        i++;
    }

    inputStream << " ]";

    inputStream << to_string(nonce);

    inputStream << to_string(timestamp);

    inputStream << previousHash;
    inputStream << hash;

    string shaHash = sha256(inputStream.str());
    return shaHash;   
}

void Block::mineBlock(unsigned int difficulty) {
    // TODO
    bool minable = false;

    while (minable != true)
    {
        minable = true;
        nonce = rand();
        string mineString = calculateHash();

        for (int i = 0; i < difficulty; i++)
        {
            if (mineString.at(i) != '0')
            {
                minable = false;
                break;
            }
        }
    }
    return;    
}

string Block::toString() {
    // TODO
    string printString = "Nonce: " + to_string(nonce) + " Previous Hash: " + previousHash + " Time Stamp: " + to_string(timestamp) + " Hash:" + hash;
    string transString;

    for (int i = 0; i < transactions.size(); i++)
    {
        transString = transString + " " + transactions[i].toString();
    }

    printString = printString + " Transactions: " + transString;
    
    return printString;
}

string Block::getPreviousHash()
{
    return previousHash;
}

Transaction Block::getTransation(int index)
{
    return transactions[index];
}

int Block::transactionSize()
{
    return transactions.size();
}