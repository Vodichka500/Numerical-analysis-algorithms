#include <iostream>

using namespace std;

int main()
{
    int lw;
    int counter = 0;
    int counterW = 0;
    cout << "Podaj Liczbe wezlow" << endl;
    cin >> lw;

    double *tabZ = new double[lw];
    int* tabK = new int[lw];

    cout << "Podaj weziel:" << endl;
    for (int i = 0; i < lw; i++)
    {
        cout << "Z[" <<i<<"] = ";
        cin >> tabZ[i];
    }

    tabK[0] = 0;
    counter++;
    counterW++;
    for (int i = 1; i < lw; i++)
    {
        if (tabZ[i - 1] == tabZ[i])
        {
            counterW++;
            tabK[i] = tabK[i - 1];
        }
        else
        {
            counterW = 1;
            counter++;
            tabK[i] = tabK[i - 1] + 1;
        }
    }

    cout <<"ilosc wierszy "<< counterW << "Ilosc kolumn: "<<counter<<"\n"<<endl;
    double** tabf = new double* [counterW];
    for (int i = 0; i < counterW; i++) {
        tabf[i] = new double[counter];
    }
    int* tabKoef = new int[counter];
    for (int i = 0; i < counter; i++) {
        cout << "Podaj k" << i << ": ";
        cin >> tabKoef[i];
    }


    for (int i = 0; i < counter; i++) {
        for (int j = 0; j < counterW; j++) {
            if (j == 0)
            {
                cout << "Podaj wartosc f(x) z X" << i << ": ";
                cin >> tabf[i][j];
                continue;
            }
            if (j < tabKoef[i])
            {
                cout << "Podaj " << j << " pochadna z X" << i<<": ";
                cin >> tabf[i][j];
            }
            else
            {
                tabf[i][j] = 0;
            }
        }
    }

    cout << "\n";
    for (int i = 0; i < lw; i++){
        cout << "Z" << i << "  ";
    }
    cout << endl;
    for (int i = 0; i < lw; i++) {
        cout << tabZ[i] << "   ";
    }
    cout << "\n";

    for (int i = 0; i < counter; i++) {
        cout << "\nPochodne z X" << i << ": ";
        for (int j = 0; j < counterW; j++) {
            if (j == 0)
            {
                cout << "Wartosc f(x) z X" << i << ": "<< tabf[i][j]<<"   ";
                
                
            }
            if (tabf[i][j] != 0){
                cout << "Pochodna " << j << ": " << tabf[i][j] << "    ";
            }
            else {
                cout << " ";
            }

        }
        cout << endl;
    }
    for (int i = 0; i < counter; i++) {
        for (int j = 0; j < counterW; j++)
        {
            cout << tabf[i][j] << " ";
        }
        cout << endl;
    }


    double* tabOdp = new double[lw - 1];
    int k= 0;
    int w = 0;
    cout << "\nOdpowiedz: " << endl;
    for (int i = 0; i < lw-1; i++)
    {
        if (tabZ[i] == tabZ[i + 1])
        {
            tabOdp[i] = tabf[w][k+1]/1;
        }
        else
        {
            w++;
            tabOdp[i] = (tabf[w][k] - tabf[w-1][k]) / (tabZ[i + 1] - tabZ[i]);
        }
        cout << tabOdp[i] << endl;
    }

}   

