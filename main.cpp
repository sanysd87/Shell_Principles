#include <iostream>
#include <cstdlib> // For system()
#include <string>

//All shell commands are in void functions waiting to be called

//Function that lists directory contents
void listDirectoryContents() {
    std::cout << "Listing directory contents..." << std::endl;
    system("dir");
}

//function that prints the working directory
void printWorkingDirectory() {
    std::cout << "Printing working directory..." << std::endl;
    system("cd");
}

//function that creates new directory
void createNewDirectory() {
    std::string dirName;
    std::cout << "Enter the name of the directory to create: ";
    std::cin >> dirName;
    std::string command = "mkdir " + dirName;   //Concatenate mkdir command with the directory name
    system(command.c_str());
}

//function that displays the message
void displayMessage() {
    std::string message;
    std::cout << "Enter the message to display: ";
    std::cin.ignore(); // Clears the newline character from the buffer
    std::getline(std::cin, message); //Uses getline to ensure full message is displayed with spaces within message
    std::string command = "echo " + message;    //Concatenate echo command with the message
    system(command.c_str());
}

//function that concatenate and displays the file
void concatenateAndDisplayFile() {
    std::string fileName;
    std::cout << "Enter the name of the file to display: ";
    std::cin >> fileName;
    std::string command = "type " + fileName;   //Concatenate type command with the file name
    system(command.c_str());
}

int main() {
    int count = 0;  //count variable to see if it is the user's first time looping

    //The loop below loops infinitely until user exits
    while (true) {
        //The if else condition below is for if it is the user's first time iterating or not.
        if (count < 1) {    //if it is the first time, there will be no \n
            std::cout << "Main Menu:" << std::endl;
        }
        else if (count >= 1) {      //else there will be a \n after the first iteration
            std::cout << "\nMain Menu:" << std::endl;
        }
        //Every iteration will display these menu options below
        std::cout << "1. List directory contents" << std::endl;
        std::cout << "2. Print working directory" << std::endl;
        std::cout << "3. Create a new directory" << std::endl;
        std::cout << "4. Display a message" << std::endl;
        std::cout << "5. Concatenate and display content of a file" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice (1-6): ";

        //The switch cases uses integers to make it more usable/readable to the user
        int choice;
        std::cin >> choice;

        //Uses switch statements to execute the functions to execute shell commands
        switch (choice) {
        case 1:
            listDirectoryContents();
            break;
        case 2:
            printWorkingDirectory();
            break;
        case 3:
            createNewDirectory();
            break;
        case 4:
            displayMessage();
            break;
        case 5:
            concatenateAndDisplayFile();
            break;
        case 6:
            std::cout << "Exiting program." << std::endl;
            return 0;
        default:
            //this part is important because if user puts something they are not supposed to, 
            //then it will just loop again with the statement below
            std::cout << "Invalid choice, please enter a number with the numbers being 1, 2, 3, 4, 5, or 6." << std::endl;
        }
        count++;    //increments the count variable
    }

    return 0;
}