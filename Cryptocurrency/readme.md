# Cryptocurrency, C++

Catherine Xie

This set of files simulates the transfer of cryptocurrency units from person to person, called "BTC".
In this project my goal was to: 
 * Become more familiar with data structures in C++, primarily the usage of linked lists.
 
 * Familiarized myself to features within cryptocurrency, such as the blocks in the blockchain.

This program transfers cryptocurrency units from person to person, called "BTC". A user will 
start with a wallet with however much BTC, and can transfer payments to other users. Other
users may also transfer money to a user, but if there is insufficient BTC in one's wallet --
meaning one does not have enough funds -- then an error message will be displayed and the 
payment will not go through. 

Each payment has the information of previous senders tied with it, to ensure that there can be no counterfeiting. A single payment is called a "block" and the line of previous payments before it is called the "blockchain". A user may also view the information of each payment they receives or send.

 * `app_1:` Contains the `main_1.cpp` file, which is responsible for tying all the files together and executing them seamlessly.

 * `build:` Contains the auto-grader files. This is not integral to the execuation of the other files.
 
 * `code_1:` Contains integral files, an assortment of .cpp and .hpp files which are tied in the `main_1.cpp` file. These files 
             transfers "BTC" from one user to another. 
 
 * `tests:` Contains additional testing of the files. 
