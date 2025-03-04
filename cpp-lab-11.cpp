#include <bits/stdc++.h>
using namespace std;

void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void addItems(vector<string>& inventory) {
    string item;
    vector<string> items;

    cout << "Enter item name(s)(\"0\" to end input): " << endl;
    while (cin >> item && item != "0") {
        items.push_back(item);
    }
    copy(items.begin(), items.end(), back_inserter(inventory));
    clearInputBuffer();
}

void removeItems(vector<string>& inventory) {
    string item;

    cout << "Enter item name(s)(\"0\" to end input): " << endl;
    while (cin >> item && item != "0") {
        auto it = find(inventory.begin(), inventory.end(), item);
        if (it != inventory.end()) {
            inventory.erase(it);
            cout << "Item removed." << endl;
        }
        else {
            cout << "Item not found." << endl;
        }
    }
    clearInputBuffer();
}

void listItems(const vector<string>& inventory) {
    if (inventory.empty()) {
        cout << "Inventory is empty." << endl;
    }
    else {
        cout << "Items list: " << endl;
        for (size_t i = 0; i < inventory.size(); i++) {
            cout << i + 1 << ". " << inventory[i] << endl;
        }
    }
}

int main() {
    vector<string> inventory;
    string command;

    while (true) {
        cout << "Enter command(add/remove/list/exit):" << endl;
        cin >> command;

        if (command == "add") {
            addItems(inventory);
        }
        else if (command == "remove") {
            removeItems(inventory);
        }
        else if (command == "list") {
            listItems(inventory);
        }
        else if (command == "exit") {
            break;
        }
        else {
            cout << "Invalid command." << endl;
        }
    }
}