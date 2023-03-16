#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream plik("liczby.txt");
string liczba;
ofstream wynik("wynik4.txt");


int main()
{
    // Zadanie 4.1
    int ile_wiecej_zer = 0;

    while (getline(plik, liczba)) {

        int ilosc_zer = 0, ilosc_jedynek = 0;

        for (char c : liczba) {

            if (c == '0')
                ilosc_zer++;
            else
                ilosc_jedynek++;

        }

        if (ilosc_zer > ilosc_jedynek)
            ile_wiecej_zer++;

    }

    wynik << "4.1. " << ile_wiecej_zer << endl;
    plik.close();


    // Zadanie 4.2
    plik.open("liczby.txt");

    int ile_podzielnych_przez_2 = 0, ile_podzielnych_przez_8 = 0;

    while (getline(plik, liczba)) {

            if (liczba.back() == '0')
                ile_podzielnych_przez_2++;

            if (liczba.substr(liczba.length() - 3) == "000")
                ile_podzielnych_przez_8++;

    }

    wynik << "4.2. " << ile_podzielnych_przez_2 << " " << ile_podzielnych_przez_8 << endl;
    plik.close();


    // Zadanie 4.3

    plik.open("liczby.txt");
    int max_length=0, min_length=250;

    string min_string = "111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";
    string max_string = "0";

    int numer_najmniejszej = 1, numer_najwiekszej = 1, numer = 0;

    while (plik >> liczba) {

            numer++;

            if (liczba.length() >= max_length)
            {
                max_length = liczba.length();

                for(int i = 0; i < liczba.length(); i++)
                {
                    if( liczba[i] > max_string[i] )
                    {
                        max_string = liczba;
                        numer_najwiekszej = numer;
                        break;
                    }
                    if( max_string[i] > liczba[i] )
                    {
                        break;
                    }
                }
            }


            if( liczba.length() <= min_length)
            {
                min_length = liczba.length();
                // cout << " mint length: " << min_length << endl;

                for( int i = 1; i < liczba.length(); i++ )
                {
                    if (liczba[i] < min_string[i])
                    {
                        min_string = liczba;
                        numer_najmniejszej = numer;
                        break;
                    }
                    if (min_string[i] > liczba[i])
                        break;

                }
            }

    }


    // wypisujemy wyniki
    wynik << "4.3 " << endl;
    wynik << "   Najmniejsza liczba znajduje sie w wierszu nr: " << numer_najmniejszej << endl;
    wynik << "   Najwieksza liczba znajduje sie w wierszu nr: " << numer_najwiekszej << endl;
    wynik.close();

    plik.close();

    return 0;
}
