#include <iostream>
#include <fstream>
#include <string>

void welcome_message(){

    std::cout << "****************" << std::endl;
    std::cout << "* #include <fstream> *" << std::endl;
    std::cout << "*** fstream  ***" << std::endl;
    std::cout << "****************" << std::endl;
};


/*
std::ifstream
-------------
std::ifstream is used for reading data from files.
You open the file with .open(), check if it's open with .is_open(), and read data using >>, .getline(), .get(), or .read().
*/
void example_ifstream() {
    std::ifstream infile;
    infile.open("input.txt"); // Open a file for reading
    if (infile.is_open()) {
        std::string line;
        while (std::getline(infile, line)) { // Read lines from the file
            std::cout << "Read line: " << line << std::endl;
        }
        infile.close(); // Close the file
    } else {
        std::cerr << "Could not open input.txt" << std::endl;
    }
}

/*
std::ofstream
-------------
std::ofstream is used for writing data to files.
Open with .open(), check with .is_open(), write using <<, .put(), or .write(), and close with .close().
*/
void example_ofstream() {
    std::ofstream outfile("output.txt"); // Open/create a file for writing
    if (outfile.is_open()) {
        outfile << "Hello, file!" << std::endl; // Write formatted data
        outfile.put('A'); // Write a single character
        const char* raw = "Raw bytes\n";
        outfile.write(raw, 10); // Write raw bytes (including newline)
        outfile.close(); // Close the file
    } else {
        std::cerr << "Could not open output.txt" << std::endl;
    }
}

/*
std::fstream
------------
std::fstream is used for both reading and writing.
Open with file mode flags (std::ios::in | std::ios::out). You can use >>, <<, .get(), .put(), .read(), .write(), .seekg(), .seekp(), .tellg(), .tellp().
*/
void example_fstream() {
    std::fstream ioFile("data.txt", std::ios::in | std::ios::out | std::ios::trunc); // Open for read/write, clear file
    if (ioFile.is_open()) {
        ioFile << "Line 1\nLine 2\n";
        ioFile.seekg(0); // Move input pointer to beginning
        std::string line;
        while (std::getline(ioFile, line)) {
            std::cout << "fstream read: " << line << std::endl;
        }
        ioFile.close();
    }
}

/*
.open(), .close(), .is_open()
-----------------------------
.open() opens a file, .close() closes it, and .is_open() checks if it's open.
*/
void example_open_close_isopen() {
    std::ifstream file;
    file.open("input.txt");
    if (file.is_open()) {
        std::cout << "File opened successfully!" << std::endl;
        file.close();
        std::cout << "File closed." << std::endl;
    }
}

/*
.read(), .write()
-----------------------
.read() reads raw bytes, .write() writes raw bytes.
*/
void example_read_write() {
    std::ofstream out("binary.dat", std::ios::binary);
    int number = 12345;
    out.write(reinterpret_cast<char*>(&number), sizeof(number)); // Write integer in binary
    out.close();

    std::ifstream in("binary.dat", std::ios::binary);
    int recovered = 0;
    in.read(reinterpret_cast<char*>(&recovered), sizeof(recovered)); // Read integer from binary
    std::cout << "Recovered number: " << recovered << std::endl;
    in.close();
}

/*
.get(), .put()
---------------
.get() reads a single character, .put() writes a single character.
*/
void example_get_put() {
    std::ofstream out("chars.txt");
    out.put('X');
    out.put('\n');
    out.close();

    std::ifstream in("chars.txt");
    char ch;
    while (in.get(ch)) {
        std::cout << "Character read: " << ch << std::endl;
    }
    in.close();
}

/*
.getline()
----------
.getline() reads a line of text from the file into a string.
*/
void example_getline() {
    std::ofstream out("lines.txt");
    out << "First line\nSecond line\n";
    out.close();

    std::ifstream in("lines.txt");
    std::string line;
    while (std::getline(in, line)) {
        std::cout << "Line: " << line << std::endl;
    }
    in.close();
}

/*
.seekg(), .seekp(), .tellg(), .tellp()
--------------------------------------
.seekg() sets input position, .seekp() sets output position.
.tellg() gets input position, .tellp() gets output position.
*/
void example_seek_tell() {
    std::ofstream out("seek.txt");
    out << "abcdef";
    out.close();

    std::fstream file("seek.txt", std::ios::in | std::ios::out);
    file.seekg(2); // Move input pointer to position 2
    char ch;
    file.get(ch);
    std::cout << "Character at position 2: " << ch << std::endl;
    std::cout << "Current get pointer: " << file.tellg() << std::endl;

    file.seekp(4); // Move output pointer to position 4
    file.put('Z');
    file.seekg(0);
    std::string result;
    std::getline(file, result);
    std::cout << "Modified line: " << result << std::endl;
    file.close();
}

/*
.eof(), .good(), .bad(), .fail()
--------------------------
Checks stream state:
- .eof() true if end-of-file reached.
- .good() true if no error.
- .bad() true if irrecoverable error.
- .fail() true if last operation failed.
*/
void example_state() {
    std::ifstream in("lines.txt");
    std::string line;
    while (std::getline(in, line)) {
        // Reading lines
    }
    std::cout << "EOF: " << in.eof()
              << ", Good: " << in.good()
              << ", Bad: " << in.bad()
              << ", Fail: " << in.fail() << std::endl;
    in.close();
}

/*
<<, >>
---------
Use << to write formatted data, >> to read formatted data, just like with cout/cin.
*/
void example_formatted_io() {
    std::ofstream out("numbers.txt");
    out << 42 << " " << 3.14 << std::endl;
    out.close();

    std::ifstream in("numbers.txt");
    int i;
    double d;
    in >> i >> d;
    std::cout << "Read numbers: " << i << ", " << d << std::endl;
    in.close();
}

/*
.flush()
---------
.flush() manually flushes output buffer to file.
*/
void example_flush() {
    std::ofstream out("flush.txt");
    out << "This will be flushed.";
    out.flush(); // Ensure written immediately
    out.close();
}

/*
Main
-----
Demonstrate all examples.
*/
int main() {
    welcome_message();
    example_ofstream();
    example_ifstream();
    example_fstream();
    example_open_close_isopen();
    example_read_write();
    example_get_put();
    example_getline();
    example_seek_tell();
    example_state();
    example_formatted_io();
    example_flush();
    return 0;
}