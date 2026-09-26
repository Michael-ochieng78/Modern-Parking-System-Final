#DATA STRUCTURES AND ALGORITHMS – TASK ONE
MODERN PARKING SYSTEM
1. Introduction
2. The Modern Parking System is designed to manage parking automatically. It allows drivers to see available spaces, register vehicles, get a parking space, calculate parking fees and make payments before leaving.
3. Algorithms
###A. Parking Availability
Start.
Check all parking spaces.
Count available spaces.
Display available spaces.
If available = 0
Display “Parking Full.”
Stop.
START
Check parking spaces
Count available spaces
IF available = 0
    Display "Parking Full"
ELSE
    Display available spaces
END IF
STOP
###B. Vehicle Registration
Enter vehicle registration number.
Check if the vehicle is already parked.
Check for an available space.
Record vehicle details and entry time.Assign a parking space.
START
Enter registration number
Check available space
IF no space
    Display "Parking Full"
ELSE
    Record vehicle
    Record entry time
    Assign parking space
END IF
STOP
###C. Parking Fee Calculation
START
Get parking duration

IF duration <= 30 minutes
    Fee = KSh 0
ELSE IF duration <= 2 hours
    Fee = KSh 50
ELSE IF duration <= 4 hours
    Fee = KSh 100
ELSE IF duration <= 6 hours
    Fee = KSh 300
ELSE
    Fee = KSh 500
END IF

Display fee
STOP
###D. Vehicle Exit
Find the vehicle record.
Record exit time.
Calculate parking duration.
Calculate the fee.
Check payment.
If payment is made, open the barrier.
Change the parking space to available.
Save the completed record.
##3. Data Structures
Data Structure
Use
Array
Store parking spaces
Structure
Store vehicle details
Queue
Manage vehicles waiting for spaces
Linked List
Store parking records
Hash Table
Find vehicles using registration numbers
Reasons
###Array: Easy to store and access parking spaces.
Structure: Keeps vehicle information together.
Queue: Uses First In, First Out for waiting vehicles.
Linked List: Allows parking records to grow as vehicles enter.
Hash Table: Allows quick vehicle searching.
##4. Database Design
A MySQL database can be used.

###Users
Field
user_id
name
email
phone
password
role

###Vehicles
Field
vehicle_id
registration_no
vehicle_type
owner_name
owner_phone
Parking Slots
Field
slot_id
slot_number
status
Parking Records
Field
record_id
vehicle_id
slot_id
entry_time
exit_time
duration
fee
status
Payments
Field
payment_id
record_id
amount
payment_method
payment_time
payment_status
##5. Database Relationships
VEHICLES
    |
    ↓
PARKING RECORDS
   / \
  ↓   ↓
SLOTS  PAYMENTS
A vehicle can have many parking records.
A parking record belongs to a vehicle.
A parking record uses a parking slot.
A parking record has payment information.
##6. System Flow
START
  ↓
Check Available Spaces
  ↓
Register Vehicle
  ↓
Assign Parking Space
  ↓
Record Entry Time
  ↓
Vehicle Parks
  ↓
Record Exit Time
  ↓
Calculate Duration
  ↓
Calculate Fee
  ↓
Make Payment
  ↓
Open Barrier
  ↓
Make Space Available
  ↓
Save Record
  ↓
END
###7. Functional Requirements
The system should:
Display available parking spaces.
Register vehicles.
Assign parking spaces.
Record entry and exit times.
Calculate parking duration.
Calculate parking fees.
Record payments.
Allow exit after payment.
Make spaces available after vehicles leave.
Generate parking reports.
###8. Non-Functional Requirements
Security: Protect user and payment information.
Reliability: Store accurate parking records.
Usability: Make the system easy to use.
Performance: Display information quickly.
Scalability: Allow more vehicles and spaces in the future.
###9. Proposed Technologies
Frontend: HTML, CSS and JavaScript
Backend: Python
Database: MySQL
HTML/CSS/JavaScript
        ↓
      Python
        ↓
      MySQL
##10. Conclusion
The Modern Parking System will make parking management easier by automating vehicle registration, parking-space allocation, time calculation, fee calculation and payment. It will also keep parking records in a database and make a parking space available again when a vehicle leaves.…
