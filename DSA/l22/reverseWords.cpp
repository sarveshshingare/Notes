#include <bits/stdc++.h>

std::string reverseW(std::string word)
{
    int start = 0, e = word.length() - 1;
    while (start <= e)
    {
        std::swap(word[start], word[e]);
        start++;
        e--;
    }
    return word;
}

std::string reverseWords(std::string str)
{

    int n = str.length();
    std::string word = "";
    std::string ans = "";

    for (int i = 0; i < n; i++)
    {
        if (str[i] == ' ')
        {
            ans += reverseW(word)+" ";
            word="";
        }
        else{

        word.push_back(str[i]);
        }
    }
    ans+=reverseW(word);
    return ans;
}

int main()
{
    std::string str;
    std::cout << "enter your name:";
    std::getline(std::cin,str);
    std::cout << reverseWords(str);

    return 0;
}