#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <map>
#include <cstddef>
#include <algorithm>
#include <list>

int main() {

      std::vector<int> vec {10,20,30};

      std::string str = "Vasanth";

      std::list<int> lst {1,2,3};

      std::map<int, std::string> mp {
           
            {1, "one"},
            {2, "two"}
      };

      std::cout 
         << "\n================== Vector =====================\n";

      std::cout << "Stack itself Address - &vec          : "
                << &vec  // seperate stack inside obj address
                << '\n';
                
      std::cout << "Stack inside Ref Address - vec.data()    : "
                << vec.data() // stack inside obj ref value address
                << '\n';          

      std::cout 
         << "\n ================== STRING ===================\n";
         
      std::cout << "&str               : "
                << &str 
                << '\n';

      std::cout << "str.data()          : "
                << static_cast<const void*>(str.data())
                << '\n';
                
      std::cout 
         << "\n============= LIST =================\n";
         
         std::cout << "&lst            : "
                   << &lst
                   << '\n';

         std::cout << "First node value : "
                   << *lst.begin()
                   << '\n';   
                   
          std::cout 
             << "\n=============== MAP ===================\n";
             
           std::cout << "&mp           : "
                     << &mp
                     << '\n';
                     
           std::cout << "mp[1]          : "
                     << mp[1]
                     << '\n';    
                     

                   
}

/*

./a.out 

================== Vector =====================
Stack itself Address - &vec          : 0x7ffe33e8fd40
Stack inside Ref Address - vec.data()    : 0x5efe8d6522b0

 ================== STRING ===================
&str               : 0x7ffe33e8fdb0
str.data()          : 0x7ffe33e8fdc0

============= LIST =================
&lst            : 0x7ffe33e8fd60
First node value : 1

=============== MAP ===================
&mp           : 0x7ffe33e8fd80
mp[1]          : one
*/