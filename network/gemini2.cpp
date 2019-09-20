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



/*
Stream multiplexer 

Write a program that reads input from multiple UDP streams and publishes it out to a
single UDP stream. The incoming and outgoing UDP endpoints must be read as program
input (either from the command line or configuration). The messages must be published
in the order in which they are received. Each input stream sends sequenced messages.
Your program must assign every message with another sequence number that gets incremented
while also keeping the sequence number of the incoming message.

While writing code, prefer performance over cross platform compatibility.
Use Google protobuf when possible and define your own messages.

Your program should log to a file or stdout.

Please make sure your program compiles with GCC (on Linux).

Feel free to use STL as supported by your GCC compiler, however using third party libraries
(like boost, Qt, etc.) is prohibited.

Please include the source code and instructions for compiling and running the program.

For example:

Incoming UDP streams: 192.168.9.10:37865,192.168.9.11:37654, 192.168.10.15:28976 Outgoing stream: 192.168.11.155:48763

*/