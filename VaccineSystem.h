#pragma once

#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
#include<Windows.h>
#include<cstdlib>
#include<ctime>
#include<limits>

using namespace std;

/////int numOfDifferentVaccines = 0;
void setNumOfDifferentVaccines();
int generateRandomQueue();
/////--------------Date of Birth----------//
struct DOB
{
	int day;
	int month;
	int year;
	DOB();
	~DOB();
	//setter
	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);
	//getter
	int getDay();
	int getMonth();
	int getYear();
};
////signup email form of all the user
////idea is to make it an abstract class to make it reusable for all other classes 
/////-------abstract class-------------//
class EmailSignUpPage
{
public:
	EmailSignUpPage();
	~EmailSignUpPage();
	virtual void signUpEmail() = 0;
private:
};
/////-------------------person class---------------//
class Person
{
protected:
	string firstName;
	string lastName;
	int id;
	string email;
	string password;
	string phoneNum;
	int age;
	long long int CNIC;
public:
	Person();
	virtual ~Person();
	void setFirstName(string fName);
	string getFirstName();
	void setLastName(string lName);
	string getLastName();
	void setEmail(string mail);
	string getEmail();
	void setPassWord(string pasWrd);
	string getPasWord();
	void setID(int id);
	int getID();
	void setAge(int age);
	int getAge();
	void setPhNum(string num);
	string getPhNum();
	void setCNIC(long long int cnic);
	long long int getCNIC();
};
/////------------citizen class--------------//
class Citizen :public Person, public EmailSignUpPage
{
protected:
	string bloodType;
	string city;
	string state;
	string address;
	bool eligibilityCheck, allergy;
	int assignedCounter;
	DOB dateObj;
	int doseNum;
public:
	friend istream& operator >> (istream& in, Citizen& obj);
	friend ostream& operator << (ostream& out, const Citizen& obj);
	Citizen();
	~Citizen();
	void checkEligibility();
	//setter
	void setBloodType(string bldTyp);
	void setCity(string city);
	void setState(string state);
	void setAddress(string add);
	void setEligibilty(bool check);
	void setDOB(DOB obj);
	void setDoseNum(int n);
	//getter
	string getBloodType();
	string getCity();
	string getState();
	string getAddress();
	bool getEligiblity();
	int getDate();
	int getMonth();
	int getYear();
	int getDoseNum();
	//function to SignUp citizen email
	int menuCitizen();
	//abstract function defined here
	virtual void signUpEmail();
	void citizenCRUD();
};
/////--------------registered citizen---------------//
class RegisteredCitizen
{
public:
	RegisteredCitizen();
	~RegisteredCitizen();
	void setRegCitizen(Citizen cObj);
	void writeToFile();
	void readFromFile(const string email);
	void updateCitizenFile(const string email, int choice);
	friend ostream& operator << (ostream& out, const RegisteredCitizen& rObj);
	void createRegisteredCitizen();
	void showRegisteredCitizen();
	void updateRegisteredCitizen();
	void deleteRegisteredCitizen();
	void deleteFileData(const string email);
private:
	string regEmail;
	string regPassWrd;
	string regFName;
	string regLName;
	long long int regCNIC;
	string regPhoneNum;
	int regAge;
	string regBloodTyp;
	string regCity;
	string regState;
	string regAddress;
	DOB regDateObj;
	int vacDoseNum;
};
////--------------VACCINE CLASS------------//
class Vaccine
{
private:
	string vacType;
	float vacPrice;
	DOB expiryDate;
	string vacName;
	int numberOfDoses, vacID;
public:
	Vaccine();
	~Vaccine();
	void setVacType(string type);
	void setVacID(int ID);
	void setPrice(float cost);
	void setExpiryDate(DOB obj);
	void setVacName(string name);
	void setDoses(int doses);
	string getVacType();
	int getVacID();
	string getVacName();
	float getVacPrice();
	DOB getExpiryDate();
	int getNumberofDoses();

	friend istream& operator >> (istream& in, Vaccine& obj);
	friend ostream& operator <<(ostream& out, const Vaccine& obj);
};
/////-----------------BATCH_VACCINE Class---------//
class Batch_Vaccine
{
private:
	int batchSize, batchID;
	Vaccine* vaccines;					//aggregation of vaccines and they are stored in bulk, maybe create a numOfVaccines variable in vaccine class or in batch class
protected:

public:
	//bool checkSupplierID();				//implemented in warehouse, unsure whether to do here as well
	Batch_Vaccine();
	~Batch_Vaccine();
	Batch_Vaccine(Batch_Vaccine& obj);
	void setBatchSize(int size);
	void setVaccineToCreateBatch(Vaccine& obj);
	void setVaccinesInBatch(Vaccine* obj);
	void setBatchID(int id);
	Vaccine* getVaccines();
	int getBatchID();
	int getBatchSize();

	friend ostream& operator <<(ostream& out, const Batch_Vaccine& obj);
	friend istream& operator >> (istream& in, Batch_Vaccine& obj);
};
/////-------------------MANUFACTURER CLASS----------------//
class Manufacturer : public Person
{
private:
	int numOfBatches;
	Batch_Vaccine* batches;
public:
	Manufacturer();
	~Manufacturer();
	Manufacturer(Manufacturer& obj);
	void setNumOfBatches(int num);
	void setBatchesToCreate(Batch_Vaccine& obj);
	void setBatchesToStore(Batch_Vaccine* obj);
	int getNumOfBatches();
	Batch_Vaccine* getBatches();

	friend ostream& operator <<(ostream& out, const Manufacturer& obj);
	friend istream& operator >> (istream& in, Manufacturer& obj);
};
////-------------VENDOR CLASS-----------//
class Vendor :public Person
{
private:
	Manufacturer company;
	Batch_Vaccine* batchesBought;
public:
	Vendor();
	~Vendor();
	Vendor(Vendor& obj);
	void setCompany(Manufacturer& obj);
	void setBatchBought();	           //from company
	void vendorToStore(Vendor& obj);		//for deep copy purpose down in admin class
	Batch_Vaccine* getBatchesBought();
	Manufacturer& getCompany();
	friend ostream& operator <<(ostream& out, Vendor& obj);
	friend istream& operator >>(istream& in, Vendor& obj);
};

/////----------------SUPPLIER CLASS----------------//
class Supplier : public Person
{
private:
	string vaccineToBuy;
	int totalBuyers, totalBatchesSupplied, numOfBatchesBought;				//totalBuyers meaning how many different vaccines, totalBatchesSupplied means how many batches has been stored total, numOfBatches means how many batches was made by manufacturer for specific vaccine
	int numOfSpecificVaccines, * batchesOfSpecificVaccine;					//for warehouse, so that different batches can be created, knowing how many specific vaccines were supplied, also storing how many batches each vaccine was supplied to
	Vendor* buyers;
	Batch_Vaccine* batchesSupplied;
public:
	Supplier();
	~Supplier();
	Supplier(Supplier& obj);
	void setTotalBuyers(int total);
	void setBatchesSuppliedToCreate();
	void setBatchesSuppliedToStore(Batch_Vaccine* obj);		//for copying info of batches in warehouse through the supplier
	void setBatchesOfSpecificVaccine(int* arr);			//for copying info of batches in warehouse through the supplier
	void setTotalBatchesSupplied(int total);				//for copying info of batches in warehouse through the supplier
	void setNumOfSpecificVaccines(int num);					//for copying info of batches in warehouse through the supplier
	void setBuyers(Vendor* obj);
	void supplierToStore(Supplier& obj);		//for purpose of deep copy in admin class
	Batch_Vaccine* getBatchesSupplied();
	Vendor* getBuyers();
	int getTotalBuyers();
	int getTotalBatchesSupplied();
	int getNumOfBatchesBought();
	int getNumOfSpecificVaccines();
	int* getBatchesOfSpecificVaccines();
	friend ostream& operator <<(ostream& out, Supplier& obj);
	friend istream& operator >> (istream& in, Supplier& obj);
};
/////------------------WAREHOUSE CLASS------------------//
class Warehouse
{
private:
	Supplier wareSupplier;
	string wareName, wareLocation;
	double wareCapacity;
	int supplierID, batchesInWare;			//batchesInWare tells the present batches in warehouse and will be updated in set and updateWareBatches functions
	int* batchesOfEachVaccineInWare;		//to store each vaccine's batch present in warehouse, to update in updateWareBatches
	long long int vaccinesStored;
	Batch_Vaccine* wareBatches;
public:
	Warehouse();
	~Warehouse();
	void setWareSupplier(Supplier& obj);
	void setWareName(string name);
	void setWareLocation(string location);
	void setWareCapacity(double capacity);
	void setAuthorizedSupplierID(int id);
	bool setWareBatchesToCreate();			  //supplier exists as data member of Warehouse class, returning true if ID and capacity is valid 
	void setWareBatchesToStore(Batch_Vaccine* obj);
	void setBatchesInWare(int batches);
	void setBatchesOfEachVaccineInWare(int* arr);
	void updateWareBatches();		         //after batches are stored in stock of vac center
	Supplier& getWareSupplier();
	Batch_Vaccine* getWareBatches();
	string getWareName();
	int getAuthorizedSupplierID();
	string getWareLocation();
	double getWareCapacity();
	int getBatchesInWare();
	int* getBatchesOfEachVaccineInWare();
	long long int getVaccinesStored();

	friend ostream& operator <<(ostream& out, Warehouse& obj);
	friend istream& operator >> (istream& in, Warehouse& obj);
};
///////-------------COUNTER CLASS----------------//
class Counter				//for Vaccination center
{
private:
	int counterNumber;
	int queue;

public:
	Counter();
	~Counter();
	void setCounterNumber(int num);
	void setQueue(int q);
	void operator ++();		//++ queue only
	void operator --();		//-- queue only
	int getCounterNumber();
	int getQueue();

	friend ostream& operator <<(ostream& out, Counter& obj);	//no need for >> operator, setter will do the work
};
/////---------------CITY CLASS------------//
class City
{
private:
	string cityName;
	long long int population;
public:
	City();
	~City();
	void setPopulation(long long int people);
	void setCityName(string city);
	string getCityName();
	long long int getPopulation();
	friend ostream& operator << (ostream& out, City& obj);
	friend istream& operator >> (istream& in, City& obj);
};
//////----------------VACCINATION CENTER CLASS----------------//
class Vaccination_Center
{
private:
	int totalCounters;					//how many counters to make
	Counter* counterInfo;				//multiple counters so pointer, each will store counterNumber like 1 2 3 and have queue info to check whether it is busy or not
	Warehouse assignedWarehouse;
	int stockSize;						//maximum vaccines that can be stored
	Batch_Vaccine* stock;				//stock from warehouse, includes different batches having one specific vaccine
	City center_City;					//popualation and city name 
	string centerName;
public:
	Vaccination_Center();
	~Vaccination_Center();

	void setTotalCounters(int num);
	void setCounterInfo();				//counters will be created dynamically of size totalCounters and will hold counter number and queue 
	void setCenter_City(City& obj);
	void setWarehouse(Warehouse& obj);	//setting warehouse to get batches from it
	void setStock();					//implicitly storing batches as warehouse is a data member which will be set through setter
	void updateAssignedWarehouse();
	void setCenterName(string name);
	Counter* getCounterInfo();
	int getTotalCounters();
	int getStockSize();
	Warehouse& getAssignedWare();
	Batch_Vaccine* getStock();
	City& getCenter_City();
	string getCenterName();

	/////void operator --();
	friend ostream& operator <<(ostream& out, Vaccination_Center& obj);
	friend istream& operator >>(istream& in, Vaccination_Center& obj);
};
/////------------CLASS DOCTOR---------------//
class Doctor : public Person, public EmailSignUpPage
{
private:
	int totalDutyDays;
	string* dutyDays;			//will be inputted in >> overloading
	int assignedCounterNumber;
	Vaccination_Center assigned_Center;
	float citi_BloodPressure, citi_OxygenLevel, citi_GlucoseLevel;
public:
	Doctor();
	~Doctor();
	void setCenter(Vaccination_Center& obj);
	void setTotalDutyDays(int total);
	void setCounterNumber(int num);
	void setVitals(RegisteredCitizen& obj);
	void setBloodP(float bp);
	void setGlucoseL(float gl);
	void setOxygenL(float ol);
	void setDutyDays(string* obj);
	float getBloodP();
	float getGlucoseL();
	float getOxygenL();
	int getCounterNumber();
	int getTotalDutyDays();
	string* getDutyDays();
	Vaccination_Center& getCenter();
	string getAssignedCenterName();
	friend ostream& operator <<(ostream& out, Doctor& obj);
	friend istream& operator >>(istream& in, Doctor& obj);
	void menuDoctor();
	virtual void signUpEmail();
	void writeDoctorToFile();
	void createDoctor(Doctor dObj);
	void readDoctorFile(long long int cnic);
	bool logInDoctor();
	void showDoctor();
	void updateDoctor();
	void updateDoctorFile(long long int cnic, int choice);
	void deleteDoctor();
	void deleteDoctorData(long long int cnic);
	void deleteDoctorAcc();
};
//////----------------FDO CLASS------------//
class FDO : public Person, public EmailSignUpPage
{
private:
	Vaccination_Center assigned_Centre;
public:
	FDO();
	~FDO();
	void menuFDO();
	virtual void signUpEmail();
	void writeFDOToFile();
	void createFDO(FDO fObj);
	void readFDOFile(long long int cnic);
	bool logInFDO(FDO& fObj);
	void showFDO();
	void updateFDO();
	void updateFDOFile(long long int cnic, int choice);
	void deleteFDO();
	void deleteFDOData(long long int cnic);
	void deleteFDOAcc(FDO fObj);
	void setCenter(Vaccination_Center& obj);
	//unsure of getter
	bool checkRegistration(RegisteredCitizen& obj);
	int assignCounter(RegisteredCitizen& obj);

	friend ostream& operator <<(ostream& out, FDO& obj);
	friend istream& operator >>(istream& in, FDO& obj);
};
//////---------------------ADMIN CLASS------------------//
class Admin : public Person, public EmailSignUpPage
{
private:
	Vaccine* procuredVaccine;
	Batch_Vaccine* procuredBatchOfVaccine;
	Manufacturer* companies;
	Vendor* middlemen;
	Supplier* handlers;
	Warehouse* wares;
	City* cities;
	Vaccination_Center* centers;
	Doctor* doctors;
	FDO* deskOfficers;
	int totalCities, totalDoctors;
public:
	Admin();
	~Admin();
	void menuAdmin();
	virtual void signUpEmail();
	void writeAdminToFile();
	void readAdminFile(long long int cnic);
	void updateAdminFile(long long int cnic, int choice);
	bool logInAdmin(Admin& aObj);
	void createAdmin(Admin aObj);
	void showAdmin();
	void updateAdmin();
	void deleteAdmin();
	void deleteAdminData(long long int cnic);
	void deleteAdminAcc(Admin aObj);
	Admin* getDeepCopyOfProcess();		//for returning deep copy of every data member of class Admin(warehouse, center etc) to create or delete
	void createNewCenter(Admin* tempAdmin);				//create new center and update the whole data members as they are pointers(arrays), parameter is deep copy
	void deleteACenter(Admin* tempAdmin);				//delete a center and update the whole data members as they are pointers(arrays), parameter is deep copy
	Vaccination_Center* getCenters();
	Doctor* getDoctors();
	FDO* getDeskOfficers();
	void displayProcuredVaccine();
	void displayProcuredBatch();
	void displayCompanies();
	void displayMiddlemen();
	void displayHandler(Vaccination_Center& obj);
	void displayWare(Vaccination_Center& obj);
	void displayCenter(int index);
	void displayDoctors();
	void displayFDO();
	void displayCities();
	int getTotalCities();
	//setter getter of email and password remain
	void adminFunc();				//to set all the classes, work that was done in main
	friend ostream& operator <<(ostream& out, const Admin& obj);
	friend istream& operator >>(istream& in, Admin& obj);
};
//////---------------GOVT OFFICAL CLASS-----------------//
class GovtOffical :public Person, public EmailSignUpPage
{
public:
	GovtOffical();
	~GovtOffical();
	void menuGovtOff();
	virtual void signUpEmail();
	void writeOfficalToFile();
	void createOffical(GovtOffical gObj);
	void showOffical();
	void readGovtOfficalFile(long long int cnic);
	bool logInOffical(GovtOffical& gObj);
	void updateGovtOff();
	void updateGovtFile(long long int cnic, int choice);
	void deleteGovtOffical();
	bool deleteGovtData(long long int cnic);
	void deleteGovtAcc(GovtOffical gObj);
	void VaccPatient();
	void OutputStatistics();
	void vaccineBudget();
	friend istream& operator >>(istream& in, GovtOffical& obj);
	friend ostream& operator <<(ostream& out, const GovtOffical& obj);
private:
	long long int amountSpent;
	int totalPopulation;
	int partiallyVacc;
	int fullyVacc;
	int boosterVacc;
	int vaccPopulation;
	int nonVaccinatedPopulation;
	long double percVaccPopulation;
	long double perNonVaccPopulation;
};

/////-------------SUPER ADMIN CLASS------------//
class SuperAdmin :public Person
{
public:
	SuperAdmin();
	~SuperAdmin();
	bool logInSuperAdmin();
	void crudMenu();
	void writeToFile();
	friend ostream& operator << (ostream& out, const SuperAdmin& sObj);
	//friend istream& operator << (istream& in, const SuperAdmin& sObj);
};