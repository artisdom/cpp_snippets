#include <iostream>
#include <vector>
#include "Option.h"

using namespace std;

/*

-c 0:0,1,2,3,4/1:0,1,2,3,4/2:0,1,3-5/3:0,1,2,3,4,6-10/ -n 10
-c 0:0,1,1,2,2,3,4/1:0,1,1,3,3,5-7/1:0,1,2,2,5-7,5-7 -n 10 -c 0:1,2,3 -n 10
-c 0:0,1,2,3,4/1:0,1,2,3,4/

-a 127.0.0.1 -p 60003 -c 1 -n 10
-a 0.0.0.0 -c 60003 -t 60004
-a 0.0.0.0 -c 60003 -t 60004 --g6ip 192.168.3.100 --g6coreport 9000 --g6tmsport 60003

$DIR/SocketTalClient -a 127.0.0.1 -p 60003 -c 1 -n 10
$DIR/SocketTalG7 -a 0.0.0.0 -c 60003 -t 60004
$DIR/SocketTalG6 -a 0.0.0.0 -c 60003 -t 60004 --g6ip 192.168.3.100 --g6coreport 9000 --g6tmsport 60003

./main -c 0:0,1,1,2,2,3,4/1:0,1,1,3,3,5-7/1:0,1,2,2,5-7,5-7 -n 10 -c 0:1,2,3/0:0,1,2,3,4/1:0,1,2,3,4/ -n 20 -a 192.168.3.200 -p 60003 -c 1 -n 30 -c 2 -n 40 -c 3 -n 50 -c 4 -n 60

-c 0:0,1,1,2,2,3,4/1:0,1,1,3,3,5-7/1:0,1,2,2,5-7,5-7 -n 10 -c 0:1,2,3/0:0,1,2,3,4/1:0,1,2,3,4/ -n 20 -c 1 -n 30 -c 2 -n 40 -c 3 -n 50 -c 4 -n 60

*/

int main(int argc, char *argv[])
{
    vector<string> options;

    for (int i = 0; i < argc; i++) {
        options.push_back(argv[i]);
    }

    Option option(argc, argv);

    //option.dumpOption();

    if (option.processOption()) {
        printf("processOption success.\n");
        option.dumpValue();
    } else {
        printf("processOption failed.\n");
    }
    return 0;
}
