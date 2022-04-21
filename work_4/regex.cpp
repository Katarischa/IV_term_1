#include <regex>
#include <iostream>

std::vector<std::string> search(const std::regex &pattern,
                                const std::string &text) {
    auto begin = std::sregex_iterator(std::begin(text),
                                      std::end(text), pattern);
    auto end = std::sregex_iterator();
    std::vector<std::string> results(std::distance(begin, end));
    std::transform(begin, end, std::back_inserter(results), [](auto x) {
        return x.str();
    });
    auto it = std::remove_if(std::begin(results), std::end(results), [](auto item) {
        return item.empty();
    });
    results.erase(it, std::end(results));
    return results;
}

int main() {

    std::regex pattern(R"(([01][0-9]|2[0-4])(\:[0-6][0-9]){2})");

    std::string text = "23:01:48 12:20:12 98098907 121314,,,;,, 34 03 2 12:99:37 12.20.12 11:12:11 ghkjtl 5563 3jk 2ll 22:91:34 15:06:46 47674752543 45 11 02 123 40 13:02:48 00:00:00";

    auto search_result = search(pattern, text);
    for (const auto &item: search_result) {
        std::cout << item << std::endl;
    }
    return 0;
}