#include <iostream>

using namespace std;

class OutputManager{
    public:

    void hello()
    {
        cout << "Content-type:text/html\r\n\r\n";
        cout << "<html>\n";
        cout << "<head>\n";
        cout << "<title>Hello World - First CGI Program</title>\n";
        cout << "</head>\n";
        cout << "<body>\n";
        cout << "<h2>Hello World! This32 is my first CGI program</h2>\n";
        cout << "</body>\n";
        cout << "</html>\n";
    }
};