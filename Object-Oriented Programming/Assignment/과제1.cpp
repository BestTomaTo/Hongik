/*#include <iostream>
#include <cctype>
using namespace std;

void get_loweralp(char* str);
void print_alpha(char* str);

int main() {
    char str[10001];

    cout << "영문 텍스트를 입력하세요. 히스토그램을 그립니다." << endl;
    cout << "텍스트의 끝은 ;입니다. 10000개까지 가능합니다." << endl;
    cin.getline(str, 10001, ';');
    get_loweralp(str);

    print_alpha(str);

    cout << "계속하려면 아무 키나 누르십시오..." << endl;

    return 0;
}*/

/*함수 get_loweralp
  문장에 있는 알파벳의 갯수를 세고, 모든 대문자를 소문자로 바꿔줌*/
/*
void get_loweralp(char* str) {
    int cnt_al = 0;

    for (int i = 0; i < strlen(str); i++) {
        if (isalpha(str[i]) == 1 || isalpha(str[i]) == 2) { // 알파벳의 갯수 세기
            cnt_al++;
        }
        if (isalpha(str[i]) == 1) { // 대문자를 소문자로 바꾸어주기 
            str[i] = tolower(str[i]);
        }
    }

    cout << "총 알파벳 수 " << cnt_al << endl;
    cout << endl;
}*/

/*함수 print_alpha
  문장을 구성하는 알파벳의 각 갯수를 세고 *을 찍어줌*/

/*
void print_alpha(char* str) {
    int cnt = 0;

    for (int j = 97; j <= 122; j++) { // 알파벳 갯수 세기
        for (int i = 0; i < strlen(str); i++) {
            if (j == str[i]) {
                cnt++;
            }
        }

        cout << char(j) << "(" << cnt << ")" << " : ";

        for (int k = 0; k < cnt; k++) {
            cout << "*"; // 알파벳 수만큼 *찍기            
        }

        cout << endl;
        cnt = 0;
    }

}*/



