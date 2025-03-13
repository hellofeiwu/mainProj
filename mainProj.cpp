// mainProj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class FileIO {
public:
    void openFile() {
        _file = make_unique<fstream>(_fileName);
        if (!_file->is_open()) {
            throw runtime_error("failed to open file");
        }
    }
    void closeFile() {
        if (_file && _file->is_open()) {
            _file->close();
        }
    }

    void writeFile(const string& data) {
        if (!_file) {
            throw runtime_error("failed to open file before write");
        }
        (*_file) << data;
        if (_file->fail()) {
            throw runtime_error("failed to write file");
        }
    }

    string readFile() {
        if (!_file) {
            throw runtime_error("failed to open file before read");
        }
        string data;
        getline(*_file,data);
        if (_file->bad()) {
            throw runtime_error("failed to read file");
        }
        
        return data;
    }

    FileIO(const string& fileName):_fileName(fileName), _file(nullptr) {
    }
    ~FileIO() {
        closeFile();
    }
private:
    unique_ptr<fstream> _file;
    string _fileName;
};
int main()
{
    //try {
    //    FileIO file("myFile.txt");
    //    file.openFile(); // make sure you have created the file, otherwise it will throw exception
    //    file.writeFile("my new data");
    //    file.closeFile(); // need to close file and reopen file to read the content, otherwise cannot read anything

    //    file.openFile();
    //    cout << file.readFile() << endl;
    //    file.closeFile();
    //}
    //catch (const exception e) {
    //    cout << "Exception: " << e.what() << endl;
    //}

    vector<int> arr = {1,2,3,4,5};

    cout << "type in an index:" << endl;
    int i;
    cin >> i;
    try {
        if (i<0 || i>arr.size()-1) {
            throw out_of_range("index is out of range");
        }
        cout << "the number you choose is: " << arr[i] << endl;
    }
    catch (const exception e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
