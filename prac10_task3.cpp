#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#include <tuple>

using namespace std;

const int MAX_P = 1000;
const int MAX_N = 1000 / 2;

int main() {
    map<int, vector<tuple<int, int, double, int>>> res;
    int best_len = 1;
    int best_p = 0;

    for (int a = 1; a <= MAX_N; ++a) {
        for (int b = a; b <= MAX_N; ++b) {
            float c = sqrt(a * a + b * b);
            int ic = static_cast<int>(c);

            if (c == ic) {
                int p = a + b + ic;

                if (p > MAX_P) {
                    continue;
                }

                if (res.find(p) != res.end()) {
                    res[p].push_back(make_tuple(a, b, c, p));
                } else {
                    res[p] = {make_tuple(a, b, c, p)};
                }

                int new_len = res[p].size();
                if (new_len > best_len) {
                    best_len = new_len;
                    best_p = p;
                    for (const auto& item : res[p]) {
                        cout << "(" << get<0>(item) << ", " << get<1>(item) << ", " << get<2>(item) << ", " << get<3>(item) << "), ";
                    }
                    cout << endl;
                }
            }
        }
    }

    cout << "Best length: "<< best_len << endl;
    cout << "DONE" << endl;

    return 0;
}

// (10, 24, 26), 60), (15, 20, 25), 60), 
// (20, 48, 52), 120), (24, 45, 51), 120), (30, 40, 50), 120), 
// (15, 112, 113), 240), (40, 96, 104), 240), (48, 90, 102), 240), (60, 80, 100), 240), 
// (28, 195, 197), 420), (60, 175, 185), 420), (70, 168, 182), 420), (105, 140, 175), 420), (120, 126, 174), 420), 
// (40, 399, 401), 840), (56, 390, 394), 840), (105, 360, 375), 840), (120, 350, 370), 840), (140, 336, 364), 840), (168, 315, 357), 840), 
// (40, 399, 401), 840), (56, 390, 394), 840), (105, 360, 375), 840), (120, 350, 370), 840), (140, 336, 364), 840), (168, 315, 357), 840), (210, 280, 350), 840), 
// (40, 399, 401), 840), (56, 390, 394), 840), (105, 360, 375), 840), (120, 350, 370), 840), (140, 336, 364), 840), (168, 315, 357), 840), (210, 280, 350), 840), (240, 252, 348), 840), 
// (40, 399, 401), 840), (56, 390, 394), 840), (105, 360, 375), 840), (120, 350, 370), 840), (140, 336, 364), 840), (168, 315, 357), 840), (210, 280, 350), 840), (240, 252, 348), 840), 
// Best length: 8