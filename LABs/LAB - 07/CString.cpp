#include <iostream>
#include <cstring>

using namespace std;

class CString {
private:
    char *str;
    int size;

public:
    CString();
    CString(char c);
    CString(const char *s);
    CString(const CString &);
    ~CString();
    int getLength();
    void display() const;
    int find(char *substr, int start = 0) const;
    int find(char ch, int start = 0) const;
    int insert(int index, const char *substr);
    int insert(int index, const char ch);
    CString left(int count) const;
    CString right(int count) const;
    int remove(int index, int count = 1);
    int remove(char ch);
    void replace(char New);
    int replace(char oldCh, char New);
    int replace(char *oldStr, char *newStr);
    void trim();
    void trimLeft();
    void trimRight();
    void makeUpper();
    void makeLower();
    void reverse();
    void reSize(int add);
    CString concat(const CString &s2) const;
    void concatEqual(const CString &s2);
    void concatEqual(char *s2);
    int isEqual(const CString &s2) const;
    int isEqual(char *s2) const;
    void input();
    char &at(int index);
    int isEmpty();
};

CString::CString()
{
    str = nullptr;
    size = 0;
}

CString::CString(char c)
{
    size = 2;
    str = new char[size];

    str[0] = c;
    str[1] = '\0';
}

CString::CString(const char *s)
{
    if (s == nullptr) {
        str = nullptr;
        size = 0;
    } else {
        size = strlen(s) + 1;
        str = new char[size];
        strcpy(str, s);
    }
}

CString::CString(const CString & obj)
{
    if (obj.str == nullptr) {
        str = nullptr;
        size = 0;
    } else {
        size = obj.size;
        str = new char[size];
        strcpy(str, obj.str);
    }
}

CString::~CString()
{
    delete[] str;
}

int CString::getLength()
{
    if (!str) {
        return 0;
    }
    return strlen(str);
}

void CString::display() const
{
    if (str) {
        cout << str;
    } else {
        cout << "(null)";
    }
}

int CString::find(char *substr, int start) const
{
    if (!str || !substr) {
        return -1;
    }

    int len1 = strlen(str);
    int len2 = strlen(substr);

    for (int i = start; i <= len1 - len2; i++) {
        int j = 0;

        while (j < len2 && str[i + j] == substr[j]) {
            j++;
        }

        if (j == len2) {
            return i;
        }
    }

    return -1;
}

int CString::find(char ch, int start) const
{
    if (!str) {
        return -1;
    }

    int len = strlen(str);

    for (int i = start; i < len; i++) {
        if (str[i] == ch) {
            return i;
        }
    }

    return -1;
}

int CString::insert(int index, const char *substr)
{
    if (!substr) {
        return -1;
    }
    if (!str) {
        int len2 = strlen(substr);
        size = len2 + 1;
        str = new char[size];
        strcpy(str, substr);
        return len2;
    }

    int len1 = strlen(str);
    int len2 = strlen(substr);

    if (index < 0) {
        index = 0;
    }
    if (index > len1) {
        index = len1;
    }

    char *newStr = new char[len1 + len2 + 1];

    for (int i = 0; i < index; i++) {
        newStr[i] = str[i];
    }

    for (int i = 0; i < len2; i++) {
        newStr[index + i] = substr[i];
    }

    for (int i = index; i < len1; i++) {
        newStr[len2 + i] = str[i];
    }

    newStr[len1 + len2] = '\0';

    delete[] str;
    str = newStr;
    size = len1 + len2 + 1;

    return len1 + len2;
}

int CString::insert(int index, const char ch)
{
    if (!str) {
        size = 2;
        str = new char[size];
        str[0] = ch;
        str[1] = '\0';
        return 1;
    }

    int len = strlen(str);

    if (index < 0) {
        index = 0;
    }
    if (index > len) {
        index = len;
    }

    char *newstr = new char[len + 2];

    for (int i = 0; i < index; i++) {
        newstr[i] = str[i];
    }

    newstr[index] = ch;

    for (int i = index; i < len; i++) {
        newstr[i + 1] = str[i];
    }

    newstr[len + 1] = '\0';

    delete[] str;

    str = newstr;
    size = len + 2;

    return len + 1;
}

CString CString::left(int count) const
{
    if (count <= 0 || !str) {
        return CString("");
    }

    int len = strlen(str);
    if (count > len) {
        count = len;
    }

    char *newstr = new char[count + 1];

    for (int i = 0; i < count; i++) {
        newstr[i] = str[i];
    }

    newstr[count] = '\0';

    CString result(newstr);
    delete[] newstr;

    return result;
}

CString CString::right(int count) const
{
    if (count <= 0 || !str) {
        return CString("");
    }

    int len = strlen(str);
    if (count > len) {
        count = len;
    }

    int start = len - count;

    char *newstr = new char[count + 1];

    for (int i = 0; i < count; i++) {
        newstr[i] = str[start + i];
    }

    newstr[count] = '\0';

    CString result(newstr);
    delete[] newstr;

    return result;
}

int CString::remove(int index, int count)
{
    if (!str) {
        return 0;
    }

    int len = strlen(str);

    if (index < 0 || index >= len) {
        return len;
    }
    if (count <= 0) {
        return len;
    }

    if (index + count > len) {
        count = len - index;
    }

    int newLen = len - count;
    char *newstr = new char[newLen + 1];

    for (int i = 0; i < index; i++) {
        newstr[i] = str[i];
    }

    for (int i = index + count; i < len; i++) {
        newstr[i - count] = str[i];
    }

    newstr[newLen] = '\0';

    delete[] str;
    str = newstr;
    size = newLen + 1;

    return newLen;
}

int CString::remove(char ch)
{
    if (!str) {
        return 0;
    }

    int len = strlen(str);
    int removed = 0;

    char *newstr = new char[len + 1];
    int j = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] != ch) {
            newstr[j++] = str[i];
        } else {
            removed++;
        }
    }

    newstr[j] = '\0';

    delete[] str;
    str = newstr;
    size = j + 1;

    return removed;
}

void CString::replace(char New)
{
    if (!str) {
        return;
    }

    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        str[i] = New;
    }
}

int CString::replace(char oldCh, char New)
{
    if (!str) {
        return 0;
    }

    int len = strlen(str);
    int count = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] == oldCh) {
            str[i] = New;
            count++;
        }
    }

    return count;
}

int CString::replace(char *oldStr, char *newStr)
{
    if (!str || !oldStr || !newStr) {
        return 0;
    }

    int len = strlen(str);
    int oldLen = strlen(oldStr);
    int newLen = strlen(newStr);

    if (oldLen == 0) {
        return 0;
    }

    int count = 0;
    for (int i = 0; i <= len - oldLen; i++) {
        int j = 0;
        while (j < oldLen && str[i + j] == oldStr[j]) {
            j++;
        }
        if (j == oldLen) {
            count++;
            i += oldLen - 1;
        }
    }

    if (count == 0) {
        return 0;
    }

    int resultLen = len + count * (newLen - oldLen);
    char *result = new char[resultLen + 1];

    int ri = 0;
    for (int i = 0; i < len;) {
        bool matched = false;
        if (i <= len - oldLen) {
            int j = 0;
            while (j < oldLen && str[i + j] == oldStr[j]) {
                j++;
            }
            if (j == oldLen) {
                for (int k = 0; k < newLen; k++) {
                    result[ri++] = newStr[k];
                }
                i += oldLen;
                matched = true;
            }
        }
        if (!matched) {
            result[ri++] = str[i++];
        }
    }

    result[ri] = '\0';

    delete[] str;
    str = result;
    size = resultLen + 1;

    return count;
}

void CString::trim()
{
    trimLeft();
    trimRight();
}

void CString::trimLeft()
{
    if (!str) {
        return;
    }

    int len = strlen(str);
    int start = 0;

    while (start < len && str[start] == ' ') {
        start++;
    }

    if (start == 0) {
        return;
    }

    int newLen = len - start;
    char *newstr = new char[newLen + 1];

    for (int i = 0; i < newLen; i++) {
        newstr[i] = str[start + i];
    }

    newstr[newLen] = '\0';

    delete[] str;
    str = newstr;
    size = newLen + 1;
}

void CString::trimRight()
{
    if (!str) {
        return;
    }

    int len = strlen(str);
    int end = len - 1;

    while (end >= 0 && str[end] == ' ') {
        end--;
    }

    if (end == len - 1) {
        return;
    }

    int newLen = end + 1;
    char *newstr = new char[newLen + 1];

    for (int i = 0; i < newLen; i++) {
        newstr[i] = str[i];
    }

    newstr[newLen] = '\0';

    delete[] str;
    str = newstr;
    size = newLen + 1;
}

void CString::makeUpper()
{
    if (!str) {
        return;
    }

    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
}

void CString::makeLower()
{
    if (!str) {
        return;
    }

    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
}

void CString::reverse()
{
    if (!str) {
        return;
    }

    int len = strlen(str);

    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

void CString::reSize(int add)
{
    if (add <= 0) {
        return;
    }

    int oldLen = 0;
    if (str) {
        oldLen = strlen(str);
    }

    int newSize = size + add;
    char *newstr = new char[newSize];

    if (str) {
        strcpy(newstr, str);
        delete[] str;
    } else {
        newstr[0] = '\0';
    }

    str = newstr;
    size = newSize;
}

CString CString::concat(const CString &s2) const
{
    if (!str && !s2.str) {
        return CString("");
    }
    if (!str) {
        return CString(s2.str);
    }
    if (!s2.str) {
        return CString(str);
    }

    int len1 = strlen(str);
    int len2 = strlen(s2.str);

    char *newstr = new char[len1 + len2 + 1];
    strcpy(newstr, str);
    strcat(newstr, s2.str);

    CString result(newstr);
    delete[] newstr;

    return result;
}

void CString::concatEqual(const CString &s2)
{
    if (!s2.str) {
        return;
    }

    if (!str) {
        size = strlen(s2.str) + 1;
        str = new char[size];
        strcpy(str, s2.str);
        return;
    }

    int len1 = strlen(str);
    int len2 = strlen(s2.str);

    char *newstr = new char[len1 + len2 + 1];
    strcpy(newstr, str);
    strcat(newstr, s2.str);

    delete[] str;
    str = newstr;
    size = len1 + len2 + 1;
}

void CString::concatEqual(char *s2)
{
    if (!s2) {
        return;
    }

    if (!str) {
        size = strlen(s2) + 1;
        str = new char[size];
        strcpy(str, s2);
        return;
    }

    int len1 = strlen(str);
    int len2 = strlen(s2);

    char *newstr = new char[len1 + len2 + 1];
    strcpy(newstr, str);
    strcat(newstr, s2);

    delete[] str;
    str = newstr;
    size = len1 + len2 + 1;
}

int CString::isEqual(const CString &s2) const
{
    if (!str && !s2.str) {
        return 0;
    }
    if (!str) {
        return -1;
    }
    if (!s2.str) {
        return 1;
    }

    return strcmp(str, s2.str);
}

int CString::isEqual(char *s2) const
{
    if (!str && !s2) {
        return 0;
    }
    if (!str) {
        return -1;
    }
    if (!s2) {
        return 1;
    }

    return strcmp(str, s2);
}

void CString::input()
{
    char buffer[1000];
    cin.getline(buffer, 1000);

    delete[] str;

    size = strlen(buffer) + 1;
    str = new char[size];
    strcpy(str, buffer);
}

char& CString::at(int index)
{
    return str[index];
}

int CString::isEmpty()
{
    if (!str || strlen(str) == 0) {
        return 0;
    } else {
        return 1;
    }
}

int main()
{
    cout << "===== Constructors =====" << endl;
    CString obj1;
    CString obj2('A');
    CString obj3("Hello World");
    CString obj4(obj3);

    cout << endl;

    cout << "===== getLength =====" << endl;
    cout << "Length of obj3: " << obj3.getLength() << endl;

    cout << endl;

    cout << "===== display =====" << endl;
    cout << "obj3: "; obj3.display(); cout << endl;

    cout << endl;

    cout << "===== find (substring) =====" << endl;
    char sub1[] = "World";
    char sub2[] = "Hello";
    char sub3[] = "ABC";
    cout << "Index of 'World' in obj3: " << obj3.find(sub1) << endl;
    cout << "Index of 'Hello' in obj3: " << obj3.find(sub2) << endl;
    cout << "Index of 'ABC' in obj3: " << obj3.find(sub3) << endl;
    cout << "Find 'World' from index 3: " << obj3.find(sub1, 3) << endl;

    cout << endl;

    cout << "===== find (character) =====" << endl;
    cout << "Index of 'o': " << obj3.find('o') << endl;
    cout << "Index of 'W': " << obj3.find('W') << endl;
    cout << "Index of 'z': " << obj3.find('z') << endl;
    cout << "Index of 'o' from 5: " << obj3.find('o', 5) << endl;

    cout << endl;

    cout << "===== insert (substring) =====" << endl;
    CString obj5("Hello");
    cout << "Before insert: "; obj5.display(); cout << endl;
    int newLen = obj5.insert(5, " World");
    cout << "After insert: "; obj5.display(); cout << endl;
    cout << "New length: " << newLen << endl;

    cout << endl;

    cout << "===== insert (character) =====" << endl;
    CString obj6("Hello");
    cout << "Before insert: "; obj6.display(); cout << endl;
    newLen = obj6.insert(5, '!');
    cout << "After insert: "; obj6.display(); cout << endl;
    cout << "New length: " << newLen << endl;

    cout << endl;

    cout << "===== left =====" << endl;
    CString obj7("Hello World");
    CString leftPart = obj7.left(5);
    cout << "Left 5 of 'Hello World': "; leftPart.display(); cout << endl;

    cout << endl;

    cout << "===== right =====" << endl;
    CString rightPart = obj7.right(5);
    cout << "Right 5 of 'Hello World': "; rightPart.display(); cout << endl;

    cout << endl;

    cout << "===== remove (index, count) =====" << endl;
    CString obj8("Hello World");
    cout << "Before remove: "; obj8.display(); cout << endl;
    newLen = obj8.remove(5, 6);
    cout << "After remove(5,6): "; obj8.display(); cout << endl;
    cout << "New length: " << newLen << endl;

    cout << endl;

    cout << "===== remove (character) =====" << endl;
    CString obj9("Hello World");
    cout << "Before remove: "; obj9.display(); cout << endl;
    int removed = obj9.remove('l');
    cout << "After remove 'l': "; obj9.display(); cout << endl;
    cout << "Characters removed: " << removed << endl;

    cout << endl;

    cout << "===== replace (fill) =====" << endl;
    CString obj10("Hello");
    cout << "Before replace: "; obj10.display(); cout << endl;
    obj10.replace('*');
    cout << "After replace('*'): "; obj10.display(); cout << endl;

    cout << endl;

    cout << "===== replace (char, char) =====" << endl;
    CString obj11("Hello World");
    cout << "Before replace: "; obj11.display(); cout << endl;
    int rCount = obj11.replace('l', 'L');
    cout << "After replace 'l'->'L': "; obj11.display(); cout << endl;
    cout << "Replacements made: " << rCount << endl;

    cout << endl;

    cout << "===== replace (substr, substr) =====" << endl;
    CString obj12("Hello World Hello");
    cout << "Before replace: "; obj12.display(); cout << endl;
    char oldSub[] = "Hello";
    char newSub[] = "Hi";
    rCount = obj12.replace(oldSub, newSub);
    cout << "After replace 'Hello'->'Hi': "; obj12.display(); cout << endl;
    cout << "Replacements made: " << rCount << endl;

    cout << endl;

    cout << "===== trim =====" << endl;
    CString obj13("   Hello World   ");
    cout << "Before trim: ["; obj13.display(); cout << "]" << endl;
    obj13.trim();
    cout << "After trim: ["; obj13.display(); cout << "]" << endl;

    cout << endl;

    cout << "===== trimLeft =====" << endl;
    CString obj14("   Hello");
    cout << "Before trimLeft: ["; obj14.display(); cout << "]" << endl;
    obj14.trimLeft();
    cout << "After trimLeft: ["; obj14.display(); cout << "]" << endl;

    cout << endl;

    cout << "===== trimRight =====" << endl;
    CString obj15("Hello   ");
    cout << "Before trimRight: ["; obj15.display(); cout << "]" << endl;
    obj15.trimRight();
    cout << "After trimRight: ["; obj15.display(); cout << "]" << endl;

    cout << endl;

    cout << "===== makeUpper =====" << endl;
    CString obj16("Hello World");
    cout << "Before: "; obj16.display(); cout << endl;
    obj16.makeUpper();
    cout << "After makeUpper: "; obj16.display(); cout << endl;

    cout << endl;

    cout << "===== makeLower =====" << endl;
    obj16.makeLower();
    cout << "After makeLower: "; obj16.display(); cout << endl;

    cout << endl;

    cout << "===== reverse =====" << endl;
    CString obj17("Hello");
    cout << "Before: "; obj17.display(); cout << endl;
    obj17.reverse();
    cout << "After reverse: "; obj17.display(); cout << endl;

    cout << endl;

    cout << "===== reSize =====" << endl;
    CString obj18("Hello");
    cout << "Before reSize: "; obj18.display(); cout << endl;
    obj18.reSize(10);
    cout << "After reSize(10) - string preserved: "; obj18.display(); cout << endl;

    cout << endl;

    cout << "===== concat =====" << endl;
    CString obj19("Hello ");
    CString obj20("World");
    CString obj21 = obj19.concat(obj20);
    cout << "Concat result: "; obj21.display(); cout << endl;

    cout << endl;

    cout << "===== concatEqual (CString) =====" << endl;
    CString obj22("Hello ");
    CString obj23("World");
    obj22.concatEqual(obj23);
    cout << "After concatEqual: "; obj22.display(); cout << endl;

    cout << endl;

    cout << "===== concatEqual (char*) =====" << endl;
    CString obj24("Hello ");
    char appendStr[] = "World";
    obj24.concatEqual(appendStr);
    cout << "After concatEqual: "; obj24.display(); cout << endl;

    cout << endl;

    cout << "===== isEqual (CString) =====" << endl;
    CString obj25("Hello");
    CString obj26("Hello");
    CString obj27("World");
    cout << "obj25 vs obj26: " << obj25.isEqual(obj26) << " (0 = equal)" << endl;
    cout << "obj25 vs obj27: " << obj25.isEqual(obj27) << endl;

    cout << endl;

    cout << "===== isEqual (char*) =====" << endl;
    char cmpStr1[] = "Hello";
    char cmpStr2[] = "World";
    cout << "obj25 vs 'Hello': " << obj25.isEqual(cmpStr1) << " (0 = equal)" << endl;
    cout << "obj25 vs 'World': " << obj25.isEqual(cmpStr2) << endl;

    cout << endl;

    cout << "===== at =====" << endl;
    CString obj28("Hello");
    cout << "Character at index 0: " << obj28.at(0) << endl;
    cout << "Character at index 4: " << obj28.at(4) << endl;
    obj28.at(0) = 'J';
    cout << "After changing index 0 to 'J': "; obj28.display(); cout << endl;

    cout << endl;

    cout << "===== isEmpty =====" << endl;
    CString obj29;
    CString obj30("Hello");
    cout << "obj29 (empty) isEmpty: " << obj29.isEmpty() << " (0 = empty)" << endl;
    cout << "obj30 ('Hello') isEmpty: " << obj30.isEmpty() << " (nonzero = not empty)" << endl;

    cout << endl;

    cout << "===== input =====" << endl;
    CString obj31;
    cout << "Enter a string: ";
    obj31.input();
    cout << "You entered: "; obj31.display(); cout << endl;

    return 0;
}