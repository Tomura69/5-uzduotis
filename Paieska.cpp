#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <regex>

using std::cout;
using std::endl;

int main () {
    std::ifstream file("test.md");
    std::map<std::string, int> zodziai;
    std::map<std::string, std::vector<int>> vieta;
    std::map<int, std::string> site;
    std::regex url("^(https?:\\/\\/)?([\\da-z\\.-]+)\\.([a-z\\.]{2,6})([\\/\\w \\.-]*)*\\/?$");
    int nr = 1;
    if (!file.good()) {
        cout << "Failai neegzistuoja" << endl;
    }
    else {
        while (!file.eof()) {
            std::string eil;
            std::getline(file, eil);
            std::transform(eil.begin(), eil.end(), eil.begin(), ::tolower);
            std::istringstream in_line(eil);
            std::string word;
            while (in_line >> word){
                if (std::regex_match(word, url)){
                    site[nr] = word;
                    break;
                }
                word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end());
                if(word != "")
                    zodziai[word]++;
                    vieta[word].push_back(nr);
            }
            ++nr;
        }
        int sum = 0;
        for(std::map<std::string, int>::iterator it = zodziai.begin(); it != zodziai.end(); ++it){
            int kiek = 0;
            if (it->second > 1){
                cout << it->first << " - pasikartoja " << it->second << " kartu eilutese:" << endl;
                for (std::map<std::string, std::vector<int>>::iterator wit = vieta.begin(); wit != vieta.end(); ++wit){
                    if (it->first == wit->first){
                        for (int i = 0; i < wit->second.size(); ++i){
                            cout << wit->second[i] << " ";
                        }
                    }
                }
                cout << endl;
                kiek++;
            }
            sum = sum + kiek;
        }
        cout << endl;
        if (sum == 0) cout << "Besikartojanciu zodziu nera" << endl;
        for (std::map<int, std::string>::iterator it = site.begin(); it != site.end(); ++it){
            cout << "Tinklapis: " << it->second << " yra " << it->first << " eiluteje" << endl;
        }
    }
    return 0;
}