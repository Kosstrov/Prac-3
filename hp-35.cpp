/**
 * Computer Programming 2 (COMP2711, COMP8801)
 * Practical 3: HP-35
 */

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

class HPStack {

public:double arr[4], m;

void push(double  a){
        arr[3] = arr[2];
        arr[2] = arr[1];
        arr[1] = arr[0];
        arr[0] = a;
    }

    double pop(){
        double i = arr[0];
        arr[0] = arr[1];
        arr[1] = arr[2];
        arr[2] = arr[3];
        return i;
    }

    double peek(){
        return arr[0];
    }

    void sto(){
        m = arr[0];
    }

    void rcl(){
        push(m);
    }

    void clr(){
        arr[0] = 0;
        arr[1] = 0;
        arr[2] = 0;
        arr[3] = 0;
    }

    void clx(){
        arr[0] = arr[1];
        arr[1] = arr[2];
        arr[2] = arr[3];
    }

    void swap(){
        double p = arr[0];
        arr[0] = arr[1];
        arr[1] = p;
    }

    void roll(){
        double a = arr[0];
        arr[0] = arr[1];
        arr[1] = arr[2];
        arr[2] = arr[3];
        arr[3] = a;
    }

    void enter(){
        arr[3] = arr[2];
        arr[2] = arr[1];
        arr[1] = arr[0];
    }

};

int main(int argc, char* argv[])
{
    HPStack stack;
    string line;
    while (getline(cin, line)) {

        if(cin.good()){
            for (int r = 0; r < line.length(); r++) {
                line[r] = toupper(line[r]);
            }
        }

        stringstream expression(line);
        string token;
        while (expression >> token) {

            if (isdigit(token[0])) {
                stack.push(atof(token.data()));
            }

            else if (token=="+") { // similar for other arithmetic ops
                double x = stack.pop();
                double y = stack.pop();
                stack.push(y+x);
            }

            else if (token=="-") {
                double x = stack.pop();
                double y = stack.pop();
                stack.push(y-x);
            }

            else if (token=="*") {
                double x = stack.pop();
                double y = stack.pop();
                stack.push(y*x);
            }

            else if (token=="/") {
                double x = stack.pop();
                double y = stack.pop();
                stack.push(y/x);
            }

            else if (token=="PI") {
                double x = M_PI;
                stack.push(x);
            }

            else if (token=="CHS") {
                double x = stack.pop();
                stack.push(x*(-1));
            }

            else if (token=="RECIP") {
                double x = stack.pop();
                stack.push(1/x);
            }

            else if (token=="LOG") {
                double x = stack.pop();
                stack.push(log10(x));
            }

            else if (token=="LN") {
                double x = stack.pop();
                stack.push(log(x));
            }

            else if (token=="EXP") {
                double x = stack.pop();
                stack.push(exp(x));
            }

            else if (token=="SQRT") {
                double x = stack.pop();
                stack.push(sqrt(x));
            }

            else if (token=="SIN") {
                double x = stack.pop();
                stack.push(sin(x));
            }

            else if (token=="COS") {
                double x = stack.pop();
                stack.push(cos(x));
            }

            else if (token=="TAN") {
                double x = stack.pop();
                stack.push(tan(x));
            }

            else if (token=="ARCSIN") {
                double x = stack.pop();
                stack.push(asin(x));
            }

            else if (token=="ARCCOS") {
                double x = stack.pop();
                stack.push(acos(x));
            }

            else if (token=="ARCTAN") {
                double x = stack.pop();
                stack.push(atan(x));
            }

            else if (token=="POW") {
                double x = stack.pop();
                double y = stack.pop();
                stack.push(pow(x,y));
            }

            else if (token=="STO") {
                //double x = stack.peek();
                stack.sto();
            }

            else if (token=="RCL") {
                stack.rcl();
            }

            else if (token=="CLR") {
                stack.clr();
            }

            else if (token=="CLX") {
                stack.clx();
            }

            else if (token=="SWAP") {
                stack.swap();
            }

            else if (token=="ROLL") {
                stack.roll();
            }

            else if (token=="ENTER") {
                stack.enter();
            }

        }
        cout << stack.peek() << endl;
    }


    return 0;
}
