class Solution {
public:
    std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
        std::vector<std::string> res, cur_words;
        int cur_len = 0;

        for (const std::string& word : words) {
            if (cur_len + word.length() + cur_words.size() > maxWidth) {
                int total_spaces = maxWidth - cur_len;
                int gaps = cur_words.size() - 1;
                if (gaps == 0) {
                    res.push_back(cur_words[0] + std::string(total_spaces, ' '));
                } else {
                    int space_per_gap = total_spaces / gaps;
                    int extra_spaces = total_spaces % gaps;
                    std::string line = "";
                    for (int i = 0; i < cur_words.size(); ++i) {
                        line += cur_words[i];
                        if (i < gaps) {
                            line += std::string(space_per_gap, ' ');
                            if (i < extra_spaces) {
                                line += ' ';
                            }
                        }
                    }
                    res.push_back(line);
                }
                cur_words.clear();
                cur_len = 0;
            }
            cur_words.push_back(word);
            cur_len += word.length();
        }

        std::string last_line = "";
        for (const std::string& word : cur_words) {
            if (!last_line.empty()) {
                last_line += ' ';
            }
            last_line += word;
        }
        last_line += std::string(maxWidth - last_line.length(), ' ');
        res.push_back(last_line);

        return res;
    }
};