 Operations and operators
In addition to specifying what values can be stored in a variable, the type of a
variable determines what operations we can apply to it and what they mean.
For example:
Click here to view code image
int age = −1;
cin >> age;                                               
// >> reads an integer into age
string name;
cin >> name;                                            
int a2 = age+2;                                        
string n2 = name + " Jr. ";                     
int a3 = age−2;                                       
string n3 = name − " Jr. ";                    
XX
// >> reads a string into name
// + adds integers
// + concatenates strings
// - subtracts integers
// error: - isn’t defined for strings
By “error” we mean that the compiler will reject a program trying to subtract
strings. The compiler knows exactly which operations can be applied to each
variable and can therefore prevent many mistakes. However, the compiler
doesn’t know which operations make sense to you for which values, so it will
happily accept legal operations that yield results that may look absurd to you.
For example:
age = −100;
It may be obvious to you that you can’t have a negative age (why not?) but
nobody told the compiler, so it’ll produce code for that definition.
Here is a table of useful operators for some common and useful types:
operation
bool
char
assignment
addition  
=
=
int
=
+
double
string
= =
+ 
concatenation    +
subtraction  
−
multiplication  
division  
remainder (modulo)  
increment by 1  
decrement by 1  
*
/
%  
++
−−
− 
* 
/ 
++ 
−− 
increment by n  +=n +=n 
add to end    +=
decrement by n  −=n −=n 
multiply and assign  *= *= 
divide and assign  /= /= 
remainder and assign  %=  
read from s into x s >> x s >> x s >> x s >> x s >> x
write x to s s << x s << x s << x s << x s << x
equals == == == == ==
not equal != != != != !=
greater than > > > > >
greater than or equal >= >= >= >= >=
less than < < < < <
less than or equal <= <= <= <= <=
A blank square indicates that an operation is not directly available for a type
(though there may be indirect ways of using that operation; see §2.9).
We’ll explain these operations, and more, as we go along. The key points
here are that there are a lot of useful operators and that their meaning tends to
be the same for similar types.
Let’s try an example involving floating-point numbers:
Click here to view code image
int main()          // simple program to exercise operators
{
         cout << "Please enter a floating−point value: ";
         double n = 0;
         cin >> n;
         cout << "n == " << n
                  << "\nn+1 == " << n+1
                  << "\nthree times n == " << 3*n
                  << "\ntwice n == " << n+n
                  << "\nn squared == " << n*n
                  << "\nhalf of n == " << n/2
                  << "\nsquare root of n == " << sqrt(n)
                  << '\n';
}
Obviously, the usual arithmetic operations have their usual notation and
meaning as we know them from primary school. The exception is that the
notation for equal is ==, rather than just =. Plain = is used for assignment.
Naturally, not everything we might want to do to a floating-point number,
such as taking its square root, is available as an operator. Many operations are
represented as named functions. In this case, we use sqrt() from the standard
library to get the square root of n: sqrt(n). The notation is familiar from math.
We’ll use functions along the way and discuss them in some detail in §3.5
and §7.4