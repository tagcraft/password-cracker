# 🔐 Password Cracker in C++

📌 Project Overview

This project is a password cracking tool implemented in C++ to demonstrate how insecure password storage mechanisms can be exploited.
It is inspired by tools like John the Ripper and CrackStation and is built purely for educational purposes.

The project helps understand:
✔ How password hashing works

✔ Why weak hashing algorithms like MD5 are insecure

✔ How attackers crack passwords using different techniques

✔ Why modern systems use salting and slow hashes


⚙️ Features Implemented

✔ MD5 Hashing

✔ Brute Force Attack

✔ Dictionary (Wordlist) Attack

✔ Rainbow Table Generation

✔ Rainbow Table Based Password Cracking


🛠️ Technologies Used

✔ Language: C++

✔ Hashing Algorithm: MD5 (via OpenSSL)

✔ Compiler: g++

✔ Platform: Linux (GitHub Codespaces / Ubuntu)


🔎 Attack Methods Explained

🔸 Brute Force Attack

✔ Tries all possible character combinations up to a fixed length

✔ Guaranteed success for short passwords

✔ Very slow for longer passwords

🔸 Dictionary Attack

✔ Uses a wordlist of commonly used passwords

✔ Much faster than brute force

✔ Relies on human password patterns

🔸 Rainbow Table Attack

✔ Precomputes hashes and stores them in a file

✔ Cracks passwords instantly using hash lookup

✔ Demonstrates why unsalted hashes are insecure


🎓 Learning Outcomes

✔ Understanding password hashing

✔ Difference between brute force and optimized attacks

✔ File handling in C++

✔ Hash maps for fast lookups

✔ Real-world cybersecurity concepts


📜 Disclaimer

This project is created strictly for educational purposes.

The author is not responsible for misuse of this software.


👩‍💻 Author

Nitya Saluja

B.Tech CSE Student

Password Cracker Project (C++)
