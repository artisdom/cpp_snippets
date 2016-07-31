#include <iostream>
#include <string>
#include <vector>

using namespace std;

const string CASE_GROUP_SEPERATOR = "/";
const string CASE_DEVICE_SEPERATOR = ":";
const string CASE_INDEX_SEPERATOR = ",";
const string CASE_INDEX_RANGE_SEPERATOR = "-";

struct test_vector {
    int counter;
    vector<int> device_index;
    vector<int> test_index;
};

bool parse_case_index_range(vector<int>& index_vector, string str)
{
    //string str = "5-20";

    string::size_type pos = 0;
    string::size_type pos2 = 0;

    pos = str.find(CASE_INDEX_RANGE_SEPERATOR);

    if (pos != string::npos) {

        string str2 = str.substr(0, pos);
        string str3 = str.substr(pos + 1);

        int start = stoi(str2);
        int end = stoi(str3);

        for (int i = start; i <= end; i++) {
            index_vector.push_back(i);
        }

    } else {

        index_vector.push_back(stoi(str));

    }

    return true;
}

bool parse_string_by_seperator(vector<string>& str_output_vector, string str, string str_seperator)
{
    string::size_type pos = 0;
    string::size_type pos2 = 0;

    while (true) {

        pos2 = str.find(str_seperator, pos);

        if (pos2 != string::npos) {

            string str2 = str.substr(pos, pos2 - pos);
            str_output_vector.push_back(str2);

            pos = pos2 + str_seperator.size();

        } else {

            if (str.length() > pos) {
                string str2 = str.substr(pos, str.length() - pos);
                str_output_vector.push_back(str2);
            }

            break;
        }
    }

    return true;
}

bool parse_case_index(vector<int>& index_vector, string str)
{
    //string str = "0,1,1,2,2,3,4,5-7,5-7,9,10,11,21,";

    vector<string> index_str_vector;

    parse_string_by_seperator(index_str_vector, str, CASE_INDEX_SEPERATOR);

    for (string s : index_str_vector) {
        parse_case_index_range(index_vector, s);
    }

    return true;
}

bool parse_one_case(struct test_vector& t, string str)
{
    //string str = "10:0,1,1,2,2,3,4,5-7,5-7,9,10,11,21,";
    vector<int> index_vector;
    string seperator = CASE_DEVICE_SEPERATOR;
    
    string::size_type pos = 0;
    string::size_type pos2 = 0;

    pos = str.find(seperator);

    string device_id_str = str.substr(0, pos);
    cout << "device_id_str: " << device_id_str << endl;

    string index_str = str.substr(pos + seperator.size());
    cout << "index_str: " << index_str << endl;

    int device_id = stoi(device_id_str);

    parse_case_index(index_vector, index_str);

    for (int i : index_vector) {
        t.device_index.push_back(device_id);
        t.test_index.push_back(i);
    }

    return true;
}

bool parse_case_str(struct test_vector& t, string str) {
    
    vector<string> case_vector;

    parse_string_by_seperator(case_vector, str, CASE_GROUP_SEPERATOR);

    for (string s : case_vector) {
        parse_one_case(t, s);
    }

}

void dump_test_vector(struct test_vector& t) {
    cout << "counter: " << t.counter << endl;

    for (int i : t.device_index) {
        cout << i << " ";
    }
    cout << endl;

    for (int i : t.test_index) {
        cout << i << " ";
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    string str = "7:0,1,1,2,2,3,4/8:0,1,1,3,3,5-7/9:0,1,2,2,5-7,5-7,/";
    struct test_vector t;
    t.counter = 10;

    parse_case_str(t, str);

    dump_test_vector(t);
    return 0;
}
