#include "Client.h"
#include "Order.h"
#include "Consumables.h"
#include "FilmDeveloping.h"
#include "Photographer.h"
#include "PhotoPrinting.h"
#include "Report.h"
#include "StudioAdministrator.h"
#include "Repo.h"
#include "Receptionist.h"
#include "Transaction.h"

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <limits>
#include <memory>

using namespace std;

int main() {
    Repo repo;
    Receptionist receptionist("Pavol", "Salaj");
    Client client("Maksym", "Tsyhypalo", "t.max@gmail.com");

    int choice;

    while (true) {
        cout << "\n=== PHOTO STUDIO MENU ===\n";
        cout << "1. Make Order\n";
        cout << "2. Show Orders\n";
        cout << "3. Exit Program\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) {
            string description;
            int year, month, day;

            cout << "Enter order description: ";
            cin >> description;

            cout << "Enter deadline (YYYY MM DD): ";
            cin >> year >> month >> day;

            //time conversion
            tm timeinfo = {};
            timeinfo.tm_year = year - 1900;   //1900
            timeinfo.tm_mon = month - 1;     //0-based
            timeinfo.tm_mday = day;

            time_t deadline = mktime(&timeinfo);
            string deadlineStr = to_string(deadline);

            Order* order = new Order(description, deadlineStr);

            int payChoice;
            cout << "\nChoose Payment Method:\n";
            cout << "1. Pay by Card (Now)\n";
            cout << "2. Cash during pickup\n";
            cout << "Option: ";
            cin >> payChoice;

            if (payChoice == 1) {
                order->isPaid = true;
                Transaction* trans = new Transaction(repo.counter, &client, order, "Card");
                cout << trans->toString() << endl;
            }
            else {
                Transaction* trans = new Transaction(repo.counter, &client, order, "Cash");
                cout << "Order will be paid by Cash at pickup." << endl;
            }

            receptionist.recordOrder(&repo, order);

            cout << "Order created and saved.\n";
        }
        else if (choice == 2) {
            cout << "\n--- ALL ORDERS ---\n";

            if (repo.orders.empty()) {
                cout << "No orders yet.\n";
            }
            else {
                for (auto& pair : repo.orders) {
                    cout << "Order ID: " << pair.first
                        << " | " << pair.second->toString() << "\n";
                }
            }
        }
        else if (choice == 3) {
            cout << "Exiting program...\n";
            break;
        }
        else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
