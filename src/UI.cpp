#include "Ui.h"
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

UI::UI() {
}
UI::~UI() {
}

void UI::run() {
    auto repo = make_shared<Repo>();
    auto receptionist = make_shared<Receptionist>("Paul", "Big");
    auto client = make_shared<Client>("Max", "Sur", "max.test334@test.com");
    auto admin = make_shared<StudioAdministrator>("Jon", "Doe");
    auto photographer = make_shared<Photographer>("Ann", "Smith");
    admin->recordreceptionist(repo, receptionist);
    admin->recordphotographer(repo, photographer);
    receptionist->recordClient(repo, client);

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
        cout << "5. Exit program\n";
        cout << "Choose an option: ";
        if (!(cin >> mainchoice)) {
            cout << "Please enter a valid number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (mainchoice == 1) {
            cout << "1. Show Photographers\n";
            cout << "2. Show Receptionists\n";
            cout << "3. Add Receptionists\n";
            cout << "4. Add Photographers\n";
            cout << "5. Add Consumables\n";
            cout << "6. Remove Consumables\n";
            cin >> admchoice;
            admin->adminChoicehandler(repo, admchoice);
        }

        else if (mainchoice == 2) {
            string surname;

            cout << "Login using surname: \n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            getline(cin, surname);
            
            if(cin.fail()) {
                cout << "Input error. Please type in letters.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
			}

            std::shared_ptr<Client> currentClient = nullptr;

            currentClient = receptionist->findBySurname(repo, surname);

            if (currentClient == nullptr) {
                currentClient = receptionist->createClient(surname);
                receptionist->recordClient(repo, currentClient);
            }
            else {
                currentClient = receptionist->findBySurname(repo, surname);
            }

            cout << "1. Make Order\n";
            cout << "2. Show Orders\n";
            cout << "Choose an option: ";
            cin >> choice;

            if (choice == 1) {
                std::shared_ptr<Order> order = currentClient->createOrder();
				repo->saveOrder(order);

                int payChoice;
                cout << "\nChoose Payment Method:\n";
                cout << "1. Pay by Card (Now)\n";
                cout << "2. Cash during pickup\n";
                cout << "Option: ";
                cin >> payChoice;

                if (payChoice == 1) {
                    order->isPaid = true;
                    receptionist->createTransaction(repo, currentClient, order, card);
                    cout << "Order is payed by Card." << endl;
                }
                else {
                    receptionist->createTransaction(repo, currentClient, order, cash);
                    cout << "Order will be paid by Cash at pickup." << endl;
                }

                receptionist->recordOrder(repo, order);

                cout << "Order with id: " << order->orderId << " of price: " << order->getPrice() << " was created and saved.\n";


            }
            else if (choice == 2) {
                int id;
                cout << "Enter order id: ";
                cin >> id;
                if (cin.fail()) {
                    cout << "Input error. Please type in numbers.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }

                if (repo->orders.empty()) {
                    cout << "No orders yet.\n";
                }
                else {
                    receptionist->printOrderInfo(repo, id);
                }
            }
            else {
                cout << "Invalid choice.\n";
                continue;
            }
        }
        else if (mainchoice == 3) {
            receptionist->receptionistHandler(repo);
        }
        else if (mainchoice == 4) {
            cout << "1. Show Orders\n";
            cout << "2. Finish Orders\n";
            cin >> phchoice;
            if (cin.fail()) {
                cout << "Input error. Please type in numbers.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            photographer->PhotographerHandler(repo, phchoice);
            
        }
        else if (mainchoice == 5) {
            cout << "Exiting program...\n";
            break;
            }
        else {
            cout << "Invalid choice.\n";
            }
    }
}
