# 5-uzduotis
Last task of voop

## 1-oji užduotis

Reikėjo išvesti skirtingus žodžius, kurie pasikartojo dažniau negu 1 kartą ir count'erį, 
nurodantį kiek kartų konkretus žodis pasikartojo.

Programai naudojau `std::map`:
```cpp
std::map<std::string, int> zodziai;
std::map<std::string, std::vector<int>> vieta;
std::map<int, std::string> site;
```

Programos realizacina nėra sudėtinga, pagrindą sudaro šios eilutės:
```cpp
word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end());
if(word != ""){
  zodziai[word]++;
  vieta[word].push_back(nr);
}
```
* pirmoji elutė ištrina visus skirybos ženklus nuskaitytame žodyje.
* if'as tikrina ar nuskaitytas žodis nėra tuščias ir įrašo jį, jo pasikartojimo kiekį ir kurioje eilutėje jis yra.

## 2-oji užduotis

Reikėjo sukurti lentelę kurioje būtų nurodyta, kurioje teksto vietoje (kurioje(-iose) teksto eilutėse) ir kiek kartų pasikartojo žodžiai.

Sprendimas buvo paprastas ir į koncolę yra išvedama žodis, kiek kartų pasikartojo ir kuriose eilutėse:
```cpp
variklio - pasikartoja 2 kartu eilutese:
2 3
važiuojant - pasikartoja 4 kartu eilutese:
6 7 15 16
```

## 3-oji užduotis

URL adresų suradimas tekste

Ši dalis buvo sunkiausia, teko ieškoti daug informacijos. Sprendimas privedė prie `std::regex` panaudojimo.
Buvo sukurtas `std::regex` paieškos modelis:
```cpp
std::regex url("^(https?:\\/\\/)?([\\da-z\\.-]+)\\.([a-z\\.]{2,6})([\\/\\w \\.-]*)*\\/?$");
```
Pagal jį yra ieškomi tinklapių adresai su if'o pagalba:
```cpp
if (std::regex_match(word, url)){
  site[nr] = word;
  break;
}
```
Kai atrandamas tinklapio adresas, jis yra įrašomas į `std::map`

# Rezultatas:
```cpp
apie - pasikartoja 3 kartu eilutese:
1 2 19
aptarnavimo - pasikartoja 2 kartu eilutese:
18 22
ar - pasikartoja 3 kartu eilutese:
7 7 15
automobilis - pasikartoja 4 kartu eilutese:
4 8 22 24
bet - pasikartoja 5 kartu eilutese:
3 7 16 22 23
dėl - pasikartoja 2 kartu eilutese:
2 17
gana - pasikartoja 2 kartu eilutese:
3 5
ir - pasikartoja 11 kartu eilutese:
1 3 4 5 5 6 9 11 16 17 21
kad - pasikartoja 4 kartu eilutese:
2 18 22 24
kai - pasikartoja 2 kartu eilutese:
19 19
kas - pasikartoja 2 kartu eilutese:
16 23
kiti - pasikartoja 2 kartu eilutese:
18 20
klimato - pasikartoja 2 kartu eilutese:
12 20
kokiu - pasikartoja 2 kartu eilutese:
7 16
labai - pasikartoja 7 kartu eilutese:
4 6 10 12 17 23 24
nei - pasikartoja 3 kartu eilutese:
18 20 22
noriu - pasikartoja 2 kartu eilutese:
1 23
nuo - pasikartoja 2 kartu eilutese:
9 17
o - pasikartoja 2 kartu eilutese:
4 17
pavarų - pasikartoja 2 kartu eilutese:
2 4
pačiu - pasikartoja 2 kartu eilutese:
4 6
prie - pasikartoja 2 kartu eilutese:
14 15
puiki - pasikartoja 2 kartu eilutese:
11 14
puikus - pasikartoja 2 kartu eilutese:
13 24
range - pasikartoja 2 kartu eilutese:
1 18
rover - pasikartoja 2 kartu eilutese:
1 18
sistema - pasikartoja 2 kartu eilutese:
11 12
tai - pasikartoja 3 kartu eilutese:
5 7 16
taip - pasikartoja 3 kartu eilutese:
15 18 22
tiek - pasikartoja 2 kartu eilutese:
9 9
tuo - pasikartoja 2 kartu eilutese:
4 6
variklio - pasikartoja 2 kartu eilutese:
2 3
važiuojant - pasikartoja 4 kartu eilutese:
6 7 15 16
veikia - pasikartoja 2 kartu eilutese:
2 12
visus - pasikartoja 2 kartu eilutese:
5 17
vos - pasikartoja 2 kartu eilutese:
17 17
yra - pasikartoja 7 kartu eilutese:
4 5 7 15 18 22 24
į - pasikartoja 3 kartu eilutese:
7 11 21
šio - pasikartoja 2 kartu eilutese:
2 2
šviesų - pasikartoja 2 kartu eilutese:
14 14

Tinklapis: https://github.com/tomura69/5-uzduotis yra 13 eiluteje
Tinklapis: www.veju-uostas.lt yra 24 eiluteje
```

