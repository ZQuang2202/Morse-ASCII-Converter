# Internation morse code
![image](https://github.com/ZQuang2202/Morse-ASCII-Converter/assets/152836329/8499a765-fe11-41e4-be91-6e1bf00761a2)

Converting an ASCII file to a Morse code file is easy. The problem is to convert the Morse code file to an ASCII file in the fastest way and require a minimum of memory. The idea is to utilize the binary representation/integer of the Morse character. This is simpler and faster than lookup using a string representation. Here is the binary tree of the Morse characters. The data structure that contains Morse code and its ASCII character and its binary representation is built in [this file](https://github.com/ZQuang2202/Morse-ASCII-Converter/blob/main/data.h).
![image](https://github.com/ZQuang2202/Morse-ASCII-Converter/assets/152836329/92714e26-e90d-4272-9de2-aa436f1e790a)

# How to compile 
```sh
gcc morse.c -o morse.exe
```
# How to use
```sh
morse <input text file> <output text file>
```

# Please raise a 🌟 if you find it interesting. 

