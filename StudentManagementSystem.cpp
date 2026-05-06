#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class display{ // using an abstraction class 
public:
    virtual void displayIDinfo()=0; // using virtual class
    virtual ~display() {} //  virtual destructor 
};

class person: public display{ // creating a class student 
protected:     // using protected access specifer 
    string name;
    string netid;

public:
    void setname(string n){ // a setter for name of the students  
        name=n;
    }
    string getname(){ // a getter for the name for the students 
        return name;
    }

    void setnetid(string NetID){ // a setter for netID of the students  
        netid = NetID;
    }
    string getnetid(){ // a getter for the netID for the students 
        return netid;
    }

    person( string n, string id){ //creating a constructor 
        name=n;
        netid=id;
    }

    void displayIDinfo(){
        cout << left << setw(20) << name << setw(15) << netid << endl;
    }
};

class student :public person{ //child class (inheritance)
private:
    float totalmarks; 
    float cgpa;
public:
    student(string n,string id,float c,float marks):person(n,id){
       totalmarks=marks;
       cgpa=c;
    }
    void displayIDinfo(){
        cout << left << setw(20) << name << setw(15) << netid
             << setw(10) << cgpa << setw(10) << totalmarks << endl;
    }
};

int main(){
    vector<person*> people; //used polymorphism here 
    int choice;
    while(true){
        cout<<"-------STUDENT MANAGEMENT SYSTEM----------"<<endl;
        cout<<"1. ADD STUDENT"<<endl;
        cout<<"2. VIEW STUDENTS"<<endl;
        cout<<"3. DELETE STUDENT"<<endl;
        cout<<"4. EXIT"<<endl;
        cin>>choice;

        if(choice == 1){
            string name;
            string id;
            float cgpa;
            float marks;

            cout<<"ENTER NAME"<<endl;
            cin.ignore();        
            getline(cin, name);  
            cout<<"ENTER ID"<<endl;
            cin>>id;

            // cgpa from 1 to 10
            cout<<"ENTER CGPA (1.0 - 10.0)"<<endl;
            cin>>cgpa;
            while(cgpa < 1.0 || cgpa > 10.0){
                cout<<"INVALID! ENTER CGPA BETWEEN 1.0 AND 10.0: ";
                cin>>cgpa;
            }

            cout<<"ENTER MARKS"<<endl;
            cin>>marks;

            people.push_back(new student(name,id,cgpa,marks));
            cout<<"STUDENT INFO ADDED!"<<endl;
        }

        else if(choice == 2){
            if(people.empty()){
                cout<<"NO RECORDS FOUND!"<<endl;
            }
            else{
                cout << "\n" << left << setw(20) << "NAME" << setw(15) << "NET ID"
                     << setw(10) << "CGPA" << setw(10) << "MARKS" << endl;
                cout << "----------------------------------------------------" << endl;
                for(auto p: people){
                    p->displayIDinfo();                
                }
            }
        }

        else if(choice == 3){
            string id;
            cout<<"ENTER THE ID TO DELETE"<<endl;
            cin>>id;

            bool found = false;

            for(int i = 0; i<people.size();i++){
                if(people[i]->getnetid()==id){
                    delete people[i];
                    people.erase(people.begin()+i);
                    cout<<"DELETED SUCCESSFULLY!"<<endl;
                    found=true;
                    break;
                }
            }

            if(!found){
                cout<<"STUDENT NOT FOUND!"<<endl;
            }
        }

        else if (choice == 4){
            cout<<"EXITING...."<<endl;         
            break;
        }

        else{
            cout<<"INVALID CHOICE!"<<endl;
        }
    }

    for(auto p : people){
        delete p;
    }
    return 0;
}
