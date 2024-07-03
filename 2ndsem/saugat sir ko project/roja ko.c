#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
struct student{
char name[30];
int roll,math,science,english,nepali,social;

};

void list(int);
void search();
void edits();
void deletes();
void edit21(int);
void sdelete(int);
void marksheet(int);
void line();
void boundary();

int main()
{
int choice;
redo:
printf("\n");
    line();
printf("1.Add a record\n2.Add Bulk Records\n3.List Students\n4.Search Students\n5.Quit\n");
printf("What is your choice? :");
scanf("%d%*c",&choice);
switch(choice)
{
case 1:
printf("\n");
    line();
list(1);
break;
case 2:
printf("\n");
    line();
search();
break;
case 3:
printf("\n");
edits();
break;
case 4:
deletes();
break;
case 5:
exit(1);
break;
default:
printf("Bye Bye");
break;

}
return 0;
}

void boundary()
{
    int i;
    for(i=1; i<106; i++)
{
        printf("*");
    }
}

void line()
{
    int columns;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int i;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    for(i=0; i<columns; i++)
{
        printf("*");
    }
    //Stack_Overflow_Copied
}
int rollcheck(int roll){
    struct student st;

    FILE *roll_check = fopen("student.txt", "r");
    while(fscanf(roll_check, "%[^\n]\n%d\n%d\n%d\n%d\n%d\n%d\n", &st.name, &st.roll, &st.math, &st.science, &st.english, &st.nepali, &st.social) != EOF){
        if(st.roll == roll){
            fclose(roll_check);
            return 1;
        }
    }
    fclose(roll_check);
    return 0;
}

void list(int n)
{
struct student st[n];
int i,z;
for(i=0;i<n;i++)
{
FILE *p;
p=fopen("student.txt","a");
printf("\nEnter the information for student %d\n", i+1);
printf("\nEnter name:");
scanf("%[^\n]",&st[i].name);
re_roll:
printf("Enter Roll:");
scanf("%d",&st[i].roll);
z = rollcheck(st[i].roll);
if(z!=0)
{
printf("Already Taken!!");
goto re_roll;
}
re_marks:
printf("\nEnter Marks in Mathematics:");
scanf("%d",&st[i].math);
printf("Enter Marks in Science:");
scanf("%d",&st[i].science);
printf("Enter Marks in English:");
scanf("%d",&st[i].english);
printf("Enter Marks in Nepali:");
scanf("%d",&st[i].nepali);
printf("Enter Marks in Social:");
scanf("%d%*C",&st[i].social);

if(st[i].math >100 || st[i].science >100 || st[i].english >100 || st[i].nepali >100 || st[i].social>100){
            printf("Error! Full Marks is 100\n");
            goto re_marks;
        }

fprintf(p,"%s\n%d\n%d\n%d\n%d\n%d\n%d\n",st[i].name,st[i].roll,st[i].math,st[i].science,st[i].english,st[i].nepali,st[i].social);
fclose(p);

}
main();

}
void search()
{
int stnum;
printf("\nHow many Students? ");
scanf("%d%*c",&stnum);
list(stnum);

}
void edits()
{
struct student yt;
int i;
FILE *p;
line();
p=fopen("student.txt","r");
printf("Roll\tName\n");
while(fscanf(p,"%[^\n]\n%d\n%d\n%d\n%d\n%d\n%d\n",&yt.name,&yt.roll,&yt.math,&yt.science,&yt.english,&yt.nepali,&yt.social)!=EOF)
{
printf("%d      %s\n",yt.roll,yt.name);
}
fclose(p);
main();

}
void deletes()
{

int count,roll;
printf("\n");
line();
printf("Enter Roll No:");
scanf("%d",&roll);

struct student find;
FILE *p;
p=fopen("student.txt","r");
while(fscanf(p,"%[^\n]\n%d\n%d\n%d\n%d\n%d\n%d\n",&find.name, &find.roll, &find.math, &find.science, &find.english, &find.nepali, &find.social)!=EOF)
{
if(find.roll==roll)
{
count=1;
fclose(p);
break;
}
}
if(count==0)
{
printf("\n");
   line();
   printf("\nRoll Number Not Found!!");
   fclose(p);
   main();
}
int option;
printf("\n");
line();
printf("Record Found :\n");
printf("Student Name :%s\n",find.name);
line();
printf("1.Edit Record\n2.Delete Record\n3.View Marksheet\n4.Quit\n");
printf("What is you choice? :");
scanf("%d%*c",&option);
switch(option)
{
case 1:
edit21(find.roll);
break;

case 2:
sdelete(find.roll);
break;

case 3:
marksheet(find.roll);
break;

case 4:
exit(3);

default:
printf("Bye Bye!!");

}
}

void edit21(int attendence)
{
struct student change, change1;
    FILE *p = fopen("student.txt", "r");
    FILE *q = fopen("q.txt", "a");
    int edit_choice, g, ctn_edit, per_roll;

    while(fscanf(p, "%[^\n]\n%d\n%d\n%d\n%d\n%d\n%d\n", &change.name, &change.roll, &change.math, &change.science, &change.english, &change.nepali, &change.social) != EOF){
        if(change.roll == attendence){
            per_roll = change.roll;
            break;
        }
    }
    rewind(p);
    printf("\n");
    line();
    printf("\nHello %s!\nYour Current Information is:\n\n", change.name);
    printf("Name: %s\nRoll No: %d\nMarks in Mathematics: %d\nMarks in Science: %d\nMarks in English: %d\nMarks in Nepali: %d\nMarks in Social: %d", change.name, change.roll, change.math, change.science, change.english, change.nepali, change.social);
    printf("\n\nWhich Information Do You Want to Edit? Choose From The Following:");
    printf("\n[1] Name\n[2] Roll No.\n[3] Marks in Mathematics\n[4] Marks in Science\n[5] Marks in English\n[6] Marks in Nepali\n[7] Marks in Social\nPress Any Other Key To Go Back");
    printf("\n\nChoose: ");
    scanf("%d", &edit_choice);
    fflush(stdin);

    switch(edit_choice){
        case 1:
        printf("Enter New Name: ");
        gets(change.name);
        fflush(stdin);
        break;

        case 2:
        re_roll_edit:
        printf("Enter New Roll No: ");
        scanf("%d", &change.roll);
        fflush(stdin);
        g = rollcheck(change.roll);
        if(g!=0){
            printf("Taken Already");
            goto re_roll_edit;
        }
        break;

        case 3:
        edit_math:
        printf("Enter New Marks in Mathematics: ");
        scanf("%d", &change.math);
        fflush(stdin);
        if(change.math > 100){
            printf("Error! Full Marks is 100\n");
            goto edit_math;
        }
        break;

        case 4:
        edit_science:
        printf("Enter New Marks in Science: ");
        scanf("%d", &change.science);
        fflush(stdin);
        if(change.science > 100){
            printf("Error! Full Marks is 100\n");
            goto edit_science;
        }
        break;

        case 5:
        edit_english:
        printf("Enter New Marks in English: ");
        scanf("%d", &change.english);
        fflush(stdin);
        if(change.english > 100){
            printf("Error! Full Marks is 100\n");
            goto edit_english;
        }
        break;

        case 6:
        edit_nepali:
        printf("Enter New Marks in Nepali: ");
        scanf("%d", &change.nepali);
        fflush(stdin);
        if(change.nepali > 100){
            printf("Error! Full Marks is 100\n");
            goto edit_nepali;
        }
        break;

        case 7:
        edit_social:
        printf("Enter New Marks in Social: ");
        scanf("%d", &change.social);
        fflush(stdin);
        if(change.social > 100){
            printf("Error! Full Marks is 100\n");
            goto edit_social;
        }
        break;
       
        default:
        remove("q.txt");
        main();
    }
   
    while(fscanf(p, "%[^\n]\n%d\n%d\n%d\n%d\n%d\n%d\n", &change1.name, &change1.roll, &change1.math, &change1.science, &change.english, &change.nepali, &change.social) != EOF){
        if(change1.roll != per_roll){
            fprintf(q, "%s\n%d\n%d\n%d\n%d\n%d\n%d\n", change1.name, change1.roll, change1.math, change1.science, change1.english, change1.nepali, change1.social);
        }
        else{
            fprintf(q, "%s\n%d\n%d\n%d\n%d\n%d\n%d\n", change.name, change.roll, change.math, change.science, change.english, change.nepali, change.social);
        }
    }
    fclose(p);
    fclose(q);
    remove("student.txt");
    rename("q.txt","student.txt");

    re_choose:
    printf("Edit Another Info?\n[1] Yes\n[2] No");
    printf("\nChoose : ");
    scanf("%d", &ctn_edit);
    fflush(stdin);
    if(ctn_edit == 1){
        edit21(change.roll);
    }
    else if(ctn_edit == 2){
        main();
    }
    else{
        printf("\nValue Out of Bounds!!");
        goto re_choose;
    }
}

void sdelete(int ty_roll)
{
struct student delete1;
    FILE *p = fopen("student.txt", "r");
    FILE *q = fopen("q.txt", "w");

    while(fscanf(p, "%[^\n]\n%d\n%d\n%d\n%d\n%d\n%d\n", &delete1.name, &delete1.roll, &delete1.math, &delete1.science, &delete1.english, &delete1.nepali, &delete1.social) != EOF){
        if(delete1.roll != ty_roll){
            fprintf(q, "%s\n%d\n%d\n%d\n%d\n%d\n%d\n", delete1.name, delete1.roll, delete1.math, delete1.science, delete1.english, delete1.nepali, delete1.social);
        }
    }
    fclose(p);
    fclose(q);
    remove("student.txt");
    rename("q.txt", "student.txt");
    main();
}

void marksheet(int tu_roll)
{
char name[30], *division;
    int roll, sub[5], i, total = 0;

    FILE *search_file = fopen("student.txt", "r");
    while(fscanf(search_file,"%[^\n]\n%d\n%d\n%d\n%d\n%d\n%d\n",&name,&roll,&sub[0],&sub[1],&sub[2],&sub[3],&sub[4])!= EOF)
{
        if(roll == tu_roll){
            fclose(search_file);
            break;
        }
    }

    for(i=0; i<5; i++){
        total += sub[i];
    }

    float per = (((float)total / 500.0) * 100.0);

    for(i=0; i<5; i++){
        if (sub[i] < 40){
            division = "Fail";
            goto mcreate;
        }
    }

    if(per >= 80)
        division = "Distinction";
    else if(per >= 70)
        division = "FIRST";
    else if(per >= 60)
        division = "SECOND";
    else if(per >= 50)
        division = "THIRD";
    else if(per >= 40)
        division = "FOURTH";
    else
        division = "Fail";


    int sn = 1;
 /******************* MARKSHEET CREATION **************************************/
    mcreate:
    printf("\n");
    line();
    printf("\n\nST. XAVIER'S COLLEGE");
    printf("\n\nSECOND TERM EXAMINATION\n\n");
   
    boundary();
    printf("\n|\t\tName : %-81s|", name);
    printf("\n|\t\tRoll : %d\t\t\t\t\t\t\t\t\t\t|\n", roll);
   
    boundary();
    printf("\n|\tS.N\t|\t\t\tSubjects\t\t|\t\tMarks\t\t|\n");
    boundary();
    printf("\n|\t%d.\t|\t\t\tMathematics\t\t|\t%d\t\t|", sn, sub[0]);
    printf("\n|\t%d.\t|\t\t\tScience\t\t\t|\t%d\t\t|", (sn+1), sub[1]);
    printf("\n|\t%d.\t|\t\t\tEnglish\t\t\t|\t%d\t\t|", (sn+2), sub[2]);
    printf("\n|\t%d.\t|\t\t\tNepali\t\t\t|\t%d\t\t|", (sn+3), sub[3]);
    printf("\n|\t%d.\t|\t\t\tSocial\t\t\t|\t%d\t\t|\n", (sn+4), sub[4]);

    boundary();
    printf("\n|\t \t|\t\t\tPercentage\t\t|\t%.2f%%\t\t|", per);
    printf("\n|\t \t|\t\t\tDivision\t\t|\t%-11s\t\t|\n", division);
   
    boundary();
    printf("\n\nEND OF RESULT\n");
    main();
}
