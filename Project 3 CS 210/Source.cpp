#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

/**
 * The ItemTracker class is the "brain" of our program.
 * I designed it to handle all the heavy lifting—reading the files,
 * storing the data securely in a map, and generating the required backup.
 */
class ItemTracker {
private:
    // I chose a map because it automatically keeps our produce list 
    // alphabetical and makes looking up item counts super fast.
    map<string, int> itemFrequencies;

    /**
     * This helper function opens the raw daily records and
     * populates our map. It loops through every word in the file
     * and increments the count for that specific item.
     */
    void loadData(string fileName) {
        ifstream inFS(fileName);
        string item;

        if (!inFS.is_open()) {
            cout << "Hold on, I couldn't find the input file. Please check the directory!" << endl;
            return;
        }

        while (inFS >> item) {
            itemFrequencies[item]++;
        }
        inFS.close();
    }

    /**
     * Requirement Check: This creates 'frequency.dat' right at the start.
     * It loops through our finished map and writes a clean list
     * to a new file so the store has a permanent backup of the data.
     */
    void saveBackup(string outputFile) {
        ofstream outFS(outputFile);
        for (auto const& [item, count] : itemFrequencies) {
            outFS << item << " " << count << endl;
        }
        outFS.close();
    }

public:
    /**
     * When we create a 'tracker' object, it immediately gets to work.
     * It loads the grocer's data and saves the backup file
     * before the user even sees the menu.
     */
    ItemTracker(string inputFile) {
        loadData(inputFile);
        saveBackup("frequency.dat");
    }

    /**
     * Option 1: This handles the specific item search.
     * I used the .count() method to see if the item exists first,
     * which prevents the program from accidentally adding new items during a search.
     */
    void searchForItem() {
        string searchTerm;
        cout << "What item are you looking for? ";
        cin >> searchTerm;

        if (itemFrequencies.count(searchTerm)) {
            cout << searchTerm << " was purchased " << itemFrequencies[searchTerm] << " times today." << endl;
        }
        else {
            cout << "Sorry, " << searchTerm << " doesn't appear in today's records." << endl;
        }
    }

    /**
     * Option 2: A simple list output.
     * This iterates through the map and prints every item followed by its total.
     */
    void printList() {
        cout << "\n--- Full Item Frequency List ---" << endl;
        for (auto const& [item, count] : itemFrequencies) {
            cout << item << " " << count << endl;
        }
    }

    /**
     * Option 3: The Histogram.
     * I used 'setw' to keep the item names aligned on the left,
     * then used a nested loop to print an asterisk for every
     * single time that item was bought.
     */
    void printHistogram() {
        cout << "\n--- Visual Purchase Frequency ---" << endl;
        for (auto const& [item, count] : itemFrequencies) {
            cout << left << setw(12) << item << " ";
            for (int i = 0; i < count; ++i) {
                cout << "*";
            }
            cout << endl;
        }
    }
};

/**
 * Our main function acts as the interface.
 * I built a loop here that keeps the program running until the user
 * chooses to exit, with a bit of safety logic to handle typos.
 */
int main() {
    // We point the program to the specific file provided by the grocer
    ItemTracker tracker("CS210_Project_Three_Input_File.txt");
    int choice = 0;

    while (choice != 4) {
        cout << "\n1. Search for an Item" << endl;
        cout << "2. Print Frequency List" << endl;
        cout << "3. Print Histogram" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";

        // This is my input validation. If someone types a letter 
        // instead of a number, this keeps the program from crashing.
        if (!(cin >> choice)) {
            cout << "That's not a valid option. Please enter a number between 1 and 4." << endl;
            cin.clear();
            cin.ignore(100, '\n');
            continue;
        }

        switch (choice) {
        case 1: tracker.searchForItem(); break;
        case 2: tracker.printList(); break;
        case 3: tracker.printHistogram(); break;
        case 4: cout << "Thank you for using the Corner Grocer tracker. Goodbye!" << endl; break;
        default: cout << "Please select a valid menu option." << endl;
        }
    }

    return 0;
}