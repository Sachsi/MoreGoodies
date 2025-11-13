#include <iostream>
#include <cstring>
#include <string>
std::string ToUpper(const std::string &str) ;
std::string ToLower(const std::string &str) ;

std::string combine(std::string pfirst, std::string plast){
    // the strings are null terminated, so wie have to add character extra to avoid those crash
   // char *fullName = new char(strlen(pfirst) + strlen(plast) +1);
   std::string fullName = pfirst + plast;
    //strcpy(fullName, pfirst);
//    strcat(fullName, plast);
    return fullName;
}
void Character(void)
{
    std::string first;
    std::string  last;
    std::cin >>first;
    std::cin >>last;
    auto fullName =  combine(first, last);
    std::cout << fullName << std::endl;
    // Programm crashed in Debug mode
    //delete[] fullName;
}
std::string ToUpper(const std::string &str) 
{
    char *temp= new char(str.length() +1); 
    strcpy(temp, str.c_str());
   while(*temp)
     {
        *temp = toupper((unsigned char) *temp);
        temp++;
    }
    //strcat(temp, "\n");
    temp -= str.length();
    std::cout << temp << std::endl;
    
    return temp;
}
std::string ToLower(const std::string &str) 
{
    char *temp = new char(str.length() + 1);
    strcpy(temp, str.c_str());
    while(*temp){
        *temp = tolower((unsigned char)*temp);
        temp++;
    }
    temp -= str.length();
    std::cout << temp << std::endl;
    return temp;
}

int main(void)
{
    //Character();
    //init and assign
    std::string s = "Hello";
    std::string d{"directe Initializing"};
    std::string first;
    std::string last;
    std::cin >> first;
    std::cin >> last;
    //Access
    s[0] = 'W';
    char x = s[0];
    std::cout << "lower L or upper U case"<< std::endl;
    
    std::string enter;
    std::cin >> enter;
    
    if(enter[0] == 'L')
        ToLower(d);
    else if(enter[0] == 'U')
        ToUpper(d);
    
    //std::getline(std::cin, s);
    //Size
    auto le = s.length();
    std::cout << "lenght is: " << le << std::endl;
    //Insierd & Cancaterad
    
    s = first + last;
    s += last;
     std::cout << s << std::endl;
    //Compain
    if( first == last)
         std::cout << "Its the same " << std::endl;
    //Removal
    s.erase(5);
     std::cout << s << std::endl;
    //Search
    auto y = s.find("Tobi");
     std::cout << y << std::endl;
}