#include<iostream>
#include<string>

using namespace std;

string enter_passwd_structure = "";
string range_check_string_out();
int counter = 1;

struct string_type
{
    bool isfixed;
    int length;
    string content;
    int string_array[80];
};
string_type numerator[80];

int customize();

bool dup_range_check(int arr[], int num, int target);

void add_xiny(int x, string_type *input_string, const int total, int &counter);

void print_all_of_them(const int total, int &counter);

int main()
{
    // use numbers to show types.
    // 1 for fixed type
    // 2 for variable type
    cout<<"Welcome to the generator!\n"
        <<"1 for fixed type\n"
        <<"2 for variable type\n";
    cout<<"Now please enter the structure of your password generation: (for example 12121, 2, etc) \n";

    enter_passwd_structure = range_check_string_out(); // get the structure;

    cout<<"Correct input! Your format is set to: "<<enter_passwd_structure<<endl;

    cout<<"Please note that the letter you enter next is capital-sensitive!!!\n";

    int total_length = customize();
    int total = enter_passwd_structure.size();
    // cout<<total_length;
    // print all the string out

    // first string first
    for (int i = 1; i <= total; i++)
    {
        if (numerator[i].isfixed)
            cout<<numerator[i].content;
        else
            for (int j = 1; j <= numerator[i].length; j++)
                cout<<(numerator[i]).content[(numerator[i]).string_array[j]];
    }
    cout<<endl;

    print_all_of_them(total, counter);

    cout<<"All the strings are created! Thanks for using it!\n"
        <<"The strings' length is "<<total_length;

    return 0;
}

string right_string_out;
string range_check_string_out()
{
    cin>>right_string_out;

    // check if value are input correctly
    for (int i = 1; i <= right_string_out.size(); i++)
        if ((int(right_string_out[i - 1]) <= 48) || (int(right_string_out[i - 1]) >= 51))
        {
            cout<<"Input out of range! Type again please!\n";
            range_check_string_out(); // recursion to recheck...
        }
        else if (right_string_out[i - 1] == right_string_out[i])
        {
            cout<<"Duplicated parameters! Type again please!\n";
            range_check_string_out(); // recursion to recheck...
        }

    return right_string_out;
}

int customize()
{
    // put it into a organized string
    int counter_of_numerator = 1;
    int total_length = 0;

    for (int i = 1; i <= enter_passwd_structure.size(); i++)
    {
        switch (int(enter_passwd_structure[i - 1] - '0'))
        {
            case 1:
            {
                cout<<"Enter the fixed symbol, it can be a word, a letter, etc.\n";
                cin>>numerator[counter_of_numerator].content;
                numerator[counter_of_numerator].isfixed = true;
                numerator[counter_of_numerator].length = (numerator[counter_of_numerator].content).size();
                total_length += numerator[counter_of_numerator].length;
                cout<<endl;
            }
            break;
            case 2:
            {
                cout<<"Enter the variable symbol.\n";
                cout<<"Enter the length you want to give it.\n";
                cin>>numerator[counter_of_numerator].length;
                total_length += numerator[counter_of_numerator].length;
                cout<<"Enter the string characters you want.\n";
                cin>>numerator[counter_of_numerator].content;
                numerator[counter_of_numerator].isfixed = false;
                cout<<endl;
            }
            break;
        }
        counter_of_numerator++;
    }

    return total_length;
}

bool dup_range_check(int arr[], int num, int target)
{
    for (int i = 1; i < num; i++)
        if ((*(arr + i) != *(arr)) || ((*arr) != target))
            return false;
    return true;

}

void add_xiny(int x, string_type &input_string, const int total, int &counter)
{
    int y = (input_string.content).size();
    // input_string.string_array[80] = {};
    // y is for the cardinal
    // x is for the number of the digits

    if (!dup_range_check(input_string.string_array + 1, x, y - 1))
    {
        input_string.string_array[x]++;
        int pluser = x;
        while ((input_string.string_array[pluser] > y - 1) && (pluser > 0))
        {
            pluser--;
            input_string.string_array[pluser]++;
            input_string.string_array[pluser + 1] = 0;
        }
    }
    else
    {
        counter += 2;
        for (int i = 0; i <= 79; i++)
            input_string.string_array[i] = 0;
        print_all_of_them(total, counter);
    }

    return;
}

int flag = 1; // get a flag to certify where the round starts
void print_all_of_them(const int total, int &counter)
{
    if (counter > total)
        return;
    else if (!numerator[counter].isfixed)
        while (!numerator[counter].isfixed)
        {
            add_xiny(numerator[counter].length, numerator[counter], total, counter);
            if (counter > total)
                return;
            else
                counter = flag;
            // print the strings out
            for (int i = 1; i <= total; i++)
            {
                if (numerator[i].isfixed)
                    cout<<numerator[i].content;
                else
                    for (int j = 1; j <= numerator[i].length; j++)
                        cout<<(numerator[i]).content[(numerator[i]).string_array[j]];
            }
            cout<<endl;
        }
    else
    {
        counter++;
        flag = counter;
        print_all_of_them(total, counter);
    }
}
