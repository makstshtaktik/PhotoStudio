#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>
#include <QLineEdit>
#include <QComboBox>
#include <qgroupbox.h>
#include <QMessageBox>
#include <memory>
#include <mutex>

#include "Repo.h"
#include "StudioAdministrator.h"
#include "Receptionist.h"
#include "Client.h"
#include "Photographer.h"
#include "PhotoPrinting.h"
#include "FilmDeveloping.h"
#include "Consumables.h"
#include "Report.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void loginAsAdmin();
    void loginAsClient();
    void loginAsReceptionist();
    void loginAsPhotographer();
    void navigateToMainMenu();
    void handleAdminAddPhotographer();
    void handleAdminAddReceptionist();
    void handleAdminAddConsumable();
    void handleClientCreateOrder();
    void handlePhotographerComplete();
    void handleClientRegistration();
    void handleExitApplication();
    void handleAdminCreateReport();

private:
    QStackedWidget* stackedWidget;


    QWidget* loginPage;
    QWidget* adminPage;
    QWidget* clientPage;
    QWidget* receptionistPage;
    QWidget* photographerPage; 

    QListWidget* adminDataList;
    QLineEdit* adminInputName;
    QLineEdit* adminInputSurname;
    QLineEdit* adminInputConsumableQty;
    QLineEdit* adminInputConsumablePrice;
    QListWidget* adminReportList;
    QLineEdit* adminInputReportDesc;

    QLineEdit* orderDescriptionInput;
    QLineEdit* orderDateYear;
    QLineEdit* orderDateMonth;
    QLineEdit* orderDateDay;
    QComboBox* orderTypeCombo;
    QLineEdit* orderSpecInput;

    QListWidget* receptionistDataList;

    QListWidget* photographerOrdersList;
    QListWidget* photographerList;
    QLineEdit* orderIdToCompleteInput;

    QLineEdit* clientLoginEmailInput;
    QLineEdit* clientRegNameInput;
    QLineEdit* clientRegSurnameInput;
    QLineEdit* clientRegEmailInput;

    QComboBox* paymentModeCombo;


    std::shared_ptr<Repo> repo;
    std::shared_ptr<StudioAdministrator> currentAdmin;
    std::shared_ptr<Receptionist> defaultReceptionist;
    std::shared_ptr<Client> currentClient;
    std::shared_ptr<Client> authenticatedClient;

    void createLoginPage();
    void createAdminPage();
    void createClientPage();
    void createReceptionistPage();
    void createPhotographerPage();

    void populateAdminList(int displayMode);
    void populateReceptionistList(int displayMode);
    void populatePhotographerOrdersList();
    void populatePhotographerList(int displayMode);
    void createReportViewSection(QVBoxLayout* parentLayout);
    void populateAdminReportsList();
};

#endif // MAINWINDOW_H