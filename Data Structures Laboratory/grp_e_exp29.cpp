#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string job; 
    Node* next; 

    Node(string j) {
        job = j;   
        next = nullptr;
    }
};

class JobQueue {
private:
    Node* front; 
    Node* rear; 

public:
    JobQueue() {
        front = nullptr;
        rear = nullptr;
    }

    void add_job(string job) {
        Node* new_job = new Node(job); 
        if (rear == nullptr) {
            front = new_job; 
            rear = new_job;
        } else {
            rear->next = new_job;
            rear = new_job; 
        }
        cout << "Job added: " << job << endl;
    }

    void delete_job() {
        if (front == nullptr) {
            cout << "Queue is empty, no job to delete." << endl;
            return;
        }
        Node* temp = front; 
        front = front->next; 

        if (front == nullptr) {
            rear = nullptr;
        }
        
        cout << "Job deleted: " << temp->job << endl;
        delete temp; 
    }

    void display_jobs() {
        if (front == nullptr) {
            cout << "Queue is empty, no jobs to display." << endl;
            return;
        }
        Node* temp = front; 
        cout << "Jobs in queue: ";
        while (temp != nullptr) {
            cout << temp->job << " ";
            temp = temp->next; 
        }
        cout << endl;
    }
};

int main() {
    JobQueue queue; 
    int ch; 
    string job; 

    while (true) {
        cout << "Choose an operation: \n1. Add Job \n2. Delete Job \n3. Display Jobs \n4. Exit" << endl;
        cin >> ch; 
        cin.ignore();  

        switch (ch) {
            case 1:
                cout << "Enter job description: ";
                getline(cin, job); 
                queue.add_job(job);
                break;
            case 2:
                queue.delete_job();
                break;
            case 3:
                queue.display_jobs();
                break;
            case 4:
                cout << "Exiting program." << endl;
                return 0; 
            default:
                cout << "Please try again." << endl;
        }
    }

    return 0;
}
