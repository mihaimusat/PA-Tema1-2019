/*Musat Mihai-Robert
 *Grupa 323CB
 */

#include <bits/stdc++.h>

const int NMAX = 1e3 + 5, TUZGU = 0, RITZA = 1;

using namespace std;

int main()
{
    ifstream fin("p3.in");
    ofstream fout("p3.out");

    int n, v[NMAX];
    long long dp[NMAX][NMAX];

    //citire date de intrare
    fin >> n;
    for(int i = 1; i <= n; ++i) {
        fin >> v[i];
    }
	
    //dp[i][j] = diferenta maxima pe care o poate obtine Tuzgu pe fiecare interval [i..j]

    //fixez lungimea intervalului 1, 2, ...
    for(int lg = 1; lg <= n; ++lg) {
	//imi fixez capetele intervalului
	//si stiu ca initial Tuzgu este la mutare        
	int lin = 1, col = lg, turn = TUZGU;
	//daca ma aflu la pozitie impara, Ritza e la mutare
        if((n - lg) % 2 != 0) {
            turn = RITZA;
        }
	//cat timp pot sa mai marginesc superior intervalul
        while(col <= n) {
            if(turn == TUZGU) {
		//daca iau din stanga, vad cat ar fi facut Tuzgu pe [i+1..j] si adun elementul curent
		//daca iau din dreapta, vad cat ar fi facut Tuzgu pe [i..j-1] si adun elementul curent
		//scorul maxim obtinut de Tuzgu va fi maximul dintre cele 2 cazuri               
		dp[lin][col] = max(dp[lin + 1][col] + v[lin], dp[lin][col - 1] + v[col]);
            } else {
		//analog situatiei anterioare, doar ca vreau sa maximizez acum scorul Ritzei
		//deci va trebui sa calculez scorul minim dintre cele doua cazuri si sa scad elementul curent              
		dp[lin][col] = min(dp[lin + 1][col] - v[lin], dp[lin][col - 1] - v[col]);
            }
            ++lin;//actualizez si capatul inferior
            ++col;
        }
    }
    
    //afisez rezultatul
    fout << dp[1][n] << endl;

    return 0;
}
