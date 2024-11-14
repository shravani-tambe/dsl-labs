#include<iostream>
#include<string>

using namespace std;

class Node {
public:
    string prn;
    string name;
    Node* next;

    Node(string prn1, string name1) {
        prn = prn1;
        name = name1;
        next = nullptr;
    }
};

Node* insert_front(Node* head, string prn, string name) {
    Node* add = new Node(prn, name);
    add->next = head;
    return add;
}

Node* insert_back(Node* head, string prn, string name) {
    Node* add = new Node(prn, name);
    if (head == nullptr) {
        return add;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = add;
    return head;
}

Node* insert_at(Node* head, string prn, string name, int pos) {
    Node* add = new Node(prn, name);
    if (pos == 1) {
        return insert_front(head, prn, name);
    }
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Position out of bounds!" << endl;
        return head;
    }
    add->next = temp->next;
    temp->next = add;
    return head;
}

Node* delete_front(Node* head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return head;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

// Delete the last node (secretary)
Node* delete_back(Node* head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return head;
    }
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node* delete_from(Node* head, int pos) {
    if (pos == 1) {
        return delete_front(head);
    }
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }
    if (temp == nullptr || temp->next == nullptr) {
        cout << "Position out of bounds!" << endl;
        return head;
    }
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
    return head;
}

int count_total(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    cout << "Total members: " << count << endl;
    return count;
}

Node* concatenate(Node* head1, Node* head2) {
    if (head1 == nullptr) {
        return head2;
    }
    if (head2 == nullptr) {
        return head1;
    }
    Node* temp = head1;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}

void print_LL(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << "PRN: " << temp->prn << ", Name: " << temp->name << endl;
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int ch;

    while (true) {
        cout << "Choose Operation: \n1. Add member in the list \n2. Delete member from list \n3. Count total members in the list \n4. Concatenate lists of both divisions \n5. Exit" << endl;
        cin >> ch;
        switch (ch) {
            case 1: {
                int c1;
                cout << "Choose Operation \n1. Add president \n2. Add secretary \n3. Add a member" << endl;
                cin >> c1;
                string prn, name;
                switch (c1) {
                    case 1:
                        cout << "Enter PRN and name of president to be added: " << endl;
                        cin >> prn >> name;
                        head = insert_front(head, prn, name);
                        break;
                    case 2:
                        cout << "Enter PRN and name of secretary to be added: " << endl;
                        cin >> prn >> name;
                        head = insert_back(head, prn, name);
                        break;
                    case 3: {
                        cout << "Enter PRN and name of member to be added" << endl;
                        cin >> prn >> name;
                        int pos;
                        cout << "Enter position to insert in the list: " << endl;
                        cin >> pos;
                        head = insert_at(head, prn, name, pos);
                        break;
                    }
                    default:
                        cout << "Invalid option!" << endl;
                }
                print_LL(head);
                break;
            }

            case 2: {
                int c2;
                cout << "Choose Operation \n1. Delete president \n2. Delete secretary \n3. Delete a member by position" << endl;
                cin >> c2;
                switch (c2) {
                    case 1:
                        head = delete_front(head);
                        break;
                    case 2:
                        head = delete_back(head);
                        break;
                    case 3: {
                        int pos;
                        cout << "Enter position to delete from the list: " << endl;
                        cin >> pos;
                        head = delete_from(head, pos);
                        break;
                    }
                    default:
                        cout << "Invalid option!" << endl;
                }
                print_LL(head);
                break;
            }

            case 3:
                count_total(head);
                break;

            case 4: {
                Node* head2 = nullptr;
                cout << "Enter PRN and names for the second list (type 'done' to stop): " << endl;
                while (true) {
                    string prn, name;
                    cin >> prn;
                    if (prn == "done") break;
                    cin >> name;
                    head2 = insert_back(head2, prn, name);
                }
                head = concatenate(head, head2);
                print_LL(head);
                break;
            }

            case 5:
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
