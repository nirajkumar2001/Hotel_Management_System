#include <iostream>  
#include <strings.h>  
#include <conio.h>  
#define max 100  
using namespace std;  
// Here I Have created  Customer  class in which i have given the all the types of variable which i want to use // 
class Customer  
{  
public:  
    char name[100];  
    char address[100];  
    char phone[12];  
    char from_date[20];  
    char to_date[20];  
    float payment_advance;  
    int booking_id;  
};  
// here i have created room class in which i getting information about room type//
class Room  
{  
public:  
    char type;  
    char stype;  
    char ac;  
    int roomNumber;  
    int rent;  
    int status;  
    class Customer cust;  
    class Room addRoom(int);  
    void searchRoom(int);  
    void displayRoom(Room);  
};  
  
// Global Declarations  
class Room rooms[max];  
int count = 0;  
  
Room Room::addRoom(int rno)  
{  
    class Room room;  
    room.roomNumber = rno;  
    cout << "\t\tType AC/Non-AC (A/N) : ";  
    cin >> room.ac;  
    cout << "\t\tType Comfort (S/N) : ";  
    cin >> room.type;  
    cout << "\t\tType Size (B/S) : ";  
    cin >> room.stype;  
    cout << "\t\tDaily Rent : ";  
    cin >> room.rent;  
    room.status = 0;  
  
    cout << "\t\t Room Added Successfully!";  
    getch();  
    return room;  
}  
void Room::searchRoom(int rno)  
{  
    int i, found = 0;  
    for (i = 0; i < count; i++)  
    {  
        if (rooms[i].roomNumber == rno)  
        {  
            found = 1;  
            break;  
        }  
    }  
    if (found == 1)  
    {  
        cout << "Room Details\t\t"<<endl;  
        if (rooms[i].status == 1)  
        {  
            cout << "\t\tRoom is Reserved";  
        }  
        else  
        {  
            cout << "\t\tRoom is available"<<endl;  
        }  
        displayRoom(rooms[i]);  
        getch();  
    }  
    else  
    {  
        cout << "\t\tRoom not found";  
        getch();  
    }  
}  
  
void Room::displayRoom(Room tempRoom)  
{  
    cout << "\t\tRoom Number: \t" << tempRoom.roomNumber<<endl;  
    cout << "\t\tType AC/Non-AC (A/N) " << tempRoom.ac<<endl;  
    cout << "\t\tType Comfort (S/N) " << tempRoom.type<<endl;  
    cout << "\t\tType Size (B/S) " << tempRoom.stype<<endl;  
    cout << "\t\tRent: " << tempRoom.rent<<endl;  
}  
  
//  here i am created a hotel management class in which i add  functionality about the hotel management//
class TajHotel : protected Room  
{  
public:  
    void checkIn();  
    void getAvailRoom();  
    void searchCustomer(char *);  
    void checkOut(int);  
    void guestSummaryReport();  
};  
  
void TajHotel::guestSummaryReport()  
{  
  
    if (count == 0)  
    {  
        cout << "\t\t No Guest in Hotel !!";  
    }  
    for (int i = 0; i < count; i++)  
    {  
        if (rooms[i].status == 1)  
        {  
            cout << "\t\t Customer First Name : " << rooms[i].cust.name<<endl;  
            cout << "\t\t Room Number : " << rooms[i].roomNumber<<endl;  
            cout << "\t\t Address (only city) : " << rooms[i].cust.address<<endl;  
            cout << "\t\t Phone Number : " << rooms[i].cust.phone<<endl;  
            cout << "\t\t---------------------------------------";  
        }  
    }  
  
    getch();  
}  
  
//here the room  bookign process in done // 
void TajHotel::checkIn()  
{  
    int i, found = 0, rno;  
  
    class Room room;  
    cout << "\t\t Enter Room number : ";  
    cin >> rno;  
    for (i = 0; i < count; i++)  
    {  
        if (rooms[i].roomNumber == rno)  
        {  
            found = 1;  
            break;  
        }  
    }  
    if (found == 1)  
    {  
        if (rooms[i].status == 1)  
        {  
            cout << "\t\tRoom is already Booked";  
            getch();  
            return;  
        }  
  
        cout << "\t\tEnter booking id: ";  
        cin >> rooms[i].cust.booking_id;  
  
        cout << "\t\tEnter Customer Name (First Name): ";  
        cin >> rooms[i].cust.name;  
  
        cout << "\t\tEnter Address (only city): ";  
        cin >> rooms[i].cust.address;  
  
        cout << "\t\tEnter Phone: ";  
        cin >> rooms[i].cust.phone;  
  
        cout << "\t\tEnter From Date: ";  
        cin >> rooms[i].cust.from_date;  
  
        cout << "\t\tEnter to  Date: ";  
        cin >> rooms[i].cust.to_date;  
  
        cout << "\t\tEnter Advance Payment: ";  
        cin >> rooms[i].cust.payment_advance;  
  
        rooms[i].status = 1;  
  
        cout << "\t\t Customer Checked-in Successfully..";  
        getch();  
    }  
}  
  
// here we showing the list of the hotel rooms//
void TajHotel::getAvailRoom()  
{  
    int i, found = 0;  
    for (i = 0; i < count; i++)  
    {  
        if (rooms[i].status == 0)  
        {  
            displayRoom(rooms[i]);  
            cout << "\t\t Press enter for next room";  
            found = 1;  
            getch();  
        }  
    }  
    if (found == 0)  
    {  
        cout << "\t\t All rooms are reserved";  
        getch();  
    }  
}  
  
// in this function we see which person have booked the room   
void TajHotel::searchCustomer(char *pname)  
{  
    int i, found = 0;  
    for (i = 0; i < count; i++)  
    {  
        if (rooms[i].status == 1 && strcasecmp(rooms[i].cust.name, pname) == 0)  
        {  
            cout << "\t\t Customer Name: " << rooms[i].cust.name<<endl;  
            cout << "\t\t Room Number: " << rooms[i].roomNumber<<endl;  
  
            cout << "\t\t Press enter for next record";  
            found = 1;  
            getch();  
        }  
    }  
    if (found == 0)  
    {  
        cout << "\t\t  Person not found.";  
        getch();  
    }  
}  
  
// here we generate bill of the cousmoter for living in the hotel. 
void TajHotel::checkOut(int roomNum)  
{  
    int i, found = 0, days, rno;  
    float billAmount = 0;  
    for (i = 0; i < count; i++)  
    {  
        if (rooms[i].status == 1 && rooms[i].roomNumber == roomNum)  
        {  
            // rno = rooms[i].roomNumber;  
            found = 1;  
            // getch();  
            break;  
        }  
    }  
    if (found == 1)  
    {  
        cout << "\t\tEnter Number of Days:\t";  
        cin >> days;  
        billAmount = days * rooms[i].rent;  
  
        cout << "\t\t\t######## CheckOut Details of The Customer ########\t\t"<<endl;  
        cout << "\t\tCustomer Name : " << rooms[i].cust.name<<endl;  
        cout << "\t\tRoom Number : " << rooms[i].roomNumber<<endl;  
        cout << "\t\tAddress : " << rooms[i].cust.address<<endl;  
        cout << "\t\tPhone Number : " << rooms[i].cust.phone<<endl;  
        cout << "\t\tTotal Amount Due : " << billAmount << " /"<<endl;  
        cout << "\t\t Advance Payment done At The Time oF Check in: " << rooms[i].cust.payment_advance << " /"<<endl;  
        cout << "\t\t*** Total Payable Amount: " << billAmount - rooms[i].cust.payment_advance << "/ only"<<endl;  
  
        rooms[i].status = 0;  
    }  
    getch();  
}  
  
// managing rooms (adding and searching available rooms)  
void manageRooms()  
{  
    class Room room;  
    int opt, rno, i, flag = 0;  
    char ch;  
    do  
    {  
        system("cls");  
        cout << "\t\t\t Manage The Room" << endl;
        cout << "\t\t ------------------------------------" << endl;
        cout << "\t\t 1. Add Extra Room in Hotel" << endl;
        cout << "\t\t 2. Search Room" << endl;
        cout << "\t\t 3. Back to Main Menu" << endl;
        cout << "\t\t ------------------------------------" << endl;
        cout << "\t\t Enter your option Niraj: ";  
        cin >> opt;  
  
        // switch statement  
        switch (opt)  
        {  
        case 1:  
            cout << "\t\tEnter Room Number: ";  
            cin >> rno;  
            i = 0;  
            for (i = 0; i < count; i++)  
            {  
                if (rooms[i].roomNumber == rno)  
                {  
                    flag = 1;  
                }  
            }  
            if (flag == 1)  
            {  
                cout << "\t\tRoom Number is Available.\t\tPlease enter unique Number";  
                flag = 0;  
                getch();  
            }  
            else  
            {  
                rooms[count] = room.addRoom(rno);  
                count++;  
            }  
            break;  
        case 2:  
            cout << "\t\tEnter room number: ";  
            cin >> rno;  
            room.searchRoom(rno);  
            break;  
        case 3:  
            // nothing to do  
            break;  
        default:  
            cout << "\t\tPlease Enter correct option";  
            break;  
        }  
    } while (opt != 3);  
}  

int main()  
{  
    class TajHotel taj;  
    int i, j, opt, rno;  
    char ch;  
    char pname[100];  
  
    system("cls");  
  
    do  
    {  
        system("cls");  
        cout << "\t\t\t######## Welcome Niraj Kumar ########## "  <<endl;
        cout << "\t\t ------------------------------------" << endl;
        cout << "\t\t\t### Taj  Group Of Hotel ####" << endl;
        cout << "\t\t ------------------------------------" << endl;
        cout << "\t\t 1. Manage room" << endl;
        cout << "\t\t 2. Check-In room" << endl;
        cout << "\t\t 3. Available room" << endl;
        cout << "\t\t 4. Search Customer" << endl;
        cout << "\t\t 5. Check-Out room" << endl;
        cout << "\t\t 6. Guest summary" << endl;
        cout << "\t\t 7. Exit" << endl;
        cout << "\t\t ------------------------------------" << endl;
        cout << "\t\t Hello Niraj How Can  I Help You: ";  
        cin >> opt;  
        switch (opt)  
        {  
        case 1:  
            manageRooms();  
            break;  
        case 2:  
            if (count == 0)  
            {  
                cout << "\t\t ------------------------------------" << endl;
                cout << "\t\t No room available" << endl;
                cout << "\t\t ------------------------------------" << endl;
                cout << "\t\t Please add rooms First" << endl;
                getch();  
            }  
            else  
                taj.checkIn();  
            break;  
        case 3:  
            if (count == 0)  
            {  
                cout << "\t\t Rooms data is not available...Please add the rooms first.";
                getch();  
            }  
            else  
                taj.getAvailRoom();  
            break;  
        case 4:  
            if (count == 0)  
            {  
               cout << "\t\tRooms data is not available...Please add the rooms first.";
                getch();  
            }  
            else  
            {  
                cout << "Enter Customer Name: ";  
                cin >> pname;  
                taj.searchCustomer(pname);  
            }  
            break;  
        case 5:  
            if (count == 0)  
            {  
                cout << "\t\tRooms are not available.\t\tPlease add the rooms first.";  
                getch();  
            }  
            else  
            {  
                cout << "Enter Room Number : ";  
                cin >> rno;  
                taj.checkOut(rno);  
            }  
            break;  
        case 6:  
            taj.guestSummaryReport();  
            break;  
        case 7:  
            cout << "\t\t Thank You Niraj Kumar ";  
            break;  
        default:  
            cout << "\t\t Please Enter correct option";  
            break;  
        }  
    } while (opt != 7);  
  
    getch();  
}  
