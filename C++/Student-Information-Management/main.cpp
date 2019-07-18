#include <bits/stdc++.h>
using namespace std;

struct student{
    char name[100], dept[100], session[100];
    int roll, mark[5], numOfSubject;
    char subjectName[100][100];
}input;

class Project{
    int choice, total_marks = 0, roll;
public:
    void home();
    void student_login();
    void teacher_login();
    void logout();
    void addnew();
    void modify();
    void show();
    float getcgpa(int *arr, int n);
};
void Project::home(){
    cout << "***** LOGIN PAGE *****" << endl << endl;
    cout << "1. Student Login" << endl << "2. Teacher Login" << endl << "3. Exit" << endl;
    cout << "Choose an option: ";
    cin >> choice;
    switch(choice){
        case 1: {
            cin.ignore();
            student_login();
            break;
        }
        case 2: {
            cin.ignore();
            teacher_login();
            break;
        }
        case 3: exit(1);
        default: {
            system("CLS");
            cout << "Please choose a valid option " << endl;
            home();
            break;
        }
    }
}
void Project::student_login(){
    system("CLS");
    cout << "***** STUDENT LOGIN PAGE *****" << endl << endl;
    cout << "Enter your roll no: ";
    cin >> roll;
    FILE *infile;
    infile = fopen ("data.txt", "rb");
    while(fread(&input, sizeof(input), 1, infile)){
        if(input.roll == roll){
            system("CLS");
            cout << "Name: " << input.name << endl;
            cout << "Department: " << input.dept << endl;
            cout << "Session: " << input.session << endl;
            cout << "Roll: " << input.roll << endl;
            cout << "Marks: " << endl;
            total_marks = 0;
            for(int i = 0; i < input.numOfSubject; i++){
                cout << input.subjectName[i] << "\t: " << input.mark[i] << endl;
                total_marks += input.mark[i];
            }
            cout << endl;
            cout << "Percentage: " << total_marks * 1.0 / input.numOfSubject << "%" << endl;
            cout << "CGPA: " << getcgpa(input.mark, input.numOfSubject) << endl << endl;
        }
    }

    cout << "Press any key to return home ";
    cin.ignore();
    cin.ignore();
    logout();
}
void Project::teacher_login(){
    system("CLS");
    cout << "***** TEACHER LOGIN PAGE *****" << endl << endl;
    cout << "1. Add New" << endl << "2. Modify Existing Data" << endl << "3. Return Home" << endl;
    cout << "Choose an option: ";
    cin >> choice;
    cin.ignore();
    switch(choice){
        case 1: addnew(); break;
        case 2: modify(); break;
        case 3: logout(); break;
        default : {
            teacher_login();
            break;
        }
    }
}
void Project::addnew(){
    system("CLS");
    printf("Enter student name: ");
    scanf("%[^\n]s",input.name);
    fflush(stdin);
    printf("Enter student dept: ");
    scanf("%[^\n]s", input.dept);
    fflush(stdin);
    printf("Enter student session: ");
    scanf("%[^\n]s", input.session);
    fflush(stdin);
    printf("Enter student roll: ");
    cin >> input.roll;
    fflush(stdin);
    printf("Enter number of Subjects: ");
    cin >> input.numOfSubject;
    printf("Enter %d Subject Title\n", input.numOfSubject);
    cin.ignore();
    for(int i = 0; i < input.numOfSubject; i++){
        cout << i + 1 << ": ";
        scanf("%[^\n]s", input.subjectName[i]);
        fflush(stdin);
    }
    printf("Enter %d Subject Marks\n", input.numOfSubject);
    for(int i = 0; i < input.numOfSubject; i++){
        cout << input.subjectName[i] << "\t: ";
        cin >> input.mark[i];
    }
    FILE *outfile;
    outfile = fopen("data.txt", "ab");
    fwrite (&input, sizeof(student), 1, outfile);
    fclose (outfile);
    cin.ignore();
    cout << "Data successfully stored." << endl;
    cout << "Press any key to continue.." << endl;
    cin.ignore();
    teacher_login();
}
void Project::modify(){
    system("CLS");
    int r;
    FILE *infile;
    FILE *outfile;
    infile = fopen("data.txt", "rb");
    outfile = fopen("temp.txt", "wb");
    cout << "Enter student roll: ";
    cin >> r;
    while(fread(&input, sizeof(input), 1, infile)){
        if(input.roll == r){
            struct student temp;
            strcpy(temp.name, input.name);
            strcpy(temp.dept, input.dept);
            temp.roll = input.roll;
            strcpy(temp.session, input.session);
            temp.numOfSubject = input.numOfSubject;
            for(int i = 0; i < input.numOfSubject; i++){
                strcpy(temp.subjectName[i], input.subjectName[i]);
            }
            printf("Enter updated Marks\n");
            int x;
            for(int i = 0; i < input.numOfSubject; i++){
                cout << temp.subjectName[i] << "\t: ";
                cin >> temp.mark[i];
            }
            fwrite(&temp, sizeof(input), 1, outfile);
        }
        else fwrite(&input, sizeof(input), 1, outfile);
    }
    fclose(infile); fclose(outfile);
    ofstream ofs;
    ofs.open("data.txt", ofstream::out | ofstream::trunc);
    ofs.close();
    outfile = fopen("data.txt", "wb");
    infile = fopen("temp.txt", "rb");

    while(fread(&input, sizeof(student), 1, infile)){
        fwrite(&input, sizeof(student), 1, outfile);
    }
    fclose(outfile);
    fclose(infile);
    cout << endl;
    cout << "Press any key to continue.." << endl;
    cin.ignore();
    teacher_login();
}
float Project::getcgpa(int *arr, int n){
    float cg = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] >= 80) cg += 4;
        else if(arr[i] >=75 && arr[i] <= 79) cg += 3.75;
        else if(arr[i] >= 70 && arr[i] <= 74) cg += 3.50;
        else if(arr[i] >= 65 && arr[i] <= 69) cg += 3.25;
        else if(arr[i] >= 60 && arr[i] <= 64) cg += 3;
        else if(arr[i] >= 55 && arr[i] <= 59) cg += 2.75;
        else if(arr[i] >= 50 && arr[i] <= 54) cg += 2.50;
        else if(arr[i] >= 45 && arr[i] <= 49) cg += 2.25;
        else if(arr[i] >= 40 && arr[i] <= 44) cg += 2;
    }
    return cg / n;
}
void Project::logout(){
    system("CLS");
    home();
}

int main(){
    Project object;
    object.home();
    return 0;
}
