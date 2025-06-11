#include <iostream>
#include <vector>   //for times sake
#include <string>
#include <algorithm>
#include <list>
#include <chrono>
using namespace std;
using namespace chrono;

class Hash{
    public:
        vector<list<std::string>> table;
        Hash(size_t size) : table(size){}
        void ins(const std::string& key){
                size_t hashs = hash<std::string>{}(key) % table.size();
                table[hashs].push_back(key);
        }
        bool search(const std::string& key){

            size_t hashs = hash<std::string>{}(key) % table.size();
            for (const auto& a : table[hashs]){
                if (a == key){
                    return true;
                }
            }
            return false;
        }
};
string randStr(){
    static const string ranChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string r;
    for (int i = 0 ; i < 20 ; i++){
        r += ranChars[rand() % ranChars.size()];
    }
    return r;
}
bool linSearch(const vector<string>& arr, const string& target){
    for (const auto& a : arr){
        if (a == target){return true;}
    }
    return false;
}
bool binSearch(const vector<string>& arr, const string& target){
    return binary_search(arr.begin(), arr.end(), target);
}
int main() {
    vector<size_t> sizeVals = {1000, 3000, 5000, 10000};
    cout << "Linear Search , Binary Search Time, Hash Table Search" << endl;
    for (size_t N : sizeVals) {
        vector<string> data;
        data.reserve(N);
        for (size_t i = 0; i < N; ++i) {
            data.push_back(randStr());
        }
        vector<string> binData = data;
        Hash hashTbl(N);
        for (const auto& str : data) {
            hashTbl.ins(str);
        }
        sort(binData.begin(), binData.end());
        vector<string> targets;
        targets.reserve(N);
        for (size_t i = 0; i < N / 2; ++i) {
            targets.push_back(data[rand() % data.size()]);
            targets.push_back(data[rand() % data.size()]);
        }
        auto timer = [&](auto currSearch) {
            auto start = high_resolution_clock::now();
            size_t count = 0;
            for (const auto& tgt : targets) {
                if (currSearch(tgt)) {++count;}
            }
            auto end = high_resolution_clock::now();
            return duration<double>(end - start).count();
        };
        double LTime = timer([&](const string& tgt) { return linSearch(data, tgt); });
        double BTime = timer([&](const string& tgt) { return binSearch(binData, tgt); });
        double HTime = timer([&](const string& tgt) { return hashTbl.search(tgt); });
        cout << N << "," << LTime << "," << BTime << "," << HTime << "\n";
    }
    return 0;
}