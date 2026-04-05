# PhotoStudio
Advanced C/C++ photo studio project

System description:
Photo Studio project is a Management System in a console-based enviroment developed in C++.
This system is designed for small photography studio where orders, materials, staff are managed.
In many small companies making orders and keeping track of them takes most of the time from a working shift,
with this system we strife for cutting the corners and keeping data and track of them easy.
This system calculates pricing automatically based on urgency of the order. It stores orders in memory during runtime,
allowing the staff to review them later. This solution improves organisation and reduces human error.

Logic flow:
Program helps create an order for multiple clients depending on their surname as login,
for example if a new user chooses to login as client (surname not found) program will create new Client object 
where it will ask the user for additional information such as Name and Email, with these information
program will be able to record new Client as an object and therefor use it for creating orders.
Creating orders is simple, login as client choose "make order" write description, time, payment method and then its created.
Now Receptionist after login is able to look at transactions and orders and clients.
But Photographer is the one who needs to take the photos so he is responsible for finishing the orders.
at the end they should automatically report material usage to the admnisitrator.
Administrator can Add/Show each object except order.

System Entities
Admin- system administrator
Client- customer which places order with its description
Receptionist- we record orders as this entity
Photographer- responsible for taking out order
Order- main object
Transaction- transaction object
Consumables- object with which we track inventory
Also other smaller suportive entities are present.

Main Scenario:
1. 	We run the program
2. 	Program welcomes us with 4 login options (Admin,Client,Receptionist,Photographer)
3. 	We input number 2 for Client
4. 	Program requests our surname
5. 	We input "Sur"
6. 	Program shows us multiple options for Order (Make ,Show)
7. 	We choose "Make Order"
8. 	Program ask us for order description and later date and payment method
9. 	We fill out everything but choose todays date (for urgency example)
10.	Program shows us cost of the order
11.	Now we login as Photographer
12.	Program offers two options for Order (Show, Finish)
13.	We choose "Show orders"
14. Program showed us all orders
15. We run back to the previous point and choose "Finish Orders"
16.	Program asks us to provide ID of the order we want to finish
17. We input 0
18. Program declares Order as finished
19. We then choose "Login as Admin" 
20. Program offers us multiple choices again
21. We choose //TBA

