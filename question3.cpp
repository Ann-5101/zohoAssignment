#include <bits/stdc++.h>
  
using namespace std;

void Operations(int,int);
void Add_Sub_Role(int,int);
void DisplayRole(int,int);
/*void DeleteRole(int,int);
void AddUser(int,int);
void DisplayUsers(int,int);
void DisplayUsers_and_SubUsers(int,int);
void DeleteUser(int,int);
void NumberofUser(int,int);
void HeightofRoleHierachy(int,int);
void Commonboss(int,int);
*/

struct op {
    int code;
    string subrole;
    string reporter;
    string name;
    string Role;
    string hierarchy;
    
    
};
op op1[200];
void Operations(int j, int count)
{
    int option;
    cout <<"Operations: \n";
  
    cout << "\t1. Add Sub Role. \n";
    cout << "\nOperattion to be performed: ";
    cin >> option;
    switch(option)
    {
    case 1:
    j=j+1;
    Add_Sub_Role(j,count);
    break;
    case 2:
    DisplayRole(j,count);
    break;
    /*case 3:
    DeleteRole(j,count);
    break;
    case 4:
    AddUser(j,count);
    break;
    case 5:
    DisplayUsers(j, count);
    break;
    case 6:
    DisplayUsers_and_SubUsers(j,count);
    break;
    case 7:
    DeleteUser(j,count);
    break;
    case 8:
    NumberofUser(j,count);
    break;
    case 9:
    HeightofRoleHierachy(j,count);
    break;
    case 10:
    Commonboss(j,count);
    break;
    */
    
    default:break;
}
}
void Add_Sub_Role(int j,int count)
{
    string temp;
    int i = j;
    op1[i].code=i;
    cout << "Enter the Sub role name: ";
    cin>>temp;
    (op1[i].subrole=temp);
    cout << "Enter reporting to role name : ";
    cin>>(op1[i].reporter);
    Operations(j,count);
}

void DisplayRole(int j,int count)
{
   int p=0; 
  (op1[0].hierarchy=op1[0].subrole);
   for(int m=0;m<j;m++)
   {
       for(int n=0;n<j;n++)
       {
       if(op1[m].hierarchy==op1[n+1].reporter)
       {
           p++; 
           (op1[p].hierarchy=op1[n+1].subrole);
            
       }
       }
       }
   
   for(int i=0;i<=j;i++)
   {
       cout<<op1[i].hierarchy<<"\t";
   }
    
    
    
   cout<<"\n" ;
    
  /*  for(int i=0;i<j;i++)
    {
    cout <<op1[i].subrole<<"\t";
    }
    cout<<"\n";*/
    Operations(j,count);
}
int main()
{
    int j=0,count=0;
    string rootrole;
    cout<<"Enter root role name: ";
    cin>>(rootrole);
    op1[0].code=0;
    (op1[0].subrole=rootrole);
    Operations(j,count);
    return 0;
}
