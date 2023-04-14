#include "StringExtensions.hpp"

bool StringExtensions::Contains(std::string s1, std::string s2)
{
    return (s1.find(s2) != std::string::npos);
}

std::string StringExtensions::RemoveText(std::string text, std::string toRemove)
{
    int found = -1;

    do
    {
        found = text.find(toRemove, found+1);

        if(found != -1)
        {
            text = text.substr(0, found) + text.substr(found+toRemove.length());
        }

    } while (found != -1);
    
    return text;
}

std::vector<std::string> StringExtensions::Split(std::string text, std::string delimiter)
{
    std::vector<std::string> l;

    char *dup = (char*) text.c_str(); // duplicating string as char*
    const char *delimiter_ptr = delimiter.c_str();
    char *ptr = strtok(dup, delimiter_ptr); 

    while (ptr != NULL)
    {
        // Convert to string and push on list
        std::string myString;
        myString.assign(ptr);
        l.push_back(myString); 

        ptr = strtok (NULL, delimiter_ptr); 
    }

    free(dup); // releasing duplicated string

    return l;
}