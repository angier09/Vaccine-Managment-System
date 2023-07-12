#include"VaccineSystem.h"
int main()
{
	//////do no erase it
	cout << "				-----------------------------------" << endl;
	cout << "				     VACCINE MANAGMENT SYSTEM" << endl;
	cout << "				-----------------------------------" << endl;
	cout << endl;
	bool flag = false;
	SuperAdmin sObj;
	sObj.writeToFile();
	flag = sObj.logInSuperAdmin();
	if (flag == true)
	{
		sObj.crudMenu();
	}

	///////log in do not erase we will use it not take input again and again because super admin has already created admin 
	bool adflag = false;
	Admin aObj;
	cout << "=====ADMIN LOG IN PAGE=====" << endl;
	adflag = aObj.logInAdmin(aObj);
	cout << endl;
	if (adflag == true)
	{
		aObj.adminFunc();
	}
	RegisteredCitizen rCObj;
	//erase it login is doing the same thing
	/*Admin aObj;
	cin >> aObj;
	aObj.adminFunc();*/

	int tempCounterNumber = 0;
	if (aObj.getDeskOfficers()[0].checkRegistration(rCObj))
	{
		tempCounterNumber = aObj.getDeskOfficers()[0].assignCounter(rCObj);		//will return the counter number which will be used as index for which doctor's function to call
		aObj.getDoctors()[tempCounterNumber].setVitals(rCObj);
	}
	cout << "-----------------------------------------------------------" << endl;
	GovtOffical gObj;
	gObj.VaccPatient();
	gObj.vaccineBudget();
	gObj.OutputStatistics();
	cout << "-----------------------------------------------------------" << endl;
	system("pause");
	return 0;
}

