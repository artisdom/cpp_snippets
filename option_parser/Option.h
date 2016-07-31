#ifndef OPTION_H
#define OPTION_H

#include <vector>
#include <cstdlib>

using namespace std;

class Option {

public:

    Option() {}

    Option(int argc, char *argv[]) {

        initOption(argc, argv);

    }

    ~Option() {}

    int initOption(int argc, char *argv[]) {

        for (int i = 1; i < argc; i++) {
            options.push_back(argv[i]);
        }

        return 0;
    }

    void dumpOption() {

        for (string s : options) {
            cout << s << '|' << '\n';
        }

    }

    string getAddress() {
        return m_address;
    }

    string getPort() {
        return m_port;
    }

    string getCounter() {
        return "";
        //return m_counter;
    }

    bool processOption() {

        bool valid = true;
        bool address_found = false;
        bool port_found = false;
        bool case_found = false;

        for (vector<string>::iterator it = options.begin(); it != options.end(); ++it) {
            cout << *it << '|' << '\n';

            if (!it->compare(ADDRESS_OPT)) {

                if (address_found) {
                    printf("duplicated address parameter.\n");
                    return false;
                }

                ++it;

                if (it == options.end()) {
                    printf("missing address value, end of parameters.\n");
                    return false;
                }

                string value = *it;
                
                if (value[0] == '-') {
                    printf("missing address value.\n");
                    return false;
                } else {
                    address_found = true;
                    m_address = *it;
                    printf("address: %s\n", m_address.c_str());
                }

            } else if (!it->compare(PORT_OPT)) {

                if (port_found) {
                    printf("duplicated port parameter.\n");
                    return false;
                }

                ++it;

                if (it == options.end()) {
                    printf("missing port value, end of parameters.\n");
                    return false;
                }

                string value = *it;
                
                if (value[0] == '-') {
                    printf("missing port value.\n");
                    return false;
                } else {
                    port_found = true;
                    m_port = *it;
                    printf("port: %s\n", m_port.c_str());
                }

            } else if (!it->compare(CASE_OPT)) {

                ++it;

                if (it == options.end()) {
                    printf("missing case index value, end of parameters.\n");
                    return false;
                }

                string value = *it;
                
                if (value[0] == '-') {
                    printf("missing case index value.\n");
                    return false;
                } else {
                    case_found = true;
                    m_case_values.push_back(*it);
                    printf("case index: %s\n", value.c_str());
                }

                ++it;

                if (!it->compare(COUNTER_OPT)) {

                    ++it;

                    if (it == options.end()) {
                        printf("missing counter value, end of parameters.\n");
                        return false;
                    }

                    string value = *it;
                
                    if (value[0] == '-') {
                        printf("missing counter value.\n");
                        return false;
                    } else {
                        m_counter_values.push_back(value);
                        printf("counter: %s\n", value.c_str());
                    }

                } else {
                    printf("no counter value, specified, use default counter value: 1.\n");
                    
                    value = '1'; //default number of test to run is 1
                    m_counter_values.push_back(value);

                    --it;
                }

            } else if (!it->compare(COUNTER_OPT)) {

                printf("duplicated counter parameter: %s\n", it->c_str());
                return false;

            } else {
                printf("unknown parameter: %s\n", it->c_str());
                return false;
            }
        }

        if (!address_found) {
            printf("missing address parameter.\n");
            return false;
        } else if (!port_found) {
            printf("missing port parameter.\n");
            return false;
        } else if (!case_found) {
            printf("missing test case parameter.\n");
            return false;
        } else {
            return true;
        }

    }

    void dumpValue() {
        printf("address: %s\n", m_address.c_str());
        printf("port: %s\n", m_port.c_str());

        printf("case:\n");
        for (string s : m_case_values) {
            cout << s << '|' << '\n';
        }

        printf("counter:\n");
        for (string s : m_counter_values) {
            cout << s << '|' << '\n';
        }

    }

private:

    vector<string> options;

    string m_address;
    string m_port;
    vector<string> m_case_values;
    vector<string> m_counter_values;

    struct test_vector {
        int counter;
        vector<int> device_index;
        vector<int> test_index;
    };

    vector<struct test_vector> m_test_vectors;

    bool processCaseValue() {
        for (int i = 0; (i < m_case_values.size()) && (i < m_counter_values.size()); i++) {

            struct test_vector t;
            t.counter = stoi(m_counter_values[i]);
            
        }
    }
    


    const string ADDRESS_OPT = "-a";
    const string PORT_OPT = "-p";
    const string CASE_OPT = "-c";
    const string COUNTER_OPT = "-n";

};

#endif /* OPTION_H */
