#include <bits/stdc++.h>
  
using namespace std;
  
void Operations(int,int);
void Add_Sub_Role(int,int);
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
    /*case 2:
    DisplayRole(j,count);
    break;
    case 3:
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
