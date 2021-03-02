#include <iostream>

#include "linkedQueue.h"

using namespace std;

const int numberOfBuckets = 36;

// helper method
void outputDataArray(string data[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << (data[i]) << endl;
    }
}

void sort(string inArray[], int arrayLength, const int sizeOfValues)
{

    linkedQueueType<string> buckets[numberOfBuckets];

    // for each position to be sorted
    for (int charPos = sizeOfValues-1; charPos >= 0; charPos--)
    { 

        // clear the buckets
        for (int i = 0; i < arrayLength; i++)
        {
            buckets[i].initializeQueue();
        }

        // add each element to proper bucket
        for (int i = 0; i < arrayLength; i++)
        {   
            // Condition to account for if the character is a number (0-9) or not, changes how they get binned
            if(static_cast<int>(inArray[i].at(charPos)) >= 48 && static_cast<int>(inArray[i].at(charPos)) <= 57) 
                buckets[static_cast<int>(inArray[i].at(charPos) & 0x0f)].addQueue(inArray[i]);
            else
                buckets[static_cast<int>(inArray[i].at(charPos))-87].addQueue(inArray[i]); //87 is the offset between lowercase a and the number 9 (36 bins)
            //cout << static_cast<int>(inArray[i].at(charPos)) << " ";
        }

        //cout << endl;

        // 'restack' input array from buckets
        int arrayPosition = 0;
        int bucketNumber = 0;
        while (bucketNumber < numberOfBuckets)
        {
            while (!(buckets[bucketNumber].isEmptyQueue()))
            {
                inArray[arrayPosition] = buckets[bucketNumber].front();
                buckets[bucketNumber].deleteQueue();
                arrayPosition += 1;
            }
            bucketNumber += 1;
        }
    }
}

int main()
{
    cout << "Radix Sort Program - Tyler Harrison - Lab 06\n-----------------------" << endl;

    char loopVar = 'Y';
    while(loopVar == 'Y' || loopVar == 'y')
    {
        cout << "Select one of the following demonstrations: \n[1] Numbers only\n[2] Letters only\n[3] Alpha-numeric\n";
        cout << "Input: ";
        
        int choice = 0;
        cin >> choice;

        // Dummy data
        string dummyData[] = {"0000", "0000", "0000", "0000", "0000",
                        "0000", "0000", "0000", "0000", "0000"};
        string *data = dummyData;
        if(choice == 1)
        {
            string numbers[] = {"1123", "1398", "1210", "1019", "1528",
                            "1003", "1513", "1129", "1220", "1294"};
            data = numbers;
        }
        else if (choice == 2)
        {
            string words[] = {"test", "fire", "thik", "slik", "aunt",
                            "cass", "meme", "easy", "game", "noob"};
            data = words;
        }
        else if (choice == 3)
        {
            string alphanum[] = {"t3st", "f1re", "th1k", "sl1k", "4unt",
                            "c4ss", "m3m3", "3asy", "g4m3", "n00b"};
            data = alphanum;
        }
        
        cout << "Before Sort\n-----------------------" << endl;
        outputDataArray(data, 10);

        sort(data, 10, 4);

        cout << "\nAfter Sort\n-----------------------" << endl;
        outputDataArray(data, 10);
        cout << "\nDo it again? (Y/N): ";
        cin >> loopVar;
        cout << endl;
    }
}
