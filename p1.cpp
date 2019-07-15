/*Musat Mihai-Robert
 *Grupa 323CB
 */

#include <bits/stdc++.h>

const int NMAX = 1e5 + 5;

using namespace std;

int main()
{
    ifstream fin("p1.in");
    ofstream fout("p1.out");

    int n, v[NMAX];

    //citire date de intrare
    fin >> n;
    for(int i = 0; i < n; ++i) {
        fin >> v[i];
    }

    //sortez vectorul crescator
    sort(v, v + n);

    //ans = variabila in care salvez diferenta maxima
    long long ans = 0;

    //parcurg vectorul de la inceput, dar iau apoi indicii de la final
    for(int i = 0; i < n; ++i) {
	//am 2 cazuri : Tuzgu e la mutare sau Ritza e la mutare      
	if(i % 2 == 0) { 
            ans = ans + v[n - 1 - i];//Tuzgu e la mutare -> pozitie para -> adun la rezultat
        } else {
            ans = ans - v[n - 1 - i];//Ritza e la mutare -> pozitie impara -> scad din rezultat
        }
    }

    //afisez diferenta maxima
    fout << ans << endl;

    return 0;
}
