/*
 * =========================================================================================
 * PROJECT: Detective Mystery Game - "The Manor House Murder"
 * Team: Sanyam Goyal, Arzoo, Vidhi Gupta, Chaitanya Gupta
 * Lab: S.D.F Lab PBL Project (JIIT Noida)
 * =========================================================================================
 */

#include <iostream>
#include <vector>
#include <string>


using namespace std;

// ==========================================================
// Clue class to store evidence details
class Clue {
private:
    string description; // Text describing the clue
    bool collected;     // Flag to check if player has found it

public:
    /*
     * Constructor: Clue
     * Parameters: string desc - The description of the clue
     * Purpose: Initializes a new clue with given description.
     */
    Clue(string desc) {
        description = desc;
        collected = false;
    }

    /*
     * Method: getDescription
     * Return: string - The clue's text
     */
    string getDescription() const {
        return description;
    }

    /*
     * Method: isCollected
     * Return: bool - True if found, false otherwise
     */
    bool isCollected() const {
        return collected;
    }

    /*
     * Method: collect
     * Purpose: Marks the clue as found by the player.
     */
    void collect() {
        collected = true;
    }
};

// ==========================================================
// Suspect class to store character information
class Suspect {
private:
    string name;       // Name of the suspect
    string statement;  // Alibi provided during interview
    bool isCulprit;    // Hidden flag for the killer

public:
    /*
     * Constructor: Suspect
     * Parameters: name, statement, culprit flag
     * Purpose: Initializes suspect attributes.
     */
    Suspect(string n, string s, bool culprit) {
        name = n;
        statement = s;
        isCulprit = culprit;
    }

    /*
     * Method: getName
     * Return: string - The suspect's name
     */
    string getName() const {
        return name;
    }

    /*
     * Method: getStatement
     * Return: string - The alibi statement
     */
    string getStatement() const {
        return statement;
    }

    /*
     * Method: getIsCulprit
     * Return: bool - True if this person is the killer
     */
    bool getIsCulprit() const {
        return isCulprit;
    }
};

// ==========================================================
// Game class to control the game flow
class Game {
private:
    vector<Suspect> suspects;      // List of all suspects
    vector<Clue> clues;            // List of initial clues
    vector<Clue> extraClues;       // List of hidden clues
    bool gameWon;                  // Tracks if player solved the case
    bool gameRunning;              // Controls the main loop

    /*
     * Method: printBanner
     * Purpose: Prints a stylish ASCII banner for the game.
     */
    void printBanner() {
        cout << "======================================================" << endl;
        cout << "      DETECTION & MYSTERY: THE BLACKWOOD MANOR        " << endl;
        cout << "            S.D.F LAB - JIIT NOIDA                    " << endl;
        cout << "======================================================" << endl;
        cout << "               CASE FILE #10303                       " << endl;
        cout << "======================================================" << endl << endl;
    }

    /*
     * Method: initializeData
     * Purpose: Sets up the initial suspects and clues.
     */
    void initializeData() {
        // Adding Suspects (as per requirements)
        suspects.push_back(Suspect("Lord Blackwood", "I was in my chambers all evening.", false));
        suspects.push_back(Suspect("Miss Scarlett", "I left early with a headache... alone.", true));
        suspects.push_back(Suspect("Dr. Watson", "I was treating a patient in east wing.", false));
        suspects.push_back(Suspect("Colonel Mustard", "I played cards with Edmund till 10 PM.", false));

        // Adding Initial Clues
        clues.push_back(Clue("A muddy footprint near the library window"));
        clues.push_back(Clue("A torn piece of red fabric on the garden fence"));
        clues.push_back(Clue("A half-burned letter found in the fireplace"));
        clues.push_back(Clue("The victim's pocket watch is missing from the body"));
        clues.push_back(Clue("An overturned glass of wine on the study table"));

        // Adding Extra Clues (Deeper Investigation)
        extraClues.push_back(Clue("A witness saw someone in red near the study at midnight"));
        extraClues.push_back(Clue("Miss Scarlett's glove found under the victim's desk"));
        extraClues.push_back(Clue("Security log: Miss Scarlett entered mansion at 11:45 PM"));
    }

    /*
     * Method: showIntro
     * Purpose: Provides the back-story to the user.
     */
    void showIntro() {
        cout << "\n========================================================" << endl;
        cout << "                [ CASE BACKGROUND ]                     " << endl;
        cout << "===================================================" << endl;
        cout << "A thick fog roll=====s over the manor. Inside, Sir Edmund, the billionaire" << endl;
        cout << "philanthropist, has been murdered. The study door was locked from" << endl;
        cout << "the inside, but a window was left slightly ajar." << endl << endl;
        cout << "The Inspector has secured the perimeter, and now it is your turn." << endl;
        cout << "Search for clues, question everyone, and find the truth." << endl;
        cout << "========================================================" << endl;
        cout << "Press ENTER to begin the investigation...";
        cin.ignore(1000, '\n');
    }

    /*
     * Method: visitCrimeScene
     * Purpose: Describes the crime scene state.
     */
    void visitCrimeScene() {
        cout << "\n[ SEARCHING: SIR EDMUND'S STUDY ]" << endl;
        cout << "The smell of old books and expensive tobacco fills the air." << endl;
        cout << "The desk is a mess, and the floor shows signs of a struggle." << endl;
    }

    /*
     * Method: collectClues
     * Purpose: Iterates through clues and 'collects' them.
     */
    void collectClues() {
        cout << "\n>>> Scanning the room for evidence..." << endl;
        bool newlyFound = false;
        for (int i = 0; i < clues.size(); i++) {
            if (!clues[i].isCollected()) {
                cout << "[!] NEW EVIDENCE: " << clues[i].getDescription() << endl;
                clues[i].collect();
                newlyFound = true;
            }
        }
        
        if (!newlyFound) {
            cout << "You've already picked this room clean of basic evidence." << endl;
        } else {
            cout << "\nInitial sweep complete. Basic clues stored in case file." << endl;
        }
    }

    /*
     * Method: showInventory
     * Purpose: Displays all collected clues so far.
     */
    void showInventory() {
        cout << "\n====================================" << endl;
        cout << "      YOUR CASE FILE (CLUES)        " << endl;
        cout << "====================================" << endl;
        int count = 0;
        for (int i = 0; i < clues.size(); i++) {
            if (clues[i].isCollected()) {
                cout << " - " << clues[i].getDescription() << endl;
                count++;
            }
        }
        for (int i = 0; i < extraClues.size(); i++) {
            if (extraClues[i].isCollected()) {
                cout << " - " << extraClues[i].getDescription() << endl;
                count++;
            }
        }
        if (count == 0) {
            cout << "(No evidence collected yet.)" << endl;
        }
        cout << "====================================" << endl;
    }

    /*
     * Method: interviewSuspects
     * Purpose: Interactive loop for questioning characters.
     */
    void interviewSuspects() {
        int subChoice = -1;
        while (subChoice != 0) {
            cout << "\n================================" << endl;
            cout << "        INTERVIEW ROOM          " << endl;
            cout << "================================" << endl;
            cout << "Who would you like to question?" << endl;
            for (int i = 0; i < suspects.size(); i++) {
                cout << (i + 1) << ". " << suspects[i].getName() << endl;
            }
            cout << "0. Return to Menu" << endl;
            cout << "Select (0-4): ";
            cin >> subChoice;

            if (subChoice > 0 && subChoice <= suspects.size()) {
                cout << "\n" << suspects[subChoice - 1].getName() << " leans forward and says:" << endl;
                cout << ">> \"" << suspects[subChoice - 1].getStatement() << "\"" << endl;
            } else if (subChoice != 0) {
                cout << "\n[!] That person is not on the suspect list." << endl;
            }
        }
    }

    /*
     * Method: deepSearch
     * Purpose: Logic to find extra, more conclusive clues.
     */
    void deepSearch() {
        cout << "\n>>> Digging deeper into the manor's archives and logs..." << endl;
        bool foundAnything = false;
        for (int i = 0; i < extraClues.size(); i++) {
            if (!extraClues[i].isCollected()) {
                cout << "[!!] CRITICAL CLUE FOUND: " << extraClues[i].getDescription() << endl;
                extraClues[i].collect();
                foundAnything = true;
                break; // Progression: one extra clue per deep search
            }
        }
        
        if (!foundAnything) {
            cout << "Nothing more to find here. You have all the evidence." << endl;
        }
    }

    /*
     * Method: accuse
     * Purpose: The final logic check to see if the player wins.
     */
    void accuse() {
        cout << "\n====================================" << endl;
        cout << "        THE FINAL ACCUSATION        " << endl;
        cout << "====================================" << endl;
        cout << "The suspects are gathered in the drawing room." << endl;
        cout << "Silence falls as you prepare to point your finger." << endl << endl;
        
        for (int i = 0; i < suspects.size(); i++) {
            cout << (i + 1) << ". " << suspects[i].getName() << endl;
        }
        
        int finalChoice;
        cout << "\nWho is the killer? (1-4): ";
        cin >> finalChoice;

        if (finalChoice > 0 && finalChoice <= suspects.size()) {
            if (suspects[finalChoice - 1].getIsCulprit()) {
                cout << "\n[ SUCCESS ]" << endl;
                cout << "You correctly identified " << suspects[finalChoice - 1].getName() << "!" << endl;
                cout << "As the police take her away, she confesses." << endl;
                cout << "She was furious about being cut out of the will." << endl;
                cout << "You have solved the Blackwood Manor mystery!" << endl;
                gameWon = true;
            } else {
                cout << "\n[ FAILURE ]" << endl;
                cout << "You accused " << suspects[finalChoice - 1].getName() << " incorrectly." << endl;
                cout << "While you were wrong, the real killer escaped in the night." << endl;
                cout << "The case will remain cold forever." << endl;
                gameWon = false;
            }
        } else {
            cout << "Invalid choice. The investigation ends in confusion." << endl;
        }
        gameRunning = false;
    }

public:
    /*
     * Constructor: Game
     * Purpose: Sets initial flags and calls data initialization.
     */
    Game() {
        gameWon = false;
        gameRunning = true;
        initializeData();
    }

    /*
     * Method: run
     * Purpose: The central loop of the game.
     */
    void run() {
        printBanner();
        showIntro();
        visitCrimeScene();

        while (gameRunning) {
            cout << "\n====================================" << endl;
            cout << "     MAIN INVESTIGATION MENU        " << endl;
            cout << "====================================" << endl;
            cout << "1. Collect Basic Evidence" << endl;
            cout << "2. View Collected Clues (Inventory)" << endl;
            cout << "3. Interview Suspects" << endl;
            cout << "4. Deep Search (Extra Clues)" << endl;
            cout << "5. Final Accusation (Solve Case)" << endl;
            cout << "6. Give Up & Quit" << endl;
            cout << "Choice: ";

            int choice;
            cin >> choice;

            // Simple validation for non-integer inputs
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Please enter a valid menu number (1-6)." << endl;
                continue;
            }

            switch (choice) {
                case 1: collectClues(); break;
                case 2: showInventory(); break;
                case 3: interviewSuspects(); break;
                case 4: deepSearch(); break;
                case 5: accuse(); break;
                case 6: 
                    cout << "Leaving the manor... the killer remains at large." << endl;
                    gameRunning = false; 
                    break;
                default:
                    cout << "Detective, please choose a valid action." << endl;
                    break;
            }
        }

        cout << "\n==========================================================" << endl;
        if (gameWon) {
            cout << "             MISSION ACCOMPLISHED - Case Closed           " << endl;
        } else {
            cout << "             MISSION FAILED - Case Unsolved               " << endl;
        }
        cout << "==========================================================" << endl;
        cout << "Thank you for playing our S.D.F Lab PBL Project!" << endl;
        cout << "Team: Sanyam, Arzoo, Vidhi, Chaitanya (JIIT Noida)" << endl;
    }
};

// ==========================================================
// Main Function to start the game
int main() {
    // Instantiate the Game object
    Game detectiveGame;
    
    // Start the game execution
    detectiveGame.run();
    
    return 0;
}

/*
 * =========================================================================================
 * OOP CONCEPT CHECKLIST (For Lab Viva):
 * 1. Classes & Objects: 'Game', 'Suspect', and 'Clue' are classes. 'detectiveGame' is an object.
 * 2. Encapsulation: All properties are private; accessed via public methods.
 * 3. Constructors: Used to initialize state (e.g., Clue description).
 * 4. Vectors: Used to store lists of objects dynamically.
 * 5. Control Structures: Loops and conditionals for game logic.
 * 6. Member Functions: Logic is organized into modular functions.
 * =========================================================================================
 */