#include <iostream>
using namespace std;

struct student{
    int id;
    char name[50];
    float agno;
    int graduation_state;

};

 //function to add a student;
void addstudent(student*tab[], int &nbstudents){
   student*e=new student;
   cout<< "enter the student's ID:";
   cin>>e->id;
   cin.ignore();
   cout<<"enter the student's name:";
   cin.getline(e->name,50);
   cout<< " enter the student's AGNO:";
   cin>> e->agno;
   cout<< "state of graduation,(0=not graduated, 1= graduated)";
   cin >> e->graduation_state;

   tab[nbstudents]=e;
   nbstudents++;
   cout<<"student added!\n";
}

// function to show a student's information

void showStudent(student* s) {
    cout << "ID: " << s->id << endl;
    cout << "Name: " << s->name << endl;
    cout << "AGNO: " << s->agno << endl;
    cout << "Graduation State: " << s->graduation_state << endl;
    cout << "-----------------------------\n";
}


// function to show all of the students
void liststudents(student*tab[], int nbstudents){
    if (nbstudents==0){
        cout << "No students to display.\n";
        return;    
    }
    for(int i=0;i<nbstudents; i++){
       showStudent(tab[i]);
       cout<<" student SHOWEDDDDDDDD !!!!!\n";
    }
}


// function to find the  highest AGNO
void highestAGNO(student*tab[],int nbstudents){
    if(nbstudents==0){
        cout<<"the class is emptyyyyy.\n";
        return;
    }
    student*beststudent=tab[0];
    for(int i=1;i<nbstudents;i++){
        if ((beststudent->agno)<tab[i]->agno){
            beststudent=tab[i];
        }
    }
    showStudent(beststudent);
}


//finding a student 
void findstudent(student*tab[], int nbstudents, int id){
     if(nbstudents==0){
        cout<<"the class is emptyyyyy.\n";
        return;
    }
    for(int i=0;i<nbstudents;i++){
        if(tab[i]->id==id){
            showStudent(tab[i]);
            return;
        }
    }

        cout<<"STUDENT NOT FOUND!!!\n";
}



//function to update a student
void update(student* tab[], int nbstudents, int id){
    if(nbstudents==0){
        cout<<"empty class\n";
        return;
    }

    for(int i=0;i<nbstudents;i++){
        if( tab[i]->id==id){
            cout<<"enter the new name:";
            cin.ignore();
            cin.getline(tab[i]->name,50);

            cout<<"enter the new AGNO:";
            cin>> tab[i]->agno;

            cout<<"enter the new graduation state(0/1)";
            cin>>tab[i]->graduation_state;
            cout<<"student's info successfully updated updated!\n";
            return;
        }
    }
    cout<<"student not found :(\n";

}

int main(){

   student* tab[100];
   int nbstudents = 0;

   int choice;

   
     do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Add Student\n";
        cout << "2. List Students\n";
        cout << "3. Find Student With Highest AGNO\n";
        cout << "4. Search Student by ID\n";
        cout << "5. Update Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1: {
                addstudent(tab, nbstudents);
                break;
            }

            case 2: {
                liststudents(tab, nbstudents);
                break;
            }

            case 3: {
                highestAGNO(tab, nbstudents);
                break;
            }

            case 4: {
                int id;
                cout << "Enter the ID you want to search: ";
                cin >> id;
                findstudent(tab, nbstudents, id);
                break;
            }

            case 5: {
                int id;
                cout << "Enter the ID you want to update: ";
                cin >> id;
                update(tab, nbstudents, id);
                break;
            }

            case 6:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);




   for (int i = 0; i < nbstudents; i++) {
       delete tab[i]; 
      tab[i] = nullptr; 
   }
   return 0;
}