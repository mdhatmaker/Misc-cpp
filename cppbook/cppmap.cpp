#include <iostream>
#include <map>
#include <string>
#include <iterator>

using namespace std;


int main() {

    map<string,int> mapOfWords;     // Key = Word (std::string), Value = Word's frequency count (int)
    map<string,int>::iterator it;   // iterator used to iterate through elements in std::map

    /* No external sorting criteria for key(std::string) is specified in above std::map, therefore it will
    use default key sorting criteria (i.e. operator < and all elements arranged by alphabetical order of keys). */

    // Inserting data into std::map
    mapOfWords.insert(make_pair("earth", 1));   // insert data into std::map using make_pair(key,value)
    mapOfWords.insert(make_pair("moon", 2));
    mapOfWords["sun"] = 3;                      // insert data into std::map using [] indexing
    mapOfWords["earth"] = 4;                    // replace the value of already added key "earth"

    // Iterate through all elements in std::map
    it = mapOfWords.begin();
    while (it != mapOfWords.end()) {
        cout << it->first << " :: " << it->second << "\n";
        it++;
    }

    // Check if insertion is successful or not
    if (mapOfWords.insert(make_pair("earth", 1)).second == false) {
        cout << "Element with key 'earth' not inserted because key already existed\n";
    }

    /* Check If Map Contains a Key (std::map::find) */
    if (mapOfWords.find("sun") != mapOfWords.end())
        cout << "word 'sun' found\n";
    if (mapOfWords.find("mars") == mapOfWords.end())
        cout << "word 'mars' not found\n";

    /* Check If Map Contains a Key (std::map::count) */
    if (mapOfWords.count("moon") > 0) {
        cout << "'moon' Found\n";
    }
    else {
        cout << "'moon' Not Found\n";
    }

    /* Deleting Data From Map
    Use std::map's erase member funtion to delete an element in std::map.*/

    // Erasing By Iterator
    it = mapOfWords.find("moon");
    mapOfWords.erase("earth");

    // Erasing By Key
    mapOfWords.erase("earth");

}