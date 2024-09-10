#include <iostream>
#include <string>
using namespace std;

int main()
{
    // 输入第一行字符串
    string originalStr;
    getline(cin, originalStr);

    // 输入第二行子字符串
    string targetStr;
    getline(cin, targetStr);

    // 输入第三行替换字符串
    string replaceStr;
    getline(cin, replaceStr);

    // 在第一行字符串中查找并替换所有的第二行子字符串
    size_t startPos = 0;
    while ((startPos = originalStr.find(targetStr, startPos)) != string::npos)
    {
        // 执行替换操作
        originalStr.replace(startPos, targetStr.length(), replaceStr);
        // 将 startPos 更新为下一个可能的匹配位置
        startPos += replaceStr.length();
    }
    // 输出结果
    cout << originalStr << endl;
    return 0;
}
