class Spreadsheet {
public:
    unordered_map<string, int> map;
    Spreadsheet(int rows) {

        for (int i = 1; i <= rows; i++) {
            char ch = 'A' + (i - 1);
            for (int j = 1; j <= 26; j++) {
                string s;
                s += ch;
                s += to_string(j);
                map[s] = 0;
            }
        }
    }

    void setCell(string cell, int value) { map[cell] = value; }

    void resetCell(string cell) { map[cell] = 0; }

    int getValue(string formula) {
        if (!formula.empty() && formula[0] == '=') {
            formula = formula.substr(1);
        }
        int i = 0;
        string str1;
        for (i = 0; i < formula.size(); i++) {
            if (formula[i] == '+') {
                break;
            }
            if (formula[i]!= ' ') {
                str1 += formula[i];
            }
        }

        string str2;
        for (int j = i + 1; j < formula.size(); j++) {
            if (formula[j] != ' ') {
                str2 += formula[j];
            }
        }
        // check whether str1 and str2 has only a number or an existing cell
        bool flag = true;
        int n1 = 0, n2 = 0;
        for (auto ch : str1) {
            if (!isdigit(ch)) {
                if (isalpha(ch)) {
                    // an existing cell
                    n1 = map[str1];
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            n1 = stoi(str1);
        }
        flag = true;
        for (auto ch : str2) {
            if (!isdigit(ch)) {
                if (isalpha(ch)) {
                    n2 = map[str2];
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            n2 = stoi(str2);
        }
        return n1 + n2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */