#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
	repo = std::make_shared<Repo>();
	currentAdmin = std::make_shared<StudioAdministrator>("Jon", "Doe");
	defaultReceptionist = std::make_shared<Receptionist>("Paul", "Big");
	currentClient = std::make_shared<Client>("Max", "Sur", "max.test334@test.com");

    if (repo->receptionists.empty()) {
        repo->saveReceptionist(defaultReceptionist);
    }
    if (repo->photographers.empty()) {
        auto initialPhotographer = std::make_shared<Photographer>("Ann", "Smith");
        repo->savePhotographer(initialPhotographer);
    }

    if (repo->clients.empty()) {
        repo->saveClient(currentClient);
    }

	stackedWidget = new QStackedWidget(this);
	setCentralWidget(stackedWidget);

	createLoginPage();
	createAdminPage();
	createClientPage();
	createReceptionistPage();
    createPhotographerPage();

	stackedWidget->addWidget(loginPage);
	stackedWidget->addWidget(adminPage);
	stackedWidget->addWidget(clientPage);
	stackedWidget->addWidget(receptionistPage);
    stackedWidget->addWidget(photographerPage);

	stackedWidget->setCurrentIndex(0);
	resize(700, 500);
}

MainWindow::~MainWindow() {

}

void MainWindow::createLoginPage() {
    loginPage = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(loginPage);

    QLabel* welcomeLabel = new QLabel("<h2>Photo Studio Portal Hub</h2>", loginPage);
    welcomeLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(welcomeLabel);

    QGroupBox* clientGroup = new QGroupBox("Client Portal Access", loginPage);
    QVBoxLayout* clientLayout = new QVBoxLayout(clientGroup);

    clientLoginEmailInput = new QLineEdit(loginPage);
    clientLoginEmailInput->setPlaceholderText("Enter registered Email to access dashboard...");
    QPushButton* clientLoginButton = new QPushButton("Verify & Sign In", loginPage);

    clientLayout->addWidget(clientLoginEmailInput);
    clientLayout->addWidget(clientLoginButton);
    layout->addWidget(clientGroup);

    QHBoxLayout* staffLayout = new QHBoxLayout();
    QPushButton* adminLoginButton = new QPushButton("Staff: Admin Dashboard", loginPage);
    QPushButton* recepLoginButton = new QPushButton("Staff: Receptionist Area", loginPage);
    QPushButton* photoLoginButton = new QPushButton("Staff: Photographer Workbench", loginPage);
    staffLayout->addWidget(adminLoginButton);
    staffLayout->addWidget(recepLoginButton);
    staffLayout->addWidget(photoLoginButton);
    layout->addLayout(staffLayout);

    QGroupBox* regGroup = new QGroupBox("New Client? Register Profiler Here", loginPage);
    QHBoxLayout* regLayout = new QHBoxLayout(regGroup);
    clientRegNameInput = new QLineEdit(loginPage); clientRegNameInput->setPlaceholderText("First Name");
    clientRegSurnameInput = new QLineEdit(loginPage); clientRegSurnameInput->setPlaceholderText("Last Name");
    clientRegEmailInput = new QLineEdit(loginPage); clientRegEmailInput->setPlaceholderText("Email Addr");
    QPushButton* btnRegister = new QPushButton("Create Account", loginPage);
    regLayout->addWidget(clientRegNameInput);
    regLayout->addWidget(clientRegSurnameInput);
    regLayout->addWidget(clientRegEmailInput);
    regLayout->addWidget(btnRegister);
    layout->addWidget(regGroup);

    QPushButton* exitButton = new QPushButton("Exit Application", loginPage);
    exitButton->setStyleSheet("color: #b22222; font-weight: bold;");
    layout->addWidget(exitButton);

    connect(adminLoginButton, &QPushButton::clicked, this, &MainWindow::loginAsAdmin);
    connect(recepLoginButton, &QPushButton::clicked, this, &MainWindow::loginAsReceptionist);
    connect(photoLoginButton, &QPushButton::clicked, this, &MainWindow::loginAsPhotographer);
    connect(exitButton, &QPushButton::clicked, this, &MainWindow::handleExitApplication);

    connect(clientLoginButton, &QPushButton::clicked, this, &MainWindow::loginAsClient);
    connect(btnRegister, &QPushButton::clicked, this, &MainWindow::handleClientRegistration);
}

void MainWindow::createAdminPage() {
    adminPage = new QWidget();
    QVBoxLayout* mainLayout = new QVBoxLayout(adminPage);

    mainLayout->addWidget(new QLabel("<h3>--- ADMIN DASHBOARD ---</h3>"));

    QHBoxLayout* filterLayout = new QHBoxLayout();
    QPushButton* btnShowPh = new QPushButton("Show Photographers", adminPage);
    QPushButton* btnShowRec = new QPushButton("Show Receptionists", adminPage);
    QPushButton* btnShowCons = new QPushButton("Show Consumables", adminPage);
    filterLayout->addWidget(btnShowPh);
    filterLayout->addWidget(btnShowRec);
    filterLayout->addWidget(btnShowCons);
    mainLayout->addLayout(filterLayout);

    adminDataList = new QListWidget(adminPage);
    mainLayout->addWidget(adminDataList);
    adminInputName = new QLineEdit(adminPage);
    adminInputName->setPlaceholderText("Name / Item Designation");
    adminInputSurname = new QLineEdit(adminPage);
    adminInputSurname->setPlaceholderText("Surname (Leave blank for consumables)");
    adminInputConsumableQty = new QLineEdit(adminPage);
    adminInputConsumableQty->setPlaceholderText("Quantity (Consumables only)");
    adminInputConsumablePrice = new QLineEdit(adminPage);
    adminInputConsumablePrice->setPlaceholderText("Price (Consumables only)");

    mainLayout->addWidget(adminInputName);
    mainLayout->addWidget(adminInputSurname);
    mainLayout->addWidget(adminInputConsumableQty);
    mainLayout->addWidget(adminInputConsumablePrice);

    QHBoxLayout* actionsLayout = new QHBoxLayout();
    QPushButton* btnAddPh = new QPushButton("Add Photographer", adminPage);
    QPushButton* btnAddRec = new QPushButton("Add Receptionist", adminPage);
    QPushButton* btnAddCons = new QPushButton("Add Consumable", adminPage);
    actionsLayout->addWidget(btnAddPh);
    actionsLayout->addWidget(btnAddRec);
    actionsLayout->addWidget(btnAddCons);
    mainLayout->addLayout(actionsLayout);

    QFrame* divider = new QFrame(adminPage);
    divider->setFrameShape(QFrame::HLine);
    divider->setFrameShadow(QFrame::Sunken);
    mainLayout->addWidget(divider);

    createReportViewSection(mainLayout);

    QPushButton* btnBack = new QPushButton("Back to Main Menu", adminPage);
    mainLayout->addWidget(btnBack);

    connect(btnShowPh, &QPushButton::clicked, [this]() { populateAdminList(1); });
    connect(btnShowRec, &QPushButton::clicked, [this]() { populateAdminList(2); });
    connect(btnShowCons, &QPushButton::clicked, [this]() { populateAdminList(3); });
    connect(btnAddPh, &QPushButton::clicked, this, &MainWindow::handleAdminAddPhotographer);
    connect(btnAddRec, &QPushButton::clicked, this, &MainWindow::handleAdminAddReceptionist);
    connect(btnAddCons, &QPushButton::clicked, this, &MainWindow::handleAdminAddConsumable);
    connect(btnBack, &QPushButton::clicked, this, &MainWindow::navigateToMainMenu);
}

void MainWindow::createReportViewSection(QVBoxLayout* parentLayout) {
    parentLayout->addWidget(new QLabel("<h4>Studio Performance Reports Ledger</h4>"));

    adminReportList = new QListWidget(adminPage);
    adminReportList->setMaximumHeight(120);
    parentLayout->addWidget(adminReportList);

    QHBoxLayout* reportGenLayout = new QHBoxLayout();
    adminInputReportDesc = new QLineEdit(adminPage);
    adminInputReportDesc->setPlaceholderText("Enter new log summary or performance metrics descriptive text...");

    QPushButton* btnGenReport = new QPushButton("Compile & Save Report", adminPage);

    reportGenLayout->addWidget(adminInputReportDesc, 3);
    reportGenLayout->addWidget(btnGenReport, 1);
    parentLayout->addLayout(reportGenLayout);

    connect(btnGenReport, &QPushButton::clicked, this, &MainWindow::handleAdminCreateReport);
}

void MainWindow::createPhotographerPage() {
    photographerPage = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(photographerPage);

    layout->addWidget(new QLabel("<h3>--- PHOTOGRAPHER WORKBENCH ---</h3>"));
    layout->addWidget(new QLabel("Active Assignment Orders Ledger:"));

    photographerOrdersList = new QListWidget(photographerPage);
    layout->addWidget(photographerOrdersList);

    QHBoxLayout* completeLayout = new QHBoxLayout();
    orderIdToCompleteInput = new QLineEdit(photographerPage);
    orderIdToCompleteInput->setPlaceholderText("Enter Order ID to Mark Complete");

    QPushButton* btnFinishOrder = new QPushButton("Complete Assignment", photographerPage);
    completeLayout->addWidget(orderIdToCompleteInput);
    completeLayout->addWidget(btnFinishOrder);
    layout->addLayout(completeLayout);

    QPushButton* btnBack = new QPushButton("Back to Main Menu", photographerPage);
    layout->addWidget(btnBack);

    connect(btnFinishOrder, &QPushButton::clicked, this, &MainWindow::handlePhotographerComplete);
    connect(btnBack, &QPushButton::clicked, this, &MainWindow::navigateToMainMenu);
}

void MainWindow::createClientPage() {
    clientPage = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(clientPage);

    layout->addWidget(new QLabel("<h3>--- CLIENT ORDER CREATION ---</h3>"));

    orderDescriptionInput = new QLineEdit(clientPage);
    orderDescriptionInput->setPlaceholderText("Order Description");
    layout->addWidget(orderDescriptionInput);

    layout->addWidget(new QLabel("Deadline Date Fields:"));
    QHBoxLayout* dateLayout = new QHBoxLayout();
    orderDateYear = new QLineEdit(clientPage); orderDateYear->setPlaceholderText("YYYY");
    orderDateMonth = new QLineEdit(clientPage); orderDateMonth->setPlaceholderText("MM");
    orderDateDay = new QLineEdit(clientPage); orderDateDay->setPlaceholderText("DD");
    dateLayout->addWidget(orderDateYear);
    dateLayout->addWidget(orderDateMonth);
    dateLayout->addWidget(orderDateDay);
    layout->addLayout(dateLayout);

    orderTypeCombo = new QComboBox(clientPage);
    orderTypeCombo->addItem("Photo Printing Selection", 1);
    orderTypeCombo->addItem("Film Developing Selection", 2);
    layout->addWidget(orderTypeCombo);

    orderSpecInput = new QLineEdit(clientPage);
    orderSpecInput->setPlaceholderText("Specification Metric (Photo Size in cm / Film Length)");
    layout->addWidget(orderSpecInput);

    layout->addWidget(new QLabel("Select Preferred Settlement Method:"));
    paymentModeCombo = new QComboBox(clientPage);
    paymentModeCombo->addItem("Pay Instantly via Credit Card", 0);
    paymentModeCombo->addItem("Pay Later at Reception via Cash", 1);
    layout->addWidget(paymentModeCombo);

    QPushButton* btnSubmitOrder = new QPushButton("Submit and Pay Order", clientPage);
    QPushButton* btnBack = new QPushButton("Back to Main Menu", clientPage);
    layout->addWidget(btnSubmitOrder);
    layout->addWidget(btnBack);

    connect(btnSubmitOrder, &QPushButton::clicked, this, &MainWindow::handleClientCreateOrder);
    connect(btnBack, &QPushButton::clicked, this, &MainWindow::navigateToMainMenu);
}

void MainWindow::createReceptionistPage() {
    receptionistPage = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(receptionistPage);

    layout->addWidget(new QLabel("<h3>--- RECEPTIONIST AREA ---</h3>"));

    QHBoxLayout* toggleLayout = new QHBoxLayout();
    QPushButton* btnOrders = new QPushButton("View Orders Ledger", receptionistPage);
    QPushButton* btnClients = new QPushButton("View Client Matrix", receptionistPage);
    QPushButton* btnTrans = new QPushButton("View Transaction Audits", receptionistPage);
    toggleLayout->addWidget(btnOrders);
    toggleLayout->addWidget(btnClients);
    toggleLayout->addWidget(btnTrans);
    layout->addLayout(toggleLayout);

    receptionistDataList = new QListWidget(receptionistPage);
    layout->addWidget(receptionistDataList);

    QPushButton* btnBack = new QPushButton("Back to Main Menu", receptionistPage);
    layout->addWidget(btnBack);

    connect(btnOrders, &QPushButton::clicked, [this]() { populateReceptionistList(1); });
    connect(btnClients, &QPushButton::clicked, [this]() { populateReceptionistList(2); });
    connect(btnTrans, &QPushButton::clicked, [this]() { populateReceptionistList(3); });
    connect(btnBack, &QPushButton::clicked, this, &MainWindow::navigateToMainMenu);
}
void MainWindow::loginAsAdmin() { stackedWidget->setCurrentIndex(1); populateAdminList(1); populateAdminReportsList();
}
void MainWindow::loginAsReceptionist() { stackedWidget->setCurrentIndex(3); populateReceptionistList(1); }
void MainWindow::loginAsPhotographer() { stackedWidget->setCurrentIndex(4); populatePhotographerOrdersList(); }
void MainWindow::navigateToMainMenu() { stackedWidget->setCurrentIndex(0); }
void MainWindow::loginAsClient() {
    QString inputEmail = clientLoginEmailInput->text().trimmed();
    if (inputEmail.isEmpty()) {
        QMessageBox::warning(this, "Input Required", "Please fill out your Email identifier token.");
        return;
    }
    bool userFound = false;
    {
        std::lock_guard<std::mutex> lock(repo->repoMutex);
        for (auto const& [id, clientProfile] : repo->clients) {
            if (clientProfile && clientProfile->getEmail() == inputEmail.toStdString()) {
                authenticatedClient = clientProfile;
                userFound = true;
                break;
            }
        }
    }
    if (userFound && authenticatedClient) {
        clientLoginEmailInput->clear();
        orderDescriptionInput->clear();
        stackedWidget->setCurrentIndex(2);
        QMessageBox::information(this, "Welcome Back", QString::fromStdString("Authenticated session for: " + authenticatedClient->toString()));
    }
    else {
        QMessageBox::critical(this, "Security Error", "No matched profile registry linked to this email address.");
    }
}

void MainWindow::populateAdminList(int displayMode) {
    adminDataList->clear();

    std::lock_guard<std::mutex> lock(repo->repoMutex);

    if (displayMode == 1) {
        for (auto const& [id, item] : repo->photographers) {
            adminDataList->addItem(QString::fromStdString("ID: " + std::to_string(id) + " | " + item->toString()));
        }
    }
    else if (displayMode == 2) {
        for (auto const& [id, item] : repo->receptionists) {
            adminDataList->addItem(QString::fromStdString("ID: " + std::to_string(id) + " | " + item->toString()));
        }
    }
    else if (displayMode == 3) {
        for (auto const& item : repo->consumables) {
            adminDataList->addItem(QString::fromStdString(item->toString() + " | Cost value: " + std::to_string(item->getPrice())));
        }
    }
}

void MainWindow::populatePhotographerOrdersList() {
    photographerOrdersList->clear();

    for (auto const& [id, item] : repo->orders) {
        if (item) {
            QString status = item->isFinished ? "[FINISHED]" : "[ACTIVE]";
            QString itemText = QString("ID: %1 %2 | %3")
                .arg(id)
                .arg(status)
                .arg(QString::fromStdString(item->toString()));

            photographerOrdersList->addItem(itemText);
        }
    }
}

void MainWindow::populateReceptionistList(int displayMode) {
    receptionistDataList->clear();

    std::lock_guard<std::mutex> lock(repo->repoMutex);

    if (displayMode == 1) {
        for (auto const& [id, item] : repo->orders) {
            receptionistDataList->addItem(QString::fromStdString("ID: " + std::to_string(id) + " | " + item->toString()));
        }
    }
    else if (displayMode == 2) {
        for (auto const& [id, item] : repo->clients) {
            receptionistDataList->addItem(QString::fromStdString("ID: " + std::to_string(id) + " | " + item->toString()));
        }
    }
    else if (displayMode == 3) {
        for (auto const& [id, item] : repo->transactions) {
            receptionistDataList->addItem(QString::fromStdString(item->toString()));
        }
    }
}

void MainWindow::populatePhotographerList(int displayMode) {
	photographerList->clear();
	for (auto const& [id, photographer] : repo->photographers) {
		if (photographer) {
			QString itemText = QString::fromStdString("ID: " + std::to_string(id) + " | " + photographer->toString());
			photographerList->addItem(itemText);
		}
	}
}

void MainWindow::handleAdminAddPhotographer() {
    QString name = adminInputName->text();
    QString surname = adminInputSurname->text();
    if (name.isEmpty() || surname.isEmpty()) {
        QMessageBox::warning(this, "Formatting Error", "Complete registration fields first.");
        return;
    }
    auto ph = std::make_shared<Photographer>(name.toStdString(), surname.toStdString());
    currentAdmin->recordphotographer(repo, ph);

    adminInputName->clear(); adminInputSurname->clear();
    populateAdminList(1);
}

void MainWindow::handleAdminAddReceptionist() {
    QString name = adminInputName->text();
    QString surname = adminInputSurname->text();
    if (name.isEmpty() || surname.isEmpty()) {
        QMessageBox::warning(this, "Formatting Error", "Complete registration fields first.");
        return;
    }
    auto rec = std::make_shared<Receptionist>(name.toStdString(), surname.toStdString());
    currentAdmin->recordreceptionist(repo, rec);

    adminInputName->clear(); adminInputSurname->clear();
    populateAdminList(2);
}

void MainWindow::handleAdminAddConsumable() {
    QString name = adminInputName->text();
    int qty = adminInputConsumableQty->text().toInt();
    int price = adminInputConsumablePrice->text().toInt();

    if (name.isEmpty() || qty <= 0 || price <= 0) {
        QMessageBox::warning(this, "Input Violation", "Ensure numeric fields contain accurate positive metrics.");
        return;
    }
    currentAdmin->createConsumable(repo, name.toStdString(), qty, price);

    adminInputName->clear(); adminInputConsumableQty->clear(); adminInputConsumablePrice->clear();
    populateAdminList(3);
}

void MainWindow::handleClientCreateOrder() {
    if (!authenticatedClient) {
        QMessageBox::critical(this, "Session Mismatch", "No client profile currently authenticated.");
        return;
    }

    std::string desc = orderDescriptionInput->text().toStdString();
    int year = orderDateYear->text().toInt();
    int month = orderDateMonth->text().toInt();
    int day = orderDateDay->text().toInt();
    int choice = orderTypeCombo->currentData().toInt();
    double specVal = orderSpecInput->text().toDouble();
    int chosenPayment = paymentModeCombo->currentData().toInt();

    if (desc.empty() || year < 2026 || month < 1 || month > 12 || day < 1 || day > 31) {
        QMessageBox::warning(this, "Validation Error", "Check descriptions and timeline boundaries.");
        return;
    }

    try {
        tm timeinfo = {};
        timeinfo.tm_year = year - 1900;
        timeinfo.tm_mon = month - 1;
        timeinfo.tm_mday = day;
        time_t deadline = mktime(&timeinfo);

        if (deadline == -1) throw std::runtime_error("Datetime construction fault.");
        std::string targetDate = std::to_string(deadline);

        std::shared_ptr<Order> newOrder;
        if (choice == 1) {
            newOrder = std::make_shared<PhotoPrinting>(desc, targetDate, specVal);
        }
        else {
            newOrder = std::make_shared<FilmDeveloping>(desc, targetDate, static_cast<int>(specVal));
        }

        defaultReceptionist->recordOrder(repo, newOrder);

        if (chosenPayment == 0) {
            authenticatedClient->payOrder(newOrder);
            defaultReceptionist->createTransaction(repo, authenticatedClient, newOrder, PayMode::card);
            QMessageBox::information(this, "Success", "Order recorded and settled via Instant Card processing!");
        }
        else {
            defaultReceptionist->createTransaction(repo, authenticatedClient, newOrder, PayMode::cash);
            QMessageBox::information(this, "Order Queued", "Order saved! Balance deferred to cash settlement at desk.");
        }
        orderDescriptionInput->clear();
        orderDateYear->clear(); orderDateMonth->clear(); orderDateDay->clear();
        orderSpecInput->clear();
    }
    catch (const std::exception& e) {
        QMessageBox::critical(this, "Execution Fault", e.what());
    }
}

void MainWindow::handlePhotographerComplete() {
    int id = orderIdToCompleteInput->text().toInt();
    bool success = false;
    {
        std::lock_guard<std::mutex> lock(repo->repoMutex);
        auto it = repo->orders.find(id);
        if (it != repo->orders.end() && it->second != nullptr) {
            it->second->isFinished = true;
            success = true;
        }
    }
    if (success) {
        QMessageBox::information(this, "Success", "Order status flipped to: Finished.");
        orderIdToCompleteInput->clear();
        if (stackedWidget->currentIndex() == 1) {
            populateAdminList(1);
        }
        else if (stackedWidget->currentIndex() == 4) {
            populatePhotographerOrdersList();
        }
    }
    else {
        QMessageBox::warning(this, "Lookup Mismatch", "Order profile tracking token not found.");
    }
}

void MainWindow::handleClientRegistration() {
    QString name = clientRegNameInput->text().trimmed();
    QString surname = clientRegSurnameInput->text().trimmed();
    QString email = clientRegEmailInput->text().trimmed();
    if (name.isEmpty() || surname.isEmpty() || email.isEmpty()) {
        QMessageBox::warning(this, "Profile Creation Error", "Please fill in all details for registry initialization.");
        return;
    }

    auto newClient = std::make_shared<Client>(name.toStdString(), surname.toStdString(), email.toStdString());

    {
        repo->saveClient(newClient);
    }
    QMessageBox::information(this, "Registration Success", "Profile verified! You can now log in using your email address.");
    clientRegNameInput->clear();
    clientRegSurnameInput->clear();
    clientRegEmailInput->clear();
}

void MainWindow::populateAdminReportsList() {
    adminReportList->clear();
    std::lock_guard<std::mutex> lock(repo->repoMutex);
    for (auto const& [id, reportItem] : repo->reports) {
        if (reportItem) {
            QString itemText = QString("Report ID: %1 | Details: %2")
                .arg(static_cast<int>(reportItem->getReportId()))
                .arg(QString::fromStdString(reportItem->getDescription()));
            adminReportList->addItem(itemText);
        }
    }
}

void MainWindow::handleAdminCreateReport() {
    QString description = adminInputReportDesc->text().trimmed();
    if (description.isEmpty()) {
        QMessageBox::warning(this, "Empty Payload", "Please fill out description summaries before archiving data log entries.");
        return;
    }
    int trackingId = 0;
    {
        std::lock_guard<std::mutex> lock(repo->repoMutex);
        trackingId = repo->counterrp;
    }
    auto newReport = std::make_shared<Report>(trackingId, description.toStdString());
    repo->saveReport(newReport);
    adminInputReportDesc->clear();
    populateAdminReportsList();
    QMessageBox::information(this, "System Logged", "Performance report compiled and synchronized successfully.");
}

void MainWindow::handleExitApplication() {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Exit Program", "Are you sure you want to close the management system?",
        QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        this->close();
    }
}