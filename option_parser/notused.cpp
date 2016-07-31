/*
-c 0:0,1,2,3,4/1:0,1,2,3,4/2:0,1,3-5/3:0,1,2,3,4,6-10/ -n 10
-c 0:0,1,1,2,2,3,4/1:0,1,1,3,3,5-7/1:0,1,2,2,5-7,5-7 -n 10 -c 0:1,2,3 -n 10
-c 0:0,1,2,3,4/1:0,1,2,3,4/

-c 0:0,1,2,3,4@1:0,1,2,3,4@2:0,1,3-5@3:0,1,2,3,4,6-10@ -n 10
-c 0:0,1,1,2,2,3,4@1:0,1,1,3,3,5-7@1:0,1,2,2,5-7,5-7 -n 10 -c 0:1,2,3 -n 10
-c 0:0,1,2,3,4@1:0,1,2,3,4@

-c 0:0,1,2,3,4#1:0,1,2,3,4#2:0,1,3-5#3:0,1,2,3,4,6-10# -n 10
-c 0:0,1,1,2,2,3,4#1:0,1,1,3,3,5-7#1:0,1,2,2,5-7,5-7 -n 10 -c 0:1,2,3 -n 10
-c 0:0,1,2,3,4#1:0,1,2,3,4#

-c 0:0,1,2,3,4!1:0,1,2,3,4!2:0,1,3-5!3:0,1,2,3,4,6-10! -n 10
-c 0:0,1,1,2,2,3,4!1:0,1,1,3,3,5-7!1:0,1,2,2,5-7,5-7 -n 10 -c 0:1,2,3 -n 10
-c 0:0,1,2,3,4!1:0,1,2,3,4!

-c 0:0,1,2,3,4+1:0,1,2,3,4+2:0,1,3-5+3:0,1,2,3,4,6-10+ -n 10
-c 0:0,1,1,2,2,3,4+1:0,1,1,3,3,5-7+1:0,1,2,2,5-7,5-7 -n 10 -c 0:1,2,3 -n 10
-c 0:0,1,2,3,4+1:0,1,2,3,4+

-c 0:0,1,2,3,4?1:0,1,2,3,4?2:0,1,3-5?3:0,1,2,3,4,6-10? -n 10
-c 0:0,1,1,2,2,3,4?1:0,1,1,3,3,5-7?1:0,1,2,2,5-7,5-7 -n 10 -c 0:1,2,3 -n 10
-c 0:0,1,2,3,4?1:0,1,2,3,4?

-c 0:0,1,2,3,4*1:0,1,2,3,4*2:0,1,3-5*3:0,1,2,3,4,6-10* -n 10
-c 0:0,1,1,2,2,3,4*1:0,1,1,3,3,5-7*1:0,1,2,2,5-7,5-7 -n 10 -c 0:1,2,3 -n 10
-c 0:0,1,2,3,4*1:0,1,2,3,4*

-c 0:0,1,2,3,4~1:0,1,2,3,4~2:0,1,3-5~3:0,1,2,3,4,6-10~ -n 10
-c 0:0,1,1,2,2,3,4~1:0,1,1,3,3,5-7~1:0,1,2,2,5-7,5-7 -n 10 -c 0:1,2,3 -n 10
-c 0:0,1,2,3,4~1:0,1,2,3,4~

*/


if (it == options.end()) {
    value = '1'; //default number of test to run is 1
    m_counter_vector.push_back(value);
} else if (!it->compare(COUNTER_OPT)) {

} else {
    value = '1'; //default number of test to run is 1
    m_counter_vector.push_back(value);
}

for (string s : options) {
    cout << s << '|' << '\n';
}


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
                        m_counter_vector.push_back(value);
                        printf("counter: %s\n", value.c_str());
                    }

                } else {
                    printf("no counter value, specified, use default counter value: 1.\n");
                    
                    value = '1'; //default number of test to run is 1
                    m_counter_vector.push_back(value);

                    --it;
/*
                    if (it == options.end()) {
                        printf("parsing parameter finished.\n");
                        return true;
                    } else {
                        printf("parsing parameter finished.\n");
                        return true;
                    }
*/
                }
