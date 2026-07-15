#include "mystr.h"

void my_str::regrow()
{
    char* temp = nullptr;
    cap = cap * 2;
    temp = new char[cap];
    for (int i = 0; i < len; i++)
        temp[i] = cs[i];

    delete[] cs;
    cs = temp;
}

void my_str::copy(const my_str& temp)
{
    len = temp.len;
    cap = temp.cap;
    if (cs)
    {
        delete[] cs;
    }
    cs = new char[cap];

    for (int i = 0; i < len; i++)
    {
        cs[i] = temp.cs[i];
    }

    cs[len] = '\0';
}

void my_str::itos(int num)
{
    int temp = num;
    len = 0;

    while (temp > 0)
    {
        len++;
        temp = temp / 10;
    }

    if (len == 0)
    {
        len = 1;
    }

    cap = len + 1;
    cs = new char[cap];

    for (int i = 0; i < len; i++)
    {
        int mod = num % 10;
        cs[len - i - 1] = mod + '0';
        num = num / 10;
    }

    cs[len] = '\0';
}

int my_str::length_str(const char* s)
{
    int count = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        count++;
    }

    return count;
}

my_str::my_str()
{
    len = 0;
    cap = len + 1;
    cs = new char[cap];
}

my_str::my_str(char ch)
{
    len = 1;
    cap = len + 1;
    cs = new char[cap];
    cs[0] = ch;
    cs[1] = '\0';
}

my_str::my_str(const char* p)
{
    len = length_str(p);
    cap = len + 1;
    cs = new char[cap];

    for (int i = 0; i < len; i++)
    {
        cs[i] = p[i];
    }

    cs[len] = '\0';
}

my_str::my_str(const char* temp, int size)
{
    len = size;
    cap = len + 1;
    cs = new char[cap];

    for (int i = 0; i < len; i++)
    {
        cs[i] = temp[i];
    }

    cs[len] = '\0';
}

my_str::my_str(int num)
{
    len = 0;
    cap = 0;
    cs = nullptr;
    itos(num);
}

my_str::my_str(const my_str& temp)
{
    len = temp.len;
    cap = temp.cap;
    cs = new char[cap];
    for (int i = 0; i <= len; i++) { // Include null terminator
        cs[i] = temp.cs[i];
    }
}

my_str& my_str::operator=(const my_str& temp)
{
    if (this != &temp) {
        char* new_cs = new char[temp.cap];
        for (int i = 0; i <= temp.len; i++) {
            new_cs[i] = temp.cs[i];
        }
        delete[] cs;
        cs = new_cs;
        len = temp.len;
        cap = temp.cap;
    }
    return *this;
}

int my_str::get_length()
{
    return len;
}

void my_str::replace_first(char ch)
{
    if (len > 0)
    {
        cs[0] = ch;
    }
}

int my_str::stoi()
{
    int num = 0;
    for (int i = 0;i < len;i++)
    {
        num = num * 10 + (cs[i] - '0');
    }

    return num;
}

void my_str::trim()
{
    char temp[40] = { '\0' };
    int count = 0;
    for (int i = 0;i < len;i++)
    {
        if ((cs[i] >= 65 && cs[i] <= 90) || (cs[i] >= 97 && cs[i] <= 122))
        {
            temp[count] = cs[i];
            count++;
        }
    }

    delete[] cs;
    len = count;
    if (cap <= len)
        cap = len + 1;

    cs = new char[cap];

    for (int i = 0;i < len;i++)
        cs[i] = temp[i];
}

char my_str::operator[](int i) const
{
    return cs[i];
}

char& my_str::operator[](int i)
{

    return cs[i];
}

bool my_str::equal(my_str& str2)
{
    if (len != str2.len)
        return false;

    char* temp1 = new char[len];
    char* temp2 = new char[str2.len];
    for (int i = 0;i < len;i++)
    {
        temp1[i] = cs[i];
    }

    for (int i = 0;i < str2.len;i++)
    {
        temp2[i] = str2.cs[i];
    }

    to_lower();
    str2.to_lower();

    for (int i = 0;i < len;i++)
    {
        if (cs[i] != str2.cs[i])
        {
            for (int i = 0;i < len;i++)
                cs[i] = temp1[i];

            for (int i = 0;i < str2.len;i++)
                str2.cs[i] = temp2[i];

            return false;
        }

        if (cs[i] == '\0' && str2.cs[i] == '\0')
        {
            for (int i = 0;i < len;i++)
                cs[i] = temp1[i];

            for (int i = 0;i < str2.len;i++)
                str2.cs[i] = temp2[i];

            return true;
        }
    }

    for (int i = 0;i < len;i++)
        cs[i] = temp1[i];

    for (int i = 0;i < str2.len;i++)
        str2.cs[i] = temp2[i];

    return true;
}

bool my_str::is_greater(my_str& str2)
{
    bool equality = equal(str2);
    if (equality)
        return false;

    else
    {
        char* temp1 = new char[len];
        char* temp2 = new char[str2.len];
        for (int i = 0;i < len;i++)
        {
            temp1[i] = cs[i];
        }

        for (int i = 0;i < str2.len;i++)
        {
            temp2[i] = str2.cs[i];
        }

        to_lower();
        str2.to_lower();

        for (int i = 0;i < len;i++)
        {
            if (cs[i] < str2.cs[i])
            {
                for (int i = 0;i < len;i++)
                    cs[i] = temp1[i];

                for (int i = 0;i < str2.len;i++)
                    str2.cs[i] = temp2[i];
                return false;
            }

            else if (cs[i] > str2.cs[i])
            {
                for (int i = 0;i < len;i++)
                    cs[i] = temp1[i];

                for (int i = 0;i < str2.len;i++)
                    str2.cs[i] = temp2[i];

                return true;
            }
        }
    }
}

bool my_str::is_less(my_str& str2)
{
    bool equality = equal(str2);
    if (equality)
        return false;

    else
    {
        char* temp1 = new char[len];
        char* temp2 = new char[str2.len];
        for (int i = 0;i < len;i++)
        {
            temp1[i] = cs[i];
        }

        for (int i = 0;i < str2.len;i++)
        {
            temp2[i] = str2.cs[i];
        }

        to_lower();
        str2.to_lower();
        for (int i = 0;i < len;i++)
        {
            if (cs[i] > str2.cs[i])
            {
                for (int i = 0;i < len;i++)
                    cs[i] = temp1[i];

                for (int i = 0;i < str2.len;i++)
                    str2.cs[i] = temp2[i];
                return false;
            }
            else if (cs[i] < str2.cs[i])
            {
                for (int i = 0;i < len;i++)
                    cs[i] = temp1[i];

                for (int i = 0;i < str2.len;i++)
                    str2.cs[i] = temp2[i];
                return true;
            }

        }
    }
}

my_str* my_str::split(char delim, int& count)
{
    count = 1;
    for (int i = 0; i < len; i++)
    {
        if (cs[i] == delim)
            count++;
    }

    my_str* result = new my_str[count];

    int res_idx = 0, idx = 0;

    for (int i = 0; i <= len; i++)
    {
        if (cs[i] == delim || cs[i] == '\0')
        {
            int res_len = i - idx;

            result[res_idx].cs = new char[res_len + 1];
            result[res_idx].len = res_len;
            result[res_idx].cap = res_len + 1;

            for (int j = 0; j < res_len; j++)
            {
                result[res_idx].cs[j] = cs[idx + j];
            }
            result[res_idx].cs[res_len] = '\0';

            res_idx++;
            idx = i + 1;
        }
    }

    return result;
}

my_str* my_str::tokenization(const char* delim, int& count)
{
    int delim_len = 0;
    delim_len = length_str(delim);
    count = 0;

    for (int i = 0; i <= len - delim_len; i++)
    {
        bool match = true;
        for (int j = 0; j < delim_len; j++)
        {
            if (cs[i + j] != delim[j])
            {
                match = false;
                break;
            }
        }

        if (match)
        {
            count++;
            i = i + delim_len - 1;
        }
    }
    count++;

    my_str* result = new my_str[count];

    int res_idx = 0;
    int start = 0;

    for (int i = 0; i <= len; i++)
    {
        bool match = false;
        if (i <= len - delim_len)
        {
            match = true;
            for (int j = 0; j < delim_len; j++)
            {
                if (cs[i + j] != delim[j])
                {
                    match = false;
                    break;
                }
            }
        }

        if (match || i == len)
        {
            int res_len = i - start;
            result[res_idx].cs = new char[res_len + 1];
            result[res_idx].len = res_len;
            result[res_idx].cap = res_len + 1;

            for (int j = 0; j < res_len; j++)
            {
                result[res_idx].cs[j] = cs[start + j];
            }
            result[res_idx].cs[res_len] = '\0';

            res_idx++;
            start = i + delim_len;
            i = i + delim_len - 1;
        }
    }
    return result;
}

my_str my_str::concat(const my_str& str2)
{
    my_str result;
    result.len = len + 1 + str2.len;     
    result.cap = result.len + 1;        
    result.cs = new char[result.cap];

    for (int i = 0; i < len; i++)
    {
        result.cs[i] = cs[i];
    }

    result.cs[len] = ' ';

    for (int i = 0; i < str2.len; i++)
    {
        result.cs[len + 1 + i] = str2.cs[i];
    }

    result.cs[result.len] = '\0';  
    return result;
}

my_str& my_str::operator +=(const my_str& str2)
{
    my_str temp = concat(str2);
    delete[] cs;
    len = temp.len;
    cap = temp.cap;
    cs = new char[cap];
    for (int i = 0;i < len;i++)
        cs[i] = temp.cs[i];

    return *this;
}

int* my_str::sub_searching(char* sub, int& count)
{
    int sub_len = 0;
    sub_len = length_str(sub);
    count = 0;

    for (int i = 0; i <= len - sub_len; i++)
    {
        bool match = true;
        for (int j = 0; j < sub_len; j++)
        {
            if (cs[i + j] != sub[j])
            {
                match = false;
                break;
            }
        }

        if (match)
        {
            count++;
            i = i + sub_len - 1;
        }
    }

    int* idxes = new int[count];
    int idx = 0;
    for (int i = 0; i <= len - sub_len; i++)
    {
        bool match = true;
        for (int j = 0; j < sub_len; j++)
        {
            if (cs[i + j] != sub[j])
            {
                match = false;
                break;
            }
        }

        if (match)
        {
            idxes[idx] = i;
            idx++;
        }
    }

    return idxes;
}

int my_str::find_first(char ch)
{
    for (int i = 0;i < len;i++)
    {
        if (cs[i] == ch)
            return i;
    }

    return -1;
}

int my_str::find_first(const char* sub)
{
    int length = length_str(sub);

    for (int i = 0; i < len; i++)
    {
        bool match = true;
        for (int j = 0; j < length; j++)
        {
            if (cs[i + j] != sub[j])
            {
                match = false;
                break;
            }
        }

        if (match)
        {
            return i;
        }
    }

    return -1;
}

int my_str::find_last(char ch)
{
    for (int i = len - 1;i >= 0;i--)
    {
        if (cs[i] == ch)
            return i;
    }

    return -1;
}

bool my_str::operator==(const my_str& other)
{
    if (len != other.len)
        return false;

    for (int i = 0;i < len;i++)
    {
        if (cs[i] != other.cs[i])
            return false;
    }

    return true;
}

int my_str::find_last(const char* sub)
{
    int length = length_str(sub);
    char* rev_sub = new char[length + 1];

    int idx = 0;
    for (int i = length - 1;i >= 0;i--)
    {
        rev_sub[idx] = sub[i];
        idx++;
    }

    for (int i = len - 1; i >= 0; i--)
    {
        bool match = true;
        for (int j = 0; j < length; j++)
        {
            if (cs[i + j] != rev_sub[j])
            {
                match = false;
                break;
            }
        }

        if (match)
        {
            return i;
        }
    }

    return -1;
}

int* my_str::find_all(char ch, int& count)
{

    for (int i = 0;i < len;i++)
    {
        if (cs[i] == ch)
            count++;
    }

    int* idx = new int[count];
    int index = 0;

    for (int i = 0;i < len;i++)
    {
        if (cs[i] == ch)
        {
            idx[index] = i;
            index++;
        }
    }

    return idx;
}

int* my_str::find_all(const char* sub, int& count)
{
    int length = length_str(sub);
    for (int i = 0; i < len; i++)
    {
        bool match = true;
        for (int j = 0; j < length; j++)
        {
            if (cs[i + j] != sub[j])
            {
                match = false;
                break;
            }
        }

        if (match)
        {
            count++;
        }
    }

    int* idx = new int[count];
    int indx = 0;

    for (int i = 0; i < len; i++)
    {
        bool match = true;
        for (int j = 0; j < length; j++)
        {
            if (cs[i + j] != sub[j])
            {
                match = false;
                break;
            }
        }

        if (match)
        {
            idx[indx] = i;
            indx++;
        }
    }

    return idx;
}

void my_str::remove_char(int idx)
{
    if (idx < 0 || idx >= len)
    {
        cout << "Invalid index.\n";
        return;
    }

    my_str temp;
    temp.len = len - 1;
    temp.cap = temp.len + 1;
    temp.cs = new char[temp.cap];

    int temp_idx = 0;


    for (int i = 0; i < len; i++)
    {
        if (i != idx)
        {
            temp.cs[temp_idx] = cs[i];
            temp_idx++;
        }
    }

    temp.cs[temp.len] = '\0';


    delete[] cs;
    len = temp.len;
    cap = temp.cap;
    cs = new char[cap];

    for (int i = 0;i < temp.len;i++)
        cs[i] = temp.cs[i];
}

void my_str::insert_at(int idx, char ch)
{
    if (idx > len || idx < 0)
    {
        cout << "Index out of bounds." << endl;
        return;
    }
    my_str temp;
    temp.len = len + 1;
    temp.cap = temp.len + 1;
    temp.cs = new char[temp.cap];
    int temp_idx = 0;
    for (int i = 0;i < len;i++)
    {
        if (i == idx)
        {
            temp.cs[temp_idx] = ch;
            temp_idx++;
        }

        else
        {
            temp.cs[temp_idx] = cs[i];
            temp_idx++;
        }
    }

    temp.cs[temp.len] = '\0';


    delete[] cs;
    len = temp.len;
    cap = temp.cap;
    cs = new char[cap];

    for (int i = 0;i < temp.len;i++)
        cs[i] = temp.cs[i];
}


void my_str::insert_at(int idx, const my_str& sub)
{
    if (idx > len || idx < 0)
    {
        cout << "Index out of bounds." << endl;
        return;
    }

    int new_len = len + sub.len;
    char* temp = new char[cap];

    for (int i = 0; i < len; i++)
        temp[i] = cs[i];

    delete[] cs;
    cs = new char[new_len + 1];

    int cs_idx = 0;

    for (int i = 0; i < idx; i++)
    {
        cs[cs_idx] = temp[i];
        cs_idx++;
    }

    for (int i = 0; i < sub.len; i++)
    {
        cs[cs_idx] = sub.cs[i];
        cs_idx++;
    }

    for (int i = idx; i < len; i++)
    {
        cs[cs_idx] = temp[i];
        cs_idx++;
    }

    cs[new_len] = '\0';
    len = new_len;
    cap = new_len + 1;

    delete[] temp;
}

void my_str::remove_first(char ch)
{
    int idx = find_first(ch);
    if (idx != -1)
    {
        remove_char(idx);
    }
}

void my_str::remove_last(char ch)
{
    int idx = find_last(ch);
    if (idx != -1)
    {
        remove_char(idx);
    }
}

void my_str::remove_all(char ch)
{
    int idx = find_first(ch);
    while (idx != -1)
    {
        remove_char(idx);
        idx = find_first(ch);
    }
}

void my_str::clear()
{ 
    if (cs)
    {
        delete[] cs;
        cs = nullptr;
    }
    len = 0;
    cap = 0;
    cs = nullptr;
}

void my_str::to_lower()
{
    for (int i = 0;i < len;i++)
    {
        if (cs[i] >= 65 && cs[i] <= 90)
            cs[i] = cs[i] + 32;
    }
}

void my_str::to_upper()
{
    for (int i = 0;i < len;i++)
    {
        if (cs[i] >= 97 && cs[i] <= 122)
            cs[i] = cs[i] - 32;
    }
}

void my_str::print()
{
    for (int i = 0; i < len; i++)
        cout << cs[i];
    cout << "\n";
}

ostream& operator<<(ostream& out, const my_str& obj)
{
    for(int i=0;i<obj.len;i++)
    out << obj.cs[i];
    return out;
}

const char* my_str::get_cs()
{
    return cs;
}

const char* my_str::get_cs() const
{
    return cs;
}

my_str::~my_str()
{
    if(cs)
    delete[] cs;
}