#include <iostream> 
#include <fstream> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
#include <cstring> 
using namespace std; 
void simulate_cp(const string &source, const string &destination) { 
ifstream src(source, ios::binary); 
if (!src) { 
cerr << "Source file open failed" << endl; 
exit(1); 
} 
ofstream dest(destination, ios::binary); 
if (!dest) { 
cerr << "Destination file open failed" << endl; 
exit(1); 
} 
dest << src.rdbuf(); 
cout << "File copied successfully by process " << getpid() << endl; 
} 
void simulate_grep(const string &pattern, const string &file) { 
ifstream fp(file); 
if (!fp) { 
cerr << "File open failed" << endl; 
exit(1); 
} 
string line; 
while (getline(fp, line)) { 
if (line.find(pattern) != string::npos) { 
cout << line << endl; 
}                                        
} 
cout << "Grep operation completed by process " << getpid() << endl; 
} 
int main() { 
int choice; 
string source, destination, pattern, file; 
while (true) { 
        cout << "\nMenu:\n"; 
        cout << "1. Copy file (cp)\n"; 
        cout << "2. Search in file (grep)\n"; 
        cout << "3. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
        cin.ignore(); 
         
        switch (choice) { 
            case 1: 
                cout << "Enter source file name: "; 
                cin >> source; 
                cout << "Enter destination file name: "; 
                cin >> destination; 
                 
                if (fork() == 0) { 
                    simulate_cp(source, destination); 
                    exit(0); 
                } else { 
                    wait(NULL); 
                } 
                break; 
             
            case 2: 
                cout << "Enter pattern to search: "; 
                cin >> pattern; 
                cout << "Enter file name: "; 
                cin >> file; 
                 
                if (fork() == 0) { 
                    simulate_grep(pattern, file); 
                    exit(0); 
                } else { 
                    wait(NULL); 
                } 
                break; 
             
            case 3: 
                cout << "Exiting program..." << endl; 
                exit(0); 
             
            default: 
                cout << "Invalid choice. Please try again." << endl; 
        } 
    } 
    return 0; 
}
