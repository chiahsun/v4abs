// Reference
// http://www.iti.fh-flensburg.de/lang/algorithmen/sortieren/networks/oemen.htm
// http://www.eli.sdsu.edu/courses/spring96/cs662/notes/batcher/batcher.html
// http://ieeexplore.ieee.org/stamp/stamp.jsp?tp=&arnumber=922292
//
#include <iostream>
#include <string>
#include <set>
#include <sstream>
using namespace std;

const int num_of_var = 16;
const int num_of_bit = 13;


int test1[num_of_var] = {1, 2, 3, 4, 5, 6, 7, 8};
int test2[num_of_var] = {8, 7, 6, 5, 4, 3, 2, 1};
int test3[num_of_var] = {1, 2, 3, 4, 5, 6, 7, 8};
int test4[num_of_var] = {1, 2, 3, 4, 5, 6, 7, 8};


set<string> myset;
set<string>::iterator it;

int a[num_of_var] = {0};
int table[num_of_var] = {0};
int num_of_comparator = 0;

stringstream comparator_buffer;


string covertInt(int num) {
   stringstream ss;
   ss << num;
   return ss.str();
}


void print_array() {
    for(int i=0; i<num_of_var; ++i)
       cout << a[i] << " ";
    cout << endl;
}

void oddEvenMerge(int lo, int n, int r);

void swap(int i, int j) {
   int t = a[i];
   a[i] = a[j];
   a[j] = t;
}

void oddEvenMergeSort(int lo, int n) {
    if(n > 1) {
        int m = n/2;
        oddEvenMergeSort(lo, m);
        oddEvenMergeSort(lo+m, m);
        oddEvenMerge(lo, n, 1);
    }
}





void compare(int i, int j) {
    string str1 = "a";
    str1 += covertInt(table[i]);
    str1 += "v";
    str1 += covertInt(i);
    string str2 = "a";
    str2 += covertInt(table[j]);
    str2 += "v";
    str2 += covertInt(j);
    myset.insert(str2);
    comparator_buffer << "comparator c" << num_of_comparator++ << " (";
    comparator_buffer << str1 << ", " << str2;
    comparator_buffer << ", ";

    ++table[i]; ++table[j];
    string str3 = "a";
    str3 += covertInt(table[i]);
    str3 += "v";
    str3 += covertInt(i);
    string str4 = "a";
    str4 += covertInt(table[j]);
    str4 += "v";
    str4 += covertInt(j);
    comparator_buffer << str3 << ", " << str4;
    comparator_buffer << ");" << endl;
    myset.insert(str2);
    myset.insert(str1);
    myset.insert(str2);
    myset.insert(str3);
    myset.insert(str4);
    if(a[i] > a[j])
       swap(i, j);
}

void oddEvenMerge(int lo, int n, int r) {
    int m = r*2;
    if(m < n) {
       oddEvenMerge(lo, n, m);
       oddEvenMerge(lo+r, n, m);
       for(int i = lo+r; i+r < lo+n; i+=m)
          compare(i, i+r);
    }
    else 
       compare(lo, lo+r);
}

const char* comparator_mod_string[6] = { 
    "module comparator(d1_in, d2_in, d1_out, d2_out);\n"
  , "    input  ["
  , ":0] d1_in, d2_in;\n    output [" 
  , ":0] d1_out, d2_out;\n"
  , "    assign {d2_out,d1_out} = (d1_in > d2_in) ? {d1_in,d2_in} : {d2_in,d1_in};\n"
  , "endmodule\n" };

int main() {
    for(int i=0; i<num_of_var; ++i) {
        // a[i] = test1[i];
        // a[i] = test2[i];
        // a[i] = i;
        a[i] = num_of_var-i;
        table[i] = 1;
    }
    // General info
    cout << "// Before sort ----- " << endl;
    cout << "// ";
    print_array();
    oddEvenMergeSort(0, num_of_var); 
    cout << "// After sort ------ " << endl;
    cout << "// ";
    print_array();
    cout << "// # wires = " << myset.size() << endl;
    cout << endl;
    int count = 0;

    // Module declaration
//     cout << "`include \"./comparator.v\"" << endl;
    cout << comparator_mod_string[0];
    cout << comparator_mod_string[1] << num_of_bit-1;
    cout << comparator_mod_string[2] << num_of_bit-1;
    cout << comparator_mod_string[3];
    cout << comparator_mod_string[4];
    cout << comparator_mod_string[5] << endl << endl;
    cout << "module bsort(data_in, data_out);" << endl << endl << endl;
    cout << "input   ";
    cout << "[" << num_of_bit*(num_of_var)-1 << ":" << "0" << "] ";
    cout << "data_in;"  << endl;
    cout << "output  ";
    cout << "[" << num_of_bit*(num_of_var)-1 << ":" << "0" << "] ";
    cout << "data_out;"  << endl << endl;
    // --------------------------------------------------
    // Wire declaration
    cout << "wire[" << num_of_bit-1 << ":0] ";
    for(it = myset.begin(); it!=myset.end(); ) {
//       it2 = it;
  //     if((++it2) == myset.end()) ;
    //   else                    
        cout << *it; 
        if(++it == myset.end()) ;
        else                    cout << ", ";
        ++count;
        if(count % 10 == 0) cout << "    " << endl;
    }
    cout << ";";
    cout << endl << endl << endl;
    for(int i=0; i<num_of_var; ++i)
       cout << "assign a1v" << i << " = "
            << "data_in[" << num_of_bit*(i+1)-1 << ":" << num_of_bit*i << "]"
            << ";" << endl;
    cout << endl;
    for(int i=0; i<num_of_var; ++i)
       cout << "assign data_out[" << num_of_bit*(i+1)-1 << ":" << num_of_bit*i << "] = "
            << "a" << table[i] << "v" << i << ";" << endl;
    // --------------------------------------------------
    // Comparator declaration
    cout << endl << endl;
    cout << comparator_buffer.str(); 



    cout << endl << endl << "endmodule" << endl; 
}
