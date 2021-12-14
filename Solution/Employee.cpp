#include<iostream>
#include<string.h>
#include<fstream>
#include<iomanip>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;
class Student{
	
    string Sname;
    string fname;
    string lname;
    float CGPA;
    string studentID;
    int index;

    public:
    Student(){
        fname=" ";
        lname=" ";
        studentID=" ";
        CGPA=0.0;
        index=0;
    }
    void setInfo(string fn ,string ln, float cgpa, string sID,int c ){
        fname =fn;
        lname= ln;
        CGPA= cgpa;
        studentID= sID;
        index=c;
    }
    string getfName(){
        return fname;
    }
    string getlName(){
        return lname;
    }
    string fullName(){
    	Sname=fname+" "+lname;
    	return Sname;
	}
    float getCGPA()  {
        return CGPA;
    }
    string getstudentID(){
        return studentID;
    }
    void print(){
        Sname=fname+" "+lname;
        cout<<"||Student "<<index<<"||"<<endl;
        cout<<"Name:" <<Sname <<endl;
        cout<< "Cgpa:"<< CGPA<<endl;
        cout<<"Student Id:"<< studentID<<endl;
		cout<<endl;
    }
};

//bubble sorting 
void bubbleSort (float data[], int n){ 
    float temp;
    int swap=0;
    for (int pass = 1; (pass < n) ; ++pass){ 
        for (int x = 0; x < n-pass; ++x){ 
            if (data[x] > data[x+1]){ 
                // exchange items
                temp = data[x];
                data[x] = data[x+1];
                data[x+1] = temp;
            } // end if
        }
    // end for
    }
} 

float Coordinator(Student Emp[]){
	int choice;
	cout<<"1. View All Student"<<endl;
	cout<<"2. Sort by cgpa"<<endl;
	cout<<"3. Delete Student"<<endl;
	cout<<"Enter your choice: ";
	cin>> choice;
	cout<<endl;
	
	//reading data from file
    string studentID;
    string firstName;
    string lastName;
    float Cgpa;
    int count=0;
    int size=0;
    
    float cgpaArr[100];
    fstream infile("Student.txt",ios::in);
    int i=0;
    while(!infile.eof()){
		
		count++;
		
        infile >> studentID;  
        infile>>firstName;
        infile>>lastName;
        infile>> Cgpa;
        Emp[i].setInfo(firstName, lastName, Cgpa,studentID,count);
        cgpaArr[size]= Cgpa;
        size++;
        
        i++;
    }
    infile.close();
    
  	//Switch case
	switch(choice){
  		case 1:{
  			cout<<endl<<"Student List"<<endl;
        	cout<<"**********************"<<endl<<endl;
			for(int i=0;i<size-1;i++){
				Emp[i].print();	
			}
			break;
		}
		case 2:{
			bubbleSort(cgpaArr, size-1);// sort the data by cgpa
			cout<<endl<<"Student List"<<endl;
       		cout<<"**********************"<<endl<<endl;
			for(int i=0;i<size-1;i++){
				for(int j=0;j<size-1;j++){
					if(cgpaArr[i]==Emp[j].getCGPA()){
						Emp[j].print();
					}
				}
			}
			break;
		}	
	}
    
}
void studentFunction(Student Emp[]){
	
	string name;
	string recordedName;
	int found =0;
	
	int choice;
	cout<<endl<<"########Welcome########"<<endl<<endl;
	cout<<"1. New Student"<<endl;
	cout<<"2. Existing Student"<<endl;
	cout<<"Your choice: ";
	cin>>choice;
	cin.ignore();
	
	//reading data from file
    string studentID;
    string firstName;
    string lastName;
    float Cgpa;
    int count=0;
    int size=0;
    
    float cgpaArr[100];
    fstream infile("Student.txt",ios::in);
    int i=0;
    while(!infile.eof()){
    	count++;
        infile >> studentID;  
        infile>>firstName;
        infile>>lastName;
        infile>> Cgpa;
        Emp[i].setInfo(firstName, lastName, Cgpa,studentID,count);
        cgpaArr[size]= Cgpa;
        size++;
        
        i++;
    }
    infile.close();
	
	//adding new student 
	if(choice==1){
		string sId;
		string firstN;
		string lastN;
		float cgpa;
		
		cout<<"Student Id: ";
		cin>>sId;
		cout<<"First name: ";
		cin>>firstN;
		cout<<"Last name: ";
		cin>>lastN;
		cout<<"CGPA: ";
		cin>>cgpa;
		
		ofstream file_out("Student.txt",ios::app);
		file_out<<2<<sId<<setw(10)<<firstN<<" "<<lastN<<" "<<cgpa<<endl;
		
	}
	//finding one particular student
	else if(choice==2){
		cout<<"Type your fullname to print your information"<<endl<<endl;
		cout<<"Enter your name: ";
		getline(cin,name);
		cout<<endl<<"#####################"<<endl<<endl;
    
		for(int i=0;i<size-1;i++){
		    	
		    string recordedName = Emp[i].fullName();
		    transform(recordedName.begin(), recordedName.end(), recordedName.begin(), ::tolower);//convert to lowercase
		    transform(name.begin(), name.end(), name.begin(), ::tolower);//convert to lowercase
			if(name==recordedName){
					Emp[i].print();
					found=1;
					break;
			}
		}
		if(found==0){
			cout<<"Could not find your information...please write your name correctly"<<endl;
		}
	}
	else
		cout<<"Wrong choice"<<endl;	
}
int main(){
	Student Emp[100];
    int choice;
    cout<<"1. Student"<<endl;
    cout<<"2. Coordinator"<<endl;
    cout<<"########################"<<endl;
    cin>>choice;
    switch(choice){
        case 1: studentFunction(Emp);
            break;
        case 2: Coordinator(Emp);
            break;
        default:cout<<"wrong choice"<<endl;
            break;
    }
    return 0;
}
