#include <bits/stdc++.h>
  
using namespace std;
  
void Operations(int,int);
void Add_Sub_Role(int,int);
void DisplayRole(int,int);
void DeleteRole(int,int);
void AddUser(int,int);
void DisplayUsers(int,int);
void DisplayUsers_and_SubUsers(int,int);
void DeleteUser(int,int);
void NumberofUser(int,int);
void HeightofRoleHierachy(int,int);
void Commonboss(int,int);

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
  
    cout << "\t1. Add Sub Role. \n\t2. Display Roles. \n\t3. Delete Role. \n\t4. Add User. \n\t5. Display Users. \n\t6. Display User and Sub Users. \n\t7. Delete User. \n\t8. Number of users from top. \n\t9. Height of Role hierarchy. \n\t10. Common boss of Users.";
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
    
    
    default:break;
}
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
void DeleteRole(int j,int count)
{
    
    int temp;
    string del,trans;
    cout<<"Enter the role to be deleted : ";
    cin>>del;
    cout<<"Enter the role to be transferred :";
    cin>>trans;
    for(int i=0;i<=j;i++)
    {
       if(op1[i].subrole==del)
     {
         for(int k=0;k<j;k++){
         if(op1[k].subrole==trans){
           temp= k;
         }
         }
         op1[i].subrole=trans;
         
     }
   }
     
     for (int k = 0; k <= j ; k++) {
        
     op1[temp].subrole = op1[temp + 1].subrole;
      Operations(j,count);  
    }
    Operations(j,count);
}
void AddUser(int j,int count)
{
   
    string Role,name;
    cout<<"Enter User Name : ";
   
    cin>>(op1[count].name);
    cout<<"Enter Role :";
    cin>>(op1[count].Role);
   
    count++;
    
    Operations(j,count);
}
void DisplayUsers(int j,int count)
{
    for(int i=0;i<count;i++)
    {
        cout<<op1[i].name<<"- "<<op1[i].Role<<"\n";
    }
    Operations(j,count);
}
void DisplayUsers_and_SubUsers(int j,int count)
{
    for(int m=0;m<=count;m++)
    {
        cout<<"hello";
      cout<<op1[m].name<<"-";
      for(int k=0;k<=j;k++)
      {
        if(op1[m].Role==op1[k].hierarchy)
        {
            for(int n=m;n<count;m++)
            {
                if(op1[n].Role==op1[k].hierarchy)
                {
                    cout<<op1[n].name;
                    break;
                    
                }
            }
        }
      }
    }
    cout<<"\n";
    Operations(j,count);
}
void DeleteUser(int j,int count)
{
   int temp=0;
    char del[20];
    cout<<"Enter the Username to be deleted : ";
    cin>>(del);
   
    for(int i=0;i<=j;i++)
    {
       if(op1[i].name==del)
     {
         for(int k=0;k<count;k++)
         {
             temp=k;
         }
         for (int k = temp; k <= count ; k++) 
         {
             (op1[k].name=op1[k + 1].name) ;
        
         }
     }
     
    }
         
    Operations(j,count);
}
void NumberofUser(int j,int count)
{
    string usr;
    cout<<"Enter user name: ";
    cin>>(usr);
    for(int i=0;i<count;i++)
    {
        if(usr==op1[i].name)
        {
            for(int y=0;y<j;y++)
            {
                if(op1[i].Role==op1[y].hierarchy)
                {
                    cout<<"Number of users from top: "<<y;
                }
            }
        }
    }
 
 
 
  Operations(j,count)  ;
  
}
void HeightofRoleHierachy(int j, int count)
{
   for(int i=0;i<count;i++)
   {
       for(int k=0;k<j;k++)
       {
         if(op1[count].Role==op1[k].hierarchy)
                {
                    cout<<"Height of role hierachy: "<<k;
                }  
       }
   }
   
    Operations(j,count)  ; 
}
void Commonboss(int j,int count)
{
    string us1,us2;
    int temp1,temp2;
    cout<<"Enter user 1: ";
    cin>>us1;
    cout<<"Enter user 2: ";
    cin>>us2;
    for(int i=0;i<count;i++)
    {
        if(op1[i].Role==op1[0].hierarchy)
        {
            cout<<"Top most common boss : "<<op1[i].name;
        }
    }
    cout<<"\n";
    
    
     Operations(j,count)  ;
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


