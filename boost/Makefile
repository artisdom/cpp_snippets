all:
	c++ -I /home/ezfenxi/w/cpp/boost_1_66_0/boost/ example.cpp -o example
	c++ -I /home/ezfenxi/w/cpp/boost_1_66_0/boost/ test_optional.cpp -o test_optional
	c++ -I /home/ezfenxi/w/cpp/boost_1_66_0/boost/ test_const_optional.cpp -o test_const_optional
	c++ -I /home/ezfenxi/w/cpp/boost_1_66_0/boost/ test_compare_optional.cpp -o test_compare_optional

test:
	echo 1 2 3 | ./example
	./test_optional
	./test_compare_optional
