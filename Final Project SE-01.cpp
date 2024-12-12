#include <iostream>    //using iostream for input and output.
#include <fstream>       //using fstream for file system.
#include <string>       //using string for handling and manipulating strings.
#include <iomanip>     //using iomanip for professional formatting of input/output (making the program more readable).   
#include <windows.h>  //using the widows.h for color manipulation.
using namespace std; //standard library function.

// Function Prototypes
void setConsoleColor(int textColor, int backgroundColor);
void createContact();
void viewContacts();
void searchContact();
void deleteContact();
void updateContact();
void displayMenu();

int main() {
    int choice;

    system("color E0");

    // Display Welcome Message on the first screen
    cout<<"\n\n\n\n\t\t\t\t          Bismillah-ir-Rahman-ir-Rahim";
  cout<<"\n\n\n\n\t\t\t\t ^IN THE NAME OF ALLAH, THE MERCIFUL, THE BENEFICENT^ "<<endl;
  cout<<endl;
  cout<<"\n\n\n\n\t\t\t\t __________________ WELLCOME _________________"<<endl;
  cout<<endl;
	cout<<endl;
	cout<<endl;
    cout<<"\t     ##########   ##########   ##            #  ##############    ##       ########## ############## "<<endl;
 	cout<<"\t     #       ##  #          #  #  #          #        #         #    #     #       ##       #        "<<endl;
 	cout<<"\t     #           #           # #    #        #        #        #      #    #                #        "<<endl;
 	cout<<"\t     #           #           # #      #      #        #       # ###### #   #                #        "<<endl;
 	cout<<"\t     #           #           # #        #    #        #      #          #  #                #        "<<endl;
 	cout<<"\t     #       ##   #          # #          #  #        #     #            # #       ##       #        "<<endl;
 	cout<<"\t     ##########    #########   #             ##       #    #              # #########       #        "<<endl;
 	cout<<endl;
 	
 	cout<<"\t\t       #####  #     #  #####  ####### ####### #     # "<<endl;
 	cout<<"\t\t      #     #  #   #  #     #    #    #       ##   ##  "<<endl;
 	cout<<"\t\t      #         # #   #          #    #       # # # # "<<endl;
 	cout<<"\t\t       #####     #     #####     #    #####   #  #  # "<<endl;
	cout<<"\t\t            #    #          #    #    #       #     # "<<endl;
 	cout<<"\t\t      #     #    #    #     #    #    #       #     # "<<endl;
 	cout<<"\t\t       #####     #     #####     #    ####### #     # "<<endl;

    cout << "Press any key to continue...";
    cin.ignore();
    system("cls"); // Clear screen before showing the menu
 system("color 8E");
    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); // This ensures the input process works smoothly without unexpected behavior.

        // Clear screen for the next function display
        system("cls");

        // Based on the choice, call the corresponding function.
        switch (choice) {
            case 1: 
                createContact();
                break;
            case 2: 
                viewContacts();
                break;
            case 3: 
                searchContact();
                break;
            case 4: 
                deleteContact();
                break;
            case 5: 
                updateContact();
                break;
            case 6:
                cout << "Exiting program. Goodbye!\n";
                setConsoleColor(7, 0); // Reset to default colors
                break;
            default: 
                setConsoleColor(12, 0); // Red text
                cout << "Invalid choice. Please try again.\n";
                setConsoleColor(15, 1); // Reset to white on blue
        }
    } while (choice != 6);

    return 0;
}

// Set console text and background color
void setConsoleColor(int textColor, int backgroundColor) {
    int color = backgroundColor * 16 + textColor;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Display the main menu
void displayMenu() {
    // Use formatting to simulate the menu
    cout<<"\n\n\n\t ***************************************"<<endl;
         cout<<"\n\t            WELLCOME TO HOME PAGE "<<endl;
        cout<<"\n\n\n\t ***************************************"<<endl;
        cout<<"\n\t\t         MAIN MENU";
        cout<<"\n\n\t ##########################################"<<endl;
    cout << "\n===== Contact Management System =====\n";
    cout << "1. Create Contact\n";
    cout << "2. View All Contacts\n";
    cout << "3. Search Contact\n";
    cout << "4. Delete Contact\n";
    cout << "5. Update Contact\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

// Function for creating a contact
void createContact() {
    ofstream file("contacts.txt", ios::app);
    if (!file) {
        setConsoleColor(12, 0); // Red text
        cout << "Error opening file!" << endl;
        setConsoleColor(15, 1); // Reset to white on blue
        return;
    }

    string name, phone, email;
    cout << "\nEnter Name: ";
    getline(cin, name);
    cout << "Enter Phone: ";
    getline(cin, phone);
    cout << "Enter Email: ";
    getline(cin, email);

    file << name << endl;
    file << phone << endl;
    file << email << endl;

    setConsoleColor(10, 0); // Green text
    cout << "Contact created successfully!\n";
    setConsoleColor(15, 1); // Reset to white on blue
    file.close();

    // Wait for the user to press a key before returning to the menu
    cout << "\nPress any key to return to the menu.";
    cin.ignore();
    system("cls");
}

// Function for viewing contacts
void viewContacts() {
    ifstream file("contacts.txt");
    if (!file) {
        setConsoleColor(12, 0); // Red text
        cout << "No contacts found!\n";
        setConsoleColor(15, 1); // Reset to white on blue
        return;
    }

    string name, phone, email;
    int count = 0;

    cout << "\n===== Contact List =====\n";
    while (getline(file, name) && getline(file, phone) && getline(file, email)) {
        count++;
        setConsoleColor(14, 0); // Yellow text
        cout << "Contact #" << count << endl;
        setConsoleColor(15, 1); // Reset to white on blue
        cout << "Name  : " << name << endl;
        cout << "Phone : " << phone << endl;
        cout << "Email : " << email << endl;
        cout << "---------------------------\n";
    }

    if (count == 0) {
        setConsoleColor(12, 0); // Red text
        cout << "No contacts available!\n";
        setConsoleColor(15, 1); // Reset to white on blue
    }
    file.close();

    // Wait for the user to press a key before returning to the menu
    cout << "\nPress any key to return to the menu.";
    cin.ignore();
    system("cls");
}

// Function for searching a contact
void searchContact() {
    ifstream file("contacts.txt");
    if (!file) {
        setConsoleColor(12, 0); // Red text
        cout << "No contacts found!\n";
        setConsoleColor(15, 1); // Reset to white on blue
        return;
    }

    string name, phone, email, searchName;
    cout << "Enter the name to search: ";
    getline(cin, searchName);

    bool found = false;
    while (getline(file, name) && getline(file, phone) && getline(file, email)) {
        if (name == searchName) {
            setConsoleColor(10, 0); // Green text
            cout << "\nContact Found:\n";
            cout << "Name  : " << name << endl;
            cout << "Phone : " << phone << endl;
            cout << "Email : " << email << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        setConsoleColor(12, 0); // Red text
        cout << "Contact not found.\n";
        setConsoleColor(15, 1); // Reset to white on blue
    }
    file.close();

    // Wait for the user to press a key before returning to the menu
    cout << "\nPress any key to return to the menu.";
    cin.ignore();
    system("cls");
}

// Function for deleting a contact
void deleteContact() {
    ifstream inputFile("contacts.txt");
    ofstream tempFile("temp.txt");
    if (!inputFile || !tempFile) {
        setConsoleColor(12, 0); // Red text
        cout << "Error opening file!" << endl;
        setConsoleColor(15, 1); // Reset to white on blue
        return;
    }

    string name, phone, email, nameToDelete;
    cout << "Enter the name of the contact to delete: ";
    getline(cin, nameToDelete);

    bool found = false;

    while (getline(inputFile, name) && getline(inputFile, phone) && getline(inputFile, email)) {
        if (name == nameToDelete) {
            found = true;
            setConsoleColor(10, 0); // Green text
            cout << "Deleting contact: " << name << endl;
            setConsoleColor(15, 1); // Reset to white on blue
        } else {
            tempFile << name << endl;
            tempFile << phone << endl;
            tempFile << email << endl;
        }
    }

    inputFile.close();
    tempFile.close();

    if (found) {
        remove("contacts.txt");
        rename("temp.txt", "contacts.txt");
        setConsoleColor(10, 0); // Green text
        cout << "Contact deleted successfully.\n";
        setConsoleColor(15, 1); // Reset to white on blue
    } else {
        remove("temp.txt");
        setConsoleColor(12, 0); // Red text
        cout << "Contact not found.\n";
        setConsoleColor(15, 1); // Reset to white on blue
    }

    // Wait for the user to press a key before returning to the menu
    cout << "\nPress any key to return to the menu.";
    cin.ignore();
    system("cls");
}

// Function for updating a contact
void updateContact() {
    ifstream inputFile("contacts.txt");
    ofstream tempFile("temp.txt");
    if (!inputFile || !tempFile) {
        setConsoleColor(12, 0); // Red text
        cout << "Error opening file!" << endl;
        setConsoleColor(15, 1); // Reset to white on blue
        return;
    }

    string name, phone, email, nameToUpdate;
    cout << "Enter the name of the contact to update: ";
    getline(cin, nameToUpdate);

    bool found = false;

    while (getline(inputFile, name) && getline(inputFile, phone) && getline(inputFile, email)) {
        if (name == nameToUpdate) {
            found = true;
            setConsoleColor(14, 0); // Yellow text
            cout << "Updating contact: " << name << endl;

            string newName, newPhone, newEmail;
            cout << "Enter New Name: ";
            getline(cin, newName);
            cout << "Enter New Phone: ";
            getline(cin, newPhone);
            cout << "Enter New Email: ";
            getline(cin, newEmail);

            tempFile << newName << endl;
            tempFile << newPhone << endl;
            tempFile << newEmail << endl;
            setConsoleColor(10, 0); // Green text
            cout << "Contact updated successfully!\n";
        } else {
            tempFile << name << endl;
            tempFile << phone << endl;
            tempFile << email << endl;
        }
    }

    inputFile.close();
    tempFile.close();

    if (found) {
        remove("contacts.txt");
        rename("temp.txt", "contacts.txt");
    } else {
        remove("temp.txt");
        setConsoleColor(12, 0); // Red text
        cout << "Contact not found.\n";
    }
    setConsoleColor(15, 1); // Reset to white on blue

    // Wait for the user to press a key before returning to the menu
    cout << "\nPress any key to return to the menu.";
    cin.ignore();
    system("cls");
}

