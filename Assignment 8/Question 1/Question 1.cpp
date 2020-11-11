//Written by Eddy Zhou
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>


const int DATA_COLUMNS = 2, PARKING_SPOTS = 50, FACULTY_COLUMN = 1, NAME_COLUMN = 0, 
    FACULTY_CUTOFF = 25, OUT_OF_SPOTS = 999;
const std::string CHANGE_STATUS = "0";

//B. writes onto data array the data from parking_current.txt
void writeParkingData(std::string parkingData[PARKING_SPOTS][DATA_COLUMNS], 
    std::string& name, std::string& faculty, int& spot, std::ifstream& parkCurrent) 
{
    while (parkCurrent >> faculty) 
    {
        parkCurrent >> name;
        parkCurrent >> spot;
        spot = spot - 1;
        parkingData[spot][NAME_COLUMN] = name;
        parkingData[spot][FACULTY_COLUMN] = faculty;
    }
    return;
}

void selectiveUserRemoval(std::string parkingData[PARKING_SPOTS][DATA_COLUMNS],
    std::string& name);
void assignNewUser(std::string parkingData[PARKING_SPOTS][DATA_COLUMNS],
    std::string& name, std::string& faculty);
void rearrangeParkingUsers(std::string parkingData[PARKING_SPOTS][DATA_COLUMNS],
    std::string& name, std::string& faculty);

//C. removes users based on the file parking_remove.txt and adds users based on the file parking_add.txt
void updateParkingUsersFromFile(std::string parkingData[PARKING_SPOTS][DATA_COLUMNS],
    std::string& name, std::string& faculty, std::ifstream& parkRemove, std::ifstream& parkAdd) 
{
    while (parkRemove >> faculty) 
    {
        parkRemove >> name;
        selectiveUserRemoval(parkingData, name);
    }
    rearrangeParkingUsers(parkingData, name, faculty);
    name = "", faculty = "";
    while (parkAdd >> faculty)
    {
        parkAdd >> name;
        assignNewUser(parkingData, name, faculty);
    }
}

//D. removes users based on name
void selectiveUserRemoval(std::string parkingData[PARKING_SPOTS][DATA_COLUMNS],
    std::string& name) 
{
    for (int nameChecker = 0; nameChecker < PARKING_SPOTS; nameChecker++) 
    {
        if (parkingData[nameChecker][NAME_COLUMN] == name) 
        {
            parkingData[nameChecker][NAME_COLUMN] = "";
            parkingData[nameChecker][FACULTY_COLUMN] = "";
            break;
        }
    }
    return;
}

//E. finds User's best parking space based on status
int bestParkingSpace(std::string parkingData[PARKING_SPOTS][DATA_COLUMNS],
    std::string& name, std::string faculty) 
{
    if (faculty == "1") 
    {
        for (int spotChecker = 0; spotChecker < FACULTY_CUTOFF; spotChecker++)
        {
            if (parkingData[spotChecker][NAME_COLUMN] == "") 
            {
                return spotChecker;
            }
        }
        //if there are no spots in the first 25, faculty will be assigned to spots in the other half 
        return bestParkingSpace(parkingData, name, CHANGE_STATUS);
    }
    else if (faculty == "0") 
    {
        for (int spotChecker = FACULTY_CUTOFF; spotChecker < PARKING_SPOTS; spotChecker++)
        {
            if (parkingData[spotChecker][NAME_COLUMN] == "")
            {
                return spotChecker;
            }
        }
        //returns an invalid number when all spaces are full, or there are no possible spaces
        return OUT_OF_SPOTS;
    }
}

//F. uses E. to assign the user to the best possible spot they can get
void assignNewUser(std::string parkingData[PARKING_SPOTS][DATA_COLUMNS],
    std::string& name, std::string& faculty) {
    int bestSpace = bestParkingSpace(parkingData, name, faculty);
    if (bestSpace != OUT_OF_SPOTS) 
    {
        parkingData[bestSpace][NAME_COLUMN] = name;
        parkingData[bestSpace][FACULTY_COLUMN] = faculty;
    }
    return;
}

//G. Function moves students and faculty into their respective sections for ease of assigning
//new students and faculty. Note: faculty and students already in the section will not be moved
void rearrangeParkingUsers(std::string parkingData[PARKING_SPOTS][DATA_COLUMNS],
    std::string& name, std::string& faculty) 
{
    for (int userChecker = FACULTY_CUTOFF; userChecker < PARKING_SPOTS; userChecker++) 
    {
        if (parkingData[userChecker][FACULTY_COLUMN] == "1") {
            name = parkingData[userChecker][NAME_COLUMN];
            faculty = parkingData[userChecker][FACULTY_COLUMN];
            selectiveUserRemoval(parkingData, name);
            assignNewUser(parkingData, name, faculty);
        }
    }
    return;
}

void printParkingUsers(std::string parkingData[PARKING_SPOTS][DATA_COLUMNS],
    std::ofstream& parkUpdate) 
{
    for (int spot = 0; spot < PARKING_SPOTS; spot++) 
    {
        for (int dataColumn = DATA_COLUMNS - 1; dataColumn >= 0; dataColumn--)
        {
            if (parkingData[spot][NAME_COLUMN] != "") {
                parkUpdate << parkingData[spot][dataColumn] << " ";
            }
        }
        if (parkingData[spot][NAME_COLUMN] != "") {
            parkUpdate << spot + 1 << std::endl;
        }
    }
}

int main()
{
    std::ifstream parkRemove("parking_remove.txt"), parkCurrent("parking_current.txt"),
        parkAdd("parking_add.txt");
    if (!parkAdd || !parkRemove || !parkCurrent)
    {
        std::cout << "One of the three files are not found.\n";
        return EXIT_FAILURE;
    }
    std::ofstream parkUpdate("parking_update.txt");

    std::string parkingData[PARKING_SPOTS][DATA_COLUMNS] = {};

    std::string name, faculty;
    int spot = 0;

    writeParkingData(parkingData, name, faculty, spot, parkCurrent);

    //rearrange function happens after removal and before addition so that 
    //it doesn't have to swap as many students and faculty
    updateParkingUsersFromFile(parkingData, name, faculty, parkRemove, parkAdd);
   
    printParkingUsers(parkingData, parkUpdate);

    parkAdd.close();
    parkRemove.close();
    parkCurrent.close();
    parkUpdate.close();

    return 0;
}
/*
OUTPUT:
1 Xie_Wei-Chau 1
1 Hulls_Carol 2
1 Pritzker_Mark 3
1 Manezes_Alfred 4
1 Fluid_Newtonian 5
1 Tuncel_Levent 6
1 Gryguc_Andrew 7
1 McKinnon_David 8
1 Jeremy_Pavan 9
0 Paik_Chad 10
1 Davison_Dan 11
1 Bedi_Sanjeev 12
1 Yodelay_he_who 13
0 Malloch_Jeremy 19
1 McKillop_Bob 21
1 Davidson_George 25
0 Lung_Ian 26
0 Hmeidan_Amer 27
0 Huot_Isabella 28
0 Lau_Amanda 29
0 Tan_Mark 30
0 Mills_Joel 31
0 Roller_Anika 32
0 Starratt_Kathryn 33
0 Belisle_Matt 34
0 Jasmine_Princess 35
0 Wang_Willian 36
0 Samlalsingh_Ryan 37
0 Barakat_Abdullah 38
0 Yuan_Jacky 39
0 Hamza_Muhammad 40
0 Zheng_Tim 41
0 Ratiu_Timea 42
0 Sheng_Stephen 43
0 Kim_Leo 44
0 Clifford_Zachary 45
0 Bhamare_Yash 46
0 Yousufzay_Namoos 47
0 Kandathil_Ashar 48
0 Lau_Darren 49
0 Keillor_Peter 50
*/
 
