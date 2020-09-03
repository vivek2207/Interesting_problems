#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dos.h>
#include <iomanip> 
#include<limits>



using namespace std;
class customer // customer class
{
	private:
	public:
	string customername;
    string carmodel;
    string carnumber;
    char data;
    // variables defined in this class in public mode.
};
class rent : public customer // inhereted class from customer class
{
	public:
	int days=0,rentalfee=0, cautionmoney=20; // additional int vatiables defined
	int flag=1;
	void data()
	{
		int login();
		login();
		system("CLS");
		cout << "\t\t\t\tPlease Enter your Name: "; //taking data from the user
	    cin >> customername;
	    cout<<endl;
	    do
	    {
	        cout <<"\t\t\t\tPlease Select a Car"<<endl; //giving user a choice to select among three different models
	        cout<<"\t\t\t\tEnter 'A' for Tesla 20011."<<endl;
	        cout<<"\t\t\t\tEnter 'B' for Hyundai 2015."<<endl;
	        cout<<"\t\t\t\tEnter 'C' for Ford 2017."<<endl;
	        cout<<endl;
	        cout<<"\t\t\t\tChoose a Car from the above options: ";
	        cin >>carmodel;
	        cout<<endl;
	 		cout<<"--------------------------------------------------------------------------"<<endl;
			if(carmodel=="A")
			{
		 	system("CLS");
		 
				cout<<"You have choosed Tesla model 2011"<<endl;
				ifstream inA("A.txt"); //displaying details of model A
		        char str[200];
		        while(inA) {
			        inA.getline(str, 200);  
			        if(inA) cout << str << endl;
				}
			sleep(2);
			}
			if(carmodel=="B")
			{
			  	system("CLS");  
				cout<<"You have choosed Hyundai model 2015"<<endl;
				ifstream inB("B.txt"); //displaying details of model B
		        char str[200];
		        while(inB) {
			        inB.getline(str, 200);  
			        if(inB) cout << str << endl;         
		     	}
		    sleep(2);
			}
			if(carmodel=="C")
			{
			 	system("CLS");
			    cout<<"You have choosed Ford model 2017"<<endl;
				ifstream inC("C.txt"); //displaying details of model C
		        char str[200];
		        while(inC) {
		        	inC.getline(str, 200);  
		         	if(inC) cout << str << endl;
		     	}
			sleep(2);
			}  
			if(carmodel !="A" && carmodel !="B" &&  carmodel !="C" ){
			    cout<<"Invaild Car Model. Please try again!"<<endl;
		    }
		}while(carmodel !="A" && carmodel !="B" &&  carmodel !="C" );
	
	    cout<<"--------------------------------------------------------------------------"<<endl;
	    cout << "Please provide following information: "<<endl; 
		//getting data from user related to rental service
	    cout<<"Please select a Car No. : ";
	    cin >> carnumber;
	    cout<<"Number of days you wish to rent the car : ";
	    cin >> days;
	   	while(1)
		{
			if(cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				cout<<"You have entered wrong input. Please enter the number of days: "<<endl;
				cin>>days;
			}
			if(!cin.fail())
				break;
		}
	}
	void calculate()
	{
		sleep(1);
		system ("CLS");
		cout<<"Calculating rent. Please wait......"<<endl;
		sleep(2);
		if(carmodel == "A"||carmodel=="a")
        rentalfee=days*56;
        if(carmodel == "B" ||carmodel=="b")
        rentalfee=days*60;
        if(carmodel == "C" ||carmodel=="c")
        rentalfee=days*75;
        cautionmoney=cautionmoney*days;
        
    }
	void showrent()
	{
	    cout << "\n\t                       Customer Invoice                  "<<endl;
	    cout << "\t	///////////////////////////////////////////////////////////"<<endl;
	    cout << "\t	| Invoice No. :"<<"------------------|"<<setw(10)<<"#Cnb81353"<<" |"<<endl;
	    cout << "\t	| Customer Name:"<<"-----------------|"<<setw(10)<<customername<<" |"<<endl;
	    cout << "\t	| Car Model :"<<"--------------------|"<<setw(10)<<carmodel<<" |"<<endl;
	    cout << "\t	| Car No. :"<<"----------------------|"<<setw(10)<<carnumber<<" |"<<endl;
	    cout << "\t	| Number of days :"<<"---------------|"<<setw(10)<<days<<" |"<<endl;
	    cout << "\t	| Your Rental Amount is :"<<"--------|"<<setw(10)<<rentalfee<<" |"<<endl;
	    cout << "\t	| Caution Money(Refundable) :"<<"----|"<<setw(10)<<cautionmoney<<" |"<<endl;
	    cout << "\t	| Advanced :"<<"---------------------|"<<setw(10)<<"0"<<" |"<<endl;
	    cout << "\t	 ________________________________________________________"<<endl;
	    cout <<"\n";
	    cout << "\t	| Total Rental Amount is :"<<"-------|"<<setw(10)<<rentalfee+cautionmoney<<" |"<<endl;
	    cout << "\t	 ________________________________________________________"<<endl;
	    cout << "\t	 # This is a computer generated invoce and it does not"<<endl;
	    cout << "\t	 require an authorised signture #"<<endl;
	    cout <<" "<<endl;
	    cout << "\t	///////////////////////////////////////////////////////////"<<endl;
	    cout << "\t	You are advised to pay up the amount before due date."<<endl;
	    cout << "\t	Otherwise penelty fee will be applied"<<endl;
	    cout << "\t	///////////////////////////////////////////////////////////"<<endl;
	    int f;
	    system("PAUSE");
	    
	}
};
class welcome //welcome class
{
	public:
	int welcum()
	{
		ifstream in("welcome.txt"); //displaying welcome ASCII image text on output screen fn1353
		
		if(!in) {
		    cout << "Cannot open input file.\n";
		}
		char str[1000];
		while(in) {
		    in.getline(str, 1000);  // delim defaults to '\n' cp
		    if(in) cout << str << endl;
		}
		in.close();
		sleep(1);
		cout<<"\nStarting the program please wait....."<<endl;
		sleep(1);
		cout<<"\nloading up files....."<<endl;
		sleep(1); //function which waits for (n) seconds
		system ("CLS"); //cleares screen
	}
};
int main()
{
	welcome obj1; //object created for welcome class
	obj1.welcum(); //welcum function is called
	rent obj2; 
	//object created for rent class and further member functions are called
	int flag=1;
	while (flag==1){
		obj2.data();
		obj2.calculate();
		obj2.showrent();
		cout<<"Do you want to book another ride? Enter 1 for Yes, 0 for No. ";
		cin>>flag;
	}
	system ("CLS");
	
	ifstream inf("thanks.txt");
	
	
	char str[300];
	
	while(inf) {
		inf.getline(str, 300);
		if(inf) cout << str << endl;
	}
	inf.close();
	return 0; //end of the program
}

int login(){
   string pass ="";
   char ch;
   cout<<"\n\n\n\n\n\n\n\n\t\t       CAR RENTAL SYSTEM \n\n";
   cout<<"\t\t------------------------------";
   cout<<"\n\t\t\t     LOGIN \n";	
   cout<<"\t\t------------------------------\n\n";	
   cout << "\t\tEnter Password: ";
   ch = _getch();
   while(ch != 13){//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "vivek"){
      cout << "\n\n\nAccess Granted. Lets choose your car! \n";
      system("PAUSE");
      system ("CLS");
   }else{
      cout << "\n\nAccess Aborted...\n\t\t\t\t\t\t\tPlease Try Again\n\n";
      system("PAUSE");
      system("CLS");
      login();
   }
}
