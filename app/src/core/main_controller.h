#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>
#include <string.h>

using namespace std;

class MainController{

    string file;

    string buffer;

    void read_file()
    {
        char next_char;
        int counter = 0;
        ifstream in_file;
        
        in_file.open("/var/www/cgi-bin/res/index.html");

        if (!in_file) {
            cout << "Unable to open file";
            exit(1); // terminate with error
        }
        string current;
        while (getline(in_file, current))
        {
            this->file += current + "\n";
        }
        
        
        in_file.close();
    }

    public:

    void index()
    {
        this->read_file();
        cout << "Content-type:text/html;charset=UTF-8;\r\n\r\n";
        cout << this->file;
    }

    void sse_data()
    {
        cout << "Content-Type: text/event-stream;charset=UTF-8;\n";
        cout << "Cache-Control: no-cache;\n";
        this->sse();
    }

    void sse()
    {
        this->buffer += "&#9608; ";

        if(this->buffer.length() >= 150)
        {
            this->buffer = "&#9608; ";
        }

        cout << "data: "+this->buffer+" \n\n";

        usleep(5000);

        sse();
    }
};