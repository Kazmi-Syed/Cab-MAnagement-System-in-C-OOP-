// OOP Project

// Syad Bilal Javed Shah 
// Malik Ehtisham Ali

#include<iostream> 		// header file
#include<fstream> 		// header file
#include<string> 		// header file
#include<windows.h>		// header file

using namespace std;	// header file


class TAXI{				// Declaring a class

private:

	ifstream infile;
	ofstream outfile;
	string Username, Username_temp, Password, Password_temp, t;
	int points;
	string cat, cad;
	int count;
	bool a;

public:
	
	string ID;
	
	void signup(){

		infile.open("customers_name.txt", ios::in);
		outfile.open("temp.txt", ios::out);
	
		a = true;
		
		printf("Note: Isntead Of Space Use Underline(_).\n");
		printf("Note: Any Space in the Username and Password will be converted automatically in the Underline.\n\n");
		getline(cin, t); // ignore it
		
		cout << "Enter Your UserName: ";
		getline(cin, Username);
		cout << "Enter Your Password: ";
		getline(cin, Password);
		
		for (int i=0; i<Username.length(); i++){
			
			if (Username.at(i) == ' '){
				Username.at(i) = '_';
			}
		}
		
		for (int i=0; i<Password.length(); i++){
			
			if (Password.at(i) == ' '){
				Password.at(i) = '_';
			}
		}
		
		while (infile >> Username_temp) {
			infile >> Password_temp >> points;	
	
			if (Username.compare(Username_temp) == 0) {
	
				outfile << Username_temp << "\t" << Password_temp << "\t" << points << endl;
				a = false;
			}
			else {
				outfile << Username_temp << "\t" << Password_temp << "\t" << points << endl;
			}
		}
		if (a == true) {
			outfile << Username << "\t" << Password << "\t" << 0 << endl;
			printf("\nAccount Created Successfully. . . Please Go Back To The Main Menu And Sign In.\n");
		}
		else {
			cout << endl << "Username Already Exists. . . Please Try Another Username OR Sign In. . . !!!\n" << endl;
		}
		cout << endl;
		infile.close();
		outfile.close();
		system("del customers_name.txt");
		system("ren temp.txt customers_name.txt");
	}
	
	bool signin(){
	
		a = true;
		count = 0;
		
		getline(cin, t); // ignore it
	
		while (a) {
	
			printf("Enter Your Username: ");
			getline(cin, Username);
			printf("Enter Your Password: ");
			getline(cin, Password);
			
			for (int i=0; i<Username.length(); i++){
			
				if (Username.at(i) == ' '){
					Username.at(i) = '_';
				}
			}
		
			for (int i=0; i<Password.length(); i++){
			
				if (Password.at(i) == ' '){
					Password.at(i) = '_';
				}
			}
			
			cat = Username + Password;	
	
			infile.open("customers_name.txt", ios::in);
	
			while (infile >> Username_temp) {
				infile >> Password_temp >> points;
				cad = Username_temp + Password_temp;

				if (cat.compare(cad) == 0) {
	
					infile.close();
					ID = Username;
					cout << "\nSigned In Successfully. . . !!!\n\n";
					system("pause");
					return true;
				}
			}
			count++;
			if (count == 4) {
				printf("\nYou Are Not A Register User. Please SignUp First. . . !!!\n\n");
				a = false;
			}
			else {
				printf("\nWrong Username OR Password. Please Re-Enter Correct Username And Password. . .\n\n");
				infile.close();
			}
		}

		infile.close();
		return false;
	}
	
	bool ChangeUsername(string id){
		
		getline(cin, t);	// ignore it
		
		printf("\nEnter New Username: ");
		getline(cin, Username);
		
		for (int i=0; i<Username.length(); i++){
			
			if (Username.at(i) == ' '){
				Username.at(i) = '_';
			}
		}
		
		infile.open("customers_name.txt", ios::in);
		
		while (infile >> Username_temp){
			infile >> Password_temp >> points;
			
			if (Username == Username_temp){
				cout << "\nUsername Already Exist . . . Please Try Another Username...\n" << endl;
				infile.close();
				return false;
			}
		}
		infile.close();
		
		infile.open("customers_name.txt", ios::in);
		outfile.open("temp.txt", ios::out);
		
		while (infile >> Username_temp){
			infile >> Password_temp >> points;
		
			if (Username_temp == id){
			
				outfile << Username << "\t" << Password_temp << "\t" << points << endl;
				cout << "\nUsername Changed. . . Please Sign In Again. . . !!!\n" << endl;
			}
			else{
				outfile << Username_temp << "\t" << Password_temp << "\t" << points << endl;
			}
		}
		infile.close();
		outfile.close();
		system("del customers_name.txt");
		system("ren temp.txt customers_name.txt");
		return true;
	}
	
	void ChangePassword(string id){
		
		getline(cin, t); //ingore it
		
		printf("\nEnter New Password: ");
		getline(cin, Password);
		
		for (int i=0; i<Password.length(); i++){
			
			if (Password.at(i) == ' '){
				Password.at(i) = '_';
			}
		}
		
		infile.open("customers_name.txt", ios::in);
		outfile.open("temp.txt", ios::out);
		
		while (infile >> Username_temp){
			infile >> Password_temp >> points;
		
			if (Username_temp == id){
			
				outfile << Username_temp << "\t" << Password << "\t" << points << endl;
				cout << "\nPassword Changed. . . Please Sign In Again. . . !!!\n" << endl;
			}
			else{
				outfile << Username_temp << "\t" << Password_temp << "\t" << points << endl;
			}
		}
		infile.close();
		outfile.close();
		system("del customers_name.txt");
		system("ren temp.txt customers_name.txt");
	}
	
	void DeleteAccount(string id){
		
		infile.open("customers_name.txt", ios::in);
		outfile.open("temp.txt", ios::out);
		
		while (infile >> Username_temp){
			infile >> Password_temp >> points;
			
			if (Username_temp == id){
				
				cout << endl << "Account Deleted Successfully. . . !!!\n" << endl; 
			}
			else{
				outfile << Username_temp << "\t" << Password_temp << "\t" << points << endl;
			}
		}
		infile.close();
		outfile.close();
		system("del customers_name.txt");
		system("ren temp.txt customers_name.txt");
	}
	
	void SeeAccount(string id){
		
		infile.open("customers_name.txt", ios::in);
		
		while (infile >> Username_temp){
			infile >> Password_temp >> points;
			
			if (Username_temp == id){
				cout << "\nYour Username is: " << Username_temp << endl;
				cout << "Your Password Is: " << Password_temp << endl;
				cout << "Loyalty Points You Earned: " << points << endl;
			}
		}
		cout << endl;
		infile.close();
	}
	
	void Ride(string id, string Location){
		
		char ride_type;
		int charges_per_km;
		int charges_per_mint;
		int total_km;
		int total_charges;
		int trip_charges;
		int waiting_time;
		int waiting_time_charges;
		char decision;
		int count;
		int points2;
		char offer;
		int deduction;
		int bonus;
		
		printf("***Select The Type Of Ride***\n");
		printf("\n1. Ordinary Class.");
		printf("\n2. Business Class.");
		label1:
		printf("\n\n>>> ");
		cin >> ride_type;
		
		switch (ride_type){
			
			case '1':
				
				charges_per_km = 15;
				charges_per_mint = 2;
				bonus = 5;
				break;
				
			case '2':
				
				charges_per_km = 20;
				charges_per_mint = 5;
				bonus = 10;
				break;
				
			default:
				
				cout << "\nInvalid Input Inserted. Insert Again. . . . !!!" << endl;
				goto label1;
				
				break;
		}
		
		if (Location == "Gujranwala"){
			
			total_km = 220;
		}
		else if (Location == "Peshawar"){
			
			total_km = 185;
		}
		else if (Location == "Lahore"){
			
			total_km = 380;
		}
		else if (Location == "Karachi"){
			
			total_km = 1400;
		}
		
		cout << "\nEnter The Waiting Time (In Minutes): ";
		cin >> waiting_time;
		cout << endl;
		
		infile.open("customers_name.txt", ios::in);
		while (infile >> Username_temp){
			infile >> Password_temp >> points;
			
			if (Username_temp == id){
				
				points2 = points;
			}
		}
		infile.close();
		
		if (points2 > 40){
			
			cout << "\n\nYou Have Loyalty Points: " << points2 << endl;
			cout << "We Are Offering You...." << endl;
			cout << "1. Zero Fee On Trip Charges (Points Deduction Will Be 35)" << endl;
			cout << "2. 50% off On Trip Charges (Points Deduction Will Be 15)" << endl;
			cout << "3. No Offer Please" << endl;
			label5:
			cout << "\n\n>>> ";
			cin >> offer;
			cout << endl;
			
			switch (offer){
				
				case '1':
					
					deduction = 35;
					trip_charges = 0;
					break;
				
				case '2':
					
					deduction = 15;
					trip_charges = (charges_per_km * total_km)/2;
					break;
					
				case '3':
					
					trip_charges = (charges_per_km * total_km);
					deduction = 0;
					
					break;
				
				default:
					
					cout << "\nInvalid Input Inserted. Insert Again. . . . !!!\n" << endl;
					system("pause");
					goto label5;
					break;
			}
			
		}
		else{
			
			trip_charges = (charges_per_km * total_km);
			deduction = 0;
		}
		
		waiting_time_charges = (waiting_time * charges_per_mint);
		total_charges = ( waiting_time_charges + trip_charges );
		
		cout << "Name: " << id << endl;
		cout << "Location: " << Location << endl;
		cout << "Total Kilometers: " << total_km << endl;
		cout << "On Road Charges: " << trip_charges << endl;
		cout << "Waiting Time: " << waiting_time << endl;
		cout << "Waiting Time Charges: " << waiting_time_charges << endl;
		cout << "Total Charges: " << total_charges << endl;
		cout << endl;
		
		cout << "Confirm Ride[y/n]: ";
		cin >> decision;
		
		if (decision == 'y' || decision == 'Y'){
			
			string cab[5];
			string driver[5];
			int status[5];
			
			infile.open("cabs_and_status.txt", ios::in);
			infile >> cab[0] >> driver[0] >> status[0] >> cab[1] >> driver[1] >> status[1] >> cab[2] >> driver[2] >> status[2] >> cab[3] >> driver[3] >> status[3] >> cab[4] >> driver[4] >> status[4];
			infile.close();
			
			if ( status[0] == 0 && status[1] == 0 && status[2] == 0 && status[3] == 0 && status[4] == 0 ){
				
				
				cout << "\nLooking For A Cab For You. . . . .";
				Sleep(500);//For Pause 
				cout << "<";
				Sleep(500);//For Pause
				cout << ">";
				Sleep(500);//For Pause  
				cout << "<";
				Sleep(500);//For Pause 
				cout << ">";
				Sleep(500);//For Pause
				cout << "<";
				Sleep(500);//For Pause 
				cout << ">";
				Sleep(500);//For Pause
				cout << "<";
				Sleep(500);//For Pause 
				cout << ">";
				Sleep(500);//For Pause
				cout << "<";
				Sleep(500);//For Pause 
				cout << ">";
				Sleep(1000);//For Pause
				
				cout<<"\n\nAll The cabs Are Book. . . !!!"<<endl;
   				cout<<"We Can Not Book Cab for You. . . !!!\n"<<endl;
				goto label2;
			}
			else{
				
				for (int i=0; i<5; i++){
					
					if (status[i] == 1){
						count = i;
						break;
					}
				}
				status[count] = 0;
				
				cout << "\nLooking For A Cab For You. . . . .";
				Sleep(500);//For Pause 
				cout << "<";
				Sleep(500);//For Pause
				cout << ">";
				Sleep(500);//For Pause  
				cout << "<";
				Sleep(500);//For Pause 
				cout << ">";
				Sleep(500);//For Pause
				cout << "<";
				Sleep(500);//For Pause
				cout << ">";
				Sleep(500);//For Pause  
				cout << "<";
				Sleep(500);//For Pause 
				cout << ">";
				Sleep(500);//For Pause
				cout << "<";
				Sleep(500);//For Pause 
				cout << ">";
				Sleep(500);//For Pause
				cout << "<";
				Sleep(500);//For Pause 
				cout << ">";
				Sleep(500);//For Pause
				cout << "<";
				Sleep(500);//For Pause 
				cout << ">";
				Sleep(2000);//For Pause
				cout << "\n\n" << "--->Taxi No. " << cab[count] << " Driver " << driver[count] << " is on its Way. . . !!!" << "\n\n";
				cout << "--->Have A Safe Journey :)\n\n";
				
				outfile.open("cabs_and_status.txt", ios::out);
				outfile << cab[0]<< " " << driver[0]<< " " << status[0] << endl;
				outfile << cab[1]<< " " << driver[1]<< " " << status[1] << endl;
				outfile << cab[2]<< " " << driver[2]<< " " << status[2] << endl;
				outfile << cab[3]<< " " << driver[3]<< " " << status[3] << endl;
				outfile << cab[4]<< " " << driver[4]<< " " << status[4] << endl;
				outfile.close();
				
				outfile.open("History.txt", ios::app);
				outfile << "Name: " << id << endl;
				outfile << "Location: " << Location << endl;
				outfile << "Total Kilometers: " << total_km << endl;
				outfile << "On Road Charges: " << trip_charges << endl;
				outfile << "Waiting Time: " << waiting_time << endl;
				outfile << "Waiting Time Charges: " << waiting_time_charges << endl;
				outfile << "Total Charges: " << total_charges << endl;
				outfile << endl;
				outfile.close();
				
				infile.open("customers_name.txt", ios::in);
				outfile.open("temp.txt", ios::out);
			
				while (infile >> Username_temp){
					infile >> Password_temp >> points;
			
					if (Username_temp == id){
				
						outfile << Username_temp << "\t" << Password_temp << "\t" << (points-deduction+bonus) << endl;
					}
					else{
						
						outfile << Username_temp << "\t" << Password_temp << "\t" << points << endl;
					}
				}
				infile.close();
				outfile.close();
				system("del customers_name.txt");
				system("ren temp.txt customers_name.txt");
			}
		}
		else{
			
			cout << "\nBooking Canceled. . . !!!\n" << endl;
		}
		
		label2:
			int n;
	}
	
};


int main() {

	//************************************************************************************
	//*                             DiSpLaYiNg WeLcOmE ScReEn                            *
	//************************************************************************************
	
	cout << endl;
	printf("***************************************\n");
	printf("*               WELCOME               *\n");
	printf("*                 TO                  *\n");
	printf("*     WAJIHA CAB BOOKING SERVICE      *\n");
	printf("***************************************\n");
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "Loading. . . . .";
	Sleep(400);//For Pause 
	cout << "<";
	Sleep(400);//For Pause
	cout << ">";
	Sleep(400);//For Pause  
	cout << "<";
	Sleep(400);//For Pause 
	cout << ">";
	Sleep(400);//For Pause
	cout << "<";
	Sleep(400);//For Pause
	cout << ">";
	Sleep(400);//For Pause  
	cout << "<";
	Sleep(400);//For Pause 
	cout << ">";
	Sleep(400);//For Pause
	cout << "<";
	Sleep(400);//For Pause 
	cout << ">";
	Sleep(400);//For Pause
	cout << "<";
	Sleep(400);//For Pause 
	cout << ">";
	Sleep(400);//For Pause
	cout << "<";
	Sleep(400);//For Pause 
	cout << ">";
	Sleep(400);//For Pause
	cout << "\n\nLoaded Successfully. . . . !!!!\n\n";

	Sleep(2000);//For Pause


	TAXI obj;

	char desire;
	char desire2;
	char desire3;
	bool bool_, t;
	bool_ = true;

	while (bool_) {

		//	****************************************************************
		//	***                           MeNu                           ***
		//	****************************************************************

		system("CLS");
		system("color 0E");
		cout << endl;
		printf("> > > > > > > MAIN MENU < < < < < < <\n");
		printf("> 1 <          Sign In              <\n");
		printf("> 2 <          Sign Up              <\n");
		printf("> 3 <        Information            <\n");
		printf("> 4 <           Help                <\n");
		printf("> 5 <           Exit                <\n");
		printf("><><><><><><><><>< ><><><><><><><><><\n");

		printf("\n>>>: ");
		cin >> desire;
		bool result;

		switch (desire) {

		case '1':

			system("color 0A");
			cout << endl;
			result = obj.signin();
			t = result;
			
			if (result){
				
				while (result){
					
					system("CLS");
					system("color 0B");
					cout << endl;
					printf("> > > > > > > OPTIONS < < < < < < <\n");
					printf("> 1 <        Book A Ride          <\n");
					printf("> 2 <       Change Username       <\n");
					printf("> 3 <       Change Password       <\n");
					printf("> 4 <       Delete Account        <\n");
					printf("> 5 <       Check Account         <\n");
					printf("> 6 <         Sign out            <\n");
					printf("><><><><><><><><>< ><><><><><><><><\n");
					printf("\n>>> ");
					cin >> desire2;
					
					bool result2;
					
					switch (desire2){
						
						case '1':
							
							label3:
							system("CLS");
							system("color 0C");
							cout << endl;
							printf("> > > > > > > > Ride < < < < < < < <\n");
							printf("> 1 <    Islamabad To Lahore       <\n");
							printf("> 2 <    Islamabad To Karachi      <\n");
							printf("> 3 <    Islamabad To Peshawar     <\n");
							printf("> 4 <    Islamabad To Gujranwala   <\n");
							printf("> 5 <           Back               <\n");
							printf("><><><><><><><><><><><><><><><><><><\n");
							printf("\n>>> ");
							cin >> desire3;
							cout << endl;
							
							switch (desire3){
								
								case '1':
									system("color 0B");
									obj.Ride( obj.ID, "Lahore" );
									
									system("pause");
									break;
								
								case '2':
									system("color 0D");
									obj.Ride( obj.ID, "Karachi" );
									
									system("pause");
									break;
								
								case '3':
									system("color 0E");
									obj.Ride( obj.ID, "Peshawar" );
									
									 system("pause");
									break;
								
								case '4':
									system("color 0F");
									obj.Ride( obj.ID, "Gujranwala" );
									
									 system("pause");
									break;
								
								case '5':
									
									// To Go Back
									
									break;
								
								default:
									
									cout << "\nInvalid Input Inserted. . . . !!!\n" << endl;
									system("pause");
									goto label3;
									break;
							}
							
							break;
						
						case '2':
							
							system("color 0C");
							result2 = obj.ChangeUsername(obj.ID);
							if (result2){
								result = false;
							}
							
							break;
							
						case '3':
							system("color 0D");
							obj.ChangePassword(obj.ID);
							result = false;
							
							break;
						
						case '4':
							system("color 0E");
							obj.DeleteAccount(obj.ID);
							result = false;
							
							break;
						
						case '5':
							system("color 0F");
							obj.SeeAccount(obj.ID);
							
							break;
						
						case '6':
							cout << endl << "Signed Out. . . !!!\n" << endl;
							result = false;
							
							break;
						
						default:
							
							cout << "\nInvalid Input Inserted. . . . !!!\n" << endl;
							
							break;
					}
					
					if (desire2 != '1'){
						
						system("pause");
					}
				}
			}
			if ( t == false ){
				system("pause");
			}
			cout << endl;
			break;

		case '2':

			system("color 0B");
			cout << endl;
			obj.signup();
			cout << endl;
			break;

		case '3':

			system("color 0C");
			printf("\nDear Customer:\n");
			printf("\t\tWajiha Cab Booking Service Offers You To Book A Cab From ISLAMABAD To PESHAWAR,\n");
			printf("GUJRANWALA, LAHORE, KARACHI & Then Back To ISLAMABAD.  We Provide You Ordinary\n");
			printf("And Business Class Cabs To Make Your Journey More and More Comfortable. Win Free\n");
			printf("Rides From The Bonuse Points That We'll Give To you On Using Our Services.\n");
			printf("Allow Us To Make Your Journey Memorable... :) \n\n");
			break;

		case '4':

			system("color 0D");
			printf("\n>> Already Have An Account.?? Please Enter With \'1\' To Log In With Your ID & Password.\n");
			printf(">> Are You New Here.?? Please Enter With \'2\' To Create An Account With Unique ID & Password.\n");
			printf(">> Care To Know More About Us.??  Please Enter With \'3\' From The Menu.\n");
			printf(">> If You Want To Exit From The Program Then Please Enter With \'5\'.\n");
			printf(">> Still Confuse.??  Email Your Query To US @ WajihaCabBookingService@gmail.com.\n\n");
			break;

		case '5':

			system("color 0F");
			bool_ = false;
			printf("\nPROGRAM EXITED SUCCESSFULLY. . . . !!!!\n\n");
			printf("SEE YOU AGAIN SOON . . . . !!!! ;) \n\n");
			break;

		default:

			cout << "\nInvalid Input Inserted. . . . !!!\n" << endl;
			break;
		}
		if (desire != '5' && desire != '1'){
			system("pause");
		}
	}

	return 0;
}
