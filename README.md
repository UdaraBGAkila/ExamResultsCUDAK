# ExamResultsManagementCUDAK
Sri Lanka GCE Advanced Level results management system build with C language. Include z-score calculations and charts and graphs.

## Introduction

This is a simple menu driven console application developed in C using Code Blocks. This
application let the user to enter advanced level marks of math stream students’ (up to 100) and save
them in a text file. This process their grades, z scores and some other calculations and show them in
graphs and charts. The functionality is discussed in details below.

## Functionality

### Menus

There are 3 menus in this program. One is main menu and other 2 are sub menus for reports (charts)
and graphs. The user can navigate from main menu to sub menus and vice versa. How they look
like is given below. The user inputs for this are taken as numbers.

![image](https://user-images.githubusercontent.com/22652266/235841489-30970be4-8a1a-4e32-aeb8-5a5de72fb0ae.png)
![image](https://user-images.githubusercontent.com/22652266/235841514-679ed2ac-3b41-4009-86ba-a9e7b837e24b.png)
![image](https://user-images.githubusercontent.com/22652266/235841531-9aeb14f7-2a8f-4e5d-9682-7b27468204af.png)

### Adding Student Information

This is done with main menu option 1. Then user have to specify how many students are they going
to add. If it exceeds total of 100 (with previous records), system will not let user to add new records.
User then have to add each students’ index numbers with there marks separately.

![image](https://user-images.githubusercontent.com/22652266/235841705-1a41f34d-7c8c-4ced-8613-23d9271b72cf.png)

### Save and Load Records

Saving of entered records is done with menu option 2. This will save Records in a text file.

![image](https://user-images.githubusercontent.com/22652266/235841907-118ac915-df61-4c8a-a808-b250a5d66838.png)

Loading records is done with menu option 3. This load all records with previously saved records as
a chart.

![image](https://user-images.githubusercontent.com/22652266/235841966-1008f36d-b656-43fb-aed9-9f441a44afab.png)

### Search and Edit Records

This is done with menu option 4 of the main menu. For this user have to provide index number. At
the result, his/her marks will be displayed. If incorrect index number entered, error will be
displayed. With this user can edit the searched record data if he/she wants to as below.

![image](https://user-images.githubusercontent.com/22652266/235842076-dd3befdd-c408-4fdb-ac6e-5f53bc75fc0c.png)

### Reports

There are 2 reports produced by this application. The selection of them done by going to sub menu
for reports via option 5 of main menu.
The first report is result sheet. It is accessed via report sub menu option 1. It displays grades and z
scores of all the students.

The second report is a subject summary. This gives each subjects’ counts of grades and their means
(M) and standard deviations (D).

![image](https://user-images.githubusercontent.com/22652266/235842206-78c94cb0-6165-4b23-b58e-b1fa3db9bd8f.png)

### Graphs

There are 2 graphs produced by this application. The selection of them done by going to sub menu
for graphs via option 6 of main menu.
The first graph is the grade analysis. It is accessed via graph sub menu option 1. It displays amount
of grades for each subject.

![image](https://user-images.githubusercontent.com/22652266/235842325-571095dd-dcc1-4407-b050-53f1c754ac72.png)


The second graph is the subject analysis. It is accessed via graph sub menu option 2. It displays
amount mean and standard deviation for each subject.

![image](https://user-images.githubusercontent.com/22652266/235842358-6b143c7e-4d99-4d46-84ba-3e355d7f2274.png)

## Summary

With this application, most of the requirements given for the system are fulfilled. The
requirement to delete records was not implemented and hopes to implement in the future.







