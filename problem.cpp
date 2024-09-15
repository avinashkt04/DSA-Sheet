# include<iostream>

using namespace std;

void printTable(int start, int end, int step){
    while(start<=end){
        float cel = ((start-32)*5)/9;
        cout << start << " " << cel << endl;
        start = start + step;
    }
}

int main() {
    printTable(50, 150, 15);
    return 0;
}