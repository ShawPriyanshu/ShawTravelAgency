#include<iostream>
#include<fstream>
#include<iomanip>
#include<windows.h>

using namespace std;

void menu();//main menu function prototype
string userName="Shaw2801";
string password="1234";
class ManageMenu
{
protected:
    
    string inputusername,inputpassword;
public:
   int choice;    
public:

        
    ManageMenu()
    {
        system("color 0B"); //change terminal color
        cout << "\n\n\n\n\n\n\n\n\n\t  Enter 1 to Continue as an Admin: ";
        cout << "\n\t  Enter 2 to change password: "<<endl;
        cout<<"\t";
        cin>>choice;
        system("CLS");
        if(choice==1){
        cout << "\n\n\n\n\n\n\n\n\n\t  Enter Your Name to Continue as an Admin: ";
        cin >> inputusername;
        cout << "\n\t  Enter Your Password to Continue as an Admin: ";
        cin >> inputpassword;
        if(inputusername.compare(userName)==0 && inputpassword.compare(password)==0)
        {
        system("CLS");
        menu(); //call to main function to load after executing the constructer
        }
        else{
            cout<<"\nPlease input correct credentials.Ridirecting to Previous Menu";
            Sleep(3000);
            system("CLS");
            ManageMenu();
        }
        }
        else{
                cout<<"\nEnter userId:";
                cin>>inputusername;
               cout<<"\nEnter old password:";
               cin>>inputpassword;
               cout<<"\nEnter New Password:";
               cin>>inputpassword;

               password=inputpassword;
               userName=inputusername;
               cout<<"\nPassword set Successfully!!";
               Sleep(1200);
               system("CLS");
               ManageMenu();
        }
    }

    ~ManageMenu(){} //de
};

class Customer
{
public:
    string name, gender, address;
    int age, menuBack;
    long long mobileNo;
    static int cusID;
    char display[999];

    void getDetails()
    {
        ofstream out("customersData.txt", ios::app); //open file using append mode to write customer details
        {
            cout << "\nEnter Customer ID: ";
            cin >> cusID;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter Mobile Number: ";
            cin >> mobileNo;
            cout << "Address: ";
            cin>>address;
            cout << "Gender: ";
            cin >> gender;
        }
        out << "\nCustomer ID: " << cusID << "\nName: " << name << "\nAge: " << age << "\nMobile Number: " << mobileNo << "\nAddress: " << address << "\nGender: " << gender << endl;
        out.close();
        cout << "\nSaved \nNOTE: We save your details record for future purposes.\n" << endl;
    }
    void showDetails() //function to show old customer records
    {
        ifstream in("customersData.txt");
        {
            if(!in)
            {
                cout << "File Error!" << endl;
            }
            while(!(in.eof()))
            {
                in.getline(display, 999);
                cout << display << endl;
            }
            in.close();
        }
    }
};

int Customer::cusID;

class Cabs
{
public:
    int cabChoice,userChoice;
    int kilometers;
    float cabCost;
    static float lastCabCost;
     int hireCab;

    void cabDetails()
    {
        cout << "We provie the fastest, safest, and smartest cab service arround the country" << endl;
        cout << "-----------Shaw Cabs-----------\n" << endl;
        cout << "1. For a Standard Cab - Rs.15 for 1KM" << endl;
        cout << "2. For a Luxury Cab - Rs.25 per 1KM" << endl;

        cout << "\nEnter 3 to continue or 4 to go back to MainMenu" << endl;
        cin>>userChoice;
        system("CLS");
        if(userChoice==3)
        {
        cout << "\nTo calculate the cost for your journey.." << endl;
        cout << "Enter which kind of cab you need: ";
        cin >> cabChoice;
        cout << "Enter Kilometers you have to travel: ";
        cin >> kilometers;

       

        if(cabChoice == 1){
            cabCost = kilometers * 15;
            cout << "\nYour tour will cost " << cabCost << " rupees for a standard cab" << endl;
            cout << "Press 1 to hire this cab: or ";
            cout << "Press 2 to select another cab: ";
            cin >> hireCab;
            system("CLS");
            if (hireCab == 1){
                lastCabCost = cabCost;
                cout << "\nYou have successfully hired standard cab" << endl;
                cout << "Goto Menu to take the receipt" << endl;
            }
            else if(hireCab == 2){
                cabDetails();
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                cabDetails();
            }
        }
        else if(cabChoice == 2){
            cabCost = kilometers * 25;
            cout << "\nYour tour will cost " << cabCost << " rupees for a luxury cab" << endl;
            cout << "Press 1 to hire this cab: or ";
            cout << "Press 2 to select another cab: ";
            cin >> hireCab;
            system("CLS");
            if (hireCab == 1){
                lastCabCost = cabCost;
                cout << "\nYou have successfully hired luxury cab" << endl;
                cout << "Goto Menu to take the receipt" << endl;
            }
            else if(hireCab == 2){
                cabDetails();
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                cabDetails();
            }
        }
        }
        else{
            cout << "Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }

        cout << "\nPress 1 to Redirect Main Menu: ";
        cin >> hireCab;
        system("CLS");
        if(hireCab == 1){
            menu();
        }
        else{
            menu();
        }
    }
};

float Cabs::lastCabCost;

class Booking
{
public:
    int choiceHotel;
    int packChoice1;
    int gotoMenu;
    int stateChoice;
    static float hotelCost;

    void hotels()
    {
        string hotelWB[] = {"JW Mariott", "ITC Royal Bengal", "Grand Hyatt","Ashoka","Centaur"};
        string hotelHP[] = {"Orchid Homes", "Sonappa", "Beas View","Manali Heights","Kullu Heights"};
        string hotelPB[] = {"Sai Shivir", "Grand Hyatt", "Amritsar Heights","Ashoka","Centaur"};
        string hotelDL[] = {"JW Mariott", "ITC Royal Delhi", "Grand Hyatt","Ashoka","Centaur"};
        string hotelBNG[] = {"JW Mariott", "ITC Royal Bangalore", "Grand Hyatt","Ashoka","Centaur"};
        string hotelKSH[] = {"Gulmarg Heights", "River View", "Paradise","Centaur","Cliff"};
        string hotelMB[] = {"Taj", "SeaBird", "Mannat View","Grand Heights","Centaur"};
        cout<<"Currently,We have collaborated with the hotels of the following regions:"<<endl;
        cout<<"1.West Bengal"<<endl;
        cout<<"2.Himachal Pradesh"<<endl;
        cout<<"3.Punjab"<<endl;
        cout<<"4.Delhi"<<endl;
        cout<<"5.Bangalore"<<endl;
        cout<<"6.Kashmir"<<endl;
        cout<<"7.Mumbai"<<endl;
        cout<<"Enter the corresponding number of the region you are travelling to or any other number to go to main menu:";
        cin>>stateChoice;
        if(stateChoice==1)
        {
            int days;
            
            for(int a = 0; a < 5; a++)
        {
            cout << (a+1) <<". Hotel " << hotelWB[a] << endl;
        }

        cout << "\nCurrently we have collaborated with above hotels!" << endl;

        cout << "Enter the corresponding number to see the details of the hotel or press any key to go back:";
        cin >> choiceHotel;

        system("CLS");
        
        if(choiceHotel == 1){
            cout << "-------WELCOME TO HOTEL JW Mariott-------\n" << endl;

            cout << "The Garden, food and beverage. Enjoy all you can drink, Stay cool and get chilled in the summer sun." << endl;

            cout << "Packages offered by JW Mariott:\n" << endl;

            cout << "1. Standard Pack" << endl;
            cout << "\tAll basic facilities you need just for: Rs.5000.00" << endl;
            cout << "2. Premium Pack" << endl;
            cout << "\tEnjoy Premium: Rs.15000.00" << endl;
            cout << "3. Luxury Pack" << endl;
            cout << "\tHave a luxury stay at JW Mariott: Rs.25000.00" << endl;


            cout << "\nPress another key to back or\nEnter Package number you want to book: ";
            cin >> packChoice1;
            cout<<"\nEnter number of days of stay:";
            cin>>days;
            if (packChoice1 == 1){
                hotelCost = 5000.00*days;
                cout << "\nYou have successfully booked Standard Pack " << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 2){
                hotelCost = 15000.00*days;
                cout << "\nYou have successfully booked Premium Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 3){
                hotelCost = 25000.00*days;
                cout << "\nYou have successfully booked Luxury Pack" << endl;
                cout << "Goto Menu to take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();

            }

            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else if(choiceHotel == 2){
            cout << "-------WELCOME TO HOTEL ITC Royal Bengal-------\n" << endl;

            cout << "Swimming Pool | Free WiFi | Family Rooms \n Fitness Center | Restaurant & Bar" << endl;

            cout << "Packages Offered by Us:\n" << endl;

            cout << "1. Family Pack" << endl;
            cout << "\t Rs.15000.00 for a day" << endl;
            cout << "2. Couple Pack" << endl;
            cout << "\t Rs.10000.00 for a day" << endl;
            cout << "3. Single Pack" << endl;
            cout << "\t 5000.00 for a day" << endl;

            cout << "\nPress another key to go back or\nEnter Package number you want to book: ";
            cin >> packChoice1;
             cout<<"\nEnter number of days of stay:";
             cin>>days;
            if (packChoice1 == 1){
                hotelCost = 15000.00*days;
                cout << "You have successfully booked Family Pack " << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 2){
                hotelCost = 10000.00*days;
                cout << "You have successfully booked Couple Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 3){
                hotelCost = 5000.00*days;
                cout << "You have successfully booked Single Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }

            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else if(choiceHotel == 3){
            cout << "-------WELCOME TO HOTEL Grand Hyatt-------\n" << endl;
            cout << "Set in tropical gardens on the banks of the Ganges river" << endl;
            cout << "Amazing offer in this summer: Rs.5000.00 for one day and one night!!!" << endl;

            cout << "\nPress another key to back or\nPress 1 to book this special package: ";
            cin >> packChoice1;
            cout<<"\nEnter number of days of stay:";
             cin>>days;
            if (packChoice1 == 1){
                hotelCost = 5000.00*days;
                cout << "You have successfully booked our Special Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else if(choiceHotel == 4){
            cout << "-------WELCOME TO HOTEL Ashoka-------\n" << endl;
            cout << "Located near the astonishing Howrah Bridge" << endl;
            cout << "Amazing offer in this summer: Rs.3000.00 for one day and one night!!!" << endl;

            cout << "\nPress another key to go back or\nPress 1 to book this special package: ";
            cin >> packChoice1;
           cout<<"\nEnter number of days of stay:";
             cin>>days;
            if (packChoice1 == 1){
                hotelCost = 3000.00*days;
                cout << "You have successfully booked our Special Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else if(choiceHotel == 5){
            cout << "-------WELCOME TO HOTEL Centaur-------\n" << endl;
            cout << "Located on the banks of river Hooghly with a relaxing river view" << endl;
            cout << "Amazing offer in this summer: Rs.4000.00 for one day and one night!!!" << endl;

            cout << "\nPress another key to back or\nPress 1 to book this special package: ";
            cin >> packChoice1;
             cout<<"\nEnter number of days of stay:";
             cin>>days;
            if (packChoice1 == 1){
                hotelCost = 4000.00*days;
                cout << "You have successfully booked our Special Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else{
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
        
    }
    else if(stateChoice==2)    //Orchid Homes", "Sonappa", "Beas View","Manali Heights","Kullu Heights
        {
            int days;
            for(int a = 0; a < 5; a++)
        {
            cout << (a+1) <<". Hotel " << hotelHP[a] << endl;
        }

        cout << "\nCurrently we have collaborated with above hotels!" << endl;

        cout << "Enter the corresponding number to see the details of the hotel or press any key to go back:";
        cin >> choiceHotel;

        system("CLS");

        if(choiceHotel == 1){
            cout << "-------WELCOME TO HOTEL Orchid Homes-------\n" << endl;

            cout << "The Garden, food and beverage. Enjoy all you can drink, Stay cool and get chilled in the summer sun." << endl;

            cout << "Packages offered by JW Mariott:\n" << endl;

            cout << "1. Standard Pack" << endl;
            cout << "\tAll basic facilities you need just for: Rs.5000.00" << endl;
            cout << "2. Premium Pack" << endl;
            cout << "\tEnjoy Premium: Rs.15000.00" << endl;
            cout << "3. Luxury Pack" << endl;
            cout << "\tHave a luxury stay at JW Mariott: Rs.25000.00" << endl;


            cout << "\nPress another key to back or\nEnter Package number you want to book: ";
            cin >> packChoice1;
            cout<<"\nEnter number of days of stay:";
            cin>> days;
            if (packChoice1 == 1){
                hotelCost = 5000.00*days;
                cout << "\nYou have successfully booked Standard Pack " << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 2){
                hotelCost = 15000.00*days;
                cout << "\nYou have successfully booked Premium Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 3){
                hotelCost = 25000.00*days;
                cout << "\nYou have successfully booked Luxury Pack" << endl;
                cout << "Goto Menu to take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();

            }

            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else if(choiceHotel == 2){
            cout << "-------WELCOME TO HOTEL Sonappa-------\n" << endl;

            cout << "Swimming Pool | Free WiFi | Family Rooms \n Fitness Center | Restaurant & Bar" << endl;

            cout << "Packages Offered by Us:\n" << endl;

            cout << "1. Family Pack" << endl;
            cout << "\t Rs.15000.00 for a day" << endl;
            cout << "2. Couple Pack" << endl;
            cout << "\t Rs.10000.00 for a day" << endl;
            cout << "3. Single Pack" << endl;
            cout << "\t 5000.00 for a day" << endl;

            cout << "\nPress another key to go back or\nEnter Package number you want to book: ";
            cin >> packChoice1;
             cout<<"\nEnter number of days of stay:";
             cin>>days;
            if (packChoice1 == 1){
                hotelCost = 15000.00*days;
                cout << "You have successfully booked Family Pack " << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 2){
                hotelCost = 10000.00*days;
                cout << "You have successfully booked Couple Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 3){
                hotelCost = 5000.00*days;
                cout << "You have successfully booked Single Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }

            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else if(choiceHotel == 3){
            cout << "-------WELCOME TO HOTEL BEAS VIEW-------\n" << endl;
            cout << "Set in tropical gardens on the banks of the Ganges river" << endl;
            cout << "Amazing offer in this summer: Rs.5000.00 for one day and one night!!!" << endl;

            cout << "\nPress another key to back or\nPress 1 to book this special package: ";
            cin >> packChoice1;
            cout<<"\nEnter number of days of stay:";
             cin>>days;
            if (packChoice1 == 1){
                hotelCost = 5000.00*days;
                cout << "You have successfully booked our Special Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else if(choiceHotel == 4){
            cout << "-------WELCOME TO HOTEL Manali Heights-------\n" << endl;
            cout << "Located near the astonishing Howrah Bridge" << endl;
            cout << "Amazing offer in this summer: Rs.3000.00 for one day and one night!!!" << endl;

            cout << "\nPress another key to go back or\nPress 1 to book this special package: ";
            cin >> packChoice1;
             cout<<"\nEnter number of days of stay:";
             cin>>days;
            if (packChoice1 == 1){
                hotelCost = 3000.00*days;
                cout << "You have successfully booked our Special Pack" << endl;
                cout << "Goto*- Menu and take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else if(choiceHotel == 5){
            cout << "-------WELCOME TO HOTEL Kullu Heights-------\n" << endl;
            cout << "Located on the banks of river Hooghly with a relaxing river view" << endl;
            cout << "Amazing offer in this summer: Rs.4000.00 for one day and one night!!!" << endl;

            cout << "\nPress another key to back or\nPress 1 to book this special package: ";
            cin >> packChoice1;
            cout<<"\nEnter number of days of stay:";
             cin>>days;
            if (packChoice1 == 1){
                hotelCost = 4000.00*days;
                cout << "You have successfully booked our Special Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else{
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
        
    }
     else if(stateChoice==3)   //"Sai Shivir", "Grand Hyatt", "Amritsar Heights","Ashoka","Centaur"
        {
            int days;
            for(int a = 0; a < 5; a++)
        {
            cout << (a+1) <<". Hotel " << hotelPB[a] << endl;
        }

        cout << "\nCurrently we have collaborated with above hotels!" << endl;

        cout << "Enter the corresponding number to see the details of the hotel or press any key to go back:";
        cin >> choiceHotel;

        system("CLS");

        if(choiceHotel == 1){
            cout << "-------WELCOME TO HOTEL Sai Shivir-------\n" << endl;

            cout << "The Garden, food and beverage. Enjoy all you can drink, Stay cool and get chilled in the summer sun." << endl;

            cout << "Packages offered by JW Mariott:\n" << endl;

            cout << "1. Standard Pack" << endl;
            cout << "\tAll basic facilities you need just for: Rs.5000.00" << endl;
            cout << "2. Premium Pack" << endl;
            cout << "\tEnjoy Premium: Rs.15000.00" << endl;
            cout << "3. Luxury Pack" << endl;
            cout << "\tHave a luxury stay at JW Mariott: Rs.25000.00" << endl;


            cout << "\nPress another key to back or\nEnter Package number you want to book: ";
            cin >> packChoice1;
            cout<<"\nEnter number of days of stay:";
            cin>>days;
            if (packChoice1 == 1){
                hotelCost = 5000.00*days;
                cout << "\nYou have successfully booked Standard Pack " << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 2){
                hotelCost = 15000.00*days;
                cout << "\nYou have successfully booked Premium Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 3){
                hotelCost = 25000.00*days;
                cout << "\nYou have successfully booked Luxury Pack" << endl;
                cout << "Goto Menu to take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();

            }

            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else if(choiceHotel == 2){
            cout << "-------WELCOME TO HOTEL Grand Hyatt-------\n" << endl;

            cout << "Swimming Pool | Free WiFi | Family Rooms \n Fitness Center | Restaurant & Bar" << endl;

            cout << "Packages Offered by Us:\n" << endl;

            cout << "1. Family Pack" << endl;
            cout << "\t Rs.15000.00 for a day" << endl;
            cout << "2. Couple Pack" << endl;
            cout << "\t Rs.10000.00 for a day" << endl;
            cout << "3. Single Pack" << endl;
            cout << "\t 5000.00 for a day" << endl;

            cout << "\nPress another key to go back or\nEnter Package number you want to book: ";
            cin >> packChoice1;
             cout<<"\nEnter number of days of stay:";
            cin>>days;
            if (packChoice1 == 1){
                hotelCost = 15000.00*days;
                cout << "You have successfully booked Family Pack " << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 2){
                hotelCost = 10000.00*days;
                cout << "You have successfully booked Couple Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 3){
                hotelCost = 5000.00*days;
                cout << "You have successfully booked Single Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }

            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else if(choiceHotel == 3){
            cout << "-------WELCOME TO HOTEL Amritsar Heights-------\n" << endl;
            cout << "Set in tropical gardens on the banks of the Ganges river" << endl;
            cout << "Amazing offer in this summer: Rs.5000.00 for one day and one night!!!" << endl;

            cout << "\nPress another key to back or\nPress 1 to book this special package: ";
            cin >> packChoice1;
            cout<<"\nEnter number of days of stay:";
            cin>>days;
            if (packChoice1 == 1){
                hotelCost = 5000.00*days;
                cout << "You have successfully booked our Special Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else if(choiceHotel == 4){
            cout << "-------WELCOME TO HOTEL Ashoka-------\n" << endl;
            cout << "Located near the astonishing Howrah Bridge" << endl;
            cout << "Amazing offer in this summer: Rs.3000.00 for one day and one night!!!" << endl;

            cout << "\nPress another key to go back or\nPress 1 to book this special package: ";
            cin >> packChoice1;
           cout<<"\nEnter number of days of stay:";
            cin>>days;
            if (packChoice1 == 1){
                hotelCost = 3000.00*days;
                cout << "You have successfully booked our Special Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else if(choiceHotel == 5){
            cout << "-------WELCOME TO HOTEL Centaur-------\n" << endl;
            cout << "Located on the banks of river Hooghly with a relaxing river view" << endl;
            cout << "Amazing offer in this summer: Rs.4000.00 for one day and one night!!!" << endl;

            cout << "\nPress another key to back or\nPress 1 to book this special package: ";
            cin >> packChoice1;
            cout<<"\nEnter number of days of stay:";
            cin>>days;
            if (packChoice1 == 1){
                hotelCost = 4000.00*days;
                cout << "You have successfully booked our Special Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else{
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
        
    }
      else if(stateChoice==4)   //"JW Mariott", "ITC Royal Delhi", "Grand Hyatt","Ashoka","Centaur"
        {
            int days;
            for(int a = 0; a < 5; a++)
        {
            cout << (a+1) <<". Hotel " << hotelDL[a] << endl;
        }

        cout << "\nCurrently we have collaborated with above hotels!" << endl;

        cout << "Enter the corresponding number to see the details of the hotel or press any key to go back:";
        cin >> choiceHotel;

        system("CLS");

        if(choiceHotel == 1){
            cout << "-------WELCOME TO HOTEL JW Mariott-------\n" << endl;

            cout << "The Garden, food and beverage. Enjoy all you can drink, Stay cool and get chilled in the summer sun." << endl;

            cout << "Packages offered by JW Mariott:\n" << endl;

            cout << "1. Standard Pack" << endl;
            cout << "\tAll basic facilities you need just for: Rs.5000.00" << endl;
            cout << "2. Premium Pack" << endl;
            cout << "\tEnjoy Premium: Rs.15000.00" << endl;
            cout << "3. Luxury Pack" << endl;
            cout << "\tHave a luxury stay at JW Mariott: Rs.25000.00" << endl;


            cout << "\nPress another key to back or\nEnter Package number you want to book: ";
            cin >> packChoice1;
            cout<<"\nEnter number of days of stay:";
            cin>>days;
            if (packChoice1 == 1){
                hotelCost = 5000.00*days;
                cout << "\nYou have successfully booked Standard Pack " << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 2){
                hotelCost = 15000.00*days;
                cout << "\nYou have successfully booked Premium Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 3){
                hotelCost = 25000.00*days;
                cout << "\nYou have successfully booked Luxury Pack" << endl;
                cout << "Goto Menu to take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();

            }

            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else if(choiceHotel == 3){
            cout << "-------WELCOME TO HOTEL Grand Hyatt-------\n" << endl;

            cout << "Swimming Pool | Free WiFi | Family Rooms \n Fitness Center | Restaurant & Bar" << endl;

            cout << "Packages Offered by Us:\n" << endl;

            cout << "1. Family Pack" << endl;
            cout << "\t Rs.15000.00 for a day" << endl;
            cout << "2. Couple Pack" << endl;
            cout << "\t Rs.10000.00 for a day" << endl;
            cout << "3. Single Pack" << endl;
            cout << "\t 5000.00 for a day" << endl;

            cout << "\nPress another key to go back or\nEnter Package number you want to book: ";
            cin >> packChoice1;
             cout<<"\nEnter number of days of stay:";
            cin>>days;
            if (packChoice1 == 1){
                hotelCost = 15000.00*days;
                cout << "You have successfully booked Family Pack " << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 2){
                hotelCost = 10000.00*days;
                cout << "You have successfully booked Couple Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 3){
                hotelCost = 5000.00*days;
                cout << "You have successfully booked Single Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }

            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else if(choiceHotel == 2){
            cout << "-------WELCOME TO HOTEL ITC ROYAL DELHI-------\n" << endl;
            cout << "Set in tropical gardens on the banks of the Ganges river" << endl;
            cout << "Amazing offer in this summer: Rs.5000.00 for one day and one night!!!" << endl;

            cout << "\nPress another key to back or\nPress 1 to book this special package: ";
            cin >> packChoice1;
            cout<<"\nEnter number of days of stay:";
            cin>>days;
            if (packChoice1 == 1){
                hotelCost = 5000.00*days;
                cout << "You have successfully booked our Special Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else if(choiceHotel == 4){
            cout << "-------WELCOME TO HOTEL Ashoka-------\n" << endl;
            cout << "Located near the astonishing Howrah Bridge" << endl;
            cout << "Amazing offer in this summer: Rs.3000.00 for one day and one night!!!" << endl;

            cout << "\nPress another key to go back or\nPress 1 to book this special package: ";
            cin >> packChoice1;
           cout<<"\nEnter number of days of stay:";
            cin>>days;
            if (packChoice1 == 1){
                hotelCost = 3000.00*days;
                cout << "You have successfully booked our Special Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else if(choiceHotel == 5){
            cout << "-------WELCOME TO HOTEL Centaur-------\n" << endl;
            cout << "Located on the banks of river Hooghly with a relaxing river view" << endl;
            cout << "Amazing offer in this summer: Rs.4000.00 for one day and one night!!!" << endl;

            cout << "\nPress another key to back or\nPress 1 to book this special package: ";
            cin >> packChoice1;
            cout<<"\nEnter number of days of stay:";
            cin>>days;
            if (packChoice1 == 1){
                hotelCost = 4000.00*days;
                cout << "You have successfully booked our Special Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else{
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
        
    }
      else if(stateChoice==5)   //"JW Mariott", "ITC Royal Bangalore", "Grand Hyatt","Ashoka","Centaur"
        {
            int days;
            for(int a = 0; a < 5; a++)
        {
            cout << (a+1) <<". Hotel " << hotelBNG[a] << endl;
        }

        cout << "\nCurrently we have collaborated with above hotels!" << endl;

        cout << "Enter the corresponding number to see the details of the hotel or press any key to go back:";
        cin >> choiceHotel;

        system("CLS");

        if(choiceHotel == 1){
            cout << "-------WELCOME TO HOTEL JW Mariott-------\n" << endl;

            cout << "The Garden, food and beverage. Enjoy all you can drink, Stay cool and get chilled in the summer sun." << endl;

            cout << "Packages offered by JW Mariott:\n" << endl;

            cout << "1. Standard Pack" << endl;
            cout << "\tAll basic facilities you need just for: Rs.5000.00" << endl;
            cout << "2. Premium Pack" << endl;
            cout << "\tEnjoy Premium: Rs.15000.00" << endl;
            cout << "3. Luxury Pack" << endl;
            cout << "\tHave a luxury stay at JW Mariott: Rs.25000.00" << endl;


            cout << "\nPress another key to back or\nEnter Package number you want to book: ";
            cin >> packChoice1;
            cout<<"\nEnter number of days of stay:";
            cin>>days;
            if (packChoice1 == 1){
                hotelCost = 5000.00*days;
                cout << "\nYou have successfully booked Standard Pack " << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 2){
                hotelCost = 15000.00*days;
                cout << "\nYou have successfully booked Premium Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 3){
                hotelCost = 25000.00*days;
                cout << "\nYou have successfully booked Luxury Pack" << endl;
                cout << "Goto Menu to take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();

            }

            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else if(choiceHotel == 3){
            cout << "-------WELCOME TO HOTEL Grand Hyatt-------\n" << endl;

            cout << "Swimming Pool | Free WiFi | Family Rooms \n Fitness Center | Restaurant & Bar" << endl;

            cout << "Packages Offered by Us:\n" << endl;

            cout << "1. Family Pack" << endl;
            cout << "\t Rs.15000.00 for a day" << endl;
            cout << "2. Couple Pack" << endl;
            cout << "\t Rs.10000.00 for a day" << endl;
            cout << "3. Single Pack" << endl;
            cout << "\t 5000.00 for a day" << endl;

            cout << "\nPress another key to go back or\nEnter Package number you want to book: ";
            cin >> packChoice1;
             cout<<"\nEnter number of days of stay:";
            cin>>days;
            if (packChoice1 == 1){
                hotelCost = 15000.00*days;
                cout << "You have successfully booked Family Pack " << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 2){
                hotelCost = 10000.00*days;
                cout << "You have successfully booked Couple Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 3){
                hotelCost = 5000.00*days;
                cout << "You have successfully booked Single Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }

            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else if(choiceHotel == 2){
            cout << "-------WELCOME TO HOTEL ITC ROYAL BANGALORE-------\n" << endl;
            cout << "Set in tropical gardens on the banks of the Ganges river" << endl;
            cout << "Amazing offer in this summer: Rs.5000.00 for one day and one night!!!" << endl;

            cout << "\nPress another key to back or\nPress 1 to book this special package: ";
            cin >> packChoice1;
            cout<<"\nEnter number of days of stay:";
            cin>>days;
            if (packChoice1 == 1){
                hotelCost = 5000.00*days;
                cout << "You have successfully booked our Special Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else if(choiceHotel == 4){
            cout << "-------WELCOME TO HOTEL Ashoka-------\n" << endl;
            cout << "Located near the astonishing Howrah Bridge" << endl;
            cout << "Amazing offer in this summer: Rs.3000.00 for one day and one night!!!" << endl;

            cout << "\nPress another key to go back or\nPress 1 to book this special package: ";
            cin >> packChoice1;
           cout<<"\nEnter number of days of stay:";
            cin>>days;
            if (packChoice1 == 1){
                hotelCost = 3000.00*days;
                cout << "You have successfully booked our Special Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else if(choiceHotel == 5){
            cout << "-------WELCOME TO HOTEL Centaur-------\n" << endl;
            cout << "Located on the banks of river Hooghly with a relaxing river view" << endl;
            cout << "Amazing offer in this summer: Rs.4000.00 for one day and one night!!!" << endl;

            cout << "\nPress another key to back or\nPress 1 to book this special package: ";
            cin >> packChoice1;
            cout<<"\nEnter number of days of stay:";
            cin>>days;
            if (packChoice1 == 1){
                hotelCost = 4000.00*days;
                cout << "You have successfully booked our Special Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else{
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
        
    }
      else if(stateChoice==6)   //"Gulmarg Heights", "River View", "Paradise","Centaur","Cliff"
        {
            int days;
            for(int a = 0; a < 5; a++)
        {
            cout << (a+1) <<". Hotel " << hotelKSH[a] << endl;
        }

        cout << "\nCurrently we have collaborated with above hotels!" << endl;

        cout << "Enter the corresponding number to see the details of the hotel or press any key to go back:";
        cin >> choiceHotel;

        system("CLS");

        if(choiceHotel == 1){
            cout << "-------WELCOME TO HOTEL Gulmarg Heights-------\n" << endl;

            cout << "The Garden, food and beverage. Enjoy all you can drink, Stay cool and get chilled in the summer sun." << endl;

            cout << "Packages offered by JW Mariott:\n" << endl;

            cout << "1. Standard Pack" << endl;
            cout << "\tAll basic facilities you need just for: Rs.5000.00" << endl;
            cout << "2. Premium Pack" << endl;
            cout << "\tEnjoy Premium: Rs.15000.00" << endl;
            cout << "3. Luxury Pack" << endl;
            cout << "\tHave a luxury stay at JW Mariott: Rs.25000.00" << endl;


            cout << "\nPress another key to back or\nEnter Package number you want to book: ";
            cin >> packChoice1;
            cout<<"\nEnter number of days of stay:";
            cin>>days;
            if (packChoice1 == 1){
                hotelCost = 5000.00*days;
                cout << "\nYou have successfully booked Standard Pack " << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 2){
                hotelCost = 15000.00*days;
                cout << "\nYou have successfully booked Premium Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 3){
                hotelCost = 25000.00*days;
                cout << "\nYou have successfully booked Luxury Pack" << endl;
                cout << "Goto Menu to take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();

            }

            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else if(choiceHotel == 2){
            cout << "-------WELCOME TO HOTEL River View-------\n" << endl;

            cout << "Swimming Pool | Free WiFi | Family Rooms \n Fitness Center | Restaurant & Bar" << endl;

            cout << "Packages Offered by Us:\n" << endl;

            cout << "1. Family Pack" << endl;
            cout << "\t Rs.15000.00 for a day" << endl;
            cout << "2. Couple Pack" << endl;
            cout << "\t Rs.10000.00 for a day" << endl;
            cout << "3. Single Pack" << endl;
            cout << "\t 5000.00 for a day" << endl;

            cout << "\nPress another key to go back or\nEnter Package number you want to book: ";
            cin >> packChoice1;
             cout<<"\nEnter number of days of stay:";
            cin>>days;
            if (packChoice1 == 1){
                hotelCost = 15000.00*days;
                cout << "You have successfully booked Family Pack " << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 2){
                hotelCost = 10000.00*days;
                cout << "You have successfully booked Couple Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 3){
                hotelCost = 5000.00*days;
                cout << "You have successfully booked Single Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }

            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else if(choiceHotel == 3){
            cout << "-------WELCOME TO HOTEL Paradise-------\n" << endl;
            cout << "Set in tropical gardens on the banks of the Ganges river" << endl;
            cout << "Amazing offer in this summer: Rs.5000.00 for one day and one night!!!" << endl;

            cout << "\nPress another key to back or\nPress 1 to book this special package: ";
            cin >> packChoice1;
            cout<<"\nEnter number of days of stay:";
            cin>>days;
            if (packChoice1 == 1){
                hotelCost = 5000.00*days;
                cout << "You have successfully booked our Special Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else if(choiceHotel == 4){
            cout << "-------WELCOME TO HOTEL Centaur-------\n" << endl;
            cout << "Located near the astonishing Howrah Bridge" << endl;
            cout << "Amazing offer in this summer: Rs.3000.00 for one day and one night!!!" << endl;

            cout << "\nPress another key to go back or\nPress 1 to book this special package: ";
            cin >> packChoice1;
           cout<<"\nEnter number of days of stay:";
            cin>>days;
            if (packChoice1 == 1){
                hotelCost = 3000.00*days;
                cout << "You have successfully booked our Special Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else if(choiceHotel == 5){
            cout << "-------WELCOME TO HOTEL Cliff-------\n" << endl;
            cout << "Located on the banks of river Hooghly with a relaxing river view" << endl;
            cout << "Amazing offer in this summer: Rs.4000.00 for one day and one night!!!" << endl;

            cout << "\nPress another key to back or\nPress 1 to book this special package: ";
            cin >> packChoice1;
            cout<<"\nEnter number of days of stay:";
            cin>>days;
            if (packChoice1 == 1){
                hotelCost = 4000.00*days;
                cout << "You have successfully booked our Special Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else{
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
        
    }
      else if(stateChoice==7)   //"Taj", "SeaBird", "Mannat View","Grand Heights","Centaur"
        {
            int days;
            for(int a = 0; a < 5; a++)
        {
            cout << (a+1) <<". Hotel " << hotelPB[a] << endl;
        }

        cout << "\nCurrently we have collaborated with above hotels!" << endl;

        cout << "Enter the corresponding number to see the details of the hotel or press any key to go back:";
        cin >> choiceHotel;

        system("CLS");

        if(choiceHotel == 1){
            cout << "-------WELCOME TO HOTEL Taj-------\n" << endl;

            cout << "The Garden, food and beverage. Enjoy all you can drink, Stay cool and get chilled in the summer sun." << endl;

            cout << "Packages offered by JW Mariott:\n" << endl;

            cout << "1. Standard Pack" << endl;
            cout << "\tAll basic facilities you need just for: Rs.5000.00" << endl;
            cout << "2. Premium Pack" << endl;
            cout << "\tEnjoy Premium: Rs.15000.00" << endl;
            cout << "3. Luxury Pack" << endl;
            cout << "\tHave a luxury stay at JW Mariott: Rs.25000.00" << endl;


            cout << "\nPress another key to back or\nEnter Package number you want to book: ";
            cin >> packChoice1;
            cout<<"\nEnter number of days of stay:";
            cin>>days;
            if (packChoice1 == 1){
                hotelCost = 5000.00*days;
                cout << "\nYou have successfully booked Standard Pack " << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 2){
                hotelCost = 15000.00*days;
                cout << "\nYou have successfully booked Premium Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 3){
                hotelCost = 25000.00*days;
                cout << "\nYou have successfully booked Luxury Pack" << endl;
                cout << "Goto Menu to take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();

            }

            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else if(choiceHotel == 2){
            cout << "-------WELCOME TO HOTEL SeaBird-------\n" << endl;

            cout << "Swimming Pool | Free WiFi | Family Rooms \n Fitness Center | Restaurant & Bar" << endl;

            cout << "Packages Offered by Us:\n" << endl;

            cout << "1. Family Pack" << endl;
            cout << "\t Rs.15000.00 for a day" << endl;
            cout << "2. Couple Pack" << endl;
            cout << "\t Rs.10000.00 for a day" << endl;
            cout << "3. Single Pack" << endl;
            cout << "\t 5000.00 for a day" << endl;

            cout << "\nPress another key to go back or\nEnter Package number you want to book: ";
            cin >> packChoice1;
             cout<<"\nEnter number of days of stay:";
            cin>>days;
            if (packChoice1 == 1){
                hotelCost = 15000.00*days;
                cout << "You have successfully booked Family Pack " << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 2){
                hotelCost = 10000.00*days;
                cout << "You have successfully booked Couple Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 3){
                hotelCost = 5000.00*days;
                cout << "You have successfully booked Single Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }

            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else if(choiceHotel == 3){
            cout << "-------WELCOME TO HOTEL Mannat View-------\n" << endl;
            cout << "Set in tropical gardens on the banks of the Ganges river" << endl;
            cout << "Amazing offer in this summer: Rs.5000.00 for one day and one night!!!" << endl;

            cout << "\nPress another key to back or\nPress 1 to book this special package: ";
            cin >> packChoice1;
            cout<<"\nEnter number of days of stay:";
            cin>>days;
            if (packChoice1 == 1){
                hotelCost = 5000.00*days;
                cout << "You have successfully booked our Special Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else if(choiceHotel == 4){
            cout << "-------WELCOME TO HOTEL Grand Heights-------\n" << endl;
            cout << "Located near the astonishing Howrah Bridge" << endl;
            cout << "Amazing offer in this summer: Rs.3000.00 for one day and one night!!!" << endl;

            cout << "\nPress another key to go back or\nPress 1 to book this special package: ";
            cin >> packChoice1;
           cout<<"\nEnter number of days of stay:";
            cin>>days;
            if (packChoice1 == 1){
                hotelCost = 3000.00*days;
                cout << "You have successfully booked our Special Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else if(choiceHotel == 5){
            cout << "-------WELCOME TO HOTEL Centaur-------\n" << endl;
            cout << "Located on the banks of river Hooghly with a relaxing river view" << endl;
            cout << "Amazing offer in this summer: Rs.4000.00 for one day and one night!!!" << endl;

            cout << "\nPress another key to back or\nPress 1 to book this special package: ";
            cin >> packChoice1;
            cout<<"\nEnter number of days of stay:";
            cin>>days;
            if (packChoice1 == 1){
                hotelCost = 4000.00*days;
                cout << "You have successfully booked our Special Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else{
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
        
    }
    else{
         cout << "Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();
    }
    }
};

float Booking::hotelCost;

class Charges : public Booking, Cabs, Customer //Multiple Inheritance of some other classes to Charges
{

public:

    void printBill()
    {
        ofstream outf("receipt.txt"); //to write out the data into receipt for bought items
        {
            outf << "--------Shaw Travel Agency--------" << endl;
            outf << "-------------Receipt-------------" << endl;
            outf << "_________________________________" << endl;

            outf << "Customer ID: " << Customer::cusID << endl << endl;
            outf << "Description\t\t Total" << endl;
            outf << "Hotel cost:\t\t " << fixed << setprecision(2) << Booking::hotelCost << endl;
            outf << "Travel (cab) cost:\t " << fixed << setprecision(2) << Cabs::lastCabCost << endl;

            outf << "_________________________________" << endl;
            outf << "Total Charge:\t\t " << fixed << setprecision(2) << Booking::hotelCost+Cabs::lastCabCost << endl;
            outf << "_________________________________" << endl;
            outf << "------------THANK YOU------------" << endl;
        }
        outf.close();
        
    }

    void showBill()
    {
        ifstream inf("receipt.txt");
        {
            if(!inf)
            {
                cout << "File Error!" << endl;
            }
            while(!(inf.eof()))
            {
                inf.getline(display, 999);
                cout << display << endl;
            }
        }
        inf.close();
    }
};

void menu() //menu function contain main menu
{

    int mainChoice;
    int inChoice;
    int added=0;
    int gotoMenu;
    cout << "\t\t      * Shaw Travels *\n" << endl;
    cout << "-------------------------Main Menu--------------------------" << endl;

    cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    
    cout << "\t|\tCustomer Management -> 1\t|" << endl;
    cout << "\t|\tCabs Management     -> 2\t|" << endl;
    cout << "\t|\tBookings Management -> 3\t|" << endl;
    cout << "\t|\tCharges & Bill      -> 4\t|" << endl;
    cout << "\t|\tExit                -> 5\t|" << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl;

    cout << "\nEnter Choice: ";
    cin >> mainChoice;

    system("CLS");

    Customer a2; //creating objects
    Cabs a3;
    Booking a4;
    Charges a5;

   
    if(mainChoice == 1){
        cout << "------Customers------\n" << endl;
        cout << "1. Enter New Customer"<< endl;
        cout << "2. See Old Customers"<< endl;

        cout << "\nEnter choice: ";
        cin >> inChoice;
        
        system("CLS");
        if(inChoice == 1){
            
            a2.getDetails();
        }
        else if(inChoice == 2){
            a2.showDetails();
        }
        else{
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
        cout << "Press 1 to Redirect Main Menu: ";
        cin >> gotoMenu;
        system("CLS");
        if(gotoMenu == 1){
            menu();
        }
        else{
            menu();
        }
    }
    else if(mainChoice == 2){
        a3.cabDetails();
    }
    else if(mainChoice == 3){
        cout << "--> Book a Luxury Hotel using the System <--\n" << endl;
        a4.hotels();
    }
    else if(mainChoice == 4){
        cout<<"Is new customer added? 1 for Yes and 0 for No: ";
        cin>>added;
        if(added==1)
        {
       
        cout << "-->Get your receipt<--\n" << endl;
        a5.printBill();
        cout << "Your receipt is already printed you can get it from file path\n" << endl;
        cout << "to display the your receipt in the screen, Enter 1:";
        cin >> gotoMenu;
        if(gotoMenu == 1){
            system("CLS");
            a5.showBill();
            cout << "Press 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else{
            system("CLS");
            menu();
        }
        
        }
        else{
            cout<<"\n\n\n\n\n\n\t\t\t--------------No Receipt available-------------------"<<endl;
            cout<<"\t\tPlease purchase any package before requesting for the bill"<<endl;
            cout<<"\n\t\tPress 1 to go to main menu:";
            cin>>gotoMenu;
            system("CLS");
            if(gotoMenu==1)
            menu();
            else
            menu();
        }
    }
    else if(mainChoice == 5){
        cout << "\n\n\t--GOOD-BYE!--" << endl;
        Sleep(1100);
        system("CLS");
        ManageMenu();
    }
    else{
        cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
        Sleep(1100);
        system("CLS");
        menu();
    }
}

int main()
{
    ManageMenu start;
    return 0;
}
