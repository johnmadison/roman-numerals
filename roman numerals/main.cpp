#include <iomanip>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    ifstream inf;
    inf.open("input.txt");
    ofstream outf;
    outf.open("output.txt");
    
    int j;
    j = 0;
    outf << setw(21) <<left << "ROMAN"<<setw(9)<<right<< "DECIMAL"<<endl;
    outf << setw(21) <<left << "NUMERAL"<<setw(9)<<right<<"NUMERAL"<<endl;
    outf << "******************************"<<endl;
    while (!inf.eof())
    {
        string roman;
        int decimal;
        getline(inf, roman);
        int romsize = 0;
        romsize = roman.length();
        decimal = 0;
        
        for (int i = 0; i < romsize; i++)
        {
            if (roman[i] == 'M') decimal += 1000;
        
            else if (roman[i] == 'D')
            {
                if (roman[i+1] == 'M')
                    decimal -= 500;
                else
                    decimal += 500;
            }
		
            else if (roman[i] ==  'C')
            {
                if (roman[i+1] == 'M' ||
                    roman[i+1] == 'D')
                    decimal -= 100;
                else
                    decimal += 100;
            }
        
            else if (roman[i] ==  'L')
            {
                if (roman[i+1] == 'M' ||
                    roman[i+1] == 'D' ||
                    roman[i+1] == 'C' )
                    decimal -= 50;
                else
                    decimal += 50;
            }
        
            else if (roman[i] ==  'X')
            {
                if (roman[i+1] == 'M' ||
                    roman[i+1] == 'D' ||
                    roman[i+1] == 'C' ||
                    roman[i+1] == 'L' )
                    decimal -= 10;
                else
                    decimal += 10;
            }
            else if (roman[i] ==  'V')
            {
                if (roman[i+1] == 'M' ||
                    roman[i+1] == 'D' ||
                    roman[i+1] == 'C' ||
                    roman[i+1] == 'L' ||
                    roman[i+1] == 'X')
                    decimal -= 5;
                else
                    decimal += 5;
            }
            else if (roman[i] ==  'I')
            {
				if (roman[i+1] == 'M' ||
                    roman[i+1] == 'D' ||
                    roman[i+1] == 'C' ||
                    roman[i+1] == 'L' ||
                    roman[i+1] == 'X' ||
                    roman[i+1] == 'V' )
					decimal-=1;
                else
					decimal++;
            }
            else
                decimal += 0;
    }
        outf <<setw(19)<<left<< roman << " = " <<setw(8)<< right << decimal << endl;
    }
    return 0;
}

