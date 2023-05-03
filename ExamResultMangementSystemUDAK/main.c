#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//structures declarations
struct Students
{
    int indNo;
    double mathMark;
    double phyMark;
    double chemMark;
};

struct ZScores
{
    int indNo;
    char mathGrade;
    char phyGrade;
    char chemGrade;
    double zScore;
};

struct ZCounts
{
    char grade;
    int math;
    int phy;
    int chem;
};

struct ZSummaries
{
    char type;
    double math;
    double phy;
    double chem;
};

//global variable declarations
struct Students arrStudent[100];
struct ZScores arrZScore[100];
struct ZCounts arrZCount[5];
struct ZSummaries arrZSummary[2];
int ng = 0;
int nl = 0;
double mM,mP,mC,stdM,stdP,stdC;

//method declarations
int mainMenu();
void printReports();
void printGraphs();
void addStudent();
void saveRecords();
void loadRecords();
void searchRecords();
void resultChart();
void summaryChart();
void gradeGraph();
void subjectGraph();

void getSaveData();

void getResult(struct Students arrStudent[100]);

double calMean(double x[],int n);
double mathMean(struct Students arrStudent[100],int n);
double phyMean(struct Students arrStudent[100],int n);
double chemMean(struct Students arrStudent[100],int n);

double calStDev(double x[],int n,double u);
double mathStDev(struct Students arrStudent[100],int n,double u);
double phyStDev(struct Students arrStudent[100],int n,double u);
double chemStDev(struct Students arrStudent[100],int n,double u);

double calZSub(double x,double u,double std);
double calZTot(double x,double u,double std);

void getCount(struct Students arrStudent[100],struct ZCounts arrZCount[5]);
void getCalculations(struct Students arrStudent[100],struct ZSummaries arrZSummary[2]);

int countGrade(char arr[], char c);

char gradeCheck(double mark);

int main()
{
    int r;

    getSaveData();

    r=mainMenu();

    return r;
}

//Displays main menu
int mainMenu()
{
    int n;
    printf(" =================================\n");
    printf(" |                               |\n");
    printf(" |           Main Menu           |\n");
    printf(" |  ===========================  |\n");
    printf(" |                               |\n");
    printf(" |  [1] Add student              |\n");
    printf(" |  [2] Save records             |\n");
    printf(" |  [3] Load records             |\n");
    printf(" |  [4] Search records           |\n");
    printf(" |  [5] Print Reports            |\n");
    printf(" |  [6] Print Graphs             |\n");
    printf(" |  [7] Exit                     |\n");
    printf(" |                               |\n");
    printf(" =================================\n\n");
    printf("    Enter your choice [1-7]: ");
    scanf("%d",&n);

    switch(n)
    {
    case 1:
        addStudent();
        break;
    case 2:
        saveRecords();
        break;
    case 3:
        loadRecords();
        break;
    case 4:
        searchRecords();
        break;
    case 5:
        printReports();
        break;
    case 6:
        printGraphs();
        break;
    case 7:
        //system("taskkill/IM cb_console_runner.exe");
         return 0;
    default:
        printf("Incorrect Entry");
        break;
    }
 return 0;
}

//displays report sub menu
void printReports()
{
    int n;
    printf(" =================================\n");
    printf(" |                               |\n");
    printf(" |        Report Sub Menu        |\n");
    printf(" |  ===========================  |\n");
    printf(" |                               |\n");
    printf(" |  [1] Print Result Sheet       |\n");
    printf(" |  [2] Print Subject Summary    |\n");
    printf(" |  [3] Back To Main Menu        |\n");
    printf(" |                               |\n");
    printf(" =================================\n\n");
    printf("    Enter your choice [1-3]: ");
    scanf("%d",&n);

    switch(n)
    {
    case 1:
        resultChart();
        break;
    case 2:
        summaryChart();
        break;
    case 3:
        mainMenu();
        break;
    default:
        printf("Incorrect Entry");
        break;
    }

}

//displays graph sub menu
void printGraphs()
{
    int n;
    printf(" =================================\n");
    printf(" |                               |\n");
    printf(" |        Graph Sub Menu         |\n");
    printf(" |  ===========================  |\n");
    printf(" |                               |\n");
    printf(" |  [1] Grade Analysis           |\n");
    printf(" |  [2] Subject Analysis         |\n");
    printf(" |  [3] Back To Main Menu        |\n");
    printf(" |                               |\n");
    printf(" =================================\n\n");
    printf("    Enter your choice [1-3]: ");
    scanf("%d",&n);

    //printf("Choice is %d",n);
    switch(n)
    {
    case 1:
        gradeGraph();
        break;
    case 2:
        subjectGraph();
        break;
    case 3:
        mainMenu();
        break;
    default:
        printf("Incorrect Entry");
        break;
    }

}

//calculate mean
double calMean(double x[],int n)
{
    int i;
    double u,t=0;

    for(i=0;i<n;i++)
    {
        t = t+x[i];
    }

    u = t/n;

    return u;
}

//get mean for math
double mathMean(struct Students arrStudent[100],int n)
{
    int i;
    double m[100],mu;

    for(i=0;i<n;i++)
    {
       m[i] = arrStudent[i].mathMark;
    }

    mu = calMean(m,n);
    return mu;
}

//get mean for math physics
double phyMean(struct Students arrStudent[100],int n)
{
    int i;
    double p[100],pu;

    for(i=0;i<n;i++)
    {
       p[i] = arrStudent[i].phyMark;
    }

    pu = calMean(p,n);
    return pu;
}

//get mean for math chemistry
double chemMean(struct Students arrStudent[100],int n)
{
    int i;
    double c[100],cu;

    for(i=0;i<n;i++)
    {
       c[i] = arrStudent[i].chemMark;
    }

    cu = calMean(c,n);
    return cu;
}

//calculate standard deviation
double calStDev(double x[],int n,double u)
{
    int i;
    double std,d=0;

    for(i=0;i<n;i++)
    {
        d = d+((x[i]-u)*(x[i]-u));
    }

    std = sqrt(d/n);

    return std;
}

//get standard deviation for math
double mathStDev(struct Students arrStudent[100],int n,double u)
{
    int i;
    double m[100],mstd;

    for(i=0;i<n;i++)
    {
       m[i] = arrStudent[i].mathMark;
    }

    mstd = calStDev(m,n,u);
    return mstd;
}

//get standard deviation for physics
double phyStDev(struct Students arrStudent[100],int n,double u)
{
    int i;
    double p[100],pstd;

    for(i=0;i<n;i++)
    {
       p[i] = arrStudent[i].phyMark;
    }

    pstd = calStDev(p,n,u);
    return pstd;
}

//get standard deviation for chemistry
double chemStDev(struct Students arrStudent[100],int n,double u)
{
    int i;
    double c[100],cstd;

    for(i=0;i<n;i++)
    {
       c[i] = arrStudent[i].chemMark;
    }

    cstd = calStDev(c,n,u);
    return cstd;
}

//Calculate a subject's z score for student
double calZSub(double x,double u,double std)
{
    double zSub;
    zSub = (x-u)/std;
    return zSub;
}

//Calculate a total  z score for student
double calZTot(double math,double phy,double che)
{
    double zTot;
    zTot = (math+phy+che)/3;
    return zTot;
}

//count a given grade
int countGrade(char arr[], char c)
{
    int i,count=0;

    for(i=0;i<ng;i++)
    {
       if(arr[i]==c)
       {
           count++;
       }
    }

    return count;
}

//set grades according to marks
char gradeCheck(double mark)
{
    if(mark<35)
    {
        return 'F';
    }
    else if(mark<50)
    {
        return 'S';
    }
    else if(mark<65)
    {
        return 'C';
    }
    else if(mark<75)
    {
        return 'B';
    }
    else
    {
        return 'A';
    }
}

//adds students
void addStudent()
{

    int i,n,indNo;
    double mathMark,phyMark,chemMark;
    //char c;
    printf("\nEnter number of Students: \n");
    scanf("%d",&n);

    nl = n;

    if((ng+n)>100)
    {
        printf("Maximum number of students reached.\n");
    }
    else
    {
        for(i=ng;i<ng+n;i++)
        {
            printf("\nEnter Student Details\n\n");

            printf("Enter Index No: ");
            scanf("%d",&indNo);
            //scanf("%d",&arrStudent[i].indNo);

            printf("Enter Math Mark: ");
            scanf("%lf",&mathMark);
            //scanf("%lf",&arrStudent[i].mathMark);

            printf("Enter Physics Mark: ");
            scanf("%lf",&phyMark);
            //scanf("%lf",&arrStudent[i].phyMark);

            printf("Enter Chemistry Mark: ");
            scanf("%lf",&chemMark);
            //scanf("%lf",&arrStudent[i].chemMark);

            if((indNo>99999&&indNo<1000000)&&(mathMark>=0&&mathMark<=100)&&(phyMark>=0&&phyMark<=100)&&(chemMark>=0&&chemMark<=100))
            {
                arrStudent[i].indNo = indNo;
                arrStudent[i].mathMark = mathMark;
                arrStudent[i].phyMark = phyMark;
                arrStudent[i].chemMark = chemMark;
            }
            else
            {
                printf("\n Incorrect Data Entered. Please try again. \n");
                i--;
            }
        }

        ng = ng+n;

        /*printf("\n");

        printf("index no\tMath\tPhysics\tChemistry\n");

        for(i=0;i<n;i++)
        {
            printf("%d\t\t%.1f\t%.1f\t%.1f\n",arrStudent[i].indNo,arrStudent[i].mathMark,arrStudent[i].phyMark,arrStudent[i].chemMark);
        }*/
        }

    mainMenu();

}

//save all records
void saveRecords()
{
    int i,f;

    //FILE *outfile;
    FILE *fp;

        // open file for writing
        //outfile = fopen ("student.txt", "wb");
        fp = fopen ("student.txt", "w");
        /*if (outfile == NULL)
        {
            fprintf(stderr, "\nError opening file\n");
            exit (1);
        }*/

        if (fp == NULL)
        {
            fprintf(stderr, "\nError opening file\n");
            exit (1);
        }

        fprintf(fp,"%d\n",ng);

        // write struct to file
        for(i=0;i<ng;i++)
        {
          f = fprintf(fp,"%d\t%lf\t%lf\t%lf\n",arrStudent[i].indNo,arrStudent[i].mathMark,arrStudent[i].phyMark,arrStudent[i].chemMark);
        }
        //fwrite (&arrStudent, sizeof(struct Students), 1, outfile);


        if(f > 0)
        {
            printf("contents to file written successfully !\n");

        }

        else
        {
            printf("error writing file !\n");
        }


        // close file
        //2fclose (outfile);
        fclose (fp);
        mainMenu();
}

//load all records
void loadRecords()
{

    int i;
    printf("\n Show All Records\n");
    printf("Index no\tMath\tPhysics\tChemistry\n");

    for(i=0;i<ng;i++)
    {
        printf("%d\t\t%.1f\t%.1f\t%.1f\n",arrStudent[i].indNo,arrStudent[i].mathMark,arrStudent[i].phyMark,arrStudent[i].chemMark);
    }


    mainMenu();

}

//find a record by index number
void searchRecords()
{
    int i,r,x=0;
    char an;
    double mathMark,phyMark,chemMark;

    printf("\nEnter the index number :\n");
    scanf("%d",&r);

    for(i=0;i<ng;i++)
    {
        if(arrStudent[i].indNo==r)
        {
            printf("Math marks : %.1lf\n",arrStudent[i].mathMark);
            printf("Physics marks : %.1lf\n",arrStudent[i].phyMark);
            printf("Chemistry marks : %.1lf\n",arrStudent[i].chemMark);
            x=1;
            break;
        }
    }


    if(x!=1)
    {
        printf("No record for the given index number.\n");
        mainMenu();
    }
    else
    {
        printf("Do you want to change the record?(y-n)\n");
        scanf(" %c",&an);
        if(an=='y')
        {
            printf("Enter math mark : \n");
            scanf("%lf",&mathMark);
            printf("Enter physics mark : \n");
            scanf("%lf",&phyMark);
            printf("Enter chemistry mark : \n");
            scanf("%lf",&chemMark);

            if((mathMark>=0&&mathMark<=100)&&(phyMark>=0&&phyMark<=100)&&(chemMark>=0&&chemMark<=100))
            {
                arrStudent[i].mathMark = mathMark;
                arrStudent[i].phyMark = phyMark;
                arrStudent[i].chemMark = chemMark;

                printf("Values are edited\n");
            }
            else
            {
                printf("\n Incorrect Data Entered.\n");
            }
        }

        mainMenu();

    }

}

//get saved records and global variable ng's value
void getSaveData()
{
    int i;

    FILE *infile;

    // Open person.dat for reading
    infile = fopen ("student.txt", "r");
    if (infile == NULL)
    {
        infile = fopen ("student.txt", "w");
        fclose (infile);
        infile = fopen ("student.txt", "r");
    }

    // read file contents till end of file

    fscanf(infile, "%d\n", &ng);

    for(i=0;i<ng;i++)
        {
           fscanf(infile,"%d%lf%lf%lf\n",&arrStudent[i].indNo,&arrStudent[i].mathMark,&arrStudent[i].phyMark,&arrStudent[i].chemMark);
        }

    // close file
    fclose (infile);

}

//get values for arrZScore array
void getResult(struct Students arrStudent[100])
{
    int i;
    char m,p,c;
    double zM,zP,zC,zT;


    if(ng!=0)
    {
        mM = mathMean(arrStudent, ng);
        mP = phyMean(arrStudent, ng);
        mC = chemMean(arrStudent, ng);

        stdM = mathStDev(arrStudent, ng, mM);
        stdP = phyStDev(arrStudent, ng, mP);
        stdC = chemStDev(arrStudent, ng, mC);

        for(i=0;i<ng;i++)
        {
            m = gradeCheck(arrStudent[i].mathMark);
            p = gradeCheck(arrStudent[i].phyMark);
            c = gradeCheck(arrStudent[i].chemMark);


            zM = calZSub(arrStudent[i].mathMark, mM, stdM);
            zP = calZSub(arrStudent[i].phyMark, mP, stdP);
            zC = calZSub(arrStudent[i].chemMark, mC, stdC);
            zT = calZTot(zM,zP,zC);

            arrZScore[i].indNo = arrStudent[i].indNo;
            arrZScore[i].mathGrade = m;
            arrZScore[i].phyGrade = p;
            arrZScore[i].chemGrade = c;
            arrZScore[i].zScore = zT;
        }
    }
    else
    {
        printf("No Records");
    }
}

//display result chart
void resultChart()
{
    int i;

    getResult(arrStudent);
    printf("\n Advanced Level Result\n");
    printf("Index no\tMath\tPhysics\tChemistry\tZScore\n");

    for(i=0; i<ng; i++)
    {
        printf("%d\t\t%c\t%c\t%c\t\t%lf\n",arrZScore[i].indNo,arrZScore[i].mathGrade,arrZScore[i].phyGrade,arrZScore[i].chemGrade,arrZScore[i].zScore);
    }

    mainMenu();
}

//get values for arrZCount array
void getCount(struct Students arrStudent[100],struct ZCounts arrZCount[5])
{
    int i;
    char arrM[100], arrP[100], arrC[100];

    getResult(arrStudent);

     for(i=0;i<ng;i++)
    {
        arrM[i] = arrZScore[i].mathGrade;
        arrP[i] = arrZScore[i].phyGrade;
        arrC[i] = arrZScore[i].chemGrade;
    }

    arrZCount[0].grade = 'A';
    arrZCount[0].math = countGrade(arrM,'A');
    arrZCount[0].phy = countGrade(arrP,'A');
    arrZCount[0].chem = countGrade(arrC,'A');

    arrZCount[1].grade = 'B';
    arrZCount[1].math = countGrade(arrM,'B');
    arrZCount[1].phy = countGrade(arrP,'B');
    arrZCount[1].chem = countGrade(arrC,'B');

    arrZCount[2].grade = 'C';
    arrZCount[2].math = countGrade(arrM,'C');
    arrZCount[2].phy = countGrade(arrP,'C');
    arrZCount[2].chem = countGrade(arrC,'C');

    arrZCount[3].grade = 'S';
    arrZCount[3].math = countGrade(arrM,'S');
    arrZCount[3].phy = countGrade(arrP,'S');
    arrZCount[3].chem = countGrade(arrC,'S');

    arrZCount[4].grade = 'F';
    arrZCount[4].math = countGrade(arrM,'F');
    arrZCount[4].phy = countGrade(arrP,'F');
    arrZCount[4].chem = countGrade(arrC,'F');
}

//get values for arrZSummary array
void getCalculations(struct Students arrStudent[100],struct ZSummaries arrZSummary[2])
{
    getResult(arrStudent);

    arrZSummary[0].type = 'M';
    arrZSummary[0].math = mM;
    arrZSummary[0].phy  = mP;
    arrZSummary[0].chem = mC;

    arrZSummary[1].type = 'D';
    arrZSummary[1].math = stdM;
    arrZSummary[1].phy  = stdP;
    arrZSummary[1].chem = stdC;

}

//display subject summary
void summaryChart()
{
    int i,j;

    getCount(arrStudent,arrZCount);
    getCalculations(arrStudent,arrZSummary);
    printf("\n Advanced Level Result - Summary\n");
    printf("Grade\t\tMath\tPhysics\tChemistry\n");

    for(i=0; i<5; i++)
    {
        printf("%c\t\t%d\t%d\t%d\n",arrZCount[i].grade,arrZCount[i].math,arrZCount[i].phy,arrZCount[i].chem);
    }

    for(j=0; j<2; j++)
    {
        printf("%c\t\t%.2lf\t%.2lf\t%.2lf\n",arrZSummary[j].type,arrZSummary[j].math,arrZSummary[j].phy,arrZSummary[j].chem);
    }

    mainMenu();
}

//display Grade Analysis
void gradeGraph()
{
    int i;

    getCount(arrStudent,arrZCount);

    printf("\n            Grade Analysis              ");
    printf("\n  ====================================  ");
    printf("\n  Math - %c  Physics - %c  Chemistry - %c  \n",176,177,178);

    printf("\n A |");

    for(i=0; i<arrZCount[0].math && arrZCount[0].math!=0 ; i++)
    {
        printf("%c",176);
    }

    printf("\n   |");

    for(i=0; i<arrZCount[0].phy && arrZCount[0].phy!=0; i++)
    {
        printf("%c",177);
    }

    printf("\n   |");

    for(i=0; i<arrZCount[0].chem && arrZCount[0].chem!=0; i++)
    {
        printf("%c",178);
    }

    printf("\n   |");


    printf("\n B |");

    for(i=0; i<arrZCount[1].math && arrZCount[1].math!=0; i++)
    {
        printf("%c",176);
    }

    printf("\n   |");

    for(i=0; i<arrZCount[1].phy && arrZCount[1].phy!=0; i++)
    {
        printf("%c",177);
    }

    printf("\n   |");

    for(i=0; i<arrZCount[1].chem && arrZCount[1].chem!=0; i++)
    {
        printf("%c",178);
    }

    printf("\n   |");


    printf("\n C |");

    for(i=0; i<arrZCount[2].math && arrZCount[2].math!=0; i++)
    {
        printf("%c",176);
    }

    printf("\n   |");

    for(i=0; i<arrZCount[2].phy && arrZCount[2].phy!=0; i++)
    {
        printf("%c",177);
    }

    printf("\n   |");

    for(i=0; i<arrZCount[2].chem && arrZCount[2].chem!=0; i++)
    {
        printf("%c",178);
    }

    printf("\n   |");


    printf("\n S |");

    for(i=0; i<arrZCount[3].math && arrZCount[3].math!=0; i++)
    {
        printf("%c",176);
    }

    printf("\n   |");

    for(i=0; i<arrZCount[3].phy && arrZCount[3].phy!=0; i++)
    {
        printf("%c",177);
    }

    printf("\n   |");

    for(i=0; i<arrZCount[3].chem && arrZCount[3].chem!=0; i++)
    {
        printf("%c",178);
    }

    printf("\n   |");


    printf("\n F |");

    for(i=0; i<arrZCount[4].math && arrZCount[4].math!=0; i++)
    {
        printf("%c",176);
    }

    printf("\n   |");

    for(i=0; i<arrZCount[4].phy && arrZCount[4].phy!=0; i++)
    {
        printf("%c",177);
    }

    printf("\n   |");

    for(i=0; i<arrZCount[4].chem && arrZCount[4].chem!=0; i++)
    {
        printf("%c",178);
    }

    printf("\n   |");

    printf("\n   |_____________________________________________\n");


    mainMenu();
}

//display Subject Analysis
void subjectGraph()
{
    int i;

    getCalculations(arrStudent,arrZSummary);

    int meanMath = arrZSummary[0].math;
    int meanPhy = arrZSummary[0].phy;
    int meanChem = arrZSummary[0].chem;

    int dMath = arrZSummary[1].math;
    int dPhy = arrZSummary[1].phy;
    int dChem = arrZSummary[1].chem;



    printf("\n            Subject Analysis            ");
    printf("\n  ====================================  ");
    printf("\n  Mean - %c    Standard Deviation - %c    \n",176,178);

    printf("\n Math                |");

    for(i=0; i<meanMath && meanMath!=0 ; i++)
    {
        printf("%c",176);
    }
    printf("\n                     |");
    for(i=0; i<dMath && dMath!=0; i++)
    {
        printf("%c",178);
    }

    printf("\n                     |");

    printf("\n Physics             |");

    for(i=0; i<meanPhy && meanPhy!=0; i++)
    {
        printf("%c",176);
    }
    printf("\n                     |");
    for(i=0; i<dPhy && dPhy!=0; i++)
    {
        printf("%c",178);
    }

    printf("\n                     |");

    printf("\n Chemistry           |");

    for(i=0; i<meanChem && meanChem!=0; i++)
    {
        printf("%c",176);
    }
    printf("\n                     |");
    for(i=0; i<dChem && dChem!=0; i++)
    {
        printf("%c",178);
    }

    printf("\n                     |");

    printf("\n                     |____________________________________________________________\n");


    mainMenu();
}


