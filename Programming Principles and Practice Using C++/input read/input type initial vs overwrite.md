Input and type
CC
The input operation >> (“get from”) is sensitive to type; that is, it reads
according to the type of variable you read into. For example:
Click here to view code image
int main()          
{
// read name and age
cout << "Please enter your first name and age\n";
string first_name = "???";                
// string variable ("???" indicates "don’t know the name")
int age = −1;                                       
cin >> first_name >> age;                
// read a string followed by an integer
cout << "Hello, " << first_name << " (age " << age << ")\n";
}
// integer variable (-1 means "don’t know the age")
So, if you type in Carlos 22 the >> operator will read Carlos into first_name, 22
into age, and produce this output:
Hello, Carlos (age 22)
Why won’t it read (all of) Carlos 22 into first_name? Because, by convention,
reading of strings is terminated by what is called whitespace, that is, space,
newline, and tab characters. Otherwise, whitespace by default is ignored by
>>. For example, you can add as many spaces as you like before a number to
be read; >> will just skip past them and read the number.
Just as we can write several values in a single output statement, we can
read several values in a single input statement. Note that << is sensitive to
type, just as >> is, so we can output the int variable age as well as the string
variable first_name and the string literals "Hello, ", " (age", and ")\n".
If you type in 22 Carlos, you’ll see something that might be surprising until
you think about it. The (misguided) input 22 Carlos will output
Hello, 22 (age −1)
The 22 will be read into first_name because, after all, 22 is a sequence of
characters, and they are terminated by whitespace. On the other hand, Carlos
isn’t an integer, so it will not be read. The output will be 22 and age’s initial
value −1. Why? You didn’t succeed in reading a value into it, so it kept its
initial value.
AA
A string read using >> is (by default) terminated by whitespace; that is, it
reads a single word. But sometimes, we want to read more than one word.
There are of course many ways of doing this. For example, we can read a
name consisting of two words like this:
Click here to view code image
int main()
{
         cout << "Please enter your first and second names\n";
         string first;
         string second;
         cin >> first >> second;                               // read two strings
         cout << "Hello, " << first << " " << second << '\n';
}
We simply used >> twice, once for each name. When we want to write the
names to output, we must insert a space between them.
Note the absence of initializers for the two strings used as targets for input
(first and second). By default, a string is initialized to the empty string, that is
"".
Try This
Get the “name and age” example to run. Then, modify it to write out the
age in number of months: read the input in years and multiply (using the *
operator) by 12. Read the age into a double to allow for children who can
be very proud of being five and a half years old rather than just five