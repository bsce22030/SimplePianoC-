#include <Windows.h>
#include <iostream>

using namespace std;

const int NUM_KEYS = 7;
const int KEY_FREQS[NUM_KEYS] = { 262, 294, 330, 349, 392, 440, 494 };
const char KEY_NAMES[NUM_KEYS] = { 'C', 'D', 'E', 'F', 'G', 'A', 'B' };

int main()
{
    cout << "Simple Piano Application\n\n";
    cout << "Press the following keys to play the corresponding notes:\n";
    cout << " C D E F G A B\n";

    while (true)
    {
        char key = getchar();

        // Exit the program if the user presses 'q'
        if (key == 'q')
        {
            break;
        }

        // Find the index of the pressed key in the KEY_NAMES array
        int keyIndex = -1;
        for (int i = 0; i < NUM_KEYS; i++)
        {
            if (toupper(key) == KEY_NAMES[i])
            {
                keyIndex = i;
                break;
            }
        }

        // If a valid key was pressed, play the corresponding note
        if (keyIndex >= 0)
        {
            Beep(KEY_FREQS[keyIndex], 300);
        }
    }

    return 0;
}
