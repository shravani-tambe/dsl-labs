#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;       
    int start;         
    int duration;      
    Node* next;        

    Node(string n, int s, int d) {
        name = n;
        start = s;
        duration = d;
        next = nullptr;
    }
};

void show_free_slots(Node* head, int start_day, int end_day) {
    Node* curr = head;
    int last_end = start_day; 

    cout << "Free Slots:" << endl;
    
    while (curr != nullptr) {
        if (curr->start > last_end) {
            cout << "Free slot from " << last_end / 100 << ":" << last_end % 100 << " to " << curr->start / 100 << ":" << curr->start % 100 << endl;
        }
        last_end = curr->start + curr->duration;
        curr = curr->next;
    }
    if (last_end < end_day) {
        cout << "Free slot from " << last_end / 100 << ":" << last_end % 100 
             << " to " << end_day / 100 << ":" << end_day % 100 << endl;
    }
}

Node* book(Node* head, string n, int s, int d) {

    if (s < 800 || (s + d) > 1700) { // Appointments between 8:00 AM and 5:00 PM
        cout << "Please book between 8:00 AM and 5:00 PM." << endl;
        return head;
    }

    Node* curr = head;
    while (curr != nullptr) {
        if (!(s + d <= curr->start || s >= curr->start + curr->duration)) {
            cout << "Time slot not available!" << endl;
            return head;
        }
        curr = curr->next;
    }

    // Insert new appointment
    Node* new_node = new Node(n, s, d);
    
    if (head == nullptr || head->start > s) {
        new_node->next = head;
        return new_node;
    }

    Node* prev = nullptr;
    curr = head;

    while (curr != nullptr && curr->start < s) {
        prev = curr;
        curr = curr->next;
    }
    
    new_node->next = curr;
    prev->next = new_node;
    return head;
}

Node* cancel(Node* head, string n) {
    Node* curr = head;
    Node* prev = nullptr;

    while (curr != nullptr) {
        if (curr->name == n) {
            if (prev == nullptr) {
                head = curr->next;
            } else {
                prev->next = curr->next;
            }
            delete curr; 
            cout << "Appointment canceled for " << n << endl;
            return head;
        }
        prev = curr;
        curr = curr->next;
    }

    cout << "No appointment found for " << n << endl;
    return head;
}

Node* sort(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* sorted = nullptr;
    Node* curr = head;

    while (curr != nullptr) {
        Node* next = curr->next; 
        if (sorted == nullptr || sorted->start >= curr->start) {
            curr->next = sorted;
            sorted = curr;
        } else {
            Node* temp = sorted;
            while (temp->next != nullptr && temp->next->start < curr->start) {
                temp = temp->next;
            }
            curr->next = temp->next;
            temp->next = curr;
        }
        curr = next; 
    }
    
    return sorted; 
}

void show_appointments(Node* head) {
    Node* curr = head;

    if (curr == nullptr) {
        cout << "No appointments scheduled." << endl;
        return;
    }

    cout << "Scheduled Appointments:" << endl;
    while (curr != nullptr) {
        cout << "Name: " << curr->name 
             << ", Start: " << curr->start / 100 << ":" << (curr->start % 100)
             << ", Duration: " << curr->duration << " mins" << endl;
        curr = curr->next;
    }
}

int main() {
    Node* head = nullptr; 
    int start_day = 800; // 8:00 AM
    int end_day = 1700; // 5:00 PM
    int ch;

    while (true) {
        cout << "\nAppointment Scheduler Menu:" << endl;
        cout << "1. Show Free Slots" << endl;
        cout << "2. Book Appointment" << endl;
        cout << "3. Cancel Appointment" << endl;
        cout << "4. Sort Appointments" << endl;
        cout << "5. Show Appointments" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                show_free_slots(head, start_day, end_day);
                break;
            case 2: {
                string n;
                int s, d;
                cout << "Enter name: ";
                cin >> n;
                cout << "Enter start time: ";
                cin >> s;
                cout << "Enter duration in mins: ";
                cin >> d;
                head = book(head, n, s, d);
                break;
            }
            case 3: {
                string n;
                cout << "Enter name to cancel: ";
                cin >> n;
                head = cancel(head, n);
                break;
            }
            case 4:
                head = sort(head);
                cout << "Appointments sorted by time." << endl;
                break;
            case 5:
                show_appointments(head);
                break;
            case 6:
                cout << "Exiting." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}