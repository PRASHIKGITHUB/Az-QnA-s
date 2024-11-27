#include <bits/stdc++.h>
using namespace std;
class StringFunctions //Interface class
{
public:
    virtual string Edit(string a, string b) = 0;//pure virtual fuctions
};

class AppendFunction :public StringFunctions{
    public:
    string Edit(string a,string b) override{
        return a+b;
    }
};

class ReverseAppend :public StringFunctions{
    public:
    string Edit(string a,string b) override{
        return b+a;
    }
};

class Costom :public StringFunctions{
    public:
    string Edit(string a,string b) override{
        return b+a+b;
    }
};


class TextEditor//without changing this class we are extending it's functionality
{
public:
    string Format(string str1, string str2,StringFunctions& func)
    {
        return func.Edit(str1,str2);
    }
};

// if i want to add strings in such a manner then i need to modify the given Format function str1+str1+str2 but i dont want to do that

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    TextEditor editor;
    string a, b;
    cin >> a >> b;
    
    AppendFunction append_function;
    cout<<editor.Format(a,b,append_function)<<endl;

    ReverseAppend reverse_append_function;
    cout<<editor.Format(a,b,reverse_append_function)<<endl;

    Costom costom_append;
    cout<<editor.Format(a,b,costom_append)<<endl;

    return 0;
}