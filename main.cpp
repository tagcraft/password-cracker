#include <iostream>
#include <iomanip>
#include <sstream>
#include <openssl/md5.h>
#include <string>
#include <vector>
#include<fstream>
#include<unordered_map>

using namespace std;

string md5(const string &input) {
    unsigned char digest[MD5_DIGEST_LENGTH];
    MD5((unsigned char*)input.c_str(), input.size(), digest);

    stringstream ss;
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        ss << hex << setw(2) << setfill('0') << (int)digest[i];
    }
    return ss.str();
}

bool rainbowTableAttack(const string &targetHash, const string &filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Rainbow table file not found.\n";
        return false;
    }

    unordered_map<string, string> table;
    string password, hash;

    while (file >> password >> hash) {
        table[hash] = password;
    }

    if (table.find(targetHash) != table.end()) {
        cout << "Password cracked using rainbow table: "
             << table[targetHash] << endl;
        return true;
    }

    return false;
}


void generateRainbowTable(const string &wordlist, const string &outputFile) {
    ifstream in(wordlist);
    ofstream out(outputFile);

    if (!in || !out) {
        cout << "File error.\n";
        return;
    }

    string word;
    while (in >> word) {
        out << word << " " << md5(word) << endl;
    }

    cout << "Rainbow table generated successfully.\n";
}

bool bruteForce(const string &targetHash) {
    string charset = "abcdefghijklmnopqrstuvwxyz0123456789";
    string attempt;

    for (int len = 1; len <= 5; len++) {
        vector<int> index(len, 0);

        while (true) {
            attempt.clear();
            for (int i = 0; i < len; i++)
                attempt += charset[index[i]];

            if (md5(attempt) == targetHash) {
                cout << "Password cracked: " << attempt << endl;
                return true;
            }

            int pos = len - 1;
            while (pos >= 0) {
                index[pos]++;
                if (index[pos] < charset.size())
                    break;
                index[pos] = 0;
                pos--;
            }
            if (pos < 0)
                break;
        }
    }
    return false;
}

bool dictionaryAttack(const string &targetHash, const string &filename) {
    ifstream file(filename);
    if (!file) return false;

    string word;
    while (file >> word) {
        if (md5(word) == targetHash) {
            cout << "Password cracked: " << word << endl;
            return true;
        }
    }
    return false;
}


int main() {
    string targetHash;
    int choice;

    cout << "Enter MD5 hash: ";
    cin >> targetHash;

    cout << "\nChoose attack method:\n";
    cout << "1. Brute Force\n";
    cout << "2. Dictionary Attack\n";
    cout << "3. Generate Rainbow Table\n";
    cout << "4. Rainbow Table Attack\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
        if (!bruteForce(targetHash)) {
            cout << "Password not found using brute force.\n";
        }
    }
    else if (choice == 2) {
        if (!dictionaryAttack(targetHash, "wordlist.txt")) {
            cout << "Password not found in dictionary.\n";
        }
    }
    else if (choice == 3) {
        generateRainbowTable("wordlist.txt", "rainbow.txt");    
    }
    else if (choice == 4) {
        if (!rainbowTableAttack(targetHash, "rainbow.txt")) {
            cout << "Password not found in rainbow table.\n";
         }
    }

    else {
        cout << "Invalid choice.\n";
    }

    return 0;
}
