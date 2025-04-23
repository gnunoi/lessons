#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>
#include <algorithm>
#include <regex>
#include <map>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <memory>
#include <stdexcept>

using namespace std;

// 前向声明
class Question;
class Question24Point;
class QuestionQC;
class Question4AO;

// 模拟 Python 的 Fraction 类
class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int num, int den = 1) : numerator(num), denominator(den) {
        if (den == 0) {
            throw runtime_error("Denominator cannot be zero");
        }
        simplify();
    }

    void simplify() {
        int gcd_val = gcd(numerator, denominator);
        numerator /= gcd_val;
        denominator /= gcd_val;
    }

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    double toDouble() const {
        return static_cast<double>(numerator) / denominator;
    }

    friend ostream& operator<<(ostream& os, const Fraction& f) {
        os << f.numerator << "/" << f.denominator;
        return os;
    }

    friend Fraction operator+(const Fraction& a, const Fraction& b) {
        return Fraction(a.numerator * b.denominator + b.numerator * a.denominator, a.denominator * b.denominator);
    }

    friend Fraction operator-(const Fraction& a, const Fraction& b) {
        return Fraction(a.numerator * b.denominator - b.numerator * a.denominator, a.denominator * b.denominator);
    }

    friend Fraction operator*(const Fraction& a, const Fraction& b) {
        return Fraction(a.numerator * b.numerator, a.denominator * b.denominator);
    }

    friend Fraction operator/(const Fraction& a, const Fraction& b) {
        return Fraction(a.numerator * b.denominator, a.denominator * b.numerator);
    }

    bool operator==(const Fraction& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }
};

// 题目管理器类
class QuestionManager {
private:
    int type;
    vector<int> subtype;
    vector<int> range;
    unique_ptr<Question> q;

public:
    QuestionManager(int type = 0, const vector<int>& subtype = {0}, const vector<int>& range = {1, 10})
        : type(type), subtype(subtype), range(range) {
        CreateQuestion();
    }

    void CreateQuestion();
    void test();
};

// 题目基类
class Question {
protected:
    int type;
    string name;
    vector<int> subtype;
    vector<int> range;
    vector<int> numbers;
    vector<string> operators;
    string expression;
    string question;
    string user_input;
    string user_answer;
    double correct_answer;
    string comments;
    string check_tips;
    string answer_tips;
    bool is_correct;
    string start_time;
    string end_time;
    double used_time;

public:
    Question(int type = 0, const vector<int>& subtype = {0}, const vector<int>& range = {1, 10})
        : type(type), subtype(subtype), range(range) {}

    virtual bool Generate();
    virtual string Question();
    virtual double Answer();
    virtual void CheckTips();
    virtual void AnswerTips();
    void Tips();
    string getCurrentTime();
    int RandInt(int a, int b);
    bool ProcessUserInput(const string& input);
    virtual bool JudgeAnswer();
};

// 24点游戏类
class Question24Point : public Question {
public:
    Question24Point(const vector<int>& range = {1, 13});
    bool Generate() override;
    void Instance();
    string Validate24Point();
    string Question() override;
    double Answer() override;
    void CheckTips() override;
    void AnswerTips() override;
    bool JudgeAnswer() override;
};

// 乘法速算类
class QuestionQC : public Question {
public:
    QuestionQC(const vector<int>& subtype = {0}, const vector<int>& range = {1, 10});
    bool Generate() override;
    void Instance();
    string Question() override;
    double Answer() override;
    void AnswerTips() override;
    bool JudgeAnswer() override;
};

// 四则运算类
class Question4AO : public Question {
public:
    Question4AO(const vector<int>& subtype = {0, 0}, const vector<int>& range = {-50, 50, 10, 50});
    bool Generate() override;
    void Instance();
    string Question() override;
    double Answer() override;
    double evaluateExpression();
};

// 实现部分
void QuestionManager::CreateQuestion() {
    if (type == 0) { // 24点游戏
        q = make_unique<Question24Point>(range);
    } else if (type == 1) { // 乘法速算
        q = make_unique<QuestionQC>(subtype, range);
    } else if (type == 2) { // 四则运算
        q = make_unique<Question4AO>(subtype, range);
    } else {
        cout << type << ": 无效的类型" << endl;
        q = nullptr;
    }
}

void QuestionManager::test() {
    if (!q) {
        return;
    }
    cout << q->name << endl;

    if (!q->Generate()) {
        return;
    }

    while (true) {
        cout << q->comments << endl;
        cout << "输入EXIT或QUIT退出程序" << endl;
        cout << q->start_time << endl;
        cout << q->question << endl;
        string user_input;
        getline(cin, user_input);

        if (user_input == "EXIT" || user_input == "QUIT") {
            cout << "用户退出程序" << endl;
            break;
        }

        if (!q->ProcessUserInput(user_input)) {
            cout << "无效输入，继续做题" << endl;
            continue;
        }

        if (q->JudgeAnswer()) {
            if (q->type == 0) {
                cout << "回答正确: " << q->user_input << " = " << q->correct_answer << endl;
            } else {
                cout << "回答正确: " << q->expression << " = " << q->user_answer << endl;
            }
            cout << "答题结束时间：" << q->end_time << ", 答题用时：" << q->used_time << "秒" << endl;
            q->Generate(); // 生成下一题
        } else {
            cout << "回答错误: 再来一次" << endl;
            q->Tips();
            if (q->check_tips != "") {
                cout << "检查提示：" << q->check_tips << endl;
            }
            if (q->answer_tips != "") {
                cout << "答题提示：" << q->answer_tips << endl;
            }
        }
        cout << endl;
    }
}

bool Question::Generate() {
    start_time = getCurrentTime();
    return true;
}

string Question::Question() {
    return "";
}

double Question::Answer() {
    return 0.0;
}

void Question::CheckTips() {}

void Question::AnswerTips() {}

void Question::Tips() {
    CheckTips();
    AnswerTips();
}

string Question::getCurrentTime() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    stringstream ss;
    ss << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec;
    return ss.str();
}

int Question::RandInt(int a, int b) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(a, b);
    return dis(gen);
}

bool Question::ProcessUserInput(const string& input) {
    map<char, char> replace_map = {
        {'（', '('}, {'）', ')'}, {'[', '('}, {']', ')'}, {'{', '('}, {'}', ')'},
        {'【', '('}, {'】', ')'}, {'＋', '+'}, {'➕', '+'}, {'➖', '-'},
        {'×', '*'}, {'✖', '*'}, {'÷', '/'}
    };

    string processed_input = input;
    for (auto& pair : replace_map) {
        replace(processed_input.begin(), processed_input.end(), pair.first, pair.second);
    }

    size_t equal_pos = processed_input.find('=');
    if (equal_pos != string::npos) {
        processed_input = processed_input.substr(equal_pos + 1);
    }

    user_input = processed_input;
    user_answer = processed_input;
    return true;
}

bool Question::JudgeAnswer() {
    end_time = getCurrentTime();
    used_time = static_cast<double>(difftime(time(0), time(0)));
    return false;
}

Question24Point::Question24Point(const vector<int>& range)
    : Question(0, {0}, range) {
    name = "24点游戏";
    comments = "输入表达式，使得表达式的值为24。如: (5+3)*(8-5)。";
    Generate();
}

bool Question24Point::Generate() {
    Instance();
    Question();
    Answer();
    start_time = getCurrentTime();
    return true;
}

void Question24Point::Instance() {
    int min_val = range[0];
    int max_val = range[1];
    while (true) {
        numbers = {RandInt(min_val, max_val), RandInt(min_val, max_val),
                   RandInt(min_val, max_val), RandInt(min_val, max_val)};
        if (Validate24Point() != "") {
            break;
        }
    }
}

string Question24Point::Validate24Point() {
    return "(5+3)*(8-5)";
}

string Question24Point::Question() {
    stringstream ss;
    ss << "24点游戏: [";
    for (size_t i = 0; i < numbers.size(); ++i) {
        ss << numbers[i];
        if (i < numbers.size() - 1) {
            ss << ", ";
        }
    }
    ss << "]";
    question = ss.str();
    return question;
}

double Question24Point::Answer() {
    correct_answer = 24.0;
    return correct_answer;
}

void Question24Point::CheckTips() {
    check_tips = "检查提示: 请确保表达式正确";
}

void Question24Point::AnswerTips() {
    answer_tips = Validate24Point();
}

bool Question24Point::JudgeAnswer() {
    if (!ProcessUserInput(user_input)) {
        return false;
    }
    return correct_answer == 24.0;
}

QuestionQC::QuestionQC(const vector<int>& subtype, const vector<int>& range)
    : Question(1, subtype, range) {
    name = "两位数乘法速算";
    comments = "输入答案，可以含中间过程。如: 36 * 36 = 32 * 40 + 4 * 4 = 1280 + 16 = 1296";
    Generate();
}

bool QuestionQC::Generate() {
    Instance();
    Question();
    Answer();
    start_time = getCurrentTime();
    return true;
}

void QuestionQC::Instance() {
    int min_val = range[0];
    int max_val = range[1];
    int subtype = this->subtype[0];

    if (subtype == 0) {
        int number = RandInt(min_val, max_val);
        numbers = {number, number};
        operators = {"*"};
    } else if (subtype == 1) {
        int n1 = RandInt(min_val / 5, max_val / 5) * 5;
        int n2 = RandInt(1, 5);
        numbers = {n1 + n2, n1 - n2};
        operators = {"*"};
    } else if (subtype == 2) {
        int n1 = RandInt(min_val / 10, max_val / 10) * 10;
        int n2 = RandInt(1, 9);
        numbers = {n1 + n2, n1 + 10 - n2};
        operators = {"*"};
    } else if (subtype == 3) {
        int n1 = RandInt(min_val / 10, max_val / 10) * 10;
        int n2 = RandInt(1, 3);
        numbers = {n1 - n2, n1 + n2};
        operators = {"*"};
    } else if (subtype == 4) {
        int n1 = RandInt(min_val / 5, max_val / 5) * 5;
        int n2 = RandInt(min_val / 2, max_val / 2) * 2;
        numbers = {n1, n2};
        operators = {"*"};
    } else if (subtype == 5) {
        int n1 = RandInt(min_val / 10, max_val / 10) * 10;
        int n2 = RandInt(8, 9);
        numbers = {n1 + n2, n1 + 10 - n2};
        operators = {"*"};
    }
}

string QuestionQC::Question() {
    stringstream ss;
    ss << numbers[0] << " * " << numbers[1] << " = ";
    question = ss.str();
    return question;
}

double QuestionQC::Answer() {
    correct_answer = static_cast<double>(numbers[0] * numbers[1]);
    return correct_answer;
}

void QuestionQC::AnswerTips() {
    int subtype = this->subtype[0];
    if (subtype == 0) {
        int m = numbers[0];
        answer_tips = to_string(m) + " * " + to_string(m) + " = " + to_string(m * m);
    } else if (subtype == 1) {
        int m = numbers[0];
        int n = numbers[1];
        int a = (m + n) / 2;
        int b = abs(a - m);
        answer_tips = to_string(m) + " * " + to_string(n) + " = (" + to_string(a) + " + " + to_string(b) + ") * (" + to_string(a) + " - " + to_string(b) + ")";
    }
}

bool QuestionQC::JudgeAnswer() {
    if (!ProcessUserInput(user_input)) {
        return false;
    }
    try {
        return stod(user_answer) == correct_answer;
    } catch (...) {
        return false;
    }
}

Question4AO::Question4AO(const vector<int>& subtype, const vector<int>& range)
    : Question(2, subtype, range) {
    name = "四则速算";
    comments = "输入答案，可以含中间过程。如: 36 * 36 = 32 * 40 + 4 * 4 = 1280 + 16 = 1296";
    Generate();
}

bool Question4AO::Generate() {
    Instance();
    Question();
    Answer();
    start_time = getCurrentTime();
    return true;
}

void Question4AO::Instance() {
    int term_count = subtype[0];
    vector<string> ops = {"+", "-", "*", "/"};
    vector<string> user_operators = {ops[subtype[1]]};

    for (int i = 0; i < term_count; ++i) {
        numbers.push_back(RandInt(range[0], range[1]));
        if (i < term_count - 1) {
            operators.push_back(user_operators[0]);
        }
    }
}

string Question4AO::Question() {
    stringstream ss;
    for (size_t i = 0; i < numbers.size(); ++i) {
        ss << numbers[i];
        if (i < operators.size()) {
            ss << " " << operators[i] << " ";
        }
    }
    ss << " = ";
    question = ss.str();
    return question;
}

double Question4AO::Answer() {
    return evaluateExpression();
}

double Question4AO::evaluateExpression() {
    return 0.0;
}

int main() {
    int type = 0;
    if (type == 0) {
        QuestionManager qm(0, {0}, {1, 10});
        qm.test();
    } else if (type == 1) {
        QuestionManager qm(1, {1}, {10, 50});
        qm.test();
    } else if (type == 2) {
        QuestionManager qm(2, {3, 4}, {-50, 50, 2, 10});
        qm.test();
    }
    return 0;
}