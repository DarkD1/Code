#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Project{
    int choice, row[3], col[3];
    vector<vector<int> > tDarray[5];
    bool error = false;
public:
    Project();
    void menu();
    vector<vector<int> > matrixAddition(vector<vector<int> > a, vector<vector<int> > b);
    vector<vector<int> > matrixSubtraction(vector<vector<int> > a, vector<vector<int> > b);
    vector<vector<int> > matrixMultiplication(vector<vector<int> > a, vector<vector<int> > b);
    void transposeOfMatrix();
    void inverseMatrix();
    void isIdempotent();
    void isInvolutory();
    int matrixDeterminant(vector<vector<int > > m);
    void linearEquationSolve();
    void print2DVector(vector<vector<int >> result);
    void getInputAddSubDet(int i);
    void getInputMul(int i);
    void clearVar();
    void clrscrn();
};
Project::Project(){
    choice = 0;
}
void Project::clrscrn(){
    system("CLS");
}
void Project::clearVar(){
    choice = 0;
    error = false;
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    for(int i = 0; i < 5; i++) tDarray[i].clear();
}
void Project::getInputAddSubDet(int i){
    if(i > 0)    cout << "***Input for " << i << " Matrix***" << endl;
    else cout << "***Input for " << 1 << " Matrix***" << endl;
    cout << "Number of Row: ";
    cin >> row[i];
    cout << "Number of Column: ";
    cin >> col[i];
    if(i == 2){
        if(row[1] != row[2] || col[1] != col[2]){
            clrscrn();
            cout << "Invalid Matrix Size.." << endl;
            error = true;
            cin.ignore();
            return;
        }
    }
    if(i == 0){
        if(row[i] != col[i]){
            clrscrn();
            cout << "Invalid Matrix Size.." << endl;
            error = true;
            cin.ignore();
            return;
        }
    }
    cout << "Enter Matrix Element:" << endl;
    tDarray[i].assign(row[i], vector<int>(col[i]));
    for(int a = 0; a < row[i]; a++){
        for(int b = 0; b < col[i]; b++){
            cin >> tDarray[i][a][b];
        }
    }
}
void Project::getInputMul(int i){
    cout << "***Input for " << i << " Matrix***" << endl;
    cout << "Number of Row: ";
    cin >> row[i];
    cout << "Number of Column: ";
    cin >> col[i];
    if(i == 2){
        if(col[i-1] != row[i]){
            clrscrn();
            error = true;
            cout << "Invalid Matrix Size.." << endl;
            cin.ignore();
            return;
        }
    }
    cout << "Enter Matrix Element:" << endl;
    tDarray[i].assign(row[i], vector<int>(col[i]));
    for(int a = 0; a < row[i]; a++){
        for(int b = 0; b < col[i]; b++){
            cin >> tDarray[i][a][b];
        }
    }
}
int Project::matrixDeterminant(vector<vector<int> > m){
    if (m.size() == 1) return m[0][0];
    int result = 0;
    for (int i = 0; i < m.size(); i++) {
    vector< vector<int> > submatrix;
    for (int j = 1; j < m.size(); j++) {
      vector<int> row;
      for (int k = 0; k < m.size(); k++) if (k != i) row.push_back(m[j][k]);
      submatrix.push_back(row);
    }
    result += matrixDeterminant(submatrix) * (i % 2 == 0 ? m[0][i] : -m[0][i]);
    }
    return result;
}
void Project::menu(){
    bool keepGoing = true;
    while(keepGoing){
        clrscrn();
        cout << "\t\t*** Linear Algebra ***\t\t" << endl;
        cout << "1.\tMatrix Addition" << endl <<
            "2.\tMatrix Subtraction" << endl <<
            "3.\tMatrix Multiplication" << endl <<
            "4.\tTranspose of a Matrix" << endl <<
            "5.\tInverse of a Matrix" << endl <<
            "6.\tIdempotent Checker" << endl <<
            "7.\tInvolutory Checker" << endl <<
            "8.\tLinear Equation with the help of Matrix" << endl <<
            "9.\tMatrix Determinant" << endl <<
            "10.\tExit Program" << endl << endl << "Choose an Option: ";
        cin >> choice;
        clrscrn();
        switch(choice){
            case 1:{
                for(int i = 1; i <= 2; i++){
                    getInputAddSubDet(i);
                    if(error) break;
                }
                if(error) break;
                vector<vector<int> > result = matrixAddition(tDarray[1], tDarray[2]);
                cout << "Result is: " << endl;
                print2DVector(result);
                cin.ignore();
                break;
            }
            case 2:{
                for(int i = 1; i <= 2; i++){
                    getInputAddSubDet(i);
                    if(error) break;
                }
                if(error) break;
                vector<vector<int> > result = matrixSubtraction(tDarray[1], tDarray[2]);
                cout << "Result is: " << endl;
                print2DVector(result);
                cin.ignore();
                break;
            }
            case 3:{
                for(int i = 1; i <= 2; i++){
                    getInputMul(i);
                    if(error) break;
                }
                if(error) break;
                vector<vector<int> > result = matrixMultiplication(tDarray[1], tDarray[2]);
                cout << "Result is: " << endl;
                print2DVector(result);
                cin.ignore();
                break;
            }
            case 4:{
      //          transposeOfMatrix();
                break;
            }
            case 5:{
        //        inverseMatrix();
                break;
            }
            case 6:{
          //      isIdempotent();
                break;
            }
            case 7:{
            //    isInvolutory();
                break;
            }
            case 8:{
              //  linearEquationSolve();
                break;
            }
            case 9:{
                for(int i = 0; i <= 0; i++){
                    getInputAddSubDet(i);
                }
                if(error) break;
                int result = matrixDeterminant(tDarray[0]);
                cout << "Result is: " << result << endl;
                cin.ignore();
                break;
            }
            case 10:{
                keepGoing = false;
                break;
            }
            default: {
                menu();
                break;
            }
        }

        cout << endl << "Press any key to continue...";
        cin.ignore();
        clearVar();
    }
}
void Project::print2DVector(vector<vector<int> > result){
    for(vector<int> i: result){
        for(int j: i)   cout << j << " ";
        cout << endl;
    }
}
vector<vector<int> > Project::matrixAddition(vector<vector<int> > a, vector<vector<int> > b){
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            a[i][j] += b[i][j];
        }
    }
    return a;
}
vector<vector<int> > Project::matrixSubtraction(vector<vector<int> > a, vector<vector<int> > b){
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            a[i][j] -= b[i][j];
        }
    }
    return a;
}
vector<vector<int> > Project::matrixMultiplication(vector<vector<int> > a, vector<vector<int> > b){
    vector<vector<int> > res(a.size(), vector<int>(b[1].size()));
    for(int i = 0; i < a.size(); i++)
    for(int j = 0; j < b[1].size(); j++)
    for(int k = 0; k < a[1].size(); k++) res[i][j] += (a[i][k]*b[k][j]);
    return res;
}
int main(){
    Project obj;
    obj.menu();
    return 0;
}
