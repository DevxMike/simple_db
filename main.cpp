#include <iostream>
#include <string>
#include <vector>
namespace{
    const std::string help = 
    "Those are the only available switches:\n"
    "-h help\n"
    "-q \"Your query goes here\"\n"
    "-s valid query syntax";
    const std::string syntax = 
    "Valid syntax:";
}
int main(int argc, char** argv){
    using std::cin;
    using std::cout;
    using std::endl;

    if(argc == 1){
        cout << "Wrong syntax.\nType \"./simple_db -h\" for help." << endl;
        exit(1);
    }
    const std::vector<std::string> args(argv + 1, argv + argc);
    if(args.front().size() == 2 && args.front().front() == '-'){
        switch(args.front().back()){
            case 'h':
                cout << help << endl;
                exit(0);
            break;
            case 'q':
                cout << "Your query: ";
                cout << args.back() << endl;
                exit(0);
            break;
            case 's':
                cout << syntax << endl;
                exit(0);
            break;
            default:
                cout << "Wrong syntax.\nType \"./simple_db -h\" for help." << endl;
                exit(1);
            break;
        }
    }
    else{
        cout << "Wrong syntax.\nType \"./simple_db -h\" for help." << endl;
        exit(1);
    }
    return 0;
}