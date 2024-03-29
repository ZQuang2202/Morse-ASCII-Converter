
/* Nguyen Van Quang . MSSV: 20190026. Lop: CTTN - Dieu Khien Tu Dong K64 */

enum type {TEXT, MORSE};

typedef struct MORSE_TABLE
{
    char *morse;
    char ascii;
    int  binary;
}MORSE_TABLE;

#define ARRAY_SIZE 42    /// size of Morse table

MORSE_TABLE table[] = {
    {".-"   ,'A',0b110  },
    {"-..." ,'B',0b10001},
    {"-.-." ,'C',0b10101},
    {"-.."  ,'D',0b1001 },
    {"."    ,'E',0b10   },
    {"..-." ,'F',0b10100},
    {"--."  ,'G',0b1011 },
    {"...." ,'H',0b10000},
    {".."   ,'I',0b100  },
    {".---" ,'J',0b11110},
    {"-.-"  ,'K',0b1101 },
    {".-.." ,'L',0b10010},
    {"--"   ,'M',0b111  },
    {"-."   ,'N',0b101  },
    {"---"  ,'O',0b1111 },
    {".--." ,'P',0b10110},
    {"--.-" ,'Q',0b11011},
    {".-."  ,'R',0b1010 },
    {"..."  ,'S',0b1000 },
    {"-"    ,'T',0b11   },
    {"..-"  ,'U',0b1100 },
    {"...-" ,'V',0b11000},
    {".--"  ,'W',0b1110 },
    {"-..-" ,'X',0b11001},
    {"-.--" ,'Y',0b11101},
    {"--.." ,'Z',0b10011},
    {".----",'1',0b111110},
    {"..---",'2',0b111100},
    {"...--",'3',0b111000},
    {"....-",'4',0b110000},
    {".....",'5',0b100000},
    {"-....",'6',0b100001},
    {"--...",'7',0b100011},
    {"---..",'8',0b100111},
    {"----.",'9',0b101111},
    {"-----",'0',0b111111},
    {"..--..",'?',0b1001100},
    {".-.-.-",'.',0b1101010},
    {"--..--",',',0b1110011},
    {"-.-.-.",';',0b1010101},
    {"---...",':',0b1000111},
    {"-....-",'-',0b1100001},
    {"........",'#',0b100000000}
};
