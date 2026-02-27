#include <bits/stdc++.h>

using namespace std;

const int N = 10020;
vector<pair<int, int>> graph[ N ]; ///<sasiad, odleglosc>    /// tworze graf ( vektor par <odleglosc, numer jego sasiada>)
int dist[ N ];                                               /// tablica z odleglosciami
int ilosc_metali, ilosc_przemian, a, b, c, u, w;
int odleglosc, wierzcholek;

priority_queue<pair<int, int>> kolejka;                      /// kolejka priorytetowa <odleglosc, numer do ktorego idziemy>

void wczytaj(){                                              /// tworzymy funkcję wypelniajaca graph
    cin >> ilosc_metali;
    for(int i = 1; i <= ilosc_metali ; i++)
    {
        cin >> a;
        graph[i].push_back({ilosc_metali + i, a/2});
    }
    cin >> ilosc_przemian;
    for(int i=1 ; i<= ilosc_przemian; i++)
    {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[ilosc_metali+a].push_back({ilosc_metali+b, c});
    }
}

void Dijkstra()
{
    kolejka.push({0, 1});
    while(kolejka.size())
    {
        auto[odleglosc, wierzcholek] = kolejka.top();
        kolejka.pop();
        if(dist[wierzcholek] < -odleglosc) continue;
        else dist[wierzcholek] = -odleglosc;
        for(auto [u, w]: graph[wierzcholek])
        {
            kolejka.push({odleglosc-w, u});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 0; i < 10020; i++)
    {
        dist[i] = 500000000;
    }
    wczytaj();
    Dijkstra();
    cout << dist[ilosc_metali+1];
}

/*
4      ilosc metali
200    cena złota
100
40
2
6      ilosc przemian (z , do, cena)
1 2 10
1 3 5
2 1 25
3 2 10
3 4 5
4 1 50

- jak najmniejsze cło
- najmniej kosztowna zamiana

q.top();        wyswietla
q.pop();        usuwa
q.push( ... );  dodaje


auto [d, v] = q.top();

int d = q.top().first;
int d = q.top().second;



*/

