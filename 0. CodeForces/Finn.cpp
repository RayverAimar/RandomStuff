#include <iostream>
#include <vector>
#include <utility>

bool golpe_certero(std::pair<int, int> lich, std::pair<int, int> myPos) {
    if (lich.second == myPos.second) return true;
    else if (lich.first == myPos.first) return true;
    else if (abs(lich.first - myPos.first) == abs(lich.second - myPos.second)) return true; 
    return false;
}

int main()
{
    int aux1, aux2, n;
    std::vector<std::pair<int, int>> pos;
    std::cin >> aux1;
    std::cin >> aux2;
    pos.push_back({ aux1,aux2 });
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> aux1;
        std::cin >> aux2;
        pos.push_back({ aux1,aux2 });
        if (golpe_certero(pos[0], pos[i])) std::cout << "Algebraico!" << std::endl;
        else std::cout << ":(" << std::endl;
    }

}