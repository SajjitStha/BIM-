#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
struct student{
char name[30];
int roll,math,science,english,nepali,social;

};

void first(int);// function for record of one student
void second();// function for no of students record keeping
void third();// for listing the recorded students name and roll
void fourth();//for searching  students 
void edit21(int);//inside fourth 
void sdelete(int);//inside fourth
void marksheet(int);//inside fourth
void line();//taken from stackoverflow
void boundary();//taken from stackoverflow

int main()
{
int a;
redo:
printf("\n");
    line();
printf("1.Add a record\n2.Add Bulk Records\n3.List Students\n4.Search Students\n5.Quit\n");
printf("What is you choice? :");
scanf("%d%*c",&a);
switch(a)
{
case 1:
printf("\n");
    line();
first(1);
break;
case 2:
printf("\n");
    line();
second();
break;
case 3:
printf("\n");
third();
break;
case 4:
fourth();
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

void first(int n)
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
void second()
{
int bulk;
printf("\nHow many Students? ");
scanf("%d%*c",&bulk);
first(bulk);

}
void third()
{
struct student third;
int i;
FILE *p;
line();
p=fopen("student.txt","r");
printf("Roll\tName\n");
while(fscanf(p,"%[^\n]\n%d\n%d\n%d\n%d\n%d\n%d\n",&third.name,&third.roll,&third.math,&third.science,&third.english,&third.nepali,&third.social)!=EOF)
{
printf("%d      %s\n",third.roll,third.name);
}
fclose(p);
main();

}
void fourth()
{

int count,roll;
printf("\n");
line();
printf("Enter Roll No:");
scanf("%d",&roll);

struct student search;
FILE *p;
p=fopen("student.txt","r");
while(fscanf(p,"%[^\n]\n%d\n%d\n%d\n%d\n%d\n%d\n",&search.name, &search.roll, &search.math, &search.science, &search.english, &search.nepali, &search.social)!=EOF)
{
if(search.roll==roll)
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
int choose123;
printf("\n");
line();
printf("Record Found :\n");
printf("Student Name :%s\n",search.name);
line();
printf("1.Edit Record\n2.Delete Record\n3.View Marksheet\n4.Quit\n");
printf("What is you choice? :");
scanf("%d%*c",&choose123);
switch(choose123)
{
case 1:
edit21(search.roll);
break;

case 2:
sdelete(search.roll);
break;

case 3:
marksheet(search.roll);
break;

case 4:
exit(3);

default:
printf("Bye Bye!!");

}
}

void edit21(int tt_roll)
{
struct student edit, edit1;
    FILE *p = fopen("student.txt", "r");
    FILE *new = fopen("new.txt", "a");
    int edit_choose, x, continue_edit, per_roll;

    while(fscanf(p, "%[^\n]\n%d\n%d\n%d\n%d\n%d\n%d\n", &edit.name, &edit.roll, &edit.math, &edit.science, &edit.english, &edit.nepali, &edit.social) != EOF){
        if(edit.roll == tt_roll){
            per_roll = edit.roll;
            break;
        }
    }
    rewind(p);
    printf("\n");
    line();
    printf("\nHello %s!\nYour Current Information is:\n\n", edit.name);
    printf("Name: %s\nRoll No: %d\nMarks in Mathematics: %d\nMarks in Science: %d\nMarks in English: %d\nMarks in Nepali: %d\nMarks in Social: %d", edit.name, edit.roll, edit.math, edit.science, edit.english, edit.nepali, edit.social);
    printf("\n\nWhich Information Do You Want to Edit? Choose From The Following:");
    printf("\n[1] Name\n[2] Roll No.\n[3] Marks in Mathematics\n[4] Marks in Science\n[5] Marks in English\n[6] Marks in Nepali\n[7] Marks in Social\nPress Any Other Key To Go Back");
    printf("\n\nChoose: ");
    scanf("%d", &edit_choose);
    fflush(stdin);

    switch(edit_choose){
        case 1:
        printf("Enter New Name: ");
        gets(edit.name);
        fflush(stdin);
        break;

        case 2:
        re_roll_edit:
        printf("Enter New Roll No: ");
        scanf("%d", &edit.roll);
        fflush(stdin);
        x = rollcheck(edit.roll);
        if(x!=0){
            printf("Taken Already");
            goto re_roll_edit;
        }
        break;

        case 3:
        edit_math:
        printf("Enter New Marks in Mathematics: ");
        scanf("%d", &edit.math);
        fflush(stdin);
        if(edit.math > 100){
            printf("Error! Full Marks is 100\n");
            goto edit_math;
        }
        break;

        case 4:
        edit_science:
        printf("Enter New Marks in Science: ");
        scanf("%d", &edit.science);
        fflush(stdin);
        if(edit.science > 100){
            printf("Error! Full Marks is 100\n");
            goto edit_science;
        }
        break;

        case 5:
        edit_english:
        printf("Enter New Marks in English: ");
        scanf("%d", &edit.english);
        fflush(stdin);
        if(edit.english > 100){
            printf("Error! Full Marks is 100\n");
            goto edit_english;
        }
        break;

        case 6:
        edit_nepali:
        printf("Enter New Marks in Nepali: ");
        scanf("%d", &edit.nepali);
        fflush(stdin);
        if(edit.nepali > 100){
            printf("Error! Full Marks is 100\n");
            goto edit_nepali;
        }
        break;

        case 7:
        edit_social:
        printf("Enter New Marks in Social: ");
        scanf("%d", &edit.social);
        fflush(stdin);
        if(edit.social > 100){
            printf("Error! Full Marks is 100\n");
            goto edit_social;
        }
        break;
       
        default:
        remove("new.txt");
        main();
    }
   
    while(fscanf(p, "%[^\n]\n%d\n%d\n%d\n%d\n%d\n%d\n", &edit1.name, &edit1.roll, &edit1.math, &edit1.science, &edit1.english, &edit1.nepali, &edit1.social) != EOF){
        if(edit1.roll != per_roll){
            fprintf(new, "%s\n%d\n%d\n%d\n%d\n%d\n%d\n", edit1.name, edit1.roll, edit1.math, edit1.science, edit1.english, edit1.nepali, edit1.social);
        }
        else{
            fprintf(new, "%s\n%d\n%d\n%d\n%d\n%d\n%d\n", edit.name, edit.roll, edit.math, edit.science, edit.english, edit.nepali, edit.social);
        }
    }
    fclose(p);
    fclose(new);
    remove("student.txt");
    rename("new.txt","student.txt");

    re_choice_dn:
    printf("Edit Another Info?\n[1] Yes\n[2] No");
    printf("\nChoose : ");
    scanf("%d", &continue_edit);
    fflush(stdin);
    if(continue_edit == 1){
        edit21(edit.roll);
    }
    else if(continue_edit == 2){
        main();
    }
    else{
        printf("\nValue Out of Bounds!!");
        goto re_choice_dn;
    }
}

void sdelete(int ty_roll)
{
struct student delete1;
    FILE *p = fopen("student.txt", "r");
    FILE *new = fopen("new.txt", "w");

    while(fscanf(p, "%[^\n]\n%d\n%d\n%d\n%d\n%d\n%d\n", &delete1.name, &delete1.roll, &delete1.math, &delete1.science, &delete1.english, &delete1.nepali, &delete1.social) != EOF){
        if(delete1.roll != ty_roll){
            fprintf(new, "%s\n%d\n%d\n%d\n%d\n%d\n%d\n", delete1.name, delete1.roll, delete1.math, delete1.science, delete1.english, delete1.nepali, delete1.social);
        }
    }
    fclose(p);
    fclose(new);
    remove("student.txt");
    rename("new.txt", "student.txt");
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
