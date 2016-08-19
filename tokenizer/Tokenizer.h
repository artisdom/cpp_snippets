#ifndef TOKENIZER_H_
#define TOKENIZER_H_

//#include "core/Defines.h"
#include <string>
#include <cstdint>

using namespace std;

static const string DELIMITERS(" \t\n\r");

class Tokenizer {
public:

    Tokenizer(const string& text) {
        _string = text;
        _offset = 0;
        _delimiters = DELIMITERS;
    }

    Tokenizer(const string& text, const string& delimiters) {
        _string = text;
        _offset = 0;
        _delimiters = delimiters;
    }

    ~Tokenizer() {

    }

    bool nextToken() {

        return nextToken(_delimiters);

    }

    bool nextToken(const std::string& delimiters) {

        size_t i = _string.find_first_not_of(delimiters, _offset);

        if (string::npos == i) {
            _offset = _string.length();
            return false;
        }

        size_t j = _string.find_first_of(delimiters, i);

        if (string::npos == j) {
            _token = _string.substr(i);
            _offset = _string.length();
            return true;
        }

        _token = _string.substr(i, j - i);
        _offset = j;
        return true;

    }

    const string getToken() const {

        return _token;

    }

private:
    string _string;
    size_t _offset;
    string _token;
    string _delimiters;
};

#endif /* TOKENIZER_H_ */
