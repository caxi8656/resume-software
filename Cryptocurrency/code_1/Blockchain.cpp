#include<iostream>
#include <sstream>

#include "Transaction.hpp"
#include "Block.hpp"
#include "Blockchain.hpp"
#include<vector>

using namespace std;

Blockchain::Blockchain() {
    Transaction genesis("BFC","BFC",0);
    pending.push_back(genesis);

    Block gBlock(pending, time(nullptr), "In the beginning..");
    chain.push_back(gBlock);

    Transaction freeMoney("BFC","make money by mining",0);
    pending.push_back(freeMoney);

    difficulty = 4;
    miningReward = 10;
}

Block Blockchain::getLatestBlock() { 
    return chain.back();
}

void Blockchain::addTransaction(string src, string dst, int coins) {
    // TODO
    int balance = getBalanceOfAddress(src);

    if (balance > coins)
    {
        Transaction addTrans(src, dst, coins);
        pending.push_back(addTrans);
    }
    else
    {
        cout << "Error! Your balance is not enough!" << endl;
    }
    return;
}

bool Blockchain::isChainValid() { 
    // TODO
    int i = 0;
    bool valid = true;

    if (chain.size() <= 1)
    {
        return true;
    }

    if (chain[i + 1].getPreviousHash() != chain[i].calculateHash())
    {
        return false;
    }

    for (int m = 1; m < chain.size(); m++)
    {
        string hashString = chain[m].calculateHash();
        
        valid = true;

        for (int n = 0; n < difficulty; n++)
        {
            if (hashString.at(n) != '0')
            {
                valid = false;
                break;
            }
        }
        if (!valid)
        {
            return false;
        }
    }

    while (chain[i + 1].getPreviousHash() == chain[i].calculateHash() && valid == true)
    {
        i++;

        if (i == chain.size() - 1)
        {
            break;
        }

        if (chain[i + 1].getPreviousHash() != chain[i].calculateHash())
        {
            valid = false;
            break;
        }
    }

    return valid;
}

bool Blockchain::minePendingTransactions(string minerAddress) {
    // TODO
    
    Block newBlock(pending, time(nullptr), chain.back().calculateHash());
    newBlock.mineBlock(difficulty);

    int i = 0;
    pending.erase(pending.begin(), pending.end());

    chain.push_back(newBlock);

    Transaction reward("BFC", minerAddress, miningReward);
    return true;
}

int Blockchain::getBalanceOfAddress(string address) {
    // TODO
    int balance = 0;

    for (int i = 0; i < chain.size(); i++)
    {
        for (int p = 0; p < chain[i].transactionSize(); p++)
        {
            string sent = chain[i].getTransation(p).getSender();
            string receive = chain[i].getTransation(p).getReceiver();
            int sentAmount = chain[i].getTransation(p).getAmount();

            if (address == sent)
            {   
                balance = balance - sentAmount;
            }
            if (address == receive)
            {
                balance = balance + sentAmount;
            }
        }
    }
    return balance;
}

void Blockchain::prettyPrint() {
    // TODO
    for (int i = 1; i < chain.size(); i++)
    {
        string print = chain[i].toString();
        cout << print << endl;
    }
    return;
}