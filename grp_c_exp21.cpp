

#include <iostream>
#include <ctime>
using namespace std;

// Class for a node (appointment)
class Node {
public:
    string name;           // Name of the person
    int start_time;        // Start time of the appointment (in minutes from midnight)
    int end_time;          // End time of the appointment (in minutes from midnight)
    Node* next;            // Pointer to next node in the list

    // Constructor to initialize the node
    Node(string name, int start_time, int end_time) {
        this->name = name;
        this->start_time = start_time;
        this->end_time = end_time;
        this->next = nullptr;
    }
};

// Linked list head pointer
Node* head = nullptr;

// Function to display all free slots in a day
void displayFreeSlots(int day_start, int day_end, int min_duration, int max_duration) {
    cout << "Available slots are:\n";
    int current_time = day_start;
    Node* temp = head;
    
    while (temp != nullptr) {
        // Check for free slots between current_time and the start time of the next appointment
        if (current_time < temp->start_time) {
            int free_duration = temp->start_time - current_time;
            if (free_duration >= min_duration) {
                cout << "From " << current_time / 60 << ":" << current_time % 60 << " to "
                     << temp->start_time / 60 << ":" << temp->start_time % 60 << endl;
            }
        }
        current_time = temp->end_time;
        temp = temp->next;
    }

    // Check for free slots after the last appointment until the end of the day
    if (current_time < day_end) {
        cout << "From " << current_time / 60 << ":" << current_time % 60 << " to "
             << day_end / 60 << ":" << day_end % 60 << endl;
    }
}

// Function to book an appointment
void bookAppointment(string name, int start_time, int end_time) {
    // Check if the time is valid
    if (start_time >= end_time || start_time < 0 || end_time > 1440) {
        cout << "Invalid appointment time!" << endl;
        return;
    }
    
    Node* new_node = new Node(name, start_time, end_time);

    // Insert the new node into the list in sorted order based on time
    if (head == nullptr || head->start_time > start_time) {   //so priority to our appointment.
        new_node->next = head;
        head = new_node;
    } else {
        Node* temp = head;
        while (temp->next != nullptr && temp->next->start_time < start_time) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
    cout << "Appointment booked for " << name << " from " << start_time / 60 << ":" << start_time % 60
         << " to " << end_time / 60 << ":" << end_time % 60 << endl;
}

// Function to cancel an appointment
void cancelAppointment(string name) {
    if (head == nullptr) {
        cout << "No appointments to cancel." << endl;
        return;
    }
    
    Node* temp = head;
    Node* prev = nullptr;
    
    // Search for the appointment by name
    while (temp != nullptr && temp->name != name) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == nullptr) {
        cout << "Appointment not found for " << name << endl;
        return;
    }

    // Remove the appointment from the linked list
    if (prev == nullptr) {
        head = head->next;
    } else {
        prev->next = temp->next;
    }
    delete temp;
    cout << "Appointment for " << name << " has been canceled." << endl;
}

// Function to sort appointments based on time using pointer manipulation (insertion sort)
void sortAppointments() {      // bubble sort method is used.
    if (head == nullptr || head->next == nullptr) {
        return;
    }
    
    Node* sorted = nullptr;
    Node* current = head;
    
    while (current != nullptr) {
        Node* next = current->next;
        // Insert current into sorted linked list
        if (sorted == nullptr || sorted->start_time > current->start_time) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next != nullptr && temp->next->start_time < current->start_time) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    head = sorted;
}

// Function to display all appointments
void displayAppointments() {
    if (head == nullptr) {
        cout << "No appointments scheduled." << endl;
        return;
    }
    
    Node* temp = head;     //initialize
    while (temp != nullptr) {
        cout << "Appointment for " << temp->name << " from "
             << temp->start_time / 60 << ":" << temp->start_time % 60 << " to "
             << temp->end_time / 60 << ":" << temp->end_time % 60 << endl;
        temp = temp->next;    //incrementation
    }
}

int main() {
    int day_start = 9 * 60; // 9:00 AM in minutes
    int day_end = 17 * 60;  // 5:00 PM in minutes
    int min_duration = 30;  // Minimum duration of appointment in minutes
    int max_duration = 120; // Maximum duration of appointment in minutes

    while (true) {
        int choice;
        cout << "\n1. Display Free Slots\n"
             << "2. Book Appointment\n"
             << "3. Cancel Appointment\n"
             << "4. Sort Appointments\n"
             << "5. Display Appointments\n"
             << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            displayFreeSlots(day_start, day_end, min_duration, max_duration);
        } else if (choice == 2) {
            string name;
            int start_time, end_time;
            cout << "Enter your name: ";
            cin >> name;
            cout << "Enter appointment start time (minutes from midnight): ";
            cin >> start_time;
            cout << "Enter appointment end time (minutes from midnight): ";
            cin >> end_time;
            bookAppointment(name, start_time, end_time);
        } else if (choice == 3) {
            string name;
            cout << "Enter name to cancel appointment: ";
            cin >> name;
            cancelAppointment(name);
        } else if (choice == 4) {
            sortAppointments();
            cout << "Appointments sorted based on time.\n";
        } else if (choice == 5) {
            displayAppointments();
        } else if (choice == 6) {
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
