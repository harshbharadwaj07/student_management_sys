//Student Management System created by Harsh Bharadwaj
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
	
//Profile structure
struct stdt
{
	char stu_name[50];
	char stu_lname[50];
	int roll;
	long int date_birth;
	int year;
	int sem;
	char f_name[50];
	long long int phoneno;
	char assign[50];
	char attendance[20];
	int marks;
};
struct stdt s[100];

//Student Portal
void studentptl()
{
	FILE *fptr,*ft;
	fptr=fopen("StudentDetails.dat", "a+");
	if(fptr == NULL)
	{
		printf("Cannot open the file");
		exit(1);
	}
	int i,oper;
	int recsize=sizeof(s[i-1]);
		printf("Enter your roll no.");
    	scanf("%d",&i);
    	printf("Choose which of the operation to be performed\n\n");
    	printf("\t\t1. View profile\n");
		printf("\t\t2. Edit details\n");
		printf("\t\t3. Assignments\n");
		printf("\t\t4. Attendance info\n");
		printf("\t\t5. Marks\n");
    	scanf("%d",&oper);
    	switch(oper)
    	{
    		case 1://Viewing personal details
    			printf("Below are your personal details\n");
    			while(fread(&s[i-1],recsize,1,fptr)==1)
    			{
					printf("First name :%s Last name :%s\n",s[i-1].stu_name,s[i-1].stu_lname);
					printf("Date of Birth :%ld\n",s[i-1].date_birth);
					printf("Year of Study :%d Semester :%d\n",s[i-1].year,s[i-1].sem);
					printf("Father's Name :%s\n",s[i-1].f_name);
					printf("Phone No. :%lld\n",s[i-1].phoneno);
				}
					break;
			case 2://Editing details
				while(fread(&s[i-1],recsize,1,fptr)==1)
				{
					printf("\nEnter corrected/same first name :\t");
					scanf("%s",s[i-1].stu_name);
					printf("Enter corrected/same last name :\t");
					scanf("%s",s[i-1].stu_lname);
					printf("Enter corrected/same dob :\t");
					scanf("%ld",&s[i-1].date_birth);
					printf("Enter new/same year :\t");
					scanf("%d",&s[i-1].year);
					printf("Enter new/same semester :\t");
					scanf("%d",&s[i-1].sem);
					printf("Enter corrected/same Father's name :\t");
					scanf("%s",s[i-1].f_name);
					printf("Enter new/same phone no. :\t");
					scanf("%lld",&s[i-1].phoneno);
					fseek(fptr,recsize,SEEK_CUR);
					fwrite(&s[i-1],recsize,1,fptr);
				}
				break;
			case 3://Viewing assignments
				printf("Assignment :");
				while(fread(&s[i-1],recsize,1,fptr)==1)
				{
					printf("%s\n",s[i-1].assign);
				}
				break;
			case 4://Viewing attendance
				printf("Attendance :");
				while(fread(&s[i-1],recsize,1,fptr)==1)
				{
					printf("%s\n",s[i-1].attendance);
				}
				break;
			case 5://Viewing marks
				printf("Marks :");
				while(fread(&s[i-1],recsize,1,fptr)==1)
				{
					printf("%d\n",s[i-1].marks);
				}
				break;
			default:
				printf("Not a valid operation\n");
		fclose(fptr);
		}
}


//Teacher portal
void teacherptl()
{
	FILE *fptr;
	fptr=fopen("StudentDetails.dat", "a+");
	if(fptr == NULL)
	{
		printf("Cannot open the file");
		exit(1);
	}
	int i,oper,r,n;
	int recsize=sizeof(struct stdt);
	char temp;
    	
    	printf("Choose which of the operation to be performed\n\n");
    	printf("\t\t1. View profile of students\n\t\t2. Add a student\n\t\t3. Assignments\n\t\t4. Attendance\n\t\t5. Marks\n");
    	scanf("%d",&oper);
    	switch(oper)
    	{
    		case 1://Viewing student's details
    			printf("Enter the roll no. of student whose details are to be viewed\n");
    			scanf("%d",&i);
    			while(fread(&s[i-1],recsize,1,fptr)==1)
    			{
					printf("Below are student's personal details\n");
					printf("First name :%s Last name :%s\n",s[i-1].stu_name,s[i-1].stu_lname);
					printf("Date of Birth :%ld\n",&s[i-1].date_birth);
					printf("Year of Study :%d Semester :%d\n",&s[i-1].year,&s[i-1].sem);
					printf("Father's Name :%s\n",s[i-1].f_name);
					printf("Phone No. :%lld\n",&s[i-1].phoneno);
				}
				break;
			case 2://Adding new student
				printf("Enter the number of students whose data has to be added\n");
				scanf("%d",&r);
				for (int j=0;j<r;j++){
				
					fseek(fptr,0,SEEK_END);
					printf("Enter roll no.\t");
					scanf("%d",&i);
					fflush(stdin);
					printf("Enter first name of student:\t");
					scanf("%s",s[i-1].stu_name);
					printf("Enter the last name:\t");
					scanf("%s",s[i-1].stu_lname);
					printf("Enter Father's name:\t");
					scanf("%s",s[i-1].f_name);
					printf("Enter DOB:\t");
					scanf("%d",&s[i-1].date_birth);
					printf("Enter year and semester of study:\t");
					scanf("%d %d",&s[i-1].year,&s[i-1].sem);
					printf("Enter phone no.:\t");
					scanf("%lld",&s[i-1].phoneno);

					fwrite(&s[i-1],recsize,1,fptr);
					if(fwrite !=0)
					printf("Record added successfully\n");
					else
					printf("Error entering record\n");
				}
				break;
			case 3://Assigning work to particular student
					int i;
				printf("Enter the roll no. of student to whom work has to be assigned\n");
				scanf("%d",&i);
				
					printf("Assign the work\n");
					fseek(fptr,0,SEEK_CUR);
					scanf("%c",&temp);
					scanf("%[^\n]",s[i-1].assign);
					fwrite(&s[i-1],recsize,1,fptr);
					if(fwrite !=0)
					printf("Assignment uploaded successfully\n");
					else
					printf("Error uploading the assignment\n");
					fflush(stdin);
				break;

			case 4://Marking attendance of students
				printf("Enter the no. of students whose attendance has to be marked");
				scanf("%d",&n);
					for(int i=1;i<=n;i++)
					{
					printf("Enter attendance: Roll no.:%d\n",i++);
					fseek(fptr,0,SEEK_CUR);
					scanf("%s",s[i-1].attendance);
					fwrite(&s[i-1],recsize,1,fptr);
					if(fwrite !=0)
					printf("Attendance marked successfully\n");
					else
					printf("Error marking the attendance\n");
				}
				break;
			case 5://Giving marks to the students
				
			printf("Enter the no. of students whose marks are to be entered\n");
				scanf("%d",&n);
				
					for(int i=1;i<=n;i++){
					printf("Enter marks: Roll No.: %d\t",i++);
					fseek(fptr,0,SEEK_CUR);
					scanf("%d",&s[i-1].marks);
					fwrite(&s[i-1],recsize,1,fptr);
					if(fwrite !=0)
					printf("Marks added successfully\n");
					else
					printf("Error adding the marks\n");
				}
				break;
			default:
				printf("Invalid operation");
		}
	fclose(fptr);
}

//Student login
int loginstdt()
{
	char user_name[20];
	char password[10];
	int c,flag=0;
	printf("Enter your username:\t");
	scanf("%s",&user_name);
	
	printf("Enter your password:\t");
	scanf("%s",&password);
	if(strcmp(user_name,"student123")==0)
	{
		if(strcmp(password,"software@123")==0)
		{
			printf("Welcome to the student portal\n");
			flag=1;
		}
		else
		{
			printf("Wrong password\n");
		}
	}
	else
	{
		printf("User does not exists\n");
	}
	return (flag);
}

//Teacher login
int loginteacher()
{
	int flag=0;
	char user_name[20];
	char password[10];
	int c;
	printf("Enter your username:\t");
	scanf("%s",&user_name);
	
	printf("Enter your password:\t");
	scanf("%s",&password);
	if(strcmp(user_name,"teacher123")==0)
	{
		if(strcmp(password,"teacher#123")==0)
		{
			printf("Welcome to the teacher's portal\n");
			flag=1;
		}
		else
		{
			printf("Wrong password\n");
		}
	}
	else
	{
		printf("User does not exists\n");
	}
	return (flag);
}

//Main funtion
int main()
{
	int a,b,field;
	
	for(;;)
	{	
		printf("Welcome to the Student Management System\n\n");
	
		printf("Choose your field\n"); 
    	printf("\t\t1. Teacher login\n"); 
    	printf("\t\t2. Student's login\n");
		printf("\t\t3. Exit System\n"); 
    	scanf("%d", &field);
    
    		switch (field)
			{ 
    		case 1: 
    
        		a=loginteacher();
        		if(a==1)
        		{
					teacherptl();
				}
				else
				{
					exit(1);
				}
            	break; 
    		case 2:
    			
        		b=loginstdt();
        		if(b==1)
        		{
					studentptl(); 
            	}
            	else
            	{
            		exit(1);
				}
				break;
            case 3:
            	exit(1);
    		}
    }
    return 0;
}
