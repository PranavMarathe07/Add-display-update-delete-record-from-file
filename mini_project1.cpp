#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
using namespace std;

class Student
{
			private :
			                  int Roll;
			                  char Name[20];
			                  float per;
			                  
			public :                  
			                void get();
			                void put();
			                void Add();
			                void display();
			                void search(int Roll);
			                void deleterec(int Roll);
			                 void getupdate();
			                 void update(int Roll);
};

void Student :: get()
{
			cout <<"\n\t Enter the Roll no, Name, percentage of student : ";
			cin >> Roll >> Name >> per;
}

void Student :: getupdate()
{
			cout <<"\n\t Enter the Name, percentage of student : ";
			cin >> Name >> per;
}

void Student :: put()
{
			cout <<"\n\t " << setiosflags(ios :: left) << setw(5) << Roll << setw(20) << Name << setw(5) << per;
}

int main()
{
			int choice;
			char ch;
			Student obj;
			int Roll;
			
			do
			{
					cout <<"\n\t....................";
					cout <<"\n\t\t MENU ";
					cout <<"\n\t .....................";
					cout <<"\n\t  1. Add Record :  ";
					cout <<"\n\t  2. Display Record :  ";
					cout <<"\n\t  3. Search Record :  ";
					cout <<"\n\t  4.Delete Record : ";
					cout <<"\n\t  5.Update Record : ";
					cout <<"\n\t  6.Exit ";
					cout <<"\n\t .................... ";
					cout <<"\n\t Enter your choice (1-6) : ";
					cin >> choice;
					
					switch(choice)
					{
							case 1 :
							              obj.Add();
							              break;
							              
							case 2 :
							              cout <<"\n\t...............................................................";
							              cout <<"\n\t " << setiosflags(ios :: left) << setw(5) <<"Roll" << setw(20) <<"Name" << setw(5) <<"Percentage";
							              cout <<"\n\t...............................................................";
							              obj.display();
							              cout <<"\n\t..............................................................";
							              break;
							              
							case 3 :
							              cout <<"\n\t Enter the Roll no to search the record : ";
							              cin >> Roll;
							              obj.search(Roll);
							              break;
							              
							case 4 :
							              cout <<"\n\t Enter the Roll no to delete the record : " ;
							               cin >> Roll;
							              obj.deleterec(Roll);
							              break;
							              
							case 5 :
							             cout <<"\n\t Enter the Roll no to update the record : " ;
							              cin >> Roll;
							              obj.update(Roll);
							              break;
							              
							case 6 :
							              exit(0);
							              break;
							              
							default :
							                 cout <<"\n\t Invalid choice ";         
					}
					cout <<"\n\t Do You Want to continue(y/n) : ";
					cin >> ch;
			}
			
			while(ch =='y'  || ch =='Y');
			
			return 0;
}

void Student :: Add()
{
			Student objs;
			fstream objf;
			objf.open("data.txt", ios :: app | ios :: binary);
			
			objs.get();
			objf.write((char*)&objs, sizeof(objs));
			
			cout <<"\n\t  Record Added Succsesfully .....";
			objf.close();
}

void Student :: display()
{
			Student objs;
			fstream objf;
			objf.open("data.txt", ios :: in | ios :: binary);              //in read mode 
			
			while (objf.read((char*)&objs, sizeof(objs)))
			{
					objs.put();
			}
			objf.close();
}

void Student :: search(int Roll)
{
			Student objs;
			fstream objf;
			objf.open("data.txt", ios :: in | ios :: binary);              
			int x = 0;
			
			while (objf.read((char*)&objs, sizeof(objs)))
			{
			        if(objs.Roll==Roll)
			        {
							objs.put();
							x++;
					}
			}
			objf.close();
			if(x==0)
			{
					cout <<"\n\t Record not Found......";
			}
			else {
					cout <<"\n\t Record Found " << x <<"  times";
			}
}

void Student :: deleterec(int Roll)
{
			Student objs;
			fstream objf, objt;
			objf.open("data.txt", ios :: in | ios :: binary);       
			objt.open("temp.txt", ios :: out | ios :: binary);        
			int x = 0;
			
			while (objf.read((char*)&objs, sizeof(objs)))
			{
			        if(objs.Roll==Roll)
			        {
							x++;
					}
					else
					{
							 objt.write((char*)&objs, sizeof(objs));
					}
			}
			objf.close();
			objt.close();
			remove("data.txt");
			rename("temp.txt", "data.txt");
			
			if(x==0)
			{
					cout <<"\n\t Record not Found......";
			}
			else {
					cout <<"\n\t Record Deleted..... " << x <<"  times";
			}
}

void Student :: update(int Roll)
{
			Student objs;
			fstream objf, objt;
			objf.open("data.txt", ios :: in | ios :: binary);       
			objt.open("temp.txt", ios :: out | ios :: binary);        
			int x = 0;
			
			while (objf.read((char*)&objs, sizeof(objs)))
			{
			        if(objs.Roll==Roll)
			        {
			               objs.getupdate();
			               objt.write((char*)&objs, sizeof(objs));
							x++;
					}
					else
					{
							 objt.write((char*)&objs, sizeof(objs));
					}
			}
			objf.close();
			objt.close();
			remove("data.txt");
			rename("temp.txt", "data.txt");
			
			if(x==0)
			{
					cout <<"\n\t Record not Found......";
			}
			else {
					cout <<"\n\t Record  updated..... " << x <<"  times";
			}
}
