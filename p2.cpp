/*Musat Mihai-Robert 
 *Grupa 323CB
 */
#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1e3 + 5;

int main()
{
    ifstream fin("p2.in");
    ofstream fout("p2.out");
    
    int n, k, v[NMAX];
    long long x, y, dp[NMAX][NMAX];

    //citire date de intrare    
    fin >> n >> k;
    for(int i = 1; i <= n; ++i) {
    	fin >> v[i];
    }
    
    //sortez vectorul crescator
    sort(v + 1, v + n + 1);
    
    //apoi il inversez
    //deci in acest moment am obtinut vectorul sortat descrescator
    reverse(v + 1, v + n + 1);

    //dp[i][j] = diferenta maxima pe care pot sa o obtin daca 
    //elimin j elemente din primele i elemente din vectorul sortat
    for(int lin = 1; lin <= n; ++lin)
        for(int col = 0; col <= k; ++col)
            dp[lin][col] = 0LL;

    //calculez elementele matricii dp cu semnificatia de mai sus
    for(int lin = 1; lin <= n; ++lin)
        for(int col = 0; (col <= lin) && (col <= k); ++col) {
            //am 2 cazuri: pot sa elimin numarul sau sa il pastrez
	    //initial elimin numarul
	    if(col >= 1) {
                x = (0LL) + dp[lin - 1][col - 1];
            } else {
                x = 0LL;
	    }
	    //apoi, pastrez numarul
            if(((lin - col) % 2) == 1) {
                y = (0LL) + dp[lin - 1][col] + v[lin];//daca la mutare este primul jucator
            } else { 
                y = (0LL) + dp[lin - 1][col] - v[lin];//daca la mutare este cel de-al doilea jucator
	    }
  	    //la fiecare pas, solutia va fi data de maximul dintre cele 2 situatii
            if(x > y) {
                dp[lin][col] = (0LL) + x; 
            } else {
                dp[lin][col] = (0LL) + y;
	    }
        }

    //afisare rezultat
    fout << dp[n][k] << endl;

    return 0;
}
