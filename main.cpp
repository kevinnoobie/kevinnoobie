#include <iostream>
using namespace std;

int main() {
    string pin = "1234"; // initial pin
    string puk = "5678"; // PUK code
    int trials = 0; // number of login trials
    
    cout << "Welcome!\n";
    
    while (true) {
        cout << "Enter your choice (1 = Change PIN, 2 = Login): ";
        int choice;
        cin >> choice;
        
        if (choice == 1) {
            cout << "Enter your current PIN: ";
            string current_pin;
            cin >> current_pin;
            
            if (current_pin == pin) {
                cout << "Enter your new PIN: ";
                cin >> pin;
                cout << "PIN changed successfully.\n";
            } else {
                cout << "Wrong PIN.\n";
            }
        } else if (choice == 2) {
            while (trials < 3) {
                cout << "Enter your PIN: ";
                string entered_pin;
                cin >> entered_pin;
                
                if (entered_pin == pin) {
                    cout << "Login successful.\n";
                    break;
                } else {
                    trials++;
                    if (trials < 3) {
                        cout << "Wrong PIN. Please try again.\n";
                    } else {
                        cout << "Blocked. Enter PUK code: ";
                        string entered_puk;
                        cin >> entered_puk;
                        
                        if (entered_puk == puk) {
                            cout << "PUK code correct. Enter your new PIN: ";
                            cin >> pin;
                            cout << "PIN changed successfully.\n";
                            trials = 0;
                            break;
                        } else {
                            cout << "Wrong PUK code. SIM card blocked.\n";
                            return 0;
                        }
                    }
                }
            }
            trials = 0;
        } else {
            cout << "Invalid choice.\n";
        }
    }
    
    return 0;
}

