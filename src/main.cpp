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
    StudioAdministrator admin("Name", "Surname");
	Photographer photographer("Name2", "Surname2");

    int mainchoice;

    int choice;

    int admchoice;

    int recchoice;

    int phchoice;

    while (true) {
        cout << "\n=== PHOTO STUDIO MENU ===\n";
        cout << "1. Login as admin\n";
        cout << "2. Login as client\n";
        cout << "3. Login as receptionist\n";
        cout << "4. Login as photographer\n";
        cout << "Choose an option: ";
        cin >> mainchoice;

        //od
        if (mainchoice == 1) {
            cout << "1. Show Photographers\n";
            cout << "2. Show Receptionists\n";
            cout << "3. Add Receptionists\n";
            cout << "4. Add Photographers\n";
            cin >> admchoice;
            if (admchoice == 1) {
                cout << "\n--- PHOTOGRAPHERS ---\n";
                for (auto& p : repo.photographers) {
                    cout << p.second->toString() << endl;
                }
            }
            else if (admchoice == 2) {
                cout << "\n--- RECEPTIONISTS ---\n";
                for (auto& r : repo.receptionists) {
                    cout << r.second->toString() << endl;
                }
            }
            else if (admchoice == 3) {
                cout << "\n--- ADD RECEPTIONISTS ---\n";
                admin.createreceptionist(&repo);

            }
            else if (admchoice == 4) {
                cout << "\n--- ADD PHOTOGRAPHER ---\n";
				admin.createphotographer(&repo);
            }
            else {
                cout << "Invalid choice.\n";
            }
            //do
        }

        else if (mainchoice == 2) {
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
                    Transaction* trans = new Transaction(repo.counter, &client, order, card);
                    receptionist.createTransaction(&repo, &client, order, card);
                    cout << trans->toString() << endl;
                }
                else {
                    Transaction* trans = new Transaction(repo.counter, &client, order, cash);
                    receptionist.createTransaction(&repo, &client, order, cash);
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
        else if (mainchoice == 3) {
            cout << "1. Show Orders\n";
            cout << "2. Show Clients\n";
            cout << "3. Show Transactions\n";
            cin >> recchoice;

            //od
            if (recchoice == 1) {
                cout << "\n--- ORDERS ---\n";
                for (auto& o : repo.orders) {
                    cout << o.second->toString() << endl;
                }
            }
            else if (recchoice == 2) {
                cout << "\n--- CLIENTS ---\n";
                for (auto& c : repo.clients) {
                    cout << c.second->toString() << endl;
                }
            }
            else if (recchoice == 3) {
                cout << "\n--- TRANSACTIONS ---\n";
                for (auto& t : repo.transactions) {
                    cout << t.second->toString() << endl;
                }
            }
            else {
                cout << "Invalid choice.\n";
            }
            //do
        }
        else if (mainchoice == 4) {
            cout << "1. Show Orders\n";
            cout << "2. Finish Orders\n";
            cin >> phchoice;

            //od
            if (phchoice == 1) {
                cout << "\n--- ASSIGNED ORDERS ---\n";
                for (auto& o : repo.orders) {
                    cout << "ID: " << o.first << " | " << o.second->toString() << endl;
                }
            }
            else if (phchoice == 2) {
                int id;
                cout << "Enter Order ID to finish: ";
                cin >> id;

                if (repo.orders.find(id) != repo.orders.end()) {
                    repo.orders[id]->isFinished = true; 
                    cout << "Order marked as completed.\n";
                }
                else {
                    cout << "Order not found.\n";
                }
                //do
            }
            else {
                cout << "Invalid choice.\n";
            }
        }
    }

    return 0;
}
