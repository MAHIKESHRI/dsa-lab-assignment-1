//assignment 1 DSA
//searching and sorting

#include <iostream>
using namespace std;

/*defining a structure name student which consist of roll number,name,sgpa of five student,*/ 
struct student
{
	int rollno;
	string name;
	float sgpa;
};
//1.function to display the sorted roll number using bubble sort.
void bubblesort(student s[])
{
	 for(int i=0; i<5; i++)
	    {
	    	for(int j=0; j<5; j++)
	    	{
	    		if(s[j].rollno>s[j+1].rollno)
	    		{
	    			int a;
	    			a=s[j].rollno;
	    			s[j].rollno=s[j+1].rollno;
	    			s[j+1].rollno=a;
				}
			}
		}
		cout<<"sorted roll number::"<<endl<<"[";
		for(int j=0;j<5;j++)
		{
			cout<<s[j].rollno<<",";
		}
		cout<<"]"<<endl;
	
}

//2.ARRANGE LIST OF STUDENTS ALPHABETICALLY.>>INSERTION SORT
void insertionsort(student s[])
{
	for(int i=0;i<5-1 ; ++i)
	{
		for(int j=0 ; j<5-i-1 ;++j)
		{
			if(s[j].name > s[j+1].name)
			{
				student temp;
				temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
			}
		}
	}
	cout<<"Alphabetically arranged :"<<endl;
	for(int j=0; j<5;j++)
	{
		cout<<"name :"<<s[j].name<<" "<<",Roll number:"<<s[j].rollno<<"<<" ",sgpa:"<<s[j].sgpa<<endl;
	}
}
	


//3.QUICK SORT
int partition(student s[], int low, int high)
{

    int NUM_STUDENT=5;
	float pivot=s[high].sgpa;//choosing the last element as pivot
	int i=low-1;//index of smaller element
	
	for(int j=low; j<high; j++){
		if(s[j].sgpa>pivot)//sorting in descending order
		{
			i++;
			swap(s[i],s[j]);
		}
		
    }
	swap(s[i+1],s[high]);
	return(i+1);
}

void quicksort(student s[], int low , int high)
{
    	if(low<high)
		{
    		int pi=partition(s,low,high);
    		quicksort(s,low,pi-1);
    		quicksort(s,pi+1 ,high);
		}
}
//4.function to search and display students by sgpa.
void searchbysgpa(student s[] , int size , float searchsgpa)
{
    bool found = false;
    cout<<"STUDENTS WITH SGPA"<<searchsgpa <<endl;
    for (int i=0 ; i<size ;i++)
    {
        if(s[i].sgpa==searchsgpa)
        {
            cout<<"NAME ::"<<s[i].name<<" , ROLL NUMBER::"<<s[i].rollno<<" , SGPA::"<<s[i].sgpa<<endl;
            found=true;
        }
    }
    if(!found)
	{
         cout<<"NO STUDENTS FOUND WITH SGPA" <<searchsgpa <<endl;
    }
}
//5.function to search a particular student by it's name>binary search
void binarysearch(student s[] , int n ,string searchName)
{
	int left= 0;
	int right = 5-1;
	bool found = false;
	
	while(left<=right)
	{
		int mid = left + (right-left)/2;
		if (s[mid].name == searchName)
		{
			found = true;
			//find all occurences of the name
			int start =mid;
			while(start>=0 && s[start].name == searchName)
			{
				--start;
			}
			start++;
			
			int end = mid;
			while(end < 5 && s[end].name == searchName)
			{
				++end;
			}
			//display all occurences
			for(int i = start; i<end; ++i)
			{
				cout<<"name "<<s[i].name<<", roll no"<<",SGPA:"<<s[i].sgpa<<endl;
			}
			return;
		}
		else if(s[mid].name <searchName)
		{
			left=mid+1;
		}
		else{
			right=mid-1;
		}
	}
	if (!found){
		cout<<"no student found with the name:"<<searchName<<endl;
	}
}




int main(){
student s[5];


//taking input from user
	for(int i=0 ; i<5 ; i++)
	{
		cout<<"ENTER NAME, ROLL NUMBER , SGPA OF STUDENT"<<" "<<i+1<<endl;
		cout<<"Enter rollno:"<<endl;
		cin>>s[i].rollno;
		cout<<"Enter name:"<<endl;
		cin>>s[i].name;
		cout<<"Enter your sgpa:"<<endl;
		cin>>s[i].sgpa;
		
	}
	for(int i=0 ; i<5; i++)
	{
		cout<< "Roll number: " <<i+1<< " is "  <<s[i].rollno<<endl;
		cout<< "name of student:" <<i+1<< "is" <<s[i].name<<endl;
		cout<< "sgpa of student:" <<i+1<< "is" <<s[i].sgpa<<endl;
	}
	
	
//1.bubble sorting
	    for(int i=0; i<5; i++)
	    {
	    	for(int j=0; j<5; j++)
	    	{
	    		if(s[j].rollno>s[j+1].rollno)
	    		{
	    			int a;
	    			a=s[j].rollno;
	    			s[j].rollno=s[j+1].rollno;
	    			s[j+1].rollno=a;
				}
			}
		}
		cout<<"sorted roll number::"<<endl<<"[";
		for(int j=0;j<5;j++)
		{
			cout<<s[j].rollno<<",";
		}
		cout<<"]"<<endl;
//2.ARRANGE LIST OF STUDENTS ALPHABETICALLY>>INSERTION SORT.
    cout<<"PERFORMING INSERTION SORT"<<endl;
    insertionsort(s);
    cout<<"press 1 to continue and 0 to exit ::"<<endl;
    cout<<endl;
    
    
//3.ARRANGE LIST OF STUDENTS TO FIND OUT FIRST TEN TOPPERS FROM CLASS>>--QUICK SORT
    quicksort(s,0,5-1);
    cout<<"TOP 3 TOPPERS:"<<endl;
    cout<<endl;
    for(int i=0; i<3 && i<5; ++i){
    	cout<<"NAME :"<<s[i].name<<",ROLL NO:"<<s[i].rollno<<",SGPA:"<<s[i].sgpa<<endl;
	}
//4.SEARCH AND DISPLAY STUDENTS BY SGPA.<<linear search
    float searchsgpa;
    cout<<"enter the sgpa u want to search"<<endl;
    cin>>searchsgpa;
    searchbysgpa (s, 5, searchsgpa);
    cout<<endl;


//5.search for a student by name>>binary search.
    int n=sizeof(s);
    string searchName;
    cout<<"Enter the name of student to search:";
    cin>>searchName;
    cout<<endl;
    
    binarysearch(s , n , searchName);
    cout<<endl;

    return 0;
}


    



    
      



