#include <iostream>
#include <iomanip>

using namespace std;

struct sinhvien 
{
    string name;
    string MSV; 
    double diem[9];
    double TBM;
};

void nhapDulieu(sinhvien &sv, string subject[]);
void xuatDulieu(sinhvien sv, string subject[]);
void calc(sinhvien sv, double &TBM);

int main() 
{
    system("cls");
    int numS;
    string subject[9] {"Giai Tich", "Nhap mon lap trinh", "DSTT", "Vat li ky thuat", "Nhap mon KHMT", "Java nang cao", "Python", "C++", "TACB"};

    cout << "\n\t\t\tNhap so luong sinh vien: ";
    cout << "\n\t\t\tInput -> ";
    cin >> numS;
    cin.clear();
    fflush(stdin);
    sinhvien sv[numS];
    cin.ignore();
    system("cls");
    for(int i = 0; i < numS; i++) 
    {
        cout << "\n\t\t\tNhap diem sinh vien thu " << i + 1 << ": ";
        nhapDulieu(sv[i], subject);
    }

    cout << "\n\t\t\t---Ket thuc nhap du lieu---";
    cout << "\n\t\t\t-----------------------------------------------------\n";
    system("cls");
    cout << "\n\t\t\tTHONG TIN SINH VIEN: ";

    for(int i = 0; i < numS; i++)
        xuatDulieu(sv[i], subject);
}

void nhapDulieu(sinhvien &sv, string subject[]) 
{
    int temp;
    cout << "\n\t\t\tNhap ten sinh vien: ";
    getline(cin, sv.name);
    cout << "\n\t\t\tNhap MSV: ";
    cin >> sv.MSV;
    cout << "\n\t\t\tNHAP DIEM:";

    for(int i = 0; i < 9; i++) 
    {
        cout << "\n\t\t\t" <<subject[i] << ": ";
        cin >> temp;
        cin.clear();
        fflush(stdin);
        while(temp > 10 || temp < 0) 
        {
            cout << "\n\t\t\tDiem khong hop le, vui long nhap lai: ";
            cin >> temp;
        }
        sv.diem[i] = temp;
    }
    calc(sv, sv.TBM);
    cin.ignore();
    system("pause");
}

void xuatDulieu(sinhvien sv, string subject[]) 
{
    cout << "\n\t\t\tTen sinh vien:  " << sv.name << '\n';
    cout << "\n\t\t\tMSV: " << sv.MSV << '\n';
    for(int i = 0; i < 9; i++) 
        cout << "\n\t\t\t" << subject[i] << ": " << sv.diem[i] <<'\n';
    cout << "\n\t\t\tTBM: " << setprecision(2) << fixed << sv.TBM;
    cout << "\n\t\t\t-----------------------------------------------------\n";
}

void calc(sinhvien sv, double &TBM) 
{
    for(int i = 0; i < 9; i++) 
        TBM += sv.diem[i];
    TBM /= 9;
}