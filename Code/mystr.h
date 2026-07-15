#ifndef MYSTR_H
#define MYSTR_H
#include <iostream>
using namespace std;

class my_str
{
    int len;
    int cap;
    char* cs;

public:
    void regrow();
    void copy(const my_str& temp);
    void itos(int num);
    int length_str(const char* s);
    my_str();
    my_str(char ch);
    my_str(const char* p);
    my_str(const char* temp, int size);
    my_str(int num);
    my_str(const my_str& temp);
    my_str& operator=(const my_str& temp);
    bool operator==(const my_str& other);
    int get_length();
    void replace_first(char ch);
    int stoi();
    void trim();
    char operator[](int i) const;
    char& operator[](int i);
    bool equal(my_str& str2);
    bool is_greater(my_str& str2);
    bool is_less(my_str& str2);
    my_str* split(char delim, int& count);
    my_str* tokenization(const char* delim, int& count);
    my_str concat(const my_str& str2);
    my_str& operator +=(const my_str& str2);
    int* sub_searching(char* sub, int& count);
    int find_first(char ch);
    int find_first(const char* sub);
    int find_last(char ch);
    int find_last(const char* sub);
    int* find_all(char ch, int& count);
    int* find_all(const char* sub, int& count);
    void remove_char(int idx);
    void insert_at(int idx, char ch);
    void insert_at(int idx, const my_str& sub);
    void remove_first(char ch);
    void remove_last(char ch);
    void remove_all(char ch);
    void clear();
    void to_lower();
    void to_upper();
    void print();
    friend ostream& operator<<(ostream& out, const my_str& obj);
    const char* get_cs();
    const char* get_cs() const;
    ~my_str();
};

#endif