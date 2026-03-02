# PhotoStudio
Advanced C/C++ photo studio project

Problem Description:
Photo Studio project is a Management System in a console-based enviroment developed in C++.
This system is designed for small photography studio where stuff must manage orders, payment and material usage.
In many small companies making orders and keeping track of them takes most of the time from a working shift,
with this system we strife for cutting the corners and keeping data and track of them easy.
This system calculates pricing automatically based on deadlines and urgency rules. It stores orders in memory during runtime,
allowing the staff to review them later.
This solution improves organisation and reduces human error also demonstrates proper layered software architecture.

System Purpose:
Purpose of the system is to make work easier by making orders, applying pricing rules and storing them in memory.
Keeping track of materials for easier inventory observation.
The System demonstrates separation between UI, business logic and Repository.

Main Use Case:
The main use case is creating and storing a customer order. 
The user selects the "Make Order" option in the console menu, 
enters the order description and deadline, 
and selects a payment method. 
The system calculates the order price based on whether the deadline makes the order urgent. 
If payment by card is selected, a transaction is created immediately otherwise customer can pay during pickup. 
The order object is then stored in the repository, and the system state is updated. 
The user can later select "Show Orders" to display all stored orders.

System Entities
Client-Represents a customer
Order-Represents the main business object
Transaction-Represents a payment exchange

Also other suportive entities are present.

Main System Algorithm:
1. User selects command in UI menu
2. UI reads required input values
3. UI sends input to Logic Layer
4. Logic Layer validates input
5. Logic Layer checks business rules
6. Logic Layer requests data from Repository
7. Logic Layer creates or updates objects
8. Repository stores updated data
9. Logic Layer returns result
10. UI prints result to user
