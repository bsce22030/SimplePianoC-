#include <Windows.h>
#include <iostream>
#include <fstream>

using namespace std;

class Chord;
class Note;

class Note
{
public:
    int A,B,C,D,E,F,G;
    Note()
    {
        A=440;
        B=494;
        C=262;
        D=294;
        E=330;
        F=349;
        G=392;
    }
    virtual void play()
    {
        char note;
        cout<<"Enter notes to play: \n";
        cin >> note;
        do{
        switch (note) {
                case 'A':
                case 'a':
                    Beep(A,300);
                    break;
                case 'B':
                case 'b':
                    Beep(B,300);
                    break;
                case 'C':
                case 'c':
                    Beep(C,300);
                    break;
                case 'D':
                case 'd':
                    Beep(D,300);
                    break;
                case 'E':
                case 'e':
                    Beep(E,300);
                    break;
                case 'F':
                case 'f':
                    Beep(F,300);
                    break;
                case 'G':
                case 'g':
                    Beep(G,300);
                    break;
                default:
                    cout << "Invalid note" << endl;
                    break;
            }

    } while(note!='q'||note!='Q');
};

class Chord : public Note
{
public:
    Chord()
    {
        cout<<"Chord being played"<<endl;
    }
    void addChord()
    {
        cout << "(Enter notes A, B, C, D, E, F, G and Q to play them)\n";
        char input;
        fstream chord;
        chord.open("chord.txt", ios::out);
        do {
            cin >> input;
            if (!chord) {
                cout << "Couldn't create chord file" << endl;
                break;
            }
            else {
                chord << input;
            }
        } while (input != 'q');
        chord.close();
    }
    void play()
    {
        char note;
        fstream chord;
        chord.open("chord.txt", ios::in);
        if (!chord) {
            cout << "Couldn't open chord file" << endl;
        }
        else {
            while (chord >> note) {
                switch (note) {
                    case 'A':
                    case 'a':
                        Beep(A, 300);
                        break;
                    case 'B':
                    case 'b':
                        Beep(B, 300);
                        break;
                    case 'C':
                    case 'c':
                        Beep(C, 300);
                        break;
                    case 'D':
                    case 'd':
                        Beep(D, 300);
                        break;
                    case 'E':
                    case 'e':
                        Beep(E, 300);
                        break;
                    case 'F':
                    case 'f':
                        Beep(F, 300);
                        break;
                    case 'G':
                    case 'g':
                        Beep(G, 300);
                        break;
                    default:
                        cout << "Invalid note" << endl;
                        break;
                }
            }
        }
        chord.close();
    }
};


int main()
{
    Note n1;
    n1.play();
    return 0;
}
