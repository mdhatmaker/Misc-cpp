#include <fstream>
#include <iostream> 
#include <list> 
#include <iterator> 
#include <string>
#include <vector>
using namespace std;

vector<string> split(string s, string delim)
{
    vector<string> v;
    int start = 0;
    int end = s.find(delim);
    while (end != std::string::npos)
    {
        v.push_back(s.substr(start, end-start));
        start = end + delim.length();
        end = s.find(delim, start);
    }
    v.push_back(s.substr(start, end-start));
    return v;
}

void process_file(string filename)
{
    string line;
    int N, T;

    ifstream infile;
    infile.open(filename);

    if (!infile.is_open())
    {
        cout << "Unable to open file" << endl;
        exit(-1);
    }

    cout << "Reading from the file" << endl; 
    getline (infile, line);
    vector<string> v = split(line, " ");
    N = stoi(v[0]);
    T = stoi(v[1]);
    
    // write the config data to the screen.
    cout << "N=" << N << "  T=" << T << endl;
    
    list<unsigned long> li;

    // again read the data from the file and display it.
    while ( getline (infile, line) )
    {
        unsigned long timestamp = std::stoul(line, nullptr, 0);
        //cout << timestamp << endl;
        // process timestamp here
        if (li.size() < N)
        {
            li.push_back(timestamp);
            cout << timestamp << " pass" << endl;
        }
        else
        {
            if (timestamp > li.front() + T)
            {
                li.pop_front();
                li.push_back(timestamp);
                cout << timestamp << " pass" << endl;
            }
            else
                cout << timestamp << " fail" << endl;
        }
        
    }

    // close the opened file.
    infile.close();
}

int main() 
{ 
    process_file("./data/samplein1.txt");
    
    return(0);
} 