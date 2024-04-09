#include <iostream>

long long ClosestAncestor(long long a, long long b) {
    if (a == b == 1) {
        a /= 2;
    }
    else {
        while (a != b) {
            if (a > b) {
                a /= 2;
            }
            else {
                b /= 2;
            }
        }
    }
    return a;
}

int main(int argc, char* argv[]) {
    int n = 0;
    long long a = 0;
    long long b = 0;
    std::cin >> n >> a >> b;

    std::cout << ClosestAncestor(a, b) << std::endl;

    return 0;
}
