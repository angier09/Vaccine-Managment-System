#include"VaccineSystem.h"

int numOfDifferentVaccines = 0;
void setNumOfDifferentVaccines()
{
	int temp = 0;
	cout << "Enter number of different vaccines: ";
	cin >> temp;
	numOfDifferentVaccines = temp;
}
//randomly generating queue of people in vacciation center
int generateRandomQueue()
{
	srand(time(0));
	return (1 + (rand() % 10));
}
int generateRandomID()
{
	static int unique1 = 105;			//have less chances of getting same id for any variable in classes
	static int unique2 = 380;
	srand(time(0));
	return ((++unique1) + (rand() % (++unique2)));
}
//----------Struct DOB-------//
DOB::DOB()
{
	day = 0;
	month = 0;
	year = 0;
}
DOB::~DOB()
{
}
void DOB::setDay(int d)
{
	day = d;
}
void DOB::setMonth(int m)
{
	month = m;
}
void DOB::setYear(int y)
{
	year = y;
}
int DOB::getDay()
{
	return day;
}
int DOB::getMonth()
{
	return month;
}
int DOB::getYear()
{
	return year;
}
//-----------EmailSignUpPage Abstarct Class----------//
EmailSignUpPage::EmailSignUpPage()
{
}
EmailSignUpPage::~EmailSignUpPage()
{
}
//--------------Person Class-----------//
Person::Person()
{
	firstName = '\0';
	lastName = '\0';
	id = '\0';
	email = '\0';
	password = '\0';
	phoneNum = '\0';
	CNIC = 0;
	age = 0;
}
Person::~Person()
{
}
void Person::setFirstName(string fName)
{
	firstName = fName;
}
string Person::getFirstName()
{
	return firstName;
}
void Person::setLastName(string lName)
{
	lastName = lName;
}
string Person::getLastName()
{
	return lastName;
}
void Person::setEmail(string mail)
{
	email = mail;
}
string Person::getEmail()
{
	return email;
}
void Person::setPassWord(string pasWrd)
{
	password = pasWrd;
}
string Person::getPasWord()
{
	return password;
}
void Person::setID(int id)
{
	this->id = id;
}

int Person::getID()
{
	return id;
}
void Person::setAge(int age)
{
	this->age = age;
}
int Person::getAge()
{
	return age;
}
void Person::setPhNum(string num)
{
	phoneNum = num;
}
string Person::getPhNum()
{
	return phoneNum;
}
void Person::setCNIC(long long int cnic)
{
	CNIC = cnic;
}
long long int Person::getCNIC()
{
	return CNIC;
}
//------Citizen Class----------//
//constructor
Citizen::Citizen()
{
	bloodType = '\0';
	city = '\0';
	state = '\0';
	eligibilityCheck = false;
	doseNum = 0;
	allergy = false;
	assignedCounter = 0;
}
Citizen::~Citizen()
{
}
//CRUD operation menu
int Citizen::menuCitizen()
{
	int choice = 0;
	cout << "-------------------------" << endl;
	cout << "    CRUD MENU CITIZEN   " << endl;
	cout << "-------------------------" << endl;
	cout << "1.Register Citizen" << endl;
	cout << "2.Retrieve Data of Citizen" << endl;
	cout << "3.Update Citizen" << endl;
	cout << "4.Delete Citizen" << endl;
	cout << "5.LogOut" << endl;
	cout << endl;
	cout << "Enter Choice = ";
	cin >> choice;

	return choice;
}
//this is a sign Up function to register citizen
void Citizen::signUpEmail()
{
	//string variable to write email & password
	string writeMail;
	string writePasWrd;

	//flag
	bool flag = true;

	//string variables to read email & password from file
	string readMail;
	string readPasWrd;

	//MENU
	Sleep(300);
	system("CLS");
	cout << "-----SIGN UP Email of Citizen-----" << endl;
	cout << "Enter Email    : ";
	cin >> writeMail;
	cout << "Enter Password : ";
	cin >> writePasWrd;

	//read file object created 
	ifstream readEmail;

	//opening file in reading mode
	readEmail.open("CitizenAccountPassword.txt", ios::in);

	//write file object created
	ofstream writeEmail;

	//opening file in append mode 
	//append mode is used to save the email and passwords of all the users
	writeEmail.open("CitizenAccountPassword.txt", ios::app);

	//if file cannot open
	//then showing error message
	if (!(writeEmail.is_open()))
	{
		cout << "File can not open" << endl;
	}

	//reading data from the file until end of file character not found
	while (!(readEmail.eof()) && flag == true)
	{
		//readEmail object reading mail and password from file
		readEmail >> readMail >> readPasWrd;

		//if readMail variable is not equal to the writeMail variable
		//and readpasWrd variable is not equal to the writePasWrd variable
		//then the flag is true
		if (readMail != writeMail && readPasWrd != writePasWrd)
		{
			flag = true;
		}
		//if readMail variable is equal to the writeMail variable
		//and readpasWrd variable is equal to the writePasWrd variable
		//then the flag is false
		else
		{
			flag = false;
		}
	}
	//flag true means that no similar account exist so user can register 
	if (flag == true)
	{
		writeEmail << writeMail << " " << writePasWrd << endl;
		email = writeMail;
		password = writePasWrd;
		readEmail.close();
		writeEmail.close();

	}
	else if (flag == false)
	{
		cout << "Account already exist" << endl;

		//asking the citizen to enter some different account and password
		signUpEmail();
	}
}
//function to check citizen eligibility before registring him
void Citizen::checkEligibility()
{
	char choice;
	cout << "Enter Age      : ";
	cin >> age;
	cout << "Allergic to any chemicals invovled in vaccine? ('y'/ 'n') : ";
	cin >> choice;
	if (choice == 'n' || choice == 'N')
	{
		allergy = false;
	}
	else
	{
		allergy = true;
	}
	if (age >= 5 && allergy == false)
	{
		eligibilityCheck = true;
	}
	else
	{
		eligibilityCheck = false;
	}
}
//setter to set blood type
void Citizen::setBloodType(string bldTyp)
{
	bloodType = bldTyp;
}
//setter to set city
void Citizen::setCity(string city)
{
	this->city = city;
}
//setter to set state
void Citizen::setState(string state)
{
	this->state = state;
}
void Citizen::setAddress(string add)
{
	address = add;
}
//setter to set eligibility
void Citizen::setEligibilty(bool check)
{
	eligibilityCheck = check;
}
//setter to set date of birth
void Citizen::setDOB(DOB obj)
{
	dateObj.day = obj.day;
	dateObj.month = obj.month;
	dateObj.year = obj.year;
}
void Citizen::setDoseNum(int n)
{
	doseNum = n;
}
string Citizen::getBloodType()
{
	return bloodType;
}
string Citizen::getCity()
{
	return city;
}
string Citizen::getState()
{
	return state;
}
string Citizen::getAddress()
{
	return address;
}
bool Citizen::getEligiblity()
{
	return eligibilityCheck;
}
int Citizen::getDate()
{
	return dateObj.getDay();
}
int Citizen::getMonth()
{
	return dateObj.getMonth();
}
int Citizen::getYear()
{
	return dateObj.getYear();
}
int Citizen::getDoseNum()
{
	return doseNum;
}
//overloaded extraction operator
istream& operator >> (istream& in, Citizen& obj)
{
	if (obj.eligibilityCheck == true)
	{
		bool flag = false;
		cout << endl;
		cout << "===== FILL THE FORM =====" << endl;
		cout << "Enter First Name  :  ";
		in >> obj.firstName;

		cout << "Enter Last Name   :  ";
		in >> obj.lastName;
		do
		{
			cout << "Enter CNIC        :  ";
			in >> obj.CNIC;
			if (!in)
			{
				in.clear();
				in.ignore(100, '\n');
				cout << "Wrong Input... try again" << endl;
			}
			else
				flag = true;
		} while (!flag);


		cout << "Enter Phone Number:  ";
		in >> obj.phoneNum;
		cin.ignore();

		cout << "Enter blood type  :  ";
		in >> obj.bloodType;

		cout << "Enter city        :  ";
		in >> obj.city;

		cout << "Enter state       :  ";
		in >> obj.state;

		cout << "Enter address     :  ";
		in >> ws;
		getline(in, obj.address);

		cout << "Enter Date-Of-Birth (DD/MM/YYYY)" << endl;
		cout << "Enter day         : ";
		in >> obj.dateObj.day;
		cout << "Enter month       : ";
		in >> obj.dateObj.month;
		cout << "Enter year        : ";
		in >> obj.dateObj.year;
		return in;
	}
	else
	{
		cout << "---Not Eligible to Register---" << endl;
		return in;
	}
}
//overloaded insertion operator
ostream& operator << (ostream& out, const Citizen& obj)
{
	if (obj.eligibilityCheck == true)
	{
		out << endl;
		out << "----Citizen information----" << endl;
		out << "First Name: " << obj.firstName << endl;
		out << "Email : " << obj.email << endl;
		out << "Last Name: " << obj.lastName << endl;
		out << "CNIC: " << obj.CNIC << endl;
		out << "Phone Number: " << obj.phoneNum << endl;
		out << "Blood Type: " << obj.bloodType << endl;
		out << "City: " << obj.city << endl;
		out << "State: " << obj.state << endl;
		out << "Address: " << obj.address << endl;
		cout << "Date Of Birth : " << obj.dateObj.day << " / " << obj.dateObj.month << " / " << obj.dateObj.year << endl;
		return out;
	}
	else
	{
		cout << "---NOT ELIGIBLE----" << endl;
		return out;
	}
}

//-------------------REGISTERED CITIZEN---------------//
//overloaded stream insertion operator
ostream& operator<<(ostream& out, const RegisteredCitizen& rObj)
{
	out << "----Registered Citizen Output----" << endl;
	out << rObj.regFName << ' ' << rObj.regLName << endl;
	out << rObj.regAddress << ' ' << rObj.regState << ' ' << rObj.regCity << endl;
	out << rObj.regEmail << endl;
	out << rObj.regPassWrd << endl;
	out << rObj.regPhoneNum << endl;
	out << rObj.regCNIC << endl;
	out << rObj.regBloodTyp << endl;
	out << rObj.regDateObj.day << "/" << rObj.regDateObj.month << "/" << rObj.regDateObj.year << endl;
	return out;
}
//constructor
RegisteredCitizen::RegisteredCitizen()
{
	regEmail = '\0';
	regPassWrd = '\0';
	regFName = '\0';
	regLName = '\0';
	regCNIC = '\0';
	regPhoneNum = '\0';
	regAge = 0;
	regBloodTyp = '\0';
	regCity = '\0';
	regState = '\0';
	regAddress = '\0';
	vacDoseNum = 0;
}
//destructor
RegisteredCitizen::~RegisteredCitizen()
{
}
//setting the attributes of registered citizen
void RegisteredCitizen::setRegCitizen(Citizen cObj)
{
	regFName = cObj.getFirstName();
	regLName = cObj.getLastName();
	regEmail = cObj.getEmail();
	regPassWrd = cObj.getPasWord();
	regCNIC = cObj.getCNIC();
	regPhoneNum = cObj.getPhNum();
	regCity = cObj.getCity();
	regState = cObj.getState();
	regAddress = cObj.getAddress();
	regBloodTyp = cObj.getBloodType();
	regAge = cObj.getAge();
	regDateObj.day = cObj.getDate();
	regDateObj.month = cObj.getMonth();
	regDateObj.year = cObj.getYear();
	vacDoseNum = cObj.getDoseNum();
}
//when the citizen is created his data must be written in the file
//this function will be called when the citizen will register himself to write his data in file
void RegisteredCitizen::writeToFile()
{
	ofstream writeCitizen;
	ofstream writeRegEmail;

	//opening the files
	//this file holds citizen data
	writeCitizen.open("RegisteredCitizen.txt", ios::app | ios::out);
	//this file holds citizen email and passWrd
	writeRegEmail.open("RegisteredCitizenAccount.txt", ios::app | ios::out);

	if (!(writeCitizen.is_open()))
	{
		cout << "Registered Citizen File cannot open" << endl;
	}
	//after opening file writing data to it
	else
	{
		writeCitizen << regFName << ' ' << regLName << ' ' << regEmail << ' ' << regCNIC << ' ' << regAddress << ' ' << regState << ' ' << regCity;
		writeCitizen << ' ' << regPhoneNum << ' ' << regBloodTyp << ' ' << regDateObj.day << ' ' << regDateObj.month << ' ' << regDateObj.year << ' ' << vacDoseNum << endl;
		writeCitizen.close();
	}
	if (!(writeRegEmail.is_open()))
	{
		cout << "Registered Citizen Accounts File cannot open" << endl;
	}
	//writing email and passWord
	else
	{
		writeRegEmail << regEmail << ' ' << regPassWrd << endl;
	}
}
//this function is used to read data from file and show output on screen
void RegisteredCitizen::readFromFile(const string objEmail)
{
	string email;
	string passWrd;
	string fName;
	string lName;
	long long int CNIC;
	string phoneNum;
	string bloodTyp;
	string city;
	string state;
	string address;
	DOB dateObj;
	int doseNum;
	ifstream readCitizen;
	//opening the file of citizen data
	readCitizen.open("RegisteredCitizen.txt", ios::in);

	if (!(readCitizen.is_open()))
	{
		cout << "Registered Citizen File cannot open" << endl;
		exit(-1);
	}

	//when the required email matches the loop will be breaked
	bool showFlag = false;
	//reding the file
	while (!(readCitizen.eof()) && showFlag == false)
	{
		readCitizen >> fName;
		readCitizen >> lName;
		readCitizen >> email;
		readCitizen >> CNIC;
		readCitizen >> address;
		readCitizen >> state;
		readCitizen >> city;
		readCitizen >> phoneNum;
		readCitizen >> bloodTyp;
		readCitizen >> dateObj.day;
		readCitizen >> dateObj.month;
		readCitizen >> dateObj.year;
		readCitizen >> doseNum;

		//if the entered email matches will the email of the user in file
		//then show output on screen and flag will be true and loop will be breaked
		if (email == objEmail)
		{
			showFlag = true;
			cout << endl;
			cout << "Your Information" << endl;
			cout << "Name   : " << fName << ' ' << lName << endl;
			cout << "Email  : " << email << endl;
			cout << "CNIC   : " << CNIC << endl;
			cout << "Address: " << address << ',' << state << ',' << city << endl;
			cout << "Phone Number : " << phoneNum << endl;
			cout << "Blood Group  : " << bloodTyp << endl;
			cout << "Date_Of_Birth: " << dateObj.day << '/' << dateObj.month << '/' << dateObj.year << endl;
			//displaying vacination status
			if (doseNum == 0)
			{
				cout << "Vaccination Status: Not-Vaccinated" << endl;
			}
			else if (doseNum == 1)
			{
				cout << "Vaccination Status: Partially Vaccinated" << endl;
			}
			else if (doseNum == 2)
			{
				cout << "Vaccination Status: Fully Vaccinated" << endl;
			}
			readCitizen.close();
		}
	}
	Sleep(1000);
}
//this function will update the desired citizens attribute file
void RegisteredCitizen::updateCitizenFile(string objEmail, int choice)
{
	//for all use this logic and different functions
	string email;
	string passWrd;
	string fName;
	string lName;
	long long int CNIC = 0;
	string phoneNum;
	string bloodTyp;
	string city;
	string state;
	string address;
	DOB dateObj;
	int vacDoseNum = 0;
	ifstream readCitizen;
	ifstream readCitizenFile;

	//open file
	readCitizenFile.open("RegisteredCitizen.txt", ios::in);
	if (!(readCitizenFile.is_open()))
	{
		cout << "Copy Of regCitizen not open" << endl;
		exit(-1);
	}
	//also create and open a temporary file 
	ofstream writeUpdateCitizen("tempRegCitizen.txt", ios::app);
	if (!(writeUpdateCitizen.is_open()))
	{
		cout << "temporary file cannot open" << endl;
		exit(-1);
	}

	//reading data from file
	while (!(readCitizenFile.eof()))
	{
		readCitizenFile >> fName;
		readCitizenFile >> lName;
		readCitizenFile >> email;
		readCitizenFile >> CNIC;
		readCitizenFile >> address;
		readCitizenFile >> state;
		readCitizenFile >> city;
		readCitizenFile >> phoneNum;
		readCitizenFile >> bloodTyp;
		readCitizenFile >> dateObj.day;
		readCitizenFile >> dateObj.month;
		readCitizenFile >> dateObj.year;
		readCitizenFile >> vacDoseNum;

		if (!(readCitizenFile.eof()))
		{
			if (choice == 1)
			{
				//if required account found enter the first name to update
				//the new first name will be written & rest of the attributes remains same
				if (email == objEmail)
				{
					string newFName;
					cout << "Enter First Name : ";
					cin >> newFName;

					writeUpdateCitizen << newFName << ' ' << lName << ' ' << email << ' ' << CNIC << ' ';
					writeUpdateCitizen << address << ' ' << state << ' ' << city << ' ' << phoneNum << ' ' << bloodTyp << ' ';
					writeUpdateCitizen << dateObj.day << ' ' << dateObj.month << ' ' << dateObj.year << ' ' << vacDoseNum << endl;

				}
				//when account not matches write the old data to temp file 
				else
				{
					writeUpdateCitizen << fName << ' ' << lName << ' ' << email << ' ' << CNIC << ' ' << address << ' ' << state << ' ' << city << ' ' << phoneNum << ' ' << bloodTyp << ' ';
					writeUpdateCitizen << dateObj.day << ' ' << dateObj.month << ' ' << dateObj.year << ' ' << vacDoseNum << endl;
				}
			}
			else if (choice == 2)
			{
				string newLName;

				if (email == objEmail)
				{

					cout << "Enter Last Name : ";
					cin >> newLName;

					writeUpdateCitizen << fName << ' ' << newLName << ' ' << email << ' ' << CNIC << ' ';
					writeUpdateCitizen << address << ' ' << state << ' ' << city << ' ' << phoneNum << ' ' << bloodTyp << ' ';
					writeUpdateCitizen << dateObj.day << ' ' << dateObj.month << ' ' << dateObj.year << ' ' << vacDoseNum << endl;
				}
				else
				{
					writeUpdateCitizen << fName << ' ' << lName << ' ' << email << ' ' << CNIC << ' ' << address << ' ' << state << ' ' << city << ' ' << phoneNum << ' ' << bloodTyp << ' ';
					writeUpdateCitizen << dateObj.day << ' ' << dateObj.month << ' ' << dateObj.year << ' ' << vacDoseNum << endl;
				}

			}
			else if (choice == 3)
			{
				string newCNIC;
				if (email == objEmail)
				{

					cout << "Enter CNIC : ";
					cin >> newCNIC;

					writeUpdateCitizen << fName << ' ' << lName << ' ' << email << ' ' << newCNIC << ' ';
					writeUpdateCitizen << address << ' ' << state << ' ' << city << ' ' << phoneNum << ' ' << bloodTyp << ' ';
					writeUpdateCitizen << dateObj.day << ' ' << dateObj.month << ' ' << dateObj.year << ' ' << vacDoseNum << endl;
				}
				else
				{
					writeUpdateCitizen << fName << ' ' << lName << ' ' << email << ' ' << CNIC << ' ' << address << ' ' << state << ' ' << city << ' ' << phoneNum << ' ' << bloodTyp << ' ';
					writeUpdateCitizen << dateObj.day << ' ' << dateObj.month << ' ' << dateObj.year << ' ' << vacDoseNum << endl;
				}

			}
			else if (choice == 4)
			{
				string newPhNum;

				if (email == objEmail)
				{
					cout << "Enter PhoneNumber : ";
					cin >> newPhNum;
					writeUpdateCitizen << fName << ' ' << lName << ' ' << email << ' ' << CNIC << ' ';
					writeUpdateCitizen << address << ' ' << state << ' ' << city << ' ' << newPhNum << ' ' << bloodTyp << ' ';
					writeUpdateCitizen << dateObj.day << ' ' << dateObj.month << ' ' << dateObj.year << ' ' << vacDoseNum << endl;
				}
				else
				{
					writeUpdateCitizen << fName << ' ' << lName << ' ' << email << ' ' << CNIC << ' ' << address << ' ' << state << ' ' << city << ' ' << phoneNum << ' ' << bloodTyp << ' ';
					writeUpdateCitizen << dateObj.day << ' ' << dateObj.month << ' ' << dateObj.year << ' ' << vacDoseNum << endl;
				}
			}
			else if (choice == 5)
			{
				string newAdd;

				if (email == objEmail)
				{
					cout << "Enter Address : ";
					cin >> newAdd;
					writeUpdateCitizen << fName << ' ' << lName << ' ' << email << ' ' << CNIC << ' ';
					writeUpdateCitizen << newAdd << ' ' << state << ' ' << city << ' ' << phoneNum << ' ' << bloodTyp << ' ';
					writeUpdateCitizen << dateObj.day << ' ' << dateObj.month << ' ' << dateObj.year << ' ' << vacDoseNum << endl;
				}
				else
				{
					writeUpdateCitizen << fName << ' ' << lName << ' ' << email << ' ' << CNIC << ' ' << address << ' ' << state << ' ' << city << ' ' << phoneNum << ' ' << bloodTyp << ' ';
					writeUpdateCitizen << dateObj.day << ' ' << dateObj.month << ' ' << dateObj.year << ' ' << vacDoseNum << endl;
				}
			}
			else if (choice == 6)
			{
				string newState;

				if (email == objEmail)
				{
					cout << "Enter State : ";
					cin >> newState;
					writeUpdateCitizen << fName << ' ' << lName << ' ' << email << ' ' << CNIC << ' ';
					writeUpdateCitizen << address << ' ' << newState << ' ' << city << ' ' << phoneNum << ' ' << bloodTyp << ' ';
					writeUpdateCitizen << dateObj.day << ' ' << dateObj.month << ' ' << dateObj.year << ' ' << vacDoseNum << endl;
				}
				else
				{
					writeUpdateCitizen << fName << ' ' << lName << ' ' << email << ' ' << CNIC << ' ' << address << ' ' << state << ' ' << city << ' ' << phoneNum << ' ' << bloodTyp << ' ';
					writeUpdateCitizen << dateObj.day << ' ' << dateObj.month << ' ' << dateObj.year << ' ' << vacDoseNum << endl;
				}

			}
			else if (choice == 7)
			{
				string newCity;
				if (email == objEmail)
				{
					cout << "Enter City : ";
					cin >> newCity;
					writeUpdateCitizen << fName << ' ' << lName << ' ' << email << ' ' << CNIC << ' ';
					writeUpdateCitizen << address << ' ' << state << ' ' << newCity << ' ' << phoneNum << ' ' << bloodTyp << ' ';
					writeUpdateCitizen << dateObj.day << ' ' << dateObj.month << ' ' << dateObj.year << ' ' << vacDoseNum << endl;
				}
				else
				{
					writeUpdateCitizen << fName << ' ' << lName << ' ' << email << ' ' << CNIC << ' ' << address << ' ' << state << ' ' << city << ' ' << phoneNum << ' ' << bloodTyp << ' ';
					writeUpdateCitizen << dateObj.day << ' ' << dateObj.month << ' ' << dateObj.year << ' ' << vacDoseNum << endl;
				}
			}
			else if (choice == 8)
			{
				string newBldTyp;
				if (email == objEmail)
				{
					cout << "Enter Blood Type : ";
					cin >> newBldTyp;
					writeUpdateCitizen << fName << ' ' << lName << ' ' << email << ' ' << CNIC << ' ';
					writeUpdateCitizen << address << ' ' << state << ' ' << city << ' ' << phoneNum << ' ' << newBldTyp << ' ';
					writeUpdateCitizen << dateObj.day << ' ' << dateObj.month << ' ' << dateObj.year << ' ' << vacDoseNum << endl;
				}
				else
				{
					writeUpdateCitizen << fName << ' ' << lName << ' ' << email << ' ' << CNIC << ' ' << address << ' ' << state << ' ' << city << ' ' << phoneNum << ' ' << bloodTyp << ' ';
					writeUpdateCitizen << dateObj.day << ' ' << dateObj.month << ' ' << dateObj.year << ' ' << vacDoseNum << endl;
				}
			}
			else if (choice == 9)
			{
				DOB nObj;
				if (email == objEmail)
				{

					cout << "Enter Date Of Birth : " << endl;
					cout << "Enter Day   : "; cin >> nObj.day;
					cout << "Enter Month : "; cin >> nObj.month;
					cout << "Enter Year  : "; cin >> nObj.year;

					writeUpdateCitizen << fName << ' ' << lName << ' ' << email << ' ' << CNIC << ' ';
					writeUpdateCitizen << address << ' ' << state << ' ' << city << ' ' << phoneNum << ' ' << bloodTyp << ' ';
					writeUpdateCitizen << nObj.day << ' ' << nObj.month << ' ' << nObj.year << ' ' << vacDoseNum << endl;
				}
				else
				{
					writeUpdateCitizen << fName << ' ' << lName << ' ' << email << ' ' << CNIC << ' ' << address << ' ' << state << ' ' << city << ' ' << phoneNum << ' ' << bloodTyp << ' ';
					writeUpdateCitizen << dateObj.day << ' ' << dateObj.month << ' ' << dateObj.year << ' ' << vacDoseNum << endl;
				}
			}
			else
			{
				cout << "*****Wrong choice******" << endl;
				exit(-1);
			}
		}
	}

	cout << "Updating Your Data. Please wait ";
	for (int i = 0; i < 5; i++)
	{
		Sleep(500);
		cout << ".";
	}
	cout << endl;

	//closing files
	readCitizenFile.close();
	writeUpdateCitizen.close();

	//since the tempRegCitizen file is updated version of the RegisteredCitizen file
	//we will remove the RegisteredCitizen file
	//and name temp file as RegisteredCitizen
	remove("RegisteredCitizen.txt");
	rename("tempRegCitizen.txt", "RegisteredCitizen.txt");
}
//this function will register a new citizen
void RegisteredCitizen::createRegisteredCitizen()
{
	int citizens = 0;
	Citizen* cObj = {};

	//dynamic allocation of citizens
	cout << "Enter citizens you want to create : ";
	cin >> citizens;

	cObj = new Citizen[citizens];

	for (int i = 0; i < citizens; i++)
	{
		//signUp their email
		cObj[i].signUpEmail();
		//checking eligibility
		cObj[i].checkEligibility();
		//if citizen is eligible then input its attributes
		if (cObj[i].getEligiblity() == true)
		{
			cin >> cObj[i];
			RegisteredCitizen rObj;
			//taking inputs
			rObj.setRegCitizen(cObj[i]);
			Sleep(1000);
			system("CLS");
			//writing data to file
			rObj.writeToFile();
			cout << endl;

			cout << "Saving Your Data. Please wait ";
			for (int i = 0; i < 5; i++)
			{
				Sleep(500);
				cout << ".";
			}
			cout << endl;
			system("CLS");
			cout << "Data Saved Successfully" << endl;
			Sleep(500);
			//cout << cObj[i] << endl;
			//cout << rObj << endl;
		}
		//if citizen is not eligible he is not registered
		else if (cObj[i].getEligiblity() == false)
		{
			cout << "Checking Eligibility..Please wait";
			for (int i = 0; i < 5; i++)
			{
				Sleep(500);
				cout << ".";
			}
			cout << endl;
			cout << "---NOT ELIGIBLE TO REGISTERED---" << endl;
			Sleep(500);
		}
		system("CLS");
		Sleep(1000);
	}

	delete[]cObj;
}
//this function will show citizen output 
void RegisteredCitizen::showRegisteredCitizen()
{
	//serach by email
	//first login the email and password
	RegisteredCitizen rObj;

	cout << "Enter Email: ";
	cin >> rObj.regEmail;
	cout << "Enter Password: ";
	cin >> rObj.regPassWrd;

	string email;
	string passWrd;
	ifstream readEmail;
	readEmail.open("RegisteredCitizenAccount.txt", ios::in);
	if (!(readEmail.is_open()))
	{
		cout << "Registered Citizen Account cannot open" << endl;
		exit(-1);
	}

	//match the email and password
	//if the required account found break the loop
	else
	{
		bool logInFlag = false;
		while ((!(readEmail.eof())) && logInFlag == false)
		{
			readEmail >> email >> passWrd;
			if (email == rObj.regEmail && passWrd == rObj.regPassWrd)
			{
				logInFlag = true;
				cout << "Sucessfully logged in" << endl;
				rObj.readFromFile(rObj.regEmail);
				Sleep(500);
			}
		}
		if (logInFlag == false)
		{
			cout << "******Wrong email/password******" << endl;
		}
		readEmail.close();
	}
}
//this function will login and then update the citizen
void RegisteredCitizen::updateRegisteredCitizen()
{
	string email;
	string passWrd;
	RegisteredCitizen rObj;

	//to update attributes first login the system by entering email and password
	cout << "Enter Email: ";
	cin >> rObj.regEmail;
	cout << "Enter Password: ";
	cin >> rObj.regPassWrd;

	//open file in read mode 
	ifstream readEmail;
	readEmail.open("RegisteredCitizenAccount.txt", ios::in);
	if (!(readEmail.is_open()))
	{
		cout << "Registered Citizen Account cannot open" << endl;
		exit(-1);
	}

	//match the email and password
	//if the required account found break the loop
	else
	{
		bool logInFlag = false;
		while ((!(readEmail.eof())) && logInFlag == false)
		{
			readEmail >> email >> passWrd;
			if (email == rObj.regEmail && passWrd == rObj.regPassWrd)
			{
				logInFlag = true;
				cout << "Sucessfully logged in" << endl;
				Sleep(1000);
				system("CLS");
			}
		}
		if (logInFlag == false)
		{
			cout << "******Wrong email/password******" << endl;
			exit(-1);
		}
		readEmail.close();
	}

	int choice = 0;
	cout << "Select the following options to edit attributes" << endl;
	cout << "1.First Name  2.Last Name  3.CNIC  4.PhoneNumber " << endl;
	cout << "5.Address     6.State      7.City  8.Blood Group" << endl;
	cout << "9.Date Of Birth" << endl;
	cout << endl << "Enter Choice : ";
	cin >> choice;

	//update citizen file by passing the registered email
	//and the choice that which attribute we want to change
	rObj.updateCitizenFile(rObj.regEmail, choice);
}
//this function will delete citizen email and passWord from file
void RegisteredCitizen::deleteRegisteredCitizen()
{
	string email;
	string passWrd;

	RegisteredCitizen rObj;

	cout << "Enter Email: ";
	cin >> rObj.regEmail;
	cout << "Enter Password: ";
	cin >> rObj.regPassWrd;

	ifstream readEmail;
	readEmail.open("RegisteredCitizenAccount.txt", ios::in);

	if (!(readEmail.is_open()))
	{
		cout << "RegisteredCitizenAccount cannot open" << endl;
		exit(-1);
	}

	ofstream deleteEmail("tempAccountDel.txt", ios::app | ios::out);
	if (!(deleteEmail.is_open()))
	{
		cout << "tempAccountDel cannot open" << endl;
		exit(-1);
	}

	//match the email and password
	//if the required account found break the loop
	else
	{
		bool logInFlag = false;
		while ((!(readEmail.eof())) && logInFlag == false)
		{
			readEmail >> email >> passWrd;
			if (email == rObj.regEmail && passWrd == rObj.regPassWrd)
			{
				logInFlag = true;
				cout << "Sucessfully logged in" << endl;
				Sleep(1000);
				system("CLS");

				char choice = '\0';
				cout << "Do you want to delete your account ( 'y' / 'n' ): ";
				cin >> choice;
				if (choice == 'y' || choice == 'Y')
				{
					rObj.deleteFileData(rObj.regEmail);
				}

			}
		}
		if (logInFlag == false)
		{
			cout << "******Wrong email/password******" << endl;
			exit(-1);
		}
	}
	readEmail.close();
	readEmail.open("RegisteredCitizenAccount.txt", ios::app);

	//now reading the file of registered citizen account
	while (!(readEmail.eof()))
	{
		readEmail >> email;
		readEmail >> passWrd;

		if (!(readEmail.eof()))
		{
			//if the account is found
			//delete it by placing simple space and write it in temporary file
			if (email == rObj.regEmail && passWrd == rObj.regPassWrd)
			{
				email = ' ';
				deleteEmail << email << endl;
			}
			//write rest of the data as it is in the temporary file
			else
			{
				deleteEmail << email << ' ' << passWrd << endl;

			}

		}
	}

	readEmail.close();
	deleteEmail.close();

	//deleting the RegisteredCitizenAccount file then renaming the temporary file as RegisteredCitizenAccount
	//because temporary file is the updated version of RegisteredCitizenAccount 
	//pehle purani file delete karen ge 
	//phir change file name
	remove("RegisteredCitizenAccount.txt");
	rename("tempAccountDel.txt", "RegisteredCitizenAccount.txt");
}
//this function will delete all the data of citizen from file
void RegisteredCitizen::deleteFileData(const string objEmail)
{
	string email;
	string passWrd;

	string fName;
	string lName;
	long long int CNIC = 0;
	string phoneNum;
	string bloodTyp;
	string city;
	string state;
	string address;
	DOB dateObj;
	int vacDose = 0;

	//deleting citizen data from the file
	ifstream readCitizenFile;
	readCitizenFile.open("RegisteredCitizen.txt", ios::in);
	if (!(readCitizenFile.is_open()))
	{
		//change file name
		cout << "RegisteredCitizen file not open" << endl;
		exit(-1);
	}

	//creating temporary file 
	ofstream deleteCitizen("tempCitizendel.txt", ios::app);
	if (!(deleteCitizen.is_open()))
	{
		cout << "tempCitizendel cannot open" << endl;
		exit(-1);
	}

	while (!(readCitizenFile.eof()))
	{
		readCitizenFile >> fName;
		readCitizenFile >> lName;
		readCitizenFile >> email;
		readCitizenFile >> CNIC;
		readCitizenFile >> address;
		readCitizenFile >> state;
		readCitizenFile >> city;
		readCitizenFile >> phoneNum;
		readCitizenFile >> bloodTyp;
		readCitizenFile >> dateObj.day;
		readCitizenFile >> dateObj.month;
		readCitizenFile >> dateObj.year;
		readCitizenFile >> vacDose;

		//if account found place space in place of that line
		if (!(readCitizenFile.eof()))
		{
			if (email == objEmail)
			{
				fName = ' ';
				deleteCitizen << fName << endl;
			}
			//write rest of the accounts as it is 
			else
			{
				deleteCitizen << fName << ' ' << lName << ' ' << email << ' ' << CNIC << ' ' << address << ' ';
				deleteCitizen << state << ' ' << city << ' ' << phoneNum << ' ' << bloodTyp << ' ';
				deleteCitizen << dateObj.day << ' ' << dateObj.month << ' ' << dateObj.year << ' ' << vacDose << endl;
			}

		}
	}

	cout << "Deleting Your Data. Please wait ";
	for (int i = 0; i < 5; i++)
	{
		Sleep(500);
		cout << ".";
	}
	cout << endl;

	readCitizenFile.close();
	deleteCitizen.close();

	//pehle purani file delete karen ge 
	//phir change file name
	remove("RegisteredCitizen.txt");
	rename("tempCitizendel.txt", "RegisteredCitizen.txt");
}
//to perform CRUD operations on citizen 
void Citizen::citizenCRUD()
{
	//int choice = menuCitizen();
	bool logOut = false;

	while (logOut == false)
	{
		int choice = menuCitizen();
		switch (choice)
		{
		case 1:
		{
			RegisteredCitizen rObj;
			rObj.createRegisteredCitizen();
			break;
		}
		case 2:
		{
			cout << endl;
			cout << "------Citizen Login In Page------" << endl;
			RegisteredCitizen rObj;
			rObj.showRegisteredCitizen();
			break;
		}
		case 3:
		{
			cout << endl;
			cout << "-----Edit Citizen------" << endl;
			RegisteredCitizen rObj;
			rObj.updateRegisteredCitizen();
			break;
		}
		case 4:
		{
			cout << endl;
			cout << "------Delete Citizen-----" << endl;
			RegisteredCitizen rObj;
			rObj.deleteRegisteredCitizen();
			break;
		}
		case 5:
		{
			cout << "Log Out" << endl;
			logOut = true;
			Sleep(500);
			break;
		}
		default:
			cout << "Wrong Input" << endl;
			break;
		}

		Sleep(1000);
		system("CLS");
	}
}
//-------------VACCINE CLASS----------------//
Vaccine::Vaccine()
{
	vacType = '\0';
	vacID = '\0';
	vacPrice = 0;
	vacName = '\0';
	numberOfDoses = 0;
	expiryDate.day = 0;
	expiryDate.month = 0;
	expiryDate.year = 0;
}
Vaccine::~Vaccine()
{

}
void Vaccine::setVacType(string type)
{
	vacType = type;
}
void Vaccine::setVacID(int ID)
{
	vacID = ID;
}
void Vaccine::setPrice(float cost)
{
	vacPrice = cost;
}
void Vaccine::setExpiryDate(DOB obj)
{
	expiryDate.day = obj.day;
	expiryDate.month = obj.month;
	expiryDate.year = obj.year;
}
void Vaccine::setVacName(string name)
{
	vacName = name;
}
void Vaccine::setDoses(int doses)
{
	numberOfDoses = doses;
}
string Vaccine::getVacType()
{
	return vacType;
}
int Vaccine::getVacID()
{
	return vacID;
}
float Vaccine::getVacPrice()
{
	return vacPrice;
}
int Vaccine::getNumberofDoses()
{
	return numberOfDoses;
}
string Vaccine::getVacName()
{
	return vacName;
}
DOB Vaccine::getExpiryDate()
{
	return expiryDate;
}
ostream& operator <<(ostream& out, const Vaccine& obj)
{
	cout << "-------VACCINE INFO--------" << endl;
	out << "Vaccine Type:  " << obj.vacType << endl;
	out << "Vaccine Name:  " << obj.vacName << endl;
	out << "Vaccine Price: " << obj.vacPrice << endl;
	out << "Vaccine ID:    " << obj.vacID << endl;
	out << "Vaccine doses: " << obj.numberOfDoses << endl;
	out << "Expiry Date:   " << obj.expiryDate.day << " /" << obj.expiryDate.month << " /" << obj.expiryDate.year << endl;
	return out;
}
istream& operator >> (istream& in, Vaccine& obj)
{
	bool flag = false;
	cout << "-------VACCINE INPUT-------" << endl;
	cout << "Enter Name:  ";
	in >> obj.vacName;
	cout << "Enter Type:  ";
	in >> obj.vacType;
	do
	{
		cout << "Enter Price: ";
		in >> obj.vacPrice;
		if (!in)
		{
			cout << "Wrong Input... try again" << endl;
			in.clear();
			in.ignore(100, '\n');
		}
		else
			flag = true;
	} while (!flag);
	do
	{
		cout << "Enter ID:    ";
		in >> obj.vacID;
		if (!in)
		{
			cout << "Wrong Input... try again" << endl;
			in.clear();
			in.ignore(100, '\n');
		}
		else
			flag = true;
	} while (!flag);

	do
	{
		cout << "Enter Doses: ";
		in >> obj.numberOfDoses;
		if (!in)
		{
			cout << "Wrong Input... try again" << endl;
			in.clear();
			in.ignore(100, '\n');
		}
		else
			flag = true;
	} while (!flag);

	cout << "Enter Expiry Date" << endl;
	cout << "Enter Day:   ";
	in >> obj.expiryDate.day;
	cout << "Enter Month: ";
	in >> obj.expiryDate.month;
	cout << "Enter Year:  ";
	in >> obj.expiryDate.year;
	return in;
}
//---------------------BATCH VACCINE CLASS----------------//
Batch_Vaccine::Batch_Vaccine()
{
	batchSize = 0;
	batchID = 0;
	vaccines = nullptr;
}
Batch_Vaccine::Batch_Vaccine(Batch_Vaccine& obj)   //copy constructor
{
	batchSize = obj.batchSize;
	batchID = obj.batchID;
	vaccines = new Vaccine[batchSize];
	for (int i = 0; i < batchSize; i++)
	{
		vaccines[i].setDoses(obj.vaccines->getNumberofDoses());
		vaccines[i].setPrice(obj.vaccines->getVacPrice());
		vaccines[i].setVacID(obj.vaccines->getVacID());
		vaccines[i].setVacType(obj.vaccines->getVacType());
		vaccines[i].setVacName(obj.vaccines->getVacName());
		vaccines[i].setExpiryDate(obj.vaccines->getExpiryDate());
	}
}
Batch_Vaccine::~Batch_Vaccine()
{
	vaccines = nullptr;
}
void Batch_Vaccine::setBatchSize(int size)
{
	batchSize = size;
}
void Batch_Vaccine::setBatchID(int id)
{
	batchID = id;
}
void Batch_Vaccine::setVaccineToCreateBatch(Vaccine& obj)
{
	vaccines = new Vaccine[batchSize];
	for (int i = 0, id = 0; i < batchSize; i++, id++)
	{
		vaccines[i].setDoses(obj.getNumberofDoses());
		vaccines[i].setPrice(obj.getVacPrice());
		vaccines[i].setVacID(obj.getVacID() + id);		//have different ID's of same vaccine type
		vaccines[i].setVacType(obj.getVacType());
		vaccines[i].setVacName(obj.getVacName());
		vaccines[i].setExpiryDate(obj.getExpiryDate());
	}
}
void Batch_Vaccine::setVaccinesInBatch(Vaccine* obj)
{
	vaccines = new Vaccine[batchSize];
	for (int i = 0, id = 0; i < batchSize; i++, id++)
	{
		vaccines[i].setDoses(obj->getNumberofDoses());
		vaccines[i].setPrice(obj->getVacPrice());
		vaccines[i].setVacID(obj->getVacID() + id);		//have different ID's of same vaccine type
		vaccines[i].setVacType(obj->getVacType());
		vaccines[i].setVacName(obj->getVacName());
		vaccines[i].setExpiryDate(obj->getExpiryDate());
	}
}
int Batch_Vaccine::getBatchSize()
{
	return batchSize;
}
int Batch_Vaccine::getBatchID()
{
	return batchID;
}
Vaccine* Batch_Vaccine::getVaccines()
{
	return vaccines;
}
ostream& operator <<(ostream& out, const Batch_Vaccine& obj)
{
	cout << "------BATCH OUTPUT------" << endl;
	out << "Batch ID:   " << obj.batchID << endl;
	out << "Batch Size: " << obj.batchSize << endl;
	out << "Vaccine in Batch: " << endl << *obj.vaccines << endl;
	return out;
}
istream& operator >> (istream& in, Batch_Vaccine& obj)
{
	cout << "----BATCH INPUT----" << endl;
	cout << "Enter Batch ID:   ";
	in >> obj.batchID;
	cout << "Enter Batch Size: ";
	in >> obj.batchSize;
	//vaccines will be stored through setter getter
	return in;
}

//--------MANUFACTURER CLASS----------//
Manufacturer::Manufacturer()
{
	numOfBatches = 0;
	batches = nullptr;
}
Manufacturer::Manufacturer(Manufacturer& obj)	//copy constructor
{
	numOfBatches = obj.numOfBatches;
	for (int i = 0; i < numOfBatches; i++)
	{
		batches = new Batch_Vaccine[numOfBatches];
		for (int i = 0, id = 0; i < numOfBatches; i++, id += 50)
		{
			batches[i].setBatchID((obj.batches->getBatchID()));
			batches[i].setBatchSize(obj.batches->getBatchSize());
			batches[i].setVaccinesInBatch(obj.batches->getVaccines());
		}
	}
}
Manufacturer::~Manufacturer()
{
	batches = nullptr;
}
void Manufacturer::setNumOfBatches(int num)
{
	numOfBatches = num;
}
void Manufacturer::setBatchesToCreate(Batch_Vaccine& obj)
{
	batches = new Batch_Vaccine[numOfBatches];
	for (int i = 0, id = 0; i < numOfBatches; i++, id += 50)
	{
		batches[i].setBatchID((obj.getBatchID() + id));	//to have different batch ID's of same vaccine name
		batches[i].setBatchSize(obj.getBatchSize());
		batches[i].setVaccinesInBatch(obj.getVaccines());
	}
}
void Manufacturer::setBatchesToStore(Batch_Vaccine* obj)
{
	batches = new Batch_Vaccine[numOfBatches];
	for (int i = 0, id = 0; i < numOfBatches; i++, id += 50)
	{
		batches[i].setBatchID((obj[i].getBatchID() + id));			//to have different batch ID's of same vaccine name
		batches[i].setBatchSize(obj[i].getBatchSize());
		batches[i].setVaccinesInBatch(obj[i].getVaccines());
	}
}
int Manufacturer::getNumOfBatches()
{
	return numOfBatches;
}
Batch_Vaccine* Manufacturer::getBatches()
{
	return batches;
}
ostream& operator <<(ostream& out, const Manufacturer& obj)
{
	cout << "-----MANUFACTURE OUTPUT------" << endl;
	cout << "First Name: " << obj.firstName << endl;
	cout << "Last Name : " << obj.lastName << endl;
	cout << "CNIC: " << obj.CNIC << endl;
	cout << "Age : " << obj.age << endl;
	cout << "ID  : " << obj.id << endl;
	cout << "PhoneNumber: " << obj.phoneNum << endl;
	out << "Number of batches: " << obj.numOfBatches << endl;
	for (int i = 0; i < obj.numOfBatches; i++)
	{
		out << "Batch " << i + 1 << " ID: " << obj.batches[i].getBatchID() << endl;
	}

	return out;
}
istream& operator >> (istream& in, Manufacturer& obj)
{
	cout << "-------INPUT MANUFACTURER-------" << endl;
	cout << "Enter First Name : ";
	in >> obj.firstName;
	cout << "Enter Last Name  : ";
	in >> obj.lastName;
	cout << "Enter CNIC: ";
	in >> obj.CNIC;
	cout << "Enter Age: ";
	in >> obj.age;
	cout << "Enter ID : ";
	in >> obj.id;
	cout << "Enter PhoneNumber: ";
	in >> obj.phoneNum;
	cout << "Enter number of batches: ";
	in >> obj.numOfBatches;

	//batch_vaccine is set through setter getter, outside the class
	return in;
}
//---------------VENDOR CLASS----------------//
Vendor::Vendor()
{
	batchesBought = nullptr;
}
Vendor::Vendor(Vendor& obj)			//copy constructor
{
	company.setEmail(obj.company.getEmail());
	company.setPassWord(obj.company.getPasWord());
	company.setFirstName(obj.company.getFirstName());
	company.setLastName(obj.company.getLastName());
	company.setPhNum(obj.company.getPhNum());
	company.setID(obj.company.getID());
	company.setCNIC(obj.company.getCNIC());
	company.setAge(obj.company.getAge());
	company.setNumOfBatches(obj.company.getNumOfBatches());
	company.setBatchesToStore(obj.company.getBatches());

	int tempNumOfBatches = company.getNumOfBatches();
	if (tempNumOfBatches > 1)
	{
		batchesBought = new Batch_Vaccine[tempNumOfBatches];
		for (int i = 0; i < tempNumOfBatches; i++)
		{
			batchesBought[i].setBatchSize(company.getBatches()[i].getBatchSize());
			batchesBought[i].setBatchID(company.getBatches()[i].getBatchID());
			batchesBought[i].setVaccinesInBatch(company.getBatches()[i].getVaccines());			//complex code, pending explanation
		}
	}
	else
	{
		batchesBought = new Batch_Vaccine;
		batchesBought->setBatchID(company.getBatches()->getBatchID());
		batchesBought->setBatchSize(company.getBatches()->getBatchSize());
		batchesBought->setVaccinesInBatch(company.getBatches()->getVaccines());
	}
}
Vendor::~Vendor()
{
	batchesBought = nullptr;
}
void Vendor::setCompany(Manufacturer& obj)
{
	company.setEmail(obj.getEmail());
	company.setPassWord(obj.getPasWord());
	company.setFirstName(obj.getFirstName());
	company.setLastName(obj.getLastName());
	company.setPhNum(obj.getPhNum());
	company.setID(obj.getID());
	company.setCNIC(obj.getCNIC());
	company.setAge(obj.getAge());
	company.setNumOfBatches(obj.getNumOfBatches());
	company.setBatchesToStore(obj.getBatches());
}
void Vendor::setBatchBought()
{
	int tempNumOfBatches = company.getNumOfBatches();
	if (tempNumOfBatches > 1)
	{
		batchesBought = new Batch_Vaccine[tempNumOfBatches];
		for (int i = 0; i < tempNumOfBatches; i++)
		{
			batchesBought[i].setBatchSize(company.getBatches()[i].getBatchSize());
			batchesBought[i].setBatchID(company.getBatches()[i].getBatchID());
			batchesBought[i].setVaccinesInBatch(company.getBatches()[i].getVaccines());			//complex code, pending explanation
		}
	}
	else
	{
		batchesBought = new Batch_Vaccine;
		batchesBought->setBatchID(company.getBatches()->getBatchID());
		batchesBought->setBatchSize(company.getBatches()->getBatchSize());
		batchesBought->setVaccinesInBatch(company.getBatches()->getVaccines());
	}
}
void Vendor::vendorToStore(Vendor& obj)			//for deep copy purpose down in admin class
{
	firstName = obj.firstName;
	lastName = obj.lastName;
	age = obj.age;
	CNIC = obj.CNIC;
	id = obj.id;
	phoneNum = obj.phoneNum;

	company.setEmail(obj.company.getEmail());
	company.setPassWord(obj.company.getPasWord());
	company.setFirstName(obj.company.getFirstName());
	company.setLastName(obj.company.getLastName());
	company.setPhNum(obj.company.getPhNum());
	company.setID(obj.company.getID());
	company.setCNIC(obj.company.getCNIC());
	company.setAge(obj.company.getAge());
	company.setNumOfBatches(obj.company.getNumOfBatches());
	company.setBatchesToStore(obj.company.getBatches());

	int tempNumOfBatches = company.getNumOfBatches();
	if (tempNumOfBatches > 1)
	{
		batchesBought = new Batch_Vaccine[tempNumOfBatches];
		for (int i = 0; i < tempNumOfBatches; i++)
		{
			batchesBought[i].setBatchSize(company.getBatches()[i].getBatchSize());
			batchesBought[i].setBatchID(company.getBatches()[i].getBatchID());
			batchesBought[i].setVaccinesInBatch(company.getBatches()[i].getVaccines());			//complex code, pending explanation
		}

	}
	else
	{
		batchesBought = new Batch_Vaccine;
		batchesBought->setBatchID(company.getBatches()->getBatchID());
		batchesBought->setBatchSize(company.getBatches()->getBatchSize());
		batchesBought->setVaccinesInBatch(company.getBatches()->getVaccines());
	}
}
Batch_Vaccine* Vendor::getBatchesBought()
{
	return batchesBought;
}
Manufacturer& Vendor::getCompany()
{
	return company;
}
ostream& operator <<(ostream& out, Vendor& obj)
{
	cout << "------VENDOR DATA--------" << endl;
	cout << "First Name: " << obj.firstName << endl;
	cout << "Last Name : " << obj.lastName << endl;
	cout << "Age  : " << obj.age << endl;
	cout << "CNIC : " << obj.CNIC << endl;
	cout << "ID   : " << obj.id << endl;
	cout << "PhoneNumber: " << obj.phoneNum << endl;
	cout << "Manufacturer's ID: " << obj.company.getID() << endl;
	int tempNumOfBatches = obj.company.getNumOfBatches();
	if (tempNumOfBatches > 1)
	{
		for (int i = 0; i < tempNumOfBatches; i++)
		{
			out << "ID of Batch " << i + 1 << " Bought: " << obj.batchesBought[i].getBatchID() << endl;
			out << "Size of Batch " << i + 1 << " Bought: " << obj.batchesBought[i].getBatchSize() << endl;

		}
	}
	else
	{
		out << "ID of Batch Bought: " << obj.batchesBought->getBatchID() << endl;
		out << "Size of Batch Bought: " << obj.batchesBought->getBatchSize() << endl;
	}

	return out;
}
istream& operator >> (istream& in, Vendor& obj)
{
	cout << "------INPUT VENDOR-----" << endl;
	cout << "Enter First Name: ";
	in >> obj.firstName;
	cout << "Enter Last Name : ";
	in >> obj.lastName;
	cout << "Enter Age : ";
	in >> obj.age;
	cout << "Enter CNIC: ";
	in >> obj.CNIC;
	cout << "Enter ID:   ";
	in >> obj.id;
	cout << "Enter PhoneNumber: ";
	in >> obj.phoneNum;
	//setter of other data members is done outside the class
	return in;
}
//-----------------SUPPLIER CLASS--------------------//
Supplier::Supplier()
{
	vaccineToBuy = '\0';
	numOfSpecificVaccines = 0;
	batchesOfSpecificVaccine = nullptr;
	totalBuyers = numOfDifferentVaccines;
	numOfBatchesBought = 0;
	totalBatchesSupplied = 0;
	buyers = nullptr;
	batchesSupplied = nullptr;
}
Supplier::Supplier(Supplier& obj)
{
	vaccineToBuy = obj.vaccineToBuy;
	totalBuyers = obj.totalBuyers;
	buyers = new Vendor[totalBuyers];
	for (int i = 0; i < totalBuyers; i++)
	{
		buyers[i].setEmail(obj.buyers[i].getEmail());
		buyers[i].setPassWord(obj.buyers[i].getPasWord());
		buyers[i].setFirstName(obj.buyers[i].getFirstName());
		buyers[i].setLastName(obj.buyers[i].getLastName());
		buyers[i].setPhNum(obj.buyers[i].getPhNum());
		buyers[i].setID(obj.buyers[i].getID());
		buyers[i].setCNIC(obj.buyers[i].getCNIC());
		buyers[i].setAge(obj.buyers[i].getAge());
		buyers[i].setCompany(obj.buyers[i].getCompany());
		buyers[i].setBatchBought();
	}
	numOfSpecificVaccines = obj.numOfSpecificVaccines;
	batchesOfSpecificVaccine = new int[numOfSpecificVaccines];
	for (int i = 0; i < numOfSpecificVaccines; i++)
	{
		batchesOfSpecificVaccine[i] = obj.batchesOfSpecificVaccine[i];
	}
	numOfBatchesBought = obj.numOfBatchesBought;
	totalBatchesSupplied = obj.totalBatchesSupplied;
	batchesSupplied = new Batch_Vaccine[totalBatchesSupplied];
	for (int i = 0; i < totalBatchesSupplied; i++)
	{
		batchesSupplied[i].setBatchSize(obj.batchesSupplied[i].getBatchSize());
		batchesSupplied[i].setBatchID(obj.batchesSupplied[i].getBatchID());
		batchesSupplied[i].setVaccinesInBatch(obj.batchesSupplied[i].getVaccines());
	}
}
Supplier::~Supplier()
{
	buyers = nullptr;
	batchesSupplied = nullptr;
}
void Supplier::setTotalBuyers(int total)
{
	totalBuyers = total;
}
void Supplier::setBuyers(Vendor* obj)
{
	buyers = new Vendor[totalBuyers];
	for (int i = 0; i < totalBuyers; i++)
	{
		buyers[i].setEmail(obj[i].getEmail());
		buyers[i].setPassWord(obj[i].getPasWord());
		buyers[i].setFirstName(obj[i].getFirstName());
		buyers[i].setLastName(obj[i].getLastName());
		buyers[i].setPhNum(obj[i].getPhNum());
		buyers[i].setID(obj[i].getID());
		buyers[i].setCNIC(obj[i].getCNIC());
		buyers[i].setAge(obj[i].getAge());
		buyers[i].setCompany(obj[i].getCompany());
		buyers[i].setBatchBought();
	}
}
void Supplier::setBatchesSuppliedToCreate()
{
	bool vaccineFound = false, moreVaccine = false, previousVaccine = false;
	char tempChoice = NULL;
	int indexOfVendorToBuyFrom = 0, * tempBatchesOfSpecificVaccine = nullptr, tempCheckVaccine = 0;
	Batch_Vaccine* tempBatch = nullptr;			//for the purpose of deep copy

	while (!moreVaccine)
	{
		if (vaccineToBuy == " ")
		{
			for (int i = 0; i < numOfDifferentVaccines; i++)
			{
				cout << i + 1 << "." << buyers[i].getCompany().getBatches()[0].getVaccines()->getVacName() << " ";
			}
			cout << "\nEnter Name Of Vaccine to buy: ";
		}
		else
		{
			for (int i = 0; i < numOfDifferentVaccines; i++)
			{
				if (buyers[i].getCompany().getBatches()[0].getVaccines()->getVacName() != vaccineToBuy)
					cout << i + 1 << "." << buyers[i].getCompany().getBatches()[0].getVaccines()->getVacName() << " ";
			}
			cout << "\nEnter Name Of Vaccine to buy: ";
		}
		cin >> vaccineToBuy;
		tempCheckVaccine++;
		numOfSpecificVaccines++;					//for warehouse, so that different batches can be created, knowing how many specific vaccines were supplied and also how many batches each has
		if (previousVaccine)		//if there is the need of storing previous vaccine data 
		{
			tempBatch = new Batch_Vaccine[totalBatchesSupplied];
			for (int i = 0; i < totalBatchesSupplied; i++)
			{
				tempBatch[i].setBatchID(batchesSupplied[i].getBatchID());
				tempBatch[i].setBatchSize(batchesSupplied[i].getBatchSize());
				tempBatch[i].setVaccinesInBatch(batchesSupplied[i].getVaccines());
			}
			delete[]batchesSupplied;
			batchesSupplied = nullptr;
			tempBatchesOfSpecificVaccine = new int[numOfSpecificVaccines - 1];
			for (int i = 0; i < numOfSpecificVaccines - 1; i++)
			{
				tempBatchesOfSpecificVaccine[i] = batchesOfSpecificVaccine[i];
			}
			delete[]batchesOfSpecificVaccine;
			batchesOfSpecificVaccine = nullptr;
		}
		ofstream writePrice;
		writePrice.open("VaccineBudget.txt", ios::app);
		if (!(writePrice.is_open()))
		{
			cout << "Vaccine Budget file cannot open" << endl;
			exit(-1);
		}

		for (int i = 0; i < totalBuyers && (!vaccineFound); i++)
		{
			if (buyers[i].getBatchesBought()->getVaccines()->getVacName() == vaccineToBuy)			//vaccine name stored in batch of vendor is equal to required vaccine
			{
				indexOfVendorToBuyFrom = i;
				vaccineFound = true;
				cout << vaccineToBuy << " has been found" << endl;
				batchesOfSpecificVaccine = new int[numOfSpecificVaccines];
				writePrice << buyers[i].getBatchesBought()->getVaccines()->getVacPrice() << endl;  //write price of vaccine in file
			}
		}
		writePrice.close();

		for (int i = 0; i < numOfSpecificVaccines; i++)
		{
			if (previousVaccine && i < numOfSpecificVaccines - 1)
			{
				batchesOfSpecificVaccine[i] = tempBatchesOfSpecificVaccine[i];
			}
			else
			{
				batchesOfSpecificVaccine[i] = buyers[indexOfVendorToBuyFrom].getCompany().getNumOfBatches();
			}
		}
		numOfBatchesBought += buyers[indexOfVendorToBuyFrom].getCompany().getNumOfBatches();
		batchesSupplied = new Batch_Vaccine[numOfBatchesBought];
		if (previousVaccine)
		{
			for (int i = 0; i < totalBatchesSupplied; i++)
			{
				batchesSupplied[i].setBatchID(tempBatch[i].getBatchID());
				batchesSupplied[i].setBatchSize(tempBatch[i].getBatchSize());
				batchesSupplied[i].setVaccinesInBatch(tempBatch[i].getVaccines());
			}
			delete[]tempBatch;
			tempBatch = nullptr;
		}

		for (int i = totalBatchesSupplied, j = 0; i < numOfBatchesBought; i++, totalBatchesSupplied++, j++)			//so that loop will again run and the previous batch's data is not lost or overridden, totalBatchesSupplied is 0 at first time
		{
			batchesSupplied[i].setBatchID(buyers[indexOfVendorToBuyFrom].getCompany().getBatches()[j].getBatchID());
			batchesSupplied[i].setBatchSize(buyers[indexOfVendorToBuyFrom].getCompany().getBatches()[j].getBatchSize());
			batchesSupplied[i].setVaccinesInBatch(buyers[indexOfVendorToBuyFrom].getCompany().getBatches()[j].getVaccines());
		}


		cout << vaccineToBuy << " has been bought successfully" << endl;
		if (tempCheckVaccine < numOfDifferentVaccines)
		{
			cout << "Do you want to buy another vaccine? (Y or N)  ";
			cin >> tempChoice;			//input validation
			if (tempChoice == 'Y' || tempChoice == 'y')
			{
				vaccineFound = false;
				moreVaccine = false;
				previousVaccine = true;
			}
			else
			{
				moreVaccine = true;
				delete[]tempBatchesOfSpecificVaccine;
				tempBatchesOfSpecificVaccine = nullptr;
			}
		}
		else
		{
			cout << "All vaccines have been accounted for" << endl;
			moreVaccine = true;
			delete[]tempBatchesOfSpecificVaccine;
			tempBatchesOfSpecificVaccine = nullptr;
		}
	}

}

void Supplier::setTotalBatchesSupplied(int total)
{
	totalBatchesSupplied = total;
}
void Supplier::setNumOfSpecificVaccines(int num)
{
	numOfSpecificVaccines = num;
}
void Supplier::setBatchesOfSpecificVaccine(int* arr)
{
	batchesOfSpecificVaccine = new int[numOfSpecificVaccines];
	for (int i = 0; i < numOfSpecificVaccines; i++)
	{
		batchesOfSpecificVaccine[i] = arr[i];
	}
}
void Supplier::setBatchesSuppliedToStore(Batch_Vaccine* obj)
{
	batchesSupplied = new Batch_Vaccine[totalBatchesSupplied];
	for (int i = 0; i < totalBatchesSupplied; i++)
	{
		batchesSupplied[i].setBatchID(obj[i].getBatchID());
		batchesSupplied[i].setBatchSize(obj[i].getBatchSize());
		batchesSupplied[i].setVaccinesInBatch(obj[i].getVaccines());
	}
}
void Supplier::supplierToStore(Supplier& obj)		//deep copy purpose in admin class
{
	firstName = obj.firstName;
	lastName = obj.lastName;
	age = obj.age;
	CNIC = obj.CNIC;
	id = obj.id;
	phoneNum = obj.phoneNum;
	vaccineToBuy = obj.vaccineToBuy;
	totalBuyers = obj.totalBuyers;
	buyers = new Vendor[totalBuyers];
	for (int i = 0; i < totalBuyers; i++)
	{
		buyers[i].setEmail(obj.buyers[i].getEmail());
		buyers[i].setPassWord(obj.buyers[i].getPasWord());
		buyers[i].setFirstName(obj.buyers[i].getFirstName());
		buyers[i].setLastName(obj.buyers[i].getLastName());
		buyers[i].setPhNum(obj.buyers[i].getPhNum());
		buyers[i].setID(obj.buyers[i].getID());
		buyers[i].setCNIC(obj.buyers[i].getCNIC());
		buyers[i].setAge(obj.buyers[i].getAge());
		buyers[i].setCompany(obj.buyers[i].getCompany());
		buyers[i].setBatchBought();
	}
	numOfSpecificVaccines = obj.numOfSpecificVaccines;
	batchesOfSpecificVaccine = new int[numOfSpecificVaccines];
	for (int i = 0; i < numOfSpecificVaccines; i++)
	{
		batchesOfSpecificVaccine[i] = obj.batchesOfSpecificVaccine[i];
	}
	numOfBatchesBought = obj.numOfBatchesBought;
	totalBatchesSupplied = obj.totalBatchesSupplied;
	batchesSupplied = new Batch_Vaccine[totalBatchesSupplied];
	for (int i = 0; i < totalBatchesSupplied; i++)
	{
		batchesSupplied[i].setBatchSize(obj.batchesSupplied[i].getBatchSize());
		batchesSupplied[i].setBatchID(obj.batchesSupplied[i].getBatchID());
		batchesSupplied[i].setVaccinesInBatch(obj.batchesSupplied[i].getVaccines());
	}
}
Batch_Vaccine* Supplier::getBatchesSupplied()
{
	return batchesSupplied;
}
int Supplier::getTotalBuyers()
{
	return totalBuyers;
}
Vendor* Supplier::getBuyers()
{
	return buyers;
}
int Supplier::getTotalBatchesSupplied()
{
	return totalBatchesSupplied;
}
int Supplier::getNumOfSpecificVaccines()
{
	return numOfSpecificVaccines;
}
int* Supplier::getBatchesOfSpecificVaccines()
{
	return batchesOfSpecificVaccine;
}
int Supplier::getNumOfBatchesBought()
{
	return numOfBatchesBought;
}
ostream& operator <<(ostream& out, Supplier& obj)
{
	out << "-----SUPPLIER DATA-----" << endl;
	out << "First name : " << obj.firstName << endl;
	out << "Last name  : " << obj.lastName << endl;
	out << "Age  : " << obj.age << endl;
	out << "CNIC : " << obj.CNIC << endl;
	out << "ID   : " << obj.id << endl;
	out << "Phone Number: " << obj.phoneNum << endl;
	for (int i = 0; i < obj.totalBatchesSupplied; i++)
	{
		out << "Batch " << i + 1 << " supplied ID : " << obj.batchesSupplied[i].getBatchID() << endl;
		out << "Batch " << i + 1 << " supplied size :" << obj.batchesSupplied[i].getBatchSize() << endl;
		out << "Vaccine stored " << obj.batchesSupplied[i].getVaccines()->getVacName() << endl;
	}
	return out;
}
istream& operator >> (istream& in, Supplier& obj)
{
	cout << "------INPUT SUPPLIER-----" << endl;
	cout << "Enter First Name: ";
	in >> obj.firstName;
	cout << "Enter Last Name: ";
	in >> obj.lastName;
	cout << "Enter Age : ";
	in >> obj.age;
	cout << "Enter CNIC: ";
	in >> obj.CNIC;
	cout << "Enter ID  : ";
	in >> obj.id;
	cout << "Enter PhoneNumber: ";
	in >> obj.phoneNum;
	return in;
}
//---------------WAREHOUSE CLASS------------//
Warehouse::Warehouse()
{
	vaccinesStored = 0;
	batchesOfEachVaccineInWare = 0;
	wareName = '\0';
	wareLocation = '\0';
	wareCapacity = 0;
	batchesOfEachVaccineInWare = nullptr;
	wareBatches = nullptr;
}
Warehouse::~Warehouse()
{
	wareBatches = nullptr;
	if (batchesOfEachVaccineInWare)
	{
		//delete[]batchesOfEachVaccineInWare;
		batchesOfEachVaccineInWare = nullptr;
	}
}
void Warehouse::setWareSupplier(Supplier& obj)
{
	wareSupplier.setEmail(obj.getEmail());
	wareSupplier.setPassWord(obj.getPasWord());
	wareSupplier.setAge(obj.getAge());
	wareSupplier.setFirstName(obj.getFirstName());
	wareSupplier.setLastName(obj.getLastName());
	wareSupplier.setID(obj.getID());
	wareSupplier.setCNIC(obj.getCNIC());
	wareSupplier.setPhNum(obj.getPhNum());
	wareSupplier.setTotalBuyers(obj.getTotalBuyers());
	wareSupplier.setBuyers(obj.getBuyers());
	wareSupplier.setTotalBatchesSupplied(obj.getTotalBatchesSupplied());
	wareSupplier.setBatchesSuppliedToStore(obj.getBatchesSupplied());
	wareSupplier.setNumOfSpecificVaccines(obj.getNumOfSpecificVaccines());
	wareSupplier.setBatchesOfSpecificVaccine(obj.getBatchesOfSpecificVaccines());
}
void Warehouse::setWareName(string name)
{
	wareName = name;
}
void Warehouse::setWareLocation(string location)
{
	wareLocation = location;
}
void Warehouse::setWareCapacity(double capacity)
{
	wareCapacity = capacity;
}
void Warehouse::setAuthorizedSupplierID(int id)
{
	supplierID = id;
}
void Warehouse::setBatchesInWare(int batches)
{
	batchesInWare = batches;
}
void Warehouse::setBatchesOfEachVaccineInWare(int* arr)
{
	batchesOfEachVaccineInWare = new int[wareSupplier.getNumOfSpecificVaccines()];
	for (int i = 0; i < wareSupplier.getNumOfSpecificVaccines(); i++)
	{
		batchesOfEachVaccineInWare[i] = arr[i];
	}
}
bool Warehouse::setWareBatchesToCreate()
{
	batchesInWare = wareSupplier.getTotalBatchesSupplied();
	wareBatches = new Batch_Vaccine[batchesInWare];
	batchesOfEachVaccineInWare = new int[wareSupplier.getNumOfSpecificVaccines()];
	for (int i = 0; i < wareSupplier.getNumOfSpecificVaccines(); i++)
	{
		batchesOfEachVaccineInWare[i] = wareSupplier.getBatchesOfSpecificVaccines()[i];
	}
	if (wareSupplier.getID() == supplierID)
	{
		for (int i = 0; i < batchesInWare; i++)
		{
			vaccinesStored += wareSupplier.getBatchesSupplied()[i].getBatchSize();
		}
		if (vaccinesStored <= wareCapacity)
		{
			for (int i = 0; i < batchesInWare; i++)
			{
				wareBatches[i].setBatchID(wareSupplier.getBatchesSupplied()[i].getBatchID());
				wareBatches[i].setBatchSize(wareSupplier.getBatchesSupplied()[i].getBatchSize());
				wareBatches[i].setVaccinesInBatch(wareSupplier.getBatchesSupplied()[i].getVaccines());
			}
			return true;
		}
		else
		{
			cout << "Batch Size exceeds the capacity of Warehouse" << endl;
			return false;
		}
	}
	else
	{
		cout << "Supplier ID not authorized" << endl;
		return false;
	}
}
void Warehouse::setWareBatchesToStore(Batch_Vaccine* obj)
{
	wareBatches = new Batch_Vaccine[batchesInWare];
	for (int i = 0; i < batchesInWare; i++)
	{
		wareBatches[i].setBatchID(obj[i].getBatchID());
		wareBatches[i].setBatchSize(obj[i].getBatchSize());
		wareBatches[i].setVaccinesInBatch(obj[i].getVaccines());
	}
}
void Warehouse::updateWareBatches()
{
	Vaccine tempVacForDepletion;
	tempVacForDepletion.setDoses(0);
	tempVacForDepletion.setExpiryDate(DOB());
	tempVacForDepletion.setPrice(0);
	tempVacForDepletion.setVacID(0);
	tempVacForDepletion.setVacName("This Batch is Depleted");
	tempVacForDepletion.setVacType("NULL");
	Batch_Vaccine* tempBatches = new Batch_Vaccine[batchesInWare];		//previous data to store, then update the wareBatches accordingly
	for (int i = 0; i < batchesInWare; i++)
	{
		tempBatches[i].setBatchID(wareBatches[i].getBatchID());
		tempBatches[i].setBatchSize(wareBatches[i].getBatchSize());
		tempBatches[i].setVaccinesInBatch(wareBatches[i].getVaccines());
	}
	for (int i = 0; i < wareSupplier.getNumOfSpecificVaccines(); i++)
	{
		if (batchesOfEachVaccineInWare[i] > 1)
			batchesInWare -= 1;			//to shrink array, else not to show that batch has been depleted thus we need memory
	}
	delete[]wareBatches;												//to create new array for batches that will be shrinked
	wareBatches = new Batch_Vaccine[batchesInWare];		//to shrink the array, delete one batch of each vaccine
	string differentVacName;
	bool diffVacFound = false;
	for (int i = 0, j = 1, k = 0; i < batchesInWare && j < batchesInWare + numOfDifferentVaccines && k < wareSupplier.getNumOfSpecificVaccines(); i++)		//j and k will be incremented inside loop
	{
		differentVacName = tempBatches[i].getVaccines()->getVacName();
		if (differentVacName == tempBatches[j].getVaccines()->getVacName() && batchesOfEachVaccineInWare[k] > 1)
		{
			wareBatches[i].setBatchID(tempBatches[j].getBatchID());
			wareBatches[i].setBatchSize(tempBatches[j].getBatchSize());
			wareBatches[i].setVaccinesInBatch(tempBatches[j].getVaccines());
			batchesOfEachVaccineInWare[k] -= 1;
			j++;
		}
		else if (batchesOfEachVaccineInWare[++k] > 1)
		{
			wareBatches[i].setBatchID(tempBatches[j + 1].getBatchID());
			wareBatches[i].setBatchSize(tempBatches[j + 1].getBatchSize());
			wareBatches[i].setVaccinesInBatch(tempBatches[j + 1].getVaccines());
			batchesOfEachVaccineInWare[k] -= 1;
			j += 2;
		}
		else
		{
			wareBatches[i].setBatchID(0);
			wareBatches[i].setBatchSize(1);			//to show for depletion as loop terminates without creating anything inside the vaccine info, see setVaccineToCreateBatch function defination
			wareBatches[i].setVaccineToCreateBatch(tempVacForDepletion);
			j++;
		}
	}
	vaccinesStored = 0; //to have new value of vaccines stored in warehouse
	for (int i = 0; i < batchesInWare; i++)		//for updating vaccines stored in warehouse
	{
		if (wareBatches[i].getBatchSize() > 1)			//as 1 is stored for the sentinal value for depleted batches
			vaccinesStored += wareBatches[i].getBatchSize();
	}
}
Supplier& Warehouse::getWareSupplier()
{
	return wareSupplier;
}
string Warehouse::getWareName()
{
	return wareName;
}
string Warehouse::getWareLocation()
{
	return wareLocation;
}
int Warehouse::getAuthorizedSupplierID()
{
	return supplierID;
}
double Warehouse::getWareCapacity()
{
	return wareCapacity;
}
int Warehouse::getBatchesInWare()
{
	return batchesInWare;
}
int* Warehouse::getBatchesOfEachVaccineInWare()
{
	return batchesOfEachVaccineInWare;
}
long long int Warehouse::getVaccinesStored()
{
	return vaccinesStored;
}
Batch_Vaccine* Warehouse::getWareBatches()
{
	return wareBatches;
}

ostream& operator <<(ostream& out, Warehouse& obj)
{
	ofstream writeData;					//write data in file
	writeData.open("WareHouseData.txt", ios::app | ios::out);
	if (!(writeData.is_open()))
	{
		cout << "WareHouse file cannot open" << endl;
		exit(-1);
	}

	out << "-----WAREHOUSE DATA------" << endl;
	writeData << "-----WAREHOUSE DATA------" << endl;
	out << "Warehouse name: " << obj.wareName << endl;
	writeData << "Warehouse name: " << obj.wareName << endl;
	out << "Warehouse Location: " << obj.wareLocation << endl;
	writeData << "Warehouse Location: " << obj.wareLocation << endl;
	out << "Warehouse Capacity: " << obj.wareCapacity << endl;
	writeData << "Warehouse Capacity: " << obj.wareCapacity << endl;
	out << "Warehouse's supplier ID: " << obj.supplierID << endl;
	writeData << "Warehouse's supplier ID: " << obj.supplierID << endl;

	out << "Batches Info:-" << endl;
	writeData << "Batches Info:-" << endl;
	for (int i = 0; i < obj.getBatchesInWare(); i++)
	{
		out << "Batch " << i + 1 << "'s ID stored in warehouse : " << obj.wareBatches[i].getBatchID() << endl;
		writeData << "Batch " << i + 1 << "'s ID stored in warehouse : " << obj.wareBatches[i].getBatchID() << endl;
		out << "Batch " << i + 1 << "'s size stored in warehouse: " << obj.wareBatches[i].getBatchSize() << endl;
		writeData << "Batch " << i + 1 << "'s size stored in warehouse: " << obj.wareBatches[i].getBatchSize() << endl;
		out << "Batch " << i + 1 << "'s vaccine stored in warehouse: " << obj.wareBatches[i].getVaccines()->getVacName() << endl;
		writeData << "Batch " << i + 1 << "'s vaccine stored in warehouse: " << obj.wareBatches[i].getVaccines()->getVacName() << endl;
	}
	out << "Total Vaccines stored: " << obj.vaccinesStored << endl;
	writeData << "Total Vaccines stored: " << obj.vaccinesStored << endl;
	writeData.close();

	return out;
}
istream& operator >> (istream& in, Warehouse& obj)
{
	cout << "------INPUT WAREHOUSE-----" << endl;
	cout << "Enter Warehouse Name: ";
	in >> obj.wareName;
	cin.ignore();
	cout << "Enter Location: ";
	getline(in, obj.wareLocation);
	cout << "Enter Capacity: ";
	in >> obj.wareCapacity;
	cout << "Enter Warehouse's supplier ID: ";
	in >> obj.supplierID;

	return in;
}
//------------COUNTER CLASS----------------//
Counter::Counter()
{
	counterNumber = 0;
	queue = generateRandomQueue();			//global function, will return a random value between 1-10
}
Counter::~Counter()
{

}
void Counter::setCounterNumber(int num)
{
	counterNumber = num;
}
void Counter::setQueue(int q)
{
	queue = q;
}
void Counter::operator++()
{
	queue++;
}
void Counter::operator--()
{
	if (queue - 1 > 0)
	{
		queue--;
	}
}
int Counter::getCounterNumber()
{
	return counterNumber;
}
int Counter::getQueue()
{
	return queue;
}
ostream& operator <<(ostream& out, Counter& obj)
{
	out << "Counter Number: " << obj.counterNumber << endl;
	out << "Queue: " << obj.queue << endl;
	return out;
}
//-------------CITY CLASS-----------//
City::City()
{
	cityName = '\0';
	population = 0;
}
City::~City()
{

}

void City::setCityName(string city)
{
	cityName = city;
}
void City::setPopulation(long long int people)
{
	population = people;
}
string City::getCityName()
{
	return cityName;
}
long long int City::getPopulation()
{
	return population;
}
ostream& operator << (ostream& out, City& obj)
{
	out << "City Name: " << obj.cityName << endl;
	out << "Population: " << obj.population << endl;

	return out;
}
istream& operator >> (istream& in, City& obj)
{
	cout << "-----City Info------" << endl;
	cout << "Enter Name Of City: ";
	in >> obj.cityName;
	cout << "Enter Population of City: ";
	in >> obj.population;
	return in;
}
//---------------VACCINATION CENTER CLASS-------------//
Vaccination_Center::Vaccination_Center()
{
	totalCounters = 0;
	//counterInfo = nullptr;
	//doctors = nullptr;
	stockSize = 0;
	centerName = '\0';
}
Vaccination_Center::~Vaccination_Center()
{
	//delete[]counterInfo;
	//counterInfo = nullptr;
	//doctors = nullptr;
}
void Vaccination_Center::setTotalCounters(int num)
{
	totalCounters = num;
}
void Vaccination_Center::setCounterInfo()
{
	counterInfo = new Counter[totalCounters]; //queue is randomly generated in constructor of counters
	for (int i = 0; i < totalCounters; i++)
	{
		counterInfo[i].setCounterNumber(i + 1);			//Counter 1, Counter 2 etc
	}
}
void Vaccination_Center::setCenter_City(City& obj)
{
	center_City.setCityName(obj.getCityName());
	center_City.setPopulation(obj.getPopulation());
}
void Vaccination_Center::setWarehouse(Warehouse& obj)
{
	assignedWarehouse.setAuthorizedSupplierID(obj.getAuthorizedSupplierID());
	assignedWarehouse.setWareCapacity(obj.getWareCapacity());
	assignedWarehouse.setWareName(obj.getWareName());
	assignedWarehouse.setWareLocation(obj.getWareLocation());
	assignedWarehouse.setWareSupplier(obj.getWareSupplier());
	assignedWarehouse.setBatchesInWare(obj.getBatchesInWare());
	assignedWarehouse.setBatchesOfEachVaccineInWare(obj.getBatchesOfEachVaccineInWare());
	assignedWarehouse.setWareBatchesToStore(obj.getWareBatches());
}
void Vaccination_Center::setStock()
{
	int specificVaccinesToStore = assignedWarehouse.getWareSupplier().getNumOfSpecificVaccines();
	int indexCheckforVaccine = 0;
	stock = new Batch_Vaccine[specificVaccinesToStore];
	string differentVaccineName;				//to only store 1 batch in center, we get each vaccine's batches and since the warehouse has all the batches stored in one pointer, we use different indexes to get to each vaccine's batch info and store it
	bool differentVacFound = false;
	for (int i = 0; i < specificVaccinesToStore; i++)
	{
		if (i == 0)
		{
			stock[i].setBatchID(assignedWarehouse.getWareBatches()[i].getBatchID());
			stock[i].setBatchSize(assignedWarehouse.getWareBatches()[i].getBatchSize());
			stock[i].setVaccinesInBatch(assignedWarehouse.getWareBatches()[i].getVaccines());
			differentVaccineName = stock[i].getVaccines()->getVacName();
			stockSize += stock[i].getBatchSize();
		}
		else
		{
			for (; (indexCheckforVaccine < assignedWarehouse.getWareSupplier().getTotalBatchesSupplied()) && (!differentVacFound); indexCheckforVaccine++)	//indexCheckforVaccine declared above
			{
				if (differentVaccineName == assignedWarehouse.getWareBatches()[indexCheckforVaccine].getVaccines()->getVacName())
					differentVacFound = false;
				else
				{
					stock[i].setBatchID(assignedWarehouse.getWareBatches()[indexCheckforVaccine].getBatchID());
					stock[i].setBatchSize(assignedWarehouse.getWareBatches()[indexCheckforVaccine].getBatchSize());
					stock[i].setVaccinesInBatch(assignedWarehouse.getWareBatches()[indexCheckforVaccine].getVaccines());
					stockSize += stock[i].getBatchSize();
					differentVaccineName = stock[i].getVaccines()->getVacName();
					differentVacFound = true;
				}

			}

		}
		differentVacFound = false;
	}
}
void Vaccination_Center::updateAssignedWarehouse()
{
	assignedWarehouse.updateWareBatches();
}
void Vaccination_Center::setCenterName(string name)
{
	centerName = name;
}
int Vaccination_Center::getTotalCounters()
{
	return totalCounters;
}
Counter* Vaccination_Center::getCounterInfo()
{
	return counterInfo;
}
Batch_Vaccine* Vaccination_Center::getStock()
{
	return stock;
}
int Vaccination_Center::getStockSize()
{
	return stockSize;
}
City& Vaccination_Center::getCenter_City()
{
	return center_City;
}
string Vaccination_Center::getCenterName()
{
	return centerName;
}
Warehouse& Vaccination_Center::getAssignedWare()
{
	return assignedWarehouse;
}
ostream& operator <<(ostream& out, Vaccination_Center& obj)
{
	out << "-------Vaccination Center's Info--------" << endl;
	out << "Name: " << obj.centerName << endl;
	out << "City: " << obj.center_City.getCityName() << endl;
	out << "Population of City: " << obj.center_City.getPopulation() << endl;
	out << "Number of Counters: " << obj.totalCounters << endl;
	out << "Stock Size: " << obj.stockSize << endl;
	out << "---Stock Info---" << endl;
	for (int i = 0; i < obj.assignedWarehouse.getWareSupplier().getNumOfSpecificVaccines(); i++)
	{
		out << "Batch " << i + 1 << " 's ID: " << obj.stock[i].getBatchID() << endl;
		out << "Batch " << i + 1 << " 's Size: " << obj.stock[i].getBatchSize() << endl;
		out << "Batch " << i + 1 << " 's stored vaccine: " << obj.stock[i].getVaccines()->getVacName() << endl;
	}

	return out;
}
istream& operator >>(istream& in, Vaccination_Center& obj)
{
	cout << "-------Input Vaccination Center's Info--------" << endl;
	cout << "Enter Vaccination Center's Name: ";
	in >> obj.centerName;
	cout << "Enter Vaccination Center's total counters: ";
	in >> obj.totalCounters;
	//Doctors will be assigned to each counter through setter getter, FDO as well
	return in;
}
//----------------DOCTOR CLASS---------------//
Doctor::Doctor()
{
	totalDutyDays = 0;
	dutyDays = nullptr;
	assignedCounterNumber = 0;
	citi_BloodPressure = 0;
	citi_GlucoseLevel = 0;
	citi_OxygenLevel = 0;
}
Doctor::~Doctor()
{
	delete[]dutyDays;
	dutyDays = nullptr;
}
void Doctor::setCenter(Vaccination_Center& obj)		//change pending
{
	assigned_Center = obj;
}
void Doctor::setTotalDutyDays(int total)
{
	totalDutyDays = total;
}
void Doctor::setCounterNumber(int counter)
{
	assignedCounterNumber = counter;	//through loop, the appropriate counter number will be assigned to doctor through the vaccination center's member function
}
void Doctor::setDutyDays(string* obj)
{
	dutyDays = obj;
}
void Doctor::setVitals(RegisteredCitizen& obj)
{
	ofstream writeVitals;
	writeVitals.open("CitizenVitals.txt", ios::out);
	if (!(writeVitals.is_open()))
	{
		cout << "Citizen Vital File cannot open" << endl;
		exit(-1);
	}
	string name;
	long long int cnic = 0;
	cout << "--------Vitals Input----------" << endl;
	cout << "Input Name : ";
	cin >> name;
	cout << "Input CNIC = ";
	cin >> cnic;
	cout << "Input Blood Pressure Of Patient: ";
	cin >> citi_BloodPressure;
	cout << "Input Glucose Level Of Patient: ";
	cin >> citi_GlucoseLevel;
	cout << "Input Oxygen Level Of Patient: ";
	cin >> citi_OxygenLevel;
	writeVitals << name << ' ' << cnic << ' ' << citi_BloodPressure << ' ' << citi_GlucoseLevel << ' ' << citi_OxygenLevel << endl;
	//updating dosenumber of citizen in their file
	string email;
	string passWrd;
	string fName;
	string lName;
	long long int regCNIC = 0;
	string phoneNum;
	string bloodTyp;
	string city;
	string state;
	string address;
	DOB dateObj;
	int vacDoseNum = 0;

	ifstream readCitizenFile;
	//open file
	readCitizenFile.open("RegisteredCitizen.txt", ios::in);
	if (!(readCitizenFile.is_open()))
	{
		cout << "regCitizen not open" << endl;
		exit(-1);
	}
	//also create and open a temporary file 
	ofstream writeUpdateCitizen("tempRegCitizen.txt", ios::app);
	if (!(writeUpdateCitizen.is_open()))
	{
		cout << "temporary file cannot open" << endl;
		exit(-1);
	}
	//	//reading data from file
	while (!(readCitizenFile.eof()))
	{
		readCitizenFile >> fName;
		readCitizenFile >> lName;
		readCitizenFile >> email;
		readCitizenFile >> regCNIC;
		readCitizenFile >> address;
		readCitizenFile >> state;
		readCitizenFile >> city;
		readCitizenFile >> phoneNum;
		readCitizenFile >> bloodTyp;
		readCitizenFile >> dateObj.day;
		readCitizenFile >> dateObj.month;
		readCitizenFile >> dateObj.year;
		readCitizenFile >> vacDoseNum;

		if (!(readCitizenFile.eof()))
		{
			if (regCNIC == cnic)
			{
				vacDoseNum = vacDoseNum + 1;
				writeUpdateCitizen << fName << ' ' << lName << ' ' << email << ' ' << regCNIC << ' ';
				writeUpdateCitizen << address << ' ' << state << ' ' << city << ' ' << phoneNum << ' ' << bloodTyp << ' ';
				writeUpdateCitizen << dateObj.day << ' ' << dateObj.month << ' ' << dateObj.year << ' ' << vacDoseNum << endl;
			}
			else
			{
				writeUpdateCitizen << fName << ' ' << lName << ' ' << email << ' ' << regCNIC << ' ' << address << ' ' << state << ' ' << city << ' ' << phoneNum << ' ' << bloodTyp << ' ';
				writeUpdateCitizen << dateObj.day << ' ' << dateObj.month << ' ' << dateObj.year << ' ' << vacDoseNum << endl;
			}
		}
	}
	//closing files
	readCitizenFile.close();
	writeUpdateCitizen.close();
	remove("RegisteredCitizen.txt");
	rename("tempRegCitizen.txt", "temp.txt");

}
void Doctor::setBloodP(float bp)
{
	citi_BloodPressure = bp;
}
void Doctor::setGlucoseL(float gl)
{
	citi_GlucoseLevel = gl;
}
void Doctor::setOxygenL(float ol)
{
	citi_OxygenLevel = ol;
}
float Doctor::getBloodP()
{
	return citi_BloodPressure;
}
float Doctor::getGlucoseL()
{
	return citi_GlucoseLevel;
}
float Doctor::getOxygenL()
{
	return citi_OxygenLevel;
}
int Doctor::getCounterNumber()
{
	return assignedCounterNumber;
}
int Doctor::getTotalDutyDays()
{
	return totalDutyDays;
}
string* Doctor::getDutyDays()
{
	return dutyDays;
}
Vaccination_Center& Doctor::getCenter()
{
	return assigned_Center;
}
string Doctor::getAssignedCenterName()
{
	return (assigned_Center.getCenterName());
}

void Doctor::menuDoctor()
{
	bool flag = true;
	while (flag == true)
	{
		int choice = 0;
		cout << "-------------------------" << endl;
		cout << "     CRUD MENU DOCTOR   " << endl;
		cout << "-------------------------" << endl;
		cout << "1.Register Doctor" << endl;
		cout << "2.Retrieve Doctor's Data" << endl;
		cout << "3.Update Doctor" << endl;
		cout << "4.Delete Doctor" << endl;
		cout << "5.LogOut" << endl;
		cout << endl;

		cout << "Enter Choice = ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			int size = 0;
			Doctor* dObj = nullptr;
			cout << "How many Doctor's you want to create : ";
			cin >> size;
			dObj = new Doctor[size];
			for (int i = 0; i < size; i++)
			{
				dObj[i].signUpEmail();
				dObj[i].createDoctor(dObj[i]);
			}
			break;
		}
		case 2:
		{
			Doctor dObj;
			dObj.showDoctor();
			break;
		}
		case 3:
		{
			Doctor dObj;
			dObj.updateDoctor();
			break;
		}
		case 4:
		{
			Doctor dObj;
			dObj.deleteDoctor();
			break;
		}
		case 5:
		{
			cout << "*****LOG OUT*****" << endl;
			flag = false;
			break;
		}
		default:
		{
			cout << "Wrong Choice...Enter Again" << endl;
			break;
		}
		}
		Sleep(1000);
		system("CLS");
	}
}

ostream& operator <<(ostream& out, Doctor& obj)
{
	out << "------ Doctor's info --------" << endl;
	out << "First name: " << obj.firstName << endl;
	out << "Last name : " << obj.lastName << endl;
	out << "CNIC: " << obj.CNIC << endl;
	out << "ID  :" << obj.id << endl;
	out << "Age : " << obj.age << endl;
	out << "Phone number: " << obj.phoneNum << endl;
	out << "Assigned Center: " << obj.assigned_Center.getCenterName() << endl;
	out << "Assigned Counter: " << obj.assignedCounterNumber << endl;
	out << "Duty days: " << " ";
	for (int i = 0; i < obj.totalDutyDays; i++)
	{
		out << obj.dutyDays[i] << " ";
		if (i < obj.totalDutyDays - 1)
			out << ", ";
	}
	out << endl;

	return out;
}
istream& operator >>(istream& in, Doctor& obj)
{
	cout << "-----Input Doctor's info-----" << endl;
	cout << "Enter First Name: ";
	in >> obj.firstName;
	cout << "Enter Last Name:  ";
	in >> obj.lastName;
	cout << "Enter age:  ";
	in >> obj.age;
	cout << "Enter ID:   ";
	in >> obj.id;
	cout << "Enter CNIC: ";
	in >> obj.CNIC;
	cout << "Enter Phone Number: ";
	in >> obj.phoneNum;
	cout << "Enter total duty days(less than 7): ";			//input validation pending
	in >> obj.totalDutyDays;

	obj.dutyDays = new string[obj.totalDutyDays];

	for (int i = 0; i < obj.totalDutyDays; i++)
	{
		cout << "Enter duty day " << i + 1 << ": ";
		in >> obj.dutyDays[i];
	}
	//rest is done through setters

	return in;
}
void Doctor::signUpEmail()
{
	//string variable to write email & password
	string writeMail;
	string writePasWrd;

	//flag
	bool flag = true;

	//string variables to read email & password from file
	string readMail;
	string readPasWrd;

	//MENU
	cout << "=====SIGN UP Email DOCTOR====" << endl;
	cout << "Enter Email    : ";
	cin >> writeMail;
	cout << "Enter Password : ";
	cin >> writePasWrd;

	//read file object created 
	ifstream readEmail;

	//opening file in reading mode
	readEmail.open("DoctorAccount.txt", ios::in);
	if (!(readEmail.is_open()))
	{
		cout << "DoctorAccount File can not open" << endl;
	}

	//write file object created
	ofstream writeEmail;

	//opening file in append mode 
	//append mode is used to save the email and passwords of all the users
	writeEmail.open("DoctorAccount.txt", ios::app);

	//if file cannot open
	//then showing error message
	if (!(writeEmail.is_open()))
	{
		cout << "DoctorAccount File can not open" << endl;
	}

	//reading data from the file until end of file character not found
	while (!(readEmail.eof()) && flag == true)
	{
		//readEmail object reading mail and password from file
		readEmail >> readMail >> readPasWrd;

		//if readMail variable is not equal to the writeMail variable
		//and readpasWrd variable is not equal to the writePasWrd variable
		//then the flag is true
		if (readMail != writeMail && readPasWrd != writePasWrd)
		{
			flag = true;
		}
		//if readMail variable is equal to the writeMail variable
		//and readpasWrd variable is equal to the writePasWrd variable
		//then the flag is false
		else
		{
			flag = false;
		}
	}
	//flag true means that no similar account exist so user can register 
	if (flag == true)
	{
		writeEmail << writeMail << " " << writePasWrd << endl;
		email = writeMail;
		password = writePasWrd;
		readEmail.close();
		writeEmail.close();

	}
	else if (flag == false)
	{
		cout << "Account already exist" << endl;
		cout << endl;
		//asking the citizen to enter some different account and passWord
		signUpEmail();
	}
}
void Doctor::writeDoctorToFile()
{
	ofstream writeDr;
	//opening the file
	//this file holds Doctor data
	writeDr.open("RegDoctorData.txt", ios::app | ios::out);

	if (!(writeDr.is_open()))
	{
		cout << "RegDoctorData File cannot open" << endl;
	}
	//after opening file writing data to it
	else
	{
		writeDr << firstName << ' ' << lastName << ' ' << CNIC << ' ' << id << ' ' << phoneNum << ' ' << totalDutyDays;
		for (int i = 0; i < totalDutyDays; i++)
		{
			writeDr << ' ' << dutyDays[i];
		}
		writeDr << endl;
	}
}
void Doctor::createDoctor(Doctor dObj)
{
	cin >> dObj;
	cout << "Saving Your Data. Please wait ";
	for (int i = 0; i < 5; i++)
	{
		Sleep(500);
		cout << ".";
	}
	cout << endl;
	system("CLS");
	dObj.writeDoctorToFile();
	cout << "Data Saved Successfully" << endl;
	Sleep(500);
}
void Doctor::readDoctorFile(long long int CNIC)
{
	string fname;
	string lname;
	long long int cnic = 0;
	string phonenum;
	int id = 0;
	int totalDays = 0;
	string* dayName;

	ifstream readDr;
	//opening the file of Doctor data
	readDr.open("RegDoctorData.txt", ios::in);
	if (!(readDr.is_open()))
	{
		cout << "RegDoctorData file cannot open" << endl;
		exit(-1);
	}
	//when the required email matches the loop will be breaked
	bool showflag = false;
	while (!(readDr.eof()) && showflag == false)
	{
		readDr >> fname;
		readDr >> lname;
		readDr >> cnic;
		readDr >> id;
		readDr >> phonenum;
		readDr >> totalDays;
		dayName = new string[totalDays];
		for (int i = 0; i < totalDays; i++)
		{
			readDr >> dayName[i];
		}
		//if the entered email matches will the email of the user in file
		//then show output on screen and flag will be true and loop will be breaked
		if (CNIC == cnic)
		{
			showflag = true;
			cout << endl;
			cout << "------DOCTOR INFORMATION-----" << endl;
			cout << "name   : " << fname << ' ' << lname << endl;
			cout << "cnic   : " << cnic << endl;
			cout << "Id     : " << id << endl;
			cout << "phone number : " << phonenum << endl;
			cout << "Total Duty Days : " << totalDays << endl;
			cout << "Day Name : ";
			for (int i = 0; i < totalDays; i++)
			{
				cout << dayName[i];
				if (i < totalDays - 1)
				{
					cout << " , ";
				}
			}
		}
		delete[]dayName;
		dayName = nullptr;
	}
	readDr.close();
	Sleep(3500);
}
bool Doctor::logInDoctor()
{
	//serach by email
	//first login the email and password;
	bool loginflag = false;
	cout << "enter email: ";
	cin >> this->email;
	cout << "enter password: ";
	cin >> this->password;

	string email;
	string passwrd;
	ifstream reademail;

	reademail.open("DoctorAccount.txt", ios::in);
	if (!(reademail.is_open()))
	{
		cout << "DoctorAccount cannot open" << endl;
		exit(-1);
	}

	//match the email and password
	//if the required account found break the loop
	else
	{
		while ((!(reademail.eof())) && loginflag == false)
		{
			reademail >> email >> passwrd;
			if (email == this->email && passwrd == this->password)
			{
				loginflag = true;
				cout << "sucessfully logged in" << endl;
				Sleep(500);
			}
		}
		if (loginflag == false)
		{
			cout << "******wrong email/password******" << endl;
			exit(-1);
		}
		reademail.close();
	}
	return loginflag;
}
void Doctor::showDoctor()
{
	bool flag = false;
	long long int CNIC = 0;
	Doctor dObj;
	//if FDO log in sucessfully then show his data
	flag = dObj.logInDoctor();
	if (flag == true)
	{
		cout << "Enter your CNIC: "; cin >> CNIC;
		dObj.readDoctorFile(CNIC);
	}
}
void Doctor::updateDoctor()
{
	cout << "-----UPDATE DOCTOR-----" << endl;
	bool flag = false;
	Doctor dObj;
	//if doctor log in sucessfully then update his data
	flag = dObj.logInDoctor();
	//input his cnic to update Doctor
	long long int CNIC = 0;
	cout << "Enter CNIC :  ";
	cin >> CNIC;
	int choice = 0;
	cout << "Select the following options to edit attributes" << endl;
	cout << "1.First Name   2.Last Name  3.CNIC " << endl;
	cout << "4.PhoneNumber  5.Id         6.DutyDays" << endl;
	cout << endl << "Enter Choice : ";
	cin >> choice;

	//update doctor file by passing the CNIC
	//and the choice that which attribute we want to change
	dObj.updateDoctorFile(CNIC, choice);
}
void Doctor::updateDoctorFile(long long int cnic, int choice)
{
	//update file attributes of Doctor
	string fName;
	string lName;
	long long int CNIC = 0;
	string phoneNum;
	int id = 0;
	int totalDays = 0;
	string* dayName = nullptr;

	ifstream readDr;
	//open file
	readDr.open("RegDoctorData.txt", ios::in);
	if (!(readDr.is_open()))
	{
		cout << "DoctorData file cannot open" << endl;
		exit(-1);
	}
	//also create and open a temporary file 
	ofstream writeUpdateDr("tempDoctor.txt", ios::app);
	if (!(writeUpdateDr.is_open()))
	{
		cout << "tempDoctor file cannot open" << endl;
		exit(-1);
	}

	//reading data from file
	while (!(readDr.eof()))
	{
		readDr >> fName;
		readDr >> lName;
		readDr >> CNIC;
		readDr >> id;
		readDr >> phoneNum;
		readDr >> totalDays;
		dayName = new string[totalDays];
		for (int i = 0; i < totalDays; i++)
		{
			readDr >> dayName[i];
		}

		if (!(readDr.eof()))
		{
			//if required account found enter the first name to update
			//the new first name will be written & rest of the attributes remains same
			switch (choice)
			{
			case 1:
			{
				if (CNIC == cnic)
				{
					string newFName;
					cout << "Enter First Name : ";
					cin >> newFName;

					writeUpdateDr << newFName << ' ' << lName << ' ' << CNIC << ' ' << id << ' ' << phoneNum << ' ' << totalDays;
					for (int j = 0; j < totalDays; j++)
					{
						writeUpdateDr << ' ' << dayName[j];
					}
					writeUpdateDr << endl;
				}
				//when account not matches write the old data to temp file 
				else
				{
					writeUpdateDr << fName << ' ' << lName << ' ' << CNIC << ' ' << id << ' ' << phoneNum << ' ' << totalDays << ' ';
					for (int j = 0; j < totalDays; j++)
					{
						writeUpdateDr << ' ' << dayName[j];
					}
					writeUpdateDr << endl;
				}
				break;
			}
			case 2:
			{
				//updating last Name
				string newLName;
				if (CNIC == cnic)
				{

					cout << "Enter Last Name : ";
					cin >> newLName;
					writeUpdateDr << fName << ' ' << newLName << ' ' << CNIC << ' ' << id << ' ' << phoneNum << ' ' << totalDays;
					for (int j = 0; j < totalDays; j++)
					{
						writeUpdateDr << ' ' << dayName[j];
					}
					writeUpdateDr << endl;
				}
				else
				{
					writeUpdateDr << fName << ' ' << lName << ' ' << CNIC << ' ' << id << ' ' << phoneNum << ' ' << totalDays;
					for (int j = 0; j < totalDays; j++)
					{
						writeUpdateDr << ' ' << dayName[j];
					}
					writeUpdateDr << endl;
				}
				break;
			}
			case 3:
			{
				//updating cnic of Doctor
				string newCNIC;
				if (CNIC == cnic)
				{
					cout << "Enter CNIC : ";
					cin >> newCNIC;
					writeUpdateDr << fName << ' ' << lName << ' ' << newCNIC << ' ' << id << ' ' << phoneNum << ' ' << totalDays;
					for (int j = 0; j < totalDays; j++)
					{
						writeUpdateDr << ' ' << dayName[j];
					}
					writeUpdateDr << endl;
				}
				else
				{
					writeUpdateDr << fName << ' ' << lName << ' ' << CNIC << ' ' << id << ' ' << phoneNum << ' ' << totalDays;
					for (int j = 0; j < totalDays; j++)
					{
						writeUpdateDr << ' ' << dayName[j];
					}
					writeUpdateDr << endl;
				}
				break;
			}
			case 4:
			{
				//updating phone number
				string newPhNum;
				if (CNIC == cnic)
				{
					cout << "Enter PhoneNumber : ";
					cin >> newPhNum;
					writeUpdateDr << fName << ' ' << lName << ' ' << CNIC << ' ' << id << ' ' << newPhNum << ' ' << totalDays;
					for (int j = 0; j < totalDays; j++)
					{
						writeUpdateDr << ' ' << dayName[j];
					}
					writeUpdateDr << endl;
				}
				else
				{
					writeUpdateDr << fName << ' ' << lName << ' ' << CNIC << ' ' << id << ' ' << phoneNum << ' ' << totalDays;
					for (int j = 0; j < totalDays; j++)
					{
						writeUpdateDr << ' ' << dayName[j];
					}
					writeUpdateDr << endl;
				}
				break;
			}
			case 5:
			{
				//update id of Doctor
				int newId = 0;
				if (CNIC == cnic)
				{
					cout << "Enter Id : ";
					cin >> newId;
					writeUpdateDr << fName << ' ' << lName << ' ' << CNIC << ' ' << newId << ' ' << phoneNum << ' ' << totalDays;
					for (int j = 0; j < totalDays; j++)
					{
						writeUpdateDr << ' ' << dayName[j];
					}
					writeUpdateDr << endl;
				}
				else
				{
					writeUpdateDr << fName << ' ' << lName << ' ' << CNIC << ' ' << id << ' ' << phoneNum << ' ' << totalDays;
					for (int j = 0; j < totalDays; j++)
					{
						writeUpdateDr << ' ' << dayName[j];
					}
					writeUpdateDr << endl;
				}
				break;
			}
			case 6:
			{
				//updating duty days
				int newtDays = 0;
				string* newDays = nullptr;

				if (CNIC == cnic)
				{
					cout << "Enter totalNumber of duty days: ";
					cin >> newtDays;
					newDays = new string[newtDays];
					for (int i = 0; i < newtDays; i++)
					{
						cout << "Enter day " << i + 1 << " name : ";
						cin >> newDays[i];
					}

					writeUpdateDr << fName << ' ' << lName << ' ' << CNIC << ' ' << id << ' ' << phoneNum << ' ' << newtDays;
					for (int i = 0; i < newtDays; i++)
					{
						writeUpdateDr << ' ' << newDays[i];
					}
					writeUpdateDr << endl;
				}
				else
				{
					writeUpdateDr << fName << ' ' << lName << ' ' << CNIC << ' ' << id << ' ' << phoneNum << ' ' << totalDays;
					for (int j = 0; j < totalDays; j++)
					{
						writeUpdateDr << ' ' << dayName[j];
					}
					writeUpdateDr << endl;
				}
				break;
				delete[]newDays;
				newDays = nullptr;
			}
			default:
			{
				cout << "Invalid Choice " << endl;
				break;
			}
			}

			delete[]dayName;
			dayName = nullptr;
		}
	}
	cout << "Updating Your Data. Please wait ";
	for (int i = 0; i < 5; i++)
	{
		Sleep(500);
		cout << ".";
	}
	cout << endl;
	//closing files
	readDr.close();
	writeUpdateDr.close();

	//since the tempAdmin file is updated version of the RegisteredAdminData file
	//we will remove the RegisteredAdminData file
	//and name temp file as RegisteredAdminData file 
	remove("RegDoctorData.txt");
	rename("tempDoctor.txt", "RegDoctorData.txt");
}

void Doctor::deleteDoctor()
{
	cout << "-----DELETE DOCTOR-----" << endl;
	bool flag = false;
	Doctor dObj;

	//if FDO log in sucessfully then delete his data
	flag = dObj.logInDoctor();
	if (flag == true)
	{
		char choice = '\0';
		cout << "Do you want to delete your account ('y'/'n'): ";
		cin >> choice;
		if (choice == 'y' || choice == 'Y')
		{

			//input his cnic to delete Doctor
			long long int CNIC = 0;
			cout << "Enter CNIC :  ";
			cin >> CNIC;
			dObj.deleteDoctorData(CNIC);
			dObj.deleteDoctorAcc();
		}
		else
		{
			cout << "Account not deleted" << endl;
			return;
		}
	}
}

void Doctor::deleteDoctorData(long long int cnic)
{
	string fName;
	string lName;
	long long int CNIC = 0;
	string phoneNum;
	int id = 0;
	int totalDays = 0;
	string* dayName = nullptr;

	ifstream readDr;
	readDr.open("RegDoctorData.txt", ios::in);
	if (!(readDr.is_open()))
	{
		cout << "DoctorData file not open" << endl;
		exit(-1);
	}
	//creating temporary file 
	ofstream deleteDr("tempDoctor.txt", ios::app);
	if (!(deleteDr.is_open()))
	{
		cout << "tempDoctor file cannot open" << endl;
		exit(-1);
	}
	while (!(readDr.eof()))
	{
		readDr >> fName;
		readDr >> lName;
		readDr >> CNIC;
		readDr >> id;
		readDr >> phoneNum;
		readDr >> totalDays;
		dayName = new string[totalDays];
		for (int i = 0; i < totalDays; i++)
		{
			readDr >> dayName[i];
		}

		//if account found place space in place of that line
		if (!(readDr.eof()))
		{
			if (CNIC == cnic)
			{
				fName = ' ';
				deleteDr << fName << endl;
			}
			//write rest of the accounts as it is 
			else
			{
				deleteDr << fName << ' ' << lName << ' ' << CNIC << ' ' << id << ' ' << phoneNum << ' ' << totalDays;
				for (int i = 0; i < totalDays; i++)
				{
					deleteDr << ' ' << dayName[i];
				}
				deleteDr << endl;
			}
		}
	}

	cout << "Deleting Your Data. Please wait ";
	for (int i = 0; i < 5; i++)
	{
		Sleep(500);
		cout << ".";
	}
	cout << endl;
	readDr.close();
	deleteDr.close();

	//pehle purani file delete karen ge 
	//phir change file name
	remove("RegDoctorData.txt");
	rename("tempDoctor.txt", "RegDoctorData.txt");
}

void Doctor::deleteDoctorAcc()
{
	ifstream readDrAcc;
	//deleting account from file
	readDrAcc.open("DoctorAccount.txt", ios::in);
	if (!(readDrAcc.is_open()))
	{
		cout << "DoctorAccount file not open" << endl;
		exit(-1);
	}
	ofstream deleteEmail("tempAcc.txt", ios::app | ios::out);
	if (!(deleteEmail.is_open()))
	{
		cout << "tempAcc file cannot open" << endl;
		exit(-1);
	}

	string email;
	string passWrd;
	//now reading the file of registered FDO account
	while (!(readDrAcc.eof()))
	{
		readDrAcc >> email;
		readDrAcc >> passWrd;

		if (!(readDrAcc.eof()))
		{
			//if the account is found
			//delete it by placing simple space and write it in temporary file
			if (email == this->email && passWrd == this->password)
			{
				email = ' ';
				deleteEmail << email << endl;
			}
			//write rest of the data as it is in the temporary file
			else
			{
				deleteEmail << email << ' ' << passWrd << endl;
			}
		}
	}
	readDrAcc.close();
	deleteEmail.close();
	//deleting the FDOAccount file then renaming the temporary file as FDOAccount
	//because temporary file is the updated version of FDOAccount
	//pehle purani file delete karen ge 
	//phir change file name
	remove("DoctorAccount.txt");
	rename("tempAcc.txt", "DoctorAccount.txt");
}
//-------------------FDO CLASS---------------------//
FDO::FDO()
{

}
FDO::~FDO()
{

}
void FDO::menuFDO()
{
	bool flag = true;
	while (flag == true)
	{
		int choice = 0;
		cout << "-------------------------" << endl;
		cout << "      CRUD MENU FDO   " << endl;
		cout << "-------------------------" << endl;
		cout << "1.Register FDO" << endl;
		cout << "2.Retrieve Data of FDO" << endl;
		cout << "3.Update FDO" << endl;
		cout << "4.Delete FDO" << endl;
		cout << "5.LogOut" << endl;
		cout << endl;

		cout << "Enter Choice = ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			int size = 0;
			FDO* fObj = nullptr;
			cout << "How many FDO's you want to create : ";
			cin >> size;
			fObj = new FDO[size];
			for (int i = 0; i < size; i++)
			{
				fObj[i].signUpEmail();
				fObj[i].createFDO(fObj[i]);
			}
			break;
		}
		case 2:
		{
			FDO fObj;
			fObj.showFDO();
			break;
		}
		case 3:
		{
			FDO fObj;
			fObj.updateFDO();
			break;
		}
		case 4:
		{
			FDO fObj;
			fObj.deleteFDO();
			break;
		}
		case 5:
		{
			cout << "*****LOG OUT*****" << endl;
			flag = false;
			break;
		}
		default:
		{
			cout << "Wrong Choice...Enter Again" << endl;
			break;
		}
		}
		Sleep(1000);
		system("CLS");
	}
}
void FDO::signUpEmail()
{
	//string variable to write email & password
	string writeMail;
	string writePasWrd;
	//flag
	bool flag = true;
	//string variables to read email & password from file
	string readMail;
	string readPasWrd;
	//MENU
	cout << "=====SIGN UP Email FDO====" << endl;
	cout << "Enter Email    : ";
	cin >> writeMail;
	cout << "Enter Password : ";
	cin >> writePasWrd;

	//read file object created 
	ifstream readEmail;

	//opening file in reading mode
	readEmail.open("FDOAccount.txt", ios::in);
	if (!(readEmail.is_open()))
	{
		cout << "FDOAccount File can not open" << endl;
	}

	//write file object created
	ofstream writeEmail;
	//opening file in append mode 
	//append mode is used to save the email and passwords of all the users
	writeEmail.open("FDOAccount.txt", ios::app);

	//if file cannot open
	//then showing error message
	if (!(writeEmail.is_open()))
	{
		cout << "FDOAccount File can not open" << endl;
	}

	//reading data from the file until end of file character not found
	while (!(readEmail.eof()) && flag == true)
	{
		//readEmail object reading mail and password from file
		readEmail >> readMail >> readPasWrd;

		//if readMail variable is not equal to the writeMail variable
		//and readpasWrd variable is not equal to the writePasWrd variable
		//then the flag is true
		if (readMail != writeMail && readPasWrd != writePasWrd)
		{
			flag = true;
		}
		//if readMail variable is equal to the writeMail variable
		//and readpasWrd variable is equal to the writePasWrd variable
		//then the flag is false
		else
		{
			flag = false;
		}
	}

	//flag true means that no similar account exist so user can register 
	if (flag == true)
	{
		writeEmail << writeMail << " " << writePasWrd << endl;
		email = writeMail;
		password = writePasWrd;
		readEmail.close();
		writeEmail.close();
	}
	else if (flag == false)
	{
		cout << "Account already exist" << endl;
		//asking the citizen to enter some different account and passWord
		signUpEmail();
	}

}
void FDO::writeFDOToFile()
{
	ofstream writeFDO;
	//opening the file
	//this file holds FDO data
	writeFDO.open("RegFDOData.txt", ios::app | ios::out);

	if (!(writeFDO.is_open()))
	{
		cout << "RegFDOData File cannot open" << endl;
	}
	//after opening file writing data to it
	else
	{
		writeFDO << firstName << ' ' << lastName << ' ' << CNIC << ' ' << id << ' ' << phoneNum << endl;
	}
}
void FDO::createFDO(FDO fObj)
{
	cin >> fObj;
	cout << "Saving Your Data. Please wait ";
	for (int i = 0; i < 5; i++)
	{
		Sleep(500);
		cout << ".";
	}
	cout << endl;
	system("CLS");
	fObj.writeFDOToFile();
	cout << "Data Saved Successfully" << endl;
	Sleep(500);
}
void FDO::readFDOFile(long long int CNIC)
{
	string fname;
	string lname;
	long long int cnic = 0;
	string phonenum;
	int id = 0;

	ifstream readFDO;
	//opening the file of citizen data
	readFDO.open("RegFDOData.txt", ios::in);
	if (!(readFDO.is_open()))
	{
		cout << "RegFDOData file cannot open" << endl;
		exit(-1);
	}
	//when the required email matches the loop will be breaked
	bool showflag = false;

	while (!(readFDO.eof()) && showflag == false)
	{
		readFDO >> fname;
		readFDO >> lname;
		readFDO >> cnic;
		readFDO >> id;
		readFDO >> phonenum;
		//if the entered email matches will the email of the user in file
		//then show output on screen and flag will be true and loop will be breaked
		if (CNIC == cnic)
		{
			showflag = true;
			cout << endl;
			cout << "------FDO INFORMATION-----" << endl;
			cout << "name   : " << fname << ' ' << lname << endl;
			cout << "cnic   : " << cnic << endl;
			cout << "Id     : " << id << endl;
			cout << "phone number : " << phonenum << endl;
		}
	}
	readFDO.close();
	Sleep(3500);
}
bool FDO::logInFDO(FDO& fObj)
{
	//serach by email
	//first login the email and password;
	bool loginflag = false;
	cout << "enter email: ";
	cin >> fObj.email;
	cout << "enter password: ";
	cin >> fObj.password;

	string email;
	string passwrd;
	ifstream reademail;

	reademail.open("FDOAccount.txt", ios::in);
	if (!(reademail.is_open()))
	{
		cout << "FDOAccount cannot open" << endl;
		exit(-1);
	}
	//match the email and password
	//if the required account found break the loop
	else
	{
		while ((!(reademail.eof())) && loginflag == false)
		{
			reademail >> email >> passwrd;
			if (email == fObj.email && passwrd == fObj.password)
			{
				loginflag = true;
				cout << "sucessfully logged in" << endl;
				Sleep(500);
			}
		}
		if (loginflag == false)
		{
			cout << "******wrong email/password******" << endl;
			exit(-1);
		}
		reademail.close();
	}
	return loginflag;
}
void FDO::showFDO()
{
	bool flag = false;
	long long int CNIC = 0;
	FDO fObj;
	//if FDO log in sucessfully then show his data
	flag = fObj.logInFDO(fObj);
	if (flag == true)
	{
		cout << "Enter your CNIC: "; cin >> CNIC;
		fObj.readFDOFile(CNIC);
	}
}
void FDO::updateFDO()
{
	cout << "-----UPDATE FDO-----" << endl;
	bool flag = false;
	FDO fObj;
	//if FDO log in sucessfully then update his data
	flag = fObj.logInFDO(fObj);
	//input his cnic to update FDO
	long long int CNIC = 0;
	cout << "Enter CNIC :  ";
	cin >> CNIC;
	int choice = 0;
	cout << "Select the following options to edit attributes" << endl;
	cout << "1.First Name   2.Last Name  3.CNIC " << endl;
	cout << "4.PhoneNumber  5.Id" << endl;
	cout << endl << "Enter Choice : ";
	cin >> choice;

	//update FDO file by passing the CNIC
	//and the choice that which attribute we want to change
	fObj.updateFDOFile(CNIC, choice);
}
void FDO::updateFDOFile(long long int cnic, int choice)
{
	//update file attributes of FDO
	string fName;
	string lName;
	long long int CNIC = 0;
	string phoneNum;
	int id = 0;

	ifstream readFDO;
	//open file
	readFDO.open("RegFDOData.txt", ios::in);
	if (!(readFDO.is_open()))
	{
		cout << "FDOData file cannot open" << endl;
		exit(-1);
	}
	//also create and open a temporary file 
	ofstream writeUpdateFDO("tempFDO.txt", ios::app);
	if (!(writeUpdateFDO.is_open()))
	{
		cout << "tempFDO file cannot open" << endl;
		exit(-1);
	}

	//reading data from file
	while (!(readFDO.eof()))
	{
		readFDO >> fName;
		readFDO >> lName;
		readFDO >> CNIC;
		readFDO >> id;
		readFDO >> phoneNum;

		if (!(readFDO.eof()))
		{
			//if required account found enter the first name to update
			//the new first name will be written & rest of the attributes remains same
			switch (choice)
			{
			case 1:
			{
				if (CNIC == cnic)
				{
					string newFName;
					cout << "Enter First Name : ";
					cin >> newFName;

					writeUpdateFDO << newFName << ' ' << lName << ' ' << CNIC << ' ' << id << ' ' << phoneNum << endl;
				}
				//when account not matches write the old data to temp file 
				else
				{
					writeUpdateFDO << fName << ' ' << lName << ' ' << CNIC << ' ' << id << ' ' << phoneNum << endl;
				}
				break;
			}
			case 2:
			{
				//updating last Name
				string newLName;
				if (CNIC == cnic)
				{

					cout << "Enter Last Name : ";
					cin >> newLName;
					writeUpdateFDO << fName << ' ' << newLName << ' ' << CNIC << ' ' << id << ' ' << phoneNum << endl;
				}
				else
				{
					writeUpdateFDO << fName << ' ' << lName << ' ' << CNIC << ' ' << id << ' ' << phoneNum << endl;
				}
				break;
			}
			case 3:
			{
				//updating cnic of FDO
				string newCNIC;
				if (CNIC == cnic)
				{
					cout << "Enter CNIC : ";
					cin >> newCNIC;
					writeUpdateFDO << fName << ' ' << lName << ' ' << newCNIC << ' ' << id << ' ' << phoneNum << endl;
				}
				else
				{
					writeUpdateFDO << fName << ' ' << lName << ' ' << CNIC << ' ' << id << ' ' << phoneNum << endl;
				}
				break;
			}
			case 4:
			{
				//updating phone number
				string newPhNum;
				if (CNIC == cnic)
				{
					cout << "Enter PhoneNumber : ";
					cin >> newPhNum;
					writeUpdateFDO << fName << ' ' << lName << ' ' << CNIC << ' ' << id << ' ' << newPhNum << endl;
				}
				else
				{
					writeUpdateFDO << fName << ' ' << lName << ' ' << CNIC << ' ' << id << ' ' << phoneNum << endl;
				}
				break;
			}
			case 5:
			{
				//update id of FDO
				int newId = 0;
				if (CNIC == cnic)
				{
					cout << "Enter Id : ";
					cin >> newId;
					writeUpdateFDO << fName << ' ' << lName << ' ' << CNIC << ' ' << newId << ' ' << phoneNum << endl;
				}
				else
				{
					writeUpdateFDO << fName << ' ' << lName << ' ' << CNIC << ' ' << id << ' ' << phoneNum << endl;
				}
				break;
			}
			default:
			{
				cout << "Invalid Choice " << endl;
				break;
			}
			}
		}
	}
	cout << "Updating Your Data. Please wait ";
	for (int i = 0; i < 5; i++)
	{
		Sleep(500);
		cout << ".";
	}
	cout << endl;
	//closing files
	readFDO.close();
	writeUpdateFDO.close();

	//since the tempAdmin file is updated version of the RegisteredAdminData file
	//we will remove the RegisteredAdminData file
	//and name temp file as RegisteredAdminData file 
	remove("RegFDOData.txt");
	rename("tempFDO.txt", "RegFDOData.txt");
}
void FDO::deleteFDO()
{
	cout << "-----DELETE FDO-----" << endl;
	bool flag = false;
	FDO fObj;

	//if FDO log in sucessfully then delete his data
	flag = fObj.logInFDO(fObj);
	if (flag == true)
	{
		char choice = '\0';
		cout << "Do you want to delete your account ('y'/'n'): ";
		cin >> choice;
		if (choice == 'y' || choice == 'Y')
		{
			//input his cnic to delete FDO
			long long int CNIC = 0;
			cout << "Enter CNIC :  ";
			cin >> CNIC;
			fObj.deleteFDOData(CNIC);
			fObj.deleteFDOAcc(fObj);
		}
		else
		{
			cout << "Account not deleted" << endl;
			return;
		}
	}
}
void FDO::deleteFDOData(long long int cnic)
{
	string fName;
	string lName;
	long long int CNIC = 0;
	string phoneNum;
	int id = 0;

	ifstream readFDO;
	readFDO.open("RegFDOData.txt", ios::in);
	if (!(readFDO.is_open()))
	{
		cout << "RegFDOData file not open" << endl;
		exit(-1);
	}
	//creating temporary file 
	ofstream deleteFDO("tempFDO.txt", ios::app);
	if (!(deleteFDO.is_open()))
	{
		cout << "tempFDO file cannot open" << endl;
		exit(-1);
	}
	while (!(readFDO.eof()))
	{
		readFDO >> fName;
		readFDO >> lName;
		readFDO >> CNIC;
		readFDO >> id;
		readFDO >> phoneNum;
		//if account found place space in place of that line
		if (!(readFDO.eof()))
		{
			if (CNIC == cnic)
			{
				fName = ' ';
				deleteFDO << fName << endl;
			}
			//write rest of the accounts as it is 
			else
			{
				deleteFDO << fName << ' ' << lName << ' ' << CNIC << ' ' << id << ' ' << phoneNum << endl;
			}
		}
	}

	//shaska
	cout << "Deleting Your Data. Please wait ";
	for (int i = 0; i < 5; i++)
	{
		Sleep(500);
		cout << ".";
	}
	cout << endl;
	readFDO.close();
	deleteFDO.close();

	//pehle purani file delete karen ge 
	//phir change file name
	remove("RegFDOData.txt");
	rename("tempFDO.txt", "RegFDOData.txt");
}
void FDO::deleteFDOAcc(FDO fObj)
{
	ifstream readFDOAcc;
	//deleting account from file
	readFDOAcc.open("FDOAccount.txt", ios::in);
	if (!(readFDOAcc.is_open()))
	{
		cout << "FDOAccount file not open" << endl;
		exit(-1);
	}
	ofstream deleteEmail("tempFDOAcc.txt", ios::app | ios::out);
	if (!(deleteEmail.is_open()))
	{
		cout << "tempFDOAcc file cannot open" << endl;
		exit(-1);
	}

	string email;
	string passWrd;
	//now reading the file of registered FDO account
	while (!(readFDOAcc.eof()))
	{
		readFDOAcc >> email;
		readFDOAcc >> passWrd;

		if (!(readFDOAcc.eof()))
		{
			//if the account is found
			//delete it by placing simple space and write it in temporary file
			if (email == fObj.email && passWrd == fObj.password)
			{
				email = ' ';
				deleteEmail << email << endl;
			}
			//write rest of the data as it is in the temporary file
			else
			{
				deleteEmail << email << ' ' << passWrd << endl;
			}
		}
	}
	readFDOAcc.close();
	deleteEmail.close();
	//deleting the FDOAccount file then renaming the temporary file as FDOAccount
	//because temporary file is the updated version of FDOAccount
	//pehle purani file delete karen ge 
	//phir change file name
	remove("FDOAccount.txt");
	rename("tempFDOAcc.txt", "FDOAccount.txt");
}
void FDO::setCenter(Vaccination_Center& obj) //change pending
{
	assigned_Centre = obj;
}

bool FDO::checkRegistration(RegisteredCitizen& obj)
{
	bool logInFlag = false;
	string regEmail;
	string regPassWrd;
	cout << "===== CONFIRMING CITIZEN REGISTRATION ======" << endl;
	cout << "        ====== LOG IN PAGE ======" << endl;
	cout << endl;
	cout << "Enter Email =    ";
	cin >> regEmail;
	cout << "Enter Password = ";
	cin >> regPassWrd;

	string email;
	string passWrd;
	ifstream readEmail;
	readEmail.open("RegisteredCitizenAccount.txt", ios::in);
	if (!(readEmail.is_open()))
	{
		cout << "Registered Citizen Account cannot open" << endl;
		exit(-1);
	}

	//match the email and password
	//if the required account found break the loop
	else
	{
		while ((!(readEmail.eof())) && logInFlag == false)
		{
			readEmail >> email >> passWrd;
			if (email == regEmail && passWrd == regPassWrd)
			{
				logInFlag = true;
				cout << "Sucessfully logged in" << endl;
				Sleep(500);
			}
		}
		if (logInFlag == false)
		{
			cout << "******Wrong email/password******" << endl;
		}
		readEmail.close();
	}

	//agar registered account not found then simply cout not registered and end the function...
	//agar registered account match ho gia tou flag true return kare ga
	//phir doctor vitals check kare ga input de ga
	//phir vitals file mein write ho jaen dge
	return logInFlag;

}
int FDO::assignCounter(RegisteredCitizen& obj)			//returning int for indexOfAssignedCounter for Doctor
{
	int indexOfMinQueue = 0;
	for (int i = 1; i < assigned_Centre.getTotalCounters(); i++)
	{
		if (assigned_Centre.getCounterInfo()[i].getQueue() < assigned_Centre.getCounterInfo()[i - 1].getQueue())
			indexOfMinQueue = i;
		else
			indexOfMinQueue = i - 1;
	}
	cout << "You have been assigned to Counter " << indexOfMinQueue + 1 << endl;
	++(assigned_Centre.getCounterInfo()[indexOfMinQueue]);	//++ queue in counter where citizen has been sent to
	return indexOfMinQueue;
}
ostream& operator <<(ostream& out, FDO& obj)
{
	out << "-----Front Desk Officer's info----- " << endl;
	out << "First name: " << obj.firstName << endl;
	out << "Last name: " << obj.lastName << endl;
	out << "CNIC: " << obj.CNIC << endl;
	out << "Phone Number: " << obj.phoneNum << endl;
	out << "Age: " << obj.age << endl;
	out << "ID:" << obj.id << endl;
	out << "Assigned Center: " << obj.assigned_Centre.getCenterName() << endl;
	return out;
}
istream& operator >>(istream& in, FDO& obj)
{
	cout << "-----Input FDO's info-----" << endl;
	cout << "Enter First Name: ";
	in >> obj.firstName;
	cout << "Enter Last Name:  ";
	in >> obj.lastName;
	cout << "Enter age:  ";
	in >> obj.age;
	cout << "Enter ID:   ";
	in >> obj.id;
	cout << "Enter CNIC: ";
	in >> obj.CNIC;
	cout << "Enter PhoneNumber: ";
	in >> obj.phoneNum;
	//center is assigned by setter 
	return in;
}
//---------------------ADMIN CLASS------------------//
Admin::Admin()
{
	totalCities = 0;
	totalDoctors = 0;
	cities = nullptr;
	procuredVaccine = nullptr;
	procuredBatchOfVaccine = nullptr;
	companies = nullptr;
	middlemen = nullptr;
	handlers = nullptr;
	wares = nullptr;
	centers = nullptr;
	doctors = nullptr;
	deskOfficers = nullptr;
}
Admin::~Admin()
{
	/*delete[]procuredVaccine;
	procuredVaccine = nullptr;
	delete[]procuredBatchOfVaccine;
	procuredBatchOfVaccine = nullptr;
	delete[]company;
	company = nullptr;
	delete[]middlemen;
	delete[]handlers;
	delete[]wares;
	delete[]centers;*/
}
//crud menu of admin
void Admin::menuAdmin()
{
	bool flag = true;
	while (flag == true)
	{
		int choice = 0;
		cout << "-------------------------" << endl;
		cout << "    CRUD MENU ADMIN   " << endl;
		cout << "-------------------------" << endl;
		cout << "1.Register Admin" << endl;
		cout << "2.Retrieve Data of Admin" << endl;
		cout << "3.Update Admin" << endl;
		cout << "4.Delete Admin" << endl;
		cout << "5.LogOut" << endl;
		cout << endl;

		cout << "Enter Choice = ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			Admin aObj;
			aObj.signUpEmail();
			aObj.createAdmin(aObj);
			break;
		}
		case 2:
		{
			Admin aObj;
			aObj.showAdmin();
			break;
		}
		case 3:
		{
			Admin aObj;
			aObj.updateAdmin();
			break;
		}
		case 4:
		{
			Admin aObj;
			aObj.deleteAdmin();
			break;
		}
		case 5:
		{
			cout << "*****LOG OUT*****" << endl;
			flag = false;
			break;
		}
		default:
		{
			cout << "Wrong Choice...Enter Again" << endl;
			break;
		}
		}
		Sleep(1000);
		system("CLS");
	}

}
void Admin::signUpEmail()
{
	//string variable to write email & password
	string writeMail;
	string writePasWrd;

	//flag
	bool flag = true;

	//string variables to read email & password from file
	string readMail;
	string readPasWrd;

	//MENU
	//Sleep(300);
	//system("CLS");
	cout << "=====SIGN UP Email ADMIN====" << endl;
	cout << "Enter Email    : ";
	cin >> writeMail;
	cout << "Enter Password : ";
	cin >> writePasWrd;

	//read file object created 
	ifstream readEmail;

	//opening file in reading mode
	readEmail.open("AdminAccount.txt", ios::in);

	//write file object created
	ofstream writeEmail;

	//opening file in append mode 
	//append mode is used to save the email and passwords of all the users
	writeEmail.open("AdminAccount.txt", ios::app);

	//if file cannot open
	//then showing error message
	if (!(writeEmail.is_open()))
	{
		cout << "AdminAccount File can not open" << endl;
	}

	//reading data from the file until end of file character not found
	while (!(readEmail.eof()) && flag == true)
	{
		//readEmail object reading mail and password from file
		readEmail >> readMail >> readPasWrd;

		//if readMail variable is not equal to the writeMail variable
		//and readpasWrd variable is not equal to the writePasWrd variable
		//then the flag is true
		if (readMail != writeMail && readPasWrd != writePasWrd)
		{
			flag = true;
		}
		//if readMail variable is equal to the writeMail variable
		//and readpasWrd variable is equal to the writePasWrd variable
		//then the flag is false
		else
		{
			flag = false;
		}
	}
	//flag true means that no similar account exist so user can register 
	if (flag == true)
	{
		writeEmail << writeMail << " " << writePasWrd << endl;
		email = writeMail;
		password = writePasWrd;
		readEmail.close();
		writeEmail.close();

	}
	else if (flag == false)
	{
		cout << "Account already exist" << endl;
		//asking the citizen to enter some different account and passWord
		signUpEmail();
	}
}
void Admin::writeAdminToFile()
{
	ofstream writeAdmin;
	//opening the file
	//this file holds Admin data
	writeAdmin.open("RegisteredAdminData.txt", ios::app | ios::out);

	if (!(writeAdmin.is_open()))
	{
		cout << "RegisteredAdmin File cannot open" << endl;
	}
	//after opening file writing data to it
	else
	{
		writeAdmin << firstName << ' ' << lastName << ' ' << CNIC << ' ' << id << ' ' << phoneNum << endl;
	}
}
void Admin::readAdminFile(long long int CNIC)
{
	string fname;
	string lname;
	long long int cnic = 0;
	string phonenum;
	int id = 0;

	ifstream readAdmin;
	//opening the file of citizen data
	readAdmin.open("RegisteredAdminData.txt", ios::in);

	if (!(readAdmin.is_open()))
	{
		cout << "RegisteredAdminData file cannot open" << endl;
		exit(-1);
	}

	//when the required email matches the loop will be breaked
	bool showflag = false;

	while (!(readAdmin.eof()) && showflag == false)
	{
		readAdmin >> fname;
		readAdmin >> lname;
		readAdmin >> cnic;
		readAdmin >> id;
		readAdmin >> phonenum;

		//if the entered email matches will the email of the user in file
		//then show output on screen and flag will be true and loop will be breaked
		if (CNIC == cnic)
		{
			showflag = true;
			cout << endl;
			cout << "------ADMIN INFORMATION-----" << endl;
			cout << "name   : " << fname << ' ' << lname << endl;
			cout << "cnic   : " << cnic << endl;
			cout << "Id     : " << id << endl;
			cout << "phone number : " << phonenum << endl;
		}
	}
	readAdmin.close();
	Sleep(4000);
}
void Admin::updateAdminFile(long long int cnic, int choice)
{
	//update file attributes of admin
	string fName;
	string lName;
	long long int CNIC = 0;
	string phoneNum;
	int id = 0;

	ifstream readAdmin;
	//open file
	readAdmin.open("RegisteredAdminData.txt", ios::in);
	if (!(readAdmin.is_open()))
	{
		cout << "adminAccount file cannot open" << endl;
		exit(-1);
	}
	//also create and open a temporary file 
	ofstream writeUpdateAdmin("tempAdmin.txt", ios::app);
	if (!(writeUpdateAdmin.is_open()))
	{
		cout << "temporary admin file cannot open" << endl;
		exit(-1);
	}

	//reading data from file
	while (!(readAdmin.eof()))
	{
		readAdmin >> fName;
		readAdmin >> lName;
		readAdmin >> CNIC;
		readAdmin >> id;
		readAdmin >> phoneNum;

		if (!(readAdmin.eof()))
		{
			//if required account found enter the first name to update
			//the new first name will be written & rest of the attributes remains same

			switch (choice)
			{
			case 1:
			{
				if (CNIC == cnic)
				{
					string newFName;
					cout << "Enter First Name : ";
					cin >> newFName;
					writeUpdateAdmin << newFName << ' ' << lName << ' ' << CNIC << ' ' << id << ' ' << phoneNum << endl;
				}
				//when account not matches write the old data to temp file 
				else
				{
					writeUpdateAdmin << fName << ' ' << lName << ' ' << CNIC << ' ' << id << ' ' << phoneNum << endl;
				}
				break;
			}
			case 2:
			{
				//updating last Name
				string newLName;
				if (CNIC == cnic)
				{
					cout << "Enter Last Name : ";
					cin >> newLName;
					writeUpdateAdmin << fName << ' ' << newLName << ' ' << CNIC << ' ' << id << ' ' << phoneNum << endl;
				}
				else
				{
					writeUpdateAdmin << fName << ' ' << lName << ' ' << CNIC << ' ' << id << ' ' << phoneNum << endl;
				}
				break;
			}
			case 3:
			{
				//updating cnicof admin
				string newCNIC;
				if (CNIC == cnic)
				{
					cout << "Enter CNIC : ";
					cin >> newCNIC;
					writeUpdateAdmin << fName << ' ' << lName << ' ' << newCNIC << ' ' << id << ' ' << phoneNum << endl;
				}
				else
				{
					writeUpdateAdmin << fName << ' ' << lName << ' ' << CNIC << ' ' << id << ' ' << phoneNum << endl;
				}
				break;
			}
			case 4:
			{
				//updating phone number
				string newPhNum;
				if (CNIC == cnic)
				{
					cout << "Enter PhoneNumber : ";
					cin >> newPhNum;
					writeUpdateAdmin << fName << ' ' << lName << ' ' << CNIC << ' ' << id << ' ' << newPhNum << endl;
				}
				else
				{
					writeUpdateAdmin << fName << ' ' << lName << ' ' << CNIC << ' ' << id << ' ' << phoneNum << endl;
				}
				break;
			}
			case 5:
			{
				//update id of Admin
				int newId = 0;
				if (CNIC == cnic)
				{
					cout << "Enter Id : ";
					cin >> newId;
					writeUpdateAdmin << fName << ' ' << lName << ' ' << CNIC << ' ' << newId << ' ' << phoneNum << endl;
				}
				else
				{
					writeUpdateAdmin << fName << ' ' << lName << ' ' << CNIC << ' ' << id << ' ' << phoneNum << endl;
				}
				break;
			}
			default:
			{
				cout << "Invalid Choice " << endl;
				break;
			}
			}
		}
	}

	cout << "Updating Your Data. Please wait ";
	for (int i = 0; i < 5; i++)
	{
		Sleep(500);
		cout << ".";
	}
	cout << endl;
	//closing files
	readAdmin.close();
	writeUpdateAdmin.close();

	//since the tempAdmin file is updated version of the RegisteredAdminData file
	//we will remove the RegisteredAdminData file
	//and name temp file as RegisteredAdminData file 
	remove("RegisteredAdminData.txt");
	rename("tempAdmin.txt", "RegisteredAdminData.txt");
}
bool Admin::logInAdmin(Admin& aObj)
{
	//serach by email
	//first login the email and password
	//Admin aObj;

	bool loginflag = false;

	cout << "enter email: ";
	cin >> aObj.email;
	cout << "enter password: ";
	cin >> aObj.password;

	string email;
	string passwrd;
	ifstream reademail;

	reademail.open("AdminAccount.txt", ios::in);
	if (!(reademail.is_open()))
	{
		cout << "AdminAccount cannot open" << endl;
		exit(-1);
	}
	//match the email and password
	//if the required account found break the loop
	else
	{
		while ((!(reademail.eof())) && loginflag == false)
		{
			reademail >> email >> passwrd;
			if (email == aObj.email && passwrd == aObj.password)
			{
				loginflag = true;
				cout << "sucessfully logged in" << endl;
				//robj.readfromfile(robj.regemail);
				Sleep(500);
			}
		}
		if (loginflag == false)
		{
			cout << "******wrong email/password******" << endl;
			exit(-1);
		}
		reademail.close();
	}
	return loginflag;
}
void Admin::createAdmin(Admin aObj)
{
	cout << "-----CREATE ADMIN-----" << endl;
	cin >> aObj;
	cout << "Saving Your Data. Please wait ";
	for (int i = 0; i < 5; i++)
	{
		Sleep(500);
		cout << ".";
	}
	cout << endl;
	system("CLS");
	aObj.writeAdminToFile();
	cout << "Data Saved Successfully" << endl;
	Sleep(500);
}
void Admin::showAdmin()
{
	bool flag = false;
	long long int CNIC = 0;
	Admin aObj;

	//if admin log in sucessfully then show his data
	flag = aObj.logInAdmin(aObj);
	if (flag == true)
	{
		cout << "Enter your CNIC: "; cin >> CNIC;
		aObj.readAdminFile(CNIC);
	}
}
void Admin::updateAdmin()
{
	cout << "-----UPDATE ADMIN-----" << endl;
	bool flag = false;
	Admin aObj;
	//if admin log in sucessfully then update his data
	flag = aObj.logInAdmin(aObj);
	//input his cnic to update admin
	long long int CNIC = 0;
	cout << "Enter CNIC :  ";
	cin >> CNIC;
	int choice = 0;
	cout << "Select the following options to edit attributes" << endl;
	cout << "1.First Name   2.Last Name  3.CNIC " << endl;
	cout << "4.PhoneNumber  5.Id" << endl;
	cout << endl << "Enter Choice : ";
	cin >> choice;

	//update citizen file by passing the CNIC
	//and the choice that which attribute we want to change
	aObj.updateAdminFile(CNIC, choice);
}
void Admin::deleteAdmin()
{
	cout << "-----DELETE ADMIN-----" << endl;
	bool flag = false;
	Admin aObj;
	//if admin log in sucessfully then delete his data
	flag = aObj.logInAdmin(aObj);
	if (flag == true)
	{
		char choice = '\0';
		cout << "Do you want to delete your account ('y'/'n'): ";
		cin >> choice;
		if (choice == 'y' || choice == 'Y')
		{
			//input his cnic to delete admin
			long long int CNIC = 0;
			cout << "Enter CNIC :  ";
			cin >> CNIC;
			aObj.deleteAdminData(CNIC);
			aObj.deleteAdminAcc(aObj);
		}
		else
		{
			cout << "Account not deleted" << endl;
			return;
		}
	}
}
void Admin::deleteAdminData(long long int cnic)
{
	string fName;
	string lName;
	long long int CNIC = 0;
	string phoneNum;
	int id = 0;

	ifstream readAdmin;
	readAdmin.open("RegisteredAdminData.txt", ios::in);
	if (!(readAdmin.is_open()))
	{
		//change file name
		cout << "RegisteredAdminData file not open" << endl;
		exit(-1);
	}
	//creating temporary file 
	ofstream deleteAdmin("tempAdmin.txt", ios::app);
	if (!(deleteAdmin.is_open()))
	{
		cout << "tempAdmin file cannot open" << endl;
		exit(-1);
	}
	while (!(readAdmin.eof()))
	{
		readAdmin >> fName;
		readAdmin >> lName;
		readAdmin >> CNIC;
		readAdmin >> id;
		readAdmin >> phoneNum;
		//if account found place space in place of that line
		if (!(readAdmin.eof()))
		{
			if (CNIC == cnic)
			{
				fName = ' ';
				deleteAdmin << fName << endl;
			}
			//write rest of the accounts as it is 
			else
			{
				deleteAdmin << fName << ' ' << lName << ' ' << CNIC << ' ' << id << ' ' << phoneNum << endl;
			}
		}
	}
	cout << "Deleting Your Data. Please wait ";
	for (int i = 0; i < 5; i++)
	{
		Sleep(500);
		cout << ".";
	}
	cout << endl;
	readAdmin.close();
	deleteAdmin.close();

	//pehle purani file delete karen ge 
	//phir change file name
	remove("RegisteredAdminData.txt");
	rename("tempAdmin.txt", "RegisteredAdminData.txt");
}
void Admin::deleteAdminAcc(Admin aObj)
{
	ifstream readAdminAcc;
	//deleting account from file
	readAdminAcc.open("AdminAccount.txt", ios::in);
	if (!(readAdminAcc.is_open()))
	{
		//change file name
		cout << "AdminAccount file not open" << endl;
		exit(-1);
	}
	ofstream deleteEmail("temp-Admin-Acc.txt", ios::app | ios::out);
	if (!(deleteEmail.is_open()))
	{
		cout << "tempAdminAcc file cannot open" << endl;
		exit(-1);
	}
	string email;
	string passWrd;
	//now reading the file of registered citizen account
	while (!(readAdminAcc.eof()))
	{
		readAdminAcc >> email;
		readAdminAcc >> passWrd;
		if (!(readAdminAcc.eof()))
		{
			//if the account is found
			//delete it by placing simple space and write it in temporary file
			if (email == aObj.email && passWrd == aObj.password)
			{
				email = ' ';
				deleteEmail << email << endl;
			}
			//write rest of the data as it is in the temporary file
			else
			{
				deleteEmail << email << ' ' << passWrd << endl;
			}
		}
	}
	readAdminAcc.close();
	deleteEmail.close();
	//deleting the AdminAccount file then renaming the temporary file as AdminAccount
	//because temporary file is the updated version of AdminAccount
	//pehle purani file delete karen ge 
	//phir change file name
	remove("AdminAccount.txt");
	rename("temp-Admin-Acc.txt", "AdminAccount.txt");
}
void Admin::adminFunc()					//menu driven
{
	int inputChoice = 0;			//for menu
	bool adminLogOut = false;		//for menu
	while (!adminLogOut)
	{
		if (totalCities == 0)				//when running program the first time, this condition will be true
		{
			cout << "------INPUT VACCINE DATA-------" << endl;
			setNumOfDifferentVaccines();		//calling a global function to set a global variable to work in all classes, input will be taken inside the fucntion, see line 4
		 //creating pointers rather than objects as it becomes easier to return pointer as a object in getter functions

			procuredVaccine = new Vaccine[numOfDifferentVaccines];
			for (int i = 0; i < numOfDifferentVaccines; i++)
			{
				cin >> procuredVaccine[i];
				cout << endl;
				cout << procuredVaccine[i];
			}
			procuredVaccine = procuredVaccine;
			cout << "\n\n";

			procuredBatchOfVaccine = new Batch_Vaccine[numOfDifferentVaccines];
			for (int i = 0; i < numOfDifferentVaccines; i++)
			{
				cin >> procuredBatchOfVaccine[i];
				procuredBatchOfVaccine[i].setVaccineToCreateBatch(procuredVaccine[i]);
				cout << endl;
			}
			cout << "\n\n";


			companies = new Manufacturer[numOfDifferentVaccines];
			for (int i = 0; i < numOfDifferentVaccines; i++)
			{
				cin >> companies[i];		//can create multiple batches
				companies[i].setBatchesToCreate(procuredBatchOfVaccine[i]); 	//different batches can be retrieved but one manufacturer will only create one type of vaccine
				cout << endl;
				cout << companies[i];
			}

			cout << "\n\n";


			middlemen = new Vendor[numOfDifferentVaccines];
			for (int i = 0; i < numOfDifferentVaccines; i++)
			{
				cin >> middlemen[i];
				middlemen[i].setCompany(companies[i]);		//taking manufacturer's object to set the vendor as the buyer from multiple manufacturers
				middlemen[i].setBatchBought();		//the function will get the batch from the manufacturer's object, which has been stored in data member of vendor
				cout << middlemen[i] << endl;
			}
			cout << "\n\n";

			handlers = new Supplier[1];		//first time running so 1 supplier only, later on dynamically increase
			cin >> handlers[0];
			handlers[0].setBuyers(middlemen);		//it will set the vendor in the data member of supplier class
			handlers[0].setBatchesSuppliedToCreate();		//it will set the batchSupplied in the class by using the vendor object which has the batch/batches bought from manufacturer
			cout << handlers[0] << endl;
			cout << "\n\n";


			wares = new Warehouse[1];		//first time running so 1 warehouse only, later on dynamically increase
			cin >> wares[0];
			wares[0].setWareSupplier(handlers[0]);     //set supplier in data member

			if (wares[0].setWareBatchesToCreate())			//set batches through supplier stored in data member, will return true or false 
			{
				cout << "Batch successfuly stored in warehouse" << endl;
			}
			else
			{
				cout << "Batch could not be stored in Warehouse" << endl;
			}

			cout << wares[0] << endl;
			cout << "\n\n";


			bool flag = false;
			cities = new City[1];				//first time running so 1 city only, later on dynamically increase
			while (!flag)
			{
				cin >> cities[0];
				if (cities[0].getPopulation() < 20000)
				{
					cout << "Population must be above 20,000. Enter Another City" << endl;
				}
				else
				{
					flag = true;
					totalCities++;	//for the above condition on line 5134
				}
			}


			centers = new Vaccination_Center[1];		//first time running so 1 center only, later on dynamically increase
			cin >> centers[0];
			centers[0].setCenter_City(cities[0]);
			centers[0].setCounterInfo();		//done implicitly, counter number 1, 2... and also have random 1-10 Queue 
			centers[0].setWarehouse(wares[0]);
			centers[0].setStock();

			cout << centers[0] << endl;
			for (int i = 0; i < centers[0].getTotalCounters(); i++)
			{
				cout << centers[0].getCounterInfo()[i];
			}
			centers[0].updateAssignedWarehouse();
			wares[0].updateWareBatches();		//pending change
			cout << "---------------Updated Warehouse------------- " << endl;
			cout << wares[0] << endl;	//to check if warehouse has been updated

			int tempCounters = centers[0].getTotalCounters();		//by input(>>) of center, we will get the totalCounters value so no setter needed
			doctors = new Doctor[tempCounters];
			totalDoctors += tempCounters;
			for (int i = 0; i < tempCounters; i++)
			{
				cin >> doctors[i];
				doctors[i].setCenter(centers[0]);
				doctors[i].setCounterNumber(centers[0].getCounterInfo()[i].getCounterNumber());		//counter 1, 2 and so on through setter getter
				cout << doctors[i] << endl;
			}

			cout << "\n\n";

			deskOfficers = new FDO[1];
			cin >> deskOfficers[0];
			deskOfficers[0].setCenter(centers[0]);
			cout << deskOfficers[0] << endl;

			cout << "\n\n";
		}
		else
		{
			char temp = ' ';
			system("CLS");
			cout << "---------Admin Menu---------" << endl;
			cout << "First Name Of Admin: " << firstName << endl << "Last Name Of Admin: " << lastName << endl << "ID Of Admin: " << id << endl;
			cout << "Press 1,2,3,4 to select which action to perform: " << endl;
			cout << "1. Create Center for city" << endl;
			cout << "2. Check Stock of Center" << endl;
			cout << "3. Delete Center" << endl;
			cout << "4. Log out" << endl;
			cout << "Input: ";
			cin >> inputChoice;
			switch (inputChoice)
			{
			case 1:
				system("CLS");
				cout << "TO NOTE: Manufacturers and Vendors are already set, the respective batches will come from them" << endl;
				createNewCenter(getDeepCopyOfProcess());	//first deep copy then return deep copy, then the data will be stored first and new info of center and supplier will be inputted
				break;
			case 2:
				system("CLS");
				displayCities();		//show the cities 1. Faisalabad .... etc
				cout << "Enter which city's vaccination center to show stock(Enter number): ";
				cin >> inputChoice;		//input validation pending
				cout << centers[inputChoice - 1] << endl;		//show stock batches and size
				Sleep(800);
				if (centers[inputChoice - 1].getStockSize() < 10)
				{
					cout << "Restock center? (Y or N): ";
					cin >> temp;
					if (temp == 'Y' || temp == 'y')
					{
						centers[inputChoice - 1].setStock();
						centers[inputChoice - 1].updateAssignedWarehouse();
						wares[inputChoice - 1].updateWareBatches();
					}
				}
				break;
			case 3:
				system("CLS");
				displayCities();		//show the cities 1. Faisalabad .... etc
				cout << "Enter which city's vaccination center to delete(Enter number): ";
				cin >> inputChoice;		//input validation pending

				for (int i = 0; i < totalDoctors; i++)
				{
					if (doctors[i].getAssignedCenterName() == centers[inputChoice - 1].getCenterName())
						doctors[i].setFirstName("delete");
				}

				cities[inputChoice - 1].setCityName("delete");
				centers[inputChoice - 1].setCenterName("delete");		//to indicate which center to not copy when creating new array
				deskOfficers[inputChoice - 1].setFirstName("delete");
				wares[inputChoice - 1].setWareName("delete");
				handlers[inputChoice - 1].setFirstName("delete");

				deleteACenter(getDeepCopyOfProcess());			//first deepCopy then return deepCopy to use in shrinking the arrays
				break;
			case 4:
				adminLogOut = true;
				//call function of logout?
				break;
			default:
				cout << "Wrong Input" << endl;
				//input validation pending
			}

		}
	}
}
Admin* Admin::getDeepCopyOfProcess()
{
	Admin* temp;
	temp = new Admin;
	temp->totalDoctors = totalDoctors;
	temp->procuredVaccine = new Vaccine[numOfDifferentVaccines];
	temp->procuredBatchOfVaccine = new Batch_Vaccine[numOfDifferentVaccines];
	temp->companies = new Manufacturer[numOfDifferentVaccines];
	temp->middlemen = new Vendor[numOfDifferentVaccines];
	for (int i = 0; i < numOfDifferentVaccines; i++)
	{
		temp->procuredVaccine[i].setVacName(procuredVaccine[i].getVacName());
		temp->procuredVaccine[i].setVacType(procuredVaccine[i].getVacType());
		temp->procuredVaccine[i].setVacID(procuredVaccine[i].getVacID());
		temp->procuredVaccine[i].setPrice(procuredVaccine[i].getVacPrice());
		temp->procuredVaccine[i].setExpiryDate(procuredVaccine[i].getExpiryDate());
		temp->procuredVaccine[i].setDoses(procuredVaccine[i].getNumberofDoses());

		temp->procuredBatchOfVaccine[i].setBatchID(procuredBatchOfVaccine[i].getBatchID());
		temp->procuredBatchOfVaccine[i].setBatchSize(procuredBatchOfVaccine[i].getBatchSize());
		temp->procuredBatchOfVaccine[i].setVaccinesInBatch(procuredBatchOfVaccine[i].getVaccines());

		temp->companies[i].setEmail(companies[i].getEmail());
		temp->companies[i].setPassWord(companies[i].getPasWord());
		temp->companies[i].setFirstName(companies[i].getFirstName());
		temp->companies[i].setLastName(companies[i].getLastName());
		temp->companies[i].setPhNum(companies[i].getPhNum());
		temp->companies[i].setID(companies[i].getID());
		temp->companies[i].setCNIC(companies[i].getCNIC());
		temp->companies[i].setAge(companies[i].getAge());
		temp->companies[i].setNumOfBatches(companies[i].getNumOfBatches());
		temp->companies[i].setBatchesToStore(companies[i].getBatches());

		temp->middlemen[i].vendorToStore(middlemen[i]);	//copy constructor functionality but called as another function since copy constructor cannot be called explicitly
	}
	temp->handlers = new Supplier[totalCities];
	temp->wares = new Warehouse[totalCities];
	temp->cities = new City[totalCities];
	temp->centers = new Vaccination_Center[totalCities];
	temp->deskOfficers = new FDO[totalCities];
	for (int i = 0; i < totalCities; i++)
	{
		temp->handlers[i].supplierToStore(handlers[i]);

		temp->wares[i].setAuthorizedSupplierID(wares[i].getAuthorizedSupplierID());
		temp->wares[i].setWareCapacity(wares[i].getWareCapacity());
		temp->wares[i].setWareName(wares[i].getWareName());
		temp->wares[i].setWareLocation(wares[i].getWareLocation());
		temp->wares[i].setWareSupplier(temp->handlers[i]);		//after debugging
		temp->wares[i].setBatchesInWare(wares[i].getBatchesInWare());
		temp->wares[i].setBatchesOfEachVaccineInWare(wares[i].getBatchesOfEachVaccineInWare());
		temp->wares[i].setWareBatchesToStore(wares[i].getWareBatches());

		temp->cities[i].setCityName(cities[i].getCityName());
		temp->cities[i].setPopulation(cities[i].getPopulation());

		temp->centers[i].setCenterName(centers[i].getCenterName());
		temp->centers[i].setCenter_City(centers[i].getCenter_City());		//population and name will set
		temp->centers[i].setTotalCounters(centers[i].getTotalCounters());
		temp->centers[i].setCounterInfo();
		temp->centers[i].setWarehouse(centers[i].getAssignedWare());
		temp->centers[i].setStock();

		temp->deskOfficers[i].setEmail(deskOfficers[i].getEmail());
		temp->deskOfficers[i].setPassWord(deskOfficers[i].getPasWord());
		temp->deskOfficers[i].setFirstName(deskOfficers[i].getFirstName());
		temp->deskOfficers[i].setLastName(deskOfficers[i].getLastName());
		temp->deskOfficers[i].setPhNum(deskOfficers[i].getPhNum());
		temp->deskOfficers[i].setID(deskOfficers[i].getID());
		temp->deskOfficers[i].setCNIC(deskOfficers[i].getCNIC());
		temp->deskOfficers[i].setAge(deskOfficers[i].getAge());
		temp->deskOfficers[i].setCenter(temp->centers[i]);
	}
	temp->doctors = new Doctor[totalDoctors];
	for (int i = 0; i < totalDoctors; i++)
	{
		temp->doctors[i].setEmail(doctors[i].getEmail());
		temp->doctors[i].setPassWord(doctors[i].getPasWord());
		temp->doctors[i].setFirstName(doctors[i].getFirstName());
		temp->doctors[i].setLastName(doctors[i].getLastName());
		temp->doctors[i].setPhNum(doctors[i].getPhNum());
		temp->doctors[i].setID(doctors[i].getID());
		temp->doctors[i].setCNIC(doctors[i].getCNIC());
		temp->doctors[i].setAge(doctors[i].getAge());
		temp->doctors[i].setTotalDutyDays(doctors[i].getTotalDutyDays());
		temp->doctors[i].setDutyDays(doctors[i].getDutyDays());
		temp->doctors[i].setCenter(temp->centers[i]);
		temp->doctors[i].setCounterNumber(doctors[i].getCounterNumber());

	}

	return temp;
}
void Admin::createNewCenter(Admin* tempAdmin)
{
	totalCities++;
	int index = totalCities - 1;			//to set the new center at the last index of array
	delete[]handlers;
	handlers = new Supplier[totalCities];
	delete[]wares;
	wares = new Warehouse[totalCities];
	delete[]cities;
	cities = new City[totalCities];
	delete[]centers;
	centers = new Vaccination_Center[totalCities];
	delete[]deskOfficers;
	deskOfficers = new FDO[totalCities];
	delete[]doctors;
	doctors = nullptr;	//will be set later
	for (int i = 0; i < totalCities - 1; i++)		//to store previous centers 
	{
		handlers[i].supplierToStore(tempAdmin->handlers[i]);

		wares[i].setAuthorizedSupplierID(tempAdmin->wares[i].getAuthorizedSupplierID());
		wares[i].setWareCapacity(tempAdmin->wares[i].getWareCapacity());
		wares[i].setWareName(tempAdmin->wares[i].getWareName());
		wares[i].setWareLocation(tempAdmin->wares[i].getWareLocation());
		wares[i].setWareSupplier(handlers[i]);
		wares[i].setBatchesInWare(tempAdmin->wares[i].getBatchesInWare());
		wares[i].setBatchesOfEachVaccineInWare(tempAdmin->wares[i].getBatchesOfEachVaccineInWare());
		wares[i].setWareBatchesToStore(tempAdmin->wares[i].getWareBatches());

		cities[i].setCityName(tempAdmin->cities[i].getCityName());
		cities[i].setPopulation(tempAdmin->cities[i].getPopulation());

		centers[i].setCenterName(tempAdmin->centers[i].getCenterName());
		centers[i].setCenter_City(tempAdmin->centers[i].getCenter_City());		//population and name will set
		centers[i].setTotalCounters(tempAdmin->centers[i].getTotalCounters());
		centers[i].setCounterInfo();
		centers[i].setWarehouse(tempAdmin->centers[i].getAssignedWare());
		centers[i].setStock();

		deskOfficers[i].setEmail(tempAdmin->deskOfficers[i].getEmail());
		deskOfficers[i].setPassWord(tempAdmin->deskOfficers[i].getPasWord());
		deskOfficers[i].setFirstName(tempAdmin->deskOfficers[i].getFirstName());
		deskOfficers[i].setLastName(tempAdmin->deskOfficers[i].getLastName());
		deskOfficers[i].setPhNum(tempAdmin->deskOfficers[i].getPhNum());
		deskOfficers[i].setID(tempAdmin->deskOfficers[i].getID());
		deskOfficers[i].setCNIC(tempAdmin->deskOfficers[i].getCNIC());
		deskOfficers[i].setAge(tempAdmin->deskOfficers[i].getAge());
		deskOfficers[i].setCenter(centers[i]);
	}


	cin >> handlers[index];
	handlers[index].setBuyers(middlemen);		//it will set the vendor in the data member of supplier class
	handlers[index].setBatchesSuppliedToCreate();		//it will set the batchSupplied in the class by using the vendor object which has the batch/batches bought from manufacturer
	cout << handlers[index] << endl;
	cout << "\n\n";


	cin >> wares[index];
	wares[index].setWareSupplier(handlers[index]);     //set supplier in data member

	if (wares[index].setWareBatchesToCreate())			//set batches through supplier stored in data member, will return true or false 
	{
		cout << "Batch successfuly stored in warehouse" << endl;
	}
	else
	{
		cout << "Batch could not be stored in Warehouse" << endl;
	}

	cout << wares[index] << endl;
	cout << "\n\n";


	bool flag = false;
	while (!flag)
	{
		cin >> cities[index];
		if (cities[index].getPopulation() < 20000)
		{
			cout << "Population must be above 20,000. Enter Another City" << endl;
		}
		else
		{
			flag = true;
		}
	}

	cin >> centers[index];
	centers[index].setCenter_City(cities[index]);
	centers[index].setCounterInfo();		//done implicitly, counter number 1, 2... and also have random 1-10 Queue 
	centers[index].setWarehouse(wares[index]);
	centers[index].setStock();

	cout << centers[index] << endl;
	for (int i = 0; i < centers[index].getTotalCounters(); i++)
	{
		cout << centers[index].getCounterInfo()[i];
	}
	wares[index].updateWareBatches();
	cout << "---------------Updated Warehouse------------- " << endl;
	cout << wares[index] << endl;	//to check if warehouse has been updated

	int tempCounters = centers[index].getTotalCounters();		//by input(>>) of center, we will get the totalCounters value so no setter needed
	doctors = new Doctor[tempCounters + totalDoctors];		//as doctors already exist so extending array
	for (int i = 0; i < totalDoctors; i++)		//to store previous doctors data
	{
		doctors[i].setEmail(tempAdmin->doctors[i].getEmail());
		doctors[i].setPassWord(tempAdmin->doctors[i].getPasWord());
		doctors[i].setFirstName(tempAdmin->doctors[i].getFirstName());
		doctors[i].setLastName(tempAdmin->doctors[i].getLastName());
		doctors[i].setPhNum(tempAdmin->doctors[i].getPhNum());
		doctors[i].setID(tempAdmin->doctors[i].getID());
		doctors[i].setCNIC(tempAdmin->doctors[i].getCNIC());
		doctors[i].setAge(tempAdmin->doctors[i].getAge());
		doctors[i].setCenter(tempAdmin->doctors[i].getCenter());
		doctors[i].setCounterNumber(tempAdmin->doctors[i].getCounterNumber());
	}
	totalDoctors += tempCounters;
	for (int i = totalDoctors - tempCounters, j = 0; i < totalDoctors; i++, j++)
	{
		cin >> doctors[i];
		doctors[i].setCenter(centers[index]);
		doctors[i].setCounterNumber(centers[index].getCounterInfo()[j].getCounterNumber());		//counter 1, 2 and so on through setter getter
		cout << doctors[i] << endl;
	}

	cout << "\n\n";

	cin >> deskOfficers[index];
	deskOfficers[index].setCenter(centers[index]);
	cout << deskOfficers[index] << endl;

	//delete tempAdmin;
	tempAdmin = nullptr;

	cout << "\n\n";
}
void Admin::deleteACenter(Admin* tempAdmin)
{
	totalCities--;
	delete[]handlers;
	handlers = new Supplier[totalCities];
	delete[]wares;
	wares = new Warehouse[totalCities];
	delete[]centers;
	centers = new Vaccination_Center[totalCities];
	delete[]deskOfficers;
	deskOfficers = new FDO[totalCities];
	delete[]doctors;
	doctors = nullptr;	//will be set later

	int tempDeleteCounters = 0;

	for (int i = 0; i < totalCities + 1; i++)	//since tempAdmin has the previous deep Copy, on one index, data will not be stored so totalCities--
	{
		if (tempAdmin->centers[i].getCenterName() != "delete")
		{
			if (tempAdmin->handlers[i].getFirstName() != "delete")
				handlers[i].supplierToStore(tempAdmin->handlers[i]);

			if (tempAdmin->wares[i].getWareName() != "delete")
			{
				wares[i].setAuthorizedSupplierID(tempAdmin->wares[i].getAuthorizedSupplierID());
				wares[i].setWareCapacity(tempAdmin->wares[i].getWareCapacity());
				wares[i].setWareName(tempAdmin->wares[i].getWareName());
				wares[i].setWareLocation(tempAdmin->wares[i].getWareLocation());
				wares[i].setWareSupplier(handlers[i]);
				wares[i].setBatchesInWare(tempAdmin->wares[i].getBatchesInWare());
				wares[i].setBatchesOfEachVaccineInWare(tempAdmin->wares[i].getBatchesOfEachVaccineInWare());
				wares[i].setWareBatchesToStore(tempAdmin->wares[i].getWareBatches());
			}
			if (tempAdmin->cities[i].getCityName() != "delete")
			{
				cities[i].setCityName(tempAdmin->cities[i].getCityName());
				cities[i].setPopulation(tempAdmin->cities[i].getPopulation());
			}

			if (tempAdmin->centers[i].getCenterName() != "delete")
			{
				centers[i].setCenterName(tempAdmin->centers[i].getCenterName());
				centers[i].setCenter_City(tempAdmin->centers[i].getCenter_City());		//population and name will set
				centers[i].setTotalCounters(tempAdmin->centers[i].getTotalCounters());
				centers[i].setCounterInfo();
				centers[i].setWarehouse(tempAdmin->centers[i].getAssignedWare());
				centers[i].setStock();
			}



			if (tempAdmin->deskOfficers[i].getFirstName() != "delete")
			{
				deskOfficers[i].setEmail(tempAdmin->deskOfficers[i].getEmail());
				deskOfficers[i].setPassWord(tempAdmin->deskOfficers[i].getPasWord());
				deskOfficers[i].setFirstName(tempAdmin->deskOfficers[i].getFirstName());
				deskOfficers[i].setLastName(tempAdmin->deskOfficers[i].getLastName());
				deskOfficers[i].setPhNum(tempAdmin->deskOfficers[i].getPhNum());
				deskOfficers[i].setID(tempAdmin->deskOfficers[i].getID());
				deskOfficers[i].setCNIC(tempAdmin->deskOfficers[i].getCNIC());
				deskOfficers[i].setAge(tempAdmin->deskOfficers[i].getAge());
				deskOfficers[i].setCenter(centers[i]);
			}
		}
		else
			tempDeleteCounters -= tempAdmin->getCenters()[i].getTotalCounters();	//for doctors
	}

	totalDoctors -= tempDeleteCounters;
	doctors = new Doctor[totalDoctors];
	for (int i = 0; i < totalDoctors + tempDeleteCounters; i++)	//deep copy purpose
	{
		if (tempAdmin->doctors[i].getFirstName() != "delete")
		{
			doctors[i].setEmail(tempAdmin->doctors[i].getEmail());
			doctors[i].setPassWord(tempAdmin->doctors[i].getPasWord());
			doctors[i].setFirstName(tempAdmin->doctors[i].getFirstName());
			doctors[i].setLastName(tempAdmin->doctors[i].getLastName());
			doctors[i].setPhNum(tempAdmin->doctors[i].getPhNum());
			doctors[i].setID(tempAdmin->doctors[i].getID());
			doctors[i].setCNIC(tempAdmin->doctors[i].getCNIC());
			doctors[i].setAge(tempAdmin->doctors[i].getAge());
			doctors[i].setCenter(tempAdmin->doctors[i].getCenter());
			doctors[i].setCounterNumber(tempAdmin->doctors[i].getCounterNumber());
		}
	}

	//delete tempAdmin;
	tempAdmin = nullptr;
}
void Admin::displayProcuredVaccine()
{
	for (int i = 0; i < numOfDifferentVaccines; i++)
	{
		cout << "Vaccine " << i + 1 << " info that will be created into batches: " << endl;
		cout << procuredVaccine[i] << endl;
	}
}
void Admin::displayProcuredBatch()
{
	for (int i = 0; i < numOfDifferentVaccines; i++)
	{
		cout << "------Batch " << char(65 + i) << " 's info----- " << endl;  //Batch A's info Batch B's info etc.
		cout << procuredBatchOfVaccine[i] << endl;
	}
}
void Admin::displayCompanies()
{
	for (int i = 0; i < numOfDifferentVaccines; i++)
	{
		cout << "----Manufacturer " << i + 1 << " 's info-----" << endl;
		cout << companies[i] << endl;
	}
}
void Admin::displayMiddlemen()
{
	for (int i = 0; i < numOfDifferentVaccines; i++)
	{
		cout << "----Vendor " << i + 1 << " 's info-----" << endl;
		cout << middlemen[i] << endl;
	}
}
void Admin::displayHandler(Vaccination_Center& obj)
{
	cout << "----Supplier info---- " << endl;
	cout << obj.getAssignedWare().getWareSupplier() << endl;
}
void Admin::displayWare(Vaccination_Center& obj)
{
	cout << "----Warehouse info---- " << endl;
	cout << obj.getAssignedWare() << endl;
}
void Admin::displayCenter(int index)
{
	cout << "-----Vaccination Center Info------" << endl;
	cout << centers[index] << endl;
}
void Admin::displayCities()
{
	for (int i = 0; i < totalCities; i++)
	{
		cout << i + 1 << ". " << cities[i].getCityName() << endl;
	}
}
void Admin::displayDoctors()
{
	for (int i = 0; i < totalDoctors; i++)
	{
		cout << doctors[i] << endl;
	}
}
void Admin::displayFDO()
{
	for (int i = 0; i < totalCities; i++)
	{
		cout << deskOfficers[i] << endl;
	}
}
Vaccination_Center* Admin::getCenters()
{
	return centers;
}
Doctor* Admin::getDoctors()
{
	return doctors;
}
FDO* Admin::getDeskOfficers()
{
	return deskOfficers;
}
int Admin::getTotalCities()
{
	return totalCities;
}
ostream& operator <<(ostream& out, const Admin& obj)
{
	cout << "----Admin Data----" << endl;
	cout << "First Name: " << obj.firstName << endl;
	cout << "Last  Name: " << obj.lastName << endl;
	cout << "Age : " << obj.age << endl;
	cout << "CNIC: " << obj.CNIC << endl;
	cout << "ID  : " << obj.id << endl;
	cout << "PhoneNumber: " << obj.phoneNum << endl;
	cout << endl;
	return out;
}
istream& operator >>(istream& in, Admin& obj)
{
	cout << "-----Input Admin------" << endl;
	cout << "Enter First Name : ";
	in >> obj.firstName;
	cout << "Enter Last Name  : ";
	in >> obj.lastName;
	cout << "Enter Age : ";
	in >> obj.age;
	cout << "Enter ID  : ";
	in >> obj.id;
	cout << "Enter CNIC: ";
	in >> obj.CNIC;
	cout << "Enter PhoneNumber : ";
	in >> obj.phoneNum;
	return in;
}
//----------GOVT OFFICAL CLASS--------------//
GovtOffical::GovtOffical()
{
	amountSpent = 0;
	totalPopulation = 200000;
	partiallyVacc = 0;
	fullyVacc = 0;
	boosterVacc = 0;
	vaccPopulation = 0;
	nonVaccinatedPopulation = 0;
	percVaccPopulation = 0;
	perNonVaccPopulation = 0;
}
GovtOffical::~GovtOffical()
{
}
void GovtOffical::menuGovtOff()
{
	bool flag = true;
	while (flag == true)
	{
		int choice = 0;
		cout << "-------------------------" << endl;
		cout << "  CRUD MENU GOVT OFFICAL " << endl;
		cout << "-------------------------" << endl;
		cout << "1.Register Govt. Offical" << endl;
		cout << "2.Retrieve Data of Govt. Offical" << endl;
		cout << "3.Update Govt. Offical" << endl;
		cout << "4.Delete Govt. Offical" << endl;
		cout << "5.LogOut" << endl;
		cout << endl;
		cout << "Enter Choice = ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			GovtOffical gObj;
			gObj.signUpEmail();
			gObj.createOffical(gObj);
			break;
		}
		case 2:
		{
			GovtOffical gObj;
			gObj.showOffical();
			break;
		}
		case 3:
		{
			GovtOffical gObj;
			gObj.updateGovtOff();
			break;
		}
		case 4:
		{
			GovtOffical gObj;
			gObj.deleteGovtOffical();
			break;
		}
		case 5:
		{
			cout << "*****LOG OUT*****" << endl;
			flag = false;
			break;
		}
		default:
		{
			cout << "Wrong Choice...Enter Again" << endl;
			break;
		}
		}
		Sleep(1000);
		system("CLS");
	}
}
ostream& operator <<(ostream& out, const GovtOffical& obj)
{
	cout << "----Govt Offical Data----" << endl;
	cout << "First Name: " << obj.firstName << endl;
	cout << "Last  Name: " << obj.lastName << endl;
	cout << "Age : " << obj.age << endl;
	cout << "CNIC: " << obj.CNIC << endl;
	cout << "ID  : " << obj.id << endl;
	cout << "PhoneNumber: " << obj.phoneNum << endl;
	cout << endl;
	return out;
}
istream& operator >>(istream& in, GovtOffical& obj)
{
	//cout << "-----Input Govt Offical------" << endl;
	cout << "Enter First Name : ";
	in >> obj.firstName;
	cout << "Enter Last Name  : ";
	in >> obj.lastName;
	cout << "Enter Age : ";
	in >> obj.age;
	cout << "Enter ID  : ";
	in >> obj.id;
	cout << "Enter CNIC: ";
	in >> obj.CNIC;
	cout << "Enter PhoneNumber : ";
	in >> obj.phoneNum;
	return in;
}
void GovtOffical::signUpEmail()
{
	//string variable to write email & password
	string writeMail;
	string writePasWrd;
	//flag
	bool flag = true;
	//string variables to read email & password from file
	string readMail;
	string readPasWrd;
	cout << "=====SIGN UP Email GOVT. Offical====" << endl;
	cout << "Enter Email    : ";
	cin >> writeMail;
	cout << "Enter Password : ";
	cin >> writePasWrd;
	//read file object created 
	ifstream readEmail;
	//opening file in reading mode
	readEmail.open("GovtOfficalAccount.txt", ios::in);
	//write file object created
	ofstream writeEmail;
	//opening file in append mode 
	//append mode is used to save the email and passwords of all the users
	writeEmail.open("GovtOfficalAccount.txt", ios::app);
	//if file cannot open
	//then showing error message
	if (!(writeEmail.is_open()))
	{
		cout << "GovtOfficalAccount File can not open" << endl;
	}
	//reading data from the file until end of file character not found
	while (!(readEmail.eof()) && flag == true)
	{
		//readEmail object reading mail and password from file
		readEmail >> readMail >> readPasWrd;
		//if readMail variable is not equal to the writeMail variable
		//and readpasWrd variable is not equal to the writePasWrd variable
		//then the flag is true
		if (readMail != writeMail && readPasWrd != writePasWrd)
		{
			flag = true;
		}
		//if readMail variable is equal to the writeMail variable
		//and readpasWrd variable is equal to the writePasWrd variable
		//then the flag is false
		else
		{
			flag = false;
		}
	}
	//flag true means that no similar account exist so user can register 
	if (flag == true)
	{
		writeEmail << writeMail << " " << writePasWrd << endl;
		email = writeMail;
		password = writePasWrd;
		readEmail.close();
		writeEmail.close();

	}
	else if (flag == false)
	{
		cout << "Account already exist" << endl;
		//asking the citizen to enter some different account and passWord
		signUpEmail();
	}
}
void GovtOffical::writeOfficalToFile()
{
	ofstream writeOffical;
	//opening the file
	//this file holds Admin data
	writeOffical.open("GovtOfficalData.txt", ios::app | ios::out);
	if (!(writeOffical.is_open()))
	{
		cout << "GovtOfficalData File cannot open" << endl;
	}
	//after opening file writing data to it
	else
	{
		writeOffical << firstName << ' ' << lastName << ' ' << CNIC << ' ' << id << ' ' << phoneNum << endl;
	}
}
void GovtOffical::createOffical(GovtOffical gObj)
{
	cout << "-----CREATE GOVT Offical-----" << endl;
	cin >> gObj;
	cout << "Saving Your Data. Please wait ";
	for (int i = 0; i < 5; i++)
	{
		Sleep(500);
		cout << ".";
	}
	cout << endl;
	system("CLS");
	gObj.writeOfficalToFile();
	cout << "Data Saved Successfully" << endl;
	Sleep(500);
}
bool GovtOffical::logInOffical(GovtOffical& gObj)
{
	//serach by email
	//first login the email and password
	bool loginflag = false;
	cout << "Enter Email: ";
	cin >> gObj.email;
	cout << "Enter Password: ";
	cin >> gObj.password;
	string email;
	string passwrd;
	ifstream reademail;
	reademail.open("GovtOfficalAccount.txt", ios::in);
	if (!(reademail.is_open()))
	{
		cout << "GovtOfficalAccount file cannot open" << endl;
		exit(-1);
	}
	//match the email and password
	//if the required account found break the loop
	else
	{
		while ((!(reademail.eof())) && loginflag == false)
		{
			reademail >> email >> passwrd;
			if (email == gObj.email && passwrd == gObj.password)
			{
				loginflag = true;
				cout << "sucessfully logged in" << endl;
				Sleep(500);
			}
		}
		if (loginflag == false)
		{
			cout << "******wrong email/password******" << endl;
			exit(-1);

		}
		reademail.close();
	}
	return loginflag;
}
void GovtOffical::updateGovtOff()
{
	cout << "-----UPDATE GOVT OFFICAL-----" << endl;
	bool flag = false;
	GovtOffical gObj;
	//if govtOffical log in sucessfully then update his data
	flag = gObj.logInOffical(gObj);
	//input his cnic to update govt offical
	long long int CNIC = 0;
	cout << "Enter CNIC :  ";
	cin >> CNIC;
	int choice = 0;
	cout << "Select the following options to edit attributes" << endl;
	cout << "1.First Name   2.Last Name  3.CNIC " << endl;
	cout << "4.PhoneNumber  5.Id" << endl;
	cout << endl << "Enter Choice : ";
	cin >> choice;
	//update govt offical file by passing the CNIC
	//and the choice that which attribute we want to change
	gObj.updateGovtFile(CNIC, choice);
}
void GovtOffical::updateGovtFile(long long int cnic, int choice)
{
	bool updFlag = false;
	//update file attributes of admin
	string fName;
	string lName;
	long long int CNIC = 0;
	string phoneNum;
	int id = 0;
	ifstream readGovt;
	//open file
	readGovt.open("GovtOfficalData.txt", ios::in);
	if (!(readGovt.is_open()))
	{
		cout << "GovtOfficalData file cannot open" << endl;
		exit(-1);
	}
	//also create and open a temporary file 
	ofstream writeUpdateGovt("tempGovtOff.txt", ios::app);
	if (!(writeUpdateGovt.is_open()))
	{
		cout << "temporary Govt Offical file cannot open" << endl;
		exit(-1);
	}

	//reading data from file
	while (!(readGovt.eof()))
	{
		readGovt >> fName;
		readGovt >> lName;
		readGovt >> CNIC;
		readGovt >> id;
		readGovt >> phoneNum;
		if (!(readGovt.eof()))
		{
			//if required account found enter the first name to update
			//the new first name will be written & rest of the attributes remains same
			switch (choice)
			{
			case 1:
			{
				if (CNIC == cnic)
				{
					updFlag = true;
					string newFName;
					cout << "Enter First Name : ";
					cin >> newFName;
					writeUpdateGovt << newFName << ' ' << lName << ' ' << CNIC << ' ' << id << ' ' << phoneNum << endl;
				}
				//when account not matches write the old data to temp file 
				else
				{
					writeUpdateGovt << fName << ' ' << lName << ' ' << CNIC << ' ' << id << ' ' << phoneNum << endl;
				}
				break;
			}
			case 2:
			{
				//updating last Name
				string newLName;
				if (CNIC == cnic)
				{
					updFlag = true;
					cout << "Enter Last Name : ";
					cin >> newLName;
					writeUpdateGovt << fName << ' ' << newLName << ' ' << CNIC << ' ' << id << ' ' << phoneNum << endl;
				}
				else
				{
					writeUpdateGovt << fName << ' ' << lName << ' ' << CNIC << ' ' << id << ' ' << phoneNum << endl;
				}
				break;
			}
			case 3:
			{
				//updating cnicof admin
				string newCNIC;
				if (CNIC == cnic)
				{
					updFlag = true;
					cout << "Enter CNIC : ";
					cin >> newCNIC;
					writeUpdateGovt << fName << ' ' << lName << ' ' << newCNIC << ' ' << id << ' ' << phoneNum << endl;
				}
				else
				{
					writeUpdateGovt << fName << ' ' << lName << ' ' << CNIC << ' ' << id << ' ' << phoneNum << endl;
				}
				break;
			}
			case 4:
			{
				//updating phone number
				string newPhNum;
				if (CNIC == cnic)
				{
					updFlag = true;
					cout << "Enter PhoneNumber : ";
					cin >> newPhNum;
					writeUpdateGovt << fName << ' ' << lName << ' ' << CNIC << ' ' << id << ' ' << newPhNum << endl;
				}
				else
				{
					writeUpdateGovt << fName << ' ' << lName << ' ' << CNIC << ' ' << id << ' ' << phoneNum << endl;
				}
				break;
			}
			case 5:
			{
				//update id of Admin
				int newId = 0;
				if (CNIC == cnic)
				{
					updFlag = true;
					cout << "Enter Id : ";
					cin >> newId;
					writeUpdateGovt << fName << ' ' << lName << ' ' << CNIC << ' ' << newId << ' ' << phoneNum << endl;
				}
				else
				{
					writeUpdateGovt << fName << ' ' << lName << ' ' << CNIC << ' ' << id << ' ' << phoneNum << endl;
				}
				break;
			}
			cout << endl;
			default:
			{
				cout << "Invalid Choice " << endl;
				break;
			}
			}
		}
	}
	if (updFlag == true)
	{
		cout << "Updating Your Data. Please wait ";
		for (int i = 0; i < 5; i++)
		{
			Sleep(500);
			cout << ".";
		}
	}
	else
	{
		cout << "Data Not Updated" << endl;
	}
	//closing files
	readGovt.close();
	writeUpdateGovt.close();
	//since the tempGovtOff file is updated version of the GovtOfficalData file
	//we will remove the GovtOfficalData file
	//and name temp file as GovtOfficalData file 
	remove("GovtOfficalData.txt");
	rename("tempGovtOff.txt", "GovtOfficalData.txt");
}
void GovtOffical::deleteGovtOffical()
{
	cout << "-----DELETE GOVT OFFICAL-----" << endl;
	bool flag = false;
	GovtOffical gObj;
	//if admin log in sucessfully then delete his data
	flag = gObj.logInOffical(gObj);
	if (flag == true)
	{
		char choice = '\0';
		cout << "Do you want to delete your account ('y'/'n'): ";
		cin >> choice;
		if (choice == 'y' || choice == 'Y')
		{
			bool accDel = false;
			//input his cnic to delete admin
			long long int CNIC = 0;
			cout << "Enter CNIC :  ";
			cin >> CNIC;
			accDel = gObj.deleteGovtData(CNIC);
			if (accDel == true)
			{
				gObj.deleteGovtAcc(gObj);
			}
			else
			{
				cout << "Account cannot be deleted" << endl;
			}
		}
		else
		{
			cout << "Account not deleted" << endl;
			return;
		}

	}
}
bool GovtOffical::deleteGovtData(long long int cnic)
{
	bool flag = false;
	string fName;
	string lName;
	long long int CNIC = 0;
	string phoneNum;
	int id = 0;
	ifstream readGovt;
	readGovt.open("GovtOfficalData.txt", ios::in);
	if (!(readGovt.is_open()))
	{
		//change file name
		cout << "GovtOfficalData file not open" << endl;
		exit(-1);
	}
	//creating temporary file 
	ofstream deleteGovt("tempGovt.txt", ios::app);
	if (!(deleteGovt.is_open()))
	{
		cout << "tempGovt file cannot open" << endl;
		exit(-1);
	}
	while (!(readGovt.eof()))
	{
		readGovt >> fName;
		readGovt >> lName;
		readGovt >> CNIC;
		readGovt >> id;
		readGovt >> phoneNum;
		//if account found place space in place of that line
		if (!(readGovt.eof()))
		{
			if (CNIC == cnic)
			{
				flag = true;
				fName = ' ';
				deleteGovt << fName << endl;
			}
			//write rest of the accounts as it is 
			else
			{
				deleteGovt << fName << ' ' << lName << ' ' << CNIC << ' ' << id << ' ' << phoneNum << endl;
			}

		}
	}
	if (flag == true)
	{
		cout << "Deleting Your Data. Please wait ";
		for (int i = 0; i < 5; i++)
		{
			Sleep(500);
			cout << ".";
		}
	}
	cout << endl;
	readGovt.close();
	deleteGovt.close();
	//pehle purani file delete karen ge 
	//phir change file name
	remove("GovtOfficalData.txt");
	rename("tempGovt.txt", "GovtOfficalData.txt");
	return flag;
}
void GovtOffical::deleteGovtAcc(GovtOffical gObj)
{
	ifstream readGovt;
	//deleting account from file
	readGovt.open("GovtOfficalAccount.txt", ios::in);
	if (!(readGovt.is_open()))
	{
		cout << "GovtOfficalAccount file not open" << endl;
		exit(-1);
	}
	ofstream deleteGovt("tempGovtAcc.txt", ios::app | ios::out);
	if (!(deleteGovt.is_open()))
	{
		cout << "tempGovtAcc file cannot open" << endl;
		exit(-1);
	}
	string email;
	string passWrd;
	//now reading the file of registered citizen account
	while (!(readGovt.eof()))
	{
		readGovt >> email;
		readGovt >> passWrd;
		if (!(readGovt.eof()))
		{
			//if the account is found
			//delete it by placing simple space and write it in temporary file
			if (email == gObj.email && passWrd == gObj.password)
			{
				email = ' ';
				deleteGovt << email << endl;
			}
			//write rest of the data as it is in the temporary file
			else
			{
				deleteGovt << email << ' ' << passWrd << endl;
			}
		}
	}
	readGovt.close();
	deleteGovt.close();
	//deleting the GovtOfficalAccount file then renaming the temporary file as GovtOfficalAccount
	//because temporary file is the updated version of GovtOfficalAccount
	//pehle purani file delete karen ge 
	//phir change file name
	remove("GovtOfficalAccount.txt");
	rename("tempGovtAcc.txt", "GovtOfficalAccount.txt");
}
void GovtOffical::vaccineBudget()
{
	long long int amount = 0;
	ifstream readAmount;
	readAmount.open("VaccineBudget.txt", ios::in);
	if (!(readAmount.is_open()))
	{
		cout << "VaccineBudget File cannot open" << endl;
		exit(-1);
	}
	while (!(readAmount.eof()))
	{
		readAmount >> amount;
		amountSpent = amountSpent + amount;
	}
	readAmount.close();
}
void GovtOffical::VaccPatient()
{
	string email;
	string passWrd;
	string fName;
	string lName;
	long long int CNIC = 0;
	string phoneNum;
	string bloodTyp;
	string city;
	string state;
	string address;
	DOB dateObj;
	int vacDoseNum = 0;
	ifstream readCitizen;

	//deleting account from file
	readCitizen.open("RegisteredCitizen.txt", ios::in);
	if (!(readCitizen.is_open()))
	{
		cout << "RegisteredCitizen file not open" << endl;
		exit(-1);
	}
	while (!(readCitizen.eof()))
	{
		readCitizen >> fName;
		readCitizen >> lName;
		readCitizen >> email;
		readCitizen >> CNIC;
		readCitizen >> address;
		readCitizen >> state;
		readCitizen >> city;
		readCitizen >> phoneNum;
		readCitizen >> bloodTyp;
		readCitizen >> dateObj.day;
		readCitizen >> dateObj.month;
		readCitizen >> dateObj.year;
		readCitizen >> vacDoseNum;

		if (vacDoseNum == 1)
		{
			this->vaccPopulation = this->vaccPopulation + 1;
			this->partiallyVacc = this->partiallyVacc + 1;
		}
		else if (vacDoseNum == 2)
		{
			this->fullyVacc = this->fullyVacc + 1;
			this->vaccPopulation = this->vaccPopulation + 1;
		}
		else if (vacDoseNum >= 3)
		{
			this->boosterVacc = this->boosterVacc + 1;
			this->vaccPopulation = this->vaccPopulation + 1;
		}
	}
}
void GovtOffical::OutputStatistics()
{
	cout << "---------VACCINATED PEOPLE DATA------------" << endl;
	long double percentage = 0;
	percentage = static_cast<long double>(vaccPopulation) / static_cast<long double>(totalPopulation);
	percVaccPopulation = percentage * 100;
	nonVaccinatedPopulation = totalPopulation - vaccPopulation;
	percentage = static_cast<long double>(nonVaccinatedPopulation) / static_cast<long double>(totalPopulation);
	perNonVaccPopulation = percentage * 100;
	cout << endl;
	cout << "Total Population =          " << totalPopulation << endl;
	cout << "Vaccinated Population =     " << vaccPopulation << endl;
	cout << "Non-Vaccinated Population = " << nonVaccinatedPopulation << endl;
	cout << endl;
	cout << "---------VACCINATED PEOPLE GRAPH----------" << endl;
	cout << endl;
	cout << "Fully Vaccinated      ";
	for (int i = 0; i < fullyVacc; i++)
	{
		cout << " o ";
	}
	cout << endl;
	cout << "Partially Vaccinated  ";
	for (int i = 0; i < partiallyVacc; i++)
	{
		cout << " o ";
	}
	cout << endl;
	cout << "Booster Dose          ";
	for (int i = 0; i < boosterVacc; i++)
	{
		cout << " o ";
	}
	cout << endl << endl;
	cout << "Vaccinated Population =    " << percVaccPopulation << " %" << endl;
	cout << "Non Vaccinated Poulation = " << perNonVaccPopulation << " %" << endl;
	cout << endl;
	cout << "Total Amount spent = " << amountSpent << endl;
}
void GovtOffical::readGovtOfficalFile(long long int CNIC)
{
	string fname;
	string lname;
	long long int cnic = 0;
	string phonenum;
	int id = 0;

	ifstream readGovt;
	//opening the file of citizen data
	readGovt.open("GovtOfficalData.txt", ios::in);

	if (!(readGovt.is_open()))
	{
		cout << "GovtOfficalData file cannot open" << endl;
		exit(-1);
	}

	//when the required email matches the loop will be breaked
	bool showflag = false;

	while (!(readGovt.eof()) && showflag == false)
	{
		readGovt >> fname;
		readGovt >> lname;
		readGovt >> cnic;
		readGovt >> id;
		readGovt >> phonenum;

		//if the entered email matches will the email of the user in file
		//then show output on screen and flag will be true and loop will be breaked
		if (CNIC == cnic)
		{

			showflag = true;
			cout << endl;
			cout << "------GOVT OFFICAL INFORMATION-----" << endl;
			cout << "name   : " << fname << ' ' << lname << endl;
			cout << "cnic   : " << cnic << endl;
			cout << "Id     : " << id << endl;
			cout << "phone number : " << phonenum << endl;
		}
	}
	readGovt.close();
	Sleep(4000);
}
void GovtOffical::showOffical()
{
	bool flag = false;
	long long int CNIC = 0;
	GovtOffical gObj;
	//if offical log in sucessfully then show his data
	flag = gObj.logInOffical(gObj);
	if (flag == true)
	{
		cout << "Enter your CNIC: "; cin >> CNIC;
		gObj.readGovtOfficalFile(CNIC);
	}
}
//-------------SUPER ADMIN CLASS------------//
SuperAdmin::SuperAdmin()
{
	email = "super.admin@gmail.com";
	password = "0000";
	firstName = "Super";
	lastName = "Admin";
	id = 9999;
	phoneNum = "030123123";
	CNIC = 331025555;
	age = 50;
}
SuperAdmin::~SuperAdmin()
{
}
bool SuperAdmin::logInSuperAdmin()
{
	bool logInFlag = false;
	SuperAdmin sObj;
	string email;
	string passWrd;

	cout << "========LOG IN Page Of Super Admin=======" << endl;
	cout << "Enter Email: ";
	cin >> sObj.email;
	cout << "Enter Password: ";
	cin >> sObj.password;
	ifstream readSuperAdmin;
	readSuperAdmin.open("SuperAdminAccount.txt", ios::in);
	if (!(readSuperAdmin.is_open()))
	{
		cout << "SuperAdmin Account file cannot open" << endl;
		exit(-1);
	}
	else
	{
		while ((!(readSuperAdmin.eof())) && logInFlag == false)
		{
			readSuperAdmin >> email >> passWrd;
			if (email == sObj.email && passWrd == sObj.password)
			{
				logInFlag = true;
				cout << "Sucessfully logged in" << endl;
				Sleep(1000);
				system("CLS");
			}
		}
		if (logInFlag == false)
		{
			cout << "******Wrong email/password******" << endl;
			exit(-1);
		}
		readSuperAdmin.close();
	}
	return logInFlag;
}
void SuperAdmin::crudMenu()
{
	int choice = 0;

	bool flag = true;
	while (flag == true)
	{
		cout << "Select Account To perform CRUD operation" << endl;
		cout << "1.Citizen        2.Admin" << endl;
		cout << "3.Doctor         4.FDO" << endl;
		cout << "5.GOVT OFFICAL   6.LOGOUT" << endl;
		cout << endl;
		cout << "Enter Choice = "; cin >> choice;

		switch (choice)
		{
		case 1:
		{
			Sleep(300);
			system("CLS");
			Citizen cObj;
			cObj.citizenCRUD();
			break;
		}
		case 2:
		{
			Sleep(300);
			system("CLS");
			Admin aObj;
			aObj.menuAdmin();
			break;
		}
		case 3:
		{
			Sleep(300);
			system("CLS");
			Doctor dObj;
			dObj.menuDoctor();
			break;
		}
		case 4:
		{
			Sleep(300);
			system("CLS");
			FDO fObj;
			fObj.menuFDO();
			break;
		}
		case 5:
		{
			Sleep(300);
			system("CLS");
			GovtOffical gObj;
			gObj.menuGovtOff();
			break;
		}
		case 6:
		{
			Sleep(300);
			system("CLS");
			cout << "----LOGOUT----" << endl;
			flag = false;
			break;
		}
		default:
		{
			Sleep(300);
			system("CLS");
			cout << "Invalid Choice...Enter Again" << endl;
			break;
		}
		}
		Sleep(1000);
		system("CLS");
	}
}
//writing data in file
void SuperAdmin::writeToFile()
{
	ofstream writeSuperAdmin;
	writeSuperAdmin.open("SuperAdminAccount.txt", ios::out);
	if (!(writeSuperAdmin.is_open()))
	{
		cout << "SuperAdmin Account file cannot open" << endl;
		exit(-1);
	}
	writeSuperAdmin << email << ' ' << password << endl;
	writeSuperAdmin.close();

	ofstream writeSuperAdminData;
	writeSuperAdminData.open("SuperAdminData.txt", ios::out);
	if (!(writeSuperAdminData.is_open()))
	{
		cout << "SuperAdminData file cannot open" << endl;
		exit(-1);
	}
	writeSuperAdminData << firstName << ' ' << lastName << ' ' << email << ' ' << CNIC << ' ' << phoneNum << ' ' << id << endl;
}
ostream& operator << (ostream& out, const SuperAdmin& sObj)
{
	out << "-----SUPER ADMIN INFO------" << endl;
	out << "First Name:   " << sObj.firstName << endl;
	out << "Last  Name:   " << sObj.lastName << endl;
	out << "Email:       " << sObj.email << endl;
	out << "Id_Number:   " << sObj.id << endl;
	out << "CNIC_Number : " << sObj.CNIC << endl;
	out << "Phone_Number: " << sObj.phoneNum << endl;
	return out;
}